#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

volatile unsigned int i;

int main(void){
	pid_t pid = fork();
	if (pid != 0){
        wait(NULL);
        printf("I am parent process with pid %d\n", getpid());
	}
	else {
        printf("I am child process with pid %d\n", getpid());
        volatile unsigned long i;
        for (int j=0; j<500; j++) {
            for(i=0;i<1000000UL;i++);
        }
    }
	return 0;
}
