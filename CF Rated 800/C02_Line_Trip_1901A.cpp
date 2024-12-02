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

/* FUNCTIONS */
#define f(i,s,e) for(long long int i=s;i<e;i++)

void func(int n,int x, vi &nums){

    int maxi = nums[0];
    f(i,0,n-1){
        if(maxi < (nums[i+1] - nums[i])){
            maxi = (nums[i+1] - nums[i]);
        }
    }
    maxi = max(maxi,2*(x-nums[n-1]));

    cout<<maxi<<endl;
}

/* Main()  function */
int main()
{

    int t;cin>>t;

    while(t--){
        int n,x;
        cin>>n>>x;

        vi nums(n);
        f(i,0,n){
            cin>>nums[i];
        }

        func(n,x,nums);

    }

	return 0;
}
/* Main() Ends Here */