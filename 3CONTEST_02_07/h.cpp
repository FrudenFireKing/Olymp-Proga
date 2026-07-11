#include <bits/stdc++.h>
using namespace std;

inline double d(int x1, int y1, int x2, int y2) {
    double dx = x1 - x2;
    double dy = y1 - y2;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int ax0, ay0, bx0, by0;
    cin >> ax0 >> ay0 >> bx0 >> by0;

    double dpA = d(ax0, ay0, bx0, by0);
    double dpB = dpA;

    for (int i = 1; i < n; i++) {
        int ax, ay, bx, by;
        cin >> ax >> ay >> bx >> by;

        double len = d(ax, ay, bx, by);

        double AA = d(ax0, ay0, ax, ay);
        double AB = d(ax0, ay0, bx, by);
        double BA = d(bx0, by0, ax, ay);
        double BB = d(bx0, by0, bx, by);

        double ndpA = len + min(dpA + AB, dpB + BB);
        double ndpB = len + min(dpA + AA, dpB + BA);

        dpA = ndpA;
        dpB = ndpB;

        ax0 = ax;
        ay0 = ay;
        bx0 = bx;
        by0 = by;
    }

    cout.setf(ios::fixed);
    cout << setprecision(10) << min(dpA, dpB) << '\n';
}
