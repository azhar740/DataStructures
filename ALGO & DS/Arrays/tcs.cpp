int arr[] = {9,2,1,12,5,3};


int secondLargest(int arr[], int n) {
	int max = INT_MIN;
	for(int i = 0; i < n; i++) {
		if(max < arr[i]) {
			max = arr[i];
			index = i;
			
		}
		if(max >= arr[i])
				second = arr[i];
	}

	return second;



}
