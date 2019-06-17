#include<iostream>
using namespace std;

int stringToInt(char *a, int n){
	if(n==0)
		return 0;
	int chotaAns = stringToInt(a, n-1);
	cout<<chotaAns<<endl;
	return chotaAns*10 + a[n];
}

int main(){
	char a[] = "1234";
	int n = sizeof(a)/sizeof(int);
	int num = stringToInt(a, n);
	cout<<num<<endl;
}


// for(int i=0; i<n; i++){
// 	sum = 10*sum + a[i];
// }