#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        const int max_k = 100000;
        int a[max_k];
        long long max_val = 0;

        for (int i = 0; i < k; i++) {
            cin >> a[i];
            max_val = max(max_val, (long long)a[i]);
        }

        long long operations = 2 * (n - max_val) - (k - 1);

        cout << operations << endl;

    }

    return 0;
}
