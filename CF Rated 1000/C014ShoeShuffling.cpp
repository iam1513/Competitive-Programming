#include <bits/stdc++.h>

#define ll long long
#define vll vector<ll>
#define io                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);

using namespace std;

int main()
{
    io;
    ll t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;
        vll nums(n), idx(n);

        for (ll i = 0; i < n; i++)
        {
            cin >> nums[i];
            idx[i] = i + 1; // 1-based indexing for output
        }

        ll l = 0, r = 0;
        bool valid = true;

        while (r < n)
        {
            while (r < n - 1 && nums[r] == nums[r + 1])
                r++;

            if (l == r) // Single unique element case
            {
                valid = false;
                break;
            }
            else
                rotate(idx.begin() + l, idx.begin() + r, idx.begin() + r + 1);

            l = r + 1;
            r = l;
        }

        if (valid)
        {
            for (ll i = 0; i < n; i++)
                cout << idx[i] << " ";
            cout << endl;
        }
        else
            cout << "-1" << endl;
    }
    return 0;
}
