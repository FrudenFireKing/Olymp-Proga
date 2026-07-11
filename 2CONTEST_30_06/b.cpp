#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
 
vector<int> z_function(const string& s) {
    int n = s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    string s;
    if (!(cin >> s)) return 0;
    int n = s.length();
 
    vector<int> pi = z_function(s);
    
    int k = n - pi[n - 1];
    
    if (n % k == 0) {
        cout << k << endl;
    } else {
        cout << n << endl;
    }
 
    return 0;
}
