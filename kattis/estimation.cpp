#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main()
{
    int n, K;
    cin >> n >> K;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<vector<int>> cost(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        priority_queue<int> lower;
        priority_queue<int, vector<int>, greater<int>> upper;
        int lower_sum = 0;
        int upper_sum = 0;
        for (int j = i; j < n; j++)
        {
            if (!lower.empty() && a[j] > lower.top())
            {
                upper.push(a[j]);
                upper_sum += a[j];
            }
            else
            {
                lower.push(a[j]);
                lower_sum += a[j];
            }

            if (upper.size() > lower.size())
            {
                lower.push(upper.top());
                lower_sum += upper.top();
                upper_sum -= upper.top();
                upper.pop();
            }
            else if (lower.size() > upper.size() + 1)
            {
                upper.push(lower.top());
                upper_sum += lower.top();
                lower_sum -= lower.top();
                lower.pop();
            }
            cost[i][j] = (lower.top() * lower.size() - lower_sum) + (upper_sum - lower.top() * upper.size());
        }
    }

    vector<int> dp(n);
    for (int i = 0; i < n; i++)
    {
        dp[i] = cost[0][i];
    }
    
    for (int j = 1; j < K; j++)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            for (int x = 0; x < i; x++)
            {
                dp[i] = min(dp[i], dp[x] + cost[x + 1][i]);
            }
        }
    }
    cout << dp[n - 1];
}