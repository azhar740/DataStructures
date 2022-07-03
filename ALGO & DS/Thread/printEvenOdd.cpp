#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

mutex m;
int i = 1;
condition_variable cv;
void printEven(int n) {
    while(i < n){
	unique_lock<mutex> lg(m);
	cv.wait(lg, [] {return i%2 == 0?true: false;});
	cout << i << " ";
	i++;
	//if(i > n) return;
	cv.notify_one();
    }
	

}
void printOdd(int n) {
    while(i < n){
	unique_lock<mutex> ul(m);
	cv.wait(ul, [] {return i%2 == 1?true: false;});
	cout << i << " ";
	i++;
	//if(i > n) return;
	cv.notify_one();
    }
	


}

int main() {
	int n = 10;
	thread t1(printEven, n);
	thread t2 (printOdd, n);
	t1.join();
	t2.join();

}


#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

mutex m;
int i = 1;
condition_variable cv;
void printEven(int n) {
    while(i < n){
	unique_lock<mutex> ul1(m);
	cv.wait(ul1, [] {return i%2 == 0?true: false;});
	cout << i << " ";
	i++;
	//if(i > n) return;
	cv.notify_one();
    }
	

}
void printOdd(int n) {
    while(i < n){
	unique_lock<mutex> ul2(m);
	cv.wait(ul2, [] {return i%2 == 1?true: false;});
	cout << i << " ";
	i++;
	//if(i > n) return;
	cv.notify_one();
    }
	


}

int main() {
	int n = 10;
	thread t1(printEven, n);
	thread t2 (printOdd, n);

	thread t1(printEven, n);

	t1.join();
	t2.join();

}


unique_lock<mutex> ul1(m);
lock_guard<mutex> lg1(m);






