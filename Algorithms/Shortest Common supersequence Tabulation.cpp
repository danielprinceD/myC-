#include <bits/stdc++.h>
using namespace std;

string shortestSupersequence(string &a, string &b){
	int n = a.length() , m = b.length();
	vector<vector<int>> dp(n+1 , vector<int> (m+1 , 0));

	for(int i=1;i<=n;i++)
	{
	    for(int j=1;j<=m;j++)
	    {
	        if(a[i-1] == b[j-1])
	            dp[i][j] = 1 + dp[i-1][j-1];
	       else 
	            dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
	    }
	}
	string ans = "";
	
	int i = n , j = m;
	
	while(i > 0 && j > 0)
	{
	    if(a[i-1] == b[j-1])
	    {
	     ans = a[i-1] + ans;
	     i--; j--;   
	    }
	    else if(dp[i-1][j] > dp[i][j-1])
	    {
	        ans = a[i-1] + ans;
	        i--;
	    }
	    else 
	   {
	       ans = b[j-1] + ans;
	       j--;
	   }
	}
	
	while(i > 0)
	{
	    ans = a[i-1] + ans;
	    i--;
	}
	while(j > 0)
	{
	    ans = b[j-1] + ans;
	    j--;
	}
	
	return ans;
}

int main()
{
    string s1 = "groot" , s2 = "brute";
    cout<<shortestSupersequence(s1 , s2);
    return 0;
}