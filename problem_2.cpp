#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){
    int m,n,p=1,arr[100][100];
    // srand(time(0));
    cout<<"enter the no of rows of your matrix:";
    cin>>m;
    cout<<"enter the no of columns of your matrix:"<<endl;
    cin>>n;
    for(int i=0;i<m;i++){
        cout<<"enter the nos of "<<p<<" row";
        for(int j=0;j<n;j++){
           cin>>arr[i][j];
        }
        p++;
    }
    // int arr[3][3] = {
    //                {3,7,8},
    //                {9,11,13}, 
    //                {15,16,17}
    //                          };
    // cout<<"the matrix is"<<endl;
    // m=3;
    // n=3;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<",";
        }
        cout<<endl;
    }
   
   for(int i=0;i<m;i++){
        int col_index=0, mini=10008,max;
           for(int k=0;k<n;k++){//checking the min in each row
               if (arr[i][k]<=mini)
               {
                   mini=arr[i][k];
                  col_index=k;
               }
               
           }
            max = -1;
           for(int j=0;j<m;j++){ //checking the max number in the given column of the min number
                   if(arr[j][col_index]>max){
                      max=arr[j][col_index];
                   }
               }
               if(mini==max){
                   cout<<"the lucky no is"<<max;
               }
       }
   }
    
