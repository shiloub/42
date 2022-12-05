#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>
#include <stdexcept>

template <typename T>
class Array
{
	private :
		T *array;
		unsigned int _size;
	
	public :
		Array();
		Array(unsigned int);
		Array(const Array &cpy);
		~Array();
		Array	&operator=(const Array &rhs);
		T		&operator[](unsigned int i) const;
		unsigned int size() const;

};

template <typename T>
std::ostream &operator<<(std::ostream &stream, const Array<T> &rhs);


//implementations des fonctions

template <typename T>
Array<T>::Array() : _size(0)
{
	array = new T[_size];
}

template <typename T>
Array<T>::Array(unsigned int size)
{
	this->_size = size;
	this->array = new (std::nothrow) T[_size];
	if (!this->array)
	{
		std::cout << "error : bad alloc\n";
		this->_size = 0;
		return ;
	}
	for (unsigned int i = 0; i < _size; i++)
	{
		this->array[i] = T();
	}
}

template <typename T>
unsigned int Array<T>::size() const
{
	return this->_size;
}

template <typename T>
Array<T>::Array(const Array &cpy)
{
	this->_size = cpy._size;
	this->array = new T[_size];
	for (unsigned int i = 0; i < _size; i++)
	{
		this->array[i] = cpy.array[i];
	}
}

template <typename T>
Array<T>::~Array()
{
	delete [] this->array;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &rhs)
{
	this->_size = rhs._size;
	delete [] this->array;
	this->array = new T[_size];
	for (unsigned int i = 0; i < _size; i++)
	{
		this->array[i] = rhs.array[i];
	}
	return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int i) const
{
	if (i >= this->_size)
		throw std::out_of_range("index out of range");
	return this->array[i];
}

template <typename T>
std::ostream &operator<<(std::ostream &stream, Array<T> &array)
{
	for (unsigned int i = 0; i < array.size(); i++)
		stream << array[i] << std::endl;
	return (stream);
}

#endif