#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  int search(vector<int>& nums, int target) {
        int n = (int)nums.size();
        if (!n) {
            return -1;
        }
        if (n == 1) {
            return nums[0] == target ? 0 : -1;
        }
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) return mid;
            if (nums[0] <= nums[mid]) {
                if (nums[0] <= target && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[n - 1]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }


};

int main() {
  vector<int> nums;
  nums.push_back(8);
  nums.push_back(8);
  nums.push_back(10);
  nums.push_back(1);
  nums.push_back(7);
  nums.push_back(7);

  Solution S;
  int res = S.search(nums, 8);
  cout << res << endl;
}
