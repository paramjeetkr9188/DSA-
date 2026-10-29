#include <stdio.h>

// Helper to count digits: no_of_digits(n)
int numDigits(long long n) {
    int count = 0;
    while (n > 0) {
        count++;
        n /= 10;
    }
    return (count == 0) ? 1 : count;
}

// Simple power of 10 (10^p)
long long power(int p) {
    long long res = 1;
    for (int i = 0; i < p; i++) {
        res *= 10;
    }
    return res;
}

// Karatsuba Multiplication (x, y from notes)
long long karatsuba(long long u, long long v) {
    // if (u < 10 || v < 10) return (u * v);
    if (u < 10 || v < 10) {
        return u * v;
    }

    // n = max(no_of_digits(u), no_of_digits(v))
    int d1 = numDigits(u);
    int d2 = numDigits(v);
    int n = (d1 > d2) ? d1 : d2;

    // m = n / 2
    int m = n / 2;

    long long ten_m = power(m);

    // Splitting exactly as in notebook:
    // w = u / 10^m
    // x = u % 10^m
    // y = v / 10^m
    // z = v % 10^m
    long long w = u / ten_m;
    long long x = u % ten_m;
    long long y = v / ten_m;
    long long z = v % ten_m;

    // Recursive calls:
    long long P1 = karatsuba(w, y);              // P1 = karatsuba(w, y)
    long long P2 = karatsuba(x, z);              // P2 = karatsuba(x, z)
    long long P3 = karatsuba(w + x, y + z);      // P3 = karatsuba(w + x, y + z)

    // return (P1 * 10^(2m) + (P3 - P1 - P2) * 10^m + P2)
    return (P1 * power(2 * m)) + ((P3 - P1 - P2) * ten_m) + P2;
}

int main() {
    long long u, v;

    printf("Enter two numbers: ");
    scanf("%lld %lld", &u, &v);

    printf("Product = %lld\n", karatsuba(u, v));

    return 0;
}
