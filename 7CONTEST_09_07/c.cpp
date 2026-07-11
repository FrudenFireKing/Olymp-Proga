#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        long long first = (k + 1) / 2;
        long long last = k / 2;
        int counter = 0;

        for (int i = 0; i < n; ++i) {
            if (a[i] <= first) {
                first -= a[i];
                a[i] = 0;
                counter++;
            } else {
                a[i] -= first;
                first = 0;
                break;
            }
        }

        for (int i = n - 1; i >= 0; --i) {
            if (a[i] == 0) continue;

            if (a[i] <= last) {
                last -= a[i];
                a[i] = 0;
                counter++;
            } else {
                a[i] -= last;
                last = 0;
                break;
            }
        }

        cout << counter << "\n";
    }

    return 0;
}