class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int sz = profits.size();
        vector<pair<int, int>> v(sz);

        for(int i=0; i<sz; i++){
            v[i] = {capital[i], profits[i]};
        }

        sort(v.begin(), v.end());
        int i = 0;
        priority_queue<int> maxCap;

        while(k--){
            while(i < sz && v[i].first <= w){
                maxCap.push(v[i].second);
                i++;
            }

            if(maxCap.empty()){
                break;
            }
            w += maxCap.top();
            maxCap.pop();
        }
        return w;
    }
};
