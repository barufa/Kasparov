// IMPORTANTE: func es una funcion que toma un arreglo de indices(unsigned int) y la longitud (k);
// El arreglo de indices varia en todas las combinaciones(o permutaciones) posibles, y en cada llamada
// a func se le pasara como argumento estos indices.
// ---------------------------------------------------------------------------------------------------
// combinations:Genera los numero combinatorios y los almacena en una matriz;
ull C[MAXN][MAXN];
void
combinations(int maximo)
{
    forn(i, maximo) C[i][0] = C[i][i] = 1;
    forn(i, maximo) forr(j, 1, i) C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
}

// ---------------------------------------------------------------------------------------------------
// Combinaciones: Aplica func a todas las combinaciones posibles de un conjunto de sz elementos tomados de a k;
// Retorna la cantidad de combinaciones;
// Crea las combinaciones en orden lexicografico;
unsigned int A[MAXN];
bool
next_combination(unsigned int n, unsigned int k) // Genera todas las permutaciones una por una(Necesaria en ambas funciones);
{
    rforn(i, k) if (A[i] < n - k + i + 1) {
        A[i]++;
        forr(j, i + 1, k) A[j] = A[j - 1] + 1;
        return true;
    }
    return false;
}

ull
combinaciones(unsigned int sz, unsigned int k, void (*func)(unsigned int *, unsigned int)) // O((szCk)*O(func))
{
    ull cnt = 0;

    forn(i, sz) A[i] = i;

    if (sz == k) {
        cnt++;
        func(A, k);
    } else {
        do {
            cnt++;
            func(A, k);
        } while (next_combination(sz - 1, k));
    }
    return cnt;
}

// ---------------------------------------------------------------------------------------------------
// Permutaciones:Aplica func a todas las combinaciones posibles de un conjunto de sz elementos tomados de a k;
// Retorna la cantidad de permutaciones;
// Crea las permutaciones en orden lexicografico;
bool is[MAXN];
ull A[MAXN];
void
in_permutaciones(unsigned int sz, unsigned int k, void (*func)(ull *, ull), ull &c, ull idx = 0) // O((n-k)!)*O(func))
{
    if (idx == k) {
        c++;
        func(A, k);
    } else {
        forn(i, sz) if (!is[i]) {
            is[i]  = true;
            A[idx] = i;
            in_permutaciones(sz, k, func, c, idx + 1);
            is[i]  = false;
            A[idx] = 0;
        }
    }
}

ull
permutaciones(unsigned int sz, unsigned int k, void (*func)(ull *, ull))
{
    ull cnt = 0;

    in_permutaciones(sz, k, func, cnt, 0);

    return cnt;
}

// ---------------------------------------------------------------------------------------------------
