class Solution {
public:
    struct frontierData {
        int distance;
        pair<int, int> position;
        frontierData(int d, pair<int, int> p) : distance(d), position(p) {}
        bool operator>(const frontierData& other) const {
            return distance > other.distance;
        }
    };

    int minimumEffortPath(vector<vector<int>>& heights) {
        int tx = heights[0].size() - 1; 
        int ty = heights.size() - 1;    
        int cx = 0, cy = 0, res = 0;
        priority_queue<frontierData, vector<frontierData>, greater<frontierData>> frontier;
        frontier.push(frontierData(0, make_pair(0, 0)));  
        while (cx != tx || cy != ty) {
            auto currNode = frontier.top();
            while (heights[currNode.position.second][currNode.position.first] < 0) {
                frontier.pop();
                currNode = frontier.top();
            }
            res = max(res, currNode.distance);
            cx = currNode.position.first;
            cy = currNode.position.second;
            if (cx && heights[cy][cx - 1] > 0) {
                frontier.push(frontierData(abs(heights[cy][cx] - heights[cy][cx - 1]), make_pair(cx - 1, cy)));
            }
            if (cy && heights[cy - 1][cx] > 0) {
                frontier.push(frontierData(abs(heights[cy][cx] - heights[cy - 1][cx]), make_pair(cx, cy - 1)));
            }
            if (cx < tx && heights[cy][cx + 1] > 0) {
                frontier.push(frontierData(abs(heights[cy][cx] - heights[cy][cx + 1]), make_pair(cx + 1, cy)));
            }
            if (cy < ty && heights[cy + 1][cx] > 0) {
                frontier.push(frontierData(abs(heights[cy][cx] - heights[cy + 1][cx]), make_pair(cx, cy + 1)));
            }
            heights[cy][cx] = -heights[cy][cx];
        }
        return res;
    }
};
