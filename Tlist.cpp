#include "Tlist.h"

int main()
{	
	BNode<int>* head1 = nullptr;
	BNode<int>* end1 = nullptr;
	BList<int> list1;
	int a[]{  4, 2, 3, 9, 7, 8 };
	int size1 = 6;

	int b[]{ 10, 11, 6 };
	int size2 = 3;

	list1.addToHead(1);
	head1=list1.getHead();
	list1.print();
	list1.addAfterBNode(head1, 5);
	head1 = list1.getHead();
	list1.print();
	list1.addGroupAfterBNode(head1, a, size1);
	head1 = list1.getHead();
	list1.print();

	list1.deleteFromHead();
	head1 = list1.getHead();
	list1.print();
	list1.deleteGroupFromHead(2);
	head1 = list1.getHead();
	list1.print();

	list1.swapElem(head1, 13);
	list1.print();
	list1.swapGroup(head1->next, b, size2);
	list1.print();

	std::cout << "--------------------------------" << std::endl;
	BNode<int>* head2 = nullptr;
	BNode<int>* end2 = nullptr;
	BList<int> list2;
	int c[]{ 4, 5, 3, 6, 7, 8 };
	int size3 = 6;

	list2.addToHead(1);
	head2 = list2.getHead();
	list2.addAfterBNode(head2, 2);
	list2.addGroupToHead(c, size3);
	head2 = list2.getHead();
	list2.print();
	list2.deleteAfterBNode(head2);
	list2.print();
	list2.deleteGroupAfterBNode(head2->next,2);
	list2.print();

	std::cout << "--------------------------------" << std::endl;
	BNode<int>* headc = nullptr;
	BNode<int>* endc = nullptr;
	BList<int> listc;
	listc=list1.combine(list2, 5, 5);
	listc.print();

	std::cout << "--------------------------------" << std::endl;
	listc = list1.intersect(list2, 5, 5);
	listc.print();

	return 0;
}