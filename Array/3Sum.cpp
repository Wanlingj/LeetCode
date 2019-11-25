class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        for(int i=0;i<n-1;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int l=i+1;
            int r=n-1;
            while(l<r){
             int s=nums[i]+nums[l]+nums[r];
             
             if(s==0) {
              
              res.push_back({nums[i],nums[l],nums[r]});
              int dup_l=nums[l],dup_r=nums[r];
              while(l<r && dup_l==nums[l]) l+=1;
              while(l<r && dup_r==nums[r]) r-=1;
             
             }
             else if (s<0)  l+=1;
             else r-=1;
              
            }
            
        }
     return res;
        
       
    }
};
