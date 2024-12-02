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
        int k;
        cin >> k;
        vi nums(k);

        for (int i = 0; i < k; i++)
        {
            cin >> nums[i];
        }

        int n = k - 2;

        sort(nums.begin(), nums.end());

        int i = 0, j = k - 1;

        while (i < j)
        {
            if (nums[i] * nums[j] == n)
            {
                break;
            }
            if (nums[i] * nums[j] > n)
            {
                j--;
            }
            if (nums[i] * nums[j] < n)
            {
                i++;
            }
        }

        cout << nums[i]<<" " << nums[j] << endl;
    }

    return 0;
}