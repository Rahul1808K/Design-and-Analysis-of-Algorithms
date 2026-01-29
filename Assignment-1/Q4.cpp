#include <iostream>
using namespace std;

int maxCrossingSum(int arr[], int l, int mid, int r) {
    int sum = 0;
    int lSum = arr[mid];

    for (int i = mid; i >= l; i--) {
        sum += arr[i];
        if (sum > lSum)
            lSum = sum;
    }

    sum = 0;
    int rsum = arr[mid + 1];

    for (int i = mid + 1; i <= r; i++) {
        sum += arr[i];
        if (sum > rsum)
            rsum = sum;
    }

    return lSum + rsum;
}

int maxSubArraySum(int arr[], int l, int r) {
    if (l == r)
        return arr[l];

    int mid = (l + r) / 2;

    int leftMax = maxSubArraySum(arr, l, mid);
    int rightMax = maxSubArraySum(arr, mid + 1, r);
    int crossMax = maxCrossingSum(arr, l, mid, r);

    return max(leftMax, max(rightMax, crossMax));
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Maximum Subarray Sum = "
         << maxSubArraySum(arr, 0, n - 1);

    return 0;
}
