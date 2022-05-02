#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> a;//提供一对一的hash
        vector<int> b(2,-1);//用来承载结果，初始化一个大小为2，值为-1的容器b
        for(int i=0;i<nums.size();i++)
        {
            if(a.count(target-nums[i])>0)
            {
                b[0]=a[target-nums[i]];
                b[1]=i;
                break;
            }
            a[nums[i]]=i;//反过来放入map中，用来获取结果下标
        }
        return b;
    };
};



int main() {

  vector<int> numslist;
  numslist.push_back(1);
  numslist.push_back(2);
  numslist.push_back(3);
  numslist.push_back(4);
  Solution tmp;
  vector<int> res;
  res = tmp.twoSum(numslist, 6);
  for (int i = 0; i < res.size();++i){
    cout << res[i];
  }
  return 0;
}