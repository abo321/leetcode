#include <vector>
#include <iomanip>
#include <iostream>
using namespace std;

typedef std::vector<std::vector<int> > Array2_t;

class Solution
{
public:
    int minTotal(Array2_t& a)
    {
        for (int i = a.size() - 2; i >= 0; i-- )
            for (int j = 0; j < i + 1; j++)
                a[i][j] += min(a[i+1][j], a[i+1][j+1]);

        return a[0][0];
    }
};

void dump(Array2_t a)
{
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[i].size(); j++)
            std::cout << std::setw(3) << std::left << a[i][j];
        std::cout << std::endl;
    }
}

void test()
{
    int a[4][4] = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}
    };

    Array2_t v; 
    for (int i = 0; i < 4; i++)
    {
        vector<int> vec(a[i], a[i] + i + 1);
        v.push_back(vec);
    }

    std::cout << "Original triangle:" << std::endl;
    dump(v);
    std::cout << std::endl;

    Solution solution;
    int total = solution.minTotal(v);
    std::cout << "Min total: " << total << std::endl;
}

int main(int argc, char** argv)
{
    test();
    return 0;
}
