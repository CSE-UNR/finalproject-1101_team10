#include <stdio.h>

int main (){
	FILE* file;
	char tempName[50];
  
    	printf("What is the name of the image file? ");
    	fscanf(stdin, "%s", tempName);
    
   	 int ind = 0;
   	 while(tempName[ind] != '\n' && tempName[ind] != '\0'){
    	 ind++;
   	 }
    
    char fileName[ind+2];
    
    fileName[0] = '"';
    for(int i = 1; i <= ind; i++){
    	fileName[i] = tempName[i-1];
    }	
    fileName[ind+1] = '"';

    file = fopen(tempName, "r");
    if (file != NULL) {
        printf("Success!\n");
    }
 
    fclose(file);

	
	return 0;
}
