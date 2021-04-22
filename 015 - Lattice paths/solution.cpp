#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll unsigned long long
const int MAXN = 1001;
const int m = (int) (1e9 + 7);
ll factorial[MAXN];

// Returns (a * b) % mod
ll modMult(ll a, ll b, int mod)
{
    ll res = 0;
    a %= mod;

    while (b)
    {
        if (b & 1)
            res = (res + a) % mod;
        a = (a << 1) % mod;
        b >>= 1;
    }
    return res;
}

ll power(ll x, int y, int p)
{
    ll res = 1;
    x = x % p; 
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

ll modInverse(ll n, int p)
{
    return power(n, p - 2, p);
}

void precompute_factorial() {
    factorial[0] = 1;
    for (int i = 1; i <= MAXN; i++) {
        factorial[i] = modMult(factorial[i - 1], i, m);
    }
}

ll binomial_coefficient(int n, int k) {
    ll denom = (modInverse(factorial[k], m) * modInverse(factorial[n-k], m)) % m;
    return (factorial[n] * denom) % m;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    cin >> T;
    
    precompute_factorial();
    
    for (int a0=0; a0<T; a0++) {
        int N, M;
        cin >> N >> M;
        cout << binomial_coefficient(N+M, N) << endl;
    }
    return 0;
}
