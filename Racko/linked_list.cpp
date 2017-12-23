#include "linked_list.h"
#ifndef LIST_CPP
#define LIST_CPP
#include <cassert>
#include <iostream>
#include <string>
using namespace std;

template <class NODETYPE>
void linked_list<NODETYPE>::initList()
{
	destroyList();
	first = NULL;
	current = NULL;
	last = NULL;
	count = 0;
}


template <class NODETYPE>
linked_list<NODETYPE>::linked_list()
{
	first = NULL;
	current = NULL;
	last = NULL;
	count = 0;
}
template <class NODETYPE>
void linked_list<NODETYPE>::destroyList()
{
	if (!IsEmpty())
	{
		current = first;
		while (current != NULL)
		{
			first = first->next;
			delete current;
			current = first;
		}
		current = last = first = NULL;
		count = 0;
	}
}
template <class NODETYPE>
linked_list<NODETYPE>::~linked_list()
{
	destroyList();
}
template <class NODETYPE>
int linked_list<NODETYPE>::length()
{
	return count;
}
template <class NODETYPE>
linked_list<NODETYPE>::linked_list(linked_list<NODETYPE> &originalList)
{
	first = NULL;
	copyList(originalList);
}
template <class NODETYPE>
void linked_list<NODETYPE>::copyList(const linked_list<NODETYPE>& otherList)
{
	ListNode<NODETYPE> *newNode; //pointer to create a node

	if (first != NULL) //if the list is nonempty, make it empty
		destroyList();

	if (otherList.first == NULL) //otherList is empty
	{
		first = NULL;
		last = NULL;
		count = 0;
	}
	else
	{
		current = otherList.first; //current points to the 
		//list to be copied
		count = otherList.count;

		//copy the first node
		first = new ListNode<NODETYPE>;  //create the node

		assert(first != NULL);

		first->data = current->data; //copy the info
		first->next = NULL;        //set the link field of 
		//the node to NULL
		last = first;              //make last point to the
		//first node
		current = current->next;     //make current point to
		//the next node

		//copy the remaining list
		while (current != NULL)
		{
			newNode = new ListNode<NODETYPE>;  //create a node

			assert(newNode != NULL);

			newNode->data = current->data; //copy the info
			newNode->next = NULL;       //set the link of 
			//newNode to NULL
			last->next = newNode;  //attach newNode after last
			last = newNode;        //make last point to
			//the actual last node
			current = current->next;   //make current point 
			//to the next node
		}//end while
	}//end else
}//end copyList

template <class NODETYPE>
bool linked_list<NODETYPE>::Remove(NODETYPE & value)
{
	ListNode<NODETYPE> *trailCurrent; //pointer just before current
	bool found;

	if (first == NULL){ //Case 1
		cout << "Cannot delete from an empty list." << endl;
		return false;
	}
	else
	{
		current = first;
		found = false;

		while (current != NULL && !found)  //search the list
		{
			if (current->data >= value)
				found = true;
			else
			{
				trailCurrent = current;
				current = current->next;
			}
		}

		if (current == NULL) {  //Case 4
			cout << "The item to be deleted is not in the list." << endl;
			return false;
		}
		else
			if (current->data == value) //the item to be 
				//deleted is in the list
			{
				if (first == current)       //Case 2
				{
					first = first->next;

					if (first == NULL)
						last = NULL;
					value = current->data;
					delete current;
				}
				else                         //Case 3
				{
					trailCurrent->next = current->next;

					if (current == last)
						last = trailCurrent;
					value = current->data;
					delete current;
				}
				count = 0;
				return true;
			}
			else{                            //Case 4
				cout << "The item to be deleted is not in the list." << endl;
				return false;
			}
	}

}

