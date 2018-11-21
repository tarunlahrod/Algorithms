/*
					MERGE SORT
This is inplace merge sort algorithm for merge sort.
Inplace algorithm has space complexity of O(1), i.e. they use constant space.

*/


#include<iostream>
 using namespace std;


//function merge() for merging two half array segments
void merge(int a[], int low, int mid, int high)
{
	int temp[10];
	int i=low;
	int j= mid+1;
	int k=low;

	while( (i<=mid) && (j<=high) )
	{
		if(a[i]<=a[j])
			temp[k++]=a[i++];
		else
			temp[k++] = a[j++];	
	}
	
	while(i<=mid)
		temp[k++] = a[i++];
	
	while(j<=high)
		temp[k++] = a[j++];
	
	for(i=low;i<=high;i++)
		a[i] = temp[i];
}


//function part() for making partitions of the given array into two halves.
void part(int arr[], int low, int high)
{
	int mid;
	if(low!=high)
	{
		mid = (low+high)/2;
		part(arr,low,mid);
		part(arr,mid+1,high);
		merge(arr,low,mid,high);
	}
}

int main()
{
	int arr[10]={5,2,3,6,4,1,8,9,7,10}, low, high, size;

	size = sizeof(arr)/sizeof(arr[0]);

	part(arr,0,size-1);

	cout<<"\nSorted array is : ";
	for(int i = 0 ; i < size ; i++)
		cout<<arr[i]<<" ";
}
