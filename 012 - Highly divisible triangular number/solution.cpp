#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

#define ll long long
#define MAXP 1000000
#define MAXD 1000
using namespace std;

struct Pair {
    ll div;
    ll num;
    Pair(ll x, ll y) : div(x), num(y) {};
};

vector<ll> prime;
vector<Pair> triangular_over_N;
ll last_tri = 1;

void generate_primes() {
    ll limit = floor(sqrt(MAXP));
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


int count_divisors(int N) {
    if (N == 1)
        return 1;
    int count = 1;
    int i = 0;
    while (prime[i] <= N) {
        if (N % prime[i] == 0) {
            int pow = 0;
            while (N%prime[i] == 0) {
                N /= prime[i];
                pow++;
            }
            count *= (pow + 1);
        }
        i++;
    }
    return count;
}

void generate_triangles() {
    int idx = 1;
    triangular_over_N.push_back(Pair(1, 1));
    
    while (triangular_over_N.back().div <= MAXD) {
        idx++;
        int curr_tri = (idx * (idx+1)) / 2;
        int divs = count_divisors(curr_tri);
        if (divs >triangular_over_N.back().div) 
            triangular_over_N.push_back(Pair(divs, curr_tri));
    }
}

int get_first_T_with_N(int N) {
    int lo = 0, hi = triangular_over_N.size();
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
    
        if (triangular_over_N[mid].div == N)
            return triangular_over_N[mid].num;
        if (triangular_over_N[mid].div < N) 
            lo = mid + 1; 
        else
            hi = mid - 1;
    }
    
    return triangular_over_N[hi+1].num;
}
    
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin >> T;
    generate_primes();
    generate_triangles();
    for (int a0=0; a0 < T; a0++) {
        int N;
        cin >> N;
        cout << get_first_T_with_N(N+1) << endl;
    }
    return 0;
}