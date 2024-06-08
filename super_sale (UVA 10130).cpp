#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int knapsack( vector<pair<int, int>>& items, int maxWeight) {
    vector<int> dp(maxWeight + 1, 0);
    for (const auto& item : items) {
        int value = item.first;
        int weight = item.second;
        for (int w = maxWeight; w >= weight; --w) {

            dp[w] = max(dp[w], dp[w - weight] + value);
            cout << "w=" << w << " " << dp[w] << "  " << dp[w - weight] + value << "   " << weight << endl;
        }
        cout << endl;

    }
    return dp[maxWeight];
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<pair<int, int>> items(N);
        for (int i = 0; i < N; ++i) {
            cin >> items[i].first >> items[i].second;
        }

        int G;
        cin >> G;
        int totalMaxValue = 0;
        for (int i = 0; i < G; ++i) {
            int maxWeight;
            cin >> maxWeight;
            totalMaxValue += knapsack(items, maxWeight);
        }

    }
    return 0;
}
