#include <iostream>
#include "smart.hpp"

class Foo{
	private:
		int a;
		int b;
	public:
		Foo():a(0),b(0){}
		~Foo(){}
		Foo(int _a, int _b)
			:a(_a), b(_b){}
		int sum(){
			return a+b;
		}
};
int main(int argc, char **argv){

std::cout<<"Hi"<<std::endl;
smartptr<Foo> f1(new Foo(2,4));
std::cout<<f1->sum()<<std::endl;

return 0;
}
