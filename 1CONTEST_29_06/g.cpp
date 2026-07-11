#include <iostream>
using namespace std;
 
int main() {
    int T;
    cin >> T;
 
    while (T--) {
        int x, y;
        cin >> x >> y;
 
        int n = x + y;
        int d = y - x;
 
 
        if ((x == 0 && n % 2 == 0) || (2 * x > n)) {
            cout << "NO\n";
            continue;
        }
 
        cout << "YES\n";
 
        int mm = 2 * x + (d & 1);
 
        for (int i = 2; i <= mm; i++)
            cout << i - 1 << " " << i << "\n";
 
        for (int i = mm + 1; i <= n; i++)
            cout << mm << " " << i << "\n";
    }
 
    return 0;
}