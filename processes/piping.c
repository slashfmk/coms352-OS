//
// Created by Yannick Fumukani on 8/31/22.
//

#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <printf.h>

int main() {

    // fd[0] - read
    // fd[1] - write
    int fd[2];

    if (pipe(fd) == -1) {
        printf("An error occurred while opening a pipe\n");
        return -1;
    }

    int forkResult = fork();

    if (forkResult == -1) {
        printf("There was an error when forking\n");
        return 4;
    }

    if (forkResult == 0) {
        // Since, we are not reading fd[0] has to be close
        close(fd[0]);

        int x;
        // Display and prompt the user fot a number
        printf("Please enter a number ");
        scanf("%d", &x);

        // write in the current process's pipe
        if (write(fd[1], &x, sizeof(int)) == -1) {
            printf("An error occur while writing");
        }
        // close the pipe writing
        close(fd[1]);

    } else {

        close(fd[1]); // close the write mode of the parent process
        int y;

        if (read(fd[0], &y, sizeof(int)) == -1) {
            printf("An error occurred while reading from the process");
        }
        close(fd[0]);

        y -= 2022;

        printf("Your age is %d, Got %d from child process \n", abs(y), (y + 2022));

    }

    return 0;
}
