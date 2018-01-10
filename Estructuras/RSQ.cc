//~ RSQ r;
//~ r.create(arreglo,len);
//~ r.query(desde,hasta);[desde,hasta]
//~ r.update(idx,valor);
//~ r.clear();
typedef struct RSQ{
    vector<int> bit;//binary indexed tree
    int sum(int i){//O(log N)
        int r;
        for(r=0;i>=0;i=(i&(i+1))-1)r+=bit[i];
        return r;
    }
    void add(int i,int value){//Funcion interna
		for(;i<(int)bit.size();i=i|(i+1))bit[i]+=value;
	}
    void create(int a[],int sz){//O(N*log N)
        bit.assign(sz,0);
        forn(i,sz)add(i,a[i]);
	}
	void update(int idx,int value){//O(log N)
		add(idx,-sum(idx)+value);
	}
    int query(int l,int r){return sum(r)-sum(l-1);}//O(log N)
    void clear(void){bit.clear();}//O(1);
}RSQ;
