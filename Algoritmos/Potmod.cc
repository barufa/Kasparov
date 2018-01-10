ll potmod(ll a,ll b,ll m){//O(log b);
	if(b==0)return 1;
	a%=m;
	return(potmod((a*a)%m,b/2,m)*(b%2?a:1))%m;
}//Calcula (a^b)%m;
