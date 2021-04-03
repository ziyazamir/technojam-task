#include<iostream>
using namespace std;
void xorfunction(int n,int start){
    int nums[50],result;
    for(int i=0;i<n;i++){
        nums[i]=start + (i*2);
    }
   for(int k=0;k<n;k++){
       if(k==0){
           result = nums[k]^0;
       }
       else{
           result = result^nums[k];
       }
   }
   cout<<"the result is:"<<result;
}
int main(){
    int n,start;
    cout<<"enter the size of array:"<<endl;
    cin>>n;
    cout<<"enter the o index value of array:"<<endl;
    cin>>start;
    cout<<"the array is"<<endl;
    xorfunction(n,start);
    return 0;
}