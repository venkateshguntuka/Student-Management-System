#include<stdio.h>
#include<string.h>
#include<windows.h>
#define MAX 10
struct student
{
  char sname[50];
  int marks[MAX];
  struct student* next;
};
struct student* insertIntoList(struct student* head,char *name,int *arr,int len)
{
    struct student* temp=(struct student*)malloc(sizeof(struct student));
    int i;
    for(i=0;name[i]!='\0';i++)
        temp->sname[i]=name[i];
        temp->sname[i]='\0';

    for(i=0;i<len;i++)
        temp->marks[i]=arr[i];

    temp->next=NULL;

    if(head==NULL)
        {
            head=temp;
            return head;
        }
    struct student* tail=head;
    while(tail->next)
    {
        tail=tail->next;
    }
    tail->next=temp;
    return head;
}
void averageMarks(struct student* head,char *str,int len)
{
    struct student* temp=head;
    int found=0,sum=0,i;
    float avg=0;
     printf("\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Student Average Marks \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n\t\t");
     printf("\n");
    while(temp!=NULL)
    {
        int res=strcmp(str,temp->sname);
        if(res==0)
        {
            printf("\t\t\tstudent name :%s\n",temp->sname);
            printf("\t\t\tAverage marks:");
            for(i=0;i<len;i++)
                sum+=temp->marks[i];
                sum/=len;
            printf("%d",sum);
            printf("\n");
            found=1;
            break;
        }
        temp=temp->next;
    }
     if(found==0)
        printf("Student not found in the list\n");
}
void studentMarks(struct student* head,char *str,int len,char subjects[][30])//printing marks of a particular student
{
    struct student* temp=head;
    int found=0,i;
    printf("\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Student Marks \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n\t\t");
    while(temp!=NULL)
    {
        int res=strcmp(str,temp->sname);
        if(res==0)
        {
            for(i=0;i<len;i++)
                printf("%s\t",subjects[i]);
            printf("\n");
            printf("%s\n\t\t",temp->sname);
            for(i=0;i<len;i++)
                printf("%d\t",temp->marks[i]);
            printf("\n");
            found=1;
            break;
        }
        temp=temp->next;
    }
    if(found==0)
        printf("Student not found in the list\n");
}
int getSubIndex(char *str,char subjects[][30],int len)
{
    int i;
    for(i=0;i<len;i++)
    {
        if(strcmp(str,subjects[i])==0)
            return i;
    }
    return -1;

}
int findMax(int *arr,int len)
{
    int i,index=0,max=0;
    for(i=0;i<len;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
            index=i;
        }
    }
    return index;

}
void maxMarks(struct student* head,char *str,int len,char subjects[][30])
{
    struct student* temp=head;
    int i,found=0;
    printf("\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Maximum-Marks \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n\t\t");
    while(temp!=NULL)
    {
        int res=strcmp(str,temp->sname);
        if(res==0)
        {
            printf("student name\t\t");
            printf("subject\t\t");
            printf("marks\n");
            printf("\t\t%s",temp->sname);
            int index=findMax(temp->marks,len);
            printf("\t\t%s",subjects[index]);
            printf("\t\t%d\n",temp->marks[index]);
            found=1;
        }
        temp=temp->next;
    }
    if(found==0)
        printf("Entered student name was not found in the list\n");
}
void subMarks(struct student* head,char *str,char *sub,int len,char subjects[][30])
{
    int res=getSubIndex(sub,subjects,len);
    if(res==-1)
    {
        printf("No such subject is registered\n");
        return;
    }
    printf("\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Subject-Marks \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n\t\t");
    struct student *temp=head;
    int i,found=0;
    while(temp!=NULL)
    {
        int res2=(strcmp(str,temp->sname));
        if(res2==0)
        {
            printf("\tStudent Name");
            printf("\t\tSubject:%s",subjects[res]);
            printf("\n");
            printf("\t\t\t%s",temp->sname);
            printf("\t\t\t%d\n",temp->marks[res]);
            found=1;
            break;
        }
        temp=temp->next;
    }
     if(found==0)
            printf("No such student is found in the list\n");

}
void printAll_subject(struct student* head,char *sub,int len,char subjects[][30])
{
    int res=getSubIndex(sub,subjects,len);
    if(res==-1)
    {
        printf("No such subject is registered\n");
        return;
    }
    printf("\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 %s-Marks \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n\t",subjects[res]);
    printf("    Student Name");
    printf("\tMarks\n");

    struct student* temp=head;
    int i,found=0;
    while(temp!=NULL)
    {
        printf("            %s",temp->sname);
        printf("\t\t%d\n",temp->marks[res]);
        temp=temp->next;
    }
}
void printList(struct student* head,int length,char subjects[][30])
{
    struct student* temp=head;
    int i;
    printf("\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Results \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n\t");
    for(i=0;i<length;i++)
    printf("%s  ",subjects[i]);
    printf("\n");
    while(temp!=NULL)
    {
	printf("%s\n\t\t",temp->sname);
    for(i=0;i<length;i++)
    printf("%d\t",temp->marks[i]);
    printf("\n");
    temp=temp->next;
    }
     printf("\n\n");
}
void modifyMarks(struct student* head,char *stu,int *arr,int len)
{
    struct student* temp=head;
    int i=0,found=0;
    while(temp!=NULL)
    {
        int res=strcmp(stu,temp->sname);
        if(res==0)
        {
            for(i=0;i<len;i++)
                temp->marks[i]=arr[i];
            found=1;
            break;
        }
        temp=temp->next;
    }
    if(found==0)
    printf("student name specified does not exist in the list\n");
}

