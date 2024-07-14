int knapsack(int N, int W, vector<int>& weights, vector<int>& values, vector<int>& dependencies, vector<int>& categories, vector<int>& limits) {
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
    unordered_map<int, int> category_taken;
    
    for (int i = 0; i < N; ++i) {
        for (int k = 1; k <= limits[i]; ++k) {
            for (int w = W; w >= weights[i]; --w) {
                int dep = dependencies[i];
                if (dep != -1 && dp[i][w - weights[i]] == 0) {
                    continue;
                }
                
                if (category_taken[categories[i]] != i && category_taken[categories[i]] != 0) {
                    continue;
                }
                
                dp[i + 1][w] = max(dp[i + 1][w], dp[i][w - weights[i]] + values[i]);
                category_taken[categories[i]] = i;
            }
        }
    }
    
    int max_value = 0;
    for (int w = 0; w <= W; ++w) {
        max_value = max(max_value, dp[N][w]);
    }
    
    return max_value;
}