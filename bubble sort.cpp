/*
			BUBBLE SORT
Time complexity: O(n^2)
Space complexity: O(1)

*/

#include<iostream>
using namespace std;

void printMe(int a[], int size)
{
	for(int i=0; i<size; i++)
		cout<<" "<<a[i];
	cout<<"\n";
}


void bubbleSort(int a[], int size)
{
	int flag;

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