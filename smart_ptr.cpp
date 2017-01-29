#ifndef SMART_PTR_CPP
#define SMART_PTR_CPP
#include <iostream>
#include <utility>
#include "smart_ptr.hpp"

template<typename T>
Smart_Ptr<T>::Smart_Ptr():pointer(nullptr), ref_counter(new int(0)){}

template<typename T>
Smart_Ptr<T>::Smart_Ptr(T* _val):pointer(_val),ref_counter(new int(1)){}

template<typename T>
Smart_Ptr<T>::Smart_Ptr(const Smart_Ptr<T> &rhv){
	pointer = rhv.pointer;
	ref_counter = rhv.ref_counter;
	increase();
}

template<typename T>
void Smart_Ptr<T>::decrease(){
	--(*ref_counter);
	if((*ref_counter) <1){
			delete ref_counter;	
			if(pointer !=nullptr)
				delete pointer;
	}
}

template<typename T>
Smart_Ptr<T>::~Smart_Ptr(){
	decrease();
}

template<typename T>
Smart_Ptr<T>& Smart_Ptr<T>::operator=(Smart_Ptr<T> const&rhv){
		decrease();
		this->pointer = rhv.pointer;
		this->ref_counter = rhv.ref_counter;
		increase();
	return *this;
}

template<typename T>
T& Smart_Ptr<T>::operator*() const{
	return pointer;
}

template<typename T>
T* Smart_Ptr<T>::operator ->(){
	if(!pointer){
		pointer = new T();
		std::cerr <<"Bad pointer"<<std::endl;
	}
	return pointer;
}


template<typename T>
int Smart_Ptr<T>::use_count() const{
	return *ref_counter;
}


template<typename T>
T* Smart_Ptr<T>::get(){
	return pointer;
}

template<typename T>
void Smart_Ptr<T>::increase(){
	if(ref_counter != nullptr)
		++(*ref_counter);
}

#endif




