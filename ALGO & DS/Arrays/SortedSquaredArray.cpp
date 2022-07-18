//Function to sort an square array
void sortSquares(vector<int>& arr, int n)
{
    int left = 0, right = n - 1;
    int result[n];
 
    // Iterate from n - 1 to 0
    for (int index = n - 1; index >= 0; index--) {
       
        // Check if abs(arr[left]) is greater
        // than arr[right]
        if (abs(arr[left]) > arr[right]) {
            result[index] = arr[left] * arr[left];
            left++;
        }
        else {
            result[index] = arr[right] * arr[right];
            right--;
        }
    }
    for (int i = 0; i < n; i++)
        arr[i] = result[i];
}
