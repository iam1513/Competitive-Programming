#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> dp;
const int MOD = 1e9 + 7;
int recom(int i, int j, vector<vector<char>> &paths, int n)
{
    if (i >= n || j >= n || i < 0 || j < 0 || paths[i][j] == '*')
    {
        return 0;
    }

    if (i == n - 1 && j == n - 1)
    {
        return 1;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int ans = 0;

    int right = (recom(i, j + 1, paths, n)) % MOD;
    int down = (recom(i + 1, j, paths, n)) % MOD;

    ans = (right + down) % MOD;

    return dp[i][j] = ans;
}

int main()
{

    int n;
    cin >> n;

    vector<vector<char>> paths(n, vector<char>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> paths[i][j];
        }
    }

    dp.clear();
    dp.resize(n, vector<int>(n, -1));

    int ans = recom(0, 0, paths, n);

    cout << ans << " ";

    return 0;
}