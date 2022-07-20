int equi(int arr[], int n) {
  int leftSum = 0, sum = 0;
  for(int i = 0; i < n; i++) {
    sum += arr[i];
  }
  for(int i = 0; i < n ; i++) {
    sum = sum - arr[i];
    if(sum == leftSum) return i;
    leftSum += arr[i];
  }
  return -1;
}
