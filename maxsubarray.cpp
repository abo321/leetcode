#include <vector>
#include <climits>
#include <iomanip>
#include <iostream>
using namespace std;

typedef std::vector<int> Array_t;

class Solution
{
public:
    int maxSubArray(Array_t& a)
    {
        int maxsum = INT_MIN;
        int tsum = 0;

        for (int i = 0; i < a.size(); i++)
        {
            tsum = max(tsum + a[i], a[i]);
            maxsum = max(tsum, maxsum); 
        }

        return maxsum;
    }
};

void dump(Array_t a)
{
    for (int i = 0; i < a.size(); i++)
        std::cout << std::setw(4) << std::left << a[i];
    std::cout << std::endl;
}

void test(int a[], int n)
{
    Array_t vec(a, a + n);
    std::cout << "Original: ";
    dump(vec);

    Solution solution;
    int maxsum = solution.maxSubArray(vec);

    std::cout << "Max sum : " << maxsum << std::endl;
}

int main(int argc, char** argv)
{
    int a[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    test(a, 9);
    std::cout << std::endl;

    int b[] = {3, 8, 7, 15, 19, 6, 13, 1, 10};
    test(b, 9);
    std::cout << std::endl;

    int c[] = {-3, 8, -7, 15, -19, 6, -13, 1, 10};
    test(c, 9);
    return 0;
}
