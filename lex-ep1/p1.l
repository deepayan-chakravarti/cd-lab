%{
#include <stdio.h>
#include <stdlib.h>
float num1, num2, result;
char op;
%}
%%
[0-9]+"."[0-9]+    { num2 = atof(yytext); }
[0-9]+             { num2 = atof(yytext); }
[+\-*/]            { op = yytext[0]; num1 = num2; }
\n                 {
                       switch(op) {
                           case '+': result = num1 + num2; break;
                           case '-': result = num1 - num2; break;
                           case '*': result = num1 * num2; break;
                           case '/': result = num1 / num2; break;
                       }
                       printf("The Answer = %f\n", result);
                    }
%%
int main() {
    yylex();
    return 0;
}
int yywrap() {
    return 1;
}
