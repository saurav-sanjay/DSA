//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
  long long int count(int coins[], int N, int sum)
  {

    // code here.
    vector<vector<long long int>> dp(N, vector<long long int>(sum + 1, 0));
    for (int i = 0; i <= sum; i++)
    {
      dp[0][i] = (i % coins[0] == 0);
    }

    for (int i = 1; i < N; i++)
    {
      for (int j = 0; j <= sum; j++)
      {
        long long int notPick = dp[i - 1][j];
        long long int pick = 0;
        if (j >= coins[i])
        {
          pick = dp[i][j - coins[i]];
        }
        dp[i][j] = notPick + pick;
      }
    }

    return dp[N - 1][sum];
  }
};

//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int sum, N;
    cin >> sum >> N;
    int coins[N];
    for (int i = 0; i < N; i++)
      cin >> coins[i];
    Solution ob;
    cout << ob.count(coins, N, sum) << endl;
  }

  return 0;
}

// } Driver Code Ends