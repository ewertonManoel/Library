bool check(ll mid) {
    return true;
}

ll binary_search_answer(ll l, ll r) {
    while(l <= r) {
        ll mid = l + (r - l) / 2;

        if(check(mid)) r = mid - 1;
        else l = mid + 1;
    }

    return l;
}