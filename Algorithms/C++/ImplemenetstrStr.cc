class Solution {
public:
    // 直接使用string类的find函数
    int find(string haystack, string needle) {
        int pos = haystack.find(needle);
        if(pos==string::npos)
            return -1;
        return pos;
    }
    
    bool equal(string str1, string str2, int start) {
        for(int i=0;i<str2.size();i++) {
            if(str1[i+start] != str2[i])
                return false;
        }
        return true;
    }

    int strStr(string haystack, string needle) {
        //return find(haystack, needle);
        if(needle.size() > haystack.size())
            return -1;
        int pos = -1;
        
        for(int i=0;i<=haystack.size()-needle.size();i++) {
            if(equal(haystack, needle, i))
                return i;
        }
        
        return pos;
    }
    
    
};