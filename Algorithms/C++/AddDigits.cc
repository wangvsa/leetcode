class Solution {
public:
    int addDigits(int num) {
        /**
         * 10:1
         * 11:2
         * 12:3
         * 13:4
         * 14:5
         * 15:6
         * 17:8
         * 18:9
         *
         * 19:1
         * 20:2
         * 21:3
         */
        if(num < 10)
            return num;
        return (num % 9)==0 ? 9 : (num%9);
    }
};
