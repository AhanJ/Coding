#include <iostream>
#include <vector>
#include <string>

using namespace std;

int max(int a, int b)

{
    return (a > b) ? a : b;
}

string longestCommonSubsequence(string str1, string str2)

{
    int m = str1.length();
    int n = str2.length();

    // Create a 2D vector to store the LCS lengths.
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Build the dp array to store LCS lengths.
    for (int i = 1; i <= m; i++)

    {
        for (int j = 1; j <= n; j++)

        {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int index = dp[m][n];
    string lcs(index, ' ');

    int i = m, j = n;
    while (i > 0 && j > 0)

    {
        if (str1[i - 1] == str2[j - 1])

        {
            lcs[index - 1] = str1[i - 1];
            i--;
            j--;
            index--;
        }

        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }

    return lcs;
}

int main()

{
    string str1, str2;

    cout << "Enter the First String: ";
    cin >> str1;

    cout << "Enter the Second String: ";
    cin >> str2;

    string lcs = longestCommonSubsequence(str1, str2);

    if (lcs == "")

    {
        cout << "No Longest Common Subsequence Exists";
    }

    else

    {
        cout << "Longest Common Subsequence: " << lcs << endl;
    }

    return 0;
}
