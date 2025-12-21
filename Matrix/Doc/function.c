#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../Lib/Matrix.h"

int get_random(int a, int b)  // 获得[a, b]的随机整数
{
  return rand() % (b - a + 1) + a;
}

void InitialMatrix(Matrix* T, int row, int col)  // 只分配空间不初始化；
{
  int i = 0;

  if (row <= 0 || col <= 0) {
    printf("error, 矩阵行或列未大于0\n");
    return;
  }
  if (T == NULL) {
    printf("error, 矩阵未分配内存\n");
    return;
  }
  T->row = row;
  T->col = col;
  T->mat = (double**)malloc(row * sizeof(double*));

  for (i = 0; i < row; i++) {
    T->mat[i] = (double*)malloc(col * sizeof(double));
  }

  return;
}

void InitialMatrixZero(Matrix* T, int row, int col)  // 初始化为0
{
  int i = 0;
  int j = 0;

  InitialMatrix(T, row, col);
  if (T->mat == NULL) {
    return;
  }

  for (i = 0; i < row; i++) {
    for (j = 0; j < col; j++) {
      T->mat[i][j] = 0.0;
    }
  }

  return;
}

void InitialMatrixRand(Matrix* T, int row, int col)  // 初始化为50以内随机正整数
{
  int i = 0;
  int j = 0;

  InitialMatrix(T, row, col);
  if (T->mat == NULL) {
    return;
  }

  for (i = 0; i < row; i++) {
    for (j = 0; j < col; j++) {
      T->mat[i][j] = get_random(1, 49);
    }
  }

  return;
}

void InputMatrix(Matrix* T)  // 键盘输入矩阵
{
  printf("请输入%d行%d列矩阵元素(按行输入,空格分隔):\n", T->row, T->col);
  if (T->mat == NULL) {
    printf("矩阵未初始化\n");
    return;
  }

  int i = 0;
  int j = 0;

  for (i = 0; i < T->row; i++) {
    for (j = 0; j < T->col; j++) {
      scanf("%lf", &(T->mat[i][j]));
    }
  }

  return;
}

void DestroyMatrix(Matrix* T)  // 释放矩阵空间
{
  int i = 0;

  if (T == NULL || T->mat == NULL) {
    return;
  }

  for (i = 0; i < T->row; i++) {
    free(T->mat[i]);
  }
  free(T->mat);
  T->row = T->col = 0;
  T->mat = NULL;

  return;
}

void PrintfMatrix(Matrix* T)  // 矩阵输出
{
  if (T == NULL || T->mat == NULL) {
    printf("该矩阵未初始化\n");
    return;
  }

  int i = 0;
  int j = 0;

  for (i = 0; i < T->row; i++) {
    for (j = 0; j < T->col; j++) {
      printf("%8.2f ", T->mat[i][j]);
    }
    printf("\n");
  }

  return;
}

int AddMatrix(Matrix* A, Matrix* B, Matrix* C)  // 矩阵加， C = A + B
{
  if (A->col != B->col || A->row != B->row) {
    printf("矩阵维度不匹配，无法相加！\n");
    return 0;
  }
  InitialMatrixZero(C, A->row, A->col);

  if (C->mat == NULL) {
    return 0;
  }

  int i = 0;
  int j = 0;

  for (i = 0; i < C->row; i++) {
    for (j = 0; j < C->col; j++) {
      C->mat[i][j] = A->mat[i][j] + B->mat[i][j];
    }
  }

  return 1;
}

int MinusMatrix(Matrix* A, Matrix* B, Matrix* C)  // 矩阵减， C = A - B
{
  if (A->col != B->col || A->row != B->row) {
    printf("矩阵维度不匹配，无法相减！\n");
    return 0;
  }

  InitialMatrixZero(C, A->row, A->col);

  if (C->mat == NULL) {
    return 0;
  }

  int i = 0;
  int j = 0;

  for (i = 0; i < C->row; i++) {
    for (j = 0; j < C->col; j++) {
      C->mat[i][j] = A->mat[i][j] - B->mat[i][j];
    }
  }

  return 1;
}

