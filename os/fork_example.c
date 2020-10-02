#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>       /* needed to use wait() */  


int main(int argc, char const *argv[])
{
    printf("before the fork system call\n");
    int id =  fork();

    if (id > 0) {
        printf("%d", wait(0));
        printf("\nparent process\n");
        exit(0);
    }else {
        printf("child process calling helloWorld.out\n");
        execlp("./helloWorld", "", NULL);
        printf("program is not present at the destination");
        exit(0);

    }
    
    printf("after the fork system call\n");
    return 0;
}
