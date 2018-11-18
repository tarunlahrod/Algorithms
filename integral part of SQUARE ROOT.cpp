#include<iostream>
using namespace std;

int sqrt(int a)
{
	int i=0;
	while( i*i <= a) 
	{
		i++;
	}
	return i-1;
}

int main()
{
	int a = 10;
	int ans;
	ans = sqrt(a);
	cout<<ans<<endl;
}