int MultiMatrix(Matrix* A, Matrix* B, Matrix* C)  // 矩阵乘法，C = A * B
{
  if (A->col != B->row) {
    printf("矩阵维度不匹配，无法相乘！\n");
    return 0;
  }
  InitialMatrixZero(C, A->row, B->col);
  if (C->mat == NULL) {
    return 0;
  }

  int i = 0;
  int j = 0;
  int k = 0;

  for (i = 0; i < C->row; i++) {
    for (j = 0; j < C->col; j++) {
      for (k = 0; k < A->col; k++) {
        C->mat[i][j] += A->mat[i][k] * B->mat[k][j];
      }
    }
  }

  return 1;
}

double MeanMatrix(Matrix* T)  // 矩阵元素均值
{
  double sum = 0.0;
  if (T == NULL || T->mat == NULL) {
    printf("该矩阵未初始化\n");
    return NAN;
  }
  int i = 0;
  int j = 0;
  for (i = 0; i < T->row; i++) {
    for (j = 0; j < T->col; j++) {
      sum += T->mat[i][j];
    }
  }

  return sum / (T->row * T->col);
}

int SubMatrix(Matrix* T1, Matrix* T2, int BeginRow, int BeginCol, int EndRow,
              int EndCol)  // 求T1的子矩阵T2
{
  if (T1 == NULL || T1->mat == NULL) {
    printf("该矩阵未初始化\n");
    return 0;
  }
  if (BeginRow > T1->row || EndRow > T1->row || BeginCol > T1->col ||
      EndCol > T1->col || BeginRow > EndRow || BeginCol > EndCol ||
      BeginRow < 1 || EndRow < 1 || EndCol < 1 || BeginCol < 1) {
    printf("子矩阵选取非法\n");
    return 0;
  }
  InitialMatrixZero(T2, EndRow - BeginRow + 1, EndCol - BeginCol + 1);
  if (T2->mat == NULL) {
    printf("子矩阵未初始化\n");
    return 0;
  }
  int i = 0;
  int j = 0;
  for (i = 0; i < T2->row; i++) {
    for (j = 0; j < T2->col; j++) {
      T2->mat[i][j] = T1->mat[BeginRow + i - 1][BeginCol + j - 1];
    }
  }
  return 1;
}

double MaxMatrix(Matrix* T)  // 矩阵元素最大值
{
  if (T == NULL || T->mat == NULL) {
    printf("该矩阵未初始化\n");
    return NAN;
  }
  double max = T->mat[0][0];
  int i = 0;
  int j = 0;
  for (i = 0; i < T->row; i++) {
    for (j = 0; j < T->col; j++) {
      if (T->mat[i][j] > max) {
        max = T->mat[i][j];
      }
    }
  }
  return max;
}

void TransMatrix(Matrix* T)  // 矩阵转置
{
  if (T == NULL || T->mat == NULL) {
    printf("该矩阵未初始化\n");
    return;
  }

  Matrix tem;
  tem.row = T->col;
  tem.col = T->row;

  InitialMatrixZero(&tem, tem.row, tem.col);
  for (int i = 0; i < T->row; i++) {
    for (int j = 0; j < T->col; j++) {
      tem.mat[j][i] = T->mat[i][j];
    }
  }
  DestroyMatrix(T);
  T->mat = tem.mat;
  T->col = tem.col;
  T->row = tem.row;
  tem.mat = NULL;
  tem.col = 0;
  tem.row = 0;
}

