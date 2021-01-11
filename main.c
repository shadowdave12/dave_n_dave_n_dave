#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

#define SIZE 100
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	Stack stack = newStack();
	stackItem string[SIZE];
	
	int checksValid;
	char option;
	
	do {
		system("cls");
		printf("\n\t-STACKING-");
		
		
		printf("\n\n\tPlease Enter string of symbols : ");
		fgets(string, SIZE, stdin); 
		removeNewline(string); 
		
		
		while (Symbols(string) != 1) {
			printf("\n\tThe Inputted string is invalid!");
			printf("\n\tPlease Enter string of symbols : ");
			fflush(stdin); //clears input buffer
			fgets(string, 50, stdin);
			removeNewline(string); 
		}
			
		checksValid = isValid(stack, string);
		
		printf("\nStack : "); display(stack);
		
		
		if (checksValid == 1)
			printf("\n\n%s - It matches!",string);
		else
			printf("\n\n%s - Conflicted",string);
			
		
		freeStack(stack);
		
		
		printf("\n\n\n\tDo you want to continue or not? (y/n) : ");
		scanf(" %c",&option);
			
			while (option != 'n' && option != 'y') {
				fflush(stdin);
				printf("\n\n\tInvalid Input!");
				printf("\n\tDo you want to continue or not?(y/n) : ");
				scanf(" %c",&option);
			}
		fflush(stdin); 
	} while (option == 'y');
		printf("\nTHANK YOU!\n");
}
