class Solution {
public:
    unordered_map<char, string> m1;
    unordered_map<string, char> m2;
    bool wordPatternMatch(string pattern, string str) {
        return dfs(pattern, str, 0, 0);
    }
    // i is pos in pattern
    // h is pos in str
    bool dfs(string& pattern, string& str, int i, int j){
        if (i == pattern.size() && j == str.size()){
            return true;
        }
        else if (j == str.size()){
            return false;
        }
        char c = pattern[i];
        if (m1.count(c)){
            string match = m1[c];
            int n = match.size();
            if (str.substr(j, n) == match){
                return dfs(pattern, str, i + 1, j + n);
            }
            else{
                return false;
            }
        }
        else{
            for (int r = j; r < str.size(); r ++){
                string match = str.substr(j, r - j + 1);
                // match already exists in a previous bijection
                if (!m2.count(match)){
                    m1[c] = match;
                    m2[match] = c;
                    if (dfs(pattern, str, i + 1, r + 1)){
                        return true;
                    }
                    m1.erase(c);
                    m2.erase(match);
                }
            }
        }
        return false;
    }
};
