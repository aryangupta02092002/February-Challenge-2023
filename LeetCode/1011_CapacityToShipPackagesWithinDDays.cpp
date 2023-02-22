class Solution {
public:
    bool isPossible(vector<int> &weights, int lim, int days){
        int d = 1, sum = 0;

        for(int i=0; i<weights.size(); i++){
            sum += weights[i];

            if(sum > lim){
                d++;
                sum = weights[i];
            }
        }
        return d <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0;
        int mx = 0;

        for(int i=0; i<weights.size(); i++){
            sum += weights[i];
            mx = max(mx, weights[i]);
        }
        if(weights.size() == days){
            return mx;
        }
        int low = mx, high = sum, ans = 0;

        while(low <= high){
            int mid = low + (high-low)/2;

            if(isPossible(weights, mid, days) == true){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};
