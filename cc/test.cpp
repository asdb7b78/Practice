#include<cstdio>
#include<cstring>
#define M 1000000007

void build_table(){
    for (int i=0; i<10; i++) {
        table[0][i%3][i][(i==3)?1:0][(i==6)?1:0][(i==9)?1:0] = 1;
    }
    for (int a=1; a<1000; a++) {
        for (int i=0; i<10; i++) {
            for (int b=0; b<3; b++) {
                for (int c=0; c<11; c++) {
                    for (int d=0; d<3; d++) {
                        for (int e=0; e<3; e++) {
                            for (int f=0; f<3; f++) {
                                table[a][(b+i)%3][(a%2==0)?(c+i)%11:(c+11-i)%11][(i==3)?(d+1)%3:d][(i==6)?(e+1)%3:e][(i==9)?(f+1)%3:f] += table[a-1][b][c][d][e][f];
                                table[a][(b+i)%3][(a%2==0)?(c+i)%11:(c+11-i)%11][(i==3)?(d+1)%3:d][(i==6)?(e+1)%3:e][(i==9)?(f+1)%3:f] %= M;
                            }
                        }
                    }
                }
            }
        }
    }
    return;
}

int main(int argc, char *argv[]){
    build_table();
    int table[1000][3][11][3][3][3]={0};
    int n;
    scanf("%d", &n);
    if(n>0)
        printf("%d\n", table[n-1][0][0][0][0][0]);
    return 0;
}
