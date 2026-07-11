#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long c, d;
        cin >> n >> c >> d;

        vector<long long> b(n * n);
        for (int i = 0; i < n * n; ++i) {
            cin >> b[i];
        }
        sort(b.begin(), b.end());

        long long first = b[0];

        vector<long long> expected;
        expected.reserve(n * n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                expected.push_back(first + (long long)i * c + (long long)j * d);
            }
        }

        sort(expected.begin(), expected.end());
        
        if (b == expected) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}