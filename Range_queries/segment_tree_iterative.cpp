struct SegTree {
    int n;
    vector<ll> st;

    SegTree(vector<ll>& a) {
        n = a.size();
        st.assign(2 * n, 0);

        for(int i = 0; i < n; i++) {
            st[n + i] = a[i];
        }

        for(int i = n - 1; i > 0; i--) {
            st[i] = st[i * 2] + st[i * 2 + 1];
        }
    }

    void update(int idx, ll val) {
        idx += n;
        st[idx] = val;

        while(idx > 1) {
            idx /= 2;
            st[idx] = st[idx * 2] + st[idx * 2 + 1];
        }
    }

    ll query(int l, int r) {
        ll ans = 0;

        l += n;
        r += n + 1;

        while(l < r) {
            if(l & 1) ans += st[l++];
            if(r & 1) ans += st[--r];

            l /= 2;
            r /= 2;
        }

        return ans;
    }
};
