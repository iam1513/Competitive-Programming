#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define vll vector<ll>
#define mll map<ll, ll>
#define sl set<ll>
#define sc set<char>
#define pb push_back
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    vector<ll> mel, cost;
    mel.push_back(1);
    cost.push_back(3);

    ll p = 3; 
    ll k = 1;
    while (p <= 1e9)
    {
        ll c = p * 3 + k * (p / 3);
        mel.push_back(p);
        cost.push_back(c);
        p *= 3;
        k++;
    }

    while (t--)
    {
        ll n;
        cin >> n;
        ll ans = 0;

        while (n > 0)
        {
            int idx = upper_bound(mel.begin(), mel.end(), n) - mel.begin();
            idx--; 
            ans += cost[idx];
            n -= mel[idx];
        }

        cout << ans << "\n";
    }
    return 0;
}