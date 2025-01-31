
deque<Node*>dqEven;
deque<Node*>dqOdd;

dqEven.push_back(root);
bool even = true;

vector<int>ans;

while(true){
if(even){
while(!dqEven.empty()){
Node* node = dqEven.back();
dqEven.pop_back();

ans.push_back(node->data);
// even wale k liye left , right push krenge

if(node->left) dqOdd.push_back(node->left);
if(node->right) dqOdd.push_back(node->right);
}
even = false;
}
else if(!even){
while(!dqOdd.empty()){
Node* node = dqOdd.back();
dqOdd.pop_back();

ans.push_back(node->data);
// odd lvl k liye hmm right , left push krenge

if(node->right) dqEven.push_back(node->right);
if(node->left) dqEven.push_back(node->left);
}
even = true;
}

// jab sare lvl khtm ho jayenge
if(dqEven.size()==0 && dqOdd.size()==0){
break;
}
}

return ans;

// bool fn(vector<int>& arr, int n, int k, int mid){
// int total = 0;
// int painters = 1;
// for(int i = 0; i < n; i++){
// total += arr[i];
// if(total > mid){
// painter++;
// total = arr[i];
// }
// if(painters > k){
// return false;
// }
// }
// return true;
// }
// int minTime(vector<int>& arr, int n, int countPainters){
// int low = INT_MAX;
// int high = 0;
// for(int i = 0; i < n; i++){
// low = min(low, arr[i]);
// high += arr[i];
// }
// int ans = -1;
// while(low <= high){
// int mid = (low + high) >> 1; // check for overflow
// bool can = fn(arr, n, k, mid);
// if(can){
// ans = mid;
// high = mid - 1;
// }
// else{
// low = mid + 1;
// }
// }
// return ans;

// }
// int findPages(vector<int> &arr, int k) {
// return minTime(arr, arr.size(), k); //
// }