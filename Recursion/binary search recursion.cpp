#include<iostream>
using namespace std;

int binarySearch(int *a, int key, int left, int right){

	if(right >= left){

		int mid = (left+right)/2;
		
		if(a[mid]==key)
			return mid;

		if(key < a[mid])
			return binarySearch(a, key, left, mid-1);

		return binarySearch(a, key, mid+1, right);
	}
	// not found case
	return -1;
}

int main(){
	int a[] = {1,2,3,4,5,6,7,8,9};
	int n = sizeof(a)/sizeof(int);
	int i = binarySearch(a, 17, 0, n);
	cout<<i<<endl;
}