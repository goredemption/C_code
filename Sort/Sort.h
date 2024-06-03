#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// ��������
void InsertSort(int* a, int n);
// ϣ������
void ShellSort(int* a, int n);
// ѡ������
void SelectSort(int* a, int n);
// ������
void AdjustDown(int* a, int n, int root);
void HeapSort(int* a, int n);
//���������ӡ
void PrintArray(int* a, int n);
// ð������
void BubbleSort(int* a, int n);

// ��������ݹ�ʵ��
// ��������hoare�汾
int SinglePassSort1(int* a, int left, int right);
// ���������ڿӷ�
int SinglePassSort2(int* a, int left, int right);
// ��������ǰ��ָ�뷨
int SinglePassSort3(int* a, int left, int right);
void QuickSort(int* a, int left, int right);

// �������� �ǵݹ�ʵ��
void QuickSortNonR(int* a, int left, int right);
