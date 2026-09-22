%{
#include <stdio.h>
int flag = 0;
%}

%%
"hello"    { flag = 1; }
.          { }
\n         {
                if (flag)
                    printf("String matched\n");
                else
                    printf("String not matched\n");
                flag = 0;
           }
%%

int main() {
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
