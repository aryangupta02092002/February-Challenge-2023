//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        int i=0;
        int ans=INT_MAX;
        unordered_map<char,int> mp;
        while(i<s.length()){
            if(s[i]=='b' or s[i]=='a' or s[i]=='l' or s[i]=='o' or s[i]=='n')
                mp[s[i]]++;
            i++;
        }
        
        if(mp.find('b')==mp.end() or mp.find('a')==mp.end() or mp.find('l')==mp.end() or mp.find('o')==mp.end() or mp.find('n')==mp.end() )
            return 0;
        for(i=0;i<s.length();i++){
            if(s[i]=='b' or s[i]=='a' or s[i]=='n')
                ans = min(ans,mp[s[i]]);
            else if(s[i]=='l' or s[i]=='o')
                ans = min(ans,(mp[s[i]])/2);
            else 
                continue;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends
