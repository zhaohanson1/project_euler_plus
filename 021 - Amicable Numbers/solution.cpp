#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <set>
#include <unordered_set>

#define ll long long
#define MAXP 100000
using namespace std;

struct Pair {
    ll div;
    ll num;
    Pair(ll x, ll y) : div(x), num(y) {};
};

vector<ll> prime;
vector<Pair> ami;

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

void generate_amicable() {
    unordered_set<int> seen_amicable;
    set<int> ordered_amicable;
    int maxN = 0;
    for (int i = 1; i <= MAXP; i++) {
        if (seen_amicable.find(i) != seen_amicable.end()) {
            continue;
        }
        int A = sum_proper_divisors(i);    
        int B = sum_proper_divisors(A);
        if (B == i && A != B) {
            seen_amicable.insert(A);
            seen_amicable.insert(B);
            ordered_amicable.insert(B);
            ordered_amicable.insert(A);    
        }
    }

    int sum = 0;
    ami.push_back(Pair(1, 0));
    for (int x: ordered_amicable) {
        sum += x;
        ami.push_back(Pair(x, sum));
    }
}

int get_first_T_with_N(int N) {
    int lo = 0, hi = ami.size()-1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
    
        if (ami[mid].div == N)
            return ami[mid].num;
        if (ami[mid].div < N) 
            lo = mid + 1; 
        else
            hi = mid - 1;
    }
    return ami[hi].num;
}
    
int main() {
    int T;
    cin >> T;
    generate_primes();
    generate_amicable();
    for (int a0=0; a0 < T; a0++) {
        int N;
        cin >> N;
        cout << get_first_T_with_N(N-1) << endl;
    }
    return 0;
}