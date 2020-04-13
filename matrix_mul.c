#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int ValidateInput(char num[]);//function declaration
int main()
{
      char row_1[5],col_1[5],row_2[5],col_2[5];
      char row1,col1,row2,col2;
      int i,j,k,c=0;

    //Enter first matrix dimension
      printf("Enter 1st matrix row & column\n");
      scanf("%s%s",row_1,col_1);
      //validating dimension of first matrix
      if((ValidateInput(row_1)!=1) | (ValidateInput(col_1)!=1))
            {printf("Enter row %s and col %s is not an integer\n",row_1,col_1);
            return -1;//exit from the program
            }
     row1=atoi(row_1);
     col1=atoi(col_1);
    //Enter second matrix Dimension
      printf("Enter 2nd matrix row & column\n");
      scanf("%s%s",row_2,col_2);
    //validating dimension of second matrix
      if((ValidateInput(row_2)!=1)| (ValidateInput(col_2)!=1))
            {printf("Enter row %s and col %s is not an integer\n",row_1,col_1);
            return -1;
            }
      row2=atoi(row_2);
      col2=atoi(col_2);
    //allocate dimension of input matrix and output matrix
      int mat1[row1][col1];
      int mat2[row2][col2];
      int m3[row1][col2];

    //logic for multiplication
    if (col1==row2) // should match column of 1st matrix to the row of 2nd matrix
       {

            printf("Enter 1 matrix values\n");
            for(i=0;i<row1;i++)
                {for(j=0;j<col1;j++)
                    scanf("%d",&mat1[i][j]);
                }

            printf("Enter 2 matrix values\n");
            for(i=0;i<row2;i++)
                {for(j=0;j<col2;j++)
                    scanf("%d",&mat2[i][j]);
                }

           // Matrix multiplication
            for(i=0;i<row1;i++)
            {  for(j=0;j<col2;j++)
               {
                    for(k=0;k<row2;k++)
                        c=(mat1[i][k] * mat2[k][j])+c;
                    m3[i][j]=c;
                    c=0;
                }
            }

            //Display result of multiplication
            for(i=0;i<row1;i++)
                {   printf("\n");
                    for(j=0;j<col2;j++)
                        printf("%d\t",m3[i][j]);
                }
            return 0;//successfully executed program
       }
    else
       {
        printf("Error:Matrix multiplication not possible,Incompatible size of matrix\n");
        return -1; //Execution failed due to improper dimension
       }

}

//Validating input number,if it is not valid it will exit.
int ValidateInput(char num[])
{
    int i;
    for(i=0;num[i]!='\0';i++)
    {
        if(!(isdigit(num[i])))
            return 0;
    }
    return 1;
}
