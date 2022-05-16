#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> res = {-1, -1};
    int tmp = bsearch(nums, 0, nums.size() - 1, target);
    if (tmp == -1) return res;
    for (int i = tmp; nums[i] == target && i >= 0; i++) res[1] = i;
    for (int i = tmp; nums[i] == target && i < nums.size(); i--) res[0] = i;
    return res;
  }
  int bsearch(vector<int>& nums, int l, int r, int target) {
    while (l <= r) {
      int tmp = (l + r) >> 1;
      if (nums[tmp] > target) {
        r = tmp - 1;
      } else if (nums[tmp] < target) {
        l = tmp + 1;
      } else {
        return tmp;
      }
    }
    return -1;
  }
};

int main() {
  vector<int> nums;
  nums.push_back(1);
  // nums.push_back(7);
  // nums.push_back(7);
  // nums.push_back(8);
  // nums.push_back(8);
  // nums.push_back(10);
  Solution S;
  nums = S.searchRange(nums, 1);
  cout << nums[0] << ' ' << nums[1] << endl;
}
