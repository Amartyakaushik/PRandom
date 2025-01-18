// #include <bits/stdc++.h>
// using namespace std;

// // Insertion sort function to sort individual buckets
// void insertionSort(vector<float>& bucket) {
//     for (int i = 1; i < bucket.size(); ++i) {
//         float key = bucket[i];
//         int j = i - 1;
//         while (j >= 0 && bucket[j] > key) {
//             bucket[j + 1] = bucket[j];
//             j--;
//         }
//         bucket[j + 1] = key;
//     }
// }

// // Function to sort arr[] of size n using bucket sort
// void bucketSort(float arr[], int n) {
//     // 1) Create n empty buckets
//     vector<float> b[n];

//     // 2) Put array elements in different buckets
//     for (int i = 0; i < n; i++) {
//         int bi = n * arr[i];
//         b[bi].push_back(arr[i]);
//     }

//     // 3) Sort individual buckets using insertion sort
//     for (int i = 0; i < n; i++) {
//         insertionSort(b[i]);
//     }

//     // 4) Concatenate all buckets into arr[]
//     int index = 0;
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < b[i].size(); j++) {
//             arr[index++] = b[i][j];
//         }
//     }
// }

// // Driver program to test above function
// int main() {
//     float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     bucketSort(arr, n);

//     cout << "Sorted array is \n";
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }
//     return 0;
// }


class Solution {
public:
int largestRectangleArea(vector<int>& arr) {
int n = arr.size();
stack<int> s;
vector<int> left(n, -1); // pse
vector<int> right(n, n); // nse
for(int i = 0; i < n; i++){
while(!s.empty() and arr[i] <= arr[s.top()]){
s.pop();
}
if(!s.empty()){
left[i] = s.top() + 1;
}
s.push(i);
}
for(int i = n - 1; i >= 0; i--){
while(!s.empty() and arr[i] >= arr[s.top()]){
s.pop();
}
if(!s.empty()){
right[i] = s.top() - 1;
}
s.push(i);
}
int ans = 0;
for(int i = 0; i < n; i++){
int pse = left[i];
int nse = right[i];
int width = (nse - pse - 1);
int length = arr[i];
int curArea = (length * width);
ans = max(ans, curArea);
}
return ans;
}
};

