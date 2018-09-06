/*
 * =====================================================================================
 *
 *       Filename:  count.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/06/2018 02:02:47 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"

#define MAX_LEN 10

void counting_sort(int A[], int B[], int k)
{
    int i;
    int *C = (int *)malloc(sizeof(int)*k);

    memset(C, 0, sizeof(int)*k);

    /* 统计数组A中每个值为i的元素出现的次数*/
    for(i=0;i<MAX_LEN;i++)
        C[A[i]] += 1;

    /* 确定值为i的元素在数组c中出现的位置*/
    for(i=1;i<k;i++)
        C[i] = C[i] + C[i-1];

     /* 对A数组，从后向前确定每个元素所在的最终位置 */
    for(i=MAX_LEN-1;i>=0;i--){
        B[C[A[i]]-1] = A[i];
        C[A[i]] -= 1;
    }

    free(C);
}

int main()
{
    int i, largest = 0;
    int arr_test[MAX_LEN] = { 8, 4, 2, 3, 5, 1, 6, 0, 7, 100};
    int arr_out[MAX_LEN] = {0};
   
    for(i=0;i<MAX_LEN;i++){
        if(arr_test[i] > largest)
            largest = arr_test[i];
    }

    //排序前数组序列
    Show( arr_test, MAX_LEN );
    //排序
    counting_sort(arr_test, arr_out, largest+1);
    //排序后数组序列
    Show( arr_out, MAX_LEN );
}

