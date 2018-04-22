#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct
{
    char name[100];
    int age;
    float marks;
    long id;
} emp;
void inputdata(emp *ep)
{
    printf("Enter student's name:");
    fflush(stdin);
    scanf("%s",ep->name);
    printf("Enter student's age:");
    scanf("%d",&ep->age);
    printf("Enter Student's salary:");
    scanf("%f",&ep->marks);
    printf("Enter student's id:");
    scanf("%ld",&ep->id);
}
void savedata(FILE *fp,emp *ep)
{
    fprintf(fp,"%s\n%d\n%7.2f\n%ld\n",ep->name,ep->age,ep->marks,ep->id);
}
int readdata(FILE *fp,emp *ep)
{
    char temp[31];
    if(fgets(ep->name,99,fp)==NULL)
        return 0;
    ep->name[strlen(ep->name)-1]='\0';
    fgets(temp,30,fp);//replaces enter by null fgets//
    temp[strlen(temp)-1]='\0';
    ep->age=atoi(temp);
    fgets(temp,10,fp);
    temp[strlen(temp)-1]='\0';
    ep->marks=atof(temp);
    fgets(temp,30,fp);
    temp[strlen(temp)-1]='\0';
    ep->id=atol(temp);
    return 1;
}
void printdata(emp *e,int i)
{
    printf("%d# Student's name is %s, Age is %d, Marks is %7.2f, id is %ld\n",i,e->name,e->age,e->marks,e->id);
}
void addrecord(FILE *fp)
{
    emp e;
    fp=fopen("student.txt","a");
    inputdata(&e);
    savedata(fp,&e);
    fclose(fp);
}
void displayrecord(FILE *fp)
{
    int i=1;
    char temp[100];
    emp e;
    fp=fopen("student.txt","r");
    if(fp==NULL)
        puts("file not found");
    else
        puts("file found");
    while(readdata(fp,&e))
    {
        printdata(&e,i);
        i++;
    }
    fclose(fp);
}
void searchbyid(FILE *fp)
{
    emp e;
    fp=fopen("student.txt","r");
    long id; int found=0,i=1;
    printf("enter the id you want to search:");
    scanf("%ld",&id);
    while(readdata(fp,&e))
    {
        if(e.id==id)
        {
            printdata(&e,i);
            found=1;
            break;
        }
        i++;
    }
    if(!found)
        printf("id not found");
    fclose(fp);
}
int main()
{
    int n,i,ch;
    FILE *fp;
    while(1)
    {
        printf("1.Add\n2.Display\n3.Search by id\n4.Exit\n");
        printf("enter choice:");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            addrecord(fp);
            break;
        case 2:
            displayrecord(fp);
            break;
        case 3:
            searchbyid(fp);
            break;
        case 4:
            exit(1);
        }
    }
}
