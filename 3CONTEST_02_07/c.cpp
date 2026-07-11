#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
 
int main()
{
    int n, m, k; 
    cin >> n >> m >> k;
    vector<vector<int>> count(n + 1, vector<int>(m + 1, 0)); count[0][0] = 1;
    vector<vector<int>> way(n + 1, vector<int>(m + 1, 0));
    

    for (int i = 0; i < k; i++)
    {
        int n_dan, m_dan; cin >> n_dan >> m_dan;
        way[n_dan][m_dan] = 1;
        count[n_dan][m_dan] = 0;
    }

    for (int j = 1; j <= m; j++) 
    {
        if (way[0][j] == 1) break;
        count[0][j] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        if (way[i][0] == 1) break;
        count[i][0] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (way[i][j] == 0)
            {
                count[i][j] = (count[i - 1][j] + count[i][j - 1]) % MOD;
            }
        }
    }
    cout << count[n][m] % MOD << endl;
    return 0;
}
