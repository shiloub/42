#ifndef SPAN_HPP
#define SPAN_HPP
#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>

class Span
{
	private:
		std::vector<int> _stock;
		unsigned int _n;

	public:
		Span(unsigned int N);
		Span(const Span &cpy);
		Span &operator=(const Span &rhs);
		void 			addNumber(int n);
		void			add_by_it(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();
		void			print();
		~Span();
		class AlreadyFullException : public std::exception
		{
			public :
				const char*    what() const throw()
				{
					return ("Vector is full");
				}
		};
		class EmptyExeption : public std::exception
		{
			public :
				const char*    what() const throw()
				{
					return ("Stock size is 0 or 1");
				}
		};
};

void Span::print()
{
	for (unsigned int i = 0; i < this->_stock.size(); i++)
		std::cout << this->_stock[i] << std::endl;
}

Span::Span(unsigned int N) : _n(N)
{
}

Span::Span(const Span &cpy)
{
	this->_n = cpy._n;
	this->_stock = cpy._stock;
}


Span &Span::operator=(const Span &rhs)
{
	this->_n = rhs._n;
	this->_stock = rhs._stock;
	return *this;
}

Span::~Span()
{
}

void Span::addNumber(int n)
{
	if (this->_stock.size() == _n)
		throw Span::AlreadyFullException();
	this->_stock.push_back(n);
}

void	Span::add_by_it(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	std::vector<int> add(begin, end);
	if ((add.size() + this->_stock.size()) > this->_n)
		throw (Span::AlreadyFullException());
	copy(add.begin(), add.end(), std::back_inserter(this->_stock));
}

unsigned int Span::shortestSpan()
{
	unsigned int dif = 4294967295;
	if (this->_stock.size() == 0 || this->_stock.size() == 1)
		throw (Span::EmptyExeption());
	std::sort(this->_stock.begin(), this->_stock.end());

	for(unsigned int i = 0; i < this->_stock.size(); i++)
	{
		for(unsigned int j = i + 1; j < this->_stock.size(); j++)
		{
			if (this->_stock[i] == this->_stock[j])
				return (0);
			else if ((unsigned int)(this->_stock[j] - this->_stock[i]) < dif)
				dif = this->_stock[j] - this->_stock[i];
		}
	}
	return (dif);
}

unsigned int Span::longestSpan()
{
	if (this->_stock.size() == 0 || this->_stock.size() == 1)
		throw (Span::EmptyExeption());
	std::sort(this->_stock.begin(), this->_stock.end());
	return (this->_stock[this->_stock.size() - 1] - this->_stock[0]);
}

#endif