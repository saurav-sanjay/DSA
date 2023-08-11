//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Recursive approach to find the number of ways to make coin change
class Solution
{
public:
  long long int solve(int index, int coins[], int target)
  {
    if (index == 0)
    {
      return ((target % coins[index]) == 0);
    }
    long long int notPick = solve(index - 1, coins, target);
    long long int pick = 0;
    if (target >= coins[index])
    {
      pick = solve(index, coins, (target - coins[index]));
    }
    return (notPick + pick);
  }
  long long int count(int coins[], int N, int sum)
  {

    // code here.
    return solve(N - 1, coins, sum);
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