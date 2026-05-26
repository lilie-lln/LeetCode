bool compare(pair<int, int> a, pair<int, int> b){
    return (a.second == b.second)? a.first < b.first:a.second < b.second;
};

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> ans;
        vector<int> res;

        for( int i=0;i<mat.size();i++){
            ans.push_back(make_pair(-1,0));
            for( int j=0;j<mat[i].size(); j++){
                ans[i].first=i;
                if(mat[i][j] == 1) {
                    ans[i].second++;
                }
            }
        }
		
        sort(ans.begin(), ans.end(), compare);
        
        int n=0;
        while(n<k){
            res.push_back(ans[n].first);
            n++;
        }
        return res;
    }
};
