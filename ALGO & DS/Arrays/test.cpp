



int arr [] = {1 2 3, 3 2 0 -2}


0 -1 0 -1 1,2,3,4


int maxPeakCount(int arr[], int n) {
	int maxCount = INT_MIN;

	int i = 0;
	while(true) {
		int cnt = 0;
		bool flag1 = false, flag2 = false;
		while(a[i] < arr[i+1] && i < n -1) {
			cnt++;
			i++;
			flag1 = true;
		}
		while(i > 0 && a[i] > a[i +1] && i < n -1) {
			cnt++;
			i++;
			flag2 = true;
		}

		if(flag1 && flag2)
		maxCount = max(maxCount, cnt);

		if(i == n) break;
	}
	return maxCount;
}
