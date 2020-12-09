/* 
 * Write a function that receives a linked list of integers,
 * and a pivot value x, and arranges the list according to the pivot:
 * Each value smaller than x, will appear before x.
 * Each value bigger than x, will appear after x. Make no assumptions on the
 * content of the list.
 * Write down your functions time complexity.
 */

#include <iostream>
#include <list>

using namespace std;

void RearangeList(list<int> &main_list, int pivot);
void PrintList(list<int> &main_list);

int main()
{
    list<int> main_list = {40, 20, 10, 15, 30, 25, 50};
    int pivot = 22;

    cout << "Before rearange list:" << endl;
    PrintList(main_list);

    cout << "After rearange list:" << endl;
    RearangeList(main_list, pivot);
    PrintList(main_list);


    return (0);
}

void RearangeList(list<int> &main_list, int pivot) // Time complexity O(n)
{
    list<int>::iterator iter;

    iter = main_list.begin();
    ++iter;

    while (iter != main_list.end())
    {
        if (*iter < pivot)
        {
            main_list.push_front(*iter);
            iter = main_list.erase(iter);
        }
        else
        {
            ++iter;
        }
    }
}

void PrintList(list<int> &main_list) // Time complexity O(n)
{
    list<int>::iterator iter;
    for (iter = main_list.begin(); iter != main_list.end(); ++iter)
    {
        cout << *iter << ", ";
    }

    cout << endl;
}