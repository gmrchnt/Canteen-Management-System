#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
void initial(void);
int enter(void);
int signup(void);
int login(void);
int user(void);
int buyer(void);
int c_record(void);
int record(void);
int a_record(void);
void cant_1(void);
void cant_2(void);
void cant_3(void);
void cant_4(void);
int canteens(int op);
int filing(void);
int x=0;
char *idptr;
FILE *cs,*fp,*fp2;

struct customer
{
	char Name[20];
	char ID[9];
	struct canteen
	{
		char name[20];
		char item[10][30];
		float price[10];
		int quantity[10];
		int amount[10];
		int total;
	}canteen[4];
}customer[1];
int main()
{
	enter();
	initial();
	return 0;
}
void initial(void)
{
	cant_1();
	cant_2();
	cant_3();
	cant_4();
}
int enter(void)
{
	int op=1;
	while(1)
	{
		system("cls");
		printf("              Welcome to FAST ORDER PLACEMENT  \n ");
		printf("             +============================+          \n\n");
		printf("                     $  HOME PAGE  $ \n\n");
		printf(" || Please select the Option that you would like to do. || \n\n");
		printf("\t\t      [1]  LOGIN \n");
		printf("\t\t      [2]  SIGN UP \n");
		printf("\t\t      [0]  EXIT\n\n");
		if(op>2 || op<0)
			printf("\n\tPlease Choose Correctly\n\n");
		printf("Enter your choice here : ");
		scanf("%d",&op);
		if(op==0)
			break;
		else if(op==1)
			login();
		else if(op==2)
			signup();
		else
		printf("\n\tPlease Choose Correctly\n\n");
	}
	return 0;
}
int signup(void)
{
	char name[20],id[9],customer_ID[9],customer_name[20];
	int i,option,flag=0;
	while(1)
	{
		system("cls");
		flag=0;
		printf("              Welcome to FAST ORDER PLACEMENT  \n ");
		printf("             +============================+          \n\n");
		printf("                     $  SIGN UP PAGE  $ \n\n");
		printf("\t\t    FOR EXIT PRESS [0] \n\n");
		printf("ENTER YOUR NAME : ");
		scanf("%s",name);
		if(name[0]=='0')
			break;
		printf("\nENTER YOUR ID [22k-1234] : ");
		scanf("%s",id);
		if(id[0]=='0')
			break;
		if((id[0]=='1' || id[0]=='2') && (id[2]=='k' && id[3]=='-'))
		{
			cs=fopen("AllUsers.txt","r");
			while (!feof(cs))
			{
				fgets(customer_ID,9,cs);
				option = strcmp(id,customer_ID);
				if (option == 0)
				{
					printf("\n\t\t    ID ALREADY EXISTS\n");sleep(1);
					flag=1;
					break;
				}
			}
			fclose(cs);	
		}
		else
		{
			printf("\n\t\t  !.PLEASE GIVE CORRECT ID.!\n");
			sleep(1);
			continue;
		}
		if(flag!=1)
		{
			strcpy(customer[x].ID,id);
			strcpy(customer[x].Name,name);
			cs=fopen("AllUsers.txt","a+");
			fprintf(cs,"%s\n",name);
			fprintf(cs,"%s\n",id);
			strcat(id,".txt");
			fclose(cs);
			printf("\n\t\t    SIGNED UP SUCCESSULLY\n");
			sleep(1);
			return 0;
		}
	}
	return 0;
}
int login(void)
{
	char c,id[9],customer_ID[9],customer_name[20];
	int option,i,flag=0;
	while(1)
	{
		system("cls");
		printf("              Welcome to FAST ORDER PLACEMENT  \n ");
		printf("             +============================+          \n\n");
		printf("                     $  LOGIN PAGE  $ \n\n");
		printf("\t\t    FOR EXIT PRESS [0] \n\n");
		printf("\nEnter YOUR ID : ");
		scanf(" %s", id);
		if(id[0]=='0')
			break;
		if((id[0]=='1' || id[0]=='2') && (id[2]=='k' && id[3]=='-'))
		{
		cs=fopen("AllUsers.txt","r");
		while ((c = fgetc(cs)) != EOF)
		{
			fgets(customer_name,20,cs);
			fgets(customer_ID,9,cs);
			option = strcmp(id,customer_ID);
			if (option == 0)
			{
				printf("\n\t\t    LOGIN SUCCESSFUL\n");
				sleep(1);
				printf("\n\t\t    WELCOME MR. %c%s\n",c,customer_name);
				
				fclose(cs);
				strcat(id,".txt");
				idptr=id;
				strcpy(customer[x].ID,customer_ID);
				strcpy(customer[x].Name,customer_name);
				sleep(1);
				initial();
				user();
				return 0;
			}
		}
		fclose(cs);
		}
		printf("\n\t\tPLEASE ENTER CORRECT ID\n");
		sleep(1);
	}
	return 0;
}
int user(void)
{
	int ch=0;
	while(1)
	{
		system("cls");
		fflush(stdin);
		printf("              Welcome to FAST ORDER PLACEMENT  \n ");
		printf("             +============================+          \n\n");
		printf("                     $  USER MENU  $ \n\n");
		printf("  || Please select the Option that you would like to do. || \n\n");
		printf("\t\t      [1] ORDER PLACEMENT \n");
		printf("\t\t      [2] RECORD CHECK\n");
		printf("\t\t      [0] EXIT\n\n");
		if(ch>2 || ch<0)
			printf("\n\tPlease Choose Correctly\n\n");
		fflush(stdin);	
		printf("Enter your choice here : ");
		scanf("%d", &ch);
		if (ch==0)
			break;
		if(ch==1)
			buyer();
		if(ch==2)
			record();
	}
	printf("Thankyou for using this program");
	filing();
	fclose(fp);

	return 0;
}
int record(void)
{
	int ch=0;
	while(1)
	{
		system("cls");
		fflush(stdin);
		printf("              Welcome to FAST ORDER PLACEMENT  \n ");
		printf("             +============================+          \n\n");
		printf("                     $  USER MENU  $ \n\n");
		printf("  || Please select the Option that you would like to do. || \n\n");
		printf("\t\t      [1] CURRENT RECORD \n");
		printf("\t\t      [2] ALL RECORD \n");
		printf("\t\t      [0] EXIT\n\n");
		if(ch>2 || ch<0)
			printf("\n\tPlease Choose Correctly\n\n");
		fflush(stdin);	
		printf("Enter your choice here : ");
		scanf("%d", &ch);
		if (ch==0)
			break;
		if(ch==1)
			c_record();
		if(ch==2)
			a_record();
	}
	return 0;
}
int c_record(void)
{
	int op=0,i,j,final=0;
	system("cls");
	while(1)
	{
		system("cls");
		fflush(stdin);
		printf("              Welcome to FAST ORDER PLACEMENT  \n ");
		printf("             +============================+          \n\n");
		printf("                     $  RECORD CHECK  $ \n\n");
		printf("    \t || Please select the Canteen for which ||\n\t ||   you would like to check record.   || \n\n");
		printf("\t\t      [1] CAFE \n");
		printf("\t\t      [2] FAST FOOD\n");
		printf("\t\t      [3] DHABA\n");
		printf("\t\t      [4] DRINKS CORNER\n");
		printf("\t\t      [5] ALL RECORDS\n");
		printf("\t\t      [0] EXIT\n\n");
		fflush(stdin);
		if(op>0 && op<5)
		{
			op-=1;
			printf("                   $  %s  $ \n\n",customer[x].canteen[op].name);
			int o=0;
			customer[x].canteen[op].total=0;
			printf("\nITEMS          \t\tQUANTITY\tAMOUNT");
			for(i=0;i<10;i++)
			if(customer[x].canteen[op].quantity[i]!=0)
			{
				fflush(stdin);
				customer[x].canteen[op].total+=customer[x].canteen[op].amount[i];
				printf("\n%s",customer[x].canteen[op].item[i]);
				SetConsoleCursorPosition(28,19+o);
				printf("%d\t\t",customer[x].canteen[op].quantity[i]);
				SetConsoleCursorPosition(42,19+o);
				printf("%d",customer[x].canteen[op].amount[i]);
				o++;
			}
			printf("\n-----------------------------------------------");
			printf("\nTotal\t\t\t\t\t %d\n",customer[x].canteen[op].total);
		}
		else if (op==5)
		{
			fflush(stdin);
			int o=0;
			for(j=0;j<4;j++)
			{
				printf("                   $  %s  $ \n\n",customer[x].canteen[j].name);
				customer[x].canteen[j].total=0;
				printf("\nITEMS          \t\tQUANTITY\tAMOUNT");
				for(i=0;i<10;i++)
				{
					if(customer[x].canteen[j].quantity[i]!=0)
					{
						customer[x].canteen[j].total+=customer[x].canteen[j].amount[i];
						printf("\n%s",customer[x].canteen[j].item[i]);
						SetConsoleCursorPosition(28,20+o);
						printf("%d\t\t",customer[x].canteen[j].quantity[i]);
						SetConsoleCursorPosition(42,20+o);
						printf("%d",customer[x].canteen[j].amount[i]);
						o++;
					}
				}
				final = final + customer[x].canteen[j].total;
				o+=7;
				printf("\n-----------------------------------------------");
				printf("\nTotal\t\t\t\t\t %d\n",customer[x].canteen[j].total);
			}
			printf("\n-----------------------------------------------");
			printf("\nTotal Amount:\t\t\t\t %d\n",final);
		}
		else if (op>5 || op<0)
			printf("\n\tPlease Choose Correctly\n\n");
		fflush(stdin);
		printf("\nEnter your choice here : ");
		scanf("%d", &op);
		if(op==0)
			break;
	} 
	return 0;
}
int buyer()
{
	char a;
	int ch=1;
	while(1)
	{
		system("cls");
		printf("              Welcome to FAST ORDER PLACEMENT  \n ");
		printf("             +============================+          \n\n");
		printf("                     $  ORDER PLACEMENT  $ \n\n");
		printf("\t || Please select the Canteen from which ||\n\t ||      you would like to purchase.     || \n\n");
		printf("\t\t      [1] CAFE \n");
		printf("\t\t      [2] FAST FOOD\n");
		printf("\t\t      [3] DHABA\n");
		printf("\t\t      [4] DRINKS CORNER\n");
		printf("\t\t      [0] EXIT\n\n");
		if(ch>4 || ch<0)
			printf("\n\tPlease Choose Correctly\n\n");	
		printf("Enter your choice here : ");
			scanf("%d", &ch);
		if (ch==0)
			break;
		if(ch<5&&ch>0)
			canteens(ch-1);
	}
	printf("\nThankyou for your order");
	return 0;
}
int canteens(int op)
{
	int i,choice = 0; //local variables
	int quant = 0;
	do
	{
		system("cls");
		printf("              Welcome to FAST ORDER PLACEMENT  \n ");
		printf("             +============================+          \n\n");
		printf("                     $  %s  $ \n\n",customer[x].canteen[op].name);
		printf("  || Please select food that you would like to purchase. || \n\n");
		for(i=0;i<10;i++)
		{
			printf("\t   [%d]",i+1);
			printf(" %s",customer[x].canteen[op].item[i]);
			printf("-Rs %.2f\n",customer[x].canteen[op].price[i]);
		}
		printf("\n\t   [0]  EXIT \n");
		if(1)
		{
			int o=0;
			customer[x].canteen[op].total=0;
			printf("\nITEMS          \t\tQUANTITY\tAMOUNT");
			for(i=0;i<10;i++)
				if(customer[x].canteen[op].quantity[i]!=0)
				{
					customer[x].canteen[op].total+=customer[x].canteen[op].amount[i];
					printf("\n%s",customer[x].canteen[op].item[i]);
					SetConsoleCursorPosition(28,22+o);
					printf("%d\t\t",customer[x].canteen[op].quantity[i]);
					SetConsoleCursorPosition(42,22+o);
					printf("%d",customer[x].canteen[op].amount[i]);
					o++;
				}
			printf("\n-----------------------------------------------");
			printf("\nTotal\t\t\t\t\t %d\n",customer[x].canteen[op].total);
		}
		do
		{	
			if(choice>10 || choice<0)
			printf("\n\tPlease Choose Correctly\n\n");
			printf("Enter your choice here : ");
			scanf("%d", &choice);
		}while(choice<0 && choice>10);
		if(choice==0)
			return 0;
		printf("Enter quantity : ");
		scanf("%d", &quant);	
		customer[x].canteen[op].amount[choice-1]+=customer[x].canteen[op].price[choice-1] * quant;
		customer[x].canteen[op].quantity[choice-1]+=quant;
		customer[x].canteen[op].total=0;
	}while(choice!=0);
	return 0;
}
void cant_1(void)
{
	strcpy(customer[x].canteen[0].name,"     CAFE      ");
	strcpy(customer[x].canteen[0].item[0]," Chicken Pulao             ");
	strcpy(customer[x].canteen[0].item[1]," Daal Chawal               ");
	strcpy(customer[x].canteen[0].item[2]," Singapuri Rice            ");
	strcpy(customer[x].canteen[0].item[3]," Biryani                   ");
	strcpy(customer[x].canteen[0].item[4]," Daal Salan                ");
	strcpy(customer[x].canteen[0].item[5]," Kahrai (1 Plate)          ");
	strcpy(customer[x].canteen[0].item[6]," Qorma (1 plate)           ");
	strcpy(customer[x].canteen[0].item[7]," Chapati/Paratha           ");
	strcpy(customer[x].canteen[0].item[8]," Egg Paratha               ");
	strcpy(customer[x].canteen[0].item[9],"Halwa Puri + Gravy        ");
	
	customer[x].canteen[0].price[0]=140;
	customer[x].canteen[0].price[1]=100;
	customer[x].canteen[0].price[2]=150;
	customer[x].canteen[0].price[3]=140;
	customer[x].canteen[0].price[4]=80;
	customer[x].canteen[0].price[5]=140;
	customer[x].canteen[0].price[6]=140;
	customer[x].canteen[0].price[7]=20;
	customer[x].canteen[0].price[8]=80;
	customer[x].canteen[0].price[9]=60;
}
void cant_2(void)
{
	strcpy(customer[x].canteen[1].name,"   FAST FOOD   ");
	
	strcpy(customer[x].canteen[1].item[0]," Beef Burger               ");
	strcpy(customer[x].canteen[1].item[1]," Chicken Burger            ");
	strcpy(customer[x].canteen[1].item[2]," Club Sandwich             ");
	strcpy(customer[x].canteen[1].item[3]," Chicken Sandwich          ");
	strcpy(customer[x].canteen[1].item[4]," Sekh Kabab Roll           ");
	strcpy(customer[x].canteen[1].item[5]," Zinger Roll               ");
	strcpy(customer[x].canteen[1].item[6]," Chicken Wraped Roll       ");
	strcpy(customer[x].canteen[1].item[7]," Pizza Fries               ");
	strcpy(customer[x].canteen[1].item[8]," Loaded Fries              ");
	strcpy(customer[x].canteen[1].item[9],"Regular Pizza             ");
	
	customer[x].canteen[1].price[0]=180;
	customer[x].canteen[1].price[1]=150;
	customer[x].canteen[1].price[2]=170;
	customer[x].canteen[1].price[3]=200;
	customer[x].canteen[1].price[4]=90;
	customer[x].canteen[1].price[5]=150;
	customer[x].canteen[1].price[6]=120;
	customer[x].canteen[1].price[7]=170;
	customer[x].canteen[1].price[8]=150;
	customer[x].canteen[1].price[9]=400;
}
void cant_3(void)
{
	strcpy(customer[x].canteen[2].name,"    DHABA      ");
	strcpy(customer[x].canteen[2].item[0]," Vegetable Patties         ");
	strcpy(customer[x].canteen[2].item[1]," Chicken Patties           ");
	strcpy(customer[x].canteen[2].item[2]," Chicken Samosa            ");
	strcpy(customer[x].canteen[2].item[3]," Chicken B.B.Q Samosa      ");
	strcpy(customer[x].canteen[2].item[4]," Aloo Samosa               ");
	strcpy(customer[x].canteen[2].item[5]," Shami Burger              ");
	strcpy(customer[x].canteen[2].item[6]," Anda Burger               ");
	strcpy(customer[x].canteen[2].item[7]," Chicken Shawarma          ");
	strcpy(customer[x].canteen[2].item[8]," Zinger Shawarma           ");
	strcpy(customer[x].canteen[2].item[9],"Chicken Cheese Shawarma   ");
	
	customer[x].canteen[2].price[0]=40;
	customer[x].canteen[2].price[1]=40;
	customer[x].canteen[2].price[2]=40;
	customer[x].canteen[2].price[3]=50;
	customer[x].canteen[2].price[4]=30;
	customer[x].canteen[2].price[5]=100;
	customer[x].canteen[2].price[6]=120;
	customer[x].canteen[2].price[7]=100;
	customer[x].canteen[2].price[8]=140;
	customer[x].canteen[2].price[9]=140;
}
void cant_4(void)
{
	strcpy(customer[x].canteen[3].name," DRINKS CORNER ");
	strcpy(customer[x].canteen[3].item[0]," Tea                       ");
	strcpy(customer[x].canteen[3].item[1]," Coffee                    ");
	strcpy(customer[x].canteen[3].item[2]," Lemon juice               ");
	strcpy(customer[x].canteen[3].item[3]," Grapes juice              ");
	strcpy(customer[x].canteen[3].item[4]," Mango juice               ");
	strcpy(customer[x].canteen[3].item[5]," Orange juice              ");
	strcpy(customer[x].canteen[3].item[6]," Pineapple juice           ");
	strcpy(customer[x].canteen[3].item[7]," Lassi                     ");
	strcpy(customer[x].canteen[3].item[8]," Milk Shake                ");
	strcpy(customer[x].canteen[3].item[9],"Soft Drink                ");
	
	customer[x].canteen[3].price[0]=120;
	customer[x].canteen[3].price[1]=110;
	customer[x].canteen[3].price[2]=80;
	customer[x].canteen[3].price[3]=140;
	customer[x].canteen[3].price[4]=140;
	customer[x].canteen[3].price[5]=110;
	customer[x].canteen[3].price[6]=180;
	customer[x].canteen[3].price[7]=110;
	customer[x].canteen[3].price[8]=90;
	customer[x].canteen[3].price[9]=70;
}
int filing(void)
{
	
			fflush(stdin);
			int final,j,i,o=0;
			fp=fopen(idptr,"a+");

			fprintf(fp,"                   $  NEW ORDER  $ \n\n");
			for(j=0;j<4;j++)
			{
				fprintf(fp,"                   $  %s  $ \n\n",customer[x].canteen[j].name);
				customer[x].canteen[j].total=0;
				fprintf(fp,"\nITEMS          \t\tQUANTITY\tAMOUNT");
				for(i=0;i<10;i++)
				{
					if(customer[x].canteen[j].quantity[i]!=0)
					{
						customer[x].canteen[j].total+=customer[x].canteen[j].amount[i];
						fprintf(fp,"\n%s",customer[x].canteen[j].item[i]);
					
						SetConsoleCursorPosition(28,20+o);
						fprintf(fp,"%d\t\t",customer[x].canteen[j].quantity[i]);
						SetConsoleCursorPosition(42,20+o);
						fprintf(fp,"%d",customer[x].canteen[j].amount[i]);
						o++;
					}
				}
				final = final + customer[x].canteen[j].total;
				o+=7;
				fprintf(fp,"\n-----------------------------------------------");
				fprintf(fp,"\nTotal\t\t\t\t\t %d\n",customer[x].canteen[j].total);
			}
	fprintf(fp,"\n-----------------------------------------------");
	fprintf(fp,"\nTotal Amount:\t\t\t\t %d\n\n\n",final);
	fclose(fp);
	return 0;	
}
int a_record(void)
{
	int op=1;
	char ch;
	while(1)
	{
		system("cls");
		fflush(stdin);
		printf("              Welcome to FAST ORDER PLACEMENT  \n ");
		printf("             +============================+          \n\n");
		printf("                     $  ALL RECORD  $ \n\n");
		printf("\t\t      [0] EXIT\n\n");
		fflush(stdin);
		fp=fopen(idptr,"r");
	
		ch=fgetc(fp);
		while (!feof(fp))
		{
			printf("%c",ch);
			fscanf(fp,"%c",&ch);
		}
		if (op!=0 || op!=1)
		printf("\n\tPlease Type Correctly\n\n");
		fflush(stdin);
		printf("\nEnter your choice here : ");
		scanf("%d", &op);
		if(op==0)
		{
			fclose(fp);
			break;
		}
	}
	return 0;
}
