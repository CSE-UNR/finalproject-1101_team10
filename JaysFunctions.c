//This file is for Jay to work on their assigned functions
//Author: Jay Tilman
//Date: April 29

#include <stdio.h>
#define IMAGE "image.txt"
#define SIZE 500
#include <stdbool.h>

void loadNewImage(FILE* filePtr, int rowSize, int colSize, int imageArray[][colSize], int* trueRowPtr, int* trueColPtr);
void displayEditMenu();
int getEditChoice();
void getCropSpecs(int* startRowPtr, int* endRowPtr, int* startColPtr, int* endColPtr);
void saveNewImage(FILE* filePtr, int rowSize, int colSize, int imageArray[][colSize]);
void sayGoodbye();

int main() {
	FILE* loadFile;
	int anArray[SIZE][SIZE];
	int trueRowSize, trueColSize;
	
	loadFile = fopen(IMAGE, "r");
	if(loadFile == NULL){
		printf("AHHHH\n");
		return 0;
	}
	loadNewImage(loadFile, SIZE, SIZE, anArray, &trueRowSize, &trueColSize);  
	
	printf(" %d, %d\n", trueRowSize, trueColSize);
	
	fclose(loadFile);
	
	return 0;
}
		
void loadNewImage(FILE* filePtr, int rowSize, int colSize, int imageArray[][colSize], int* trueRowPtr, int* trueColPtr){
	int count, row, col, tRow, tCol, columnCount[colSize];
	count = tRow = tCol = 0;
	
	for(row = 0; row < rowSize; row++){
		for(col = 0; col < colSize; col++){
			while(fscanf(filePtr, "%d", &imageArray[row][col]) == 1){
				tRow++;
			}
			
		}
	}
	tCol = count / tRow;
	*trueRowPtr = tRow;
	*trueColPtr = tCol;
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







