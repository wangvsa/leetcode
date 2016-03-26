class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0;
        int i = 0;
        while(i<nums.size() && nums[i]!=val) {
            i++;
            count++;
        }
        if(i >= nums.size())
            return nums.size();
            
        for(int j=i+1;j<nums.size();) {
            if(nums[j] != val) {
                count++;
                nums[i++] = nums[j++];
            } else {
                j++;
            }
        }
        
        return count;
    }
};