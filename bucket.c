/*
 * =====================================================================================
 *
 *       Filename:  bucket.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/25/2018 05:02:32 PM
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

//获得未排序数组中最大的一个元素值
int GetMaxVal(int* arr, int len)
{
    
    int i, maxVal = arr[0]; //假设最大为arr[0]
    
    for(i = 1; i < len; i++)  //遍历比较，找到大的就赋值给maxVal
    {
        if(arr[i] > maxVal)
            maxVal = arr[i];
    }
    
    return maxVal;  //返回最大值
}
 
//桶排序   参数：数组及其长度
void BucketSort(int* arr , int len)
{
    int tmpArrLen = GetMaxVal(arr , len) + 1;
    int tmpArr[tmpArrLen];  //获得空桶大小
    int i, j;
    
    for( i = 0; i < tmpArrLen; i++)  //空桶初始化
        tmpArr[i] = 0;
    
    for(i = 0; i < len; i++)   //寻访序列，并且把项目一个一个放到对应的桶子去。
        tmpArr[ arr[i] ]++;
    
    for(i = 0, j = 0; i < tmpArrLen; i ++)
    {
        while( tmpArr[ i ] != 0) //对每个不是空的桶子进行排序。
        {
            arr[j ] = i;  //从不是空的桶子里把项目再放回原来的序列中。
            j++;
            tmpArr[i]--;
        }
    }
}
 
int main()
{   //测试数据
    int arr_test[MAX_LEN] = { 8, 4, 2, 3, 5, 1, 6, 9, 0, 7 };
    
    //排序前数组序列
    Show( arr_test, MAX_LEN );
    //排序
    BucketSort( arr_test,  MAX_LEN);
    //排序后数组序列
    Show( arr_test, MAX_LEN );
    
    return 0;
}

