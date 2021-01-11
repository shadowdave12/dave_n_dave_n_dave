#include <stdio.h>
#include <windows.h>
#define SIZE 10

void initSeats(int seats[], int size) {
	int i;
	
	for (i = 0 ; i < size ; i++)	
		seats[i] = 0;
	return;
}

void displaySeats(int seats[], int size) {
	int i;
	
	printf("\tWELCOME TO GDD AIRLINES!");
	printf("\n\tType 1 for First Class Section");
	printf("\n\tType 2 for Economy Class Section");
	printf("\n\tFirst Class Section:");
		for (i=0; i < size/2 ; i++)	
			printf("[%d] ",seats[i]);
	
	printf("\n\tEconomy Class Section:");
		for (i=5; i < size ; i++)	
			printf("[%d] ",seats[i]);
	
}

int assignFirstClass(int seats[], int size) {
	int i;
	
	
	for	(i = 0 ; i < size/2 ; i++) { 
		if(seats[i] == 0) {
			seats[i] += 1; return i; }
	}
	return -1; 
}

int assignEconomy(int seats[], int size) {
	
	int i;
	
	for	(i = 5 ; i < size ; i++) { 
		if(seats[i] == 0) { 
			seats[i] += 1; return i; }
	}
	return -1; 
}

void exits(){
	 printf("THANK YOU!");
	 printf("NEXT FLIGHT LEAVES IN 3 HOURS!");
	exit(0);
}

int assignSeat(int seats[], int seatType) {
	
	
	int seat;
	char choice; 
	
	if (seatType == 1)	{ 
	seat = assignFirstClass (seats, SIZE);
	
	
		if (seat == -1){
			printf("\n\tThe First Class Section is Full.");
			printf("Would you like to reserved in Economy Section [y/n] ? ");
			scanf(" %c",&choice);
		
			while (choice != 'y' && choice != 'n'){
				printf("INVALID!");
				printf("  ");
		  		scanf(" %c",&choice);
			} 
		}
	
			if (choice == 'y'){
				system("cls");
				return seat = assignEconomy (seats,SIZE); 	
			}
				if (choice == 'n'); 
				exits();
	}
	
	
	if (seatType == 2) { 
		seat = assignEconomy (seats, SIZE);
	
	
		if (seat == -1){
			printf("The Economy Class Section is full!");
			printf("Would you like to reserved in First Class Section [y/n] ? ");
			scanf(" %c",&choice);
		
		
			while (choice != 'y' && choice != 'n'){
				printf("INVALID!");
				printf("  ");
	  			scanf(" %c",&choice);
			} 
		}
		
			if (choice == 'y'){
				system("cls");
				return seat = assignFirstClass (seats,SIZE); 
			}
	
				if (choice == 'n') 
				exits();
		
	}
	
	if (seatType != 1 && seatType != 2) {
		printf("INVALID TYPE!");
		return -1;	
	}
	
	return seat;
	
}

int Occupied (int seats[],int size) {
	
	int i;
	int counter = 0;
	
	
		for (i = 0; i < size ; i++) {
			if (seats[i] == 1) 
				counter++;	
		}
		
	if (counter == size) 
		return 1;
	
	return 0;
}


void boardPass(int seat) {
	
	printf("BOARD PASS");
	
	if (seat != -1){
		
		if (seat >= 0 && seat < 5){	
			 printf("First Class Section");
		}
	
		else {	
    	printf("Economy Class Section");
		}
	
	printf("Seat Number : %d",seat+1);
	}
	
}




