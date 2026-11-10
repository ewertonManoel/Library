ll mod_inverse(ll a, ll mod) {
    auto [g, x, y] = extended_gcd(a, mod);

    if(g != 1) return -1;
    return (x % mod + mod) % mod;
}
