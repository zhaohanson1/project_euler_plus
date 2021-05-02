#include <string.h> // memset
#include <iostream>
#include <vector>
using namespace std;

#define MAX_BOUND 5000001
#define ll long long
int longest_collatz[MAX_BOUND];
int largest_chain_lt_N[MAX_BOUND];

void setup_collatz() {

    memset(longest_collatz, -1, sizeof(longest_collatz));
    memset(largest_chain_lt_N, -1, sizeof(largest_chain_lt_N));
    
    longest_collatz[1] = 0;
    largest_chain_lt_N[1] = 0;
    int maxChain = 0;
    int maxN = -1;
    
    for (int i = 2; i < MAX_BOUND; i++) {
        if (longest_collatz[i] == -1) {
            vector<ll> stack;    
            int count = 0;
            ll j = i;
            while (j != 1) {
                stack.push_back(j);
                if ((j & 1) == 0) {
                    j >>= 1;
                    if (j < MAX_BOUND && longest_collatz[j] != -1) {
                        count += longest_collatz[j] + 1;
                        break;
                    }
                } else {
                    j = 3*j + 1;
                }
                count++;
            }
            
            for (int k=0; k<stack.size(); k++) {
                ll curr = stack[k];
                if (curr < MAX_BOUND)
                    longest_collatz[curr] = count;
                count--;
            }
        }
        
        if (maxChain <= longest_collatz[i]) {
            maxChain = longest_collatz[i];
            maxN = i;
        }
        largest_chain_lt_N[i] = maxN;
    }
    return;
}


int main() {
    setup_collatz();    
    int T, N;
    cin >> T;    
    for (int a0=0; a0 < T; a0++) {
        cin >> N;
        cout << largest_chain_lt_N[N] << endl;
    }
    return 0;
}
