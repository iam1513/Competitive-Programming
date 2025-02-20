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

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

bool prime(ll a)
{
    if (a == 1)
        return 0;
    for (int i = 2; i <= round(sqrt(a)); ++i)
        if (a % i == 0)
            return 0;
    return 1;
}

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string st;
    cin >> st;

    map<char, ll> up, low; // Map characters to their index values

    for (ll i = 65; i <= 90; i++) // Uppercase letters
    {
        up[char(i)] = i - 64; // 'A' -> 1, 'B' -> 2, ..., 'Z' -> 26
    }

    for (ll i = 97; i <= 122; i++) // Lowercase letters
    {
        low[char(i)] = i - 96; // 'a' -> 1, 'b' -> 2, ..., 'z' -> 26
    }

    ll u = 0, l = 0;

    for (ll i = 0; i < st.size(); i++)
    {
        char ch = st[i];
        if (up.find(ch) != up.end())
        {
            u++;
        }
        else
        {
            l++;
        }
    }

    if (u > l)
    {
        transform(st.begin(), st.end(), st.begin(), ::toupper); // Convert to uppercase
    }
    else
    {
        transform(st.begin(), st.end(), st.begin(), ::tolower); // Convert to lowercase
    }

    cout << st << endl;
    return 0;
}