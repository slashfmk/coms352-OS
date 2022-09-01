//
// Created by Yannick Fumukani on 8/31/22.
//

#include <unistd.h>
#include <printf.h>
#include <sys/wait.h>

int main() {

    int id = fork();

    if(id == 0) {
        printf("current id: %d\n", getpid());
        printf("waiting ...\n");
        sleep(2);
        printf("Let's start counting, \n");

        for(int i = 0; i <= 10; i++) {
            printf("%d seconds: child \n", i);
            sleep(1);
        }
    } else {
        int childId = wait(NULL);

        printf("%d process child terminated!\n", childId);

        for(int i = 20; i <= 30; i++) {
            printf("%d seconds: parents \n", i);
            sleep(1);
        }
    }

    int res = wait(NULL);

    if(res == -1) {
        printf("No children to wait for!!\n");
    } else {
        printf("%d process terminated successfully!!\n", res);
    }

//    if(id != 0) {
//        printf("");
//    }

    return 0;
}