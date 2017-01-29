#include <iostream>
#include "smart_ptr.hpp"

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
Smart_Ptr<Foo> f1(new Foo(2,3));
std::cout<<f1.use_count()<<std::endl;
std::cout<<f1->sum()<<std::endl; 
std::cout<<"Hi"<<std::endl;
Smart_Ptr<Foo> f2;
f2 = f1;
std::cout<<"lol"<<std::endl;
Smart_Ptr<Foo> f3(f1);
std::cout<<f3->sum()<<std::endl;
std::cout<<f2->sum()<<std::endl;
std::cout<<f2.use_count()<<std::endl;

return 0;
}
