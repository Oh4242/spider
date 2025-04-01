#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ��������
void InsertSort(int s[], int n) {
    for (int i = 1; i < n; i++) {
        int k = s[i];
        int j = i - 1;
        while (j >= 0 && s[j] > k) {
            s[j + 1] = s[j];
            j--;
        }
        s[j + 1] = k;
    }
}

// �鲢����ĺϲ�����
void merge(int s[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        L[i] = s[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = s[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            s[k] = L[i];
            i++;
        } else {
            s[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        s[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        s[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

// �鲢����
void Mergesort(int s[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        Mergesort(s, left, mid);
        Mergesort(s, mid + 1, right);

        merge(s, left, mid, right);
    }
}

// �鲢�����װ����
void MergeSortWrapper(int s[], int n) {
    Mergesort(s, 0, n - 1);
}

// ��������ķ�������
int pin(int s[], int low, int high) {
    int goal = s[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (s[j] < goal) {
            i++;
            int temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }
    }
    int temp = s[i + 1];
    s[i + 1] = s[high];
    s[high] = temp;
    return (i + 1);
}

// ��������
void Quicksort(int s[], int low, int high) {
    if (low < high) {
        int pi = pin(s, low, high);

        Quicksort(s, low, pi - 1);
        Quicksort(s, pi + 1, high);
    }
}

// ���������װ����
void QuickSortWrapper(int s[], int n) {
    Quicksort(s, 0, n - 1);
}

// ��������
void Countsort(int s[], int n) {
    if (n <= 1) return;

    int max = s[0], min = s[0];
    for (int i = 1; i < n; i++) {
        if (s[i] > max) max = s[i];
        if (s[i] < min) min = s[i];
    }

    int range = max - min + 1;
    int *count = (int *)calloc(range, sizeof(int));
    int *output = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        count[s[i] - min]++;

    for (int i = 1; i < range; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[s[i] - min] - 1] = s[i];
        count[s[i] - min]--;
    }

    for (int i = 0; i < n; i++)
        s[i] = output[i];

    free(count);
    free(output);
}

// ��ȡ�����е����ֵ
int getMax(int s[], int n) {
    int mx = s[0];
    for (int i = 1; i < n; i++) {
        if (s[i] > mx) {
            mx = s[i];
        }
    }
    return mx;
}

// ��������ļ�������������
void countingSort(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// ��������
void Radixsort(int s[], int n) {
    int m = getMax(s, n);

    for (int exp = 1; m / exp > 0; exp *= 10)
        countingSort(s, n, exp);
}

// ���Բ�ͬ�����㷨��ʱ��
void countime(void (*sort)(int[], int), const char *sortname) {
    int datasizes[] = {10000, 50000, 200000};
    int i, j;
    clock_t start, end;
    double times;

    for (i = 0; i < 3; i++) {
        int *arr = (int *)malloc(datasizes[i] * sizeof(int));
        // �����������
        srand(time(NULL));
        for (j = 0; j < datasizes[i]; j++) {
            arr[j] = rand();
        }

        start = clock();
        sort(arr, datasizes[i]);
        end = clock();

        times = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("%s ���� %d ��������ʱ %f ��\n", sortname, datasizes[i], times);

        free(arr);
    }
}

int main() {
    int s[] = {23, 43, 66, 234, 645, 2, 5, 8, 444, 332, 9, 3, 10};
    int n = sizeof(s) / sizeof(s[0]);

    printf("����ǰ��\n");
    for (int i = 0; i < n; i++) {
        printf("%d, ", s[i]);
    }
    printf("\n\n");

    printf("��ѡ��Ҫʹ�õ����򷽷���\n");
    printf("*************************************************\n");
    printf("*                 1.��������                    *\n");
    printf("*                 2.�鲢����                    *\n");
    printf("*                 3.��������                    *\n");
    printf("*                 4.��������                    *\n");
    printf("*                 5.��������                    *\n");
    printf("*                 6.�˳�����                    *\n");
    printf("*************************************************\n");

    int a;
    scanf("%d", &a);

    int *sorted = (int *)malloc(n * sizeof(int));
    memcpy(sorted, s, n * sizeof(int));

    switch (a) {
        case 1:
            InsertSort(sorted, n);
            countime(InsertSort, "��������");
            break;
        case 2:
            MergeSortWrapper(sorted, n);
            countime(MergeSortWrapper, "�鲢����");
            break;
        case 3:
            QuickSortWrapper(sorted, n);
            countime(QuickSortWrapper, "��������");
            break;
        case 4:
            Countsort(sorted, n);
            countime(Countsort, "��������");
            break;
        case 5:
            Radixsort(sorted, n);
            countime(Radixsort, "��������");
            break;
        case 6:
            free(sorted);
            return 0;
        default:
            printf("��Ч��ѡ��\n");
            free(sorted);
            return 1;
    }

    printf("�����\n");
    for (int i = 0; i < n; i++) {
        printf("%d, ", sorted[i]);
    }
    printf("\n");

    free(sorted);
    system("pause");
    return 0;
}
