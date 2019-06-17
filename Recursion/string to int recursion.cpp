#include<iostream>
#include<cstring>
using namespace std;

int stringToInt(char *a, int n){
	if(n==0)
		return 0;
	return stringToInt(a, n-1)*10 + (a[n-1] - '0'); 		// '0' = -48 because the ASCII value of 0 is 48
}

int main(){
	char a[] = "1234";
	int n = strlen(a);
	int num = stringToInt(a, n);
	cout<<num<<endl;
}
