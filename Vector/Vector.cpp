#include <iostream>

typedef int Elem;

struct Node
{
    Node* Next; 
    Node* Prev; 
    Elem Value;
};

class Vector {
public:
  class Iterator {
  public:
        Elem& operator*(); // reference to the element
        bool operator==(const Iterator& p) const; // compare positions
        bool operator!=(const Iterator& p) const;
        Iterator& operator++(); // move to next position
        Iterator& operator−−(); // move to previous position
  };
public:

    Vector() // constructor
    {
        Node* Array[1];
        Capacity = 1;
    }

    Vector(const Vector& other) // copy ctor
    {
        if (this != &other) 
        {
            delete[] Array;
            Array = other.Capacity;
            for (size_t i = 0; i < other.SizeVector; i++)
            {
                Array[i] = other.Array[i];
            }
            SizeVector = other.SizeVector;
            Capacity = other.Capacity;
        }
    }

    Vector& operator=(const Vector& other) // copy assignment
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

    ~Vector() // destructor
    {
        delete[] Array;
    }

    bool Empty() const // is vector empty?
    {
        return SizeVector == 0;
    }

    void Erase(size_t index) // remove element at index
    {
        for (size_t i = index + 1; i < SizeVector; ++i)
        {
            Array[i - 1] = Array[i];
        }
        --SizeVector;
    }

    Elem& operator[ ](size_t index) // element at index
    {
        return Array[index];
    }

    const Elem& operator[ ](size_t index) const // element at index
    {
        return Array[index];
    }



    Iterator begin() const; // start position
    Iterator end() const // past the end position
    int Count() const; // number of elements
   
    Elem& At(size_t i); // element at index
    const Elem& At(size_t i) const; // element at index
    
    void Insert(size_t i, const Elem& e); // insert element at index
    void Reserve(size_t n); // reserve at least N spots

private:
    Node* Array;
    size_t SizeVector{};
    size_t Capacity{};
}



int main()
{
    
}
