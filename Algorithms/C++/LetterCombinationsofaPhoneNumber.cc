class Solution {
public:
    vector<string> letterCombinations(string digits) {
       
        string charmap[] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        vector<string> res;
        if(digits.size()==0)
            return res;
            
        res.push_back("");
        for(int i=0;i<digits.size();i++) {
            int idx = digits[i] - '0';
            string chars = charmap[idx];
            
            // 将每一个新字符增加在已有的所有字符串的后面
            vector<string> tmpres;
            for(int j=0;j<chars.size();j++) {
                for(int k=0;k<res.size();k++) {
                    tmpres.push_back(res[k] + chars[j]);    // vector不能直接修改
                }
            }
            res = tmpres;
        }
        
        return res;
    }
};