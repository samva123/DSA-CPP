#include<iostream>
#include<vector>
using namespace std;

int func(vector<int>&arr , int target){
    int s  = 0 ;
    int e  = arr.size()-1;
    int mid  = s+(e-s)/2;

    while(s <= e){
        mid  = s+(e-s)/2;

        if(arr[mid] == target){
            return mid;
            s = mid+1;
        }
        else if(arr[mid] < target){
            s  = mid+1;
        }else{
            e = mid-1;

        }
    }
    return -1;
}

int pivot(vector<int>&arr){
    int s  = 0 ;
    int e  = arr.size()-1;
    int mid  = s+(e-s)/2;

    while(s <= e){
        mid  = s+(e-s)/2;

        if(arr[mid] > arr[mid+1]){
            return mid;
        }else if(arr[mid] < arr[mid-1]){
            return mid-1;
        }

    }

}


int peak(vector<int>&arr){
    int s  = 0 ;
    int e  = arr.size()-1;
    int mid  = s+(e-s)/2;


    while(s < e){
        mid  = s+(e-s)/2;

        if(arr[mid] < arr[mid+1]){
            s  = mid+1;
        }
        else{
            e  = mid;
        }

    }
    return e;

}


int sqrt(int n ){
    int s  = 0 ;
    int e  = n;

    int mid  = s+(e-s)/2;

    while(s <= e){
        if(mid*mid  == n){
            return mid;
        }
        if()
    }


}

int main(){

}