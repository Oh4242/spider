#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    FILE *fp;
    int numData = 1000; // ��������
    int i;

    fp = fopen("test_data.txt","w");
    if (fp == NULL) {
        perror("�ļ���ʧ��");
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
