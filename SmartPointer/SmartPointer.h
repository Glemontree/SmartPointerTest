#ifndef __SMART_POINTER_H__
#define __SMART_POINTER_H__
template <typename T>
class SmartPointer {
public:
	SmartPointer(T* ptr);
	SmartPointer(SmartPointer<T> &from);
	SmartPointer<T>& operator = (SmartPointer<T>& from);
	~SmartPointer();
	T getValue();
	unsigned getRefCount();

protected:
	void remove();

private:
	T* ref;
	unsigned* refCount;
};

template <typename T>
SmartPointer<T>::SmartPointer(T* ptr) {
	ref = ptr;
	refCount = (unsigned*) malloc(sizeof(unsigned));
	*refCount = 1;
}

template <typename T>
SmartPointer<T>::SmartPointer(SmartPointer<T> &from) {
	ref = from.ref;
	refCount = from.refCount;
	++(*refCount);
}

template <typename T>
SmartPointer<T>& SmartPointer<T>::operator = (SmartPointer<T>& sptr) {
	if (this == sptr) return this;
	if (*refCount > 0) {
		remove();
	}
	ref = sptr.ref;
	refCount = sptr.refCount;
	(*refCount)++;
	return *this;
}

template <typename T>
SmartPointer<T>::~SmartPointer() {
	remove();
}

template <typename T>
T SmartPointer<T>::getValue() {
	return *ref;
}

template <typename T>
void SmartPointer<T>::remove() {
	--(*refCount);
	if (*refCount == 0) {
		delete ref; // 对象使用delete释放资源
		free(refCount); // 内置对象使用free释放资源
		ref = nullptr;
		refCount = nullptr;
	}
}

template <typename T>
unsigned SmartPointer<T>::getRefCount() {
	return *refCount;
}
#endif