#include <stdio.h>
#include <stdlib.h>

void print_matrix(int **matrix, int rows, int cols);
int **create_matrix(int rows, int cols);
int free_matrix(int **matrix, int rows, int cols);
int main()
{
    int rows, cols =0;
    printf("Please entered the rows and cols of matrix: ");
    scanf("%d %d",&rows, &cols);
    int **matrix1=create_matrix(rows, cols);
    print_matrix(matrix1, rows, cols);
    free_matrix(matrix1,rows,cols);

    return 0;
}

void print_matrix(int **matrix, int rows, int cols)
{
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            printf("%3d",matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
}

int **create_matrix(int rows, int cols)
{
   int **matrix = (int **)malloc(sizeof(int *) * rows);
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(sizeof(int) * cols);
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = i * cols + j + 1; // 값을 순서대로 저장
        }
    }
    return matrix;
} 


int free_matrix(int **matrix, int rows, int cols)
{
    for(int i=0; i<rows; i++){
        
            free (matrix[i]);
        
    }
    free(matrix);
    return 1;
}