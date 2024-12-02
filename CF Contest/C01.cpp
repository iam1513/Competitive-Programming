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
        int n;
        cin >> n;

        vi nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        mii cnt;
        for (int i = 0; i < n; i++)
        {
            cnt[nums[i]]++;
        }

        int ans = 0;

        for (auto ele : cnt)
        {
            ans += ele.second / 2;
        }

        cout << ans << endl;
    }

    return 0;
}