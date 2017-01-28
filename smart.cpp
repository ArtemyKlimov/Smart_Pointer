#ifndef SMART_CPP
#define SMART_CPP
#include <iostream>
#include <utility>
#include "smart.hpp"

template<typename T>
Smart_Ptr<T>::Smart_Ptr(T* _val){
	data = new Pointer<T>();
	data->value = _val;
	data->ref_counter = 1;
}

template<typename T>
Smart_Ptr<T>::~Smart_Ptr()
{
	delete data;
}

template<typename T>
T& Smart_Ptr<T>::operator*() const{
	return data->value;
}

template<typename T>
T* Smart_Ptr<T>::operator ->(){
	if(!data->value){
		data->value = new T();
		std::cerr <<"Bad pointer"<<std::endl;
	}
	return data->value;
}

template<typename T>
size_t Smart_Ptr<T>::use_count() const{
	return data->ref_counter;
}

template<typename T>
Smart_Ptr<T>&Smart_Ptr<T>::operator=(const Smart_ptr<T> &rhv){
	if(data->value !=rhv.get()){
		decrease();
		data = rhv.data;
		++data->ref_counter;
	
	}

	return *this;
}

template<typename T>
T* Smart_Ptr<T>::get(){
	return data->value;
}

template<typename T>
void Smart_Ptr<T>::decrease(){
	--data->ref_counter;
	if(data->counter == 0){
		delete data->value;
		delete data;	
	}
}

#endif




