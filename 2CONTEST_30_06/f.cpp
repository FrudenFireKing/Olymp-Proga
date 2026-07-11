#include <bits/stdc++.h>
using namespace std;

const int LOG = 30;

struct Node {
    int nxt[2];
    int cnt;
    Node() {
        nxt[0] = nxt[1] = -1;
        cnt = 0;
    }
};

vector<Node> trie(1);

void add(int x, int delta) {
    int v = 0;
    trie[v].cnt += delta;
    for (int b = LOG; b >= 0; b--) {
        int bit = (x >> b) & 1;
        if (trie[v].nxt[bit] == -1) {
            trie[v].nxt[bit] = trie.size();
            trie.emplace_back();
        }
        v = trie[v].nxt[bit];
        trie[v].cnt += delta;
    }
}

int getMin(int x) {
    int v = 0;
    int ans = 0;
    for (int b = LOG; b >= 0; b--) {
        int bit = (x >> b) & 1;

        int to = trie[v].nxt[bit];
        if (to != -1 && trie[to].cnt > 0) {
            v = to;
        } else {
            ans |= (1 << b);
            v = trie[v].nxt[bit ^ 1];
        }
    }
    return ans;
}

int getMax(int x) {
    int v = 0;
    int ans = 0;
    for (int b = LOG; b >= 0; b--) {
        int bit = (x >> b) & 1;

        int to = trie[v].nxt[bit ^ 1];
        if (to != -1 && trie[to].cnt > 0) {
            ans |= (1 << b);
            v = to;
        } else {
            v = trie[v].nxt[bit];
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int &x : a) {
        cin >> x;
        add(x, 1);
    }

    for (int x : a) {
        add(x, -1);
        cout << getMin(x) << " " << getMax(x) << "\n";
        add(x, 1);
    }

    return 0;
}
