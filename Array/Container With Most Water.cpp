class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size()-1;
        int max_water=0;
    
        while(i<j){
            max_water=max(max_water,min(height[i],height[j])*(j-i));
            if(height[i]>height[j])
                --j;
            else
                ++i;
        }
        return max_water;   
    }
};
