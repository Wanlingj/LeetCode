class Solution {
public:
    int fib(int N) {
        if (N == 0 || N == 1) return N;
        int pre = 1;
        int prepre = 0;
        for (int i = 2;i <= N; i++) {
            int newpre = pre + prepre;
            prepre = pre;
            pre = newpre;
        }
        return pre;
    }
};

//time complexity: O(N)
