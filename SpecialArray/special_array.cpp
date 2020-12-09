
#include <math.h>

#include "special_array.hpp"

using namespace std;

const int barrier = (pow(2, 32) / 2) - 1;;

Array::Array(int size) : m_size(size), m_index(0)
{
    arr = new struct Member[size + 1];
    arr[m_size].m_value = -1;
    arr[m_size].m_total = -1;
}

Array::~Array()
{
    delete[] arr;
}

void Array::Insert(int val)
{
    if (IsFull())
    {
        cout << "Array is full" << endl;
        return;
    }

    arr[m_index].m_value = val;
    arr[m_index].m_total = arr[m_size].m_total + 1;
    ++m_index;
}

void Array::SetVal(int index, int val)
{
    arr[index].m_value = val;
    arr[index].m_total = arr[m_size].m_total + 1;
}

int Array::GetVal(int index) const
{
    // The case where the last function on the "index" was SetAll()
    if (arr[index].m_total - arr[m_size].m_total != 1)
    {
        return (arr[m_size].m_value);
    }
    // The case where the last function on the "index" was SetVal()
    else
    {
        return (arr[index].m_value);
    }
}

void Array::SetAll(int val)
{
    arr[m_size].m_value = val;
    if (arr[m_size].m_total == barrier - 1) // If we get to the maximum int
    {                                       // it will do a reset and will
        arr[m_size].m_total = -1;           // start from the begining.
        for (int i = 0; i < m_size; ++i)    // It wont be O(1), but it has to
        {                                   // be done
            arr[i].m_total = -1;
        }
    }
    arr[m_size].m_total += 1;
}

bool Array::IsFull()
{
    if (m_index == m_size)
    {
        return (true); // Full
    }

    return (false); // Not Full
}

void Array::Print()
{
    for (int i = 0; i < m_size; ++i)
    {
        printf("%d, ", GetVal(i)); 
    }
    printf("\n\n");
}
