#ifndef MATRIX_H
#define MATRIX_H

typedef struct matrix // 矩阵
{
    double **mat; // 二维数组：mat[row][col]
    int row;      // 行数
    int col;      // 列数
} Matrix;

#endif