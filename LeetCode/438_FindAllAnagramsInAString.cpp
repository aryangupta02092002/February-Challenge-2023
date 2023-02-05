class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if(s.size() < p.size()){
            return ans;
        }
        vector<char> tmpP(26, 0);
        vector<char> tmpS(26, 0);
        for(int i=0; i<p.size(); i++){
            tmpP[p[i]-'a']++;
            tmpS[s[i]-'a']++;
        }
        for(int i=0; i<=s.size()-p.size(); i++){
            if(tmpS == tmpP){
                ans.push_back(i);
            }
            tmpS[s[i]-'a']--;
            if(i + p.size() < s.size()){
                tmpS[s[i + p.size()] - 'a']++;
            }
        }
        return ans;
    }
};
