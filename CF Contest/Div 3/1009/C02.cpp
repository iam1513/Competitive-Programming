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

        priority_queue<ll> mh;
        for (ll i = 0; i < n; i++)
        {
            ll num;
            cin >> num;
            mh.push(num);
        }

        while (mh.size() > 1)
        {
            ll first = mh.top();
            mh.pop();
            ll second = mh.top();
            mh.pop();

            ll newElement = first + second - 1;
            mh.push(newElement);
        }

        cout << mh.top() << endl;
    }

    return 0;
}