
#include "special_array.hpp"

using namespace std;

int main()
{
    system("clear");
    cout << "\n\n" << endl;

    int size = 10;
    Array main_arr(size);

    for (int i = 0; i < size; ++i)
    {
        main_arr.Insert(i + 1);
    }
    main_arr.Print();

    main_arr.SetAll(0);
    main_arr.Print();
    main_arr.SetAll(1);
    main_arr.Print();

    main_arr.SetVal(1, 3);
    main_arr.Print();

    cout << "main_arr[1] is (3): " << main_arr.GetVal(1) << "\n" << endl;

    for (int i = 0; i < 6; ++i)
    {
        main_arr.SetAll(i);
        main_arr.Print();
    }

    main_arr.SetAll(8);
    main_arr.Print();
    
    cout << "\n\n" << endl;

    return (0);
}