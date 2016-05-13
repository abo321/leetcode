#include <iostream>
using namespace std;

int removeelement(int a[], int n, int element)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != element)
            a[count++] = a[i];
    }

    return count;
}

void dumparray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;
}

int main(int argc, char** argv)
{
    int a[] = {1, 1, 2};
    std::cout << "Original: ";
    dumparray(a, 3);

    std::cout << "Removing: 1" << std::endl;
    int count = removeelement(a, 3, 1);
    std::cout << "Removed : ";
    dumparray(a, count);

    int b[] = {1, 1, 2, 2, 3, 5, 2, 7, 2, 9};
    std::cout << "Original: ";
    dumparray(b, 10);

    std::cout << "Removing: 2" << std::endl;;
    count = removeelement(b, 10, 2);
    std::cout << "Removed : ";
    dumparray(b, count);

    return 0;
}
