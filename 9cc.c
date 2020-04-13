
#include <stdio.h>
#include <stdlib.h>

 int main(int argc, char **argv){
   if (argc != 2){
     fprintf(stderr, "Invalid number of argument\n");
     return 1;
   }

   char *p = argv[1];

   printf(".intel_syntax noprefix\n");
   printf(".global main\n");
   printf("main:\n");
   printf("    mov rax, %ld\n", strtol(p, &p, 10));

   while(*p){
     if(*p == '+'){
       p++;
       printf("    add rax, %ld\n", strtol(p, &p, 10));
       //continue; // I wanted to avoid "continue". Insted, I use "else if":
     }else if(*p == '-'){
       p++;
       printf("    sub rax, %ld\n", strtol(p, &p, 10));
       // Again, original code has "continue;" here.
     }else{
       // In the original code, the following two lines are put outside of the if statement.
       fprintf(stderr, "Unknown character -- '%c'\n", *p);
       return 1;
     }
   }
   
   printf("    ret\n");
   return 0;
 }

