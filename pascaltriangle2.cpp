#include <vector>
#include <iomanip>
#include <iostream>
using namespace std;

typedef std::vector<int> Array_t;

Array_t pascaltriangle(int rows)
{
    Array_t a;
    a.resize(rows, 1);

    for (int i = 1; i < rows; i++)
    {
        for (int j = i - 1; j >= 1; j--)
            a[j] = a[j-1] + a[j];
    }

    return a;
}

void dump(Array_t a)
{
    for (int i = 0; i < a.size(); i++)
        std::cout << std::setw(3) << std::left << a[i];
    std::cout << std::endl;
}

int main(int argc, char** argv)
{
    Array_t a = pascaltriangle(1);
    dump(a);
    std::cout << std::endl;

    a = pascaltriangle(2);
    dump(a);
    std::cout << std::endl;

    a = pascaltriangle(3);
    dump(a);
    std::cout << std::endl;

    a = pascaltriangle(6);
    dump(a);
    std::cout << std::endl;

    a = pascaltriangle(9);
    dump(a);
    return 0;
}
