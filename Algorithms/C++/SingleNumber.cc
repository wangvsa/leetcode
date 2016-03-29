class Solution {
public:
	// 出现两次的数异或后为0
    int singleNumber(vector<int>& nums) {
        int res = nums[0];
        for(int i=1;i<nums.size();i++) {
            res ^= nums[i];
        }
        return res;
    }
};