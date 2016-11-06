#pragma once

#include <iostream>
#include <string>

template<class T>
class Ring
{
public:
	class Iterator;
	Ring(int size);
	Ring(const Ring &other);
	~Ring();	
	Iterator begin();
	Iterator end();
	Ring& operator=(const Ring rhs);
	void Add(T t);
	T& Get(int i);
	int size();

private:
	int pos_;
	int size_;
	T *t_;	
};

template<class T>
class Ring<T>::Iterator {
public:
	Iterator(int pos, Ring &ring) : pos_(pos), ring_(ring) {
	}
	
	// Prefix
	Iterator& operator++() {
		pos_++;
		return *this;
	}
	// Postfix
	Iterator& operator++(int) {
		pos_++;
		return *this;
	}

	T& operator*() {
		return ring_.Get(pos_);
	}

	bool operator!=(const Iterator &rhs) const {
		return pos_ != rhs.pos_;
	}

private:
	int pos_;
	Ring &ring_;
};

template<class T>
Ring<T>::Ring(int size) : pos_(0), size_(size), t_(new T[size_]) {
}

template<class T>
Ring<T>::Ring(const Ring &other) : pos_(0), size_(other.size_), t_(new T[size_]) {
	std::cout << "Copy size: " << size_*sizeof(T) << '\n';
	std::memcpy(t_, other.t_, size_*sizeof(T));
}

template<class T>
Ring<T>::~Ring() {
	std::cout << "delete\n";
	delete[] t_;
}

template<class T>
typename Ring<T>::Iterator Ring<T>::begin() {
	return Ring<T>::Iterator(0, *this);
}

template<class T>
typename Ring<T>::Iterator Ring<T>::end() { // Outerclass<T>::Innerclass needs typename if it is a type(not a member), which it is in this case... the return type
	return Ring<T>::Iterator(size_, *this);
}

template<class T>
Ring<T>& Ring<T>::operator=(const Ring<T> rhs) {
	std::cout << "=\n";
	std::swap(rhs);
	return *this;
}

template<class T>
void Ring<T>::Add(T t) {
	t_[pos_++] = t;
	if (pos_ == size_) {
		pos_ = 0;
	}
	
}

template<class T>
T& Ring<T>::Get(int i) {
	return t_[i];
}

template<class T>
int Ring<T>::size() {
	return size_;
}

