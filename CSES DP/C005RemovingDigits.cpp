#include <iostream>
#include <climits>
#include <vector>
using namespace std;
vector<int> dp;

int recom(int num)
{

    if (num < 0)
    {
        return INT_MAX;
    }

    if (num == 0)
    {
        return 0;
    }

    if (dp[num] != -1)
    {
        return dp[num];
    }

    int ans = INT_MAX;

    int temp = num;
    while (temp > 0)
    {
        int x = temp % 10;
        if (x > 0)
        {
            ans = min(ans, 1 + recom(num - x));
        }
        temp /= 10;
    }

    return dp[num] = ans;
}

int main()
{
    int n;
    cin >> n;

    dp.clear();
    dp.resize(n + 5, -1);

    int ans = recom(n);
    cout << ans << " ";

    return 0;
}
