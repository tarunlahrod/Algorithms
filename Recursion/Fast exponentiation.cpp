#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include <chrono>

using namespace std::chrono;
using boost::multiprecision::cpp_int;
using namespace std;

cpp_int slowexp(cpp_int a, cpp_int b){
    if(b == 0)
        return 1;
    return a * slowexp(a, b-1);
}

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