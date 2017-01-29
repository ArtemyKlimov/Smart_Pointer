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
		bool operator==(const Foo& lvh)const{
			return (a ==lvh.a && b ==lvh.b);
		}
};
int main(int argc, char **argv){
Smart_Ptr<Foo> f1(new Foo(2,3));//создан 1
std::cout<<f1.use_count()<<std::endl;
std::cout<<f1->sum()<<std::endl; 
std::cout<<"Hi"<<std::endl;
Smart_Ptr<Foo> f2;//по-прежнему 1
f2 = f1;
Smart_Ptr<Foo> f3(f1);//по-прежнему 1
Foo* f4 = f1.get();
std::cout<<"f4 sum is: "<<f4->sum()<<std::endl;
std::cout<<f3->sum()<<std::endl;
std::cout<<f2->sum()<<std::endl;
std::cout<<f2.use_count()<<std::endl;
if(f2 == f1){
	std::cout<<"Yes, they are equal!"<<std::endl;
}
if(f1 == f4){
	std::cout<<"Yes, they are equal!"<<std::endl;
}
f1.reset();
std::cout<<f3.use_count()<<std::endl;
Smart_Ptr<Foo> f5 = f2;
Smart_Ptr<Foo> f6(new Foo(15,16));
std::cout<<f6.use_count()<<std::endl;
std::cout<<f5.use_count()<<std::endl;
std::cout<<f1.use_count()<<std::endl;
f5 = f1;
std::cout<<f5.use_count()<<std::endl;
std::cout<<f3.use_count()<<std::endl;

return 0;
}


