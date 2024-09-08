#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long recursive_fib(int n) {
   if (n == 1) //shifts the n back by 1 making #1 fib = 0
        return 0;
    else if (n == 2)
        return 1;
    else
        return recursive_fib(n - 1) + recursive_fib(n - 2);
}

long long iterative_fib(int n) {
    if (n == 1) return 0; //shifts the n back by 1
    if (n == 2) return 1;
    int a = 0, b = 1, c;
    for (int i = 3; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main(int argc, char *argv[]) { 
   //Check if the number of arguments is correct
   if (argc != 4) {  
      printf("Usage: %s <integer> <r|i> <filename>\n", argv[0]); 
      return 1;
   }
   //Get the arguments
   int num1 = atoi(argv[1]);
   char mode = argv[2][0];
   char *filename = argv[3];
   //Read the file
   FILE *file = fopen(filename, "r");
   if (file == NULL) {
      printf("Error: File not found\n");
      return 1;
   }
   //store content
   char buffer[100];
   //get the string
   fgets(buffer, 100, file); 
   //convert the string to an integer
   int num2 = atoi(buffer);
   int fib = num1 + num2; 
   //determine modes
   if (mode == 'r') {
      fib = recursive_fib(fib);
   } else if (mode == 'i') {
      fib = iterative_fib(fib);
   } else {
      printf("Error: Invalid mode\n");
      return 1;
   }
   printf("%d", fib); //Result
   return 0;
}