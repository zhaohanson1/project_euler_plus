#include <iostream>
#include <cstring>
using namespace std;
long long fib_cache[100];

void generate_even_fib_n() {
    fib_cache[0] = 0;
    fib_cache[1] = 2;
    for (int i=2; i <= 100; i++) {
        fib_cache[i] = fib_cache[i-1]*4 + fib_cache[i-2];
    }
}

int main(){

    memset(fib_cache, -1, sizeof(fib_cache));
    generate_even_fib_n();

    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        long n;
        cin >> n;
        long long f;
        long x = 1;
        long long sum = 0;
        while ((f = fib_cache[x]) <= n) {
            sum += f;
            x += 1;
        }

        cout << sum << endl;
    }
    return 0;
}
