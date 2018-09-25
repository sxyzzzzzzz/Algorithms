/*
 * =====================================================================================
 *
 *       Filename:  radix.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/25/2018 04:29:21 PM
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
#define RADIX_10 10    //整形排序
#define KEYNUM_31 10     //关键字个数，这里为整形位数

// 找到num的从低到高的第pos位的数据
int get_num_in_pos(int num,int pos)
{
    int i, temp = 1;
    for (i = 0; i < pos - 1; i++)
        temp *= 10;

    return (num / temp) % 10;
}

void radix_sort(int* pDataArray, int iDataNum)
{   
    int pos, i, j, k, *radixArrays[RADIX_10];    //分别为0~9的序列空间    
    for (i = 0; i < 10; i++){       
        radixArrays[i] = (int *)malloc(sizeof(int) * (iDataNum + 1));       
        radixArrays[i][0] = 0;    //index为0处记录这组数据的个数    
    }       

    for (pos = 1; pos <= KEYNUM_31; pos++){    //从个位开始到31位           
        for (i = 0; i < iDataNum; i++){    //分配过程                   
            int num = get_num_in_pos(pDataArray[i], pos);          
            int index = ++radixArrays[num][0];          
            radixArrays[num][index] = pDataArray[i];        
        }               
        for (i = 0, j = 0; i < RADIX_10; i++){    //收集                 
            for (k = 1; k <= radixArrays[i][0]; k++)                
                pDataArray[j++] = radixArrays[i][k];            
            radixArrays[i][0] = 0;    //复位        
        }   
    }
} 

int main()
{   
    //测试数据    
    int arr_test[MAX_LEN] = { 83, 14, 22, 53, 15, 61, 26, 79, 90, 57 };    
    //排序前数组序列    
    Show( arr_test, MAX_LEN);    
    radix_sort( arr_test, MAX_LEN);    
    //排序后数组序列    
    Show( arr_test, MAX_LEN);    
    return 0;
}


