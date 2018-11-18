#include<iostream>

using namespace std;

struct node
{
	int data;
	node *next;
}*head;

void insert(int data)
{
	node *newNode = new node;
	newNode -> data = data;		
	newNode -> next = head;
	head = newNode;
}

void printMe(node *temp)
{
	if(temp == NULL)
		return;

	cout<<temp->data<<" ";
	printMe(temp->next);
}

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

	int ans = looplength(head)
	c;out<<ans<<endl;
}