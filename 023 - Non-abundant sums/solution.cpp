#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <unordered_set>

#define ll long long
#define MAXP 100000
using namespace std;

vector<ll> prime;
unordered_set<int> abundants;

void generate_primes() {
    ll limit = ceil(sqrt(MAXP));
    bool mark[limit];
    
    memset(mark, true, sizeof(mark)); 
    for (ll p=2; p*p<limit; p++)
    {
        if (mark[p] == true)
        {
            for (ll i=p*p; i<limit; i+=p)
                mark[i] = false;
        }
    }
 
    for (ll p=2; p<limit; p++)
    {
        if (mark[p] == true)
        {
            prime.push_back(p);
        }
    }
    int size = prime.size();
    ll low = limit;
    ll high = 2*limit;
    while (low < MAXP)
    {
        if (high >= MAXP)  high = MAXP;
        bool mark[limit+1];
        memset(mark, true, sizeof(mark));
        for (ll i = 0; i < size; i++)
        {
            ll loLim = floor(low/prime[i]) * prime[i];
            if (loLim < low)
                loLim += prime[i];
 
            for (ll j=loLim; j<high; j+=prime[i])
                mark[j-low] = false;
        }

        for (ll i = low; i<high; i++) {
            if (mark[i - low] == true)
            {
                prime.push_back(i);
            }
        }
        low = low + limit;
        high = high + limit;
    }
}

int sum_proper_divisors(int N) {
    int orig = N;
    if (N == 1)
        return 1;
    int count = 1;
    int i = 0;
    while (i < prime.size() && prime[i] <= N) {
        if ((N % prime[i]) == 0) {
            int e = 0;
            while (N%prime[i] == 0) {
                N /= prime[i];
                e++;
            }
            count *= (pow(prime[i], e+1) - 1) / (prime[i] - 1);
        }
        i++;
    }
    return count - orig;
}

void generate_abundant() {
    int maxN = 0;
    for (int i = 1; i <= MAXP; i++) {
        int A = sum_proper_divisors(i);
        if (A > i) {
            abundants.insert(i);
        }
    }
}

string sum_of_two_abundant(int x) {
    if (x > 28123) return "YES";
    for (int a: abundants) {
        if (abundants.find(x - a) != abundants.end()) {
            return "YES";
        }
    }
    return "NO";
}


int main() {
    int T;
    cin >> T;
    generate_primes();
    generate_abundant();
    for (int a0=0; a0 < T; a0++) {
        int N;
        cin >> N;
        cout << sum_of_two_abundant(N) << endl;
    }
    return 0;
}
