#pragma once
#include <initializer_list>
#include <utility>
#include <algorithm>
#include <ostream>

class Vector
{
private:
	size_t size_ = 0;
	int* data_ = nullptr;
	size_t capacity_ = 0;
public:
	
	Vector()
	{
		size_ = 0;
		data_ = nullptr;
		capacity_ = 0;
	}
	Vector(size_t n)
	{
		size_ = n;
		data_ = new int[n];
		for (size_t i = 0; i < n; ++i)
		{
			data_[i] = 0;
		}
		capacity_ = n;
	}	
	Vector(std::initializer_list<int> list)
	{
		size_ = list.size();
		data_ = new int[list.size()];
		for (size_t i = 0; int number : list)
		{
			data_[i] = number;
			++i;
		}
		capacity_ =  list.size();
	}
	Vector(const Vector& other)
	{
		size_ = other.size_;
		data_ = new int[other.capacity_];
		for (size_t i = 0; i < other.size_; ++i)
		{
			data_[i] = other.data_[i];
		}
		capacity_=  other.capacity_;
	}
	~Vector()
	{
		delete[] data_;
	}
	Vector& operator=(const Vector& other)
	{
		if (this == &other) 
		{
			return *this;
		}
		size_ = other.size_;
		delete[] data_;
		data_ = new int[other.capacity_];
		std::copy(other.data_, other.data_ + size_, data_);
		capacity_ =  other.capacity_;
		return *this;
	}
	void Swap(Vector& other) 
	{
		std::swap(size_, other.size_);
		std::swap(data_, other.data_);
		std::swap(capacity_, other.capacity_);
	}
	int& operator[](size_t index) 
	{
		return data_[index];
	}
	const int& operator[](size_t index) const
	{
		return data_[index];
	}
	int Size()
	{
		return size_;
	}
	int Capacity()
	{
		return capacity_;
	}
	void PushBack(int number)
	{
		if ((size_ + 1) <= capacity_)
		{
			data_[size_] = number;
			size_ = size_ + 1;

		}
		else
		{
			size_t size_new_ = (size_+1);
			size_t capacity_new_;
			if (capacity_ == 0) 
			{
				capacity_new_ = 1;
			}
			else 
			{
				capacity_new_ = capacity_ * 2;
			}
			int* data_new_ = new int[capacity_new_];
			for (size_t i = 0; i < size_; ++i)
			{
				data_new_[i] = data_[i];
			}
			data_new_[size_] = number;
			delete[] data_;
			size_ = size_new_;
			capacity_ = capacity_new_;
			data_ = data_new_;
		}
	}
	void PopBack()
	{
		if (size_ == 0)
		{
			return;
		}
		size_--;
	}
	void Clear()
	{
		size_ = 0;
	}
	void Reserve(size_t amount)
	{
		if (capacity_ >= amount)
		{
			return;
		}
    size_t capacity_new_ = amount;
	int* data_new_ = new int[capacity_new_];
	for (size_t i = 0; i < size_; ++i)
	{
		data_new_[i] = data_[i];
	}
	delete[] data_;
	capacity_ = capacity_new_;
	data_ = data_new_;
		
	}
	
};
std::ostream& operator<<(std::ostream& cout,  Vector& vector)
{
	cout << "[";
	if (vector.Size() == 0)
	{
		cout << "]";
	}
	for (size_t i = 0; i < vector.Size()-1; ++i)
	{
		cout << vector[i] << ", ";
	}
	cout << vector[vector.Size() - 1];
	cout << "]\n";
	return cout;
}
