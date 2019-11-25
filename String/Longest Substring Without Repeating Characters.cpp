class Solution {
public:
    int lengthOfLongestSubstring(string s) {
            int t[256], len, start = 0, end = 0, maxLength = 0;
            memset(t, 0xff, 256*sizeof(int));
            len = s.length();

            while(end != len){
                if(t[s[end]] >= start){ 
                    if(maxLength < end - start){
                        maxLength = end - start;
                    }
                    start = t[s[end]] + 1;
                    //every new letter, start=0, so length keeps increasing
                    //if there's repeating letter, then count from the next one
                }
                t[s[end]] = end;
                ++end;
            }
            if(maxLength < end - start) maxLength = end - start;
            return maxLength;
    }
};
