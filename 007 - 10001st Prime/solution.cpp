#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;
#define ll long long
 
int main(){
    
    int t;
    cin >> t;   
    
    int n = (1e6)+1;
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

    for(int a0 = 0; a0 < t; a0++){
        long n;
        cin >> n;
        cout << prime[n-1] << "\n";
    
    }
    return 0;
}
