#include <bits/stdc++.h>

#define ll long long
#define pll pair<ll, ll>
#define vll vector<ll>
#define mll map<ll, ll>
#define sl set<ll>
#define sc set<char>

#define pb push_back

#define MOD 1000000007
#define PI 3.1415926535897932384626433832795

using namespace std;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

bool prime(ll a)
{
    if (a == 1) return 0;
    for (int i = 2; i <= round(sqrt(a)); ++i)
        if (a % i == 0) return 0;
    return 1;
}

void take_input_vector(vll &nums, ll n)
{
    for (ll i = 0; i < n; i++) cin >> nums[i];
}

void print_vector_to_debug(vll &nums, ll n)
{
    for (ll i = 0; i < n; i++) cout << nums[i] << " ";
    cout << "\n";
}


ll n, m;
vector<vector<char>> grid;
ll si, sj, gi, gj;
ll ans = LLONG_MAX;

vector<vector<vector<ll>>> visited;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(ll i, ll j, ll state, ll steps)
{
    if (steps >= ans) return; 
    if (i == gi && j == gj)
    {
        ans = min(ans, steps);
        return;
    }

    for (int k = 0; k < 4; k++)
    {
        ll ni = i + dx[k], nj = j + dy[k];
        ll nstate = state;

        if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;

        char c = grid[ni][nj];
        if (c == '#') continue;

        if (c == 'o' || c == 'x')
        {
            if (c == 'o' && state == 0) continue;
            if (c == 'x' && state == 1) continue;
        }

        if (c == '?') nstate = 1 - state; 

        if (visited[ni][nj][nstate] <= steps + 1) continue;
        visited[ni][nj][nstate] = steps + 1;

        dfs(ni, nj, nstate, steps + 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    grid.assign(n, vector<char>(m));

    si = sj = gi = gj = -1;

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'S') { si = i; sj = j; }
            if (grid[i][j] == 'G') { gi = i; gj = j; }
        }
    }

    visited.assign(n, vector<vector<ll>>(m, vector<ll>(2, LLONG_MAX)));
    visited[si][sj][1] = 0;

    dfs(si, sj, 1, 0);

    if (ans == LLONG_MAX) cout << -1 << "\n";
    else cout << ans << "\n";

    return 0;
}
