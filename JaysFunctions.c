//This file is for Jay to work on their assigned functions
//Author: Jay Tilman
//Date: April 29

#include <stdio.h>
#define IMAGE "image.txt"
#define SIZE 500
#define NAMECAP 50
#include <stdbool.h>

void loadNewImage(char fileName[], int rowSize, int colSize, int imageArray[][colSize], int* trueRowPtr, int* trueColPtr);
void displayEditMenu();
int getEditChoice();
void getCropSpecs(int* startRowPtr, int* endRowPtr, int* startColPtr, int* endColPtr);
void saveNewImage(FILE* filePtr, int rowSize, int colSize, int imageArray[][colSize]);
void sayGoodbye();

int main() {
	char loadFile[NAMECAP];
	int anArray[SIZE][SIZE];
	int trueRowSize, trueColSize;
	
	
	loadNewImage(IMAGE, SIZE, SIZE, anArray, &trueRowSize, &trueColSize);  
	
	printf(" %d, %d\n", trueRowSize, trueColSize);
	
	
	return 0;
}
		
void loadNewImage(char fileName[], int rowSize, int colSize, int imageArray[][colSize], int* trueRowPtr, int* trueColPtr){
	FILE* file;
	int rowCount, colCount, elementCount, rowArray[rowSize][colSize];
	rowCount = colCount = elementCount = 0;
	
	file = fopen(fileName, "r");
	if(file != NULL){
	
		for(int e = 0; e < colSize*rowSize; e++){
			while(fscanf(file, "%1d", &e) == 1){
				elementCount++;
			}
		}
	}
	fclose(file);
	
	file = fopen(fileName, "r");
	if(file != NULL){
		for(int row = 0; row < rowSize; row++){
			for(int col = 0; col < colSize; col++){
				while(fscanf(file, "%d", &rowArray[row][col]) == 1){
					rowCount++;
				}
			}
		}
	}
	fclose(file);
	
	colCount = elementCount / rowCount;
	
	file = fopen(fileName, "r");
	if(file != NULL){
		for(int row = 0; row < rowCount; row++){
			for(int col = 0; col < colCount; col++){
				fscanf(file, "%1d", &imageArray[row][col]);
			}
		}
	}
	fclose(file);
	
	for(int row = 0; row < 12; row++){
		for(int col = 0; col < 21; col++){
			printf("%d", imageArray[row][col]);
		}
		printf("\n");
	}
	
	*trueRowPtr = rowCount;
	*trueColPtr = colCount;
	
}

void displayEditMenu(){
	printf("Choose an edit to make:\n");
	printf("1: Crop Image\n");
	printf("2: Dim image\n");
	printf("3: Brighten Image\n");
}

int getEditChoice(){
	int choice;
	
	printf("Enter the number of your choice: ");
	scanf("%d", &choice);
	
	return choice;
}

void getCropSpecs(int* startRowPtr, int* endRowPtr, int* startColPtr, int* endColPtr){
	int startRow, endRow, startCol, endCol;
	
	printf("What section of the image would you like to crop?\n");
	printf("Starting row number: ");
	scanf("%d", &startRow);
	*startRowPtr = startRow;
	
	printf("Ending row number: ");
	scanf("%d", &endRow);
	*endRowPtr = endRow;	
	
	printf("Starting column number: ");
	scanf("%d", &startCol);
	*startColPtr = startCol;
	
	printf("Ending column number: ");
	scanf("%d", &endCol);
	*endColPtr = endCol;
}

void saveNewImage(FILE* filePtr, int rowSize, int colSize, int imageArray[][colSize]){
	for(int row = 0; row < rowSize; row ++){
		for(int col = 0; col < colSize; col++){
			fprintf(filePtr, "%d", imageArray[row][col]);
		}
	}
}

void sayGoodbye(){
	printf("Goodbye!\n");
}




