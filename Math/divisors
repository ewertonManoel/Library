vector<ll> get_divisors(ll n) {
    vector<ll> divisors;

    for(ll i = 1; i * i <= n; i++) {
        if(n % i != 0) continue;

        divisors.push_back(i);

        if(i != n / i) {
            divisors.push_back(n / i);
        }
    }

    sort(divisors.begin(), divisors.end());

    return divisors;
}