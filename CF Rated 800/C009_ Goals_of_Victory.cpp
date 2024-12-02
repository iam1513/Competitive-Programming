#include <iostream>
#include <vector>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int sum = 0;

        for (int i = 0; i < n - 1; i++)
        {
            int a;
            cin >> a;
            sum += a;
        }

        cout << -sum << endl;
    }

    return 0;
}