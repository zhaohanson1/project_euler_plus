#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int getNameScore(string name) {
    int s = 0;
    for (int i=1; i<name.length()-1; i++) {
        s += name[i]-'A'+1;
    }
    return s;
}

int main() {

    ifstream name_file;
    name_file.open("p022_names.txt");
    vector<string> names;
    string s;
    string delimiter=",";
    getline(name_file, s);
    size_t last = 0; 
    size_t next = 0; 

    // https://stackoverflow.com/a/14266139
    // in reply
    while ((next = s.find(delimiter, last)) != string::npos) {   
        names.push_back(s.substr(last, next-last));
        last = next + 1; 
    } 
    names.push_back(s.substr(last));;
    
    sort(names.begin(), names.end());
    long long score = 0;
    for (int i = 0; i < names.size(); i++) {
        score += (i+1) * getNameScore(names[i]);
    }
    cout << score;
    
    return 0;
}
