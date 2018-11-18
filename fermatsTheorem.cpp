#include<iostream>
#include<math.h>
using namespace std;


//theorem: if p is a prime number such that p does not divides a then a^(p-1) = 1(mod p)

bool isPrime(int x)
{
	for(int i=2;i<(x/2);i++)
		if(x%i == 0)
			return false;
	return true;
}



void fermats(int a,long pwr,int p)
{
	if(!isPrime(p))
	{
		cout<<endl<<p<<" is not a prime number.\n";
		return;
	}
	if(p%a==0)
	{
		cout<<"\n Numbers are not co-prime.";
		return;
	}

	//now i know that a^(p-1) = 1(mod p)
	int flag=0;

	if(pwr<(p-1))
	{
		long ans = pow(a,pwr);
		ans = ans % ans;
		cout<<"\nAnswer: "<<ans;
	}
	else
		flag++;

	if(flag)
	{
		int rem = pwr % (p-1);
		int ans = pow(a,rem); 
		ans = ans % p;
		cout<<endl<<"Answer: "<<ans;
	}
}


int main()
{
	fermats(4,9,31);		//fermats(a,pwr,p)
								//a = base, p = divisor, pwr = base to the power
}