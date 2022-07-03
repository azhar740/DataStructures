/*

https://www.youtube.com/watch?v=w6dQQt10Dxo
*/
/*
Thread::joinable is an in-built function in C++ std::thread. 
It is an observer function which means it observes a state and 
then returns the corresponding output and checks whether the 
thread object is joinable or not. A thread object is said to be 
joinable if it identifies/represent an active thread of execution.
*/


/*
The CPU only executes what the OS tells it to, the OS is in charge of 
which threads run and how long they run before they are interrupted. 
There is some anti-starvation built into the scheduler so it should never 
completely lock the system but you can probably almost bring it to its 
knees if you just keep spawning as many threads as possible until you run out of 
memory or address space.

If we pretend that your program is the only program running then the ideal 
number of threads is the same as the number of CPU cores if the task is CPU limited. 
If the task is I/O limited or needs to wait on kernel objects then more threads might be ideal.

If you create thousands of threads then you will waste time context switching 
between them and your work will take longer to complete. Instead of manually starting 
new threads you should use the thread pool to perform your work so Windows itself can balance
 the optimum number of threads.
*/

#include <iostream>
#include <stdint.h>
#include <vector>
#include <thread>
#include <numeric>

void printVector(std::vector<uint64_t> vec) {
    for(uint64_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

void accumulateRange(uint64_t &sum, uint64_t start, uint64_t end) {
    sum = 0;
    for(uint64_t i = start; i < end; i++){
        sum += i;
    }
}

int main() {
    const int num_of_threads = 10;
    uint64_t number_of_elements = 1000 * 1000 * 1000;
    uint64_t step = number_of_elements / num_of_threads;
    std::vector<std::thread> threads;
    std::vector<uint64_t> partial_sums(num_of_threads);
    
    for(uint64_t i = 0; i < num_of_threads; i++) {
        threads.push_back(std::thread(accumulateRange, std::ref(partial_sums[i]), i*step, (i+1) * step));
    }
    
    for(std::thread &t : threads) {
        if(t.joinable())
            t.join();
    }
    
    uint64_t total = accumulate(partial_sums.begin(), partial_sums.end(), uint64_t(0));
    
    printVector(partial_sums);
    
    std::cout << "total " << total << std::endl;
    
}
