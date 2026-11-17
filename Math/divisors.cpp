vector<ll> get_divisors(ll n) {
    vector<ll> divisors, aux;

    for(ll i = 1; i * i <= n; i++) {
        if(n % i != 0) continue;

        divisors.push_back(i);

        if(i != n / i) {
            aux.push_back(n / i);
        }
    }

    for(int i = (int)aux.size() - 1; i >= 0; i--) {
        divisors.push_back(aux[i]);
    }

    return divisors;
}
