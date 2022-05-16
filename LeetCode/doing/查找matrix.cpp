#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int l = 0, r = m * n - 1;
    while (l <= r) {
      int mid = (r - l) / 2 + l;
      int x = matrix[mid / n][mid % n];
      if (x == target) return 1;
      if (x < target)
        l = mid + 1;
      else
        r = mid - 1;
    }
    return 0;
  }
};

int main() {
  vector<vector<int>> nums;
  int count = 0;
  vector<int>* tmp;
  for (int j = 0; j < 5; j++) {
    tmp = new vector<int>;
    for (int i = 0; i < 5; i++, count++) {
      tmp->push_back(count);
    }
    nums.push_back(*tmp);
  }
  Solution S;
  int h = nums.size();
  int w = nums[0].size();
  int ph, pw;
  int n = h * w;
  for (int i = 0; i < 25; i++) {
    int mid = i;
    ph = mid / h;
    pw = mid % w;
    cout << nums[ph][pw] << ' ';
  }
  cout << endl;
  bool res = S.searchMatrix(nums, 30);
  cout << res << endl;
}
