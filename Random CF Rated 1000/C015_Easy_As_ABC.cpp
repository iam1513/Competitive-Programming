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
 
vector<vector<bool>> chk(3, vector<bool>(3, false));
 
void check_ans(string st, string &ans)
{
    if (ans == "")
    {
        ans = st;
    }
    else
    {
        for (ll i = 0; i < 3; i++)
        {
            if (ans[i] > st[i])
            {
                ans = st;
                break;
            }
            else if (ans[i] < st[i])
            {
                break;
            }
        }
    }
}
 
void func(vector<vector<char>> &ch, string st, string &ans, ll i, ll j)
{
    if (st.size() >= 3)
    {
        check_ans(st, ans);
        return;
    }
 
    chk[i][j] = true;
 
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
 
    for (int dir = 0; dir < 8; dir++)
    {
        int ni = i + dx[dir];
        int nj = j + dy[dir];
 
        if (ni >= 0 && ni < 3 && nj >= 0 && nj < 3 && !chk[ni][nj])
        {
            func(ch, st + ch[ni][nj], ans, ni, nj);
        }
    }
 
    chk[i][j] = false; // backtrack
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    vector<vector<char>> ch(3, vector<char>(3, 0));
 
    for (ll i = 0; i < 3; i++)
    {
        for (ll j = 0; j < 3; j++)
        {
            cin >> ch[i][j];
        }
    }
 
    string ans = "";
 
    for (ll i = 0; i < 3; i++)
    {
        for (ll j = 0; j < 3; j++)
        {
            string st = "";
            func(ch, st + ch[i][j], ans, i, j);
        }
    }
 
    cout << ans << endl;
 
    return 0;
}

// #include <bits/stdc++.h>

// #define ll long long
// #define pll pair<ll, ll>
// #define vll vector<ll>
// #define mll map<ll, ll>
// #define sl set<ll>
// #define sc set<char>

// #define pb push_back

// #define MOD 1000000007
// #define PI 3.1415926535897932384626433832795

// using namespace std;

// ll gcd(ll a, ll b)
// {
//     if (b == 0)
//         return a;
//     return gcd(b, a % b);
// }

// ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

// bool prime(ll a)
// {
//     if (a == 1)
//         return 0;
//     for (int i = 2; i <= round(sqrt(a)); ++i)
//         if (a % i == 0)
//             return 0;
//     return 1;
// }

// void take_input_vector(vll &nums, ll n)
// {
//     for (ll i = 0; i < n; i++)
//     {
//         cin >> nums[i];
//     }
// }

// void print_vector_to_debug(vll &nums, ll n)
// {
//     for (ll i = 0; i < n; i++)
//     {
//         cout << nums[i] << " ";
//     }
//     cout << "\n";
// }

// void check_ans(string st, string &ans)
// {
//     if (ans == "")
//     {
//         ans = st;
//     }
//     else if (st < ans)
//     { // Simplified comparison
//         ans = st;
//     }
// }

// vector<vector<bool>> chk(3, vector<bool>(3, false));

// void func(vector<vector<char>> &ch, string st, string &ans, ll i, ll j)
// {
//     if (st.size() == 3)
//     { // Changed from >= to ==
//         check_ans(st, ans);
//         return;
//     }

//     // Mark current cell as visited
//     chk[i][j] = true;

//     // Explore neighbors
//     if (i > 0 && !chk[i - 1][j])
//     {
//         func(ch, st + ch[i - 1][j], ans, i - 1, j);
//     }
//     if (i < 2 && !chk[i + 1][j])
//     {
//         func(ch, st + ch[i + 1][j], ans, i + 1, j);
//     }
//     if (j > 0 && !chk[i][j - 1])
//     {
//         func(ch, st + ch[i][j - 1], ans, i, j - 1);
//     }
//     if (j < 2 && !chk[i][j + 1])
//     {
//         func(ch, st + ch[i][j + 1], ans, i, j + 1);
//     }
//     if (i > 0 && j > 0 && !chk[i - 1][j - 1])
//     {
//         func(ch, st + ch[i - 1][j - 1], ans, i - 1, j - 1);
//     }
//     if (i > 0 && j < 2 && !chk[i - 1][j + 1])
//     {
//         func(ch, st + ch[i - 1][j + 1], ans, i - 1, j + 1);
//     }
//     if (i < 2 && j > 0 && !chk[i + 1][j - 1])
//     {
//         func(ch, st + ch[i + 1][j - 1], ans, i + 1, j - 1);
//     }
//     if (i < 2 && j < 2 && !chk[i + 1][j + 1])
//     {
//         func(ch, st + ch[i + 1][j + 1], ans, i + 1, j + 1);
//     }

//     // Unmark current cell
//     chk[i][j] = false;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     vector<vector<char>> ch(3, vector<char>(3));
//     for (ll i = 0; i < 3; i++)
//     {
//         for (ll j = 0; j < 3; j++)
//         {
//             cin >> ch[i][j];
//         }
//     }

//     string ans = "";

//     // Start from every cell
//     for (ll i = 0; i < 3; i++)
//     {
//         for (ll j = 0; j < 3; j++)
//         {
//             string st = "";
//             func(ch, st, ans, i, j);
//         }
//     }

//     cout << ans << endl;
//     return 0;
// }