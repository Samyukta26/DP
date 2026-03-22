vi mv = {0, 1, 0, -1, 0};

void bfs(vs &a, vector<vector<pair<I, I>>> &par, I &i, I &j)
{
    I n = a.size(), m = a[0].size();
    queue<pi> q;
    a[i][j] = '#';
    q.push({i, j});
    while (q.size())
    {
        I b = q.front().first, c = q.front().second;
        q.pop();
        for0(k, 4)
        {
            I l1 = b + mv[k], l2 = c + mv[k + 1];
            if (l1 >= 0 && l2 >= 0 && l1 < n && l2 < m && a[l1][l2] != '#')
            {
                par[l1][l2] = {b, c};
                if (a[l1][l2] == 'B')
                    return;
                a[l1][l2] = '#';
                q.push({l1, l2});
            }
        }
    }
}

void solve()
{
    def2(n, m);
    vs a(n);
    I b, c, d, e;
    for0(i, n)
    {
        in(a[i]);
        for0(j, m)
        {
            if (a[i][j] == 'A')
                b = i, c = j;
            if (a[i][j] == 'B')
                d = i, e = j;
        }
    }
    vector<vector<pair<I, I>>> par(n, vpi(m, {-1, -1}));
    bfs(a, par, b, c);
    
    if (par[d][e].first == -1)
        noo;
    S ans = "";
    while (b != d || c != e)
    {
        I f = par[d][e].first, g = par[d][e].second;
        if (d > f)
            ans += 'D';
        else if (d < f)
            ans += 'U';
        else if (e > g)
            ans += 'R';
        else
            ans += 'L';
        d = f, e = g;
    }
    reverse(all(ans));
    yes;
    outl(ans.size());
    outl(ans);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}