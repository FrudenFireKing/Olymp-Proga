#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
 
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> count(n, vector<int>(m));
    

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ll c; cin >> c;
            count[i][j] = c;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0) continue;
            else if (i == 0) count[i][j] = (count[i][j - 1] + count[i][j]);
            else if (j == 0) count[i][j] = (count[i - 1][j] + count[i][j]);
            else {
                if (count[i - 1][j] > count[i][j - 1]) count[i][j] = (count[i - 1][j] + count[i][j]) % MOD;
                else count[i][j] = (count[i][j - 1] + count[i][j]);
                
            }

        }
    }
    cout << count[n - 1][m - 1] << endl;
    return 0;
}
