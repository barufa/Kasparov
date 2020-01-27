// SegTree T; recordar modificar el typedef tipo
// T.create(arreglo,len,neutro,oper); donde oper es una operacion binaria(funcion) con neutro
// T.query(desde,hasta); Devuelve la respuesta de la query(busca en el rango [desde,hasta])
// T.update(idx,valor); Modifica el valor y actualiza la estructura
// T.clear();
typedef int tipo;
typedef struct SegTree {
    int          sz;
    tipo         e;
    tipo (* oper)(tipo, tipo);
    vector<tipo> T;
    tipo
    crt(tipo a[], int l, int r, int pos) // Funcion Interna
    {
        if (l == r) T[pos] = a[r];
        else T[pos] =
              oper(crt(a, l, (l + r) / 2, 2 * pos + 1), crt(a, (l + r) / 2 + 1, r, 2 * pos + 2));
        return T[pos];
    }

    void
    create(tipo a[], int size, tipo neutro, tipo (*fnc)(tipo, tipo)) // O(N);
    {
        oper = fnc;
        e    = neutro;
        sz   = size;
        T.assign(sz * 2, e);
        crt(a, 0, sz - 1, 0);
    }

    tipo
    query(int l, int r, int ql, int qr, int pos) // O(logN);
    {
        if (l <= ql && r >= qr) return T[pos];

        if (l > qr || r < ql) return e;

        return oper(query(l, r, ql, (ql + qr) / 2, 2 * pos + 1),
                 query(l, r, (ql + qr) / 2 + 1, qr, 2 * pos + 2));
    }

    void
    upd(int idx, tipo val, int l, int r, int pos) // O(log N);
    {
        if (l == r && r == idx) { T[pos] = val; } else {
            if (idx <= (l + r) / 2) upd(idx, val, l, (l + r) / 2, 2 * pos + 1);
            else upd(idx, val, (l + r) / 2 + 1, r, 2 * pos + 2);
            T[pos] = oper(T[2 * pos + 1], T[2 * pos + 2]);
        }
    }

    tipo
    query(int l, int r){ return query(l, r, 0, sz - 1, 0); }

    void
    update(int idx, tipo val){ upd(idx, val, 0, sz - 1, 0); }

    void
    clear(){ T.clear(); sz = 0; }// O(1);
} SegTree;
