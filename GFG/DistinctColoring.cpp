//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

#define ll long long
class Solution{   
    public:
    
        vector<vector<ll>>dp;
        ll solve(int i,int prev,int n,vector<vector<int>>&cost){
            if(i == n)
                return 0;
            if(dp[i][prev+1] != -1)
                return dp[i][prev+1];
            ll ans=1e15;
            for(int c=0; c<3; c++){
                if(c == prev)
                    continue;
                ans = min(ans, cost[c][i] + solve(i+1, c, n, cost));
            }
            return dp[i][prev+1] = ans;
        }
        long long int distinctColoring(int n, int r[], int g[], int b[]){
            vector<vector<int>>cost(3, vector<int>(n));
            dp = vector<vector<ll>>(n+1, vector<ll>(4, -1));
            
            for(int i=0; i<n; i++){
                cost[0][i] = r[i];
                cost[1][i] = g[i];
                cost[2][i] = b[i];
            }
            return solve(0, -1, n, cost);
        }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int r[N],g[N],b[N];
        for(int i = 0; i < N; i++)
            cin >> r[i];
        for(int i = 0; i < N; i++)
            cin >> g[i];
        for(int i = 0; i < N; i++)
            cin >> b[i];
        
        Solution ob;
        cout << ob.distinctColoring(N, r, g, b) << endl;
    }
    return 0; 
}
// } Driver Code Ends
