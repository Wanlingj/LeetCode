class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farest_index = 0;
        int n=nums.size();
        for (int i=0; i<=min(farest_index,n-1); i++){
            farest_index = max(farest_index, i+nums[i]);
            if (farest_index>=n-1) return true;
        }
        return false;
    }
};
