#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

class CustomInt {
    deque<int> digits;
    
    public:
        CustomInt(deque<int> d) : digits(d) {};
        CustomInt(string n) {
            for (int i = 0; i < n.size(); i++) {
                digits.push_back(n[i] - '0');
            }
        }
        
        int length() {return digits.size();}
        int& operator[](int idx) {return digits[idx];}
        CustomInt add(CustomInt* other);
        void printInt();
        void printfirstN(int N);
};

CustomInt CustomInt::add(CustomInt* other) {
    deque<int> sum;
    CustomInt* top = this;
    CustomInt* bot = other;
    if (bot->length() > top->length()) {
        CustomInt* tmp = top;
        top = bot;
        bot = tmp;
    }
    
    
    int carry = 0;
    for (int i = bot->length()-1; i >= 0; i--) {
        int j = top->length()-1-(bot->length()-1-i);
        int topd = top->digits[j];
        int botd = bot->digits[i];
        
        int curr = (topd + botd + carry) % 10;
        carry = (topd + botd + carry) / 10;
        sum.push_front(curr);
    }    
    
    for (int i = top->length()-bot->length()-1; i >= 0; i--) {
        int topd = top->digits[i];
        int curr = (topd + carry) % 10;
        carry = (topd + carry) / 10;
        sum.push_front(curr);
    }
    if (carry == 1) {
        sum.push_front(carry);
    }
    
    return CustomInt(sum);
}

void CustomInt::printInt() {
    for (int x: digits) {
        printf("%d", x);
    }
    printf("\n");
}

void CustomInt::printfirstN(int N) {
    if (N > digits.size()) 
        N=digits.size();
    for (int i=0; i<N; i++) {
        printf("%d", digits[i]);
    }
    printf("\n");
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int T;
    cin >> T;
    CustomInt currSum("0");
    for (int a0 = 0; a0 < T; a0++) {
        string N;
        cin >> N;
        CustomInt x(N);
        currSum = currSum.add(&x);
    }
    currSum.printfirstN(10);
    return 0;
}

