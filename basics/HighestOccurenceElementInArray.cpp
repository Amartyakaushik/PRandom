class Solution {
    public:
        int mostFrequentElement(vector<int>& nums) {
            // Line 5: Correct the method to get the size of the vector
            int n = nums.size();
            vector<int> hash(1000, 0);
            int maxCount = 0, hOEle = 0;
            for(int i : nums){
                hash[i]++;
            }
            // Line 12-17: Suggest refining max logic into a helper method and correct iteration from 0 as only used indices should be considered
            for(int i = 0; i < hash.size(); i++){
                if (hash[i] > maxCount) {
                    maxCount = hash[i];
                    hOEle = i;
                }
            }
            return hOEle;
    
        }
    
        int max(int a, int b){
            return (a > b) ? a : b;
        }
    };