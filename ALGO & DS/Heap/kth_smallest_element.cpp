#include<bits/stdc++.h>
using namespace std;
class MinHeap{
    int *harr;
    int heap_size;
    public:
    void heapify(int i);
    void build_heap(int *arr, int size);
    void swap(int i, int j);
    int extract_min();
};
void MinHeap::swap(int i, int j){
    int temp = harr[i];
    harr[i] = harr[j];
    harr[j] = temp;
}
void MinHeap::heapify(int k){
    int l = 2 * k + 1;
    int r = 2 * k + 2;
    int smallest = k;
    if(l < heap_size && harr[l] < harr[k]) smallest = l;
    else smallest = k;
    if(r < heap_size && harr[r] < harr[smallest]) smallest = r;
    if( smallest != k){
        swap(smallest, k);
        heapify(smallest);
    }
}
void MinHeap::build_heap(int heap[], int size){
    harr = heap;
    heap_size = size;
    for(int i = heap_size/2 - 1; i >= 0; i--){
        heapify(i);
    }
} 
int MinHeap::extract_min(){
    int ans = harr[0];
    harr[0] = harr[heap_size - 1];
    heap_size = heap_size - 1;
    heapify(0);
    return ans;
}
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int heap[n];
	    for(int i = 0; i < n; i++) cin >> heap[i];
	    MinHeap h;
	    h.build_heap(heap, n);
	    int ans, k;
	    cin >> k;
	    for(int i = 0; i < k; i++){
	        ans = h.extract_min();
	    }
	    cout << ans << endl;
	}
	return 0;
}