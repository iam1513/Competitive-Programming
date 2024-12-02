#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7; // Define the modulo value

vector<int> dp;

int om(int n)
{
    if (n == 0)
    {
        return 1;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    int ans = 0;

    for (int i = 1; i <= 6; i++)
    {
        if (n - i >= 0)
        {
            ans = (ans + om(n - i)) % MOD; // Add and take modulo
        }
    }

    return dp[n] = ans; // Store the result modulo MOD
}

int main()
{
    int n;
    cin >> n;

    if (n == 0)
    {
        cout << 0 << endl;
        return 0;
    }

    dp.clear();
    dp.resize(n + 5, -1);

    cout << om(n) << endl;

    return 0;
}
