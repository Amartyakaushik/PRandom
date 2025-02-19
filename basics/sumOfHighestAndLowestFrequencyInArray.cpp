class Solution {
    public:
        int sumHighestAndLowestFrequency(vector<int>& nums) {
            map<int, int> anotherarr;
            for(int i : nums){
                anotherarr[i]++;
            }
    
            int max_freq = 0, min_freq = INT_MAX;
            for(const auto& it : anotherarr){
                max_freq = max(it.second, max_freq);
                min_freq = min(it.second, min_freq);
            }
            return (max_freq + min_freq);
        }
    
        int max(int a, int b){
            return (a > b) ? a : b;
        }
    
        int min(int a, int b){
            return (a < b) ? a : b;
        }
    };
    