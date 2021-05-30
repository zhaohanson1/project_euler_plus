#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int getNameScore(string name) {
    int s = 0;
    for (int i=0; i<name.length(); i++) {
        s += name[i]-'A'+1;
    }
    return s;
}
int main() {   
    int N; 
    cin >> N;
    string names[N];
    for (int i = 0; i < N; i++) {
        cin >> names[i];
    }
    sort(names, names+N);
    int Q;
    cin >> Q;
    string Qi;
    for (int j = 0; j < Q; j++) {
        cin >> Qi;
        int lo=0, hi=N, mid, cmp;
        while (lo <= hi) {
            mid = (hi-lo)/2 + lo;
            cmp = Qi.compare(names[mid]);
            if (cmp == 0) {
                break;
            } else if (cmp > 0) {
                lo = mid+1;
            } else {
                hi = mid-1;
            }
        }
        int rank = mid+1;
        int score = getNameScore(Qi);
        cout << rank*score << endl;
    }
    
    return 0;
}
