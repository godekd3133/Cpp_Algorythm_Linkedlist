#pragma once
#include <iostream>
#include <functional>
template <typename T>
class Node
{
public:
	Node() {}
	~Node() {}
public:
	Node<T> * pNext = nullptr;
	Node<T> * pPrev = nullptr;
	T Data;
};

template <typename T>
class list
{

private:
	Node<T> * pHead;
	Node<T> * pTail;
public:
	class iterator
	{
	public:
		Node<T> * pNode;
	public:
		iterator(Node<T> * _pNode) : pNode(_pNode) {}
		~iterator() {}
		T& operator *() const {
			return pNode->Data;
		}
		
		bool operator != (list<T>::iterator _MyIter)
		{
			return pNode != _MyIter.pNode;
		}
		void operator =(list<T>::iterator _MyIter){
			pNode = _MyIter.pNode;
		}

		list<T>::iterator operator ++()	{
			pNode = pNode->pNext;
			return *this;
		}

		list<T>::iterator operator ++(int)	{
			pNode = pNode->pNext;
			return *this;
		}

		list<T>::iterator operator --()	{
			pNode = pNode->pPrev;
			return *this;
		}

		list<T>::iterator operator --(int)	{
			pNode = pNode->pPrev;
			return *this;
		}

		list<T>::iterator operator + (int _nCount)
		{
			Node<T> * temp = this->pNode;

			for (int i = 0; i < _nCount; i++)
			{
				temp = temp->pNext;
			}

			return iterator(temp);
		}

		list<T>::iterator operator - (int _nCount)
		{
			Node<T> * temp = this->pNode;

			for (int i = 0; i < _nCount; i++)
			{
				temp = temp->pPrev;
			}

			return iterator(temp);
		}
	};
	void assign(int _Amount, T _Value)
	{
		for (int i = 0; i < _Amount; i++)
		{
			push_back(_Value);
		}
	}
	void assign(list<T>::iterator _Begin, list<T>::iterator _End)
	{
		for (auto iter = _Begin; iter != _End; iter++)
		{
			push_back(iter.pNode->Data);
		}
	}

	list<T>::iterator  begin() { return iterator(pHead->pNext); }
	void clear()
	{
		printf("clear() È£ÃâµÊ\n");
		for (auto iter = begin(); iter != end();)
		{
			iter = erase(iter);
		}
	}
	T back()
	{
		return (end()-1).pNode->Data;
	}
	T front()
	{
		return begin().pNode->Data;
	}

	void push_back(T _Data)
	{
		printf("push_back(%d) È£ÃâµÊ\n", _Data);
		
		Node<T> * pNewNode = new Node<T>;
		pNewNode->Data = _Data;

		pNewNode->pNext = pTail;
		pNewNode->pPrev = pTail->pPrev;

		pTail->pPrev->pNext = pNewNode;
		pTail->pPrev = pNewNode;
	}
	void push_front(T _Data)
	{
		printf("push_front(%d) È£ÃâµÊ\n", _Data);
		
		Node<T> * pNewNode = new Node<T>;
		pNewNode->Data = _Data;

		pNewNode->pNext = pHead->pNext;
		pNewNode->pPrev = pHead;

		pHead->pNext->pPrev = pNewNode;
		pHead->pNext = pNewNode;
	}
	void pop_back()
	{
		Node<T> * pDelNode = pTail->pPrev;
		if (pDelNode == pHead) return;
		pTail->pPrev->pPrev->pNext = pTail;
		pTail->pPrev = pTail->pPrev->pPrev;
		delete pDelNode;
	}	
	void pop_front()
	{
		Node<T> * pDelNode = pHead->pNext;
		if (pDelNode == pTail) return;
		pHead->pNext->pNext->pPrev = pHead;
		pHead->pNext = pHead->pNext->pNext;
		delete pDelNode;
	}
	void remove(T _Data)
	{
		for (auto iter = begin(); iter != end(); )
		{
			if ((*iter) == _Data)
			{
				iter = erase(iter);
			}
			else iter++;
		}
	}
	void remove_if(std::function<bool(T _A)> _pred)
	{
		for (auto iter = begin(); iter != end();)
		{
			if (_pred(*iter) == true)
			{
				iter = erase(iter);
			}
			else iter++;
		}
	}
	list<T>::iterator erase(list<T>::iterator _Iter)
	{
		_Iter.pNode->pPrev->pNext = _Iter.pNode->pNext;
		_Iter.pNode->pNext->pPrev = _Iter.pNode->pPrev;
		auto rtn = list<T>::iterator(_Iter.pNode->pNext);
		delete (_Iter.pNode);
		return rtn;
	}
	list<T>::iterator erase(list<T>::iterator _Iter, list<T>::iterator _Iter2)
	{
		for (auto iter = _Iter ; iter != _Iter2; )
		{
			iter = erase(iter);
		}
		auto rtn = _Iter2;
		return rtn;
	}
	list<T>::iterator insert(list<T>::iterator _Where, T _Data)
	{
		Node<T> * Location = _Where.pNode;
		Node<T> * NewNode = new Node<T>;
		NewNode->Data = _Data;

		NewNode->pNext = Location;
		NewNode->pPrev = Location->pPrev;

		Location->pPrev->pNext = NewNode;
		Location->pPrev = NewNode;

		return list<T>::iterator(NewNode);
	}
	void insert(list<T>::iterator _Where,int _Amount, T _Data)
	{
		list<T>::iterator Location = _Where;
		for (int i = 0; i < _Amount; i++)
		{
			Location = insert(Location, _Data);
		}
	}
	void insert(list<T>::iterator _Where, list<T>::iterator _Begin, list<T>::iterator _End)
	{
		list<T>::iterator Location = _Where;
		for (auto iter = _Begin; iter != _End; iter++)
		{
			 insert(_Where, iter.pNode->Data);
		}
	}

