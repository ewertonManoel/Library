tuple<ll, ll, ll> extended_gcd(ll a, ll b) {
    if(b == 0) {
        return {a, 1, 0};
    }

    auto [g, x1, y1] = extended_gcd(b, a % b);

    ll x = y1;
    ll y = x1 - (a / b) * y1;

    return {g, x, y};
}
