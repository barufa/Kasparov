#define MAXV MAXN
#define INF  INT_MAX
typedef struct arista { int nodo, peso;
} arista;
vector<arista> G[MAXV];
int dist[MAXV][MAXV], path[MAXV][MAXV];
void
Floyd_Warshall(int V) // O(|V|^3)
{
    forn(i, V) forn(j, V) dist[i][j] = ((i == j) ? 0 : INF);
    forn(i, V) forn(j, V) path[i][j] = i;
    forn(i, V) forall(j, G[i]){
        dist[i][j->nodo] = j->peso;
        path[i][j->nodo] = i;
    }
    forn(k, V) forn(i, V) if (dist[i][k] != INF) {
        forn(j, V) if (dist[k][j] != INF) {
            if (dist[i][j] > dist[i][k] + dist[k][j]) {
                dist[i][j] = dist[i][k] + dist[k][j];
                path[i][j] = k;
            }
        }
    }
}

// dist[u][v]= distancia minima de u a v;
// path[u][v]=k ||| u-x0-x1-...-k-v;
bool
hasNegCycle(int v, int u, int V) // O(V)
{
    if (v == u) return dist[v][u] < 0;

    forn(i, V) if (dist[v][i] != INF && dist[i][i] < 0 && dist[i][u] != INF) return true;

    return false;
}

bool
inNegCycle(int v){ return dist[v][v] < 0; }

// True si hay un ciclo negativo en vu-camino, o si v==u retorna true si v esta en un algun ciclo negativo(esto ultimo es O(1));
void
printPath(int u, int v)
{
    if (u != v) printPath(u, path[u][v]);
    cout << v << ' ';
}
