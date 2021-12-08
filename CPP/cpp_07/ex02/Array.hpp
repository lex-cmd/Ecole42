#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <string>
# include <iostream>
# include <cstdlib>

template <class T>
class Array
{
	private:
		T				*data;
		unsigned int	size;

	public:
		Array()
		{
			size = 0;
			data = 0;
		}
		Array(unsigned int n)
		{

			data = new T[n];
			size = n;
		}
		~Array()
		{
			delete data;
		}
		Array(const Array &other)
		{
			this->size = other.size;
			if (other.data)
			{
				this->data = new T[other.size];
				for (int i = 0; i < other.size; i++)
					this->data[i] = other.data[i];
			}
		}

		Array	&operator=(const Array &other)
		{
			if (this->data)
				delete this->data;
			this->data = 0;
			this->size = other.size;
			if (other.data)
			{
				this->data = new T[other.size];
				for (int i = 0; i < other.size; i++)
					this->data[i] = other.data[i];
			}
			return (*this);
		}

		class OutOfRangeException : public std::exception
		{
			const char* what() const throw()
			{
				return ("OutOfRangeException: Element is out of the limits");
			}
		};

		T& operator[](int index)
		{
			if (index >= static_cast<int>(size))
				throw Array::OutOfRangeException();
			return (data[index]);
		}

	
		unsigned int getSize();
};

template <typename T>
unsigned int Array<T>::getSize()
{
	return (this->size);
}

#endif
