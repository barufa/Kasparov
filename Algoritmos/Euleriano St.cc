vector<int> G[MAXN];
vector<int> EulTour;
int N[MAXN][MAXN];
bitset<MAXN> visit;

void dfs_euler(int v){
	for(auto u:G[v]){
		if(N[v][u]>0){
			N[v][u]--;
			N[u][v]--;
			dfs_euler(u);
		}
	}
	EulTour.push_back(v);
}

void EulerTour(int n){//Encuentra un ciclo euleriano(dado que el grafo es euleriano)
	forn(u,n)for(auto v:G[u])N[u][v]++;
	dfs_euler(0);
}

bool isEuler(int n){//Verifica si el grafo es euleriano
	forn(u,n)if((int)G[u].size()%2!=0)return false;
	queue<int> Q;
	Q.push(0);
	visit[0]=true;
	while(!Q.empty()){
		int v=Q.front();Q.pop();
		for(auto u:G[v])if(!visit[u]){
			visit[u]=true;
			Q.push(u);
		}
	}
	forn(u,n)if(!visit[u])return false;
	return true;
}

//Solo probado con grafos no dirigidos
