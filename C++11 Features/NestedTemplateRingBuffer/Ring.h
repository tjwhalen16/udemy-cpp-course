#pragma once

template<class T>
class Ring
{
public:
	class Iterator;

	Ring::Ring(int size) : t_(new T[size]), size_(size) {
		begin_ = t_;
		end_ = t_ + size*sizeof(t_);
	}

	void Ring::Add(T t) {
		(*t_) = t;
		MoveIt();
	}

	T Ring::Get(int i) {
		return *(begin_ + i * sizeof(t_));
		//return begin_[i];
	}

	int Ring::size() {
		return size_;
	}

	T* begin() { return begin_; }
	T* end() { return end_; }

private:
	T *t_;
	T *begin_;
	T *end_;
	int size_;

	void MoveIt() {
		t_ += sizeof(t_);
		if (t_ == end_) { t_ = begin_; }
	}
	
};

template<class T>
class Ring<T>::Iterator {

};

