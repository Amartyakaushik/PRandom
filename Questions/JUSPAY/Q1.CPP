/*
Background:

A water supply company has constructed a network of pipelines to distribute water from a central reservoir to all connected towns. The network is organized in a balanced tree structure, with the reservoir as the root. Each pipeline has a maintenance cost based on its length and condition.

Objective:

You need to manage this pipeline network by calculating the water transport cost between towns and updating pipeline maintenance costs as needed.

Functionality Requirements:

1. Transport Cost Query: Calculate the total maintenance cost for transporting water between any two towns.

2. Cost Update Query: Adjust the maintenance cost for any specific pipeline between towns.

Input Format:

Network Configuration: The input contains 3 integers, N (the number of towns) and R (the root town representing the reservoir), M=N-1.

• The next N-1 lines each contain three integers I, J, K, where I and J are two connected towns and K is the maintenance cost of the pipeline.

Answered

Queries: An integer Q indicates the number of queries.

Each of the next Q lines describes a query, either:

1 A B to calculate the total maintenance cost between towns A and B.

21 J K to update the maintenance cost for the pipeline between towns I and J to K.

Output Format:

Sum of result of each transport cost query, le sum of the total cost between the specified towns.

Function description

Complete the solve function in the editor below. It has the following parameter(s):

Console

N

Name

Type

Description

INTEGER

number of towns

G

Submit

R

INTEGER

root town representing the reservoir

M

INTEGER

N-1
M

edges

INTEGER

N-1

INTEGER 2D ARRAY

Q

INTEGER

queries

Return

Next >

C

80

81

82

83

N-1 rows each contain three integers I, J, K, where I and J are two connected towns and K is the maintenance cost of the pipeline.

84

85

85

87

88

89

number of queries

90

91

92

93

94

INTEGER 2D ARRAY

Q rows describes a query, either: 1 A B to calculate the total maintenance cost between towns A and B. 21JK to update the maintenance cost for the pipeline between towns I and J to K.

The function must return an INTEGER denoting the sum of result of each transport cost query, le sum of the total cost between the specified towns. Function description Constraints Input format for debugging Sample Testcases Failed to save Title needs to

95

96

97

Constraints

1 <N< 10^5

1R 10^5

1≤M≤ 10°5

1 sedges[i][j]≤ 10^5

1 ≤Q≤ 10^5

1<queries[i]≤ 10^5

Input format for debugging

The first line contains an integer, N, denoting the number of towns

Input format for debugging

Next >

80

81

The first line contains an integer, N, denoting the number of towns.

82

The next line contains an integer, R, denoting the root town representing the reservoir.

83

84

The next line contains an integer, M, denoting the number of rows in edges.

85

The next line contains an integer, 3, denoting the number of columns in edges.

86

87

Each line i of the M subsequent lines (where 01 M) contains 3 space separated integers each describing the row edges[i].

88

89

The next line contains an integer, Q, denoting the number of rows in queries.

90

The next line contains an integer, 4, denoting the number of columns in queries.

91

92

Each line i of the Q subsequent lines (where 0≤1 <Q) contains 4 space separated integers each describing the row queries[i].

93

94

95

Sample Testcases

96

97

Input

Output

Output Description

Anowered

2

1

125

3

1210

2122

1128

3

2

121

231

3

1130

G

Submit

2235

1330

undefined

Initially 1 to 3 had cost 1+1-2

Later, cost =6

So, 6+2= 8.
#include <bits/stdc++.h>

using namespace std;

tral

3

4 string trim(string);

5 vector<string> splitString(string);

6

s and

7

8 int solve(int N, int R, int M, vector<vector<int>> edges, int Q, vector<vect

9

// write your code here

10

11

en any

}

12

13

14

int main() {

15

ios::sync_with_stdio(0);

root

16

cin.tie(0); cout.tie(0);

17

string inputline;

ns and

18

I

getline(cin, inputline);

20

int N stoi(trim(inputline));

22

23

getline(cin, inputline);

int R stoi(trim(inputline));

25

getline(cin, inputline);

ns.

26

int M stoi(trim(inputline));

28

29

vector<vector<int>> edges (M, vector<int>(3));

for(int i=0; i<M; i++) {

getline(cin, inputline);

vector<string> inputLineArr splitString(trim(inputline));

tral

33

edges[i][j] stoi(inputLineArr[j]);

34

20

35

}

36

s and

37

38

39

40

een any

41

42

43

S. ns.

44

j++){ for (int j=0; j<4; j++) {

45

root

46

getline(cin, inputline);

int Q stoi(trim(inputline));

vector<vector<int>> queries(Q, vector<int>(4));

for(int i=0; i<0; i++) (

getline(cin, inputline);

vector<string> inputLinearr = splitstring(trim(inputline));

}

queries[i][j] stoi (inputLineArr[j]);

47

}

ns and

48

49

50

51

int result solve(N, R, M, edges, Q, queries);

cout << result << "\n";

52

53

return 0;

54

}

55

56

57

// Utility functions. Don't modify these //

58 string trim(string str){

59 if(str.empty())

60

return str;
size t firstscan str.find_first_not_of('');

63 size t first firstScan string::npos? str.length(): firstScan;

a central with the

64 size t last - str.find_last_not_of('');

65 return str.substr(first, last-first+1);

ition.

66

67

en towns and

68

69 vector<string> splitstring(string input string) {

70 string::iterator new_end unique(input string.begin(), input string.end(), [] (c

71

return xy and x = '';

72

});

between any

73

74 input_string.erase(new_end, input_string.end());

towns.

75

76 while (input string[input_string.length() 1]==''){

R (the root

77

input_string.pop_back();

78

79

ed towns and

80 vector<string> splits;

81 char delimiter = '';

82

83 size ti=0;

B4 size t pos input_string.find(delimiter);

85

86 while (pos 1 string::npos) {

ed towns.

87 splits.push_back(input_string.substr(i, posi));

88

89 i pos + 1;

90 pos input_string.find(delimiter, i);

splits.push_back(input_string.substr(i, min(pos, input string.length()) 1+1));

tral

95 return splits;

Solve this question accordingly
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> adj;
vector<int> parent;
vector<int> depth;
vector<unordered_map<int, int>> cost;

void dfs(int u, int p, int d) {
    parent[u] = p;
    depth[u] = d;
    for (auto &edge : adj[u]) {
        int v = edge.first;
        int w = edge.second;
        if (v != p) {
            cost[u][v] = w;
            dfs(v, u, d + 1);
        }
    }
}

int getCost(int u, int v) {
    int totalCost = 0;
    while (u != v) {
        if (depth[u] > depth[v]) {
            totalCost += cost[parent[u]][u];
            u = parent[u];
        } else {
            totalCost += cost[parent[v]][v];
            v = parent[v];
        }
    }
    return totalCost;
}

int solve(int N, int R, int M, vector<vector<int>> edges, int Q, vector<vector<int>> queries) {
    adj.resize(N + 1);
    parent.resize(N + 1);
    depth.resize(N + 1);
    cost.resize(N + 1);

    for (auto &edge : edges) {
        int u = edge[0], v = edge[1], w = edge[2];
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    dfs(R, -1, 0);

    int total = 0;
    for (auto &query : queries) {
        if (query[0] == 1) {
            int u = query[1], v = query[2];
            total += getCost(u, v);
        } else if (query[0] == 2) {
            int u = query[1], v = query[2], newCost = query[3];
            if (parent[u] == v) {
                cost[v][u] = newCost;
            } else {
                cost[u][v] = newCost;
            }
        }
    }

    return total;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string inputline;
    getline(cin, inputline);
    int N = stoi(inputline);

    getline(cin, inputline);
    int R = stoi(inputline);

    getline(cin, inputline);
    int M = stoi(inputline);

    vector<vector<int>> edges(M, vector<int>(3));
    for (int i = 0; i < M; i++) {
        getline(cin, inputline);
        istringstream iss(inputline);
        iss >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    getline(cin, inputline);
    int Q = stoi(inputline);

    vector<vector<int>> queries(Q, vector<int>(4));
    for (int i = 0; i < Q; i++) {
        getline(cin, inputline);
        istringstream iss(inputline);
        iss >> queries[i][0] >> queries[i][1] >> queries[i][2] >> queries[i][3];
    }

    int result = solve(N, R, M, edges, Q, queries);
    cout << result << "\n";

    return 0;
}

/* input
5
1
4
1 2 10
2 3 5
3 4 8
4 5 12
3
1 1 5
2 3 4 15
1 1 5



output

77*/

/*
    
2
1
1
1 2 5
3
1 2 1 0
2 1 2 2
1 1 2 0
OUTPUT
7*/