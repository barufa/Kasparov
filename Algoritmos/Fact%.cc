ll
factmod(ll n, ll p) // (n!)%p
{
    ll res = 1;

    while (n > 1) {
        res = (res * ((n / p) % 2 ? p - 1 : 1)) % p;
        forr(i, 2, (n % p) + 1) res = (res * i) % p;
        n /= p;
    }
    return res % p;
}
