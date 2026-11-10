bool miller_rabin(ll n) {
    if(n < 2) return false;

    for(ll p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if(n % p == 0) return n == p;
    }

    ll d = n - 1;
    ll s = 0;

    while(d % 2 == 0) {
        d /= 2;
        s++;
    }

    for(ll a : {2LL, 325LL, 9375LL, 28178LL, 450775LL, 9780504LL, 1795265022LL}) {
        if(a % n == 0) continue;

        ll x = modpow(a, d, n);

        if(x == 1 || x == n - 1) continue;

        bool is_composite = true;

        for(int i = 1; i < s; i++) {
            x = (__int128)x * x % n;

            if(x == n - 1) {
                is_composite = false;
                break;
            }
        }

        if(is_composite) return false;
    }

    return true;
}
