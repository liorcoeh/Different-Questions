/*
 * You are given an array of length 24, where each element represents the
 * number of new subscribers during the corresponding hour.
 * Implement a data structure that efficiently supports the following:
 * update(hour: int, value: int): Increment the element at index hour by value.
 * query(start: int, end: int): Retrieve the number of subscribers that have
 * signed up between start and end (inclusive).
 */

#include <iostream>
#include <cstdlib>

class NewSubscribers
{
public:
    NewSubscribers(int arr[]);
    ~NewSubscribers();

    void update(int hour, int value);
    int query(int start, int end);

    void printArr();

private:
    int *m_arr;
};

NewSubscribers::NewSubscribers(int arr[])
{
    m_arr = new int[24];
    
    for (int i = 0; i < 24; ++i)
    {
        m_arr[i] = arr[i];
    }
}

NewSubscribers::~NewSubscribers()
{
    delete[] m_arr;
}

void NewSubscribers::update(int hour, int value)
{
    m_arr[hour - 1] += value;
}

int NewSubscribers::query(int start, int end)
{
    int total = 0;

    for (int i = start - 1; i < (end - start) + 1; ++i)
    {
        total += m_arr[i];
    }

    return (total);
}

void NewSubscribers::printArr()
{
    for (int i = 0; i < 24; ++i)
    {
        std::cout << m_arr[i] << ", ";
    }
    std::cout << "\n" << std::endl;
}

int main()
{
    system("clear");
    std::cout << "\n" << std::endl;

    int arr[] = {0, 0, 0, 0, 0, 0, 0, 8, 10, 12, 14, 16, 15, 13, 11, 9, 7, 5, 3, 0, 0 ,0 ,0 ,0};
    NewSubscribers main_ns(arr);

    main_ns.printArr();

    main_ns.update(3, 5);
    main_ns.update(5, 3);

    main_ns.printArr();

    std::cout << main_ns.query(3, 19) << std::endl;

    return (0);
}