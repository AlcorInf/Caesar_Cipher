/*
Author: Kishan Murthy (AlcorInf)

Coded and tested on repl.it
Tested on Linux and Windows
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "crypter.h"


int main(int argc, char *argv[])
/* For command line arguments,
(if space, add it in " ") 
Format 1: Message Shift Choice
Choice - 1: Encrypt 2: Decrypt

Format 2:Filename Shift Choice
Choice - 3: Encrypt 4: Decrypt
*/
{
	int choice, shift;
  char Message[100];
  char FileName[FILENAME_MAX];
  FILE *fp;

  if(argc == 4){
    if(atoi(argv[3]) == 1){
      strcpy(Message,argv[1]);
      shift = atoi(argv[2]) % 26;
      choice = atoi(argv[3]);
      t_crypter(Message, shift, choice);
    }
    else if(atoi(argv[3]) == 2){
      strcpy(Message,argv[1]);
      shift = atoi(argv[2]);
      shift = 26 - (atoi(argv[2]) % 26);
      choice = atoi(argv[3]);
      t_crypter(Message, shift, choice);
    }
    else if(atoi(argv[3]) == 3){
      strcpy(FileName,argv[1]);
      shift = atoi(argv[2]) % 26;
      choice = atoi(argv[3]);
      f_crypter(FileName, shift, choice);
    }
    else if(atoi(argv[3]) == 4){
      strcpy(FileName,argv[1]);
      shift = 26 - (atoi(argv[2]) % 26);
      choice = atoi(argv[3]);
      f_crypter(FileName, shift, choice);
    }
    exit(0);
  }
  else if(argc != 1){
    printf("Wrong number of arguments entered\n");
    exit(0);
  }



	do {
		printf("\n1.Encrypt Text\n2.Decrypt Text\n3.Encrypt via File\n4.Decrypt via File\n5.Exit\n");
    printf("\nEnter choice:");
		scanf("%d", &choice);

    //Take inputs
    if(choice == 1 || choice == 2){
      printf("Enter Text:");
      scanf(" %[^\n]s", Message);
      printf("Enter Shift(1-25):");
      scanf("%d", &shift); //Only taking positive value
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

      //Filename must be existing
      while((fp = fopen(FileName, "r")) == NULL){
      fprintf(stderr, "\nError: Unable to open file %s\nTry Again\n", FileName);
      printf("Enter Filename:");
      scanf(" %[^\n]s", FileName);
      }

      printf("Enter Shift(1-25):\n");
      scanf("%d", &shift); //Only taking positive value
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
			t_crypter(Message, shift, choice);
			break;

		case 2:
      shift = 26 - shift; //De-ciphering and for shorter code
			t_crypter(Message, shift, choice);
			break;
    
    // Pointer FILE* isn't used because name of file required
		case 3:
      f_crypter(FileName, shift, choice);
      break;

    case 4:
      shift = 26 - shift; //De-ciphering and for shorter code
      f_crypter(FileName, shift, choice);
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
