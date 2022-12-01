class Solution
{
    public:
       	// BFS 
        bool canFinish(int num, vector<vector < int>> &pr)
        {
            int n = pr.size();
            queue<int> qu;
            vector<vector < int>> adj(num);
            for (int i = 0; i < n; i++)
            {
                adj[pr[i][0]].push_back(pr[i][1]);
            }
            vector<int> vis(num), ind(num);
            for (int i = 0; i < num; i++)
            {
                for (auto it: adj[i]) ind[it]++;
            }
            for (int i = 0; i < num; i++)
            {
                if (ind[i] == 0) qu.push(i);
            }
            int count = 0;
            while (!qu.empty())
            {
                int tp = qu.front();
                qu.pop();
                count++;
                for (auto it: adj[tp])
                {
                    ind[it]--;
                    if (ind[it] == 0)
                    {
                        qu.push(it);
                    }
                }
            }
            cout << count << " " << num << endl;
            if (count == num) return true;
            return false;
        }
};