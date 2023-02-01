class Solution {
public:
    int GCD(int a, int b){
        if(b==0)
            return a;
        return GCD(b, a%b);
    }
    string gcdOfStrings(string str1, string str2) {
        if(str1+str2 != str2+str1)
            return "";
        int gcd = GCD(str1.size(), str2.size());
        return str1.substr(0, gcd);
    }
};
