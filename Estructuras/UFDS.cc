//UnionFind U;
//U.add(elem);Agrega un elemento al universo(como conjunto unitario)
//U.find(elem1);Devuelve el conjunto del elemento(puede cambiar si se usa merge)
//U.merge(elem1,elem2);Une dos conjuntos
//U.clear(); Limpia la estructura
//U.size; Cantidad de conjuntos

//Cantidad de elementos desconocida o fija
//------------------------------------------------
#define MAXN_UNION 100010
typedef struct UnionFind{
	int maxsize,size=0;
	int parent[MAXN_UNION],rango[MAXN_UNION];
	void add(int v){parent[v]=v;rango[v]=0;size++;}//O(1)
	int find(int v){if(v==parent[v])return v;return parent[v]=find(parent[v]);}//O(1)
	void merge(int a,int b) {//O(M*α(M,N));M=#SETS;N=#ELEM.
			a=find(a);b=find(b);
			if(a!=b){
				if(rango[a]<rango[b])swap(a,b);
				parent[b]=a;
				if(rango[a]==rango[b])rango[a]++;
				size--;
			}
	}
	void clear(){size=0;zero(parent);zero(rango);}
}UnionFind;
//------------------------------------------------

//Cantidad de elementos varia en cada caso, SETEAR CON CREATE
//------------------------------------------------
typedef struct UnionFind{
	int maxsize,size=0;
	vector<int> parent,rango;
	void create(int n){//O(N)
		maxsize=n;
		parent.insert(parent.begin(),n+1,-1);
		rango.insert(rango.begin(),n+1,-1);
	}
	void add(int v){//O(1)
		parent[v]=v;
		rango[v]=0;
		size++;
	}
	int find(int v){//O(1)
		if(v==parent[v])return v;
		return parent[v]=find(parent[v]);
	}
	void merge(int a,int b){//O(M*α(M,N));M=#SETS;N=#ELEM.
			a=find(a);b=find(b);
			if(a!=b){
				if(rango[a]<rango[b])swap(a,b);
				parent[b]=a;
				if(rango[a]==rango[b])rango[a]++;
				size--;
			}
	}
	void clear(){
		size=0;
		parent.clear();
		rango.clear();
	}
}UnionFind;
//------------------------------------------------
