#include <unordered_map>
class Solution {
    public:
        int lengthOfLongestSubstring(string s) {

            unordered_map<char, int> map;
            int max = 0, length = 0;
            char ch;
            int start = 0;  // 子串的开始计数位置
            for(int i=0;i<s.length();i++) {
                ch = s.at(i);

                if(map.count(ch) > 0) {          // 出现重复，重新计数
                    start = start > map[ch] ? start : map[ch];
                    length = i - start;
                } else
                    length++;

                map[ch] = i;
                max = length > max ? length : max;
            }

            return max;
        }
};
