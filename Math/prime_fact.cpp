vector<pair<ll, int>> prime_factorization(ll n) {
    vector<pair<ll, int>> factors;

    for(ll i = 2; i * i <= n; i++) {
        if(n % i != 0) continue;

        int cnt = 0;

        while(n % i == 0) {
            n /= i;
            cnt++;
        }

        factors.push_back({i, cnt});
    }

    if(n > 1) factors.push_back({n, 1});

    return factors;
}