#define MAXV 300
#define INF 1e9
map<int,int> G[MAXV];
int parent[MAXV];
bitset<MAXV> visit;

ll augment(int v,int m,int src){
	if(v==src)return m;
	else if(parent[v]!=-1){
		ll f=augment(parent[v],min(m,G[parent[v]][v]),src);
		G[parent[v]][v]-=f,G[v][parent[v]]+=f;
		return f;
	}
	return 0;
}

ll EdmondsKarp(int src,int dst,int V){//O(V*E^2)
	int v;
	ll maxflow=0,flow;
	do{
		queue<int> Q;
		flow=0,fill(parent,parent+V,-1),visit.reset(),Q.push(src);
		while(!Q.empty()){
			v=Q.front(),Q.pop();
			if(v==dst)break;
			forall(u,G[v])if(u->snd>0 && !visit[u->fst])
				visit[u->fst]=true,parent[u->fst]=v,Q.push(u->fst);
		}
		flow=augment(dst,INF,src);
		maxflow+=flow;
	}while(flow>0);
	return maxflow;
}
