mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll M1 = 1e9 + 7, M2 = 1e9 + 9;
const ll B = uniform_int_distribution<ll>(256, M1 - 1)(rng);

struct StringHash {
    vector<ll> h1, h2, p1, p2;

    StringHash(const string& s = "") {
        int n = s.size();
        h1.assign(n + 1, 0); h2.assign(n + 1, 0);
        p1.assign(n + 1, 1); p2.assign(n + 1, 1);
        for(int i = 0; i < n; i++) {
            p1[i + 1] = p1[i] * B % M1;
            p2[i + 1] = p2[i] * B % M2;
            h1[i + 1] = (h1[i] * B + s[i]) % M1;
            h2[i + 1] = (h2[i] * B + s[i]) % M2;
        }
    }

    ll query(int l, int r) {
        ll x1 = (h1[r + 1] - h1[l] * p1[r - l + 1] % M1 + M1) % M1;
        ll x2 = (h2[r + 1] - h2[l] * p2[r - l + 1] % M2 + M2) % M2;
        return (x1 << 32) | x2;
    }
};
