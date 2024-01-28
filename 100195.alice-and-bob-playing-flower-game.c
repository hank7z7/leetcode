#include <stdio.h>

long long flowerGame(int n, int m)
{
    long long n_even = (long long) n / 2;
    long long n_odd  = (long long) n / 2 + ((long long) n & 1);
    long long m_even = (long long) m / 2;
    long long m_odd  = (long long) m / 2 + ((long long) m & 1);
    return n_even * m_odd + n_odd * m_even;
}

int main(int argc, char** argv)
{
    int n, m;
    // Test 1
    n = 3;
    m = 2;
    printf("%lld\n", flowerGame(n, m));

    // Test 2
    n = 1;
    m = 1;
    printf("%lld\n", flowerGame(n, m));
    return 0;
}