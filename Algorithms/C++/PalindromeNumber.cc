class Solution {
    public:
        bool isPalindrome(int x) {
            if( x < 0 )
                return false;

            int i = 1, j = 1;
            int num = x;
            // 除到10就够了,还能防止i的溢出
            while( num > 10 ) {
                num /= 10;
                i *= 10;
            }
            if( num >= 10 )
                i *= 10;


            int left, right;
            // i从高位到低位,j从低位到高位
            while(i > j) {
                left = x / i % 10;
                right = x / j %10;
                if(left!=right)
                    return false;
                i /= 10;
                j *= 10;
            }
            return true;
        }
};
