vector<int> G[MAXN];
int numb[MAXN], low[MAXN], timer, scc;
bitset<MAXN> visit;
vector<int> V, SCC[MAXN];

void
dfs_tarjan(int u)
{
    numb[u]  = low[u] = timer++;
    visit[u] = true;
    V.push_back(u);
    forall(v, G[u]){
        if (numb[*v] == 0) dfs_tarjan(*v);
        if (visit[*v]) low[u] = min(low[u], low[*v]);
    }
    if (low[u] == numb[u]) {
        SCC[scc].clear();
        while (1) {
            int v = V.back();
            V.pop_back();
            visit[v] = false;
            SCC[scc].push_back(v);
            if (v == u) break;
        }
        scc++;
    }
}

int
Tarjan(int n) // O(|V|)
{
    timer = 1;
    scc   = 0;
    V.clear();
    visit.reset();
    forn(i, n) if (!numb[i]) dfs_tarjan(i);
    return scc;
}

// En SCC[i] guarda los vertices de la i-esima SCC(en cualquier orden), y hay scc componentes en total.
