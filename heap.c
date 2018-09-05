/*
 * =====================================================================================
 *
 *       Filename:  ��.c
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

// ��ӡ���
void Show(int  arr[], int n)
{
    int i;
    for ( i=0; i<n; i++ )
        printf("%d  ", arr[i]);
    printf("\n");
}

//����Ϊ����
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

//��������
void build_max_heap(int A[])
{
    int i;
    //�������2��1��ԭ��ȫ������������£�MAX_LEN/2-1Ϊ�ٽ磬֮����Ҷ�ӽڵ㡣������ͼ��012�Ƿ�Ҷ�ӽڵ㣬3456��Ҷ�ӽڵ㡣Ҷ�ӽڵ�ȸ��ڵ��1��
    //����Ĵ������Ǳ������еķ�Ҷ�ӽڵ㣬��һ������ĵ�����
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
        /*�������Ĳ������ǰ��������ŵ���������Ȼ���ʣ�µ�����һ�����ѵ���������A[10]��A[0]������
         * �µ�A[0]���ܱ��������ӽڵ�С����������ĺ������Ϳ��԰���������������ʵ�λ�á���֤�������A[0]
         * ����A[0]~A[9]�������Ǹ�����Ȼ��forѭ�����Ϳ��Լ�����A[0]��A[9]��λ���ˡ�
        */
        max_heapify(A, 0, i);
        Show(A, MAX_LEN);
    }
}

int main()
{
    int arr_test[MAX_LEN] = { 8, 4, 2, 3, 5, 1, 6, 0, 7, 9};
    //����ǰ��������
    Show( arr_test, MAX_LEN );
    //����
    heap_sort(arr_test);
    //�������������
    Show( arr_test, MAX_LEN );
}
