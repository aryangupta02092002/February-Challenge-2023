class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> u;
        int i = 0, j = 0, res = 0;
        
        while(j < fruits.size()){
            u[fruits[j]]++; 
            if(u.size() <= 2) 
                res = max(res, j-i+1);
            else{
                u[fruits[i]]--;
                if(u[fruits[i]] == 0) 
                    u.erase(fruits[i]);

                i++;
            }
            j++;
        }
        return res;
    }
};
