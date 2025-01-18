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