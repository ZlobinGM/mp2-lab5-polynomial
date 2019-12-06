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
			while (_p != nullptr)
			{
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
		while (p != nullptr)
		{
			pFirst = p->pNext;
			delete p;
			p = pFirst;
		}
	}
	List<T>& operator=(const List<T>& _list)
	{
		Node<T>* p = pFirst;
		while (p1 != nullptr)
		{
			pFirst = p->pNext;
			delete p;
			p = pFirst;
		}
		length = _list.length;
		pFirst = new Node<T>;
		pFirst->data = _list.pFirst->data;
		p = pFirst;
		Node<T>* _p = _list.pFirst->pNext, * tmp;
		while (_p != nullptr)
		{
			tmp = new Node<T>;
			tmp->data = _p->data;
			p->pNext = tmp;
			p = p->pNext;
			_p = _p->pNext;
		}
		return *this;
	}
	int Length() { return length; }
};

#endif