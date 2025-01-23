#include <iostream>
#include <vector>
using namespace std;

#define ll long long

void solve()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n);

        ll total_product = 1;
        bool has_zero = false;
        for (ll i = 0; i < n; ++i)
        {
            cin >> a[i];
            if (a[i] == 0)
            {
                has_zero = true;
            }
            total_product *= a[i];
        }

        if (has_zero)
        {
            cout << "-1\n";
            continue;
        }

        ll left_product = 1;
        bool found = false;
        for (ll k = 0; k < n - 1; ++k)
        {
            left_product *= a[k];
            if (total_product % left_product == 0)
            {
                ll right_product = total_product / left_product;
                if (left_product == right_product)
                {
                    cout << (k + 1) << "\n";
                    found = true;
                    break;
                }
            }
        }

        if (!found)
        {
            cout << "-1\n";
        }
    }
}

int main()
{
    solve();
    return 0;
}