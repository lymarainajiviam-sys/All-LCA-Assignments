#include <stdio.h>
int main() {
char op;
int a, b, results;
printf("Enter operator (+, -, *, /, l): ");
scanf(" %c", &op);
printf("Enter two numbers: ");
scanf("%d %d", &a, &b);
switch (op) {
case '+' : results= a + b; printf("Result = %d", results); break;
case '-' : results= a - b; printf("Result = %d", results); break;
case '*' : results= a * b; printf("Result = %d", results); break;
case 'l' : results= a % b; printf("%d", results); break;
case '/' :
if (b != 0) {
results = a/b ; printf("Results = %d", results);
} else {
printf("Cannot divide by zero");
}
break;
default: printf("Invalid operator");
}
return 0;
}
