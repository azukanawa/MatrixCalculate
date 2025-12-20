#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../Lib/function.h"
int main() {
  Matrix A = {NULL, 0, 0};
  Matrix B = {NULL, 0, 0};
  Matrix C = {NULL, 0, 0};
  srand((unsigned int)time(NULL));  // 随机数种子
  while (1) {
    printf("矩阵函数测试，请选择功能，输入对应的数字：\n");
    printf("***************************************************\n");
    printf("1：输入一个矩阵，求矩阵均值；\n");
    printf("2：产生一个随机数矩阵，求矩阵均值；\n");
    printf("3：输入两个矩阵，求矩阵和；\n");
    printf("4：输入两个矩阵，求矩阵差；\n");
    printf("5：输入两个矩阵，求矩阵积；\n");
    printf("6：产生两个随机数矩阵，求矩阵和；\n");
    printf("7：产生两个随机数矩阵，求矩阵差；\n");
    printf("8：产生两个随机数矩阵，求矩阵积；\n");
    printf("9：求矩阵的子阵，如矩阵的2-4行，1-3列的子阵；\n");
    printf("10：输入一个矩阵，求矩阵元素的最大值；\n");
    printf("11：产生一个随机数矩阵，求矩阵元素的最大值；\n");
    printf("12：输入一个矩阵，求矩阵转置；\n");
    printf("13：产生一个随机数矩阵，求矩阵转置；\n");
    printf("14：输入一个矩阵，求矩阵归一化；\n");
    printf("15：产生一个随机数矩阵，求矩阵归一化；\n");
    printf("16：输入一个矩阵，求矩阵的逆；\n");
    printf("17：产生一个随机数矩阵，求矩阵的逆；\n");
    printf("0：结束!\n");

    int input = 0;  // 用户输入
    scanf("%d", &input);
    switch (input) {
      case 0:
        return 0;
      case 1:  // 1：输入一个矩阵，求矩阵均值；
        DestroyMatrix(&A);
        printf("请输入矩阵行数和列数\n");
        scanf("%d", &A.row);
        scanf("%d", &A.col);
        InitialMatrixZero(&A, A.row, A.col);

        InputMatrix(&A);

        printf("输入矩阵为：\n");
        PrintfMatrix(&A);

        printf("%lf\n", MeanMatrix(&A));

        DestroyMatrix(&A);

        break;
      case 2:  // 2：产生一个随机数矩阵，求矩阵均值；
        DestroyMatrix(&A);
        printf("请输入矩阵行数和列数\n");
        scanf("%d", &A.row);
        scanf("%d", &A.col);
        InitialMatrixRand(&A, A.row, A.col);

        printf("随机数矩阵为：\n");
        PrintfMatrix(&A);
        printf("%lf\n", MeanMatrix(&A));

        DestroyMatrix(&A);

        break;
      case 3:  // 3：输入两个矩阵，求矩阵和；
        DestroyMatrix(&A);
        printf("请输入矩阵行数和列数\n");
        scanf("%d", &A.row);
        scanf("%d", &A.col);
        InitialMatrixZero(&A, A.row, A.col);
        InputMatrix(&A);
        printf("输入矩阵为：\n");
        PrintfMatrix(&A);

        DestroyMatrix(&B);
        InitialMatrixZero(&B, A.row, A.col);
        InputMatrix(&B);
        printf("输入矩阵为：\n");
        PrintfMatrix(&B);

        AddMatrix(&A, &B, &C);
        printf("输入矩阵之和为：\n");
        PrintfMatrix(&C);

        DestroyMatrix(&A);
        DestroyMatrix(&B);
        DestroyMatrix(&C);

        break;
      case 4:  // 4：输入两个矩阵，求矩阵差；
        DestroyMatrix(&A);
        printf("请输入矩阵行数和列数\n");
        scanf("%d", &A.row);
        scanf("%d", &A.col);
        InitialMatrixZero(&A, A.row, A.col);
        InputMatrix(&A);
        printf("输入矩阵为：\n");
        PrintfMatrix(&A);

        DestroyMatrix(&B);
        InitialMatrixZero(&B, A.row, A.col);
        InputMatrix(&B);
        printf("输入矩阵为：\n");
        PrintfMatrix(&B);

        MinusMatrix(&A, &B, &C);
        printf("输入矩阵之差为：\n");
        PrintfMatrix(&C);

        DestroyMatrix(&A);
        DestroyMatrix(&B);
        DestroyMatrix(&C);

        break;
      case 5:  // 5：输入两个矩阵，求矩阵积；
        DestroyMatrix(&A);
        printf("请输入矩阵行数和列数\n");
        scanf("%d", &A.row);
        scanf("%d", &A.col);
        InitialMatrixZero(&A, A.row, A.col);
        InputMatrix(&A);
        printf("输入矩阵为：\n");
        PrintfMatrix(&A);

        DestroyMatrix(&B);
        printf("请输入矩阵行数和列数\n");
        scanf("%d", &B.row);
        scanf("%d", &B.col);
        InitialMatrixZero(&B, B.row, B.col);
        InputMatrix(&B);
        printf("输入矩阵为：\n");
        PrintfMatrix(&B);

        MultiMatrix(&A, &B, &C);

        printf("输入矩阵之积为：\n");
        PrintfMatrix(&C);

        DestroyMatrix(&A);
        DestroyMatrix(&B);
        DestroyMatrix(&C);

        break;
      case 6:  // 6：产生两个随机数矩阵，求矩阵和；
        DestroyMatrix(&A);
        printf("请输入矩阵行数和列数\n");
        scanf("%d", &A.row);
        scanf("%d", &A.col);
        InitialMatrixRand(&A, A.row, A.col);
        printf("产生的第一个随机数矩阵为：\n");
        PrintfMatrix(&A);

        DestroyMatrix(&B);
        InitialMatrixRand(&B, A.row, A.col);
        printf("产生的第二个随机数矩阵为：\n");
        PrintfMatrix(&B);

        AddMatrix(&A, &B, &C);
        printf("随机数矩阵之和为：\n");
        PrintfMatrix(&C);

        DestroyMatrix(&A);
        DestroyMatrix(&B);
        DestroyMatrix(&C);

        break;
      case 7:  // 7：产生两个随机数矩阵，求矩阵差；
        DestroyMatrix(&A);
        printf("请输入矩阵行数和列数\n");
        scanf("%d", &A.row);
        scanf("%d", &A.col);
        InitialMatrixRand(&A, A.row, A.col);
        printf("产生的第一个随机数矩阵为：\n");
        PrintfMatrix(&A);

        DestroyMatrix(&B);
        InitialMatrixRand(&B, A.row, A.col);
        printf("产生的第二个随机数矩阵为：\n");
        PrintfMatrix(&B);

        MinusMatrix(&A, &B, &C);
        printf("随机数矩阵之差为：\n");
        PrintfMatrix(&C);

        DestroyMatrix(&A);
        DestroyMatrix(&B);
        DestroyMatrix(&C);

        break;
      case 8:  // 8：产生两个随机数矩阵，求矩阵积；
        DestroyMatrix(&A);
        printf("请输入矩阵行数和列数\n");
        scanf("%d", &A.row);
        scanf("%d", &A.col);
        InitialMatrixRand(&A, A.row, A.col);
        printf("产生的第一个随机数矩阵为：\n");
        PrintfMatrix(&A);

        DestroyMatrix(&B);
        printf("请输入矩阵行数和列数\n");
        scanf("%d", &B.row);
        scanf("%d", &B.col);
        InitialMatrixRand(&B, B.row, B.col);
        printf("产生的第二个随机数矩阵为：\n");
        PrintfMatrix(&B);

        MultiMatrix(&A, &B, &C);
        printf("随机数矩阵之积为：\n");
        PrintfMatrix(&C);

        DestroyMatrix(&A);
        DestroyMatrix(&B);
        DestroyMatrix(&C);

        break;
      case 9:          // 9：求矩阵的子阵，如矩阵的2-4行，1-3列的子阵；
        int BeginRow;  // 子阵起始行
        int BeginCol;  // 子阵终止行
        int EndRow;    // 子阵起始列
        int EndCol;    // 子阵终止列

        DestroyMatrix(&A);
        printf("请输入矩阵行数和列数\n");
        scanf("%d", &A.row);
        scanf("%d", &A.col);
        InitialMatrixZero(&A, A.row, A.col);
        InputMatrix(&A);
        printf("输入矩阵为：\n");
        PrintfMatrix(&A);

        printf("请输入子矩阵开始的行数\n");
        scanf("%d", &BeginRow);
        printf("请输入子矩阵开始的列数\n");
        scanf("%d", &BeginCol);
        printf("请输入子矩阵结束的行数\n");
        scanf("%d", &EndRow);
        printf("请输入子矩阵结束的列数\n");
        scanf("%d", &EndCol);

        DestroyMatrix(&B);

        if (SubMatrix(&A, &B, BeginRow, BeginCol, EndRow, EndCol) == 1) {
          printf("子矩阵为：\n");
          PrintfMatrix(&B);
        }

        DestroyMatrix(&A);
        DestroyMatrix(&B);

        break;
      case 10:  // 10：输入一个矩阵，求矩阵元素的最大值；
        DestroyMatrix(&A);
        printf("请输入矩阵行数和列数\n");
        scanf("%d", &A.row);
        scanf("%d", &A.col);
        InitialMatrixZero(&A, A.row, A.col);
        InputMatrix(&A);
        printf("输入矩阵为：\n");
        PrintfMatrix(&A);

        printf("该矩阵元素最大值为：%lf\n", MaxMatrix(&A));
        DestroyMatrix(&A);
        break;
      case 11:  // 11：产生一个随机数矩阵，求矩阵元素的最大值；
        DestroyMatrix(&A);
        printf("请输入矩阵行数和列数\n");
        scanf("%d", &A.row);
        scanf("%d", &A.col);
        InitialMatrixRand(&A, A.row, A.col);
        printf("产生的随机数矩阵为：\n");
        PrintfMatrix(&A);

        printf("该矩阵元素最大值为：%lf\n", MaxMatrix(&A));
        DestroyMatrix(&A);
        break;
      case 12:  // 12：输入一个矩阵，求矩阵转置；
        DestroyMatrix(&A);
        printf("请输入矩阵行数和列数\n");
        scanf("%d", &A.row);
        scanf("%d", &A.col);
        InitialMatrixZero(&A, A.row, A.col);
        InputMatrix(&A);
        printf("输入矩阵为：\n");
        PrintfMatrix(&A);

        TransMatrix(&A);
        printf("输入矩阵的转置为：\n");
        PrintfMatrix(&A);

        DestroyMatrix(&A);
        break;
      case 13:  // 13：产生一个随机数矩阵，求矩阵转置；
        DestroyMatrix(&A);
        printf("请输入矩阵行数和列数\n");
        scanf("%d", &A.row);
        scanf("%d", &A.col);
        InitialMatrixRand(&A, A.row, A.col);
        printf("产生的随机数矩阵为：\n");
        PrintfMatrix(&A);

        TransMatrix(&A);
        printf("产生的随机数矩阵的转置为：\n");
        PrintfMatrix(&A);

        DestroyMatrix(&A);
        break;
      case 14:  // 14：输入一个矩阵，求矩阵归一化；
        DestroyMatrix(&A);
        printf("请输入矩阵行数和列数\n");
        scanf("%d", &A.row);
        scanf("%d", &A.col);
        InitialMatrixZero(&A, A.row, A.col);
        InputMatrix(&A);
        printf("输入矩阵为：\n");
        PrintfMatrix(&A);

        NormMatrix(&A);
        printf("输入矩阵归一化后为：\n");
        PrintfMatrix(&A);

        DestroyMatrix(&A);
        break;
      case 15:  // 15：产生一个随机数矩阵，求矩阵归一化；
        DestroyMatrix(&A);
        printf("请输入矩阵行数和列数\n");
        scanf("%d", &A.row);
        scanf("%d", &A.col);
        InitialMatrixRand(&A, A.row, A.col);
        printf("产生的随机数矩阵为：\n");
        PrintfMatrix(&A);

        NormMatrix(&A);
        printf("产生的随机数矩阵归一化后为：\n");
        PrintfMatrix(&A);

        DestroyMatrix(&A);
        break;
      case 16:  // 16：输入一个矩阵，求矩阵的逆；
        DestroyMatrix(&A);
        printf("请输入矩阵行数和列数\n");
        scanf("%d", &A.row);
        scanf("%d", &A.col);
        InitialMatrixZero(&A, A.row, A.col);
        InputMatrix(&A);
        printf("输入矩阵为：\n");
        PrintfMatrix(&A);

        DestroyMatrix(&B);
        ReverseMatrix(&A, &B);

        printf("输入矩阵的逆为：\n");
        PrintfMatrix(&B);

        DestroyMatrix(&A);
        DestroyMatrix(&B);
        break;
      case 17:  // 产生一个随机数矩阵，求矩阵的逆；
        DestroyMatrix(&A);
        printf("请输入矩阵行数和列数\n");
        scanf("%d", &A.row);
        scanf("%d", &A.col);
        InitialMatrixRand(&A, A.row, A.col);
        printf("产生的随机数矩阵为：\n");
        PrintfMatrix(&A);

        DestroyMatrix(&B);
        ReverseMatrix(&A, &B);

        printf("产生的随机数矩阵的逆为：\n");
        PrintfMatrix(&B);

        DestroyMatrix(&A);
        DestroyMatrix(&B);
        break;
    }
  }
}