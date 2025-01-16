#include<bits/stdc++.h>
using namespace std;
// each time select the smallest element and then greater and then greater and place it to its correct position
void selectionSort(vector<int>& arr, int size){
    for(int i = 0; i< size-1; i++){
        int min_index = i;
        // the unsorted part
        for(int j = i + 1; j <size; j++){
            if(arr[j] < arr[min_index]){
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]);
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
    for(int &i : arr){
        cin>>i;
    }

    selectionSort(arr, n);
    print(arr);
}