#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, d;
    cin >> n >> d;

    priority_queue<ll> qu;

    for (ll i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        qu.push(a);
    }
    ll cnt = 0, ans = 0;
    while (!qu.empty() && cnt <= n)
    {
        ll sum = (d / qu.top()) + 1;
        // cout << "sum :" << sum << endl;
        cnt += sum;
        // cout << "cnt :" << cnt << endl;
        if (cnt > n)
        {
            break;
        }
        ans++;
        // cout << "ans :" << ans << endl;
        qu.pop();
    }
    cout << ans << endl;

    return 0;
}