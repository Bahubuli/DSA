//check if given array is sorted or not using recursion
#include <iostream>
using namespace std;

//
bool is_sorted(int *a, int size)
{
    if (size == 0 || size == 1)
    {
        return true;
    }

    if (a[0] > a[1])
        return false;

    bool ismallersorted = is_sorted(a + 1, size - 1);

    return ismallersorted;
}

bool is_sorted2(int *a, int size)
{
    if (size == 0 || size == 1)
    {
        return true;
    }
    bool ismallersorted = is_sorted(a + 1, size - 1);

    if (a[0] > a[1])
        return false;

    return ismallersorted;
}

int main()
{
    int a[] = {2, 4, 5, 7, 8, 9};
    cout << is_sorted2(a, 6);
}
