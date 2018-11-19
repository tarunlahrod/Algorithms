//using slow and fast pointer approach to find the length of a loop in a linked list.
#include<iostream>

using namespace std;

//basic node element structure with 1. Data and, 
//									2. Pointer to store the address of the next node.

struct node
{
	int data;
	node *next;
} *head;			// head pointer, stores the address of the very first node in the linked list.


/*
Function name: insert()
Input:	value to be inserted into the new node
Output:	void
Functioning: Inserts a new node in the linked list
*/

void insert(int data)
{
	node *newNode = new node;
	newNode -> data = data;		
	newNode -> next = head;
	head = newNode;
}

/*
Function name: printMe()
Input:	pointer to the first node
Output:	void
Functioning: Prints the linked list from head to the last node.
*/


void printMe(node *temp)
{
	if(temp == NULL)
		return;

	cout<<temp->data<<" ";
	printMe(temp->next);
}



/*
Function name: detectloop()
Input:	Pointer to the first node
Output:	Pointer to some node
Functioning: Checks whether there is a loop in linked list or not.
*/

node* detectloop(node *head)
{
	node *slow, *fast;
	slow = fast = head;

	while(fast -> next != NULL && fast -> next -> next !=  NULL)
	{
		fast = fast -> next -> next;
		slow = slow -> next;

		if(slow == fast)
		{
			return fast;
		}
	}

	//while loop terminated means there is no loop in the linked list.
	return 0; 
}



/*
Function name: looplength()
Input:	pointer to the first node.
Output:	length of the loop (int).
Functioning: Finds the length of the loop.
*/

int looplength(node *head)
{
	if(node *t = detectloop(head))
	{
		node *r = t;
		int count=0;
		while(r -> next != t)
		{
			r = r->next;
			count++;
		}
		return count+1;
	}
	else
		return -1;
}

int main()
{
	head = NULL;
	insert(2);
	insert(3);
	insert(23);
	insert(75);
	insert(32);
	insert(56);
	insert(89);

	//creating a loop in data structure
	head->next->next->next->next->next->next->next = head->next;
	//printMe(head);

	int length = looplength(head);
	cout<<length<<endl;
}