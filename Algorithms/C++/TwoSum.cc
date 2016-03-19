#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

/**
 * 注意：[0,4,3,0], 0的结果是[0, 3]
 * 题目说每组输入只有一个正确答案
 * 因此如果遇到重复出现的数（向上面的两个0）的话，
 * 1. 重复的数不可能和其他数组成答案
 * 2. 这两个重复的数相加就是答案
 */

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            vector<int> result;
            int index1, index2;

            unordered_map<int, int> map;
            for(int i=0;i<nums.size();i++) {
                // 出现一个重复的数，判断其是不是自己相加为答案
                if(map.count(target-nums[i])>0 && nums[i]+nums[i]==target ) {
                    index1 = map[nums[i]];
                    index2 = i;
                    break;
                }

                map[nums[i]] = i;
                if( map.count(target-nums[i]) > 0 && i != map[target-nums[i]]) {
                    index1 = i < map[target-nums[i]] ? i : map[target-nums[i]];
                    index2 = i > map[target-nums[i]] ? i : map[target-nums[i]];
                    break;
                }
            }

            result.push_back(index1);
            result.push_back(index2);
            return result;
        }

};

int main() {
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(4);
    nums.push_back(4);
    nums.push_back(0);
    Solution s;
    vector<int> result = s.twoSum(nums, 0);
    cout<<result[0]<<","<<result[1]<<endl;
}
