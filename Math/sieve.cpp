vector<int> primes, spf;

void sieve(int n) {
    primes.clear();
    spf.resize(n + 1);

    for(int i = 0; i <= n; i++) {
        spf[i] = i;
    }

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
