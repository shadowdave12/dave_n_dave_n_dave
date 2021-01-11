#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stack.h"

Stack newStack() {
	Stack stack;
	stack = (Stack) malloc (sizeof(STACK_HEAD));
	stack -> top = NULL;
	stack -> count = 0;
	return stack;
}

void freeStack(Stack s){
	Nodeptr temp;
	while(s->top!=NULL){
		temp = s->top;
		s->top = s->top->next;
		temp->next = NULL; 
		free(temp);
		(s->count)--;
	}
}
Nodeptr createNode (char item) {
	Nodeptr ptr;
	ptr = (Nodeptr) malloc(sizeof(Node));
	ptr -> data = item;
	ptr -> next = NULL;
	return ptr;
}

void push(Stack s,stackItem item) { 
	
	Nodeptr temp = createNode(item);
	temp -> next = s -> top;
	s -> top = temp;
	s -> count++;
}

void pop(Stack s) {
	Nodeptr temp;
	temp = s -> top;
	s -> top = temp -> next;
	temp -> next = NULL;
	free(temp);
	s -> count --;
}

stackItem stackTop(Stack s) {
	Nodeptr temp = s -> top;
	
	return temp -> data;
}

int isEmpty(Stack s) {
	int isEmpty = 0;
	if (s -> top == NULL)
		isEmpty = 1;
		
	return isEmpty;
}

void display(Stack s) {
	Nodeptr ptr;
	ptr = s -> top;
	while (ptr != NULL) {
		printf("%c", ptr -> data);
		ptr = ptr -> next;
	}
}

int isValid(Stack opening ,stackItem symbol[]) {
	int i;
	stackItem topOpening;
	int isValid = 1;
		
			for(i = 0; symbol[i] != '\0' ; i++) {
				if(StartSymbol(symbol[i]))
					push(opening, symbol[i]);
			 else {
			 	
				if(!isEmpty(opening)) {
					if(EndSymbol(symbol[i])) {
						topOpening = stackTop(opening);
							//Check if the symbols matched
						if (Matches(topOpening, symbol[i]))
							pop(opening); 
						else {
							isValid = 0;
							break; }
					}
				}
				else {
					isValid = 0;
					break; }
					
				}
			}
		
		if (!isEmpty(opening))
			isValid = 0;
				
	return isValid;
}

int Symbols(stackItem symbol[]) {
	int i;
	int Symbols = 1;
		for (i = 0; symbol[i] != '\0' ; i++) {
			if (StartSymbol(symbol[i]) || EndSymbol(symbol[i])) 
				continue;
			else {
				Symbols = 0;
				break;
			}
		}
	return Symbols;
}

int Matches(stackItem opening, stackItem closing) {
	stackItem openingSymbols[] = { '{', '[', '('  };
	stackItem closingSymbols[] = { '}', ']', ')' };
	int index;
	int i;
	int Matches = 0;
	
		for (i = 0; openingSymbols[i] != '\0' ; i++) {
				if (opening == openingSymbols[i]) {
					index = i;
					break;
				}
		}
	
	if (closing == closingSymbols[index])
		Matches = 1;
	
	return Matches;
}

int StartSymbol (stackItem item) { 
	stackItem StartingSymbols[] = { '{', '[', '(' };
	int StartSymbol = 0;
	int i;
		for (i = 0; StartingSymbols[i] != '\0' ; i++) {
				if (item == StartingSymbols[i]) {
					StartSymbol = 1;
					break;
				}
		}
	
	return StartSymbol;
}


int EndSymbol (stackItem item) {
		stackItem LastSymbols[] = { '}', ']', ')' };
	int EndSymbol = 0;
	int i;
		for (i = 0; LastSymbols[i] != '\0' ; i++) {
				if (item == LastSymbols[i]) {
					EndSymbol = 1;
					break;
				}
		}
	
	return EndSymbol;
}


void removelines(stackItem arr[]) {
	int len = strlen(arr); 
		
		if (arr[len] == '\0' && arr[len - 1] == '\n')
			arr[len - 1] = '\0';
}

