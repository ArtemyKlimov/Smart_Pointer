#ifndef SMART_PTR_HPP
#define SMART_PTR_HPP

template <typename T>class Smart_Ptr;
template<typename T>Smart_Ptr<T> make_shared(T* rhv);


template <typename T>
class Smart_Ptr{
private:
	void decrease();
	void increase();
	friend Smart_Ptr<T> make_shared<>(T* rhv); 
public:
	T* pointer;
	int* ref_counter;	
	explicit Smart_Ptr();
	explicit Smart_Ptr(T* _val);
	Smart_Ptr(const Smart_Ptr<T>&rhv);
	~Smart_Ptr();
	T& operator* () const;
	T *operator->();
	bool operator==(const Smart_Ptr<T>& rhv) const;
	bool operator==(const T* rhv) const;
	bool operator!=(const Smart_Ptr<T>& rhv)const;
	bool operator!=(const T* rhv) const;
	int use_count() const;
	void reset();
	Smart_Ptr<T>& operator=(Smart_Ptr<T> const& rhv);
	T* get();
	void delete_if_one_left();
};


template<typename T>
Smart_Ptr<T> make_shared(T* rhv){
	Smart_Ptr<T> ptr;
	ptr.pointer = rhv;
	(*ptr.ref_counter) = 1;

	return ptr;
}


#include "smart_ptr.cpp"
#endif
