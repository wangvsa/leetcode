class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        int area = 0;
        // 令底最长,然后从两边将短板向另一侧移动
        for(int i=0,j=height.size()-1;i<j;) {
            area = min(height[i], height[j]) * (j-i);
            if(area > max)
                max = area;
            if(height[i] < height[j])
                i++;
            else if(height[i] > height[j])
                j--;
            else {  // 处理两端相等的情况
                int tmpi = i, tmpj = j;
                while(height[tmpi]==height[tmpj])   // 优先移动能得到更高的值的一侧
                    tmpi++;
                    tmpj--;
                if(height[tmpi] > height[tmpj])
                    i++;
                else
                    j--;
                
            }
        }
        return max;
    }
};