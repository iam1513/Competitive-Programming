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

bool isPrime(int num)
{
    if (num <= 1)
        return false;
    if (num == 2 || num == 3)
        return true;
    if (num % 2 == 0 || num % 3 == 0)
        return false;

    for (int i = 5; i * i <= num; i += 6)
    {
        if (num % i == 0 || num % (i + 2) == 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vi nums(n);
        nums[0] = 1;

        int s = n % 2 == 1 ? n / 2 : n / 2 - 1;
        for (int i = 1; i <= s; i++)
        {
            nums[i] = nums[i - 1] + 2;
        }
        nums[s + 1] = 2;
        for (int i = s + 2; i < n; i++)
        {
            nums[i] = nums[i - 1] + 2;
        }

        // for (int i = 0; i < n; i++)
        // {
        //     cout << nums[i] << " ";
        // }
        // cout << endl;

        int ptr1 = s, ptr2 = s + 1;

        while (ptr2 < n)
        {
            int sum = nums[ptr1] + nums[ptr2];
            if (!isPrime(sum))
            {
                break;
            }
            else
            {
                ptr2++;
            }
        }

        if (ptr2 != n)
        {
            swap(nums[s + 1], nums[ptr2]);
        }

        if (n == 2 || n == 4 || ptr2 == n)
        {
            int ans = -1;
            cout << ans << endl;
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

    return 0;
}