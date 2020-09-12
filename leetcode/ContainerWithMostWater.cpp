#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int maxArea(vector<int> &height) {
        int leftIndex = 0;
        int rightIndex = height.size() - 1;
        int biggestArea = 0;

        while (leftIndex < rightIndex) {
            int area = min(height[leftIndex], height[rightIndex]) * (rightIndex - leftIndex);
            biggestArea = max(area, biggestArea);

            if (height[leftIndex] < height[rightIndex]) {
                leftIndex++;
            } else {
                rightIndex--;
            }
        }

        return biggestArea;
    }
};