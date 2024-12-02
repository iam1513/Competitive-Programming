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
        ll n;
        cin >> n;
        char ch;
        cin >> ch;
        string st;
        cin >> st;

        st += st;

        if (ch == 'g')
        {
            cout << 0 << endl;
        }

        else
        {
            ll i = 0;
            ll j = 1;
            ll cnt = 1;
            ll ans = 0;
            while (i < n && j < 2 * n)
            {
                if (st[i] != ch)
                {
                    i++;
                    if (i == j)
                    {
                        j++;
                    }
                }

                if (st[j] == 'g' && st[i] == ch)
                {
                    ans = max(ans, j - i);
                    i = j + 1;
                    j = j + 2;
                }
                if (st[j] != 'g')
                {
                    j++;
                }
            }
            cout << ans << endl;
        }
    }

    return 0;
}