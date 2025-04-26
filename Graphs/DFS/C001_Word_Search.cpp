#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define mll map<ll, ll>
#define sl set<ll>
#define sc set<char>

#define pb push_back

#define MOD 1000000007
#define PI 3.1415926535897932384626433832795

bool dfs(char **grid, string word, int n, int i, int r, int c)
{
    if (i >= word.length())
    {
        return true;
    }

    if (r < 0 || r >= n || c < 0 || c >= n || grid[r][c] != word[i])
    {
        return false;
    }

    grid[r][c] = '#'; // Mark as visited
    // Recurive intuition
    bool retval = false;
    vll row = {0, 0, -1, 1};
    vll col = {-1, 1, 0, 0};
    for (ll x = 0; x < 4; x++)
    {
        retval = dfs(grid, word, n, i + 1, r + row[x], c + col[x]);
        if (retval)
        {
            break;
        }
    }
    grid[r][c] = word[i];
    return retval;
}

bool find(char **grid, string word, int n)
{
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            if (grid[i][j] == word[0])
            {
                if (dfs(grid, word, n, 0, i, j))
                {
                    return true;
                }
            }
        }
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n = 4;
    char **grid = new char *[n];
    for (int i = 0; i < n; ++i)
    {
        grid[i] = new char[n];
    }

    // Initialize the grid
    grid[0][0] = 'A';
    grid[0][1] = 'B';
    grid[0][2] = 'C';
    grid[0][3] = 'E';
    grid[1][0] = 'S';
    grid[1][1] = 'F';
    grid[1][2] = 'C';
    grid[1][3] = 'S';
    grid[2][0] = 'A';
    grid[2][1] = 'D';
    grid[2][2] = 'E';
    grid[2][3] = 'E';
    grid[3][0] = 'A';
    grid[3][1] = 'B';
    grid[3][2] = 'C';
    grid[3][3] = 'E';

    string word = "ABCDZCED";

    cout << (find(grid, word, n) ? "true" : "false") << "\n";

    return 0;
}