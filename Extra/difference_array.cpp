#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> difference_array(int n, vector<tuple<int, int, ll>>& queries) {
    vector<ll> diff(n + 1, 0);

    for(auto [l, r, val] : queries) {
        diff[l] += val;
        diff[r + 1] -= val;
    }

    vector<ll> ans(n);
    ll sum = 0;

    for(int i = 0; i < n; i++) {
        sum += diff[i];
        ans[i] = sum;
    }

    return ans;
}