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
        ll n, k;
        cin >> n >> k;

        string st;
        cin >> st;

        ll maxi = 0;
        ll ans = 0;

        for (int i = 0; i < k; i++)
        {
            if (st[i] == 'B')
            {
                ans++;
            }
        }
        maxi = max(ans, maxi);
        ll i = 0, j = k;

        while (j < n)
        {
            if (st[i] == 'B')
            {
                ans--;
            }
            if (st[j] == 'B')
            {
                ans++;
            }

            maxi = max(ans, maxi);
            i++;
            j++;
        }

        cout << k - maxi << endl;
    }

    return 0;
}