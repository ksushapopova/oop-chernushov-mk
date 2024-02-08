#pragma once

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

template<typename datatype>
struct BNode {
	datatype value;
	BNode<datatype>* next;
	BNode<datatype>* prev;
	BNode(datatype newValue)
	{
		next = nullptr;
		prev = nullptr;
		value = newValue;
	}
};

template<typename datatype>
class BList
{
	BNode<datatype>* head;
	BNode<datatype>* end;
	void clear();
	void addBeforeBNode(BNode<datatype>* n, datatype value);
	void deleteBeforeBNode(BNode<datatype>* n);
	void addToEnd(datatype value);
	void deleteFromEnd();
	bool searchForDuplicates(int elem);

public:
	BList();
	BNode<datatype>* getEnd();
	BNode<datatype>* getHead();
	void addAfterBNode(BNode<datatype>* p, datatype value);
	void deleteAfterBNode(BNode<datatype>* p);
	void addToHead( datatype value);
	void deleteFromHead();
	void addGroupToHead(datatype values[], int size);
	void addGroupAfterBNode(BNode<datatype>* pBNode, datatype values[], int size);
	void addElem(BNode<datatype>* p, datatype value);
	void addGroup(BNode<datatype>* p, datatype values[], int size);
	void deleteElem(BNode<datatype>* p);
	void deleteGroup(BNode<datatype>* p, int size);
	void deleteGroupFromHead(int size);
	void deleteGroupAfterBNode(BNode<datatype>* pBNode, int size);
	void print();
	bool isEmpty();
	void swapElem(BNode<datatype>* pBNode, datatype value);
	void swapGroup(BNode<datatype>* pBNode, datatype values[], int size);


	BList<datatype> combine(const BList<datatype>& other, int size1, int size2);
	BList<datatype> intersect(const BList<datatype>& other, int size1, int size2);
};


template<typename datatype>
void BList<datatype>::clear()
{
	while (!isEmpty())
	{
		deleteFromHead();
	}
}

template <typename datatype>
BList<datatype>::BList() : head(nullptr), end(nullptr){}


template <typename datatype>
void BList<datatype>::addToHead(datatype value)
{
	BNode<datatype>* ptr = new BNode<datatype>(value);
	ptr->next = head;
	if (head != nullptr)
	{
		head->prev = ptr;
	}
	head = ptr;
	if (head->next == nullptr)
	{
		end = ptr;
	}
}


template <typename datatype>
void BList<datatype>::deleteFromHead()
{
	if (head != nullptr)
	{
		BNode<datatype>* ptr = head;
		head = ptr->next;
		if (ptr->next != nullptr)
		{
			ptr->next->prev = nullptr;
		}
		else
		{
			end = nullptr;
		}
		ptr->next = nullptr;
		ptr->prev = nullptr;
		delete ptr;
		ptr = nullptr;
	}
}

template <typename datatype>
void BList<datatype>::addToEnd(datatype value)
{
	BNode<datatype>* ptr = new BNode<datatype>(value);
	ptr->prev = end;
	if (end != nullptr)
	{
		end->next = ptr;
	}
	if (head == nullptr)
	{
		head = ptr;
	}
	end = ptr;
}

template <typename datatype>
void BList<datatype>::deleteFromEnd()
{
	if (end != nullptr)
	{
		BNode<datatype>* ptr = end;
		end = ptr->prev;
		if (ptr->prev != nullptr)
		{
			ptr->prev->next = nullptr;
		}
		else
		{
			head = nullptr;
		}
		ptr->next = nullptr;
		ptr->prev = nullptr;
		delete ptr;
		ptr = nullptr;
	}
}

template <typename datatype>
BNode<datatype>* BList<datatype>::getEnd()
{
	return end;
}

template <typename datatype>
BNode<datatype>* BList<datatype>::getHead()
{
	return head;
}

template <typename datatype>
void BList<datatype>::addAfterBNode(BNode<datatype>* pBNode, datatype value)
{
	BNode<datatype>* p = new BNode<datatype>(value);
	if (pBNode != end)
	{
		p->next = pBNode->next;
		pBNode->next->prev = p;
	}
	else
	{
		end = p;
	}
	pBNode->next = p;
	p->prev = pBNode;
}

template <typename datatype>
void BList<datatype>::addBeforeBNode(BNode<datatype>* nBNode, datatype value)
{
	BNode<datatype>* p = new BNode<datatype>(value);

	if (nBNode != head)
	{
		//p->prev = nBNode->prev;
		nBNode->prev->next = p;
	}
	else
	{
		head = p;
	}
	nBNode->prev = p;
	p->next = nBNode;

}

