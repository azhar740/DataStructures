#include <iostream>
#include <climits>
using namespace std;

int secondLargestEl(int arr[], int n) {
    int second = INT_MIN, max = INT_MIN;
    for(int i = 0; i < n; i++) {
        if(max < arr[i]) {
            second = max;
            max = arr[i];
        }
        /* If arr[i] is in between first and  
           second then update second  */
        else if(second < arr[i] && arr[i] < max)
            second = arr[i];    
    }
    if(second == INT_MIN) cout << "seocnd largest element is not present\n";
    return second;
}

int main() {
	int arr[] = {1,2,9,7,10,6};
	cout << secondLargestEl(arr, 6);
	return 0;
}
