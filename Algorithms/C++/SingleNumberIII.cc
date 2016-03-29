#include <bitset>
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int first = 0;
        for(int i=0;i<nums.size();i++) {
            first ^= nums[i];
        }
        
        // 设只出现一次的两个数是m，n，则fisrt即为m和n的异或值
        // 如果first的第i为是1，就说明这两个数第i位不同，
        // 假设m第i位是1，n第i位是0，
        // 再遍历一次数组，将所有第i位为1的数异或一次，就可以得到m
        // 用m与first异或可得到n
        bitset<32> bits(first);
        int i = 0;
        while(bits[i]==0)
            i++;
        
        int m = 0;
        for(int j=0;j<nums.size();j++) {
            bitset<32> tmp(nums[j]);
            if(tmp[i]==1)
                m ^= nums[j];
        }
        int n = first ^ m;
        
        vector<int> res;
        res.push_back(m);
        res.push_back(n);
        return res;
    }
};