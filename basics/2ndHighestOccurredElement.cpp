#include<bits/stdc++.h>
#include<map>
#include<iostream>
using namespace std;
int secondMostFrequentElement(vector<int>& nums) {
    map<int, int> anotherArr;
    for(int i = 0; i < nums.size(); i++){
        anotherArr[nums[i]]++;
    } 

    int max_element = 0;
    for(const auto& it: anotherArr){
        max_element = max(max_element, it.second);
    }
    cout<<max_element<<endl;
    int ans= (anotherArr.find(max_element));
    return ans;
}

int max(int a , int s){
    return (a > s) ? a : s;
}
int main(){
    vector<int> arr = {1,22,3,1,4,3,1,};
    cout<< secondMostFrequentElement(arr);
}