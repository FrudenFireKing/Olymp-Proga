#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        for (int i = n; i > m; --i) {
            cout << i << " ";
        }
        for (int j = 1; j <= m; ++j) {
            cout << j << " ";
        }

        cout << "\n";

    }

    return 0;
}
