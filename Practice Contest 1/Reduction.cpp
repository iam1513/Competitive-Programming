#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void om(vector<int>& nums, int k) {
    for (int i = 0; i < nums.size() - 1; ++i) {
        if (nums[i] > k && nums[i + 1] > k) {
            nums[i]--;
            nums[i + 1]--;
        }
    }
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }

        sort(nums.begin(), nums.end(), greater<int>());
        
        om(nums, k);

        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
        }

        cout << sum << endl;
    }

    return 0;
}
