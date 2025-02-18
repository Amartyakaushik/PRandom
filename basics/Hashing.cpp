#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i =0; i<n; i++){
        cin>>arr[i];
    }
    int max = *max_element(arr, arr+n);

    int Hash[max +1] = {0};
    for(int i = 0; i< n; i++){
        Hash[arr[i]]++;
    }

    //  for reading queries
    int q;
    cin>>q;
    while(q--){
        int query;
        cin>>query;
        if(query > max){
            cout<<0<<endl;
        }else{
            cout<<Hash[query]<<endl;
        }
    }
    return 0;

}

/*
1 3 2 1 3
*/