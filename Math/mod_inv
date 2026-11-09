ll mod_inverse(ll a, ll mod) {
    ll x, y;
    ll g = extended_gcd(a, mod, x, y);

    if(g != 1) return -1;

    return (x % mod + mod) % mod;
}