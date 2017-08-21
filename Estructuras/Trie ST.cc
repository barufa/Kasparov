//~ Trie T;
//~ T.insert();Inserta una palabra
//~ T.search();Busca una palabra en el trie
//~ T.show(); Imprime en pantalla todas las palabras almacenadas
//~ T.erase();Borrar una palabra
//~ T.clear();
typedef struct Trie{
	map<char,Trie> M;
	bool EOW=false;
	void dfs(){
		forall(it,M){
			//Do work
			it->snd.dfs();
		}
	}
	void clear(){
		M.clear();
	}
//~ ------------------------------------------------------
	void insert(string s,int p=0){
		if(s[p+1])M[s[p]].insert(s,p+1);
		else M[s[p]].EOW=true;
	}
	bool search(string s,int p=0){
		if(M.find(s[p])!=M.end()){
			if(s[p+1])return M[s[p]].search(s,p+1);
			else return M[s[p]].EOW;
		}else return false;
	}
	void erase(string s,int p=0){
		if(!s[p] || (!p && !search(s)))return;
		if(M.find(s[p])!=M.end()){
			if(s[p+1])M[s[p]].erase(s,p+1);
			else M[s[p]].EOW=false;
		}
	}
	void show(){
		//????
	}
//~ ------------------------------------------------------
}Trie;
