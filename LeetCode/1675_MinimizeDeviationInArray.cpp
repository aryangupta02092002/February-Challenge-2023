class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;
        int mn = INT_MAX, diff = INT_MAX;

        for(auto i : nums){
            if(i%2 != 0){
                i *= 2;
            }
            mn = min(mn, i);
            pq.push(i);
        }

        while(pq.top()%2 == 0){
            int mx = pq.top();
            pq.pop();
            diff = min(diff, mx-mn);
            mn = min(mn, mx/2);
            pq.push(mx/2);
        }
        return min(diff, pq.top()-mn);
    }
};
