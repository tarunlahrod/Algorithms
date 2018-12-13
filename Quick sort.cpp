#include<iostream>
using namespace std;

//Partition returns the address of the pivot or the partition point

int partition(int arr[], int start, int end)
{
	int pivot = end;		// selecting the last element as the pivot 

	for(int i=0; i<end-1; i++)
		if(arr[i] >= arr[pivot])
		{
			int temp = arr[i];
			arr[i] = arr[pivot];
			arr[pivot] = temp;
		}
	return pivot;
}

void quicksort(int arr[], int start, int end)
{
	if(start >= end)
		return;
	int partitionIndex = partition(arr, start, end);

	//recursive calls
	quicksort(arr, start, partitionIndex - 1);
	quicksort(arr, partitionIndex + 1, end);
}

int main()
{
	int arr[] = {3,5,7,9,8,6,4,1,2,10};
	int length = sizeof(arr)/sizeof(arr[0]);

	cout<<"Unsorted: ";
	for(int i=0; i<length; i++)
		cout<<arr[i]<<" ";
	cout<<endl;

	quicksort(arr, 0, length);

	cout<<"\nSorted: ";
	for(int i=0; i<length; i++)
		cout<<arr[i]<<" ";
}