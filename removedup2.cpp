#include <iostream>
using namespace std;

int removedup2(int a[], int n)
{
    int count = 0;
    int occurrence = 1;

    for (int i = 1; i < n; )
    {
        if (a[count] != a[i])
        {
            occurrence = 1;
            a[++count] = a[i++];
        }
        else
        {
            occurrence++;
            if (occurrence <= 2)
                a[++count] = a[i++];
            else
                i++;
        }
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
    int a[] = {1, 1, 1, 2, 2, 2, 3, 3, 3};
    //int a[] = {1, 1, 2, 2, 3, 3, 4, 4, 5};
    std::cout << "Original: ";
    dumparray(a, 9);

    int count = removedup2(a, 9);
    std::cout << "Removed : ";
    dumparray(a, count);

    int b[] = {1, 1, 1, 2, 5, 5, 5, 9, 9, 9};
    std::cout << "Original: ";
    dumparray(b, 10);

    count = removedup2(b, 10);
    std::cout << "Removed : ";
    dumparray(b, count);

    return 0;
}
