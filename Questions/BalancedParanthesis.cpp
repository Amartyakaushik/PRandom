#include <bits/stdc++.h>
using namespace std;

void generateSubsequences(vector<int>& arr, vector<int>& current, int index, vector<vector<int>>& result) {
    if (index == arr.size()) {
        result.push_back(current);
        return;
    }
    
    // Include the current element
    current.push_back(arr[index]);
    generateSubsequences(arr, current, index + 1, result);
    
    // Exclude the current element
    current.pop_back();
    generateSubsequences(arr, current, index + 1, result);
}

int main() {
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> result;
    vector<int> current;
    
    generateSubsequences(arr, current, 0, result);
    
    cout << "All Subsequences:" << endl;
    for (const auto& subseq : result) {
        cout << "[";
        for (const auto& val : subseq) {
            cout << val << " ";
        }
        cout << "]" << endl;
    }
    
    return 0;
}
