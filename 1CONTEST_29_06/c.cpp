#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            int first = i + 1;
            int second = n + 1 + 2 * i;
            int third = n + 2 + 2 * i;

            cout << first << " " << second << " " << third;
                
            if (i == n - 1) {
                cout << "\n";
            } else {
                cout << " ";
            }
        }
    }
    return 0;
}