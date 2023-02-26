//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs (vector<vector<int>>& adj, int i, vector<int>&vis, vector<int>&tmp){
        tmp.push_back(i);
        vis[i]++;
        
        for (auto it:adj[i])
        {
            if (!vis[it])
                dfs(adj, it, vis, tmp);
        }
    }
    int findNumberOfGoodComponent(int v, vector<vector<int>>& adj) {
        // code here
        vector<int> vis(v+1, 0);
        int ans = 0;
        
        for(int i=1; i<=v; i++){
            if(!vis[i]){
                vector<int> tmp;
                dfs(adj, i, vis, tmp);
                
                bool flag = 0;
                
                for(int i=0; i<tmp.size(); i++){
                    if(adj[tmp[i]].size() < tmp.size()-1){
                        flag = 1;
                        break;
                    }
                }
                
                if(flag == 0){
                    ans++;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int E, V;
        cin >> E >> V;
        vector<vector<int>> adj(V + 1, vector<int>());
        for (int i = 0; i < E; i++) {
            int u, v;

            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;

        int res = obj.findNumberOfGoodComponent(V, adj);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends
