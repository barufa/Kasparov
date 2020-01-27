ll
mcd(ll a, ll b) // Maximo Comun divisor;O(log N);
{
    if (b == 0) return a;

    return mcd(b, a % b);
}

// ~ --------------------------------------------------
ll
mcm(ll a, ll b) // Minimo comun multiplo;O(log N);
{
    return a * (b / mcm(a, b));
}

// ~ --------------------------------------------------
