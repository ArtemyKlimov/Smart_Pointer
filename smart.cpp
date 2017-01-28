#ifndef SMART_CPP
#define SMART_CPP
#include <iostream>
#include "smart.hpp"

template<typename T>
Smart_Ptr<T>::Smart_Ptr(T* _vall):value(_vall), ref_count(1){}

template<typename T>
Smart_Ptr<T>::~Smart_Ptr()
{
	delete value;
}

template<typename T>
T& Smart_Ptr<T>::operator*() const{
	return value;
}

template<typename T>
T* Smart_Ptr<T>::operator ->(){
	if(!value){
		value = new T();
		std::cerr <<"Bad pointer"<<std::endl;
	}
	return value;
}

template<typename T>
size_t Smart_Ptr<T>::use_count() const{
	return ref_counter;
}

template<typename T>
Smart_Ptr<T>&Smart_Ptr<T>::operator=(const Smart_ptr &rhv){
	if(rhv.get()==this->value){
		return *this;	
	}
	if(

}

template<typename T>
T* Smart_Ptr<T>get(){
	return value;
}

#endif




