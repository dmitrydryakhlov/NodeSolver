#pragma once
#include "utils.h"

const int N = 6;

int main() {
	float** MatrixUp, **MatrixLow;
	float* bLow, *bUp, *xLow, *xUp;
	int* SNodesLow, *SNodesUp, NodesNLow, NodesNUp;


	mallocMatrix(&MatrixLow, N);
	mallocMatrix(&MatrixUp, N);
	makeBlock6x6Low(MatrixLow, N);
	makeBlock6x6Up(MatrixUp, N);
	//randMatrixLow(MatrixLow, N);
	//randMatrixUp(MatrixUp, N);
	printMatrix(MatrixLow, N);
	printMatrix(MatrixUp, N);
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
	CalcSuperNodesLow(MatrixLow, &SNodesLow, N, NodesNLow);
	CalcSuperNodesUp(MatrixUp, &SNodesUp, N, NodesNUp);
	printVectorI(SNodesLow, NodesNLow);
	printVectorI(SNodesUp, NodesNUp);
	printf("%d\n", NodesNLow);
	printf("%d\n", NodesNUp);

	blockSolverLow(MatrixLow, SNodesLow, NodesNLow, xLow, bLow, N);
	blockSolverUp(MatrixUp, SNodesUp, NodesNUp, xUp, bUp, N);

	printVectorF(xLow, N);
	printVectorF(xUp, N);
	FreeMem(MatrixLow, N);
	FreeMem(MatrixUp, N);

	delete[]xUp;
	delete[]xLow;
	delete[]bLow;
	delete[]bUp;

	return 0;
}