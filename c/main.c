#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void catch(int snum){   
	printf("divided by 0\n");
    return;
}

int main(int argc, char *argv[]){
	signal(SIGFPE, catch);
    for (int i=0; i<1; i++) {
        printf("%d\n", 1000/i);
    }
	return 0;
}
