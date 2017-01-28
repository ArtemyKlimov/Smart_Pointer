#ifndef SMART_HPP
#define SMART_HPP

#include <iostream>

template <typename T>
class smartptr{
	private:
		T* value;
		size_t count;
	public:
		smartptr(T* _val);
		~smartptr();
		T& operator* () const;
		T *operator->() const;
		size_t get_count() const;
};

#include "smart.cpp"
#endif
