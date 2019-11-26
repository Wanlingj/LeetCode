class Solution {
public:
    bool isMatch(string s, string p) {
         vector<vector<bool>> dp(s.size()+1, vector<bool>(p.size()+1, false));
        dp[0][0]=true;
        dp[0][1]=p[0]=='*';//If p is all *, then it matches with empty string
		//When i=0, we need to find the boundary cases
        for (int j=1; j<=p.size(); j++)
        {
            dp[0][j]=(j>1&&p[j-1]=='*'&&dp[0][j-2]);
        }
        for (int i=1; i<=s.size(); i++)
        {
                for (int j=1; j<=p.size(); j++)
                {   
                    // if last elements matches
                     if (s[i-1]==p[j-1] || p[j-1]=='.') dp[i][j]=dp[i-1][j-1];
                     else if (p[j-1]=='*') 
                     {          
                             // Since * has zero matching ability
                             // if second to last elements matches
                             if (s[i-1]==p[j-2] || p[j-2]=='.') dp[i][j]= (dp[i][j-1]||dp[i][j-2]||dp[i-1][j]);
                             //Different cases for "*"
                             //Tthree cases: zero matching, one matching and multiple matching    
                             
                             //if second to last elements doesn't match
                             else dp[i][j]=dp[i][j-2];
                     };
                }
        }
        return dp[s.size()][p.size()];
    }
};
