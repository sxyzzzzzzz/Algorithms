/*
 * =====================================================================================
 *
 *       Filename:  快速排序.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/05/2018 11:00:31 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */


#include <stdio.h>
#include "util.h"

#define MAX_LEN 10

int partition(int A[], int start, int end)
{
    int key = A[end];
    int i = start-1;
    int j;

    for(j=start; j<end; j++){
        if(A[j]<=key){
            i++;
            if(i == j) continue;
            printf("1>> A[%d](%d)<-->A[%d](%d)\n", i, A[i], j, A[j]);
            A[i] = A[i] ^ A[j];
            A[j] = A[i] ^ A[j];
            A[i] = A[i] ^ A[j];
        }
    }
    if(i+1 != end){
        printf("2>> A[%d](%d)<-->A[%d](%d)\n", i+1, A[i+1], j, A[j]);
        A[i+1] = A[i+1] ^ A[end];
        A[end] = A[i+1] ^ A[end];
        A[i+1] = A[i+1] ^ A[end];
    }

    Show( A, MAX_LEN );
    printf("retrun %d\n", i+1);
    return i+1;
}

void quick_sort(int A[], int start, int end)
{
    int q;

    if(start < end){
        q = partition(A, start, end);
        quick_sort(A, start, q-1);
        quick_sort(A, q+1, end);
    }
}

int main()
{
    int arr_test[MAX_LEN] = { 6, 4, 9, 3, 5, 1, 8, 0, 7, 2};
    //排序前数组序列
    Show( arr_test, MAX_LEN );
    //排序
    quick_sort(arr_test, 0, MAX_LEN-1);
    //排序后数组序列
    Show( arr_test, MAX_LEN );
}
