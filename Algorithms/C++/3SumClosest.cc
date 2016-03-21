class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size()-2;i++) {
            int sum = findTwoSum(nums, i+1, nums[i], target);
            if(abs(sum-target) < abs(closest-target))
                closest = sum;
        }
        return closest;
    }
    int findTwoSum(vector<int>& nums, int start, int num, int target) {
        int closest = num + nums[start] + nums[start+1];
        for(int i=start, j=nums.size()-1;i<j;) {
            int sum = nums[i]+nums[j]+num;
            int diff = sum - target;
            if(diff == 0)
                return sum;
            else if(diff < 0)
                i++;
            else
                j--;
            
            if(abs(diff) < abs(closest-target))
                closest = sum;
        }
        return closest;
    }
};