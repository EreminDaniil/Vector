#include <iostream>
#include "Vector.h"

UVector::UVector()
{
    FNode* Array[1];
    Capacity = 1;
}

UVector::UVector(const UVector& other) // copy ctor
{
    if (this != &other) 
    {
        delete[] Array;
        size_t Array = other.Capacity;
        for (size_t i = 0; i < other.SizeVector; i++)
        {
            Array[i] = other.SizeVector[i];
        }
        SizeVector = other.SizeVector;
        Capacity = other.Capacity;
    }
}

std::vector

UVector::UVector& operator=(const UVector& other) // copy assignment
{
    if (this != &other)
    {
        delete[] Array;
    }
	Array = other.Capacity;
    for (size_t i = 0; i < other.SizeVector; ++i)
    {
        Array[i] = other.Array[i];
    }
    SizeVector = other.SizeVector;
    Capacity = other.Capacity;
	return *this;
}

UVector::~UVector() // destructor
{
    delete[] Array;
}

bool UVector::Empty() const // is vector empty?
{
    return SizeVector == 0;
}

void UVector::Erase(size_t index) // remove element at index
{
    for (size_t i = index + 1; i < SizeVector; ++i)
    {
        Array[i - 1] = Array[i];
    }
    --SizeVector;
}

Elem& UVector::operator[ ](size_t index) // element at index
{
    return Array[index];
}

const Elem& UVector::operator[ ](size_t index) const // element at index
{
    return Array[index];
}



Iterator begin() const
Iterator end() const // past the end position
int UVector::Count() const
Elem& At(size_t i); // element at index
const Elem& At(size_t i) const; // element at index

void Insert(size_t i, const Elem& e); // insert element at index
void Reserve(size_t n); // reserve at least N spots




int main()
{
    
}
