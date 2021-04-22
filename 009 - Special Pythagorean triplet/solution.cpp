#include <iostream>

using namespace std;

int f(int Z) {
    int maxProd = -1;
    for (int n = 1; n <= Z; n++) {
        for (int m = n+1; m <= Z - (n*n); m++) {
            int a = m*m - n*n;
            int b = 2*m*n;
            int c = m*m + n*n;
            int sum = a+b+c;
            if (sum == Z) {
                maxProd = max(maxProd, a*b*c);
            } else if (Z % sum == 0) {
                int k = Z / sum;
                maxProd = max(maxProd, (k*k*k*a*b*c));
            }
            
        }
    }
    return maxProd;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        
        cout << f(n) << endl;
    }
    return 0;
}
