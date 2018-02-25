#include<stdio.h>
#include<stdlib.h>
int n;
typedef struct Student
{
    int roll,marks;
    char name[20];
    struct dob
    {
        int d,m,y;
    } b;
} a;
typedef struct Distance
{
    int feet;
    float inch;
} d;
typedef struct TIME
{
    int seconds;
    int minutes;
    int hours;
} t;
void differenceBetweenTimePeriod(struct TIME start, struct TIME stop, struct TIME *diff)
{
    if(stop.seconds > start.seconds)
    {
        --start.minutes;
        start.seconds += 60;
    }
    diff->seconds = start.seconds - stop.seconds;
    if(stop.minutes > start.minutes) {
        --start.hours;
        start.minutes += 60;
    }
    diff->minutes = start.minutes - stop.minutes;
    diff->hours = start.hours - stop.hours;
}
typedef enum weekdays {sunday=1,monday,tuesday,wednesday,thursday,friday,saturday} w;
typedef union student
{
    char name[50];
    int roll;
    float marks;
} u;
void display(a p)
{
    printf("%s\t",p.name);
    printf("%d\t",p.roll);
    printf("%d\t",p.marks);
}
void display2(a p)
{
    printf("%d.%d.%d\n",p.b.d,p.b.m,p.b.y);
}
void input(a *p,int i)
{

    printf("Enter the name of student %d\n",i);
    scanf("%s",p->name);
    printf("Enter the roll number of student %d\n",i);
    scanf("%d",&p->roll);
    printf("Enter the marks of student %d\n",i);
    scanf("%d",&p->marks);
}
void input2(a *p,int i)
{
    printf("Enter the date of birth of student %d\n",i);
    scanf("%d%d%d",&p->b.d,&p->b.m,&p->b.y);
}
void main()
{
    int i,ch;
    a x[n],*z;
    d dist1,dist2,sum;
    t strt,stpt,diff;
    w day;
    u s;
    char p[10];
    for(;;)
    {
    	printf("0. Exit\n");
        printf("1. Store information (name, roll, marks) of a student.\n");
        printf("2. Add two distances (in inch-feet)\n");
        printf("3. Calculate the difference between two time periods\n");
        printf("4. Store information (name, roll, marks) of 10 students using structure\n");
        printf("5. Store information using structures for n elements dynamically\n");
        printf("6. Access array members using structure.\n");
        printf("7. Access structure members using structure pointers\n");
        printf("8. Store roll and name of a student. Store DOB of that student in another nested structure and print it\n");
        printf("9. Store information (name, roll, marks) of a student using union and display\n");
        printf("10.Identify weekdays using enum constant\n");
        scanf("%d",&ch);
        if(ch==0)
            break;
        else
        {
            switch(ch)
            {
            case 1:
                n=1;
                input(&x[0],1);
                input2(&x[0],i+1);
                printf("Stored Successfully !");
                break;
            case 2:
                printf("Enter information for 1st distance\n");
                printf("Enter feet\n");
                scanf("%d", &dist1.feet);
                printf("Enter inch\n");
                scanf("%f", &dist1.inch);
                printf("Enter information for 2nd distance\n");
                printf("Enter feet\n");
                scanf("%d", &dist2.feet);
                printf("Enter inch\n");
                scanf("%f", &dist2.inch);
                sum.feet = dist1.feet+dist2.feet;
                sum.inch = dist1.inch+dist2.inch;
                if (sum.inch>12.0)
                {
                    sum.inch = sum.inch-12.0;
                    ++sum.feet;
                }
                printf("Sum of distances = %d\'-%.1f\"",sum.feet, sum.inch);
                break;
            case 3:
                printf("Enter start time: \n");
                printf("Enter hours, minutes and seconds respectively: ");
                scanf("%d %d %d", &strt.hours, &strt.minutes, &strt.seconds);
                printf("Enter stop time: \n");
                printf("Enter hours, minutes and seconds respectively: ");
                scanf("%d %d %d", &stpt.hours, &stpt.minutes, &stpt.seconds);
                differenceBetweenTimePeriod(strt, stpt, &diff);
                printf("\nTIME DIFFERENCE: %d:%d:%d\n", diff.hours, diff.minutes, diff.seconds);
                break;
            case 4:
                n=10;
                for(i=0; i<n; i++)
                    input(&x[i],(i+1));
                printf("Stored Successfully !\n");
                break;
            case 5:
                printf("How many students's data do you want to store?\n");
                scanf("%d",&n);
                z=(a *)malloc(n*sizeof(a));
                for(i=0; i<n; i++)
                    input(&z[i],(i+1));
                printf("Stored Successfully !\n");
                break;
            case 6:
                printf("Name\tRoll\tMarks\n");
                for(i=0; i<n; i++)
                {
                    display(x[i]);
                    printf("\n");
                }
                break;
            case 7:
                display(x[0]);
                break;
            case 8:
                printf("How many students's data do you want to store?\n");
                scanf("%d",&n);
                for(i=0; i<n; i++)
                {
                    input(&x[i],(i+1));
                    input2(&x[i],(i+1));
                }
                printf("Stored Successfully !\n");
                break;
            case 9:
                printf("Enter information:\n");
                printf("Enter name: ");
                scanf("%s", s.name);
                printf("Enter roll number: ");
                scanf("%d",&s.roll);
                printf("Enter marks: ");
                scanf("%f", &s.marks);
                printf("Name: ");
                puts(s.name);
                printf("Roll number: %d\n",s.roll);
                printf("Marks: %.1f\n", s.marks);
                break;
            case 10:
                printf("Enter the weekday in lowercase\n");
                scanf("%s",p);
                printf("%d",day);
                break;
            default:
            	printf("Invalid Choice. Try again !\n");
            	break;
            }
        }
    }
}
