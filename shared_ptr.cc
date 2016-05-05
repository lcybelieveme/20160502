///
///@date   2016-05-04 15:37:01
///
 
 
 
#include <iostream>
#include <memory>
using std::cin;
using std::cout;
using std::endl;
using std::shared_ptr;

int main()
{
	shared_ptr<int> p(new int(100));
	cout<<p<<endl;
	cout<<*p<<endl;
	shared_ptr<int> p1(p);
	cout<<p1<<endl;
	cout<<*p1<<endl;
	shared_ptr<int> p3=p1;
	cout<<p3<<endl;
	cout<<*p3<<endl;
}
