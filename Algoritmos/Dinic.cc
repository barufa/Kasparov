// Agregar aristas con add_edge
#define MAXV MAXN
#define INF  1e18

typedef struct arista {
    int v, rev;
    ll  f, cap;
    arista(int v, int rev, ll f, ll cap) : v(v), rev(rev), f(f), cap(cap){ }
} arista;

int dist[MAXV], work[MAXV], q[MAXV];
vector<arista> G[MAXV];

void
add_edge(int u, int v, ll p)
{
    G[u].push_back(arista(v, G[v].size(), 0, p));
    G[v].push_back(arista(u, G[u].size() - 1, 0, 0));
}

bool
bfs_dinic(int src, int dst, int V)
{
    fill(dist, dist + V, -1);
    dist[src] = 0;
    q[0]      = src;
    int qt = 1;
    forn(qh, qt){
        int u = q[qh];

        forall(e, G[u]){
            int v = e->v;

            if (dist[v] < 0 && e->f < e->cap)
                dist[v] = dist[u] + 1, q[qt++] = v;
        }
    }
    return dist[dst] >= 0;
}

ll
dfs_dinic(int u, int dst, ll flow)
{
    if (u == dst) return flow;

    for (int &i = work[u]; i < (int) G[u].size(); i++) {
        arista &e = G[u][i];
        if (e.cap <= e.f) continue;
        int v = e.v;
        if (dist[v] == dist[u] + 1) {
            ll df = dfs_dinic(v, dst, min(flow, e.cap - e.f));
            if (0 < df) {
                e.f += df, G[v][e.rev].f -= df;
                return df;
            }
        }
    }
    return 0;
}

ll
Dinic(int src, int dst, int V) // O(E*V^2)
{
    ll maxflow = 0;

    while (bfs_dinic(src, dst, V)) {
        fill(work, work + V, 0);
        while (ll d = dfs_dinic(src, dst, INF)) maxflow += d;
    }
    return maxflow;
}

// Corte minimo: vertices con dist[v]>=0 (del lado de src) VS.  dist[v]==-1 (del lado del dst)
// Para el caso de la red de Bipartite Matching (Sean V1 y V2 los conjuntos mas proximos a src y dst respectivamente):
// Reconstruir matching: para todo v1 en V1 ver las aristas a vertices de V2 con it->f>0, es arista del Matching
// Min Vertex Cover: vertices de V1 con dist[v]==-1 + vertices de V2 con dist[v]>0
// Max Independent Set: tomar los vertices NO tomados por el Min Vertex Cover
// Max Clique: construir la red de G complemento (debe ser bipartito!) y encontrar un Max Independet Set
// Min Edge Cover: tomar las aristas del matching + para todo vertices no cubierto hasta el momento, tomar cualquier arista de el.
