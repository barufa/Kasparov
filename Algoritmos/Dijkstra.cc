#define INF INT_MAX
typedef struct arista{int nodo,peso;}arista;
vector<arista> G[MAXN];
int dst[MAXN],path[MAXN];
int dijkstra(int u,int t,int V){//O((V+E)lgV)
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> Q;
	forn(i,V)dst[i]=INF;
	forn(i,V)path[i]=-1;
	dst[u]=0;
	Q.push({dst[u],u});
	while(!Q.empty()){
		u=Q.top().snd;Q.pop();
		if(u==t)break;
		forall(v,G[u])if(dst[u]+v->peso<dst[v->nodo]){
			dst[v->nodo]=dst[u]+v->peso;
			path[v->nodo]=u;
			Q.push({dst[v->nodo],v->nodo});
		}
	}
	return dst[t];
	//~ for(int v=t;v!=-1;v=path[v])cout << v << " \n"[(v==u)]; u-v camino(impreso al reves)
}
