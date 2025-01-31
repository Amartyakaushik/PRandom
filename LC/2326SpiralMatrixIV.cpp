// class Solution {
// public:
// vector<vector<int>> spiralMatrix(int n, int m, ListNode* head) {
// // n*m
// int sr = 0;
// int sc = 0;
// int direction = 0;
// vector<vector<int>> arr(n, vector<int>(m, -1));
// while(head){
// arr[sr][sc] = head->val;
// head = head->next;
// if(direction == 0){
// sc++;
// if(sc == m or arr[sr][sc] != -1){
// sc--;
// sr++;
// direction = 1;
// }
// }
// else if(direction == 1){
// sr++;
// if(sr == n or arr[sr][sc] != -1){
// sr--;
// sc--;
// direction = 2;
// }
// }
// else if(direction == 2){
// sc--;
// if(sc < 0 or arr[sr][sc] != -1){
// sr--;
// sc++;
// direction = 3;
// }
// }
// else if(direction == 3){
// sr--;
// if(sr < 0 or arr[sr][sc] != -1){
// sr++;
// sc++;
// direction = 0;
// }
// }
// }
// return arr;
// }
// };

#include <bits/stdc++.h>
#include <array>
#include<iostream>
using namespace std;

int main(){
// char arr[] = {'a','a','a','a','a'};
// char arr2[] = "sdas";
//     cout<<sizeof(arr)<<endl;
//     cout<<strlen(arr2)<<endl;

int lar = INT_MIN;
int arr[]={1,2,3,423,23,222};
for(int i : arr){
    lar = max(i, lar);
    // cout<<i;
}

cout<<lar;
    return 0;
}