void modifyName(struct student* head,char *oname,char *newname)
{
    struct student* temp=head;
    int i=0,found=0;
    while(temp!=NULL)
    {
        int res=strcmp(oname,temp->sname);
        if(res==0)
        {
            for(i=0;i<strlen(newname);i++)
            {
                temp->sname[i]=newname[i];
            }
            temp->sname[i]='\0';
            found=1;
            break;
        }
        temp=temp->next;
    }
    if(found==0)
        printf("student name specified does not exist in the list\n");
}
int getNumber(char *str)
{
    int res=0,i;
    for(i=0;str[i]!='\0';i++)
        res=res*10+str[i]-'0';
    return res;
}
int main()
{
    FILE *fp1=fopen("SampleFile_StudentsMarksSystem.txt","r");
    FILE *fp2=fopen("output.txt","w");
    if(fp1==NULL)
        printf("Error opening the file\n");


    struct student *head=NULL;
    char expr[50],subjects[6][30],l[2];
    int i;

   //scanning the first line:number of subjects
    fscanf(fp1,"%s",l);
    int length=getNumber(l);

   //scanning the second line:subject names can printed by printing subjects[i]=%s
    fscanf(fp1,"%s",expr);
    char subs[50];
    strcpy(subs,expr);
    char *res=strtok(expr,",");
    for(i=0;i<length;i++)
    {
        int j;
        for(j=0;res[j]!='\0';j++)
        subjects[i][j]=res[j];
        subjects[i][j]='\0';
        res=strtok(NULL,",");
   }
   printf("\n");
   printf("\t\t ********************************");
   printf("\n\n");

   char name[50];
   while(fscanf(fp1,"%s",name)!=EOF)//cannot handle cases where there are non singular name//Error case
   //scanning third line which contains student name;
  {
    //scanning fourth line which gives marks of the student 1
    fscanf(fp1,"%s",expr);
    int arr[length];//marks
    res=strtok(expr,",");
    for(i=0;i<length;i++)
    {
        arr[i]=getNumber(res);
        res=strtok(NULL,",");
    }

    head=insertIntoList(head,name,arr,length);
   }
   int option;
   printf("\t\tWELCOME TO STUDENT MANAGEMENT SYSTEM\n\n");
    do
	{
        int voption,arr1[length],temp[length];
        char stud[50],stud3[50],sub[50],stud4[50],stud2[50],sub2[50],stud5[50],stud6[50],stud7[50],stud8[50];
        printf("please choose one of the following\n1.view marks\n2.add or modify student records\n3.exit\nEnter the option number\n");
		scanf("%d", &option);
		switch (option)
		{
		case 1:printf("please choose one of the following\n1.view marks of all students\n2.view marks of one particular student\n3.view marks of particular subject of particular student\n");
                printf("4.view maximum marks of particular student\n5.view average marks of a student\n6.one subject marks of all students\nplease enter an option number\n");
                scanf("%d",&voption);
                switch(voption)
                {
                    case 1:printList(head,length,subjects);
                            break;
                    case 2: printf("Enter student name:\n");
                            scanf("%s",stud);
                            studentMarks(head,stud,length,subjects);
                            break;
                    case 3: printf("Enter the student name:\n");
                            scanf("%s",stud3);
                            printf("Enter the subject name:\n");
                            scanf("%s",sub);
                            subMarks(head,stud3,sub,length,subjects);
                            break;
                    case 4:printf("Enter student name:\n");
                           scanf("%s",stud4);
                           maxMarks(head,stud4,length,subjects);
                           break;
                    case 5:printf("Enter the student name:\n");
                           scanf("%s",stud2);
                           averageMarks(head,stud2,length);
                           break;
                    case 6:printf("Enter the subject name:\n");
                            scanf("%s",sub2);
                            printAll_subject(head,sub2,length,subjects);
                    default:printf("no such option exists\n");
                            break;
                }
                break;
		case 2: printf("please choose one of the following:\n1.add a new student record\n2.change the name of the student\n3.change the student marks\nplease enter an option number\n");
                int aoption;

                scanf("%d",&aoption);
                switch(aoption)
                {
                    case 1: printf("Enter the student name to be inserted:\n");
                            scanf("%s",stud5);
                            printf("Enter the marks to the student:\n");
                            for(i=0;i<length;i++)
                            {
                                printf("Marks in %s \n",subjects[i]);
                                scanf("%d",&arr1[i]);
                            }
                            head=insertIntoList(head,stud5,arr1,length);
                            break;
                    case 2: printf("Enter the name of the student you want to change:\n");
                            scanf("%s",stud6);
                            printf("Enter the new name :\n");
                            scanf("%s",stud7);
                            modifyName(head,stud6,stud7);
                            break;
                    case 3: printf("Enter the name of the student you want to change:\n");
                            scanf("%s",stud8);
                            printf("Enter the new marks of the student:\n");
                            for(i=0;i<length;i++)
                            {
                                printf("Marks in %s \n",subjects[i]);
                                scanf("%d",&temp[i]);
                            }
                            modifyMarks(head,stud8,temp,length);
                            break;
                    default:printf("no such option exists\n");
                            break;
                }
                break;
		case 3: break;

		default:printf("no such option exists\n");
                break;
		}
	} while (option!=3);
    fprintf(fp2,"%d\n",length);
    fprintf(fp2,"%s\n",subs);
    char delim=',';
    struct student * temp1=head;
    while(temp1!=NULL)
    {
        fprintf(fp2,"%s\n",temp1->sname);
        for(i=0;i<length;i++)
        {
            fprintf(fp2,"%d",temp1->marks[i]);
            if(i!=length-1)
            fprintf(fp2,"%c",delim);
        }
        fprintf(fp2,"\n");
        temp1=temp1->next;
    }
    fclose(fp2);
    fclose(fp1);
    int r=remove("SampleFile_StudentsMarksSystem.txt");
    rename("output.txt","SampleFile_StudentsMarksSystem.txt");
    return 0;
}

