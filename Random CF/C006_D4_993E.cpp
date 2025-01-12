#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        ll k, l1, r1, l2, r2;
        cin >> k >> l1 >> r1 >> l2 >> r2;

        ll kn = 1, ans = 0;

        while (r2 / kn >= l1)
        {
            ll start = max((l2 - 1) / kn + 1, l1);

            // cout << "Start " << start << " ";
            ll end = min(r2 / kn, r1);
            // cout << "End " << end << " ";

            if (start <= end)
                ans += (end - start + 1);

            if (kn > LLONG_MAX / k)
                break;
            kn *= k;

            // cout << "ANs " << ans << endl;
        }

        cout << ans << '\n';
    }

    return 0;
}
