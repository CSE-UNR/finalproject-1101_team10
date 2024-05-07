#include <stdio.h>

// Function Declarations
void displayMenu();
void getMenuChoice(int* choice);
void displayImage(int rowSize, int colSize, int imageArray[rowSize][colSize]);
void cropImage(int image[][21], int rowSize, int colSize, int startRow, int endRow, int startCol, int endCol);
void dimImage(int image[][21], int rowSize, int colSize);
void brightenImage(int image[][21], int rowSize, int colSize);
void loadNewImage(int rowSize, int colSize, int imageArray[][colSize], int* trueRowPtr, int* trueColPtr);
void saveNewImage(int rowSize, int colSize, int imageArray[][colSize]);
void displayEditMenu();
int getEditChoice();
void getCropSpecs(int* startRowPtr, int* endRowPtr, int* startColPtr, int* endColPtr);
void sayGoodbye();

// Main Function
int main() {
    int choice;
    int rowSize = 12;
    int colSize = 21; 
    int imageArray[12][21]; 

    while (1) {
        displayMenu();
        getMenuChoice(&choice);

        switch (choice) {
            case 1:
                loadNewImage(rowSize, colSize, imageArray, &rowSize, &colSize);
                break;
            case 2:
                displayImage(rowSize, colSize, imageArray);
                break;
            case 3:
                displayEditMenu();
                int editChoice = getEditChoice();
                switch (editChoice) {
                    case 1: {
                        int startRow, endRow, startCol, endCol;
                        getCropSpecs(&startRow, &endRow, &startCol, &endCol);
                        cropImage(imageArray, rowSize, colSize, startRow, endRow, startCol, endCol);
                        break;
                    }
                    case 2:
                        dimImage(imageArray, rowSize, colSize);
                        break;
                    case 3:
                        brightenImage(imageArray, rowSize, colSize);
                        break;
                    case 0:
                        displayMenu();
       		        getMenuChoice(&choice);
                }
                char saveChoice;
                printf("Do you want to save the file? (y/n) ");
		scanf(" %c", &saveChoice);
		switch(saveChoice){
			case 'y':
			case 'Y':
				saveNewImage(rowSize, colSize, imageArray);
				break;
		}
		
                break;
            case 0:
                sayGoodbye();
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}

// Function Implementations

void displayMenu() {
    printf("**ERINSTAGRAM**\n");
    printf("1: Load image\n");
    printf("2: Display image\n");
    printf("3: Edit image\n");
    printf("0: Exit\n");
}

void getMenuChoice(int* choice) {
    printf("\nChoose from one of the options above: ");
    scanf("%d", choice);
    getchar(); // Clear the input buffer
}

void displayImage(int rowSize, int colSize, int imageArray[rowSize][colSize]) {
    for (int row = 0; row < rowSize; row++) {
        for (int col = 0; col < colSize; col++) {
            switch (imageArray[row][col]) {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf(".");
                    break;
                case 2:
                    printf("o");
                    break;
                case 3:
                    printf("O");
                    break;
                case 4:
                    printf("0");
                    break;
            }
        }
        printf("\n");
    }
}

void cropImage(int image[][21], int rowSize, int colSize, int startRow, int endRow, int startCol, int endCol) {
   

    int newStartRow, newEndRow, newStartCol, newEndCol;
    getCropSpecs(&newStartRow, &newEndRow, &newStartCol, &newEndCol);
    int newRowSize = newEndRow - newStartRow + 1;
    int newColSize = newEndCol - newStartCol + 1;

    int croppedImage[newRowSize][newColSize];

    for (int i = newStartRow; i <= newEndRow; i++) {
        for (int j = newStartCol; j <= newEndCol; j++) {
            croppedImage[i - newStartRow][j - newStartCol] = image[i][j];
        }
    }

    for (int i = 0; i < newRowSize; i++) {
        for (int j = 0; j < newColSize; j++) {
            image[i][j] = croppedImage[i][j];
        }
    }

    rowSize = newRowSize;
    colSize = newColSize;

}



void dimImage(int image[][21], int rowSize, int colSize) {
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize; j++) {
            if (image[i][j] > 0) {
                image[i][j] = image[i][j] - 1;
            } else {
                image[i][j] = 0;
            }
        }
    }
}

void brightenImage(int image[][21], int rowSize, int colSize) {
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize; j++) {
            if (image[i][j] < 4) {
                image[i][j] = image[i][j] + 1;
            } else {
                image[i][j] = 4;
            }
        }
    }
}

void loadNewImage(int rowSize, int colSize, int imageArray[rowSize][colSize], int* trueRowPtr, int* trueColPtr) {
    FILE* file;
    char fileName[50];
    int row, col;

    printf("What is the name of the image file? ");
    scanf("%s", fileName);

    file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    // Read the image data from the file
    for (row = 0; row < rowSize; row++) {
        for (col = 0; col < colSize; col++) {
            if (fscanf(file, "%1d", &imageArray[row][col]) != 1) {
                printf("Error reading file.\n");
                fclose(file);
                return;
            }
        }
    }

    fclose(file);

    // Update the true row and column counts
    *trueRowPtr = rowSize;
    *trueColPtr = colSize;

    printf("\nImage successfully loaded!\n\n");
}



void saveNewImage(int rowSize, int colSize, int imageArray[][colSize]) {
    FILE* file;
    char fileName[50];

    printf("\nWhat do you want to name the image file? (include the extension) ");
    scanf("%s", fileName);

    file = fopen(fileName, "w");

    if (file != NULL) {
        for (int row = 0; row < rowSize; row++) {
            for (int col = 0; col < colSize; col++) {
                fprintf(file, "%1d", imageArray[row][col]);
            }
        }
    } else {
        printf("Error opening file.\n");
    }

    fclose(file);
    printf("Image successfully saved!\n");
}

void displayEditMenu() {
    printf("\n**EDITING**\n");
    printf("1: Crop Image\n");
    printf("2: Dim Image\n");
    printf("3: Brighten Image\n");
    printf("0: Return to main menu\n");
}

int getEditChoice() {
    int choice;
    printf("\nChoose from one of the options above: ");
    scanf("%d", &choice);
    return choice;
}

void getCropSpecs(int* startRowPtr, int* endRowPtr, int* startColPtr, int* endColPtr) {

    
    printf("Current image dimensions: Rows: %d, Columns: %d\n", rowSize, colSize);
    
    printf("Which column do you want to be the new left side? ");
    scanf("%d", startColPtr);
    printf("Which column do you want to be the new right side? ");
    scanf("%d", endColPtr);
    printf("Which row do you want to be the new top? ");
    scanf("%d", startRowPtr);
    printf("Which row do you want to be the new bottom? ");
    scanf("%d", endRowPtr);
    
   
}

void sayGoodbye() {
    printf("\nGoodbye!\n");
}

