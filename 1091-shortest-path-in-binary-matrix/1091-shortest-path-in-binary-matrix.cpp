class Solution
{
    public:
       	//BFS is fine and very easy to implement
        int shortestPathBinaryMatrix(vector<vector < int>> &grid)
        {
            int n = grid.size();
            if (grid[0][0] || grid[n - 1][n - 1]) return -1;
            queue<pair<int, int>> qu;
            qu.push({ 0,
                0 });
            int count = 0;
            vector<int> ind1
            { -1, 0, 1, 0, -1, -1, 1, 1 };
            vector<int> ind2
            { 0,
                -1,
                0,
                1,
                -1,
                1,
                -1,
                1 };
            while (!qu.empty())
            {
                int r = qu.front().first;
                int c = qu.front().second;
                qu.pop();
                if (r == n - 1 && c == n - 1) return grid[r][c]+1;
                for (int j = 0; j < 8; j++)
                {
                    int x = r + ind1[j];
                    int y = c + ind2[j];
                    if (x >= n || y >= n || x < 0 || y < 0 || grid[x][y] != 0) continue;
                    qu.push({ x,
                        y });
                    grid[x][y] = grid[r][c] + 1;
                }
            }
            return -1;
        }
};