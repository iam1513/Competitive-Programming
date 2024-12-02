#include <bits/stdc++.h>
using namespace std;

/* TYPES  */
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n, m, l;
        cin >> n >> m >> l;

        vector<pair<int, int>> hrs(n);
        vector<pair<int, int>> power(n);

        mii hrdiff;
        mii powerUps;

        for (int i = 0; i < n; i++)
        {
            cin >> hrs[i].first >> hrs[i].second;
            hrdiff[hrs[i].first] = hrs[i].second - hrs[i].first;
        }

        for (int i = 0; i < m; i++)
        {
            cin >> power[i].first >> power[i].second;
            powerUps[power[i].first] = power[i].second;
        }

        queue<int> que;
        int cnt = 0;
        int i = 1;
        while (i <= l)
        {
            auto it1 = hrdiff.find(i);
            auto it2 = powerUps.find(i);

            if (it2 != powerUps.end())
            {
                que.push(it2->second);
                cout << it2->second << " ";
            }

            if (it1 != hrdiff.end())
            {
                int diff = it1->second;
                int sum = 1;
                while (!que.empty() && sum < diff)
                {
                    int a = que.front();
                    sum += a;
                    que.pop();
                    cnt++;
                }

                if (que.empty() && sum < diff)
                {
                    break;
                }
            }
            i++;
        }
        cout << endl;

        if (i != l)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << cnt << endl;
        }
    }

    return 0;
}