#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

int fibonacci_small_mod(int n, int m){
    int fib[n+1];
    fib[0] = 0;
    fib[1] = 1;

   for(int i =2 ;i <= n ;i++ ){
      fib[i] = (fib[i-1] + fib[i-2])%m;
   }

    return fib[n];
}

int pisano_period_length(int m){
    if( m==1 ){
        return 0;
    }

    int first = -1;
    int second = -1;
    int i = 2;

    while(1){
        second = fibonacci_small_mod(i,m);
        if (second == 1 && first == 0)
        {
            return i - 1;
        }
        first = second;
        i += 1;
    }
}

long long get_fibonacci_huge_fast(long long n, long long m)
{
    int pisano_length = pisano_period_length(m);
    int rem;
    do
    {
        rem = n % pisano_length;
        n = rem;
    } while (rem >= pisano_length);

    return fibonacci_small_mod(n, m);
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    //std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}
