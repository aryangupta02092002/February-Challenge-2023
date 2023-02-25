//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkCompressed(string S, string T) {
        // code here
        int i=0, j=0;
        
        while(i < S.size() && j < T.size()){
            if(S[i] == T[j]){
                i++;
                j++;
                continue;
            }
            
            int count = 0;
            
            while(j < T.size() && isdigit(T[j])){
                count = count * 10 + (T[j]-'0');
                j++;
            }
            
            i += count;
            if(count == 0){
                return 0;
            }
        }
        return i == S.size() && j == T.size();
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        
        cin>>S>>T;

        Solution ob;
        cout << ob.checkCompressed(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends
