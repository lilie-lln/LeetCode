class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, const vector<vector<int>>& edges) {
        vector<int> vis(n, 0);
        for(const auto& x : edges) vis[x[1]]++;
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(!vis[i]) ans.emplace_back(i);
        }
        return ans;
    }
};
