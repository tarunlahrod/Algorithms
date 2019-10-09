#include<iostream>
using namespace std;

void printMe(int a[], int size)
{
	for(int i=0; i<size; i++)
		cout<<" "<<a[i];
	cout<<"\n";
}


void insertionSort(int a[], int size)
{
	for(int i = 1; i < size ; i++)
	{
		int val = a[i];
		int hole = i;

		while(hole > 0 && a[hole-1] > val)
		{
			a[hole] = a[hole-1];
			hole = hole - 1;
		}
		a[hole] = val;
	}
}

int main()
{
	int size = 25;
	int b[] = {2,5,6,9,7,4,3,1,8,12,45,78,89,56,23,45,78,45,56,89,4,8,213,23,1};
	insertionSort(b,size);
	printMe(b,size);
}
