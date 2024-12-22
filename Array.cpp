#include <iostream>

using namespace std;

// Function to find the median of a sorted array(Assumption is the array is sorted)
double median(int arrx[], int sizex) {
    if (sizex == 0) {
        return -1; 
    }
    else if (sizex % 2 == 0) {
        return (arrx[(sizex / 2)] + arrx[(sizex / 2) - 1]) / 2.0;
    }
    else {
        return arrx[(sizex - 1) / 2];
    }
}
// Function to find the median
//Assumption is that the arrays are sorted
double findMedian(int arr1[], int size1, int arr2[], int size2) {
    // Your code here
    if (size1 == 0 && size2 == 0) {
        return -1;  
    }
    int arrv[size1 + size2];
    int r = 0, l = 0, p = 0;
    // Merge the two sorted arrays
    while (l < size2 && r < size1) {
        if (arr1[r] < arr2[l]) {
            arrv[p] = arr1[r];
            p++;
            r++;
        } else {
            arrv[p] = arr2[l];  
            p++;
            l++;
        }
    }
    // Add remaining elements from arr1
    while (r < size1) {
        arrv[p] = arr1[r];
        p++;
        r++;
    }
    
    // Add remaining elements from arr2
    while (l < size2) {
        arrv[p] = arr2[l];
        p++;
        l++;
    }
   // Find and return the median of the merged array
    return median(arrv, size1 + size2);
}



int main() {
    // You can use cout statements, but ensure that you submit after commenting them out, as the autograder will otherwise mistake it for your actual output
    // Everything else in the main function remains unchanged
    
    int size1;
    //cout << "Enter the size of the array1: ";
    cin >> size1;

    int arr[size1];
    //cout << "Enter " << size1 << " elements:" << endl;
    for (int i = 0; i < size1; ++i) {
        cin >> arr[i];
    }

    //cout << "The array elements are: ";
    //for (int i = 0; i < size1; ++i) {
      //cout << arr[i] << " ";
    //}
    //cout << endl;

    int size2;
    //cout << "Enter the size of the array2: ";
    cin >> size2;

    int arr1[size2];
    //cout << "Enter " << size2 << " elements:" << endl;
    for (int i = 0; i < size2; ++i) {
        cin >> arr1[i];
    }

    //cout << "The array elements are: ";
    //for (int i = 0; i < size2; ++i) {
        //cout << arr1[i] << " ";
    //}
    //cout << endl;
    if (findMedian(arr, size1, arr1, size2) == -1){
        cout << "Empty Array" << endl;
    }
    else{
    cout << "Median = " << findMedian(arr, size1, arr1, size2) << endl; // do not comment this out
    }
    return 0;
}
