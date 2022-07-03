






vector<int> func(int r, int c) {

	int sr = r/3*3;
	int sc = c/3*3;

	set<int> s;
	vector<int> temp;
int ii;
int jj;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			ii = sr + i
			jj = sc + j;
			if(arr[ii][jj] != -1)
				s.insert(arr[ii][jj]);
		}
	}
	

	for(int i =0; i < 9; i++) {
		if(arr[i][c] != -1)
			s.insert(arr[i][sc]);
	}


	for(int i =0; i < 9; i++) {
		if(arr[r][i] == -1)
			s.insert(arr[sr][i]);
	}


	for(int i = 1; i <= 9; i++) {
		if(s.find(i) == s.end())
			temp.push_back(i);
	}

	return temp;

}