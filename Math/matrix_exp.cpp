using Matrix = vector<vector<ll>>;

Matrix matmul(Matrix a, Matrix b, ll mod) {
    int n = a.size();
    int m = a[0].size();
    int p = b[0].size();

    Matrix ans(n, vector<ll>(p, 0));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < p; j++) {
            for(int k = 0; k < m; k++) {
                ans[i][j] = (
                    (__int128)ans[i][j] +
                    (__int128)a[i][k] * b[k][j]
                ) % mod;
            }
        }
    }

    return ans;
}

Matrix matpow(Matrix a, ll b, ll mod) {
    int n = a.size();

    Matrix ans(n, vector<ll>(n, 0));

    for(int i = 0; i < n; i++)
        ans[i][i] = 1 % mod;

    while(b > 0) {
        if(b & 1) ans = matmul(ans, a, mod);

        a = matmul(a, a, mod);
        b >>= 1;
    }

    return ans;
}
