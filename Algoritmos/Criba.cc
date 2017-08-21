//Criba guarda en P[i] un divisor(primo) de i, y 0 si i es primo;
#define isPrime(n) ((Prime[(n)])? (false):(true))
ull Prime[MAXN];
void criba(ll mxp){//O(N*log log N)
	ll p;int cur=0;
	int w[]={4,2,4,2,4,6,2,6};
	for(p=4;p<=mxp;p+=2)Prime[p]=2;
	for(p=9;p<=mxp;p+=6)Prime[p]=3;
	for(p=25;p<=mxp;p+=10)Prime[p]=5; 
	for(p=7;(p*p)<=mxp;p+=w[cur++&7])if(!Prime[p])for(int j=p*p;j<=mxp;j+=(p<<1))Prime[j]=p;
}
