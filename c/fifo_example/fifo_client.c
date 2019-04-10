#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

int main(){
        int fd = 0;
        int len = 0;
        char buf[1024] = {0};

        //只讀開啟test
        fd = open("test", O_RDONLY);
        if(fd < 0){
                perror("open error:");
        }
        puts("open fifo read");

        //從管道中讀取資料
        while((len = read(fd, buf, sizeof(buf))) > 0){
                write(STDOUT_FILENO, buf, len);
        }
        
        //如果read返回0，說明讀到檔案末尾或對端已關閉
        if(len == 0){
                puts("peer is close or file end");
        }else{
                puts("read fifo");
        }

        close(fd);
        return 0;
}
