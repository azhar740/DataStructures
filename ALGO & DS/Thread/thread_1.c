#include <stdio.h>
#include <pthread.h>
int a = 0;
void *func(void *var){
    int *id = (int *)var;
    static int b = 0;
    a = 7;
    b = 7;

    printf("the value of thread is: %d\n", *id);
    printf("the value of static variable is : %d\n", b);
    printf("the value of global variable is: %d\n", a);
    return 0;
}
int main() {

    pthread_t th;
    pthread_create(&th, NULL, func, (void *)&th);
    pthread_exit(NULL);

	return 0;
}
