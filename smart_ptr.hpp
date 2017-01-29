#ifndef SMART_PTR_HPP
#define SMART_PTR_HPP

template <typename T> class make_shared;


template <typename T>
class Smart_Ptr{
private:
	T* pointer;
	int* ref_counter;	
	void decrease();
	void increase();
public:
		Smart_Ptr();
		Smart_Ptr(T* _val);
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
		//friend class make_shared; 
};



#include "smart_ptr.cpp"
#endif
