/*Name: Dejos, Gregory Dave D.  Section: G3-C1*/
#include<stdio.h>
#include<stdlib.h>

int UP(int num[], int Size);
int P_NRZL(int num[], int Size);
int P_NRZI(int num[], int Size);
int P_RZ(int num[], int Size);
int P_BM(int num[], int Size);
int P_BDM(int num[], int Size);
int B_AMI(int num[], int Size);
int B_P(int num[], int Size);
int linecoding(int num[], int Size);

int main(){
	int i,choices, Size=12, u;
	int num[Size];
	printf("Input a binary number (1/0):");
		for(i=0; i<Size;i++){
			printf("\n%d:  ",u);
			scanf("%d", &num[i]);
			u++;
		}
		system("cls");
			for(i=0; i<Size;i++){
				printf("%d  ",num[i]);
			}
	do{
		
		printf("\n\n\tTypes of Line Coding:\n");
		printf("\t[1] Unipolar NRZ\n");
		printf("\t[2] Polar NRZ-L\n");
		printf("\t[3] Polar NRZ-I\n");
		printf("\t[4] Polar RZ\n");
		printf("\t[5] Polar Biphase Manchester\n");
		printf("\t[6] Polar Biphase Differential Manchester\n");
		printf("\t[7] Bipolar AMI\n");
		printf("\t[8] Bipolar Pseudoternary\n");
		printf("\t[0] Exit\n");
		printf("\n\tEnter a number [1-0]: ");
		scanf("%d", &choices);
			
				switch(choices){
					case 1:
						system("cls");
						UP(num, Size);
						break;
					case 2:
						system("cls");
						P_NRZL(num, Size);
						break;
					case 3:
						system("cls");
						P_NRZI(num, Size);
						break;
					case 4:
						system("cls");
						P_RZ (num, Size);
						break;
					case 5:
						system("cls");
						P_BM( num, Size);
						break;
					case 6:
						system("cls");
						P_BDM( num, Size);
						break;	
					case 7:
						system("cls");
						B_AMI( num,Size);
						break;
					case 8:
						system("cls");
						B_P(num, Size);
						break;
					case 0:
						printf("\tExiting...");
						break;
					default:
						printf("\n\tInvalid Input");
						break;	
		
		}
	}while(choices !='\0');
}
	
	int UP(int num[], int Size){
		int i;
		printf("\tUnipolar NRZ:\n");
		printf("\tThe Input:");
    	for(i = 0; i < Size; i++){
        	printf(" %d", num[i]);
		}
		
		printf("\n\tThe Output:");
		
			for(i = 0; i < Size; i++){
				if(num[i] == 1){
					printf(" hi");
				}
				if(num[i] == 0){
					printf(" lo");
				}
			}
	return 0;
	}
	
	int P_NRZL(int num[], int Size){
		int i;
		printf("\tPolar NRZ-L:\n");
		printf("\tThe Input:");
    	for(i = 0; i < Size; i++){
        	printf(" %d", num[i]);
			}
			
		printf("\n\tThe Output:");
		
		for(i = 0; i < Size; i++){
			if(num[i] == 1){
				printf(" neg");
		}
			if(num[i] == 0){
				printf(" pos");
				}
			}
	return 0;
	}
	
	int P_NRZI(int num[], int Size){
		
	int i, w = 0, hl;
	printf("\tPolar NRZ-I:\n");
	printf("\tThe Input:");
    for(i = 0; i < Size; i++){
        printf(" %d", num[i]);
	}
	i = 0;
	printf("\n\tEnter 1 for initially high or 0 for initally low: ");
	scanf("%d", &hl);
	printf("\tThe Output:");
	
		if(hl == 1){
			while(i < Size){
				if(num[i] != 0){
					if(num[i] == 1 && w == 0){								
						w=5;
						printf("  neg-inv");	
						++i;
					}
						if(num[i] == 1 && w == 5){
							w = 6;
							printf("  pos-inv");
							++i;
						}
							if(num[i] == 1 && w == 6){
								w = 5;
								printf("  neg-inv");
								++i;
							}
				}
				if(num[i] == 0){
					if(w == 5){
						printf("  neg-no-inv");
					}
					else{
						printf("  pos-no-inv");
					}
				++i;
				}
			}
		}
		if(hl == 0){
			while(i < Size){
				if(num[i] != 0){
					if(num[i] == 1 && w == 0){								
						w=5;
						printf("  pos-inv");
							++i;
					}
						if(num[i] == 1 && w == 5){
							w=6;
							printf("  neg-inv");	
							++i;
						}
							if(num[i] == 1 && w == 6){
								w = 5;
								printf("  pos-inv");
								++i;
							}
				}
				if(num[i] == 0){
					if(w == 5){
						printf("  pos-no-inv ");
					}
					else{
					printf("  neg-no-inv ");
					}
				++i;
				}
			}
		}
	return 0;
	}
	
	int P_RZ(int num[], int Size){
	int i;
	printf("\tPolar RZ:\n");
	printf("\t The Input:");
	
    for(i = 0; i < Size; i++){
        printf(" %d", num[i]);
	}
	
	printf("\n\tThe Output:");
	
		for(i = 0; i < Size; i++){
			if(num[i] == 1){
				printf(" posRZ");
			}
			if(num[i] == 0){
				printf(" negRZ");
			}
		}
	return 0;
	}
	
	int P_BM(int num[], int Size){
	int i; 
	printf("\tPolar Biphase Manchester:\n");
	printf("\t The Input:");
	
    for(i = 0; i < Size; i++){
        printf(" %d", num[i]);
	}
	
	printf("\n\tThe Output:");
		for(i = 0; i < Size; i++){
			if(num[i] == 1){
				printf(" nTp");
			}
			if(num[i] == 0){
				printf(" pTn");
			}
		}
	return 0;
	}
	
	int P_BDM(int num[], int Size){
		
	int i, k, temp = 1, hl;
	char changeN[4];
	char changeIN[4];
	
	printf("\tPolar Biphase Differential Manchester:\n");
	printf("\t The Input:");
	
    for(i = 0; i < Size; i++){
        printf(" %d", num[i]);
	}
	printf("\n\tEnter 1 for initially high or 0 for initally low: ");
	scanf("%d", &hl);
	printf("\n\tThe Output:");
	i=0;
	if(hl == 1){
		while (i <= Size){
			if(i == 0) {
				changeN[0] = 'p';
				changeN[1] = 't';
				changeN[2] = 'n';
					if(num[i] == 1 && num[temp] == 1){
						changeIN[0] = 'n';
						changeIN[1] = 'o';
						changeIN[2] = 'o';
						printf("  pTn-no inv  ");
					}
						if(num[i] == 1 && num[temp] == 0){
							changeIN[0] = 'i';
							changeIN[1] = 'n';
							changeIN[2] = 'v';
							printf("  pTn-inv  ");
						}
							if(num[i] == 0 && num[temp] == 1 || num[temp] == 0){
								changeIN[0] = 'i';
								changeIN[1] = 'n';
								changeIN[2] = 'v';
								printf("  pTn-inv  ");
							}
			}
			else if(i == Size){
				if(memcmp(changeN, (char[]){'p','t','n'}, sizeof free) == 0){
					printf("  pTn  ");
				}
				else{
					printf("  nTp  ");
				}
			}
			
		else {
			if(num[i] == 1 && num[temp] == 0){
				if(memcmp(changeN, (char[]){'p','t','n'}, sizeof free) == 0){
					printf("  nTp-inv");
					changeN[0] = 'n';
					changeN[1] = 't';
					changeN[2] = 'p';
				}
				else{
					printf("  pTn-inv  ");
					changeN[0] = 'p';
					changeN[1] = 't';
					changeN[2] = 'n';
				}
			changeIN[0] = 'i';
			changeIN[1] = 'n';
			changeIN[2] = 'v';
			}
				if(num[i] == 1 && num[temp] == 1){
					if(memcmp(changeN, (char[]){'p','t','n'}, sizeof free) == 0){
						printf("  nTp-no inv  ");
						changeN[0] = 'n';
						changeN[1] = 't';
						changeN[2] = 'p';
					}
					else{
						printf("  pTn-no inv  ");
						changeN[0] = 'p';
						changeN[1] = 't';
						changeN[2] = 'n';
					}
				changeIN[0] = 'n';
				changeIN[1] = 'o';
				changeIN[2] = 'o';	
				}
					if(num[i] == 0 && num[temp] == 1){
						if(memcmp(changeN, (char[]){'p','t','n'}, sizeof free) == 0){
							printf("  pTn-no inv  ");
							changeN[0] = 'p';
							changeN[1] = 't';
							changeN[2] = 'n';
						}
						else{
							printf("  nTp-no inv  ");
							changeN[0] = 'n';
							changeN[1] = 't';
							changeN[2] = 'p';
						}
					changeIN[0] = 'n';
					changeIN[1] = 'o';
					changeIN[2] = 'o';
					}
						if(num[i] == 0 && num[temp] == 0) {
							if(memcmp(changeN, (char[]){'p','t','n'}, sizeof free) == 0){
								printf("  pTn-inv  ");
								changeN[0] = 'p';
								changeN[1] = 't';
								changeN[2] = 'n';
							}
							else{
								printf("  nTp-inv  ");
								changeN[0] = 'n';
								changeN[1] = 't';
								changeN[2] = 'p';
							}
						changeIN[0] = 'i';
						changeIN[1] = 'n';
						changeIN[2] = 'v';	
						}
			}
		++i;
		++temp;
		}
	}
	
	if(hl == 0){
		while (i <= Size){
			if(i == 0) {
				changeN[0] = 'n';
				changeN[1] = 't';
				changeN[2] = 'p';
				if(num[i] == 1 && num[temp] == 1){
					changeIN[0] = 'n';
					changeIN[1] = 'o';
					changeIN[2] = 'o';
					printf("  nTp-no inv  ");
				}
					if(num[i] == 1 && num[temp] == 0){
						changeIN[0] = 'i';
						changeIN[1] = 'n';
						changeIN[2] = 'v';
						printf("  nTp-inv  ");
					}
						if(num[i] == 0 && num[temp] == 1 || num[temp] == 0){
							changeIN[0] = 'i';
							changeIN[1] = 'n';
							changeIN[2] = 'v';
							printf("  nTp-inv  ");
						}
			}
			else if(i == Size){
				if(memcmp(changeN, (char[]){'p','t','n'}, sizeof free) == 0){
					printf("pTn  ");
				}
				else{
					printf("nTp  ");
				}
			}
			
		else{
		if(num[i] == 1 && num[temp] == 0){
			if(memcmp(changeN, (char[]){'p','t','n'}, sizeof free) == 0){
				printf("  nTp-inv");
				changeN[0] = 'n';
				changeN[1] = 't';
				changeN[2] = 'p';
			}
			else{
				printf("  pTn-inv");
				changeN[0] = 'p';
				changeN[1] = 't';
				changeN[2] = 'n';
			}
		changeIN[0] = 'i';
		changeIN[1] = 'n';
		changeIN[2] = 'v';
		}
			if(num[i] == 1 && num[temp] == 1){
				if(memcmp(changeN, (char[]){'p','t','n'}, sizeof free) == 0){
					printf("  nTp-no inv  ");
					changeN[0] = 'n';
					changeN[1] = 't';
					changeN[2] = 'p';
				}
				else{
					printf("  pTn-no inv  ");
					changeN[0] = 'p';
					changeN[1] = 't';
					changeN[2] = 'n';
				}
			changeIN[0] = 'n';
			changeIN[1] = 'o';
			changeIN[2] = 'o';	
				}
					if(num[i] == 0 && num[temp] == 1){
						if(memcmp(changeN, (char[]){'p','t','n'}, sizeof free) == 0){
							printf("  pTn-no inv  ");
							changeN[0] = 'p';
							changeN[1] = 't';
							changeN[2] = 'n';
						}
						else{
							printf("  nTp-no inv  ");
							changeN[0] = 'n';
							changeN[1] = 't';
							changeN[2] = 'p';
						}
					changeIN[0] = 'n';
					changeIN[1] = 'o';
					changeIN[2] = 'o';
					}
						if(num[i] == 0 && num[temp] == 0) {
							if(memcmp(changeN, (char[]){'p','t','n'}, sizeof free) == 0){
								printf("  pTn-inv  ");
								changeN[0] = 'p';
								changeN[1] = 't';
								changeN[2] = 'n';
							}
							else{
								printf("  nTp-inv  ");
								changeN[0] = 'n';
								changeN[1] = 't';
								changeN[2] = 'p';
							}
						changeIN[0] = 'i';
						changeIN[1] = 'n';
						changeIN[2] = 'v';	
						}
			}
		++i;
		++temp;
		}
	}
	else{
	}
}
	
	int B_AMI(int num[], int Size){
	int i = 0, k = 0;
	printf("\tBipolar AMI:\n");
	printf("\tThe Input:");
	
    for(i = 0; i < Size; i++){
        printf(" %d", num[i]);
	}
	printf("\n\tThe Output:");
	i = 0;
	while(i<Size){
		if(num[i] != 0){
			if(num[i] == 1 && k == 0){								
				k = 5;
				printf("  pos");	
				++i;
			}
				if(num[i] == 1 && k == 5){
					k = 6;
					printf(" neg");
					++i;
				}
					if(num[i] == 1 && k == 6){
						k= 5;
						printf("  pos");
						++i;
					}
		}
		if(num[i] == 0){
			printf("  zero");
			++i;
		}
	}
	return 0;
		
	}
	
	int B_P(int num[], int Size){
	int i=0, re = 0;
	printf("\tBipolar Pseudoternary:\n");
	printf("\tThe Input:");
    for(i = 0; i < Size; i++){
        printf(" %d",num[i]);
	}
	printf("\n\tThe Output:");
	i = 0;
	while(i < Size){
		if(num[i] != 1){
			if(num[i] == 0 && re == 0){								
				re = 5;
				printf("  pos");	
				++i;
			}
				if(num[i] == 0 && re == 5){
					re = 6;
					printf("  neg");
					++i;
				}
					if(num[i] == 0 && re == 6){
						re = 5;
						printf("  pos");
						++i;
					}
		}
		if(num[i] == 1){
			printf("  zero");
			++i;
		}
	}
	return 0;
	}
	

