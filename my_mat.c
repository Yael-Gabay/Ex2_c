#include "my_mat.h"

/**
 * Defining a matrix and performing the Floyd-Warshall algorithm
*/
void initMat(int arr[][LEN]){
	int notE = FALSE;
	for (int i = 0; i < LEN; i++){
		for (int j = 0; j < LEN; j++){
			if (notE){
				arr[i][j] = 0;
			}
			else{				
				notE = (scanf("%d", &arr[i][j]) == EOF);
			}
		}
	}
	FloydWarshallAlgo(arr);		// run the floyd warshall algorithm
}

/**
 * Finding a minimum number
*/
int min(int a, int b){
	return (a < b ? a : b);
}

/**
 * @brief Implementation of the Werschel Floyd algorithm on a matrix of size (LENxLEN) = (10x10).
 * If there is no arc between 2 vertices, the value will remain 0.
 * The function works like this: A(i,j)_{k} = min { A(i,j)_{k-1} , A(i,k)_{k-1} + A(k,j)_{k- 1 } }
 * @param arr matrix of size of (LENxLEN) = (10x10)
*/
void FloydWarshallAlgo(int arr[][LEN]){
	for (int k = 0; k < LEN; k++){
		for (int i = 0; i < LEN; i++){
			for (int j = 0; j < LEN; j++){
				if (!(arr[i][k] == 0 && i != k) && !(arr[k][j] == 0 && k != j)){
					if (arr[i][j] == 0 && i != j){	
						arr[i][j] = arr[i][k] + arr[k][j];	// this is the minimal value
					}
					else{
						arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
					}
				}
			}
		}
	}
}


/**
 * @brief Gets 2 indexes and checks if a route exists. 
 * The function will return 'true' if a route exists. 
 * If not present, the function will return 'false'
 * @param arr matrix with size of (LENxLEN) = (10x10)
 */
void hasRoute(int arr[][LEN]){
	int i = 0, j = 0;
	if (!(scanf("%d%d", &i, &j) == EOF) && 0 <= i && i < LEN && 0 <= j && j < LEN){	
		printf("%s\n", (arr[i][j] ? "True" : "False"));
	}	
}

/**
 * @brief Gets 2 indexes and checks the length of the path.
 * If the path does not exist the function will return (-1)
 * @param arr matrix with size of (LENxLEN) = (10x10)
 */
void shortPath(int arr[][LEN]){
	int i = 0, j = 0;
	if (!(scanf("%d%d", &i, &j) == EOF) && 0 <= i && i < LEN && 0 <= j && j < LEN){ 
			printf("%d\n", (arr[i][j] ? arr[i][j] : -1));
	}
}