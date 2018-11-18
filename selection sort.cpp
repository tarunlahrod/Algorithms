#include<iostream>
using namespace std;
 
void printMe(int a[], int size)
{

 	for(int i=0;i<size - 1;i++)
 		cout<<" "<<a[i];
 	cout<<"\n";
}

 void InsertionSort(int a[], int size)
 {
 	int iMin;
 	for(int i=0; i < size-2; i++)
 	{
 		iMin = i;
 		for(int j=i+1;j<size-1;j++)			//this loop will give me the index of the smallest element in the remaining array.
 			if(a[j] < a[iMin])
 				iMin = j;

 		int t = a[i];
 		a[i] = a[iMin];
 		a[iMin] = t;
  	}
 	printMe(a,size);	
 }


int main()
{
	int a[] = {2,6,4,8,9,3,1,5,7};
	InsertionSort(a,9);
}