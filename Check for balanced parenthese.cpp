/*
						BALANCED PARENTHESES IN AN EXPRESSION
To check the balance we take the expression consist of '(', '{', '[', ')', ']', '}' and other expression.
Our motive is to check the balance of these parenthese only and not the correctness of the expression.

Logic:
	~> Scan from left to right.
	~> If opening symbol, add it to the list.
	~> If closing symbol, remove the opening symbol from the list (last symbol must be matching pair of the closing symbol).
	~> Should end with an empty list.

For the structure of the list, we are using STACK.(why?)
	~ because stack works on LIFO (Last In First Out). So checking the last element in the list
	  will be just a constant time operation for us because insertion and deletion from stack both takes constant time i.e. O(1).
	*/

#include<iostream>
#include <stack>
using namespace std;

char checkForOpeningPair(char ch)
{
	if(ch == '}')
		return '{';
	if(ch == ')')
		return '(';
	if(ch == ']')
		return '[';
}

bool isItBalanced(char expression[], int lenght)
{
	stack <char> s;
	for(int i = 0; i < lenght; i++)
	{
		if (expression[i] == '(' ||	expression[i] == '{' ||	expression[i] == '[' )		//opening brackets
			{
				s.push(expression[i]);
				cout<<endl << expression[i] <<" pushed";
			}

		else if (	expression[i] == ')' ||	expression[i] == '}' ||	expression[i] == ']' )		//closing brackets
		{
			cout<<endl<<expression[i] <<" encountered";
			if(s.empty() || s.top() != checkForOpeningPair(expression[i]) ) 
				return false;
			else 			// means the current parenthese is same as the top most element, so remove the topmost element.
				{
					cout<<endl<< s.top() << " popped";
					s.pop();
				}
		}
	}

	return (s.empty()) ? true : false;
}

int main()
{
	char expression[] = {"2(8-3)*(5-6)-(56(45)-2)"};
	int size;
	size = (sizeof(expression) - 1)/sizeof(expression[0]);
	if(isItBalanced(expression,size))
		cout<<"\n\nExpression is BALANCED.";
	else 
		cout<<"\n\nExpression is UNBALANCED.";
}
