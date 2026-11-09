bool two_sum(vector<ll>& v, ll target) {
    int l = 0, r = (int)v.size() - 1;

    while(l < r) {
        ll sum = v[l] + v[r];

        if(sum == target) return true;
        if(sum < target) l++;
        else r--;
    }

    return false;
}