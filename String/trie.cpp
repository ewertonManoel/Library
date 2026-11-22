struct Trie {
    vector<array<int, 26>> nxt;
    vector<int> pref, end_cnt;
    Trie() : nxt(1), pref(1, 0), end_cnt(1, 0) {}

    void insert(const string& s) {
        int u = 0;
        for (char c : s) {
            int idx = c - 'a';
            if (!nxt[u][idx]) {
                nxt[u][idx] = nxt.size();
                nxt.push_back({}); pref.push_back(0); end_cnt.push_back(0);
            }
            u = nxt[u][idx];
            pref[u]++;
        }
        end_cnt[u]++;
    }

    void erase(const string& s) {
        if (!count_word(s)) return;
        int u = 0;
        for (char c : s) {
            u = nxt[u][c - 'a'];
            pref[u]--;
        }
        end_cnt[u]--;
    }

    int count_word(const string& s) {
        int u = 0;
        for (char c : s) {
            int idx = c - 'a';
            if (!nxt[u][idx]) return 0;
            u = nxt[u][idx];
        }
        return end_cnt[u];
    }

    int count_pref(const string& s) {
        int u = 0;
        for (char c : s) {
            int idx = c - 'a';
            if (!nxt[u][idx]) return 0;
            u = nxt[u][idx];
        }
        return pref[u];
    }
};
