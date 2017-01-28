#ifndef SMART_HPP
#define SMART_HPP

template <typename T>
class pointer{
	T* value;
	size_t ref_founter;

};

template <typename T>
class Smart_Ptr{
	private:
		T* value;
		size_t ref_counter;
	public:
		Smart_Ptr(T* _val);
		~Smart_Ptr();
		T& operator* () const;
		T *operator->();
		size_t use_count() const;
		Smart_ptr& operator =(const Smart_ptr &rhv);
		T* get(); 
};

#include "smart.cpp"
#endif
