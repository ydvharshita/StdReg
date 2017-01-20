#include <stdio.h>
#include <conio.h>
#include <process.h>
#include <malloc.h>
#include <string.h>
struct node
{
	char names[50];
	int marks[50];
	struct node *next;
};

struct node *start = NULL;

void create();
void insert();
int valid();
void deletell();
void search();
void total();
void marks();
void dis_marks();
void display();

int main()
{
	int ch,r;
	char pass[25],ch1, name[30],opn;
	int i,j ;
	//clrscr();

	printf("\n\n\n\n\n\n\t\t\t xxx Please enter your name : ");
	scanf("%s",&name);
	printf("\n\t\t\t xxx Please enter your password : ");

	while (1)
	{
		if (i < 0)
		{
			i=0;
		}
		ch1 = getch();

		if (ch1 == 13) 
		break;

		if (ch1 == 8) 
		{
			putch('\b');
			putch(NULL);
			putch('\b');
			i--;
			continue;
		}

		pass[i++] = ch1;
		ch1 = '*';
		printf("%c",ch1);
	}
	pass[i] = '\0';
	
	if(strcmp(pass,"abc")==0)
	{
		//clrscr();
	  do
	  {

		printf("\n\n\t\txxxxxxxxxxxxxxx WELCOME ADMIN xxxxxxxxxxxxxxxx\n");
		printf("\n\t\tYour choices are :- \n\t\t1-create a student list\t\t2-insert a student\n\t\t3-remove a student\t\t4-search for a student\n\t\t5-display student list\t\t6-Total students\n\t\t7-Assign student marks\t\t8-Display student marks\n\t\t9-exit\n");
		printf("\n\t\txxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
		printf("  xxx Please enter a choice : ");
		scanf("%d",&ch);
		printf("  xxx Entered choice is : %d \n\n\n",ch);

		switch(ch)
		{
			case 1: create();
				break;
			case 2: insert();
				break;
			case 3: deletell();
				break;
			case 4: search();
				break;
			case 5: display();
				break;
			case 6: total();
				break;
			case 7: marks();
				break;
			case 8: dis_marks();
				break;
			case 9: exit(0);
				break;

			default: printf("\nInvalid choice..!!!\n");
		}
		getch();
		clrscr();
	  }while(ch!=9);
	}
	else
	{
		printf("\n\n\t\tXXXXXXXXXXXX WRONG PASSWORD.!!! XXXXXXXXXXXXX");
	}
	return 0;
}

void create()
{
	struct node *ptr = NULL;
	struct node *pt =NULL;

	int n,i,j;

	printf("\n\n>> Enter total number of students - ");
	scanf("%d",&n);
	printf("\n");
	for(i=0;i<n;i++)
	{
		ptr = (struct node *)malloc(sizeof(struct node));
		ptr->next =NULL;

		if(start==NULL)
		{
			pt=start=ptr;
		}

		printf("\t>> Enter Name : ");
		scanf("%s",&ptr->names);


		pt->next = ptr;
		pt=ptr;
	}

}

void insert()
{
	struct node *pt1 = NULL;
	struct node *pt2 = NULL;
	struct node *ptr = NULL;
	int pos,i,j;

	ptr=(struct node *)malloc(sizeof(struct node));

	printf("\n\n>> Enter the index number you wants to add student at : \n");
	scanf("%d",&pos);

	printf(">> Enter the student name: ");
	scanf("%s",&ptr->names);
	printf("\n\n");
	ptr->next =NULL;

	pt2=start;
	if(pos==1)
	{
		ptr->next=start;
		start=ptr;
	}
	else
	{
		for(i=1;i<pos;i++)
		{
			pt1=pt2;
			pt2 = pt2->next;
			if(pt2==NULL)
			break;
		}
		if(pt2!=NULL)
		{
			pt1->next = ptr;
			ptr->next = pt2;
		}
	}
}

void display()
{
	struct node *ptr=start;
	int i=1;

	printf("\n\t\t* INDEX NO. *   * STUDENT NAME *");
	while(ptr!=NULL)
	{
		printf("\n\t\t\t%d \t\t %s",i,ptr->names);
		ptr = ptr->next;
		i++;
	}
	printf("\n");

}
void deletell()
{
	struct node *pt1 = NULL;
	struct node *pt2 = NULL;
	int pos,i;
	display();
	printf("\n\n>>Enter the index number you wants to delete : \n");
	scanf("%d",&pos);

	pt2=start;

	if(pos==1)
	{
		pt1=start;
		start= start->next;
		free(pt1);
	}
	else
	{
		for(i=1;i<pos;i++)
		{
			pt1=pt2;
			pt2 = pt2->next;
			if(pt2==NULL)
			break;
		}
		if(pt2!=NULL)
		{
			pt1->next = pt2->next;
			pt1=pt2;
		}

	}

}

void search()
{
  struct node *ptr = start;
  char a[20];
  int flag = 0, i =0;

  printf(">> Enter the name you wants to search for : ");
  scanf("%s",&a);
  
  while(ptr != NULL)
  {      i++;
	if(strcmpi(a,ptr->names) == 0)
	{
		flag=1;
		break;
	}
	ptr = ptr->next;
  }
  if(flag==1)
  {
	printf("\nFOUND..!!!\n");
	printf("\n\t\t* INDEX NO. *   * STUDENT NAME *");
	printf("\n\t\t  %d \t\t %s",i,a);
  }
  else
  {
	printf("\nNOT FOUND..!! ");
  }

 }
 void total()
 {
	struct node *ptr = start;
	int count = 0 ;
	while(ptr!= NULL)
	{
		count++;
		ptr = ptr->next;
	}
	printf("\n>> Total number of students present in list are : %d ",count);

}

void marks()
{
	struct node *ptr = start;
	int i =0;
	while(ptr != NULL)
	{
		printf(">> Enter Marks of %s :",ptr->names);
		scanf("%d",&ptr->marks[i]);
		i++;
		ptr = ptr->next;
	}
}
void dis_marks()
{
	struct node *pt =start;
	int j=0;
	printf("\n>> Entered Marks :-\n\t\t* NAME *\t\t* MARKS *\n");
	while(pt != NULL)
	{
		printf("\t\t%s \t\t\t %d\n",pt->names,pt->marks[j]);
		j++;
		pt = pt->next;
	}
 }


