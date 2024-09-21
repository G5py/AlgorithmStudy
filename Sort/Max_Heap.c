#include<stdio.h>

int vals[] = {0, 9, 7, 6, 5, 4, 3, 2, 2, 1, 3};

typedef struct heap//Max_heap
{
    int arr[20];
    int cnt;
}heap;

void Heap_insertion(heap *he, int key)
{
    (he->cnt)++;
    he->arr[he->cnt] = key;

    int index_of_key = he->cnt;
    int half = (int)(index_of_key/2);
    while (he->arr[index_of_key] > he->arr[half] && index_of_key != 1)
    {
        int tmp = he->arr[half];
        he->arr[half] = he->arr[index_of_key];
        he->arr[index_of_key] = tmp;

        index_of_key = (int)(index_of_key/2);
        half = (int)(index_of_key/2);
    }
}

int Heap_Delete(heap *he)
{
    int ret = he->arr[1];
    he->arr[1] = he->arr[he->cnt];
    (he->cnt)--;

    int i = 1;
    int il = i*2;
    int ir = i*2+1;
    while (he->arr[il] > he->arr[i] || he->arr[ir] > he->arr[i] && ir <= he->cnt)
    {
        int ig;
        ig = (he->arr[il] > he->arr[ir]) ? il : ir;

        int tmp;
        tmp = he->arr[ig];
        he->arr[ig] = he->arr[i];
        he->arr[i] = tmp;

        i = ig;
        il = i*2;
        ir = i*2+1;
    }

    return ret;
}

int main()
{
    heap he;
    he.cnt = 0;
    for (int i = 1; i < 11; i++)
    {
        Heap_insertion(&he, vals[i]);
    }

    for (int i  = 1; i < 11; i++)
    {
        printf("%d ", he.arr[i]);
    }
    printf("\n");

    Heap_insertion(&he, 8);

    for (int i = 1; i <= he.cnt; i++)
    {
        printf("%d ", he.arr[i]);
    }
    printf("\n");

    Heap_Delete(&he);
    for (int i = 1; i <= he.cnt; i++)
    {
        printf("%d ", he.arr[i]);
    }
    printf("\n");

    return 0;
}
