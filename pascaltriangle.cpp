#include <vector>
#include <iomanip>
#include <iostream>
using namespace std;

typedef std::vector<std::vector<int> > Array2_t;

Array2_t pascaltriangle(int rows)
{
    Array2_t a;
    a.resize(rows);

    for (int i = 0; i < rows; i++)
    {
        a[i].resize(i + 1);
        a[i][0] = 1;
        a[i][i] = 1;  //the second i is a[i].size() - 1
        for (int j = 1; j < i; j++)
            a[i][j] = a[i-1][j-1] + a[i-1][j];
    }

    return a;
}

void dump(Array2_t a)
{
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[i].size(); j++)
            std::cout << std::setw(3) << std::left << a[i][j];
        std::cout << std::endl;
    }
}

int main(int argc, char** argv)
{
    Array2_t a = pascaltriangle(1);
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
    std::cout << std::endl;
    return 0;
}
