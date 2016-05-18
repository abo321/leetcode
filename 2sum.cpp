#include <vector>
#include <iomanip>
#include <iostream>
#include <unordered_map>
using namespace std;

typedef std::vector<int> Array_t;

class Solution
{
public:
    Array_t twoSum(Array_t& a, int target)
    {
        Array_t indexvec;
        if (a.size() <= 1 )
            return indexvec; 

        //create a non-ordered map as hash map to store the value and index
        unordered_map<int, int> tmap;
        for (int i = 0; i < a.size(); i++)
            tmap[a[i]] = i + 1;
        
        for (int i = 0; i < a.size(); i++)
        {
            int val2 = target - a[i];
            if (tmap.find(val2) != tmap.end())
            {
                int index = tmap[val2];
                if (index -1 == i)
                    continue;  //ingore the same index

                if (index -1 < i)
                {
                    indexvec.push_back(index);
                    indexvec.push_back(i + 1);
                    return indexvec;
                }


                indexvec.push_back(i + 1);
                indexvec.push_back(index);
                return indexvec;
            }
        }
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
    //Array_t vec;
    //for (int i = 0; i < n; i++)
    //    vec.push_back(a[i]);
    Array_t vec(a, a + n);

    std::cout << "Original: ";
    dump(vec);

    Solution solution;
    Array_t indexvec = solution.twoSum(vec, target);

    std::cout << "Target  : " << target;
    std::cout << ", index: ";
    dump(indexvec);
}

int main(int argc, char** argv)
{
    int a[] = {12, 8, 17, 5, 9, 6, 3, 11, 1, 20};
    test(a, 10, 10);
    std::cout << std::endl;

    int b[] = {2, 8, 7, 15, 19, 6, 13, 1, 10};
    test(b, 9, 13);
    return 0;
}
