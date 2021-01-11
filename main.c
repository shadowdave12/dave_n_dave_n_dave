#include <stdio.h>
#include "setList.h"
#include <stdlib.h>

int main (int argc, char *argv[]) {
    Set s1 = initialize();
    Set s2 = initialize();
    Set result = initialize();
    int choice;
    int elem;
    char setChoice;
    while (1)
    {
        system("cls");
    printf("\t0. Display\n");
    printf("\t1. Add\n");
    printf("\t2. Contains\n");
    printf("\t3. Get Union\n");
    printf("\t4. Intersection\n");
    printf("\t5. Difference\n");
    printf("\t6. Symmetric Difference\n");
    printf("\t7. Subset\n");
    printf("\t8. Disjoint\n");
    printf("\t9. Equal\n");
        printf("\tChoice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        	case 0:
        	{
        		printf("\nSet A:\n");
           		display(s1);
            	printf("Set B:\n");
            	display(s2);
            	printf("The Result Sets:\n");
            	display(result);
            	break;
        	}
        	case 1:
        	{
            	printf("\nChoose a set:\n");
            	printf("press 'a/A' for set A'\n");
            	printf("press 'b/B' for set B'\n");
            	scanf(" %c", &setChoice);
            	printf("Add element: ");
            		if (setChoice == 'A' || setChoice == 'a'){
                	scanf("%d",&elem);
                		while (contains(s1,elem) != -1)
                		{
                    		printf("Enter unique element!: ");
                    		scanf("%d",&elem);
                		}
                		s1 = add(s1, elem);
            		}
            	else if (setChoice == 'B' || setChoice == 'b'){
                	scanf("%d",&elem);
                	while (contains(s2,elem) != -1)
                	{
                    	printf("Please enter a unique element: ");
                    	scanf("%d",&elem);
                	}
                s2 = add(s2, elem);
            		}
            	break;
        	}
        	case 2:
        	{
            	printf("Choose a set:\n");
            	printf("press 'a/A' for set A'\n");
            	printf("press 'b/B' for set B'\n");
            	scanf(" %c", &setChoice);
            	printf("Please enter element to find: ");
            	scanf("%d", &elem);
            		if (setChoice == 'A' || setChoice == 'a'){
                		printf("Contains: %d\n", contains(s1, elem));
                	}
            		else if (setChoice == 'B' || setChoice == 'b'){
                		printf("Contains: %d\n", contains(s2, elem));
            		}
            	break;
        	}
        	case 3:
        	{
            	result = getUnion(result,s1,s2);
            	break;
        	}
	        case 4:
	        {
	            result = intersection(result,s1,s2);
	        	break;
	        }
	        case 5:
	        {
	            result = difference(result,s1,s2);
	            break;
	        }
	        case 6:
	        {
	            result = symmetricdifference(result,s1,s2);
	            break;
	        }
	        case 7:
	        {
	            printf("Is set A a subset of Set B: %d\n",subset(s1,s2));
	            break;
	        }
	        case 8:
	        {
	            printf("Is set A and B disjoint: %d\n",disjoint(s1,s2));
	            break;
	        }
	        case 9:
	        {
	            printf("Is set A equal set B: %d\n",equal(s1,s2));
	            break;
	        }
		}
	        system("pause");   
    }
   return 0;
}
