#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t;
    cin >> t;

    while (t--)
    {
        ll n, r, b;
        cin >> n >> r >> b;

        ll regions = b + 1;
        ll mod = r % regions;
        ll i = 0;
        ll conR = r / regions + 1;

        string ans = "";

        while (i < mod)
        {
            for (ll i = 0; i < conR; i++)
            {
                ans += 'R';
            }
            i++;
            ans += 'B';
        }

        i = 0;

        while (i < (b + 1) - mod)
        {
            for (ll i = 0; i < conR - 1; i++)
            {
                ans += 'R';
            }
            i++;
            if (i == (b + 1) - mod)
            {
                break;
            }
            ans += 'B';
        }

        cout << ans << endl;
    }

    return 0;
}