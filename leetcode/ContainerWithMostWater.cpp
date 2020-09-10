#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int maxArea(vector<int> &height) {
        int biggestArea = 0;
        for (int i = 0; i < height.size(); i++) {
            for (int j = i; j < height.size(); j++) {
                int area = min(height[i], height[j]) * (j - i);
                if (area > biggestArea)
                    biggestArea = area;
            }
        }

        return biggestArea;
    }
};