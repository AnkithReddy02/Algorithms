class KarpRabin {
    const int md = 1e9 + 7;
    int p, n;
    vector<int> powers;
    vector<int> suffix;

    public:
    KarpRabin(int p, const string& s) : p(p) {
        n = size(s);

        powers.resize(n + 1);
        powers[0] = 1;
        for (int i = 1; i <= n; i++) {
            powers[i] = (p * (long long)powers[i - 1]) % md;
        }

        suffix.resize(n + 1);
        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = (powers[i] * (long long)(s[i] + 1)) % md;
            suffix[i] = (suffix[i] + suffix[i + 1]) % md;
        }
    }

    int Hash(int l, int r) {
        int h = (suffix[l] - suffix[r + 1]) % md;
        h = (h * (long long)powers[n - l]) % md;
        if (h < 0) h += md;
        return h;
    }
};