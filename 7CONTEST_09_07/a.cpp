#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n, a, b;
        cin >> n >> a >> b;
        long long price = min(b, 2 * a);
        long long total = (n / 2) * price + (n % 2) * a;

        cout << total << endl;
    }

    return 0;
}
