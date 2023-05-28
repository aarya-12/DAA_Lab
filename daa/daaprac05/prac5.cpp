#include <bits/stdc++.h>
using namespace std;
int min(int x, int y, int z)
{
return min(min(x, y), z);
}
int editDistance(string str1, string str2, int m, int n)
{
int dp[m + 1][n + 1];
for (int i = 0; i <= m; i++)
{
for (int j = 0; j <= n; j++)
{
if (i == 0)
dp[i][j] = j; 
else if (j == 0)
dp[i][j] = i; 
else if (str1[i - 1] == str2[j - 1])
dp[i][j] = dp[i - 1][j - 1];
else
dp[i][j] = 1 + min(dp[i][j - 1], 
dp[i - 1][j], 
dp[i - 1][j - 1]); 

}
}
return dp[m][n];
}

int main()
{
char dictionary[10][10] = {'Hello', 'How', 'are', 'you', 'I', 'am', 'good','well','improve', 'cat'};

cout << "\nThe words in the dictionary are: \n";
for (int i = 0; i < 10; i++)
{
cout << dictionary[i] << "\n";
}
cout << "\n";


string str1;
cout << "\nEnter the word: \n";
cin >> str1;
string str2;

int arr[10];
for (int i = 0; i < 10; i++)
{
if (str1 == dictionary[i])
{
cout << "No change needed.\n";
exit(0);
}
else
{
str2 = dictionary[i];
arr[i] = editDistDP(str1, dictionary[i], str1.length(),str2.length());
}
}

int min = 99;
cout << "\nDid you mean:\n\n";
for (int j = 0; j < 5; j++)
{
int var;
for (int i = 0; i < 10; i++)
{
if (arr[i] <= min)
{
min = arr[i];
var = i;
}
}
min = 99;
arr[var] = 9999;
cout << dictionary[var] << "\n";
}
return 0;
}