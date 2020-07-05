#include <iostream>
#include <vector>
#include <deque>

using std::vector;
using std::deque;

class solution
{
  public:
    vector<int> maxSlidingWindow(const vector<int> & nums, int k) {
        vector<int> result;
        deque<int> indx;
        int id = 0;
        indx.push_front(id);
        id++;
        for (;id < k;id++) {
            if (nums[id] >= nums[indx.front()])
                indx.push_front(id);
            else {
                while(nums[indx.back()] < nums[id])
                    indx.pop_back();
                indx.push_back(id);
            }
        }
        result.push_back(nums[indx.front()]);

        while ((size_t)id < nums.size()) {
            while (id-indx.front() >= 3)
                indx.pop_front();
            if (nums[id] >= nums[indx.front()])
                indx.push_front(id);
            else {
                while(nums[indx.back()] < nums[id])
                    indx.pop_back();
                indx.push_back(id);
            }
            id++;
            result.push_back(nums[indx.front()]);
        }

        return result;
    }
};

int main() {
    // vector<int> nums{1,3,-1,-3,5,3,6,7};
    // vector<int> nums{1,2,3,1,4,5,2,3,6};
    // vector<int> nums{8,5,10,7,9,4,15,12,90,13};
    int n = 0;
    std::cin >> n;

    vector<int> A(n);
    for (size_t i = 0; i < n; ++i)
        std::cin >> A.at(i);

    int w = 0;
    std::cin >> w;

    solution soln;
    auto res = soln.maxSlidingWindow(A, w);

    for (auto i : res)
        std::cout << i << " ";
    std::cout << std::endl;
}
