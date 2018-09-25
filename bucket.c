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

//���δ��������������һ��Ԫ��ֵ
int GetMaxVal(int* arr, int len)
{
    
    int i, maxVal = arr[0]; //�������Ϊarr[0]
    
    for(i = 1; i < len; i++)  //�����Ƚϣ��ҵ���ľ͸�ֵ��maxVal
    {
        if(arr[i] > maxVal)
            maxVal = arr[i];
    }
    
    return maxVal;  //�������ֵ
}
 
//Ͱ����   ���������鼰�䳤��
void BucketSort(int* arr , int len)
{
    int tmpArrLen = GetMaxVal(arr , len) + 1;
    int tmpArr[tmpArrLen];  //��ÿ�Ͱ��С
    int i, j;
    
    for( i = 0; i < tmpArrLen; i++)  //��Ͱ��ʼ��
        tmpArr[i] = 0;
    
    for(i = 0; i < len; i++)   //Ѱ�����У����Ұ���Ŀһ��һ���ŵ���Ӧ��Ͱ��ȥ��
        tmpArr[ arr[i] ]++;
    
    for(i = 0, j = 0; i < tmpArrLen; i ++)
    {
        while( tmpArr[ i ] != 0) //��ÿ�����ǿյ�Ͱ�ӽ�������
        {
            arr[j ] = i;  //�Ӳ��ǿյ�Ͱ�������Ŀ�ٷŻ�ԭ���������С�
            j++;
            tmpArr[i]--;
        }
    }
}
 
int main()
{   //��������
    int arr_test[MAX_LEN] = { 8, 4, 2, 3, 5, 1, 6, 9, 0, 7 };
    
    //����ǰ��������
    Show( arr_test, MAX_LEN );
    //����
    BucketSort( arr_test,  MAX_LEN);
    //�������������
    Show( arr_test, MAX_LEN );
    
    return 0;
}

