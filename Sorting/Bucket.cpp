#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int>& arr, int n){
for(int i = 1; i < n; i++){
int j = i; // why i ?
int k = arr[i];
while(j > 0 and arr[j - 1] > k){
arr[j] = arr[j - 1];
j--;
}
arr[j] = k;
}
}

void bucketSort(vector<int>& arr){
int n = arr.size();
// vector<int> bucket[n ]; //

vector<vector<int>> bucket(n);

for(int i = 0; i < n; i++){
int bucketNo = (arr[i] * n);
bucket[bucketNo].push_back(arr[i]);
}
for(int i = 0; i < n; i++){
insertionSort(bucket[i], bucket[i].size());
}
int index= 0 ;
for(int i = 0; i < n; i++){
for(int j = 0; j < bucket[i].size(); j++){
arr[index++] = bucket[i][j];
}
}
}
void print(vector<int> arr){
cout << "Array = ";
for(int i: arr){
cout << i << " ";
}
cout << endl;
}

int main(){
int n; cin >> n;
vector<int> arr(n);
for(int &i: arr){
cin >> i;
}
bucketSort(arr);
print(arr);
return 0;
}