#include <iostream>
using namespace std;

int removedup(int a[], int n)
{
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[count] != a[i])
            a[++count] = a[i];
    }

    return count + 1;
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

    int count = removedup(a, 3);
    std::cout << "Removed : ";
    dumparray(a, count);

    int b[] = {1, 1, 2, 2, 3, 5, 5, 7, 9, 9};
    std::cout << "Original: ";
    dumparray(b, 10);

    count = removedup(b, 10);
    std::cout << "Removed : ";
    dumparray(b, count);

    return 0;
}