template <class NODETYPE>
bool linked_list<NODETYPE>::InsertInOrder(const NODETYPE value)
{
	if (IsEmpty())
	{
		// A variable used to point to data that is being inserted.
		ListNode<NODETYPE> *temp = new ListNode<NODETYPE>;

		if (temp == NULL) return false;

		temp->data = value;

		first = last = current = temp;
		last->next = NULL;
		count++;
	}
	else if (value >= last->data)
	{
		count++;
		return InsertLast(value);
	}
	else if (first->data >= value)
	{
		count++;
		return InsertFirst(value);
	}
	else
	{
		// A variable used to point to data that is being inserted.
		ListNode<NODETYPE> *temp = new ListNode<NODETYPE>;

		if (temp == NULL) return false;

		temp->data = value;

		current = first;
		while (current->next->data < temp->data)
		{
			current = current->next;
		}
		temp->next = current->next;
		current->next = temp;
		count++;
		return true;
	}
}
template <class NODETYPE>
bool linked_list<NODETYPE>::InsertFirst(const NODETYPE value)
{
	// A variable used to point to data that is being inserted.
	ListNode<NODETYPE> *temp = new ListNode<NODETYPE>;
//	cout<< value << endl;
	if (temp == NULL) return false;

	temp->data = value;
	if (first == NULL)
		temp->next = NULL;
	else
		temp->next = first;
	first = current = temp;

	return true;
}
template <class NODETYPE>
bool linked_list<NODETYPE>::InsertLast(const NODETYPE value)
{
	// A variable used to point to data that is being inserted.
	ListNode<NODETYPE> *temp = new ListNode<NODETYPE>;

	if (temp == NULL) return false;
	temp->data = value;
	if (last == NULL)
	{
		last = temp;
		first = last;
	}
	else
		last->next = temp;
	last = current = temp;
	last->next = NULL;

	return true;
}

template <class NODETYPE>
bool linked_list<NODETYPE>::IsEmpty() const
{
	return (first == NULL);
}

template <class NODETYPE>
bool linked_list<NODETYPE>::Search(NODETYPE &value)
{
	if (IsEmpty())
	{
		cout << "List is Empty\n";
		return false;
	}
	else
	{
		current = first;
		while ((current != NULL) && (current->data != value))
		{
			current = current->next;
		}
		if (current == NULL)
		{
			return false;
		}
		else
		{
			value = current->data;
			return true;
		}
	}
}


template <class NODETYPE>
void linked_list<NODETYPE>::PrintAll()
{
	if (!IsEmpty())
	{
		current = first;
		while (current != NULL)
		{
			cout << current->data << endl;
			current = current->next;
		}
	}
	else cout << "The list is empty.\n";
}

template <class NODETYPE>
void linked_list<NODETYPE>::stutterTwo()
{
	current = first;
	while (current != NULL &&  current->next != NULL ) { 
		ListNode<NODETYPE> *copy = new ListNode<NODETYPE>;
		copy->data = current->data;
		ListNode<NODETYPE> *copy2 = new ListNode<NODETYPE>;
		copy2->data = current->next->data;
		copy2->next=current->next->next;
		copy->next=copy2;
		current->next->next  =  copy;
		current   =   current->next->next->next->next;
	}

}
template <class NODETYPE>
void linked_list<NODETYPE>:: printReverse(){
	ListNode<NODETYPE> *temp = new ListNode<NODETYPE>;
	temp = last;
	while(temp != first){
		cout << temp->data << endl;
		current = first;
		while(current->next != temp){
			current = current->next;
		}
		temp = current;
	}
	cout << first->data << endl;
}
template <class NODETYPE>
bool linked_list<NODETYPE>::isListSorted(){
	bool sort = true;
	current = first;
	while((current->next != NULL)&& sort == true){
		if(current->data > current->next->data){
			sort = true;
		}
		else{
			sort = false;
		}
		current = current->next;
	}
	return sort;
}
template <class NODETYPE>
bool linked_list<NODETYPE>::replace(NODETYPE findNode, NODETYPE replaceNode){
	bool found = false;
	current = first;
	cout<<"the value to find is: " << findNode << endl;
	cout<<"the replacement is: " << replaceNode << endl;
	while(!found && current != NULL){
	//	cout << current->data << endl;
		if(current->data == findNode){
			found = true;
			current->data = replaceNode;
		}
		else{
			current = current->next;
		}
	}
	return found;
}
#endif
