#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{

    ll n;
    cin >> n;
    vector<ll> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    set<ll> ans;

    ans.insert(nums[0]);

    for (int i = 1; i < n; i++)
    {

        vector<ll> temp;
        for (auto it = ans.begin(); it != ans.end(); it++)
        {
            temp.push_back(*it + nums[i]);
        }
        ans.insert(nums[i]);
        for (int i = 0; i < temp.size(); i++)
        {
            ans.insert(temp[i]);
        }
    }

    cout << ans.size() << endl;
    for (auto it = ans.begin(); it != ans.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}