#include<bits/stdc++.h>
using namespace std;
void bubble(vector<int>& arr, int size){
    for(int i = 1; i <= size-1; i++){
        for(int j = 0; j < size-i; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void print(vector<int> arr){
    for(int i:arr){
        cout<<i<<" ";
    }
    cout<<endl;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int &i:arr){
        cin>>i;
    }

    bubble(arr, n);
    print(arr);
}