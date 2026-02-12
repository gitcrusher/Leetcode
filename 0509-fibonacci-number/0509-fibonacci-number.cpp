class Solution {
public:
    int fib(int n) {
        // base case
        if(n ==0 || n==1){
            return n ; // kyunki fibonacii 0 = 0 , fibonacii 1= 1;
        }
            return fib(n-1)+fib(n-2);
    }
};