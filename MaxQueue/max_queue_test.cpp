
#include <iostream>
#include <cstdlib>

#include "max_queue.hpp"

using namespace std;

int main()
{
    system("clear");
    cout << "\n\nMain Test\n---------\n" << endl;

    QueueMax<int> my_queue;

    cout << "The queue is empty (1): " << my_queue.IsEmpty() << endl;
    cout << "The queue size is (0): " << my_queue.Size() << "\n" << endl;

    my_queue.Push(4);
    my_queue.Push(9);
    my_queue.Push(7);
    my_queue.Push(6);
    my_queue.Push(1);
    my_queue.Push(2);
    my_queue.Push(5);

    cout << "The queue is not empty: " << my_queue.IsEmpty() << endl;
    cout << "The queue size is: " << my_queue.Size() << endl;
    cout << "The first element is: " << my_queue.Peek() << endl;
    cout << "The max element is: " << my_queue.GetMax() << "\n" << endl;

    my_queue.Pop();
    my_queue.Pop();
    my_queue.Pop();

    cout << "The first element is: " << my_queue.Peek() << endl;
    cout << "The max element is: " << my_queue.GetMax() << endl;

    cout << "\n\n" << endl;

    return (0);
}