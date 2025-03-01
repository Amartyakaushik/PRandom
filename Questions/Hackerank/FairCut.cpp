/*
Fair Cut
Problem
Submissions
Leaderboard
Li and Lu have n integers,a1,a2,..an , that they want to divide fairly between the two of them. They decide that if Li gets integers with indices I ={i1 , i2 , ... , ik}  (which implies that Lu gets integers with indices J = {1...n}/I), then the measure of unfairness of this division is:
f(I) = summation i tends to I summation j tends to J | ai - aj|

Find the minimum measure of unfairness that can be obtained with some division of the set of integers where
Li gets exactly k integers.
Note A \ B means Set complement
Input Format
The first line contains two space-separated integers denoting the respective values of n (the number of
integers Li and Lu have) and k (the number of integers Li wants).
The second line contains n space-separated integers describing the respective values of al ,a2, ... an

Constraints
• 1 < k < n < 3000
• 1 < ai < 109
• For 15% of the test cases, n < 20.
• For 45% of the test cases, n < 40.
Output Format
Print a single integer denoting the minimum measure of unfairness of some division where Li gets  integers.

Sample Input 0

4 2
4 3 1 2
Sample Output 0

 6
 Explanation O
One possible solution for this input is I {2, 4}; J {1, 3}.
|a2 — a1| + |a2-a3| + |a4 - a1| + |a4 - a3| =  1+2+2+1 = 6

Sample Input 1

4 1
3 3 3 1
Sample Output 1

2
Explanation 1
The following division of numbers is optimal for this input: I {1}; J {2, 3, 4}.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll Inf = 4000000000000000000;
const int Maxn = 3005;

int n, k;
int a[Maxn];
ll dp[Maxn][Maxn];

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    fill((ll*)dp, (ll*)dp + Maxn * Maxn, Inf);
    dp[0][0] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i && j <= k; j++) if (dp[i][j] < Inf) {
            int my = j, his = i - j;
            if (my < k) {
                ll add = ll(a[i]) * (his - (n - k - his));
                dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + add);
            }
            if (his < n - k) {
                ll add = ll(a[i]) * (my - (k - my));
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + add);
            }
        }
    printf("%lld\n", dp[n][k]);
    return 0;
}