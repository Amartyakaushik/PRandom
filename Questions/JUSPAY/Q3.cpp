/*
3. Network Technician's Mission

Submit te

In the city of Techville, a network technician named Sam is tasked with inspecting a newly established network of communication towers. The network is structured as a rooted tree with n towers, with the main control tower located at node 1. This control tower serves as the central hub fo all communications.

The network is built through various terrains, some of which are marked as hazardous zones. Each tower is either in a safe zone or a hazardous one. The outermost towers (the leaf nodes of the tree) need to be inspected by Sam, but he is cautious and wants to avoid paths that traversethrough too many consecutive hazardous zones.

Your task is to help Sam count the number of outermost towers (leaf nodes) he can safely inspect, where the path from the main control tower to the leaf contains no more than M consecutive hazardous zones.

It is guaranteed that the given set of edges forms a tree structure

Function description

Complete the safeView Points function in the editor below. It has the following parameter(s):

Name

Type

Description

INTEGER

M

the number of nodes in the tree

N

INTEGER

the maximum number of consecutive dangerous sections Alex is willing to traverse

G

INTEGER

Always equals to N-1

Submit

Arr

INTEGER ARRAY

Array of N integers stating if tower in safe zone or not

Arr2

INTEGER 2D ARRAY

2D array of size N-1 with two values.

Return

The function must return an INTEGER denoting the the number of viewpoints (leaf nodes) where the path from the main camp (node 1) contains at most M consecutive dangerous sections

Constraints

2 <= N <= 10 ^ 5

1 <= M <= N

N - 1 <= k <= N - 1

1 <= Arr * 1[i] <= 10 deg * 5

1 <= Arr * 2[i][j] <= 10 deg * 5

Input format for debugging

The first line contains an integer, N, denoting the number of elements in Arr1.

The next line contains an integer, M.

The next line contains an integer, k, denoting the number of rows in Arr2.

Each line I of the N subsequent lines (where 0 <= i < N ) contains an integer describing "Arr1[i]".

Each line i of the k subsequent lines (where 0 <= i < k ) contains 2 space separated integers each describing the row Arr2[1].
Sample Testcases

Input

Output

Output Description

2

7161011008

12

13

24

25

The number of outermost towers (leaf nodes) he can safely inspect.

mm 37

16

524110111234

45

The number of outermost towers (leaf nodes) he can safely inspect

#include <bits/stdc++.h>

using namespace std;

string trim(string);

vector<string> splitstring(string);

int safeViewPoints(int N, int M, int k, vector<int> Arri, vector<vector<int>> Arr2) (

// Write your code here

int main() (

ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); string inputline;

getline(cin, inputline); int & stol(trim(inputline));

getline(cin, inputline); int M stoi(trim(inputline));

getline(cin, inputline); int k stoi (trim(inputline));

vector<int> Arr1(N);

for(int j=0; j<n; j++) { getline(cin, inputline); Arri[j] stoi(trim(inputline));

vector<vector<int>> Arr2(k, vector<int>(2)); for(int i=0; i<k; i++) ( getline(cin, input line); vector<string> inputLineArr splitstring(trim(inputline)); for (int j e; j<z; j++) { Arr2[i][j]stoi(inputLineArr[j]);

int result safeViewPoints(N, M, k, Arr1, Arr2); cout << result << "\n";

return 0;

vector<string> splitstring(string input string) (

string::iterator new end unique(input string.begin(), input string.end(), [] (const char As, const char by) return xy and x 1);

input string.erase(new end, input string.end());

while (input string[input string.length()-1)

input string.pop_back();

vector<string> splits;

char delimiter

size t 10;

size t pos input string.find(delimiter);

while (pos 1 string::npos) (

splits.push_back(input string.substr(i, posi));

1 pos+ 1;

pos Input string.find(delimiter, i);

splits.push back(input string.substr(i, min(pos, input string.length())-1.1));
}
return splits;
}

Solve accordingly
*/


// #include <bits/stdc++.h>
// using namespace std;

// int safeViewPoints(int N, int M, vector<int>& Arr1, vector<vector<int>>& Arr2) {
//     vector<vector<int>> tree(N + 1); // Tree adjacency list
//     for (auto& edge : Arr2) {
//         tree[edge[0]].push_back(edge[1]);
//         tree[edge[1]].push_back(edge[0]);
//     }

//     int count = 0; // Count of safe viewpoints
//     vector<bool> visited(N + 1, false);

//     function<void(int, int)> dfs = [&](int node, int hazardCount) {
//         visited[node] = true;
//         if (Arr1[node - 1] == 1) hazardCount++;
//         else hazardCount = 0; // Reset consecutive hazardous count

//         if (hazardCount > M) return; // Exceeded max allowed hazardous sections

//         bool isLeaf = true;
//         for (int neighbor : tree[node]) {
//             if (!visited[neighbor]) {
//                 isLeaf = false;
//                 dfs(neighbor, hazardCount);
//             }
//         }
//         if (isLeaf) count++; // Leaf node meeting conditions
//     };

//     dfs(1, 0); // Start DFS from node 1

//     return count;
// }

// int main() {
//     ios::sync_with_stdio(0); cin.tie(0);

//     int N, M, k;
//     cin >> N >> M >> k;

//     vector<int> Arr1(N);
//     for (int i = 0; i < N; i++) cin >> Arr1[i];

//     vector<vector<int>> Arr2(k, vector<int>(2));
//     for (int i = 0; i < k; i++) cin >> Arr2[i][0] >> Arr2[i][1];

//     cout << safeViewPoints(N, M, Arr1, Arr2) << "\n";
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

int safeViewPoints(int N, int M, vector<int>& Arr1, vector<vector<int>>& Arr2) {
    vector<vector<int>> tree(N + 1); // Tree adjacency list
    for (auto& edge : Arr2) {
        tree[edge[0]].push_back(edge[1]);
        tree[edge[1]].push_back(edge[0]);
    }

    int count = 0; // Count of safe viewpoints
    vector<bool> visited(N + 1, false);

    function<void(int, int)> dfs = [&](int node, int hazardCount) {
        visited[node] = true;
        if (Arr1[node - 1] == 1) hazardCount++;
        else hazardCount = 0; // Reset consecutive hazardous count

        if (hazardCount > M) return; // Exceeded max allowed hazardous sections

        bool isLeaf = true;
        for (int neighbor : tree[node]) {
            if (!visited[neighbor]) {
                isLeaf = false;
                dfs(neighbor, hazardCount);
            }
        }
        if (isLeaf) count++; // Leaf node meeting conditions
    };

    dfs(1, 0); // Start DFS from node 1

    return count;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int N, M, k;
    cin >> N >> M >> k;

    vector<int> Arr1(N);
    for (int i = 0; i < N; i++) cin >> Arr1[i];

    vector<vector<int>> Arr2(k, vector<int>(2));
    for (int i = 0; i < k; i++) cin >> Arr2[i][0] >> Arr2[i][1];

    cout << safeViewPoints(N, M, Arr1, Arr2) << "\n";
    return 0;
}



/*
5
2
4
1
0
1
1
0
2 3
2 4
4 5
2
*/