#define INF INT_MAX
typedef struct arista { int nodo, peso;
} arista;
ll dist[MAXN];
vector<arista> G[MAXN];
void
Bellman_Ford(int s, int V) // O(|V|*|E|)
{
    forn(i, V + 1) dist[i] = INF;
    dist[s] = 0;
    forn(k, V - 1) forn(u, V) if (dist[u] != INF)
        forall(v, G[u]) dist[v->nodo] = min(dist[u] + v->peso, dist[v->nodo]);
}

bool
hasNegCycle(int V) // O(|V|)
{
    forn(u, V) if (dist[u] != INF)
        forall(v, G[u]) if (dist[u] + v->peso < dist[v->nodo]) return true;

    return false;
}
