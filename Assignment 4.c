#include <stdio.h>

int main()
{
    int term1[2][2], term2[2][2], total[2][2];
    int i, j;
    printf("Enter Term 1 marks:\n");

    printf("LYMARAINA: ");
    scanf("%d", &term1[0][0]);

    printf("TIANNA: ");
    scanf("%d", &term1[0][1]);

    printf("GRACY: ");
    scanf("%d", &term1[1][0]);

    printf("BREANNA: ");
    scanf("%d", &term1[1][1]);

    printf("\nEnter Term 2 marks:\n");

    printf("LYMARAINA: ");
    scanf("%d", &term2[0][0]);

    printf("TIANNA: ");
    scanf("%d", &term2[0][1]);

    printf("GRACY: ");
    scanf("%d", &term2[1][0]);

    printf("BREANNA: ");
    scanf("%d", &term2[1][1]);

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            total[i][j] = term1[i][j] + term2[i][j];
        }
    }

    printf("\nTerm 1 Matrix:\n");

    printf("\t\tLYMARAINA\tTIANNA\n");
    printf("Marks\t\t%d\t\t%d\n", term1[0][0], term1[0][1]);

    printf("\t\tGRACY\t\tBREANNA\n");
    printf("Marks\t\t%d\t\t%d\n", term1[1][0], term1[1][1]);

    printf("\nTerm 2 Matrix:\n");

    printf("\t\tLYMARAINA\tTIANNA\n");
    printf("Marks\t\t%d\t\t%d\n", term2[0][0], term2[0][1]);

    printf("\t\tGRACY\t\tBREANNA\n");
    printf("Marks\t\t%d\t\t%d\n", term2[1][0], term2[1][1]);

    printf("\nResultant Matrix (Total Marks):\n");

    printf("\t\tLYMARAINA\tTIANNA\n");
    printf("Total\t\t%d\t\t%d\n", total[0][0], total[0][1]);

    printf("\t\tGRACY\t\tBREANNA\n");
    printf("Total\t\t%d\t\t%d\n", total[1][0], total[1][1]);

    return 0;
}
