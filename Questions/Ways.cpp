#include<bits/c++.h>
using namespace std;

int fn(int amt, int coin, string way){
    if(amt <= 0){
        if(amt == 0){
            cout<<way<<endl;
            return 1;
        }
    }

    return fn(amt-1, coin, way)
}
int main(){

}