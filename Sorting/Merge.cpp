#include <bits/stdc++.h>
using namespace std;


void merge(vector<int> &arr, int left, int mid, int right){
    int size1 = mid - left + 1, size2 = right - mid;
    vector<int> leftArr(size1), rightArr(size2);

    for(int i = 0; i<size1; i++){
        leftArr[i] = arr[left + i];
    }
    for(int i = 0; i<size2; i++){
        rightArr[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, key = left;
    while(i < size1 && j < size2){
        if(leftArr[i] < rightArr[j]){
            arr[key++] = leftArr[i++];
        }else{
            arr[key++] = rightArr[j++];
        }
    }

    while(i < size1){
        arr[key++] = leftArr[i++];
    }
    while(j < size2){
        arr[key++] = rightArr[j++];
    }
}
void mergeSort(vector<int> &arr, int left, int right){
    if(left >= right){
        return;
    }

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);
    merge(arr, left, mid, right);
}

void printVector(vector<int> arr)
{
    for (int i :arr)
        cout <<i<< " ";
    cout << endl;
}

int main()
{
    vector<int> arr = { 12, 11, 13, 5, 6, 7 };
    int n = arr.size();

    cout << "Given vector is \n";
    printVector(arr);

    mergeSort(arr, 0, n - 1);

    cout << "\nSorted vector is \n";
    printVector(arr);
    return 0;
}