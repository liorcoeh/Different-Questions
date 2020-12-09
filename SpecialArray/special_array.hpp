// Implement the following class:
    
// class Array
// {
// public:
//     Array(int size)
//     void setval (int indx, int val); // O(1)
//     int getval (int indx) const; // O(1)
//     void setall (int val); // O(1)
// };

#include <iostream>
#include <ctime>

using namespace std;

class Array
{
public:
    Array(int size);
    ~Array();
    void Insert(int val);
    void SetVal(int index, int val); // O(1)
    int GetVal(int index) const; // O(1)
    void SetAll(int val); // O(1)
    bool IsFull();
    void Print();

private:
    struct Member
    {
        int m_value;
        int m_total;
    };
    int m_size;
    int m_index;
    struct Member* arr;
};