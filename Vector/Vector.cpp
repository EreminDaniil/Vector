#include <iostream>
#include "Vector.h"

UVector::UVector()
{
    FNode* Array[1];
    Capacity = 1;
}

UVector::UVector(const UVector& other) // copy ctor
{
	if (other.Array == nullptr)
	{
		return;
	}
	FNode* CurrentOther = other.Array;
	FNode* Current = this->Array;
	Current = new FNode;
	Current->Value = CurrentOther->Value;
	SizeVector = other.SizeVector;
	Capacity = other.SizeVector;
	while (CurrentOther->Next != nullptr)
	{
		CurrentOther = CurrentOther->Next;
		FNode* Temp = new FNode;
		Temp->Prev = Current;
		Current->Next = Temp;
		Temp->Value = CurrentOther->Value;
		Current = Temp;
	}
}

UVector& UVector::operator=(const UVector& other) // copy assignment
{
	if (other.Array == nullptr)
	{
		return;
	}
	FNode* CurrentOther = other.Array;
	FNode* Current = this->Array;
	if (other.SizeVector > this->Capacity)
	{
		this->Capacity = other.SizeVector;
	}
	SizeVector = other.SizeVector;
	if (Current == nullptr)
	{
		Current = new FNode;
	}
	Current->Value = CurrentOther->Value;
	while (CurrentOther->Next != nullptr)
	{
		CurrentOther = CurrentOther->Next;
		FNode* Temp;
		if (Current->Next == nullptr)
		{
			Temp = new FNode;
		}
		else
		{
			Temp = Current->Next;
		}
		Temp->Prev = Current;
		Current->Next = Temp;
		Temp->Value = CurrentOther->Value;
		Current = Temp;
	}
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
