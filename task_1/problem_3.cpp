#include <iostream>
using namespace std;
int result_func(int arr1[], int arr2[])//function to find the min time between two given points
{
    int res1, res2, result;
    if (arr1[0] > arr2[0])
    {
        res1 = arr1[0] - arr2[0];
    }
    else
    {
        res1 = arr2[0] - arr1[0];
    }
    if (arr1[1] > arr2[1])
    {
        res2 = arr1[1] - arr2[1];
    }
    else
    {
        res2 = arr2[1] - arr1[1];
    }
    if (res1 > res2)
    {
        result = res1;
    }
    else
    {
        result = res2;
    }
    return result;
}
int main()
{
    int arr1[2], arr2[2],arr3[2],arr4[2], n, result;
    cout << "through how many points you have to pass";
    cin >> n;
    switch (n)
    {
    case 2://for two pints
        cout << "enter x1:";
        cin >> arr1[0];
        cout << endl;
        cout << "enter y1:";
        cin >> arr1[1];
        cout << endl;
        cout << "enter x2:";
        cin >> arr2[0];
        cout << endl;
        cout << "enter y2:";
        cin >> arr2[1];
        cout << endl;
        result = result_func(arr1, arr2);
        cout << "the min time is:" << result;
        break;
    case 3://for three points
        cout << "enter x1:";
        cin >> arr1[0];
        cout << endl;
        cout << "enter y1:";
        cin >> arr1[1];
        cout << endl;
        //enter second point
        cout << "enter x2:";
        cin >> arr2[0];
        cout << endl;
        cout << "enter y2:";
        cin >> arr2[1];
        cout << endl;
       // enter third point
        cout << "enter x3:";
        cin >> arr3[0];
        cout << endl;
        cout << "enter y3:";
        cin >> arr3[1];
        cout << endl;
        result = result_func(arr1, arr2)+result_func(arr2, arr3);
        cout << "the min time is:" << result;
        break;
    }
}