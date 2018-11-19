//the code is under development and might generate undesired output.

#include <iostream>
using namespace std;

void printMe(int a[], int size)
{
	for(int i=0; i<size; i++)
		cout<<" "<<a[i];
	cout<<"\n";
}

void swap(int &a, int &b)
{
	int t=a;
	a=b;
	b=t;
}

void merge(int a[], int ls, int le, int rs, int re)
{
	int i=ls, j=rs, k=ls;

	while(i<le && j<re)
	{
		if(a[i] < a[j])
		{
			// a[k] = a[i];
			swap(a[k],a[i]);
			i++;
		}
		else
		{
			// a[k] = a[j];
			swap(a[k],a[i]);
			j++;
		}
		k++;
	}

	while(i<le)
	{
		// a[k] = a[i];
		swap(a[k],a[i]);
		i++;
		k++;
	}

	while(j<re)
	{
		// a[k] = a[j];
		swap(a[k],a[j]);
		j++;
		k++;
	}
}

int main()
{
	int a[]={1,3,5,7,2,4,6,8};
	int size=8;

	merge(a,0,3,4,7);
	printMe(a,size);
}
