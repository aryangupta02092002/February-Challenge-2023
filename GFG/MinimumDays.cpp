//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    int getMinimumDays(int n,string str, vector<int> &p) {
        int ans = 0;
        char t;
        for(int i = 0 ; i < p.size() ; i++){
            str[p[i]] == '?' ? t = '#' : t = str[p[i]];
            if(p[i] == 0){
                if(str[p[i]+1]==t){
                    ans = i+1;
                    str[p[i]] = '?';
                }
            }
            else if(p[i] == n-1){
                if(str[p[i]-1]==t){
                    ans = i+1;
                    str[p[i]] = '?';
                }
            }
            else{
                if(str[p[i]+1]==t or str[p[i]-1]==t){
                    ans = i+1;
                    str[p[i]]='?';
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        string S;cin>>S;
        
        vector<int> P(N);
        Array::input(P,N);
        
        Solution obj;
        int res = obj.getMinimumDays(N,S, P);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