	void merge(list<T>& _list)
	{
		insert(end(),_list.begin(), _list.end());
		_list.clear();
		sort();
	}
	// Àß¸ð¸£°Ú´Ù
	void merge(list<T>& _list, std::function<bool(T A, T B )> _pred)
	{
		for (auto iter = begin(); iter != end(); iter++)		
		{
			for (auto iter2 = _list.begin() +1; iter2 != _list.end(); )
			{
				if (_pred(*iter2,*iter))
				{
					insert(iter,*iter2);
					iter2 = _list.erase(iter2);
				}
				else iter2++;
			}
		}
	}

	list<T>::iterator rbegin() { return end().pNode->pPrev; }
	list<T>::iterator rend() { return begin(); }

	void reverse()
	{
		bool odd = size() % 2 == 0;
		for (int i = 0; i < (odd == true ? size()/2 : (size()+1) /2) ; i++)
		{
			list<T>::iterator Begin = begin() + i;
			list<T>::iterator End = end()-1 -i;
			if (Begin.pNode == End.pNode) break;

			swap(Begin, End);
		}
	}
	void splice(list<T>::iterator _Where, list<T>& _list)
	{
		list<T>::iterator Location = _Where;
		for (auto iter = _list.begin(); iter != _list.end();)
		{
			insert(Location, *iter);
			iter = _list.erase(iter);
		}
	}
	void splice(list<T>::iterator _Where, list<T>& _list, list<T>::iterator _Where2)
	{
		insert(_Where, *_Where2);
		_list.	erase(_Where2);
	}
	void splice(list<T>::iterator _Where, list<T>& _list, list<T>::iterator _Begin, list<T>::iterator _End)
	{
		list<T>::iterator Location = _Where;
		for (auto iter = _Begin; iter != _End; )
		{
			insert(Location, *iter);
			iter = _list.erase(iter);
		}
	}
	void unique()
	{
		for (auto iter = begin(); iter != end();)
		{
			auto  Next = (iter + 1).pNode;
			if (Next->Data == iter.pNode->Data)
			{
				iter = erase(iter);
			}
			else iter++;
		}
	}
	void unique(std::function<bool(T , T )> _pred)
	{
		for (auto iter = begin(); iter != end();)
		{
			auto  Next = (iter + 1);
			if (_pred(*iter,*Next))
			{
				iter = erase(iter);
			}
			else iter++;
		}
	}
	void sort()
	{
		sort([](T A, T B)-> bool {return A > B; });
	}
	void sort(std::function<bool(T,T)> _pred)
	{
		for (auto iter = begin(); iter != end(); iter++)
		{
			for (auto iter2 = iter + 1; iter2 != end(); iter2++)
			{
				if (_pred(*iter, *iter2) == true)
				{
					swap(iter, iter2);
				}
			}

		}
	}
	void swap(list<T>::iterator _iterA, list<T>::iterator _iterB)
	{
		T temp = _iterA.pNode->Data;
		_iterA.pNode->Data = _iterB.pNode->Data;
		_iterB.pNode->Data = temp;
	}
	list<T>::iterator  end() { return iterator(pTail); }
	size_t size() {
		Node<T> * pNode = pHead->pNext;
		size_t nSize = 0;
		while (pNode != pTail)
		{
			pNode = pNode->pNext;
			nSize++;
		}
		return nSize;
	}
	bool empty() { return size() == 0; }

	public:
		list()
		{
			pHead = new Node<T>();
			pTail = new Node<T>();

			pHead->pNext = pTail;
			pHead->pPrev = pHead;

			pTail->pNext = pTail;
			pTail->pPrev = pHead;
		}
		list(int n)
		{
			pHead = new Node<T>();
			pTail = new Node<T>();

			pHead->pNext = pTail;
			pHead->pPrev = pHead;

			pTail->pNext = pTail;
			pTail->pPrev = pHead;

			assign(n, NULL);
		}
		list(int n, T x)
		{
			pHead = new Node<T>();
			pTail = new Node<T>();

			pHead->pNext = pTail;
			pHead->pPrev = pHead;

			pTail->pNext = pTail;
			pTail->pPrev = pHead;

			assign(n, x);
		}
		list(list<T>& _list)
		{
			pHead = _list.pHead;
			pTail = _list.pTail;
		}
		list(list<T>::iterator _begin, list<T>::iterator _end)
		{
			pHead = new Node<T>();
			pTail = new Node<T>();

			pHead->pNext = pTail;
			pHead->pPrev = pHead;

			pTail->pNext = pTail;
			pTail->pPrev = pHead;
			for (auto iter = _begin; iter != _end; iter++)
			{
				push_back(*iter);
			}
		}
		~list()
		{
			Node<T> * s;
			s = pHead;
			while (s != pTail)
			{
				s = s->pNext;
				delete s->pPrev;
			}
			delete s;
		}
};