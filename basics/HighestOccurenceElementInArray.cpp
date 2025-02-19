// class Solution {
//     public:
//         int mostFrequentElement(vector<int>& nums) {
//             // Line 5: Correct the method to get the size of the vector
//             int n = nums.size();
//             vector<int> hash(1000, 0);
//             int maxCount = 0, hOEle = 0;
//             for(int i : nums){
//                 hash[i]++;
//             }
//             // Line 12-17: Suggest refining max logic into a helper method and correct iteration from 0 as only used indices should be considered
//             for(int i = 0; i < hash.size(); i++){
//                 if (hash[i] > maxCount) {
//                     maxCount = hash[i];
//                     hOEle = i;
//                 }
//             }
//             return hOEle;
    
//         }
    
//         int max(int a, int b){
//             return (a > b) ? a : b;
//         }
//     };


#include<algorithm>
class Solution {
public:
    int mostFrequentElement(vector<int>& nums) {
        map<int, int> anotherArr;
        for(int i = 0; i < nums.size(); i++){
            anotherArr[nums[i]]++;
        } 

        int max_element = 0, second_max_count=0, max_element_count= 0;
        for(const auto& it: anotherArr){
            second_max_count = max_element_count;
            max_element_count = max(max_element_count, it.second);
            if(second_max_count != max_element_count){
                max_element = it.first;
            }
        }
        // return anotherArr[second_max_idx];
        return max_element;
    }

    int max(int a , int s){
        return (a > s) ? a : s;
    }
};