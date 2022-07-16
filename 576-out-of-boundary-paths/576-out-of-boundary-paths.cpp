class Solution {
public:
    
    int findPaths(int m, int n, int N, int i, int j) {
    unsigned int g[50][50] = {}, r[50];
    while (N-- > 0)
        for (auto k = 0; k <= m; ++k)
            for (auto l = 0; l < n; ++l) {
                auto tmp = r[l];
                r[l] = (k == m ? 0 : ((k == 0 ? 1 : g[k - 1][l]) + (k == m - 1 ? 1 : g[k + 1][l])
                    + (l == 0 ? 1 : g[k][l - 1]) + (l == n - 1 ? 1 : g[k][l + 1])) % 1000000007);
                if (k > 0) g[k - 1][l] = tmp;
            }
    return g[i][j];
}
};