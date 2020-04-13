#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>// this header file for isdigit() function.

//Function declaration
int menu(int);//select option is Display data or create data
int ValidateInput(char num[]);//validation of inputs

//Structure has subject and their respective marks.
struct subject{
    char sub[20];
    int mark;
};

//It has student information.
struct stud{
    int roll_no;
    char name[20];
    struct subject sub1[5];

};

//Main program
int main()
{
    char user[2];
    int user_ip;
    printf("Do you want to create student databse\n Please select option.\n1.YES  2.NO\n");
    scanf("%s",user);
    //chaecking inputs
    if(ValidateInput(user))
    {
        user_ip=atoi(user);
        if((user_ip==1) | (user_ip==2))
            if(menu(user_ip))//calling menu program
                return 0;
            else
                return -1;
        else
           {
            printf("Invalid input %s\n",user);
            return -1;

            }
    }
    else
    {
        printf("Invalid input %s\n",user);
         return -1;

    }

}

//function defination of validating inputs
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


int menu(int u)
{
    //temporary variable for calculation
   int  n,i,user,rollno=0,j;
   float avg_s=0,avg_c=0,count=0;
   int sum_st=0,max=0;
   int sum_m=0,sum_e=0,sum_s=0,sum_h=0,sum_g=0;
   //file pointer
   FILE *fp;
   struct subject topics[5]={{"math",0},{"Eng",0},{"Science",0},{"History",0},{"Geo",0}};
   struct stud s;
   struct stud s1;

   switch(u)
{
//case 1 is used to create student database.
   case 1:
       fp=fopen("student.txt","ab+");
       printf("\nPlease enter the number of student record should be placed in database\n");
       scanf("%d",&n);
       for(i=0;i<n;i++)
        {   printf("\nEnter student Roll no,Name \n");
            scanf("%d%s",&s.roll_no,s.name);
            printf("Enter marks of respective subject\n");
            for(j=0;j<5;j++)
            {printf("\n%s\t",topics[j].sub);

             strcpy(s.sub1[j].sub,topics[j].sub);
             scanf("%d",&s.sub1[j].mark);
            }
            fwrite(&s,sizeof(s),1,fp);
        }
       fclose(fp);
       break;

//in case to we are displaying student information based on their roll no
   case 2:
      fp=fopen("student.txt","rb+");
      printf("\nDo you want student details\n1.YES 2 .NO\n");
      scanf("%d",&u);
      if(u==1)
      {   printf("\nenter student roll no\n");
          scanf("%d",&user);
          while(fread(&s1,sizeof(s1),1,fp)>0)
               {
                   count=count+1;
            //Display all student information
            // printf("\n%d\t%s\n",s1.roll_no,s1.name);
            //  for(j=0;j<5;j++)
            //{printf("%s\t%d\n",s1.sub1[j].sub,s1.sub1[j].mark);}

            //student databse and average marks of student.
                    if(s1.roll_no==user)
                      {
                          rollno=1;
                          max=0;
                          avg_s=0;
                          sum_st=0;
                          printf("\n%d\t%s\n",s1.roll_no,s1.name);
                              for(j=0;j<5;j++)
                                {
                                    printf("%s\t%d\n",s1.sub1[j].sub,s1.sub1[j].mark);
                                    sum_st=sum_st+s1.sub1[j].mark;
                                    if(max<=s1.sub1[j].mark)
                                        max=s1.sub1[j].mark;
                                }
                         avg_s=sum_st/(5.0);
                         printf("\nAverage mark of student is %f\n\nMaximum mark of student is %d\n",avg_s,max);
                      }

                  //for displaying average mark of whole class of particular subject
                  for(j=0;j<5;j++)
                        {if (strcmp(s1.sub1[j].sub,topics[0].sub)==0)
                         sum_m=sum_m+s1.sub1[j].mark;
                         if (strcmp(s1.sub1[j].sub,topics[1].sub)==0)
                         sum_e=sum_e+s1.sub1[j].mark;
                         if (strcmp(s1.sub1[j].sub,topics[2].sub)==0)
                         sum_s=sum_s+s1.sub1[j].mark;
                         if (strcmp(s1.sub1[j].sub,topics[3].sub)==0)
                         sum_h=sum_h+s1.sub1[j].mark;
                         if (strcmp(s1.sub1[j].sub,topics[4].sub)==0)
                         sum_g=sum_g+s1.sub1[j].mark;
                        }

               }
               if (rollno!=1)
               printf("\nStudent data not available\n");

                        printf("\nSubject wise average marks of whole class\n");
                        avg_c=sum_m/count;
                        printf("\nmaths\t%f\n",avg_c);
                        sum_m=0;
                        avg_c=0;
                        avg_c=sum_e/count;
                        printf("English\t%f\n",avg_c);
                        sum_e=0;
                        avg_c=0;
                        avg_c=sum_s/count;
                        printf("science\t%f\n",avg_c);
                        avg_c=0;
                        sum_s=0;
                        avg_c=sum_h/count;
                        printf("History\t%f\n",avg_c);
                        avg_c=0;
                        sum_h=0;
                        avg_c=sum_g/count;
                        printf("Geo\t%f\n",avg_c);
                        avg_c=0;
                        sum_g=0;
      }
      else
            printf("Thanks for using this application\n");
      break;
}
fclose(fp);
return 1;
}
