#ifndef SMART_HPP
#define SMART_HPP

template<typename T> class Smart_ptr;

template <typename T>
class Pointer{
	T* value;
	size_t ref_counter;
	friend class Smart_Ptr;
};

template <typename T>
class Smart_Ptr{
	private:
	Pointer<T>* data;	
	void decrease();
	void increase();
	public:
		Smart_Ptr(T* _val);
		~Smart_Ptr();
		T& operator* () const;
		T *operator->();
		size_t use_count() const;
		Smart_Ptr<T>& operator =(const Smart_ptr<T> &rhv);
		T* get(); 
};

#include "smart.cpp"
#endif
