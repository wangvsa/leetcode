class Solution {
    public:
        bool canWinNim(int n) {
            // 赢:1,2,3 输:4
            // 5,6,7 -> 使对手4 因此可赢
            // 8 -> 使对手5,6,7 因此输
            // 9,10,11 -> 使对手8 因此可赢
            // ...
            // 综上:1,2,3,5,6,7,9,10,11...可赢
            // 4,8,12...输
            if(n % 4 == 0)
                return false;
            return true;
        }
};
