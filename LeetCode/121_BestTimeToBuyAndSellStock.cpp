class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mnValue = prices[0], mxDiff = 0;
        for(int i=1; i<prices.size(); i++){
            mnValue = min(mnValue, prices[i]);
            mxDiff = max(mxDiff, prices[i]-mnValue);
        }
        return mxDiff;
    }
};
