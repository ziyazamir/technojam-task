#include<iostream>
#include<cstring>
using namespace std;
int main(){
int a,b,n,x,y;
// cout<<word1.length();
string word1,word2;
cout<<"enter your 1 string:";
cin>>word1;
a=word1.length();//give length of string
cout<<a;
cout<<"enter your 2 string:";
cin>>word2;
b=word2.length();
cout<<b;
cout<<endl;
char arr1[a],arr2[b],arr3[100],arr4[100];
strcpy(arr1, word1.c_str());//convert string word1 into array arr1
strcpy(arr2, word2.c_str());
if(a>b){
    n=a-b;
    y=b+n+1;
    x=b+1;
    for(int i=0;i<n;i++){         //splitting the extra part of the bigger array
        arr3[i]=arr1[x];        
        x++;
    }
}else if(b>a){
    n=b-a;
    y=a+n+1;
    x=a+1;
    for(int i=0;i<n;i++){
        arr3[i]=arr2[x];
    }
}else{
    y=a+b;
}
//  cout<<arr3<<endl;
int j=0,k=0; 
for(int i=0;i<y;i++){//arranging the array as question says
if(i%2==0){
   arr4[i]=arr1[j];
   j++;
}else{
    arr4[i]=arr2[k];
    k++;
}
}
string s1=string(arr4);//convert array to string
string s2=string(arr3);
cout<<s1<<s2;
}