class Solution {
public:
    vector<vector<int>> distance{{1,0},{0,1},{0,-1},{-1,0}};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {

        int row = maze.size();
        int col = maze[0].size();
        queue<pair<int, int>> que;
        que.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';

        int steps = 0;

        // classic bfs ka code hai
        while (!que.empty()) {
            int n = que.size(); // ek level ko pura traverse karne ke liye uska
                                // size nikalte hai

            while (n--) {
                pair<int, int> temp = que.front();
                que.pop();

                int i = temp.first;
                int j = temp.second;
                if (temp != make_pair(entrance[0], entrance[1]) &&
                    (i == 0 || i == row - 1 || j == 0 || j == col - 1)) {
                    return steps;
                }

                for (auto dis : distance) {
                    int new_r = i + dis[0];
                    int new_c = j + dis[1];

                    if (new_r >= 0 && new_r < row && new_c >= 0 &&
                        new_c < col && maze[new_r][new_c] != '+') {
                        que.push({new_r, new_c});
                        maze[new_r][new_c] = '+';
                    }
                }
            }

            steps++;
        }

        
        return -1;
    }
};