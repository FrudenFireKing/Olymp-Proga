/* УСЛОВИЕ:

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

struct trie {
    struct Node {
        int dp = 0;
        int cnt = 0;
        map <char, int> go;
    };

    vector <Node> data;

    int add() {
        data.push_back(Node());
        return data.size() - 1;
    }

    bool is_go(int u, char c) {
        return data[u].go.count(c);
    }

    int go(int u, char c) {
        return data[u].go[c];
    }

    void insert(const string &s) {
        int u = 0;
        data[u].dp++;
        for (char c : s) {
            if (!is_go(u, c)) {
                int v = add();
                data[u].go[c] = v;
            }
            u = go(u, c);
            data[u].dp++;
        }
        data[u].cnt++;
    }

    void erase(const string &s) {
        int u = 0;
        for (char c : s) {
            --data[u].dp;
            u = go(u, c);
        }
        --data[u].cnt;
        --data[u].dp;
    }

    string find_k_min(int k) {
        int u = 0;
        string ans;
        while (true) {
            if (data[u].cnt >= k) {
                return ans;
            } else {
                k -= data[u].cnt;
            }
            for (auto item: data[u].go) { // item = pair <char, int>
                char c = item.first;
                int nxt = item.second;
                if (data[nxt].dp >= k) {
                    ans += c;
                    u = nxt;
                    break;
                } else {
                    k -= data[nxt].dp;
                }
            }
        }
    }
};

int main() {
    int n; 
    cin >> n;
    trie t;
    t.add(); // Инициализация корня
    
    for (int i = 0; i < n; i++) {
        string s; 
        cin >> s;
        
        // Если первый символ - буква, значит это вставка
        if (s[0] >= 'a' && s[0] <= 'z') {
            t.insert(s);
        } 
        // Если первый символ - цифра, это запрос k-го элемента
        else {
            int k = stoi(s);
            string ans = t.find_k_min(k);
            cout << ans << "\n";
            t.erase(ans); // Удаляем строку из словаря после вывода
        }
    }
}

/*
|Входные данные:|
12
abacaba
abacad
ab
bazzz
bazzz
5
4
bazyz
3
2
2
1
-----------------------
|Выходные данные:|
bazzz
bazzz
abacad
abacaba
bazyz
ab
*/
