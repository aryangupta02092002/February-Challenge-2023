//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minIteration(int N, int M, int X, int Y){    
        // code here
        vector<vector<int>> adj(N+1, vector<int> (M+1, 0));
        adj[X][Y] = 1;
        
        queue<pair<int, int>> q;
        q.push({X, Y});
        
        int count = 0;
        
        while(!q.empty()){
            int sz = q.size();
            
            for(int i=0; i<sz; i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                if(x > 1 && adj[x-1][y] == 0){
                    q.push({x-1, y});
                    adj[x-1][y] = 1;
                }
                
                if(y > 1 && adj[x][y-1] == 0){
                    q.push({x, y-1});
                    adj[x][y-1] = 1;
                }
                
                if(x < N && adj[x+1][y] == 0){
                    q.push({x+1, y});
                    adj[x+1][y] = 1;
                }
                
                if(y < M && adj[x][y+1] == 0){
                    q.push({x, y+1});
                    adj[x][y+1] = 1;
                }
            }
            
            if(!q.empty()){
                count++;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends
