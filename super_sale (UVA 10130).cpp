
There is a SuperSale in a SuperHiperMarket. Every person can take only one object of each kind, i.e.
one TV, one carrot, but for extra low price. We are going with a whole family to that SuperHiperMarket.
Every person can take as many objects, as he / she can carry out from the SuperSale. We have given
list of objects with prices and their weight. We also know, what is the maximum weight that every
person can stand. What is the maximal value of objects we can buy at SuperSale ?
Input
The input consists of T test cases. The number of them (1 ≤ T ≤ 1000) is given on the first line of
the input file. Each test case begins with a line containing a single integer number N that indicates
        the number of objects (1 ≤ N ≤ 1000). Then follows N lines, each containing two integers: P and W.
        The first integer (1 ≤ P ≤ 100) corresponds to the price of object. The second integer (1 ≤ W ≤ 30)
        corresponds to the weight of object. Next line contains one integer (1 ≤ G ≤ 100) its the number of
        people in our group. Next G lines contains maximal weight (1 ≤ MW ≤ 30) that can stand this i - th
        person from our family (1 ≤ i ≤ G).
        Output
    For every test case your program has to determine one integer. Print out the maximal value of goods
            which we can buy with that family.
            Sample Input
            2
            3
            72 17
            44 23
            31 24
            1
            26
            6
            64 26
            85 22
            52 4
            99 18
            39 13
            54 9
            4
            23
            20
            20
            26
            Sample Output
            72
            514

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
