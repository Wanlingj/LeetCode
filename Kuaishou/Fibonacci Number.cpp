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

//Another question: Index of two largest numbers in an array
//You can scan each element in the array and keep track of the largest and the second largest numbers and their index.
//After all elements are scanned, you will be able to find the largest and the second largest numbers and their index.
