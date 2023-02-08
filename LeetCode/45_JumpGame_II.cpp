class Solution {
public:
    int jump(vector<int>& nums) {
        int sz = nums.size();
        
        int curr = 0, mx = 0, count=0;
        for(int i=0; i<sz-1; i++){
            mx = max(mx, i + nums[i]);
            
            if(curr == i){
                curr = mx;
                count++;
            }
        }
        return count;
    }
};
