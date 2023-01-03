#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int superEggDrop(int K, int N)
    {
        vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
        int m = 0;
        while (dp[m][K] < N) {
            m++;
            for (int k = 1; k <= K; ++k)
                dp[m][k] = dp[m - 1][k - 1] + dp[m - 1][k] + 1;
        }
        return m;
    }
};

int main(int argc, char const* argv[])
{
    Solution s;
    //std::cout << "Ans : " << s.superEggDrop(2, 9) << "\n";
    std::cout << "Ans : " << s.superEggDrop(2, 6) << "\n";
    //std::cout << "Ans : " << s.superEggDrop(3, 14) << "\n";
}
