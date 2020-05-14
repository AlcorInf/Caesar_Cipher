#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "crypter.h"


int main()
{
	int choice, shift;
  char Message[100];
  char FileName[FILENAME_MAX];
  FILE *fp; //Read Filename properly

	do {
		printf("\n1.Encrypt Text\n2.Decrypt Text\n3.Encrypt via File\n4.Decrypt via File\n5.Exit\n");
		scanf("%d", &choice);

    //Take inputs
    if(choice == 1 || choice == 2){
      printf("Enter Text:");
      scanf(" %[^\n]s", Message);
      printf("Enter Shift(1-25):");
      scanf("%d", &shift);
      while(!(shift>0)){
        printf("Number out of Range\nTry Again\n");
        printf("Enter Shift(1-25):");
        scanf("%d", &shift);
      }
      fflush(stdin);
    }

    //Take inputs
    if(choice == 3 || choice == 4){
      printf("Enter Filename:");
      scanf(" %[^\n]s", FileName);

      // Filename must be existing
      while((fp = fopen(FileName, "r")) == NULL){
      fprintf(stderr, "\nError: Unable to open file %s\nTry Again\n", FileName);
      printf("Enter Filename:");
      scanf(" %[^\n]s", FileName);
      }

      printf("Enter Shift(1-25):\n");
      scanf("%d", &shift);
      while(!(shift>0)){
        printf("Number out of Range\nTry Again\n");
        printf("Enter Shift(1-25):");
        scanf("%d", &shift);
      }
      fflush(stdin);
      fclose(fp); //Close pointer to not create problem while calling function
    }

    shift = (shift % 26); //In case number exceeds (1-25)

		switch (choice) {
		case 1:
			t_cipher(Message, shift, choice);
			break;

		case 2:
      shift = 26 - shift; //De-ciphering and for shorter code
			t_cipher(Message, shift, choice);
			break;
    
    // Pointer FILE* isn't used because name of file required
		case 3:
      f_cipher(FileName, shift, choice);
      break;

    case 4:
      shift = 26 - shift; //De-ciphering and for shorter code
      f_cipher(FileName, shift, choice);
      break;

    case 5:
			system("clear");
			printf("\n\nExiting\n\n");
			break;

		default:  
			system("clear");
			break;
		}
	} while (choice != 5);
}