class Solution {
public:
    int singleCount(int num) {
        int count = 0;
        while(num != 0) {
            num = num & (num - 1);
            count++;
        }
        return count;
    }
    vector<int> countBits(int num) {
        vector<int> res;
        for(int i=0;i<=num;i++) {
            res.push_back(singleCount(i));
        }
        return res;
    }
};