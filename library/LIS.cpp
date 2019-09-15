for (int i = 1; i <= n; ++i) g[i] = INF;
for (int i = 0; i < n; ++i) {
  int k = lower_bound(g + 1, g + n + 1, A[i]) - g;
  d[i] = k;
  g[k] = A[i];
}