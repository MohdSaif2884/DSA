 class Solution {
public:
    static const int MOD = 1e9 + 7;
    using ll = long long;
    using Matrix = vector<vector<ll>>;

    Matrix multiply(Matrix &A, Matrix &B) {
        int sz = A.size();
        Matrix C(sz, vector<ll>(sz));

        for (int i = 0; i < sz; i++) {
            for (int k = 0; k < sz; k++) {
                if (A[i][k] == 0) continue;
                for (int j = 0; j < sz; j++) {
                    if (B[k][j] == 0) continue;
                    C[i][j] =
                        (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    Matrix power(Matrix base, long long exp) {
        int sz = base.size();
        Matrix res(sz, vector<ll>(sz));

        for (int i = 0; i < sz; i++)
            res[i][i] = 1;

        while (exp) {
            if (exp & 1)
                res = multiply(res, base);

            base = multiply(base, base);
            exp >>= 1;
        }
        return res;
    }

    vector<ll> multiplyVec(vector<ll> &v, Matrix &A) {
        int sz = v.size();
        vector<ll> res(sz);

        for (int i = 0; i < sz; i++) {
            if (v[i] == 0) continue;
            for (int j = 0; j < sz; j++) {
                if (A[i][j] == 0) continue;
                res[j] =
                    (res[j] + v[i] * A[i][j]) % MOD;
            }
        }
        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        if (n == 1)
            return m;

        int S = 2 * m;

        vector<ll> state(S);

        // length = 2
        for (int i = 0; i < m; i++) {
            state[i] = i;               // up
            state[m + i] = m - 1 - i;  // down
        }

        if (n == 2) {
            ll ans = 0;
            for (ll x : state)
                ans = (ans + x) % MOD;
            return ans;
        }

        Matrix T(S, vector<ll>(S));

        // newUp[i] = sum down[j], j < i
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < i; j++) {
                T[m + j][i] = 1;
            }
        }

        // newDown[i] = sum up[j], j > i
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                T[j][m + i] = 1;
            }
        }

        Matrix P = power(T, n - 2);
        state = multiplyVec(state, P);

        ll ans = 0;
        for (ll x : state)
            ans = (ans + x) % MOD;

        return (int)ans;
    }
};