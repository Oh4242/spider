#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    FILE *fp;
    int numData = 1000; // 数据数量
    int i;

    fp = fopen("test_data.txt","w");
    if (fp == NULL) {
        perror("文件打开失败");
        return 1;
    }

    srand(time(NULL));
    for (i = 0; i < numData; i++) {
        int num = rand();
        fprintf(fp,"%d\n",num);
    }

    fclose(fp);
    return 0;
}
