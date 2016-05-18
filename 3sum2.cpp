#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;

typedef std::vector<int> Array_t;
typedef std::vector<std::vector<int> > Array2_t;

class Solution
{
public:
    Array2_t threeSum(Array_t& a, int target)
    {
        Array2_t res;
        if (a.size() < 3)
            return res; 

        sort(a.begin(), a.end());

        for (int i = 0; i < a.size() - 2; i++)
        {
            for (int j = i + 1; j < a.size() - 1; j++)
            {
                if (a[i] + a[j] < target) //optimize to avoid unnecessary calculation
                {
                    int val = target - a[i] - a[j];

                    //Further optimize
                    std::vector<int>::iterator it;
                    it = std::find(a.begin() + j + 1, a.end(), val);
                    if (it != a.end())
                    {
                        Array_t vec;
                        vec.push_back(a[i]);
                        vec.push_back(a[j]);
                        vec.push_back(val);
                        res.push_back(vec);
                    }
                }
            }
        }

        return res;
    }
};

void dump(Array_t a)
{
    for (int i = 0; i < a.size(); i++)
        std::cout << std::setw(3) << std::left << a[i];
    std::cout << std::endl;
}

void test(int a[], int n, int target)
{
    Array_t vec(a, a + n);
    std::cout << "Original: ";
    dump(vec);

    Solution solution;
    Array2_t res = solution.threeSum(vec, target);

    std::cout << "Target  : " << target << std::endl;
    std::cout << "Result:" << std::endl;
    for (int i = 0; i < res.size(); i++)
        dump(res[i]);
}

int main(int argc, char** argv)
{
    int a[] = {2, 8, 1, 5, 9, 6, 3, 7, 4, 10};
    test(a, 10, 10);
    std::cout << std::endl;

    int b[] = {3, 8, 7, 15, 19, 6, 13, 1, 10};
    test(b, 9, 16);
    return 0;
}
