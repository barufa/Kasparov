ll N[MAXN][MAXN];// Matriz a elevar
ll R[MAXN][MAXN];// Matriz auxiliar
void
potMmod(ll exp, ll sz, ll mod) // O(log(exp)*(sz^2))
{
    if (exp == 0) {
        forn(i, sz) forn(j, sz) N[i][j] = ((i == j) ? 1 : 0);
        return;
    } else if (exp == 1) {
        forn(i, sz) forn(j, sz) N[i][j] %= mod;
        return;
    } else {
        ll A[MAXN][MAXN];// Matriz auxiliar, temporal
        forn(i, sz) forn(j, sz) A[i][j] = N[i][j];
        if (exp == 2) {
            forn(i, sz) forn(j, sz){
                int aux = 0;

                forn(r, sz) aux = (aux + A[i][r] * N[r][j]) % mod;
                R[i][j]         = aux;
            }
            forn(i, sz) forn(j, sz) N[i][j] = R[i][j] % mod;
        } else {
            potMmod(2, sz, mod);
            potMmod(exp / 2, sz, mod);
            if (exp % 2) {
                forn(i, sz) forn(j, sz){
                    int aux = 0;

                    forn(r, sz) aux = (aux + N[i][r] * A[r][j]) % mod;
                    R[i][j]         = aux;
                }
                forn(i, sz) forn(j, sz) N[i][j] = R[i][j] % mod;
            }
        }
    }
} // potMmod
