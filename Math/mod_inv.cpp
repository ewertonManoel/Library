tuple<ll, ll, ll> extended_gcd(ll a, ll b) {
    if(b == 0) return {a, 1, 0};
    auto [g, x1, y1] = extended_gcd(b, a % b);
    ll x = y1, y = x1 - (a / b) * y1;
    return {g, x, y};
}

ll mod_inverse(ll a, ll mod) {
    auto [g, x, y] = extended_gcd(a, mod);
    if(g != 1) return -1;
    return (x % mod + mod) % mod;
}
