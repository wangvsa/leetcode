class Solution {
public:
    int binSearch(vector<int>& nums, int target, int low, int high) {
        if(low > high)
            return -1;
        if(low == high) {
            if(nums[low]==target)
                return low;
            else
                return -1;
        }
        
        int mid = (low+high) / 2;
        if(nums[mid] == target) {
            int i=mid;
            while(i>=0 && nums[i]==target)
                i--;
            return i+1;
        } else if(nums[mid] > target) {
            return binSearch(nums, target, low, mid-1);
        } else {
            return binSearch(nums, target, mid+1, high);
        }
    }
    vector<int> notFound() {
        vector<int> res;
        res.push_back(-1);
        res.push_back(-1);
        return res;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() < 1)
            return notFound();
        int start = binSearch(nums, target, 0, nums.size()-1);
        if(start == -1)
            return notFound();
            
        int end = start + 1;
        while(end < nums.size() && nums[end] == target)
            end++;
        
        vector<int> res;
        res.push_back(start);
        res.push_back(end-1);
        return res;
    }
};