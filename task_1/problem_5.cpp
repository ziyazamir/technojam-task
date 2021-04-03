//[,,,,,,,,,,,,,,,,,,,,,,,,,]
#include<iostream>
#include<cstring>
using namespace std;
string convert(char c){
    string res;
    switch (c){
        case 'a': res=".-";
            break;
        case 'b': res="-...";
            break;
        case 'c': res="-.-.";
            break;
        case 'd': res="-..";
            break;
        case 'e': res=".";
            break;
        case 'f': res="..-.";
            break;
         case 'g': res="--.";
            break;
        case 'h': res="....";
            break;
        case 'i': res="..";
            break;
        case 'j': res=".---";
            break;
        case 'k': res="-.-";
            break;
        case 'l': res=".-..";
            break;
         case 'm': res="--";
            break;
        case 'n': res="-.";
            break;
        case 'o': res="---";
            break;
        case 'p': res=".--.";
            break;
        case 'q': res="--.-";
            break;
        case 'r': res=".-.";
            break;
         case 's': res="...";
            break;
        case 't': res="-";
            break;
        case 'u': res="..-";
            break;
        case 'v': res="...-";
            break;
        case 'w': res=".--";
            break;
        case 'x': res="-..-";
            break;
        case 'y': res="-.--";
            break;
        case 'z': res="--..";
            break;
    }
    return res;
}
int main(){
    int n;
    string arr[100],code="",arr4[100];
    char arr1[100];
    cout<<"enter the no of words:";
    cin>>n;
    cout<<endl;
    int a=1;
    for(int i=0;i<n;i++){
        cout<<"enter the word:";
        cin>>arr[i];
        cout<<endl;
        a++;
    }
    // strcpy(arr1,arr[0].c_str());
    // cout<<arr1[0];
    for(int i=0;i<n;i++){
        strcpy(arr1,arr[i].c_str());
        int y=strlen(arr1);
         //cout<<y;
        for(int j=0;j<y;j++){
            //cout<<arr1[j]<<"\n";
           code=code+convert(arr1[j]);
        }
        arr4[i]=code;
        code="";
        cout<<arr[i]<<"->"<<arr4[i]<<"\n";
    }
    int result=n,j=0;
    for(int i=0;i<n;i++){
        j=j+i;
        for(j;j<=n;j++){
             if(arr4[i] == arr4[j]){
                 result=result-1;
             }
        }
    }
    cout<<"the no of different transformation is :"<<result;
} 