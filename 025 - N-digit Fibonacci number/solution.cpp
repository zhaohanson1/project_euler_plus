#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

#define MAXN 5000

class CustomInt {  
    public:
        deque<int> digits;
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
        int size() {return digits.size();}
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


vector<int> fib;

void generate_fib_bound() {
    CustomInt a = CustomInt("1");
    CustomInt b = CustomInt("1");
    int idx = 1;
    fib.push_back(idx);
    while (fib.size() <= MAXN) {
        CustomInt temp = a.add(&b);
        a = b;
        b = temp;
        idx++;
        if (b.size() > fib.size()) {
            fib.push_back(idx+1);
        }
    }
}

int main() {
    
    generate_fib_bound();
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;
        cout << fib[N-1] << endl;
    }
    
    return 0;
}
