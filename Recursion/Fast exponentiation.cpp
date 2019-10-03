#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include <chrono>

using namespace std::chrono;
using boost::multiprecision::cpp_int;
using namespace std;

/*
Recurrance relation: a^b = a*a^(b-1)
 f(a,b) = a*f(a,b-1)
Time Complexity recurrance relation: T(b) = t(b-1) + b
Time Complexity = O(n)
*/ 
cpp_int slowexp(cpp_int a, cpp_int b){
    if(b == 0)
        return 1;
    return a * slowexp(a, b-1);
}


/*
Logic (Problem breaking): a^b = (a^(b/2))^2
Recurrance relation (/: integral divide):
f(a,b) = ( f(a,b/2) )^2 , if b: even
f(a,b) = (( f(a,b/2) )^2)*a , if b: odd

Time Complexity recurrance relation: T(b) = T(b/2) + 1
Time Complexity = O(log(b)) 
*/
cpp_int fexp(cpp_int a, cpp_int b){
    if(b==0)
        return 1;
    cpp_int hexp = fexp(a, b/2);
    if(b%2==0)
        return hexp*hexp;
    else
        return hexp*hexp*a;
}

int main() {
	
	auto start = high_resolution_clock::now();
    cout<<"Fast exponentiaion: "<<fexp(2,2000);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop-start);
    cout<<"\nTime: "<<duration.count()<<" microseconds\n\n";

    start = high_resolution_clock::now();
    cout<<"\nSlow exponentiaion: "<<slowexp(2,2000);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop-start);
    cout<<"\nTime: "<<duration.count()<<" microseconds\n";

	return 0;
}
