#include <iostream>

long long int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

   long long int fib[n+1];
   fib[0] = 0; 
   fib[1] = 1;
    for (int i = 2; i < n + 1; ++i) {
        fib[i] = (fib[i-1] + fib[i-2])%10 ;
    }
    
    return fib[n] ;
}

int main() {
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_naive(n);
    std::cout << c << '\n';
    }
