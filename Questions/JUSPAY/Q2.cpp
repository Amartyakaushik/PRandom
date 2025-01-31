/*
Encrypted File Name Update

Next >

In a cloud storage system, files are assigned encrypted names consisting letters. When a file is updated, its encrypted name must also be of lowercase English e updated following strict rules

1. The new file name must be exactly k characters long.

2. The new file name can only include characters that are present in the original file name.

3. The new file name must be lexicographically larger than the original file name. This means it should come later than the original name if they were arranged in alphabetical order.

Given the original file name, find the smallest possible new file name of length k that satisfies these conditions. Return "-1" if no such name is possible.

Note:

A string p is lexicographically smaller than string q if p comes before q in the dictionary. For example, "abc" is smaller than "abcd", and "abd" is smaller than "abe".

Function description

Complete the solve function in the editor below. It has the following parameter(s):

Name

Type

INTEGER

INTEGER

STRING

Description

length of the original file name

k

length of the new file name

original file name

Return

Constraints

The function must return a STRING denoting the smallest possible new file name of length k that satisfies these conditions.

1≤ns 10*5

1k≤ 10^5

1≤len(s) 10^5

Input format for debugging

The first line contains an integer, n, denoting the length of the original file name.

• The next line contains an integer, k, denoting the length of the new file name.

The next line contains a string, s, denoting the original file name.

Sample Testcases

Input

Output

Output Description A

aca

abc

abcaa

abc

1

Immediately next lexicographically larger string is aca.

For such string of size 5, abcaa is smallest lexicographically larger string than s.

Since s="h" is lexicographically largest, no larger string exists.

#include <bits/stdc++.h>

using namespace std;

string trim(string);

string solve(int n, int k, string s) (

int main() {

jos::sync with_stdio(0);

cin.tie(0); cout.tie(0);

string inputline;

getline(cin, inputline); int n stoi(trim(inputline));

getline(cin, input line); int k stoi(trim(inputline));

getline(cin, inputline);

strings inputline;

string result solve(n, k, s);

cout << result << "\n";

return a;

Utility functions. Don't modify these 

// string trim(string str) (

// if (str.empty()) I

// return str;

// size t firstScan str.find_first_not_of('');

// size t first

// first.scan

// string::npos? str.length(): firstscan;

// size t last

// str.find last not of('');

// return str.substr(first, last-first+1);

// Solve in most efficient manner and accordingly that is asked
*/

// #include <bits/stdc++.h>
// using namespace std;

// string solve(int n, int k, string s) {
//     set<char> chars(s.begin(), s.end()); // Get unique characters in sorted order
//     vector<char> sortedChars(chars.begin(), chars.end()); // Sorted list of available characters
//     char minChar = sortedChars[0]; // Smallest character in s

//     // Case 1: If k > n, append the smallest character until length k
//     if (k > n) {
//         return s + string(k - n, minChar);
//     }

//     // Case 2: Modify prefix to find next lexicographical string
//     string prefix = s.substr(0, k);
//     for (int i = k - 1; i >= 0; i--) {
//         auto it = upper_bound(sortedChars.begin(), sortedChars.end(), prefix[i]);
//         if (it != sortedChars.end()) {
//             prefix[i] = *it;
//             for (int j = i + 1; j < k; j++) {
//                 prefix[j] = minChar;
//             }
//             return prefix;
//         }
//     }
    
//     return "-1"; // No valid lexicographical string found
// }

// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);

//     int n, k;
//     string s;
//     cin >> n >> k >> s;

//     cout << solve(n, k, s) << "\n";

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

string solve(int n, int k, string s) {
    set<char> chars(s.begin(), s.end()); // Get unique characters in sorted order
    vector<char> sortedChars(chars.begin(), chars.end()); // Sorted list of available characters
    char minChar = sortedChars[0]; // Smallest character in s

    // Case 1: If k > n, append the smallest character until length k
    if (k > n) {
        return s + string(k - n, minChar);
    }

    // Case 2: Modify prefix to find next lexicographical string
    string prefix = s.substr(0, k);
    for (int i = k - 1; i >= 0; i--) {
        auto it = upper_bound(sortedChars.begin(), sortedChars.end(), prefix[i]);
        if (it != sortedChars.end()) {
            prefix[i] = *it;
            for (int j = i + 1; j < k; j++) {
                prefix[j] = minChar;
            }
            return prefix;
        }
    }
    
    return "-1"; // No valid lexicographical string found
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, k;
    string s;
    cin >> n >> k >> s;

    cout << solve(n, k, s) << "\n";

    return 0;
}

/* input      output - aca
    3           
    3
    abc

    1           -1
    1
    h

    3
    2
    zzz            -1
    3
    5
    abc         abcaa
*/