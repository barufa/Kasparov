vector<int> G[MAXN];
int timer, numb[MAXN], low[MAXN];
bitset<MAXN> visit;

void
dfs_bridge(int v, int p = -1)
{
    low[v]   = numb[v] = timer++;
    visit[v] = true;
    forall(u, G[v]){
        if (!low[*u]) {
            dfs_bridge(*u, v);
            low[v] = min(low[v], low[*u]);
            if (low[*u] > numb[v]);  // (*u,v) es puente
        } else if (p != *u) { low[v] = min(low[v], numb[*u]); }
    }
}

void
Bridge(int n) // O(|V|)
{
    timer = 1;
    visit.reset();
    forn(i, n) if (!visit[i]) dfs_bridge(i);
}
