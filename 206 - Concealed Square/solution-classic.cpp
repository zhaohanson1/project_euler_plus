#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long


void iter_up(vector<int>& digits, ll* val) {
    int last = digits.back();
    int val_last = *val % 10;
    int inner, outer;
    if (last == 0 || last == 5) {
        if (*val % 10 != last) {
            while (*val % 10 != last)
                (*val)++;
        } else {
            *val += 10;
        }
        return;
    } else if (last == 1) {
        inner = 1;
        outer = 9;
    } else if (last == 4) {
        inner = 2;
        outer = 8;
    } else if (last == 6) {
        inner = 4;
        outer = 6;
    } else if (last == 9) {
        inner = 3;
        outer = 7;
    }
    
    if (inner <= val_last && val_last < outer) {
        *val += outer - val_last;
    } else {
        while (*val % 10 != inner) {
            (*val)++;
        }
    }
}

bool verify(ll val, vector<int> digits) {
    for (int i = digits.size()-1; i >= 0; i--) {
        if (val % 10 != digits[i])
            return false;
        val /= 100;
    }
    return true;
}

ll search(ll lo, ll hi, vector<int> digits) {
    while (lo <= hi) {
        //cout << lo << ' ' << lo*lo << endl;
        if (verify(lo*lo, digits)) {
            return lo;
        }
        iter_up(digits, &lo);
        
    }
    
    return -1;
}

void peturb(ll *i, ll D, ll p) {
    *i += D;
    *i *= 10;
    *i += p;
    *i *= 10;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    vector<int> digits;
    ll lo=0, hi=0;
    ll D;
    for (int i = 0; i < n-1; i++) {
        cin >> D;
        digits.push_back(D);
        peturb(&lo, D, 0);
        peturb(&hi, D, 9);
    }
    
    cin >> D;
    digits.push_back(D);
    lo += D;
    hi += D;
    
    
    
    ll lo_sq = floor(sqrtl(lo));
    ll hi_sq = ceil(sqrtl(hi));
    //cout << lo << ' ' << lo_sq << endl;
    //cout << hi << ' ' << hi_sq << endl;
    
    cout << search(lo_sq, hi_sq, digits) << endl;    
    return 0;
}
