int N[MAXN][MAXN][MAXN];

void crear_matriz_sumas(int a,int b,int c){
	forn(x,a)forn(y,b)forn(z,c)
		if(x && y && z)
			N[x][y][z]+=N[x-1][y][z]+N[x][y-1][z]+N[x][y][z-1]-N[x-1][y-1][z]-N[x][y-1][z-1]-N[x-1][y][z-1]+N[x-1][y-1][z-1];
		else if(x && y)
			N[x][y][z]+=N[x-1][y][z]+N[x][y-1][z]-N[x-1][y-1][z];
		else if(x && z)
			N[x][y][z]+=N[x-1][y][z]+N[x][y][z-1]-N[x-1][y][z-1];
		else if(y && z)
			N[x][y][z]+=N[x][y-1][z]+N[x][y][z-1]-N[x][y-1][z-1];
		else if(x)
			N[x][y][z]+=N[x-1][y][z];
		else if(y)
			N[x][y][z]+=N[x][y-1][z];
		else if(z)
			N[x][y][z]+=N[x][y][z-1];
}

int sum_query(int x1,int y1,int z1,int x2,int y2,int z2){
	if(x1 && y1 && z1)
		return N[x2][y2][z2]-N[x1-1][y2][z2]-N[x2][y1-1][z2]+N[x1-1][y1-1][z2]-N[x2][y2][z1-1]+N[x1-1][y2][z1-1]+N[x2][y1-1][z1-1]-N[x1-1][y1-1][z1-1];
	else if(x1 && y1)
		return N[x2][y2][z2]-N[x1-1][y2][z2]-N[x2][y1-1][z2]+N[x1-1][y1-1][z2];
	else if(x1 && z1)
		return N[x2][y2][z2]-N[x1-1][y2][z2]-N[x2][y2][z1-1]+N[x1-1][y2][z1-1];
	else if(y1 && z1)
		return N[x2][y2][z2]-N[x2][y1-1][z2]-N[x2][y2][z1-1]+N[x2][y1-1][z1-1];
	else if(x1)
		return N[x2][y2][z2]-N[x1-1][y2][z2];
	else if(y1)
		return N[x2][y2][z2]-N[x2][y1-1][z2];
	else if(z1)
		return N[x2][y2][z2]-N[x2][y2][z1-1];
	else
		return N[x2][y2][z2];
}

int main(void){
	set_cin;input("A.in");
	int a,b,c,s,r,T;cin >> T;
	cin >> a >> b >> c;r=INT_MIN;
	forn(x,a)forn(y,b)forn(z,c)cin >> N[x][y][z];//Leo la matriz
	crear_matriz_sumas();
	sum_query(1,1,1,2,2,2);//Suma desde el (1,1,1) al (2,2,2)
	return 0;
}
