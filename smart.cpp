#ifndef SMART_CPP
#define SMART_CPP
#include <iostream>
#include "smart.hpp"

template<typename T>
smartptr<T>::smartptr(T* _vall):value(_vall), count(1){}

template<typename T>
smartptr<T>::~smartptr()
{
	delete value;
}

template<typename T>
T& smartptr<T>::operator*() const{
	return value;
}

template<typename T>
T* smartptr<T>::operator ->() const{
//	if(!value){
//		value = new T();
//		std::cerr <<"Bad pointer"<<std::endl;
//	}
	return value;
}

template<typename T>
size_t smartptr<T>::get_count() const{
	return count;
}

#endif