void NormMatrix(Matrix* T)  // 矩阵归一化
{
  if (T == NULL || T->mat == NULL) {
    printf("该矩阵未初始化\n");
    return;
  }

  double max_abs = 0.0;
  for (int i = 0; i < T->row; i++) {
    for (int j = 0; j < T->col; j++) {
      double current_abs = fabs(T->mat[i][j]);
      if (current_abs > max_abs) {
        max_abs = current_abs;  // 取元素绝对值的最大值
      }
    }
  }

  if (max_abs < 1e-9) {
    printf("全零矩阵无需归一化\n");
    return;
  }

  for (int i = 0; i < T->row; i++) {
    for (int j = 0; j < T->col; j++) {
      T->mat[i][j] /= max_abs;
    }
  }
}

double Determinant(Matrix* T)  // 求行列式
{
  if (T == NULL || T->mat == NULL) {
    printf("该矩阵未初始化\n");
    return NAN;
  }

  if (T->row != T->col) {
    printf("非方阵无法计算行列式\n");
    return NAN;
  }

  if (T->row == 1) {
    return T->mat[0][0];
  }
  Matrix Aij;  // 余子式
  Aij.mat = NULL;
  double det = 0.0;
  int i = 0;  // 取出元素的列数
  int z = 0;

  for (i = 0; i < T->col; i++) {
    int x = 0;  // 余子式行数
    int y = 0;  // 余子式列数
    InitialMatrixZero(&Aij, T->row - 1, T->col - 1);
    for (int i1 = 1; i1 < T->row; i1++) {
      y = 0;
      for (int i2 = 0; i2 < T->col; i2++) {
        if (i2 == i) {
          continue;
        }
        Aij.mat[x][y] = T->mat[i1][i2];  // 按第一行展开的余子式
        y++;
      }
      x++;
    }
    if (i % 2 == 0) {
      z = 1;
    } else {
      z = -1;
    }
    det += T->mat[0][i] * z * Determinant(&Aij);
    DestroyMatrix(&Aij);
  }
  return det;
}

void AdjugateMatrix(Matrix* T, Matrix* adj)  // 求伴随矩阵
{
  if (T == NULL || T->mat == NULL) {
    printf("该矩阵未初始化\n");
    return;
  }
  if (T->row != T->col) {
    printf("非方阵无法计算伴随矩阵\n");
    return;
  }
  DestroyMatrix(adj);
  if (T->row == 1) {
    InitialMatrixZero(adj, 1, 1);
    adj->mat[0][0] = 1.0;
    return;
  }

  Matrix Aij;  // 余子式
  Aij.mat = NULL;

  int z = 0;

  InitialMatrixZero(adj, T->row, T->col);
  for (int i = 0; i < T->row; i++) {
    for (int j = 0; j < T->col; j++) {
      int x = 0;
      int y = 0;
      InitialMatrixZero(&Aij, T->row - 1, T->col - 1);
      for (int i1 = 0; i1 < T->row; i1++) {
        y = 0;
        if (i1 == i) {
          continue;
        }
        for (int i2 = 0; i2 < T->col; i2++) {
          if (i2 == j) {
            continue;
          }
          Aij.mat[x][y] = T->mat[i1][i2];
          y++;
        }
        x++;
      }
      if ((i + j) % 2 == 0) {
        z = 1;
      } else {
        z = -1;
      }
      adj->mat[j][i] = z * Determinant(&Aij);
      DestroyMatrix(&Aij);
    }
  }
}

void ReverseMatrix(Matrix* A, Matrix* B)  // B是A的逆矩阵
{
  if (A == NULL || B == NULL || A->mat == NULL) {
    printf("矩阵未初始化\n");
    return;
  }
  if (A->row != A->col) {
    printf("非方阵无法计算行列式\n");
    return;
  }
  double determinant = Determinant(A);
  if (fabs(determinant) < 1e-9) {
    printf("该矩阵无逆矩阵\n");
    return;
  }
  DestroyMatrix(B);
  InitialMatrixZero(B, A->row, A->col);
  AdjugateMatrix(A, B);
  for (int i = 0; i < B->row; i++) {
    for (int j = 0; j < B->col; j++) {
      B->mat[i][j] /= determinant;
    }
  }
}