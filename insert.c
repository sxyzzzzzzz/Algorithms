/*
 * =====================================================================================
 *
 *       Filename:  insertion_sort.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/23/2018 02:19:35 PM
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

int main()
{
    int A[] = {5,2,4,6,1,3};
    int i, j, k;

    Show(A, sizeof(A)/sizeof(int));

    for(j=1; j<sizeof(A)/sizeof(int); j++){
        int key = A[j];
        i = j-1;
        while(i >= 0 && A[i] > key ){
            A[i+1] = A[i];
            i = i - 1;
        }
        //printf("i=%d, key=%d\n", i, key);
        A[i+1] = key;
    }

    Show(A, sizeof(A)/sizeof(int));
}
