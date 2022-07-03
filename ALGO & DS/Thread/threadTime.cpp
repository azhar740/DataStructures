#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void foo() {
    std::cout << "coming in foo..\n";
    this_thread::sleep_for(chrono::seconds(3));
}

void bar() {
    std::cout << "coming in bar..\n";
    this_thread::sleep_for(chrono::seconds(3));
}

int main() {
    
    auto start = std::chrono::high_resolution_clock::now();
    
    std::cout << "starting first helper...\n";
    std::thread helper1(foo);
    
    std::cout << "starting second helper...\n";
    
    std::thread helper2(bar);
    
    auto stop = std::chrono::high_resolution_clock::now();
    
    
    
    cout << "Wating for helper to finish\n";
    helper1.join();
    helper2.join();
    
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    
    cout << "duration " << duration.count() << "\n";
    
    cout << "Done\n";
	
	return 0;
}