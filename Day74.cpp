class Solution {
public:
    bool check[105][105];
    int result[105][105];
    vector<pair<int,int>> test = {{-1,0},{1,0},{0,-1},{0,1}};
    int n1, n2;
    bool valid(int i, int j) {
        if(i < 0 || i >= n1 || j < 0 || j >= n2) 
            return false;
        return true;
    }
    int bfs(int si, int sj, vector<vector<char>>& maze) {
        queue<pair<int,int>> q;
        q.push({si, sj});
        check[si][sj] = true;
        result[si][sj] = 0;
        
        while(!q.empty()) {
            pair<int,int> p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;
            
            for(int i = 0; i < 4; i++) {
                int nx = x + test[i].first;
                int ny = y + test[i].second;
                if(!valid(nx, ny) && (x != si || y != sj))
                    return result[x][y];
                if(valid(nx, ny) && !check[nx][ny] && maze[nx][ny] == '.') {
                    q.push({nx, ny});
                    check[nx][ny] = true;
                    result[nx][ny] = result[x][y] + 1;
                }
            }
        }
        return -1;
    }

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        n1 = maze.size();
        n2 = maze[0].size();
        memset(check, false, sizeof(check));
        return bfs(entrance[0], entrance[1], maze);
    }
};
