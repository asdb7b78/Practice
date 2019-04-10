#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

int main(){
        int fd = 0;
        int len = 0;
        int ret;
        char buf[1024] = {0};

        //建立FIFO檔案
        ret = mkfifo("test" , 0664);
        if(ret != 0){
                perror("mkfifo error:");
                exit(-1);
        }

        //只寫方式開啟test
        fd = open("test", O_WRONLY);
        if(fd < 0){
                perror("open error");
        }
        puts("open fifo write");
        //向FIFO寫入資料
        while((len = read(STDIN_FILENO, buf, sizeof(buf))) > 0){
                write(fd, buf, len);
        }
        close(fd);
        return 0;
}
