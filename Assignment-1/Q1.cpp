#include <iostream>
using namespace std;

int main(){
    int arr[] = {2,5,8,12,16,23,38,56,72,91};
    int n = sizeof(arr)/sizeof(arr[0]);
    int ele;
    cout << "Enter the element to search: ";
    cin >> ele;
    int l = 0, r = n - 1;
    int mid = l + (r - l) / 2;

    while (l <= r) {
        if (arr[mid] == ele) {
            cout << "Element found at index: " << mid << endl;
            return 0;
        }
        else if (arr[mid] < ele) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
        mid = l + (r - l) / 2;
    }
    cout << "Element not found in the array." << endl;
    return 0;
}