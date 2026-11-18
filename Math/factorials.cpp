vector<ll> fact, inv_fact;

void precompute_factorials(ll n, ll mod) {
    fact.resize(n + 1);
    inv_fact.resize(n + 1);
    fact[0] = 1;

    for(ll i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }

    inv_fact[n] = mod_inverse(fact[n], mod);
    for(ll i = n; i >= 1; i--) {
        inv_fact[i - 1] = (inv_fact[i] * i) % mod;
    }
}
