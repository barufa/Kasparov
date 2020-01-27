vector<int> G[MAXN];
bool visit[MAXN];
void
bfs(int nodo) // O(V)
{
    int v;

    queue<int> q;
    q.push(nodo);
    visit[nodo] = true;
    while (!q.empty()) {
        v = q.front();
        q.pop();
        forall(it, G[v]) if (!visit[*it]) {
            q.push(*it);
            visit[*it] = true;
            // Do work;
        }
    }
}

// ~ --------------------------------------------------
vector<int> G[MAXN];
bool visit[MAXN];
void
dfs(int nodo) // O(V)
{
    visit[nodo] = true;
    forall(it, G[nodo]) if (!visit[nodo]) {
        visit[nodo] = true;
        // Do work;
        dfs(*it);
    }
}
