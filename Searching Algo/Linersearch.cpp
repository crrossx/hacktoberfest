#include<bits/stdc++.h>
using namespace std;

int linearSearch(int arr[],int n,int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key)
            return i;
    }

    return -1;
}

int main(){

    int arr[6]={2,6,23,634,567,123};

    int index=linearSearch(arr,6,64);
    cout<<index<<endl;


return 0;
}