#include <stdio.h>
#include <math.h>

int main(){
    char buff[100]; // 宣告字元陣列
    sprintf (buff, "%d", 123); // 字串格式化 (數字轉字串)
    printf ("%s\n", buff); // 輸出 123 的字串 (非數字)
	return 0;
}
