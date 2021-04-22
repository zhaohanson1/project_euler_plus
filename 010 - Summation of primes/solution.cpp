#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;
#define ll long long

vector<ll> generate_primes(int n) {
    vector<ll> prime;
    ll limit = floor(sqrt(n))+1;
    bool mark[limit+1];
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
    while (low < n)
    {
        if (high >= n)  high = n;
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
    return prime;
}

int bsearch(vector<ll> arr, int x) {
    int l = 0, r = arr.size();
    while (l <= r) { 
        int m = l + (r - l) / 2;  
        if (arr[m] == x) 
            return m; 

        if (arr[m] < x) 
            l = m + 1; 
        else
            r = m - 1; 
    } 
    return r; 
}

int main(){
    int t;
    cin >> t;
    vector<ll> primes = generate_primes(1e6);
    vector<ll> prefix_sum;
    prefix_sum.push_back(primes[0]);
    for (int i = 1; i < primes.size(); i++) {
        prefix_sum.push_back(primes[i]+prefix_sum[i-1]);
    }

    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        int idx = bsearch(primes, n);
        cout << prefix_sum[idx] << endl;
        
    }
    return 0;
}
