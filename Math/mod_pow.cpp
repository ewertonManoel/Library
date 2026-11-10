ll modpow(ll a, ll b, ll mod) {
    ll ans = 1;
    a %= mod;

    while(b > 0) {
        if(b & 1) ans = (__int128)ans * a % mod;
        a = (__int128)a * a % mod;
        b >>= 1;
    }

    return ans;
}
