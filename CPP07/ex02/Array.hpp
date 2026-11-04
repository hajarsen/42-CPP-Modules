#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <exception>

template <typename T>
class Array
{
private:
    T *data;
    unsigned int arraySize;
	
public:
    Array() : data(NULL), arraySize(0)
    {
    }

    Array(unsigned int n) : data(new T[n]()), arraySize(n)
    {
    }

    Array(const Array &other) : data(NULL), arraySize(other.arraySize)
    {
        if (arraySize)
        {
            data = new T[arraySize]();
            for (unsigned int i = 0; i < arraySize; ++i)
                data[i] = other.data[i];
        }
    }

    ~Array()
    {
        delete[] data;
    }

	Array &operator=(const Array &other)
	{
		if (this != &other)
		{
			delete[] data;

			arraySize = other.arraySize;

			if (arraySize > 0)
				data = new T[arraySize]();
			else
				data = NULL;

			for (unsigned int i = 0; i < arraySize; ++i)
				data[i] = other.data[i];
		}

		return *this;
	}

    T &operator[](unsigned int i)
    {
        if (i >= arraySize)
            throw OutOfBoundsException();

        return data[i];
    }

    const T &operator[](unsigned int i) const
    {
        if (i >= arraySize)
            throw OutOfBoundsException();

        return data[i];
    }

    unsigned int size() const
    {
        return arraySize;
    }

    class OutOfBoundsException : public std::exception
    {
    public:
        virtual const char *what() const throw()
        {
            return "Array index out of bounds";
        }
    };
};

#endif