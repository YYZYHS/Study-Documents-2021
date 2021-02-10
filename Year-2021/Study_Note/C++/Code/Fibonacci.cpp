class Solution {
public:
    int Fibonacci(int n) {
        //F(0)=0，F(1)=1, F(n)=F(n - 1)+F(n - 2)（n ≥ 2，n ∈ N*）
        int Fib[39] = {};
        Fib[0] = 0;
        Fib[1] = 1;
        for(int i = 2;i <= n;i++)
            Fib[i] = Fib[i - 1] + Fib[i - 2];
        return Fib[n];
    }
};

//3ms  448k