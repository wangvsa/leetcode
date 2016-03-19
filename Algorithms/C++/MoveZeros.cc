class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // O(1)复杂度:将所有非0的数放到数组最前面
        int pos = 0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i]!=0)
                nums[pos++] = nums[i];
        }
        // 将后面补0
        for(;pos<nums.size();pos++) {
            nums[pos] = 0;
        }
    }
};