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
			Node<T>* p = pFirst, *tmp;
			for (Node<T>* _p = _list.pFirst->pNext; _p != nullptr; _p = _p->pNext;)	{
				tmp = new Node<T>;
				tmp->data = _p->data;
				p->pNext = tmp;
				p = p->pNext;
			}
			p->pNext = nullptr;
		}
	}
	List(const T& _data) 
	{
		pFirst = new Node<T>;
		pFirst->data = _data;
		pFirst->pNext = nullptr;
		length = 1;
	}
	virtual ~List()
	{
		for (Node<T>* p = pFirst; p != nullptr; p = pFirst)	{
			pFirst = p->pNext;
			delete p;
		}
	}

	List<T>& operator=(const List<T>& _list)
	{
		Node<T>* p = pFirst;
		for (Node<T>* p = pFirst; p != nullptr; p = pFirst) {
			pFirst = p->pNext;
			delete p;
		}

		length = _list.length;
		if (_list.pFirst == nullptr) {
			pFirst = nullptr;
			return *this;
		}

		pFirst = new Node<T>;
		pFirst->data = _list.pFirst->data;
		Node<T>* p = pFirst, * tmp;
		for (Node<T>*_p = _list.pFirst->pNext; _p != nullptr; _p = _p->pNext) {
			tmp = new Node<T>;
			tmp->data = _p->data;
			p->pNext = tmp;
			p = p->pNext;
		}
		p->pNext = nullptr;
		return *this;
	}
	T& operator[](int i)
	{
		if (i >= length || i < 0) throw "out_of_range";
		Node<T>* p = pFirst;
		for (int count = 0; count != i; count++)
			p = p->pNext;
		return p->data;
	}

	virtual void Insert(const T& _data)
	{
		if (pFirst == nullptr) {
			pFirst = new Node<T>;
			pFirst->data = _data;
			pFirst->pNext = nullptr;
			length++;
			return;
		}
		Node<T>* p = pFirst, * tmp = new Node<T>;
		while (p->pNext != nullptr) { p = p->pNext; }
		tmp->data = _data;
		tmp->pNext = nullptr;
		p->pNext = tmp;
		length++;
	}
	virtual void Delete(int i)
	{
		if (length == 0)return;
		if (i >= length || i < 0) throw "out_of_range";
		Node<T>* p = pFirst, * _p;
		if (i == 0)	{
			pFirst = pFirst->pNext;
			delete p;
			length--;
			return;
		}

		for (int count = 1; count < i; count++)
			p = p->pNext;
		_p = p->pNext;
		p->pNext = _p->pNext;
		delete _p;
		length--;
	}
	virtual void Delete(const T& _data)
	{
		if (length == 0)return;
		Node<T>* p = pFirst, * _p;
		if (pFirst->data == _data) {
			pFirst = pFirst->pNext;
			delete p;
			length--;
			return;
		}

		for (; p->pNext != nullptr; p = p->pNext)
			if (p->pNext->data == _data) {
				_p = p->pNext;
				p->pNext = _p->pNext;
				delete _p;
				length--;
				return;
			}
	}
	int Length() { return length; }
};

#endif