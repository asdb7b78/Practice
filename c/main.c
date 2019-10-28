#include <stdio.h>

int main(){
    char cc[20] = {"save 1 2 3"};
    char command[20];
    int a, b, c;
    a = b = c = 0;
    sscanf(cc, "%s%d%d%d", command, &a, &b, &c);
    printf("%s %d %d %d\n", command, a, b, c);
    return 0;
}
