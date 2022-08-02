#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/********************two ways to declare,they are all the same**************************/

// //A simple way to declare
// #define MAXSIZE 10
// struct Node{
//     int data;
//     int next;
// };
// struct Node a[MAXSIZE];

// Another way
typedef struct Node
{
    int data;
    int next;
} SLinkList[MAXSIZE];
// SLinkList a;//means that a is an array, 10 is size, every element is Node

/**********Initialize**********************/