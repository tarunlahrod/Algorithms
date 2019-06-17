#include<iostream>
using namespace std;

int stringToInt(char *a, int n){
	if(n==0)
		return 0;
	return stringToInt(a, n-1)*10 + (a[n-1]-48); 		// -48 because the ASCII value of 0 is 48
}

int main(){
	char a[] = "1234";
	int n = sizeof(a)/sizeof(char) - 1;
	int num = stringToInt(a, n);
	cout<<num<<endl;
}
