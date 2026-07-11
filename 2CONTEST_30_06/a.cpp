#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    if (s1.length() != s2.length()) {
        cout << "-1" << "\n";
        return 0;
    }
    string comb = s2 + s2;
    size_t found = comb.find(s1);

    if (found != string::npos) {
        cout << found << "\n";
    }
    else {
        cout << "-1" << "\n";
    }

    return 0;
}