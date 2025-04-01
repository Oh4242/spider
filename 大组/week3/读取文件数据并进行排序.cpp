#include<stdio.h>
#include<stdlib.h>
// 计数排序函数实现
void countSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    int *count = (int *)calloc(max + 1, sizeof(int));
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    int index = 0;
    for (int i = 0; i <= max; i++) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }
    free(count);
}
int main() {
    FILE *fp;
    int numData = 1000;
    int *arr = (int *)malloc(numData * sizeof(int));
    int i = 0;
    fp = fopen("test_data.txt", "r");
    if (fp == NULL) {
        perror("文件打开失败");
        return 1;
    }
    while (fscanf(fp, "%d", &arr[i]) != EOF) {
        i++;
    }
    fclose(fp);
    countSort(arr, numData);
    for (i = 0; i < numData; i++) {
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}
