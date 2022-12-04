class Solution
{
    public:
        //STRIVER 
        int ladderLength(string begin, string end, vector<string> &word)
        {
            unordered_set<string> st(word.begin(), word.end());
            queue<pair<string, int>> qu;
            qu.push({ begin,
                1 });
            while (qu.empty() == false)
            {
                string wd = qu.front().first;
                int steps = qu.front().second;
                qu.pop();
                if (wd == end) return steps;
                for (int i = 0; i < wd.size(); i++)
                {
                    char original = wd[i];
                    for (char ch = 'a'; ch <= 'z'; ch++)
                    {
                        wd[i] = ch;
                        if (st.find(wd) != st.end())
                        {
                            qu.push({ wd,
                                steps + 1 });
                            st.erase(wd);
                        }
                    }
                    wd[i] = original;
                }
            }
            return 0;
        }
};