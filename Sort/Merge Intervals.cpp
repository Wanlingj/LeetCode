class Solution {
public:    
   vector<vector<int>> merge(vector<vector<int>>& a) {
        sort(a.begin(), a.end(), [](vector<int>& l, vector<int>& r){return l[0] < r[0]; });
        if(a.empty()) return {};
        vector<vector<int> > res{a[0]};
        for(int i = 1; i < (int) a.size(); ++i){
            if(res.back()[1] >= a[i][0]) res.back()[1] = max(res.back()[1], a[i][1]);
            else res.push_back(a[i]);
        }
        return res;
    }
   
};
