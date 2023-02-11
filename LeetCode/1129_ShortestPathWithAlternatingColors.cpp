class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto &e : redEdges){
            adj[e[0]].push_back({e[1], 0});
        }

        for(auto &e : blueEdges){
            adj[e[0]].push_back(make_pair(e[1], 1));
        }

        vector<int> ans(n, -1);
        vector<vector<bool>> vis(n, vector<bool>(2));
        queue<vector<int>> q;

        q.push({0, 0, -1});
        vis[0][1] = vis[0][0] = true;
        ans[0] = 0;

        while (!q.empty()) {
            auto element = q.front();
            int node = element[0], steps = element[1], prevColor = element[2];
            q.pop();

            for (auto& [neighbor, color] : adj[node]) {
                if (!vis[neighbor][color] && color != prevColor) {
                    vis[neighbor][color] = true;
                    q.push({neighbor, 1 + steps, color});
                    if (ans[neighbor] == -1) 
                        ans[neighbor] = 1 + steps;
                }
            }
        }
        return ans;
    }
};
