vector<int> G[MAXN];
int timer, numb[MAXN], low[MAXN], P[MAXN];
bitset<MAXN> visit;

void
dfs_point(int v, int p)
{
    low[v]   = numb[v] = ++timer;
    visit[v] = true;
    forall(u, G[v]) if (!visit[*u]) {
        dfs_point(*u, v);
        low[v] = min(low[v], low[*u]);
        P[v]  += (numb[v] <= low[*u]);
    } else if (*u != p) { low[v] = min(low[v], numb[*u]); }
}

void
Articulation(int n) // O(|V|)
{
    timer = 1;
    visit.reset();
    zero(P);
    forn(i, n) low[i] = INT_MAX;
    dfs_point(0, 0);
    P[0]--;
    forn(i, n) if (P[i]);  // i es un punto de articulacion
}
