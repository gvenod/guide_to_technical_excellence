
/*
 matrix multiplication - algorithm - multiply rows of the first matrix with columns of the second matrix and summing the products.
 
 Compatibility: only multiply two matrices if the number of columns in the first matrix equals the number of rows in the second matrix.
 
 Resultant Matrix: will have the same number of rows as the first matrix and the same number of columns as the second matrix.

*/

#include <stdio.h>

int main() {
	
	int rows = 3, cols = 3;
	int *mat = (int *)calloc(rows * cols, sizeof(int));
	if(mat) free (mat);
	
    int rows1, cols1, rows2, cols2;

    // Input the dimensions of the first matrix
    printf("Enter the number of rows and columns for the first matrix: ");
    scanf("%d %d", &rows1, &cols1);

    // Input the dimensions of the second matrix
    printf("Enter the number of rows and columns for the second matrix: ");
    scanf("%d %d", &rows2, &cols2);

    // Check if matrices are compatible for multiplication
    if (cols1 != rows2) {
        printf("Matrices are not compatible for multiplication.\n");
        return 1;
    }

    // Declare matrices
    int matrix1[rows1][cols1], matrix2[rows2][cols2], result[rows1][cols2];

    // Input elements of the first matrix
    printf("Enter the elements of the first matrix:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    // Input elements of the second matrix
    printf("Enter the elements of the second matrix:\n");
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Perform matrix multiplication
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0; // Initialize the element to 0
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    // Print the resulting matrix
    printf("Resultant matrix:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}