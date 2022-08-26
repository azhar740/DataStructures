


class ABC{}

ABC *ptr = new ABC[100]
when we say new ABC[100], compiler can get the information about how many objects that needs to be allocated(here it is 100) 
and will call the constructor for each of the objects created

but correspondingly if we simply use delete ptr for this case, compiler will not know how many objects that ptr is pointing to
and will end up calling of destructor and deleting memory for only 1 object(leaving the invocation of destructors and deallocation of remaining 99 objects). 
Hence there will be a memory leak.

so we need to use delete [] ptr in this case.
-----------------------------------------------------------------------
#define my_sizeof(type) (char*)(&type + 1) - (char*)(&type)

int x;
my_sizeof(x);
------------------------------------------------------------------------

int **arr = (int**)malloc(r * sizeof(int*));

for(int i = 0; i < r; i++)
	arr[i] = (int*)malloc(c * sizeof(int));

-------------------------------------------------------------------------
int *arr;

arr = (int *)malloc(r*c*sizeof(int));

for(int i = 0; i < r * c; i++)
		arr[i] = i+1;

for(int i = 0; i < r; i++)
	for(int i = 0; i < c; i++)
		cout << arr[ i*c + j] << " ";

-------------------------------------------------------------------------
#include <iostream>
#include <map>

using namespace std;

int main() {
	map<string, string> mp;
	mp.insert(make_pair("Azhar", "9900476396"));
	mp.insert(make_pair("Azhar", "9997774607")); // Will not insert as key is already there.
	
	map<string, string>::iterator it;
	for(it = mp.begin(); it != mp.end(); ++it)
	    cout << it->first << " " << it->second << "\n";
	return 0;
}

o/p--
Azhar 9900476396
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








