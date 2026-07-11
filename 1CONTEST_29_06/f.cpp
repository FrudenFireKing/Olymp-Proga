#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int count;
    cin >> count;

    while(count--) {
        int n;
        cin >> n;
        
        vector<int> parent(n + 1);
        for (int i = 2; i <= n; ++i) {
            cin >> parent[i];
        }
        
        string s;
        cin >> s;
        
        vector<int> balance(n + 1);
        for (int i = 1; i <= n; ++i) {
            balance[i] = (s[i - 1] == 'B') ? 1 : -1;
        }
        
        for (int i = n; i >= 2; --i) {
            balance[parent[i]] += balance[i];
        }
        
        int balanced_count = 0;
        for (int i = 1; i <= n; ++i) {
            if (balance[i] == 0) {
                balanced_count++;
            }
        }
        
        cout << balanced_count << "\n";
    }

    return 0;
}