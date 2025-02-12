
// class Solution {
// public:
//     int findMin(vector<int>& nums) {
//         int left = 0, right = nums.size() - 1;
        
//         while (left < right) {
//             int mid = left + (right - left) / 2;
//             if (nums[mid] > nums[right]) left = mid + 1;
//             else right = mid;
//         }
        
//         return nums[left];
//     }
// };
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) left = mid + 1;
            else right = mid;
        }
        return nums[left];
    }
};

int main() {
    string input;
    getline(cin, input);
    stringstream ss(input);
    vector<int> nums;
    int num;
    
    while (ss >> num) nums.push_back(num);

    Solution sol;
    cout << sol.findMin(nums) << endl;
    return 0;
}
