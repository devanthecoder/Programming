#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int64 pow10i(int k){ int64 p=1; while(k--) p*=10; return p; }

// S(N): sum of digits of 1..N
int64 S(int64 N){
    if(N<=0) return 0;
    if(N<10) return N*(N+1)/2;
    int d = (int)floor(log10((long double)N))+1;
    int64 p = pow10i(d-1);
    int64 a = N / p;       // most significant digit
    int64 r = N % p;
    int64 Sm1 = (d-1==0) ? 0 : 45LL*(d-1)*pow10i(d-2); // S(10^{d-1}-1)
    return a*Sm1 + (a*(a-1)/2)*p + a*(r+1) + S(r);
}

// sum of first 'k' digits of x (x in base-10)
int64 prefix_digit_sum(int64 x, int k){
    string s = to_string(x);
    int64 sum = 0;
    for(int i=0;i<k && i<(int)s.size();++i) sum += s[i]-'0';
    return sum;
}

// sum of digits in the first n characters of "123456789101112..."
int64 sum_first_n_digits(int64 n){
    if(n<=0) return 0;
    auto D = [](int d)->int64{
        // total digits up to d-digit numbers
        int64 tot = 0;
        for(int i=1;i<=d;i++) tot += 9LL*pow10i(i-1)*i;
        return tot;
    };

    // find d
    int d = 1;
    while(D(d) < n) ++d;
    int64 before = D(d-1);
    int64 R = n - before;           // digits inside d-digit block
    int64 q = (R-1) / d;            // full d-digit numbers consumed
    int rem = (int)(R - q*d);       // digits from next number
    int64 Nfull = pow10i(d-1) - 1 + q;

    int64 ans = S(Nfull);
    if(rem){
        int64 x = pow10i(d-1) + q;
        ans += prefix_digit_sum(x, rem);
    }
    return ans;
}
