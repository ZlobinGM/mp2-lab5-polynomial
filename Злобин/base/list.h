#ifndef __LIST_H__
#define __LIST_H__

using namespace std;

template <class T>
struct Node
{
	T data;
	Node<T>* pNext;
	Node() : data(), pNext(nullptr) {}
};

template <class T>
class List
{
protected:
	Node<T>* pFirst;
	int length;
public:
	List() : pFirst(nullptr), length(0) {}
	List(const List<T>& _list)
	{
		if (_list.pFirst == nullptr) {
			pFirst = nullptr;
			length = 0;
		}
		else
		{
			length = _list.length;
			pFirst = new Node<T>;
			pFirst->data = _list.pFirst->data;
			Node<T>* p = pFirst, *_p = _list.pFirst->pNext, *tmp;
			while (_p != nullptr) {
				tmp = new Node<T>;
				tmp->data = _p->data;
				p->pNext = tmp;
				p = p->pNext;
				_p = _p->pNext;
			}
		}
	}
	~List()
	{
		Node<T>* p = pFirst;
		while (p != nullptr) {
			pFirst = p->pNext;
			delete p;
			p = pFirst;
		}
	}

	List<T>& operator=(const List<T>& _list)
	{
		Node<T>* p = pFirst;
		while (p != nullptr) {
			pFirst = p->pNext;
			delete p;
			p = pFirst;
		}

		length = _list.length;
		if (_list.pFirst == nullptr) {
			pFirst = nullptr;
			return *this;
		}

		pFirst = new Node<T>;
		pFirst->data = _list.pFirst->data;
		p = pFirst;
		Node<T>* _p = _list.pFirst->pNext, * tmp;
		while (_p != nullptr) {
			tmp = new Node<T>;
			tmp->data = _p->data;
			p->pNext = tmp;
			p = p->pNext;
			_p = _p->pNext;
		}
		return *this;
	}
	T& operator[](int i)
	{
		if (i >= length || i < 0) throw "out_of_range";
		int count = 0;
		Node<T>* p = pFirst;
		while (i != count) {
			p = p->pNext;
			count++;
		}
		return p->data;
	}

	virtual void Insert(const T& _data)
	{
		if (pFirst == nullptr) {
			pFirst = new Node<T>;
			pFirst->data = _data;
			length++;
			return;
		}
		Node<T>* p = pFirst, * tmp = new Node<T>;
		while (p->pNext != nullptr) { p = p->pNext; }
		tmp->data = _data;
		p->pNext = tmp;
	}
	void Delete(int i)
	{
		if (i >= length || i < 0) throw "out_of_range";
		Node<T>* p = pFirst, * _p;
		if (i == 0)	{
			pFirst = pFirst->pNext;
			delete p;
			length--;
			return;
		}

		int count = 1;
		while (count < i) {
			p = p->pNext;
			count++;
		}
		_p = p->pNext;
		p->pNext = _p->pNext;
		delete _p;
		length--;
	}
	void Delete(const T& _data)
	{
		Node<T>* p = pFirst, * _p;
		if (pFirst->data == _data) {
			pFirst = pFirst->pNext;
			delete p;
			length--;
			return;
		}

		while (p->pNext->data != _data) { p = p->pNext; }
		_p = p->pNext;
		p->pNext = _p->pNext;
		delete _p;
		length--;
	}
	int Length() { return length; }
};

#endif