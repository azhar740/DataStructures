vector<int> subarraySum(int arr[], int n, long long s)
    {
        // Your code here
       long long currSum = 0;
       int start = 0, end = 0;
       while(end < n){
           currSum += arr[end];
           while(currSum > s) currSum -= arr[start++];
           if(currSum == s && i <= j) return {i+1, j+1};
           j++;
       }
       return {-1};
    }
