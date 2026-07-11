#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {  
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        long long max_xor = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long long current_xor = a[i] ^ a[j];
                if (current_xor > max_xor) {
                    max_xor = current_xor;
                }
            }
        }
        cout << max_xor << "\n";
    }
    
    return 0;
}