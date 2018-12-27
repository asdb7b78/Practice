#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main(int argc, char** argv){
	void catch(int);
	int a;

	signal(SIGSEGV, catch);
	a = *(int *)0;
}

void catch(int snum){
	printf("got signal %d\n", snum);
	exit(0);
}
