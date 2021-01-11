#include <stdio.h>
#include "setList.h"
#include <stdlib.h>

Set initialize()
{
    Set head;
    head = NULL;
    return head;
}
void display(Set s)
{
    nodeptr ptr;
    ptr = s;
    printf("[");
    while (ptr != NULL)
    {
        if (ptr->next == NULL)
            printf("%d", ptr->data);
        else
            printf("%d, ", ptr->data);
        ptr = ptr->next;
    }
    printf("]\n");
}

nodeptr makingNode(int item)
{
    nodeptr ptr;
    ptr = (nodeptr)malloc(sizeof(Node));
    ptr->data = item;
    ptr->next = NULL;
    return ptr;
}
Set add(Set s, int elem)
{
    nodeptr temp = makingNode(elem);
    temp->next = s;
    return temp;
}

int contains(Set s, int elem)
{
    nodeptr ptr;
    ptr = s;
    while (ptr != NULL)
    {
        if (ptr->data == elem)
            return 1;
        ptr = ptr->next;
    }
    return -1;
}
Set getUnion(Set result, Set s1, Set s2){
    result = initialize();
    nodeptr ptr1;
    ptr1 = s1;
    nodeptr ptr2;
    ptr2 = s2;
    while(ptr2 != NULL){
        result = add(result,ptr2->data);
        ptr2 = ptr2->next;
    }
    while(ptr1 != NULL){
        if(contains(result,ptr1->data) != 1){
           result = add(result,ptr1->data);
        }
        ptr1 = ptr1->next;
    }

    return result;
}
Set intersection(Set result, Set s1, Set s2){
    result = initialize();
    nodeptr ptr;
    ptr = s1;

    while(ptr != NULL){
        if(contains(s2,ptr->data) ==1){
               result = add(result,ptr->data);
        }
        ptr = ptr->next;
    }
    return result;
}
Set difference(Set result, Set s1, Set s2){
    result = initialize();
    nodeptr ptr;
    ptr = s1;
    while(ptr != NULL){
        if(contains(s2,ptr->data) != 1)
            result = add(result,ptr->data);
        ptr = ptr->next;
    }
    return result;
}
Set symmetricdifference(Set result, Set s1, Set s2){
    result = initialize();
    nodeptr ptr;
    ptr = s1;
    nodeptr ptr2;
    ptr2 = s2;
    while(ptr != NULL){
        if(contains(s2,ptr->data) != 1)
            result = add(result,ptr->data);
        ptr = ptr->next;
    }

    while(ptr2 != NULL){
        if(contains(s1,ptr2->data) != 1)
            result = add(result,ptr2->data);
        ptr2 = ptr2->next;
    }

    return result;
}
int subset(Set s1, Set s2)
{
    int tag = 0;
    nodeptr ptr1 = s1;
    nodeptr ptr2 = s2;
    int counter = 0;
    
    while(ptr1 != NULL){
        ptr2 = s2;
        while (ptr2 != NULL)
        {
            if(ptr1->data == ptr2->data)	
                counter++;

            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    if(Length(s1) == counter)
        return 1;
    return -1;
} 

int disjoint(Set s1, Set s2){
    nodeptr ptr;
    ptr = s1;
    while(ptr != NULL){
        if(contains(s2,ptr->data) == 1)
            return -1;
        ptr = ptr->next;
    }
    return 1;
}
int equal(Set s1, Set s2)
{
    if(subset(s1,s2) == 1 && subset(s2,s1) == 1)
        return 1;
    return -1;
} 
int Length(Set n){
    nodeptr ptr;
    ptr = n;
    int count = 0;
    while(ptr != NULL){

        count++;
        ptr = ptr->next;
    }
    return count;
}

