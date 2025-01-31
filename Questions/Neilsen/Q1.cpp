// // // #include <bits/stdc++.h>
// // // using namespace std;

// // // // int minSteps(vector<int> &cityMap, int r, int c, int k) {
// // // //     if (cityMap[0] || cityMap[r * c - 1]) return -1;
// // // //     int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
// // // //     queue<tuple<int, int, int>> q;
// // // //     set<tuple<int, int, int>> vis;

// // // //     q.push({0, 0, 0}), vis.insert({0, 0, 0});
// // // //     for (int steps = 0; !q.empty(); steps++) {
// // // //         for (int sz = q.size(); sz--; ) {
// // // //             auto [x, y, s] = q.front(); q.pop();
// // // //             if (x == r - 1 && y == c - 1) return steps;
// // // //             for (int i = 0; i < 4; i++) {
// // // //                 for (int j = 1; j <= k; j++) {
// // // //                     int nx = x + dx[i] * j, ny = y + dy[i] * j;
// // // //                     if (nx >= 0 && ny >= 0 && nx < r && ny < c && !cityMap[nx * c + ny] && vis.insert({nx, ny, steps + 1}).second)
// // // //                         q.push({nx, ny, steps + 1});
// // // //                 }
// // // //             }
// // // //         }
// // // //     }
// // // //     return -1;
// // // // }

// // // // int main() {
// // // //     int r, c, k;
// // // //     cin >> r >> c >> k;
// // // //     vector<int> cityMap(r * c);
// // // //     for (int &i : cityMap) cin >> i;
// // // //     cout << minSteps(cityMap, r, c, k);
// // // // }


// // // int waystoBalance(vector<int> nums) {
// // //     int count = 0;
// // //     int n = nums.size();
    
// // //     // For each possible index to remove
// // //     for (int i = 0; i < n; i++) {
// // //         int evenSum = 0, oddSum = 0;
        
// // //         // Calculate sums after removing index i
// // //         for (int j = 0; j < n; j++) {
// // //             if (j == i) continue; // Skip the removed element
            
// // //             // Adjust index because of removal
// // //             int newIndex = j > i ? j - 1 : j;
            
// // //             // Add to even or odd sum based on new index
// // //             if (newIndex % 2 == 0) {
// // //                 evenSum += nums[j];
// // //             } else {
// // //                 oddSum += nums[j];
// // //             }
// // //         }
        
// // //         // Check if balanced
// // //         if (evenSum == oddSum) {
// // //             count++;
// // //         }
// // //     }
    
// // //     return count;
// // // }

// #include <bits/stdc++.h>
// using namespace std;

// // int waystoBalance(vector<int>& nums) {
// //     int n = nums.size(), evenSum = 0, oddSum = 0, res = 0;
// //     vector<int> prefixEven(n + 1, 0), prefixOdd(n + 1, 0);

// //     for (int i = 0; i < n; i++) {
// //         prefixEven[i + 1] = prefixEven[i] + (i % 2 == 0 ? nums[i] : 0);
// //         prefixOdd[i + 1] = prefixOdd[i] + (i % 2 ? nums[i] : 0);
// //     }

// //     for (int i = 0; i < n; i++) {
// //         int leftEven = prefixEven[i], leftOdd = prefixOdd[i];
// //         int rightEven = prefixOdd[n] - prefixOdd[i + 1]; 
// //         int rightOdd = prefixEven[n] - prefixEven[i + 1];
// //         if (leftEven + rightEven == leftOdd + rightOdd) res++;
// //     }
// //     return res;
// // }

// // int main() {
// //     vector<int> nums = {1,1,1}; // Example input
// //     cout << waystoBalance(nums) << endl;
// //     return 0;
// // }
// // int func(int[] arr, int n, int 1)

// // {

// // PriorityQueue<Integer> p = new PriorityQueue<>();

// // int ct = 0

// // int res = 1;

// // for (int i = 0 ; i < n ; i++)

// // p.add(arr[i]);

// // for(;p.isEmpty() == false && ct < 1 ct++)

// // {

// // res = res * p.element();

// // p.remove();

// // }

// // return res;
// // }

// #include <bits/stdc++.h>
// using namespace std;

// struct State {
//     int x, y, steps;
//     State(int _x, int _y, int _steps) : x(_x), y(_y), steps(_steps) {}
// };

// int minSteps(vector<int> cityMap, int rows, int cols, int maxSteps) {
//     vector<vector<int>> grid(rows, vector<int>(cols));

//     // Convert 1D input into a 2D grid
//     for (int i = 0; i < rows; i++) {
//         for (int j = 0; j < cols; j++) {
//             // Convert the digit to 0 or 1 based on whether it's an obstacle
//             grid[i][j] = (cityMap[i * cols + j] > 0) ? 1 : 0;
//         }
//     }

//     // If start or end position is blocked, return -1
//     if (grid[0][0] == 1 || grid[rows - 1][cols - 1] == 1) return -1;

//     // Directions: only right and down allowed
//     vector<vector<int>> directions = {{0, 1}, {1, 0}};
    
//     // Queue stores {x, y, steps}
//     queue<State> q;
//     q.push(State(0, 0, 0));
    
//     // 3D visited array to track position and direction
//     vector<vector<vector<bool>>> visited(rows, 
//         vector<vector<bool>>(cols, 
//             vector<bool>(maxSteps + 1, false)));
//     visited[0][0][0] = true;

//     while (!q.empty()) {
//         State current = q.front();
//         q.pop();

//         int x = current.x, y = current.y, steps = current.steps;

//         // Reached destination
//         if (x == rows - 1 && y == cols - 1) return steps;

//         // Try both directions
//         for (auto dir : directions) {
//             // Try steps from 1 to maxSteps
//             for (int k = 1; k <= maxSteps; k++) {
//                 int nx = x + dir[0] * k;
//                 int ny = y + dir[1] * k;

//                 // Check bounds and obstacles
//                 if (nx >= 0 && nx < rows && ny >= 0 && ny < cols) {
//                     // Stop if hit obstacle
//                     if (grid[nx][ny] == 1) break;
                    
//                     // If not visited this position with this number of steps
//                     if (!visited[nx][ny][k]) {
//                         visited[nx][ny][k] = true;
//                         q.push(State(nx, ny, steps + 1));
//                     }
//                 } else {
//                     break; // Stop if out of bounds
//                 }
//             }
//         }
//     }
//     return -1;  // No valid path found
// }

// int main() {
//     // Test cases
//     vector<int> cityMap1 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 5};
//     cout << minSteps(cityMap1, 1, 13, 3) << endl; // Should output 5

//     vector<int> cityMap2 = {9, 0, 0, 0, 0, 1, 1, 0, 1, 0, 3, 3, 4};
//     cout << minSteps(cityMap2, 1, 13, 3) << endl; // Should output -1

//     return 0;
// }