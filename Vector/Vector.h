#pragma once
#include <iostream>

typedef int Elem;

struct FNode
{
	FNode* Next;
	FNode* Prev;
	Elem Value;
};

class UVector
{
public:
	class Iterator
	{
	public:
		Elem& operator*()
		{
			return *Point;
		}
		bool operator==(const Iterator& p) const
		{
			return Point == p.Point;
		}
		bool operator!=(const Iterator& p) const
		{
			return Point != p.Point;
		}
		Iterator& operator++()
		{
			++Point;
			return *this;
		}
		Iterator& operator−−()
		{
			--Point;
			return *this;
		}
	private:
		Elem* Point;
	};
public:
	UVector();
	UVector(const UVector& other);
	UVector& operator=(const UVector& other);
	~UVector();
	bool Empty() const;
	void Erase(size_t index);
	Elem& operator[ ](size_t index);
	const Elem& operator[ ](size_t index) const;
	Iterator begin() const;
	Iterator end() const;
	int Count() const;
	Elem& At(size_t i);
	const Elem& At(size_t i) const;
	void Insert(size_t i, const Elem& e);
	void Reserve(size_t n);
private:
	FNode* Array;
	size_t SizeVector{};
	size_t Capacity{};
};