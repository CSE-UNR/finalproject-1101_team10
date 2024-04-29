//This file is for Jay to work on their assigned functions
//Author: Jay Tilman
//Date: April 29

#include <stdio.h>

void int loadNewImage(FILE* filePtr, int rowSize, int colSize, int imageArray[][colSize]);
void displayEditMenu();
int getEditChoice();
void getCropSpecs(int* startRowPtr, int* endRowPtr, int* startColPtr, int* endColPtr);
void saveNewImage(FILE* filePtr, int rowSize, int colSize, int imageArray[][colSize]);
void sayGoodbye();

int main() {

	return 0;
}

void int loadNewImage(FILE* filePtr, int rowSize, int colSize, int imageArray[][colSize]){
	for(int row = 0; row < rowSize; row ++){
		for(int col = 0; col < colSize; col++){
			fscanf(filePtr, "%d", &imageArray[row][col]);
		}
	}
}

void displayEditMenu(){
	printf("Choose an edit to make:\n");
	printf("1: Crop Image\n");
	printf("2: Dim image\n");
	printf("3: Brighten Image\n");
}

int getEditChoice(){
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
			fprintf(filePtr, "%d", &imageArray[row][col]);
		}
	}
}

void sayGoodbye(){
	printf("Goodbye!\n");
}
