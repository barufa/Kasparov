/*bint:
* Solo trabaja con numeros positivos.
* Para leer un bint se debe usar n.read(string)
* Para imprimir un bint se debe usar n.out();
----------------------------------------------------------------
* bigint:
* Agregado a bint para trabajar con numeros negativos.
* Para leer y escribir en bigint se puede usar cin >> y cout <<.(existe read() para bigint).
----------------------------------------------------------------
* No estan definidos los operadores ++,+=,--,-=,etc en ninguno de los tipos;
*/
#define BASEXP 6
#define BASE 1000000
#define LMAX 1000
struct bint{
	int l;
	ll n[LMAX];
	bint(ll x=0){
		l=1;
		forn(i,LMAX){
			if(x)l=i+1;
			n[i]=x%BASE;x/=BASE;
		}
	}
	void read(string x){
		l=(x.size()-1)/BASEXP+1;
		fill(n,n+LMAX,0);
		ll r=1;
		forn(i,x.size()){
			n[i/BASEXP]+=r*(x[x.size()-1-i]-'0');
			r*=10;
			if(r==BASE)r=1;
		}
	}
    bint(string x){read(x);}
    void out(){
		cout << n[l-1];
		rforn(i,l-1)cout << setprecision(6) << setw(BASEXP) << setfill('0') << n[i];
	}
	void invar(){
		fill(n+l,n+LMAX,0);
		while(l>1 && !n[l-1])l--;
	}
};
bint operator+(const bint&a,const bint&b){
	bint c;
    c.l=max(a.l,b.l);
    ll q=0;
    forn(i,c.l)q+=a.n[i]+b.n[i],c.n[i]=q%BASE,q/=BASE;
    if(q)c.n[c.l++]=q;
    c.invar();
    return c;
}
pair<bint,bool> lresta(const bint& a, const bint& b){
	bint c;
    c.l=max(a.l, b.l);
    ll q=0;
    forn(i,c.l)q+=a.n[i]-b.n[i],c.n[i]=(q+BASE)%BASE,q=(q+BASE)/BASE-1;
    c.invar();
    return make_pair(c,!q);
}
bint operator-(const bint&a, const bint&b){return lresta(a, b).first;}
bool operator<(const bint&a, const bint&b){return !lresta(a, b).second;}
bool operator<=(const bint&a, const bint&b){return lresta(b, a).second;}
bool operator==(const bint&a, const bint&b){return a <= b && b <= a;}
bint operator*(const bint&a, ll b){
    bint c;
    ll q=0;
    forn(i,a.l)q+=a.n[i]*b,c.n[i]=q%BASE,q/=BASE;
    c.l=a.l;
    while(q)c.n[c.l++]=q%BASE,q/=BASE;
    c.invar();
    return c;
}
bint operator*(const bint&a, const bint&b){
    bint c;
    c.l=a.l+b.l;
    fill(c.n,c.n+b.l, 0);
    forn(i,a.l){
        ll q=0;
        forn(j,b.l)q+=a.n[i]*b.n[j]+c.n[i+j],c.n[i+j]=q%BASE,q/=BASE;
        c.n[i+b.l]=q;
    }
    c.invar();
    return c;
}
pair<bint,ll> ldiv(const bint& a,ll b){// c = a / b ; rm = a % b
	bint c;
	ll rm=0;
	rforn(i,a.l){
		rm =rm*BASE+a.n[i];
		c.n[i]=rm/b;
		rm%=b;
    }
    c.l=a.l;
    c.invar();
    return make_pair(c,rm);
}
bint operator/(const bint&a,ll b){return ldiv(a, b).first;}
ll operator%(const bint&a, ll b){return ldiv(a, b).second;}
pair<bint,bint> ldiv(const bint& a,const bint& b){
	bint c;
    bint rm=0;
    rforn(i,a.l){
        if(rm.l==1 && !rm.n[0])rm.n[0] = a.n[i];
        else{
            rforn(j,rm.l)rm.n[j+1]=rm.n[j];
            rm.n[0]=a.n[i];
            rm.l++;
        }
        ll q=rm.n[b.l]*BASE+rm.n[b.l-1];
        ll u=q/(b.n[b.l-1]+1);
        ll v=q/b.n[b.l-1]+1;
        while(u<v-1){
            ll m=(u+v)/2;
            if(b*m<=rm)u=m;
            else v=m;
        }
        c.n[i]=u;
        rm=rm-b*u;
    }
	c.l=a.l;
    c.invar();
    return make_pair(c,rm);
}
bint operator/(const bint&a, const bint&b){return ldiv(a, b).first;}
bint operator%(const bint&a, const bint&b){return ldiv(a, b).second;}
//~ -------------------------------------------------------------------------------
//~ -------------------------------------------------------------------------------
typedef struct bigint{
	int sg=1;
	bint num=0;
	void read(string s){
		if(s[0]=='-'){
			sg=-1;
			s.erase(s.begin());
		}else sg=1;
		num.read(s);
	}
	friend istream& operator>>(istream &stream, bigint &v){
		string s;
		stream >> s;
		v.read(s);
		return stream;
	}
	friend ostream& operator<<(ostream &stream, const bigint &v) {
		if(v.sg==-1)stream << '-';
		stream << v.num.n[v.num.l-1];
		rforn(i,v.num.l-1)stream << setprecision(6) << setw(BASEXP) << setfill('0') << v.num.n[i];
		return stream;
	}
}bigint;
bigint operator+(const bigint &a,const bigint &b){
	bigint r;
	if(a.sg*b.sg>0){
		r.sg=a.sg;
		r.num=a.num+b.num;
	}else{
		if(a.sg==-1){
			if(a.num<=b.num)r.num=b.num-a.num;
			else{
				r.sg=-1;r.num=a.num-b.num;
			}
		}else{
			if(b.num<=a.num)r.num=a.num-b.num;
			else{
				r.sg=-1;r.num=b.num-a.num;
			}
		}
	}
	return r;
}
bigint operator*(const bigint&a,const bigint&b){
	bigint r;
	r.sg=a.sg*b.sg;r.num=a.num*b.num;
	return r;
}
bigint operator-(const bigint&a,const bigint&b){
	bigint r=b;r.sg*=-1;
	return a+r;
}
bigint operator/(const bigint&a,const bigint&b){
	bigint r;
	r.sg=a.sg*b.sg;r.num=a.num/b.num;
	return r;
}
bigint operator%(const bigint&a, const bigint&b){
	bigint r;r.sg=a.sg;
	r.num=a.num%b.num;
	return r;
}
bool operator<(const bigint&a, const bigint&b){
	if(a.sg*b.sg<0)return(a.sg==-1);
	if(a.sg==-1)return b.num<a.num;
	return a.num<b.num;
}
bool operator==(const bigint&a, const bigint&b){return (a.sg==b.sg && a.num==b.num);}
bool operator<=(const bigint&a, const bigint&b){return (a<b || a==b);}
