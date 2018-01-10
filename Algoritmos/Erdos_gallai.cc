ll n,gr[MAXN],hr[MAXN];
bool graficable(int n){//O(N lg N)
	ll g=0;
	forn(i,n)g+=gr[i];
	if(g%2)return false;
	sort(gr,gr+n,greater<ll>());
	copy(gr,gr+n,hr);
	forn(i,n)hr[i+1]+=hr[i];
	forn(i,n){
		if(gr[i]<0)return false;
		ll j=lower_bound(gr+i+1,gr+n,i+1,greater<ll>())-gr;
		if(hr[i]>i*(i+1)+hr[n-1]-hr[j-1]+(j-i-1)*(i+1))return false;
	}
	return true;
}
