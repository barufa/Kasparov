//~ SparseTable S, cambiar el tipo en typedef;
//~ S.create(array,size,OP) inicializa la estructura, con OP asociativa e idempotente;
//~ S.query(l,r) responde la query en el intervalo [l,r];
//~ S.clear() limpia la estructura;
typedef int tipo;
typedef struct SparseTable{
	int size;
	vector<vector<tipo>> Table;
	tipo (*op)(tipo,tipo);
	void create(tipo arr[],int sz,tipo (*fnc) (tipo,tipo)){//O(NlgN)
		op=fnc;size=sz;
		int l=32-__builtin_clz(sz);
		forn(i,l){
			vector<tipo> v(sz+1,0);
			Table.push_back(v);
		}
		forn(i,sz)Table[0][i]=arr[i];
		sz=31-__builtin_clz(sz);
		forn(i,sz)forn(j,size-(1<<i))Table[i+1][j]=min(Table[i][j],Table[i][j+(1<<i)]);
	}
	tipo query(int i,int j){//O(1)
		int p=31-__builtin_clz(j-i+1);
		return min(Table[p][i],Table[p][j-(1<<p)+1]);
	}
	void clear(){//O(1)
		Table.clear();size=0;
	}
}SparseTable;
