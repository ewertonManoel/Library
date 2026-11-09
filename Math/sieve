vector<int> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    vector<int> primes;

    is_prime[0] = false;
    if(n >= 1) is_prime[1] = false;

    for(int i = 2; i * i <= n; i++) {
        if(!is_prime[i]) continue;

        for(int j = i * i; j <= n; j += i) {
            is_prime[j] = false;
        }
    }

    for(int i = 2; i <= n; i++) {
        if(is_prime[i]) primes.push_back(i);
    }

    return primes;
}