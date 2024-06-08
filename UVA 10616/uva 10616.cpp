#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, Q, D, M;
vector<int> numbers;
int dp[201][11][21];
// Function to count the number of groups that have sum divisible by D
int countGroups(int index, int count, int sum) {
    if (count == M) {
        return (sum % D == 0) ? 1 : 0;
    }
    if (index == N) {
        return 0;
    }
    if (dp[index][count][sum % D] != -1) {
        return dp[index][count][sum % D];
    }

    int include = countGroups(index + 1, count + 1, sum + numbers[index]);
    int exclude = countGroups(index + 1, count, sum);

    return dp[index][count][sum % D] = include + exclude;
}

int main() {
    int setNumber = 1;

    while (cin >> N >> Q) {
        if (N == 0 && Q == 0) break;

        numbers.clear();
        numbers.resize(N);

        for (int i = 0; i < N; ++i) {
            cin >> numbers[i];
        }

        cout << "SET " << setNumber++ << ":\n";

        for (int q = 1; q <= Q; ++q) {
            cin >> D >> M;

            memset(dp, -1, sizeof(dp));

            int result = countGroups(0, 0, 0);

            cout << "QUERY " << q << ": " << result << "\n";
        }
    }

    return 0;
}

