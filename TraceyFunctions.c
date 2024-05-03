//Tracey Msangi
//Final project functions


#include <stdio.h>

void displayMenu();
	
void getMenuChoice(int choice);

void displayImage(int rowsize, int colsize, int imagearray);	
	
void cropImage(int image[rowSize][colSize], int rowSize, int colSize, int *imageArray, int startRow, int endRow, int startCol, int endCol);

void dimImage(int image[rowSize][colSize]);

void brightenImage(int image[rowSize][colSize]);


int main(){


return 0;
}


// Function to display the menu
void displayMenu() {
    printf("**ERINSTAGRAM**\n");
    printf("1: Load image\n");
    printf("2: Display image\n");
    printf("3: Edit image\n");
    printf("0: Exit\n");
}

// Function to get menu choice from user
void getMenuChoice(int *choice) {
    printf("Choose from one of the options above: \n");
    scanf("%d", choice);
}

// Function to display the image
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

// Function to crop the image
void cropImage(int image[rowSize][colSize], int rowSize, int colSize, int *newSize, int startRow, int endRow, int startCol, int endCol) {
    printf("Which column do you want to be the new left side? ");
    scanf("%d", &startCol);

    printf("Which column do you want to be the new right side? ");
    scanf("%d", &endCol);

    printf("Which row do you want to be the new top? ");
    scanf("%d", &startRow);

    printf("Which row do you want to be the new bottom? ");
    scanf("%d", &endRow);

    int newRowSize = endRow - startRow + 1;
    int newColSize = endCol - startCol + 1;
    *newSize = newRowSize * newColSize;

    int croppedImage[newRowSize][newColSize];
    for (int i = 0; i < newRowSize; i++) {
        for (int j = 0; j < newColSize; j++) {
            croppedImage[i][j] = image[startRow + i][startCol + j];
        }
    }

    // Replacing the original image with the cropped image
    for (int i = 0; i < newRowSize; i++) {
        for (int j = 0; j < newColSize; j++) {
            image[i][j] = croppedImage[i][j];
        }
    }
}

// Function to dim the image
void dimImage(int image[rowSize][colSize], int rowSize, int colSize) {
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize; j++) {
            if (image[i][j] > 0) {
                image[i][j]--;
            }
        }
    }
}

// Function to brighten the image
void brightenImage(int image[rowSize][colSize], int rowSize, int colSize) {
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize; j++) {
            if (image[i][j] < 4) {
                image[i][j]++;
            }
        }
    }
}


/*
displayMenu() //TRACEY 05/03
INPUT PARAMETERS: none
RETURNED OUTPUT: none
FUNCTIONALITY: display numerically labeled options for the user to choose from, including load new
image, display current image, edit current image, and exit program

getMenuChoice() //TRACEY 05/03
INPUT PARAMETERS: none
RETURNED OUTPUT: int menuChoice
FUNCTIONALITY: Prompt the user for a choice and scan the user entered number for their choice and
save it in the returned variable

displayImage() //TRACEY 05/03
INPUT PARAMETERS: int rowSize, int colSize, int imageArray
RETURNED OUTPUT: none
FUNCTIONALITY: in a loop, display each value in imageArray with its corresponding value according to
the system: 0 = " ", 1 = ".", 2 = "o", 3 = "O", and 4 = "0"

cropImage() //TRACEY 05/03
INPUT PARAMETERS: int rowSize, int colSize, int imageArray, int startRow, int endRow, int startCol, int
endCol
RETURNED OUTPUT: int newImageArray
FUNCTIONALITY: Assign newImageArray the values found between the rows in imageArray from
startRow to endRow and the columns in imageArray from startCol to endCol

dimImage()  //TRACEY 05/03
INPUT PARAMETERS: int rowSize, int colSize, int imageArray
RETURNED OUTPUT: int newImageArray
FUNCTIONALITY: Assign all values in newImageArray the value minus one at corresponding
coordinates in imageArray, unless the value at a point equals zero, in which case assign the respective
point in newImageArray zero.

brightenImage() //TRACEY 05/03
INPUT PARAMETERS: int rowSize, int colSize, int imageArray
RETURNED OUTPUT: int newImageArray
FUNCTIONALITY: Assign all values in newImageArray the value plus one at corresponding coordinates
in imageArray, unless the value at a point equals four, in which case assign the respective point in
newImageArray four.

*/


































