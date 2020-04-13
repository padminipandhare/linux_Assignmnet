#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>

//Function Declaration
int ValidateInput(char num[]);
void BinaryConv(int);
void OctalcodeConv(int);
void HexacodeConv(int);

//Main function
int main()
{
    char num[10]={0};
    int input; // input is user given number
    printf("Please enter decimal no for conversion:\n");
    scanf("%s",num);

    //checking entered input is number or not
    if(ValidateInput(num))
        {
        input=atoi(num);
        if (input==0)
            printf("Binary conversion is : 0\n Octal conversion is : 0\n hexadecimal conversion is : 0\n");
        else
            if(input<0)
            {
                printf("Enter number is negative\n");
                return -1;//
            }

            else
                { // calling function of binary,octal and hexadecimal conversion
                printf("Conversion of decimal number into binary ,octal and hexadecimal are given below: \n");
                BinaryConv(input);
                OctalcodeConv(input);
                HexacodeConv(input);
                }
            return 0; //program run succefully
        }
    else
    {
       printf("Entered value  %s is not an integer\n ",num);
       return -1;      //exit from program
    }
}

//validating inputs
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
//Function Defination
void BinaryConv(int input)
{
     int n=0,rem,div=1,i;
     int arr[100];
     //Logic for binary conversion
     while(div!=0)
        {
            div=input/2;
            rem=input%2;  //will always get remider as 0 or 1 by dividing the number by 2 , it is used for binary conversion
            input=div;
            arr[n]=rem;  //appending reminder(0 or 1) in an array until divisor gets 0;
            n++;
        }
    //printing converted value
    printf("\nBinary no:\t");
    for(i=n-1;i>=0;i--)
    {
        printf("%d",arr[i]);
    }
}


void HexacodeConv(int input)
{
    int n=0,rem,div=1,i;
    int arr[100];
    //Logic for hexadecimal
    while(div!=0)
    {
        div=input/16;
        rem=input%16;//will always get remider between 0 to 15 by dividing the number by 2 , it is used for hexadecimal conversion
        arr[n]=rem;
        input=div;
        n++;
    }

    //printing converted value in hex format
    printf("\nhexadecimal no:\t");
    for(i=n-1;i>=0;i--)
    {
     printf("%x",arr[i]);
    }
}

void OctalcodeConv(int input)
{
    int n=0,rem,div=1,i;
    int arr[100];

    //Logic for Octal conversion
    while(div!=0)
    {
        div=input/8;
        rem=input%8;//printing converted value
        arr[n]=rem;
        input=div;
        n++;

    }
    //printing converted value
    printf("\nOctal no:\t");
    for(i=n-1;i>=0;i--)
    {
        printf("%d",arr[i]);
    }
}






































