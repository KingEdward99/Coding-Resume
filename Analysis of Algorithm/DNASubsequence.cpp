#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std; 
// Function to generate a random DNA string of given length
string generateRandomDNAString(int length) {
    string dnaString = "";
    static const char dnaLetters[] = {'A', 'C', 'G', 'T'};
    int numLetters = sizeof(dnaLetters) / sizeof(dnaLetters[0]);

    for (int i = 0; i < length; i++) {
        int randomIndex = rand() % numLetters;
        dnaString += dnaLetters[randomIndex];
    }

    return dnaString;
}

// Function to find the longest common subsequence between two DNA strings
string findLongestCommonSubsequence(const string& str1, const string& str2) {
    int m = str1.length();
    int n = str2.length();

    vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    string lcs = "";
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            lcs = str1[i - 1] + lcs;
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    return lcs;
}

int main() {
    // Generate two random DNA strings
    srand(time(0));
    string dnaString1 = generateRandomDNAString(100);
    string dnaString2 = generateRandomDNAString(120);

    // Find the longest common subsequence
    string lcs = findLongestCommonSubsequence(dnaString1, dnaString2);

    // Print the results
    cout << "DNA String 1: " << dnaString1 << std::endl;
    cout << "DNA String 2: " << dnaString2 << std::endl;
    cout << "Longest Common Subsequence: " << lcs << std::endl;

    return 0;
}