template <typename datatype>
void BList<datatype>::deleteAfterBNode(BNode<datatype>* pBNode)
{
	if (pBNode != end)
	{
		BNode<datatype>* p = pBNode->next;
		pBNode->next = p->next;
		if (p != end)
		{
			p->next->prev = pBNode;
		}
		else
		{
			end = pBNode;
		}
		p->next = nullptr;
		p->prev = nullptr;
		delete p;
		p = nullptr;
	}
}

template <typename datatype>
void BList<datatype>::deleteBeforeBNode(BNode<datatype>* nBNode)
{
	if (nBNode != head)
	{
		BNode<datatype>* p = nBNode->prev;
		nBNode->prev = p->prev;
		if (p != head)
		{
			p->prev->next = nBNode;
		}
		else
		{
			head = nBNode;
		}
		p->next = nullptr;
		p->prev = nullptr;
		delete p;
		p = nullptr;
	}
}

template <typename datatype>
void BList<datatype>::addElem(BNode<datatype>* pBNode, datatype value)
{
	if (head == nullptr)
	{
		addToHead(value);
	}
	else
	{
		addAfterBNode(pBNode, value);
	}
}

template <typename datatype>
void BList<datatype>::addGroupToHead(datatype values[], int size)
{
	//BNode<datatype> ptr;
	for (int i=0; i<size; i++)
	{
		addToHead(values[i]);
	}
}

template <typename datatype>
void BList<datatype>::addGroupAfterBNode(BNode<datatype>* pBNode, datatype values[], int size)
{
	//BNode<datatype> ptr;
	for (int i = 0; i < size; i++)
	{
		addAfterBNode(pBNode, values[i]);
	}
}

template <typename datatype>
void BList<datatype>::deleteElem(BNode<datatype>* pBNode)
{
	if (head != pBNode)
	{
		deleteAfterBNode(pBNode);
	}
	else
	{
		deleteFromHead();
	}
}

template <typename datatype>
void BList<datatype>::deleteGroupFromHead(int size)
{
	for (int i = 0; i < size; i++)
	{
		deleteFromHead();
	}
}

template <typename datatype>
void BList<datatype>::deleteGroupAfterBNode(BNode<datatype>* pBNode, int size)
{
	for (int i = 0; i < size; i++)
	{
		deleteAfterBNode(pBNode);
	}
}

template <typename datatype>
void BList<datatype>::print()
{
	if (head == nullptr)
	{
		std::cout << "nullptr" << '\n';
	}
	else
	{
		BNode<datatype>* current = head;
		while (current != nullptr)
		{
			std::cout << current->value << '\t';
			current = current->next;
		}
		std::cout << '\n';
	}
}

template <typename datatype>
bool BList<datatype>::isEmpty()
{
	return !(head);
}

template<typename datatype>
void BList<datatype>::swapElem(BNode<datatype>* pBNode, datatype elem)
{
	pBNode->value=elem;
}

template<typename datatype>
void BList<datatype>::swapGroup(BNode<datatype>* pBNode, datatype values[], int size)
{
	for (int i = 0; i < size; i++)
	{
		swapElem(pBNode, values[i]);
		pBNode = pBNode->next;
	}
}

template<typename datatype>
bool BList<datatype>::searchForDuplicates(int elem)
{
	BNode<datatype>* p1=head;
	while (p1 != nullptr)
	{
		if (p1->value == elem)
		{
			return true;
		}
		p1 = p1->next;
	}
	return false;
}

template<typename datatype>
BList<datatype> BList<datatype>::combine(const BList<datatype>& other, int size1, int size2)
{
	BNode<datatype>* p1 = head;
	BNode<datatype>* p2 = other.head;
	BList<datatype> result;
	while(p1!=nullptr) {
		result.addToHead(p1->value);
		p1 = p1->next;
	}
	while (p2!=nullptr)
	{
		if (!result.searchForDuplicates(p2->value))
		{
			result.addToHead(p2->value);
		}
		p2=p2->next;
	}
	return result;
}


template<typename datatype>
BList<datatype> BList<datatype>::intersect(const BList<datatype>& other, int size1, int size2)
{
	BNode<datatype>* p1 = head;
	BNode<datatype>* p2 = other.head;
	BNode<datatype>* headr = nullptr;
	BNode<datatype>* endr = nullptr;
	BList<datatype> result;
	for (int i = 0; i < size1; i++) 
	{
		for (int j = 0; j < size2; j++)
		{
			if (p1->value == p2->value)
			{
				result.addToHead(p1->value);
				headr = result.getHead();
			}
			p2 = p2->next;
		}
		p2 = other.head;
		p1= p1->next;
	}
	return result;
}

