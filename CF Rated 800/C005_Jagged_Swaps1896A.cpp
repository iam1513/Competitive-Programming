#include <iostream>
#include <vector>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int a;
        cin >> a;

        vector<int> nums(a);
        for (int i = 0; i < a; i++)
        {
            cin >> nums[i];
        }

        if (nums[0] != 1)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }

    return 0;
}