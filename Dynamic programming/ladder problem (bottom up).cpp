// Taking input as n and k where n is the number of steps and k is the max no of steps one can jump at a time.

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <iomanip> //for setprecision()
#include <cstring> //for memset()
using namespace std;
#define ll long long
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define w(x) int x; cin>>x; while(x--)
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int ladders_bottomup(int n, int k)  // O(NK)
{
	int dp[100] = {};

	dp[0] = 1, dp[1] = 1, dp[2] = 2;

	for (int i = 3; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			dp[i] += dp[i - j];
		}
	}

	return dp[n];
}

int ladders_bottomupOpt(int n, int k)  // O(N)
{
	int dp[101]={};
	
	dp[0] = dp[1] = 1;
	
	for(int i=2;i<=k;i++)
	    dp[i]=2*dp[i-1];
	
	for(int i=k+1;i<=n;i++)
	    dp[i]=2*dp[i-1]-dp[i-k-1];
	    
	return dp[n];
}
	
int main()
{
    
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, k, dp[100] = {};
	cin >> n >> k;

	cout << ladders_bottomup(n, k)<<endl;
	cout<<ladders_bottomupOpt(n,k);

	return 0;
}
