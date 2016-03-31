class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)
            return "";
        string res;
        int minimumLength = INT_MAX;
        for(int i=0;i<strs.size();i++) {
            if(strs[i].size() < minimumLength) {
                minimumLength = strs[i].size();
                res = strs[i];
            }
        }
        
        for(int pos=0;pos<minimumLength;pos++) {
            char ch = strs[0][pos];
            for(int i=1;i<strs.size();i++) {
                if(ch != strs[i][pos])
                    return strs[0].substr(0, pos);
            }
        }
        
        return res;
    }
};