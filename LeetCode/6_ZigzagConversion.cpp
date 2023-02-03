class Solution {
public:
    string convert(string s, int numRows) {
        int sz = s.size();
      if(numRows == 1){
        return s;
      }
      string ans;
      int cycle = 2 * numRows - 2;
      for(int i=0; i<numRows; i++){
        for(int j=i; j<sz; j+=cycle){
          ans += s[j];
          int cycle2 = (j-i) + cycle - i;
          if(i!=0 && i!=numRows-1 && cycle2<sz){
            ans += s[cycle2];
          }
        }
      }
      return ans;
    }
};
