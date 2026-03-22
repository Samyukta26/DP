#include <bits/stdc++.h>
using namespace std;

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int dfs(int i, int j, vector<vector<char>> &grid,
        vector<vector<int>> &dp, int n, int m)
{
    if (dp[i][j] != -1)
    
        return dp[i][j];

    int best = 1;

    for (int d = 0; d < 8; d++)
    {
        int ni = i + dx[d];
        int nj = j + dy[d];

        if (ni >= 0 && ni < n && nj >= 0 && nj < m)
        {
            if (grid[ni][nj] == grid[i][j] + 1)
            {
                best = max(best, 1 + dfs(ni, nj, grid, dp, n, m));
            }
        }
    }

    return dp[i][j] = best;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    int caseNo = 1;

    while (cin >> n >> m)
    {
        if (n == 0 && m == 0)
            break;

        vector<vector<char>> grid(n, vector<char>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }

        vector<vector<int>> dp(n, vector<int>(m, -1));

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 'A')
                {
                    ans = max(ans, dfs(i, j, grid, dp, n, m));
                }
            }
        }

        cout << "Case " << caseNo++ << ": " << ans << '\n';
    }

    return 0;
}
