#include<stdio.h>
#include<conio.h>
#include<process.h>
void read();
void write();
void close(void);
struct record
{
    char name[30];
    int id;
    float sal;
}s;
void main()
{
    int ch;
    while(1)
    {
        printf("\n1:Write Records.");
        printf("\n2:Read Records.");
        printf("\n3:Exit.");
        printf("\n\tEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            write();
            break;
        case 2:
            read();
            break;
        case 3:
            close();
            exit(1);
            break;

        default:
            printf("\n\tOption not available.\n");
            break;
        }
    }
    getch();
}

void write()
{
    int i,n=0;
    FILE *fp;
    fp=fopen("stu.dat","wb");
    if(fp==NULL)
    {
        printf("Can't create file.\n");
        getch();
        exit(1);
    }
    printf("\n\tHow many records you want to enter?: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nEnter employee ID:- ");
        scanf("%d",&s.id);

        printf("\nEnter employee Name:- ");
        scanf("%s",s.name);

        printf("\nEnter the Salary:- ");
        scanf("%f",&s.sal);
        printf("\n*****************\n");

        fwrite(&s,sizeof(s),1,fp);

    }
    fclose(fp);
}

void read()
{
    FILE *fp;
    fp=fopen("stu.dat","rb");
    if(fp==NULL)
    {
        printf("Can't read file.");
        getch();
        exit(1);
    }
    while(fread(&s,sizeof(s),1,fp)==1)
    {
        printf("\nEmployee ID:- %d",s.id);
        printf("\nEmployee Name:- %s",s.name);
        printf("\nSalary:- %f",s.sal);
        printf("\n********************\n");

    }
    fclose(fp);
}
void close(void)
{
     printf("This project has been created by DEBAYAN DAM.\n");
}
