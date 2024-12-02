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

}

/* Main()  function */
int main()
{

    int t;cin>>t;

    while(t--){
        int n,k;
        cin>>n>>k;

        vi nums(n);
        f(i,0,n){
            cin>>nums[i];
        }

        if(is_sorted(nums.begin(),nums.end()) || k>1){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }

    }

	return 0;
}