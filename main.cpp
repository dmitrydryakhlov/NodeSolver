#pragma once
#include "utils.h"
#include <stdio.h>

const int N = 6;
const int NzU = 15;
const int NzL = 15;

int main() {
	float* MatrixUpVal, *MatrixLowVal;
	int *MatrixUpRow, *MatrixLowRow,
		*MatrixUpIndx, *MatrixLowIndx;

	float* bLow, *bUp, *xLow, *xUp;
	int* SNodesLow, *SNodesUp, NodesNLow, NodesNUp;


	mallocMatrixCCS(&MatrixLowVal, &MatrixLowRow, &MatrixLowIndx, NzL, N);
	mallocMatrixCCS(&MatrixUpVal, &MatrixUpRow, &MatrixUpIndx, NzU, N);
	makeBlock6x6LowCCS(MatrixLowVal, MatrixLowRow, MatrixLowIndx, NzL, N);
	makeBlock6x6UpCCS(MatrixUpVal, MatrixUpRow, MatrixUpIndx, NzU, N);

	mallocVectorF(&xLow, N);
	mallocVectorF(&xUp, N);
	mallocVectorF(&bLow, N);
	mallocVectorF(&bUp, N);

	for (int i = 0; i < N; i++)
		bUp[i] = bLow[i] = i + 1;
	
	printVectorF(bLow, N);
	printVectorF(bUp, N);

	mallocVectorI(&SNodesLow, N);
	mallocVectorI(&SNodesUp, N);

	CalcSuperNodesLowCCS(MatrixLowVal, MatrixLowRow, MatrixLowIndx, &SNodesLow, NodesNLow, NzL, N);
	CalcSuperNodesUpCCS(MatrixUpVal, MatrixUpRow, MatrixUpIndx, &SNodesUp, NodesNUp, NzU, N);

	printf("\nNodesLow/N : %d/%d\n", NodesNLow - 1, N);
	printVectorI(SNodesLow, NodesNLow);
	printf("\nNodesUp/N : %d/%d\n", NodesNUp - 1, N);
	printVectorI(SNodesUp, NodesNUp);

	blockSolverLowCCS(MatrixLowVal, MatrixLowRow, MatrixLowIndx, SNodesLow, NodesNLow, xLow, bLow, N);
	blockSolverUpCCS(MatrixUpVal, MatrixUpRow, MatrixUpIndx, SNodesUp, NodesNUp, xUp, bUp, N);

	printVectorF(xLow, N);
	printVectorF(xUp, N);

	delete[]MatrixUpVal; delete[]MatrixLowVal;
	delete[]MatrixUpRow; delete[]MatrixLowRow;
	delete[]MatrixUpIndx;delete[]MatrixLowIndx;
	delete[]xUp; delete[]xLow;
	delete[]bUp; delete[]bLow;

	return 0;
}