#include<iostream>
using namespace std;

void merge(int *x, int *y, int *a, int s, int e){
	int i = s;
	int mid = (s+e)/2;
	int j = mid+1;
	int k = s;

	while(i<=mid && j<=e){
		if(x[i]<y[j]){
			a[k] = x[i];
			i++; k++;
		}
		else{
			a[k++] = y[j++];
		}
	}

	while(i<=mid){
		a[k++] = x[i++];
	}
	while(j<=e){
		a[k++] = y[j++];
	}
}

void mergeSort(int *a, int s, int e){
	// Base case: no element
	if(s>=e)
		return;

	// Recursive case
	// Step 1: divide
	int mid = (s+e)/2;
	int x[100], y[100];

	for(int i=s; i<=mid; i++){
		x[i] = a[i];
	}

	for(int i=mid+1; i<=e; i++){
		y[i] = a[i];
	}


	// Step 2: sort
	mergeSort(x, s, mid);
	mergeSort(y, mid+1, e);


	// Step 3: merge
	merge(x, y, a, s, e);
}

int main(){
	int a[] = {2,1,4,3,6,5};
	int n = sizeof(a)/sizeof(int);
	int start = 0, end = n-1;
	mergeSort(a, start, end);

	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}