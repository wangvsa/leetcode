class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        if(nums.size()<3)
            return result;

        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size()-2;i++) {
            if(i>0 && nums[i]==nums[i-1])
                continue;
            findTwoSum(nums, i+1, -nums[i]);
        }
        
        return result;
    }
    
    void findTwoSum(vector<int>& nums, int start, int target) {
        for(int i=start, j=nums.size()-1;i<j;) {
            if(nums[i]+nums[j] == target) {
                vector<int> vec;
                vec.push_back(-target);
                vec.push_back(nums[i]);
                vec.push_back(nums[j]);
                sort(vec.begin(), vec.end());
                result.push_back(vec);
            
                while(i<j && nums[i]==nums[i+1])
                    i++;
                while(i<j && nums[j]==nums[j-1])
                    j--;
                i++;
                j--;
            } else if(nums[i]+nums[j] < target) {
                i++;
            } else {
                j--;
            }
        }
    }
    
};