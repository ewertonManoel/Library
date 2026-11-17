pair<vector<ll>, vector<ll>> precompute_factorials(ll n, ll mod) {
    vector<ll> fact(n + 1), inv_fact(n + 1);

    fact[0] = 1;

    for(ll i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }

    inv_fact[n] = mod_inverse(fact[n], mod);

    for(ll i = n; i >= 1; i--) {
        inv_fact[i - 1] = (inv_fact[i] * i) % mod;
    }

    return {fact, inv_fact};
}
