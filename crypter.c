#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "crypter.h"


void t_crypter(char *Message, int shift, int choice){
  char *fMessage;

  fMessage = (char*) malloc(sizeof(Message)); //Allocating memory based on message size

  //Algorithm
	for (int i = 0; *(Message+i)!='\0'; i++) {
		if (*(Message+i) >= 'A' && *(Message+i) <= 'Z') {
			*(fMessage+i) = (((*(Message+i) - 'A') + shift) % 26 + 'A');
		}
		else if (*(Message+i) >= 'a' && *(Message+i) <= 'z') {
			*(fMessage+i) = (((*(Message+i) - 'a') + shift) % 26 + 'a');
		}
    else{
      *(fMessage+i) = *(Message+i);
    }
  }

  if(choice == 1){
    printf("\nEncrypted text:%s\n", fMessage);
  }
  else if(choice == 2){
    printf("\nDecrypted text:%s\n", fMessage);
  }

  free(fMessage); //Free memory
  
}


void f_crypter(char *filename1, int shift, int choice){
  FILE *fp1, *fp2;
  char *filename2;
  int ch;
  fp1 = fopen(filename1, "r"); //Reading file
  const char *prefix_enc = "encrypt_";
  const char *prefix_dec = "decrypt_";

  if(choice == 3){
  filename2 = malloc(strlen(filename1) + strlen(prefix_enc) + 1); //New filename2 based on filename1 length and prefix + \0
  
  //String concatenation but using prefix and filename1 as const
  strcpy(filename2, prefix_enc); 
  strcat(filename2, filename1);
    if ((fp2 = fopen(filename2, "w")) == NULL) {
      fprintf(stderr, "\nError: Unable to open file %s\n", filename1);
      exit(EXIT_FAILURE);
    }
  free(filename2); //Free memory
  }

  if(choice == 4){
  filename2 = malloc(strlen(filename1) + strlen(prefix_dec) + 1); //New filename2 based on filename1 length and prefix + \0

  //String concatenation but using prefix and filename1 as const
  strcpy(filename2, prefix_dec);
  strcat(filename2, filename1);
    if ((fp2 = fopen(filename2, "w")) == NULL) {
      fprintf(stderr, "\nError: Unable to open file %s\n", filename1);
      exit(EXIT_FAILURE);
    }
  free(filename2); //Free memory
  }
  
  //Alogrithm
  while ((ch = getc(fp1)) != EOF) {
    if (ch >= 'A' && ch <= 'Z') {
      putc(((ch - 'A') + shift) % 26 + 'A', fp2);
    } 
    else if (ch >= 'a' && ch <= 'z') {
      putc(((ch - 'a') + shift) % 26 + 'a', fp2);
    } 
    else {
      putc(ch, fp2);
    }
  }
  fclose(fp1);
  fclose(fp2); //Close files
  printf("Done!\n");
}