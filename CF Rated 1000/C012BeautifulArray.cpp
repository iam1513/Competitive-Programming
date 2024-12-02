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
        ll n, k, b, s;
        cin >> n >> k >> b >> s;
        vector<ll> nums(n);
        nums[0] = k * b;
        s -= k * b;
        if (s < 0)
        {
            cout << -1 << endl;
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                ll curr = min(k - 1, s);
                nums[i] += curr;
                s -= curr;
            }
            if (s > 0)
            {
                cout << -1 << endl;
            }
            else
            {
                for (int i = 0; i < n; i++)
                {
                    cout << nums[i] << " ";
                }
                cout << endl;
            }
        }
    }

    return 0;
}