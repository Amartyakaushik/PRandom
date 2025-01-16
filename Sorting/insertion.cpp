#include <bits/stdc++.h>
using namespace std;
void insertionSort(vector<int>& arr, int size){
    for(int i = 1; i < size; i++){
        int key = arr[i];
        int lastSortedEle = i -1;
        // while(arr[lastSortedEle] > key && lastSortedEle >= 0){
        //     arr[lastSortedEle + 1] = arr[lastSortedEle];
        //     lastSortedEle--;
        // }

        // with the help of pointer
        while(arr[lastSortedEle] > key && lastSortedEle >= 0){
            int *current = &arr[lastSortedEle + 1];
            int *prev =  &arr[lastSortedEle];
            int temp = *current;
            *current = *prev;
            *prev = temp;
            lastSortedEle--;
        }

        // arr[lastSortedEle + 1] = key;
    }
}
void print(vector<int> arr, int size){
    for(int i:arr){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    // for(int i = 0; i < n; i++){
    //     cin>>arr[i];
    // }
    for(int &i : arr){
        cin>>i;
    }

    insertionSort(arr, n);
    print(arr,n);
}