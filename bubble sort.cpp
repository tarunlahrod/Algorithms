/*
			BUBBLE SORT
Time complexity: O(n^2)
Space complexity: O(1)

*/

#include<iostream>
using namespace std;

//printMe() is a function to print the array which is passed to it as parameter
void printMe(int a[], int size)
{
	for(int i=0; i<size; i++)
		cout<<" "<<a[i];
	cout<<"\n";
}

//bubble sort function

void bubbleSort(int a[], int size)
{
	int flag;
	/* flag is a variable we used to make our code a bit more optimised and efficient.
	   The code would have been iterated for size-1 times (which generally happens in a basic bubble sort)
	   in absence of this variable flag. In bubble sort even if the given array has been 
	   sorted even then the code keep iterating for size-1 times (which makes it redundant). 
	   So for optimisation we use this concept of flag. What it does is that it is initialised
	   as 0 (zero) and is upgraded to 1 whenever a swapping between the elements if performed and then
	   made equal to zero after every pass. Say during any iteration in between if the flag didn't changed, which implies
	   that our array is now sorted, hence we break out of the iterator.
	   This concept optimised our code.
	 */

	for(int i=0;i<size-1;i++)
	{
		flag = 0;
		for(int j = 0;j<size-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				int t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
				flag = 1;
			}
		}
		if(flag == 0)
			break;
	}
}


int main()
{
	//initialisations
	int arr[]={5,4,7,9,3,1,2,8,6,0};
	int size;

	//finding the size of the array arr
	size = sizeof(arr)/sizeof(arr[0]);
	cout<<"\nUnsorted array (before bubble sort) : ";
	printMe(arr,size);
	bubbleSort(arr,10);
	cout<<"\nSorted array (after bubble sort) : ";
	printMe(arr,size);
}
