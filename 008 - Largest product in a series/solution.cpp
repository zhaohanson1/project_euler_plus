#include <iostream>
#include <string>

using namespace std;


int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int k;
        cin >> n >> k;
        string num;
        cin >> num;
        int zeros = 0;
        long long currProd = 1;

        for (int i = 0; i < k; i++) {
            if (num[i]-'0' == 0) {
                zeros++;
            } else {
                currProd *= num[i]-'0';
            }
        }

        long long maxProd = zeros > 0 ? 0 : currProd;

        for (int i = k; i < n; i++) {

            if (num[i-k]-'0' == 0) {
                zeros--;
            } else {
                currProd /= num[i-k] - '0';
            }
            
            if (num[i]-'0' == 0) {
                zeros++;
            } else {
                currProd *= num[i]-'0';
                if (zeros == 0)
                    maxProd = max(maxProd, currProd);
            }
            
        }
        cout << maxProd << '\n';
    }
    return 0;
}
