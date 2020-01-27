ll
phi(ll n) // O();
{
    ll r = n;

    for (ll i = 2; i * i <= n; i++) if (n % i == 0) {
            while (n % i == 0) n /= i;
            r -= r / i;
        }
    if (1 < n) r -= r / n;
    return r;
}
