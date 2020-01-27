// SegTree T; recordar modificar el typedef tipo
// T.create(arreglo,len,neutro,oper); donde oper es una operacion binaria(funcion) con neutro
// T.query(desde,hasta); Devuelve la respuesta de la query(busca en el rango [desde,hasta])
// T.update(l,r,v); Incrementa el rango [l,r] en v
// T.clear(); Limpia la estructura
// T[i] muestra el elemento en la i-esima posicion del arreglo sobre el cual se aplica el segtree
typedef ll tipo;
typedef ll Alt;
typedef struct SegTreeLazy {
    int          sz;
    tipo (* oper)(tipo, tipo);
    tipo         neutro;
    vector<tipo> T;
    vector<Alt>  A;// las alteraciones pueden ser de distinto tipo
    tipo &
    operator [] (int idx){ return T[sz + idx + 1]; }

    tipo
    crt(tipo a[], int l, int r, int pos) // Funcion Interna
    {
        if (l == r) T[pos] = a[r];
        else T[pos] =
              oper(crt(a, l, (l + r) / 2, 2 * pos), crt(a, (l + r) / 2 + 1, r, 2 * pos + 1));
        return T[pos];
    }

    void
    create(tipo arr[], int n, tipo ntr, tipo (*fnc)(tipo, tipo)) // O(nlgn)
    {
        sz   = 1 << (32 - __builtin_clz(n));
        oper = fnc;
        T.assign(2 * sz, neutro);
        A.assign(2 * sz, neutro);
        crt(arr, 0, n - 1, 1);
    }

    void
    push(int pos, int l, int r)
    {
        if (A[pos] != 0) {
            T[pos] += A[pos] * (r - l);
            if (pos < sz) {
                A[2 * pos]     += A[pos];
                A[2 * pos + 1] += A[pos];
            }
            A[pos] = 0;
        }
    }

    tipo
    query(int ql, int qr, int pos, int l, int r) // O(lgn)
    {
        if (qr <= l || ql >= r) return neutro;

        push(pos, l, r);
        if (ql <= l && r <= qr) return T[pos];

        return oper(query(ql, qr, 2 * pos, l, (l + r) / 2),
                 query(ql, qr, 2 * pos + 1, (l + r) / 2, r));
    }

    tipo
    query(int l, int r){ return query(l, r + 1, 1, 0, sz - 1); }

    void
    update(Alt val, int i, int j, int n, int a, int b) // O(lgn)
    {
        push(n, a, b);
        if (j <= a || i >= b) return;

        if (i <= a && b <= j) {
            A[n] += val;
            push(n, a, b);
            return;
        }
        int c = (a + b) / 2;
        update(val, i, j, 2 * n, a, c), update(val, i, j, 2 * n + 1, c, b);
        T[n] = oper(T[2 * n], T[2 * n + 1]);
    }

    void
    update(int l, int r, Alt val){ update(val, l, r + 1, 1, 0, sz - 1); }

    void
    clear(){ T.clear(); A.clear(); }
} SegTreeLazy;
