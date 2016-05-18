#include <iostream>
using namespace std;

//Assume that a has enough space, >= m+n
int merge_sorted_array(int a[], int m, int b[], int n)
{
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    while (i >= 0 && j >= 0)
    {
        if (a[i] <= b[j])
        {
            a[k--] = b[j--];
        }
        else
        {
            a[k--] = a[i--];
        }
    }

    if (i < 0)
    {
        while (j >= 0)
            a[k--] = b[j--];
    }

    if (j < 0)
    {
        while (i >= 0)
            a[k--] = a[i--];
    }

    return m + n;
}

void dumparray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;
}

void test1()
{
    int a[] = {1, 2, 5, 9, 12, 0, 0, 0, 0, 0, 0,};
    int b[] = {1, 3, 4, 10, 13};
    std::cout << "Original: " << std::endl;
    dumparray(a, 5);
    dumparray(b, 5);

    int c = merge_sorted_array(a, 5, b, 5);
    std::cout << "Merged: ";
    dumparray(a, c);
}

void test2()
{
    int a[] = {1, 3, 3, 5, 6, 0, 0, 0, 0, 0, 0,};
    int b[] = {7, 9, 10, 11, 13};
    std::cout << "Original: " << std::endl;
    dumparray(a, 5);
    dumparray(b, 5);

    int c = merge_sorted_array(a, 5, b, 5);
    std::cout << "Merged: ";
    dumparray(a, c);
}

int main(int argc, char** argv)
{
    test1();
    std::cout << std::endl;
    test2();
    return 0;
}
