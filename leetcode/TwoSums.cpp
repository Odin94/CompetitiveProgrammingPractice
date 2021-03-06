#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> index_by_num;
        for (int i = 0; i < nums.size(); i++) {
            int pair_index = target - nums[i];
            if (index_by_num.count(pair_index) != 0 && index_by_num[pair_index] != i) {
                vector<int> solution = {index_by_num[pair_index], i};
                return solution;
            }

            index_by_num[nums[i]] = i;
        }

        int i = nums.size() - 1;
        int pair_index = target - nums[i];
        if (index_by_num.count(pair_index) != 0 && index_by_num[pair_index] != i) {
            vector<int> solution = {index_by_num[pair_index], i};
            return solution;
        }

        return {};
    }
};