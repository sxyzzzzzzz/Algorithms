/*
 * =====================================================================================
 *
 *       Filename:  堆.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/31/2018 02:11:00 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>
 
#define MAX_LEN 10

int LEFT(int i)
{
    return 2*i+1;
}

int RIGHT(int i)
{
    return 2*i+2;
}

int PARENT(i)
{
    return i/2;
}

// 打印结果
void Show(int  arr[], int n)
{
    int i;
    for ( i=0; i<n; i++ )
        printf("%d  ", arr[i]);
    printf("\n");
}

//调整为最大堆
int max_heapify(int A[], int i, int heapsize)
{
    int l = LEFT(i);
    int r = RIGHT(i);
    int largest;

    if(l < heapsize && A[l] > A[i])
        largest = l;
    else
        largest = i;

    if(r < heapsize && A[r] > A[largest])
        largest = r;
    if(largest != i){
        A[i] = A[i] ^ A[largest];
        A[largest] = A[i] ^ A[largest];
        A[i] = A[i] ^ A[largest];
        max_heapify(A, largest, heapsize);
    }
}

//创建最大堆
void build_max_heap(int A[])
{
    int i;
    //这里除以2减1的原因：全二叉树的情况下，MAX_LEN/2-1为临界，之后都是叶子节点。例如下图：012是非叶子节点，3456是叶子节点。叶子节点比根节点多1。
    //这里的创建，是遍历所有的非叶子节点，做一个整体的调整。
    /*
            0
           / \
          1   2
         / \ / \
        3  4 5  6
    */
    for(i = MAX_LEN/2-1; i >=0; i--){
        max_heapify( A, i, MAX_LEN );
        Show(A, MAX_LEN);
    }

    //Show(A, MAX_LEN);
}

void heap_sort(int A[])
{
    int i;
    build_max_heap(A);
    for(i=MAX_LEN-1;i>=0;i--){
        A[0] = A[0] ^ A[i];
        A[i] = A[0] ^ A[i];
        A[0] = A[0] ^ A[i];
        /*这里做的操作，是把最大的数放到数组的最后。然后把剩下的数做一次最大堆调整，比如A[10]和A[0]互换，
         * 新的A[0]可能比其他的子节点小，调用下面的函数，就可以把这个数调整到合适的位置。保证调整后的A[0]
         * 还是A[0]~A[9]里最大的那个数。然后for循环，就可以继续把A[0]和A[9]换位置了。
        */
        max_heapify(A, 0, i);
        Show(A, MAX_LEN);
    }
}

int main()
{
    int arr_test[MAX_LEN] = { 8, 4, 2, 3, 5, 1, 6, 0, 7, 9};
    //排序前数组序列
    Show( arr_test, MAX_LEN );
    //排序
    heap_sort(arr_test);
    //排序后数组序列
    Show( arr_test, MAX_LEN );
}
