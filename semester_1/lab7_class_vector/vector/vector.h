#pragma once
#include <initializer_list>
class Vector
{
private:
	size_t size_ = 0;
	int* data_ = nullptr;
	int capacity_ = 0;
public:
	Vector()
	{
		size_ = 0;
		data_ = nullptr;
		capacity_ = 0;
	}
	Vector(int n)
	{
		size_ = n;
		data_ = new int[n];
		for (size_t i = 0; i < n; ++i)
		{
			data_[i] = 0;
		}
		capacity_ = (sizeof(int) * n);
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
		capacity_ = (sizeof(int) * list.size());
	}
	Vector(const Vector& other)
	{
		size_ = other.size_;
		data_ = new int[other.size_];
		for (size_t i = 0; i < other.size_; ++i)
		{
			data_[i] = other.data_[i];
		}
		capacity_= (sizeof(int) * other.size_);
	}
	int& operator[](size_t index) 
	{
		return data_[index];
	}
	const int& operator[](size_t index) const
	{
		return data_[index];
	}
};
