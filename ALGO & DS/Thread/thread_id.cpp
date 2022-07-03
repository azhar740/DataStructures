#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
using namespace std;
mutex mutex_var;

void calSum(int &sum, int arr[], int n){
    std::thread::id this_id = std::this_thread::get_id();
    mutex_var.lock();
    sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }
    cout << "thread id " << this_id << endl;
    cout << "sum is " << sum << endl;
    mutex_var.unlock();
}

int main() {
    int arr[] = {1,2,3,43,5};
    int sum;
    std::vector<std::thread> threads;
    std::thread th1 = std::thread(calSum, std::ref(sum), arr, 5); // error if ref() is not there
    std::thread th2 = std::thread(calSum, std::ref(sum), arr, 5);
    cout << "thread_id is " << th1.get_id() << endl;
    cout << "thread_id is " << th2.get_id() << endl;
    th1.join();
    th2.join();
    //cout << "sum is " << sum << endl;
    return 0;
}