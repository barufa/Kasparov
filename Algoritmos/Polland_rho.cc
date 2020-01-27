ll
gcd(ll a, ll b){ return a ? gcd(b % a, a) : b; }

ll
mulmod(ll a, ll b, ll c)
{
    ll x = 0, y = a % c;

    while (0 < b) {
        if (b % 2) x = (x + y) % c;
        y  = (y * 2) % c;
        b /= 2;
    }
    return x % c;
}

ll
expmod(ll b, ll e, ll m) // O(log e)
{
    if (!e) return 1;

    ll q = expmod(b, e / 2, m);
    q = mulmod(q, q, m);
    return (e % 2) ? mulmod(b, q, m) : q;
}

bool
es_primo_prob(ll n, int a)
{
    if (n == a) return true;

    ll s = 0, d = n - 1;
    while (!d % 2) s++, d /= 2;
    ll x = expmod(a, d, n);
    if ((x == 1) || (x + 1 == n)) return true;

    forn(i, s - 1){
        x = mulmod(x, x, n);
        if (x == 1) return false;

        if (x + 1 == n) return true;
    }
    return false;
}

bool
isprime(ll n) // devuelve true si n es primo
{
    if (n == 1) return false;

    const int ar[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23 };
    forn(j, 9) if (!es_primo_prob(n, ar[j])) return false;

    return true;
}

ll
rho(ll n) // Devuelve un divisor de n
{
    if ((n & 1) == 0) return 2;

    ll x = 2, y = 2, d = 1, c = rand() % n + 1;
    while (d == 1) {
        x = (mulmod(x, x, n) + c) % n;
        y = (mulmod(y, y, n) + c) % n;
        y = (mulmod(y, y, n) + c) % n;
        if (x - y >= 0) d = gcd(x - y, n);
        else d = gcd(y - x, n);
    }
    return (d == n) ? rho(n) : d;
}

ll
polland(ll n) // O(sqrt(N))<-Usar esta
{
    if (isprime(n)) return n;

    ll r;
    while (!isprime((r = rho(n))));
    return r;
}
