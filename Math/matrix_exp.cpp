
using Matrix = vector<vector<ll>>;

Matrix matmul(const Matrix& a, const Matrix& b, ll mod) {
    assert(a[0].size() == b.size());

    int n = a.size(), m = a[0].size(), p = b[0].size();
    Matrix ans(n, vector<ll>(p, 0));

    for(int i = 0; i < n; i++) {
        for(int k = 0; k < m; k++) {
            if(a[i][k] == 0) continue;

            for(int j = 0; j < p; j++) {
                ans[i][j] = ((__int128)ans[i][j] + (__int128)a[i][k] * b[k][j]) % mod;
            }
        }
    }

    return ans;
}

Matrix matpow(Matrix a, Matrix ans, ll b, ll mod) {
    assert(a.size() == a[0].size());
    assert(a[0].size() == ans.size());

    while(b > 0) {
        if(b & 1) ans = matmul(a, ans, mod);

        b >>= 1;
        if(b) a = matmul(a, a, mod);
    }

    return ans;
}
