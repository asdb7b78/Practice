#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>

struct process{
    char n[32];
    unsigned int r, t;
};

char *FRSP[] = {"FIFO", "RR", "SJF", "PSJF"};

int main(void) {
    
    char policy[8]={0};
    
    int N, policy_num = -1;
    
    scanf("%s%d", policy, &N);
    
    struct process *p = (struct process *)malloc(sizeof(struct process));
    
    for (int i=0; i<N; i++) {
        scanf("%s%u%u", p[i].n, &p[i].r, &p[i].t);
    }
    
    for (int i=0; i<4; i++) {
        if (strcmp(policy, FRSP[i]) == 0) {
            policy_num = i;
        }
    }
    
    if (policy_num < 0) {
        puts("wrong policy\n");
        exit(-1);
    }
    
    int time = 0, done = (1 << N)-1;
    
    while (done != 0) {
        int todo = -1;
        for (int i=0; i<N; i++) {
            if ((done & 1<<i) != 0 && p[i].r <= time) {
                switch (policy_num) {
                    case 0:
                        todo = i;
                        time += p[todo].t;
                        done -= 1<<todo;
                        printf("%s : st = %d, ft = %d\n", p[todo].n, p[todo].r, time);
						break;
                    
					case 1:
                        todo = i;
                        if (p[todo].t > 500) {
                            p[todo].t -= 500;
                            time += 500;
                        }
                        else {
                            time += p[todo].t;
                            done -= 1<<todo;
                        	printf("%s : st = %d, ft = %d\n", p[todo].n, p[todo].r, time);
                        }
                        break;
                        
                    case 2: case 3:
                        if (todo < 0 || p[i].t < p[todo].t) {
                            todo = i;
                        }
                        break;
                }
            }
        }
        if (todo < 0) {
            time++;
        }
        else{
            switch (policy_num) {
                case 2:
                    time += p[todo].t;
                    done -= 1<<todo;
                    printf("%s : st = %d, ft = %d\n", p[todo].n, p[todo].r, time);
                    break;
                    
                case 3:
                    p[todo].t--;
                    time++;
                    if (p[todo].t == 0) {
                        done -= 1<<todo;
                        printf("%s : st = %d, ft = %d\n", p[todo].n, p[todo].r, time);
                    }
                    break;
                    
                default:
                    break;
            }
        }
    }
    return 0;
}

