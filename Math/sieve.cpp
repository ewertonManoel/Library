vector<int> primes, spf;

void sieve(int n) {
    primes.clear();
    spf.resize(n + 1);
    iota(spf.begin(), spf.end(), 0);

    for(int i = 2; i * i <= n; i++) {
        if(spf[i] != i) continue;
        for(int j = i * i; j <= n; j += i) {
            if(spf[j] == j) {
                spf[j] = i;
            }
        }
    }

    for(int i = 2; i <= n; i++) {
        if(spf[i] == i) {
            primes.push_back(i);
        }
    }
}

bool is_prime(int x) {
    return x >= 2 && spf[x] == x;
}

vector<pair<int, int>> factorize_spf(int x) {
    vector<pair<int, int>> factors;
    while(x > 1) {
        int p = spf[x], cnt = 0;
        while(x % p == 0) {
            x /= p;
            cnt++;
        }
        factors.push_back({p, cnt});
    }
    return factors;
}
