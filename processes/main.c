
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {

    pid_t cId;

    if (fork() == 0) {
        // exit(0); // child terminated
        printf("Hello from child\n");
        printf("Bye from child!!!\n");
    } else {
        printf("HP: hello from parent\n");
        cId = wait(NULL);
        printf("The child has been terminated!!\n");
    }

    printf("The child id: %d\n", cId);
    printf("The parent id: %d\n", getpid());

//    int id = fork();
//   // printf("The current id is %d\n", id);
//
//    if(id == 0) {
//        printf("Hello from child process\n");
//    } else {
//        printf("Hello from parent process\n");
//    }

    return 0;
}
