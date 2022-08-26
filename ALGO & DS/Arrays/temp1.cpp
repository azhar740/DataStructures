



------------------------------------------------------------------------

int **arr = (int**)malloc(r * sizeof(int*));

for(int i = 0; i < r; i++)
	arr[i] = (int*)malloc(c * sizeof(int));

--------------------------------------------------------------------
int *arr;

arr = (int *)malloc(r*c*sizeof(int));

for(int i = 0; i < r * c; i++)
		arr[i] = i+1;

for(int i = 0; i < r; i++)
	for(int i = 0; i < c; i++)
		cout << arr[ i*c + j] << " ";




int **arr;

arr = (int **)malloc(r* sizeof(int*))

for (int i = 0;)





void insertMap(string name, string phone) {
	map<string, string> mp;
	mp[name] = phone;

	mp.insert(make_pair(name, phone));
}


name --> 123
name ---> 567
--------------------------------------------
1->2->3->4

1 2 3 4 


----------------------


int g_status;


mutex m;

m.lock();
update(g_status);
m.unlock();



-g -o 








