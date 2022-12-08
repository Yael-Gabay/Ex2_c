
#include <stdio.h>
#include "my_mat.h"

void printArr(int arr[][LEN]){
	for (int i = 0; i < LEN; i++){
		for (int j = 0; j < LEN; j++){
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main(){	
	char ch = '0';
	int arr[LEN][LEN] = { 0 };	// the matrix that the functions are running on

	// do-while is the most prefered for menus
	do{
		fflush(stdin);
		if (scanf(" %c", &ch) == EOF){
			ch = 'D';
		}

		switch (ch){
			case 'A':			// when 'A' is chosen run function (1) - init the marix
				initMat(arr);
				break;
			case 'B':			// when 'B' is chosen run function (2) - detect if path exists
				hasRoute(arr);
				break;
			case 'C':			// when 'C' is chosen run function (3) - get tha shortest path
				shortPath(arr);
				break;
			default:			// ignore other chars
				break;
		}

	} 
    while (ch != 'D');		// when 'D' is chosen, break the loop
	return (0);
}