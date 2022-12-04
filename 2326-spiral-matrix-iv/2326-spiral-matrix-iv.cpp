/**
 *Definition for singly-linked list.
 *struct ListNode {
 *   int val;
 *   ListNode * next;
 *   ListNode() : val(0), next(nullptr) {}
 *   ListNode(int x) : val(x), next(nullptr) {}
 *   ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        vector<vector < int>> spiralMatrix(int m, int n, ListNode *head)
        {
            vector<vector < int>> ans(m, vector<int> (n, 0));
            int top = 0, down = m - 1, left = 0, right = n - 1;
            int pro = m * n;
            while (left <= right && top <= down)
            {
                if (!pro) break;
                for (int i = left; i <= right; i++)
                {
                    if (head)
                    {
                        ans[top][i] = head->val;
                        head = head->next;
                        pro--;
                    }
                    else
                    {
                        ans[top][i] = -1;
                        pro--;
                    }
                }
                top++;
                if (!pro) break;
                for (int i = top; i <= down; i++)
                {
                    if (head)
                    {
                        ans[i][right] = head->val;
                        head = head->next;
                        pro--;
                    }
                    else
                    {
                        ans[i][right] = -1;
                        pro--;
                    }
                }
                right--;
                if (!pro) break;
                for (int i = right; i >= left; i--)
                {
                    if (head)
                    {
                        ans[down][i] = head->val;
                        head = head->next;
                        pro--;
                    }
                    else
                    {
                        ans[down][i] = -1;
                        pro--;
                    }
                }
                down--;
                if (!pro) break;
                for (int i = down; i >= top; i--)
                {
                    if (head)
                    {
                        ans[i][left] = head->val;
                        head = head->next;
                        pro--;
                    }
                    else
                    {
                        ans[i][left] = -1;
                        pro--;
                    }
                }
                left++;
            }
            return ans;
        }
};