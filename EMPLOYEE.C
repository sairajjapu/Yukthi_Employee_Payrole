#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
struct Emp {
	char ename[25];
	char emp_Id[25];
	char password[15];
	int phoneno;
	int sal;
	char gender;
	char desig[25];
};
struct project{
	char pname;
	char p_Id;
};
struct Dept{
	int deptno;
	char dname[50];
	char eattendance[50];
	   struct Emp demp;
	   struct project pro;
};
struct node{
	struct node *next;
    struct Dept mdept;
	struct node *prev;
}*head=NULL,*tail=NULL;
int view();
int dptvew();
int prdtl();
int edtemp();
void menu();
int AED(char );
int UED(char );
int DED(char );
int RED(char );
int emp();
struct node* mergeSort(struct node* head);
struct node* merge(struct node* first, struct node* second);
struct node* getMiddle(struct node* head);
struct node * binarySearch(struct node* head,char target[25]);
struct node* findMiddle(struct node* head);
int view()
{
	struct node *temp1;
	int i,count=0;
	char EMPNO[10];
	FILE *empout;
	MENU:
	{
		empout=fopen("C://Users/User/Documents/Learning/C/PROJECTS/Yukthi/YUKTHI.bin","rb+");
		if(empout==NULL)
		{
			fprintf(stderr,"\n\n\t\t\tError to open the file");
			exit(1);
		}
	    system("cls");
	    printf("\n\n\t\t\t\t   1.VIEW COMPANY EMPLOYEE DETAILS");
        printf("\n\n\t\t\t\t=========================================");
        printf("\n\n\t\t\t\tEMPLOYEE ID:");
        scanf("%s",EMPNO);
        while(fread(&temp1,sizeof(struct node),12,empout))
	    {
	      if((temp1->mdept.demp.emp_Id)==EMPNO)
      	  {
            printf("\n\t\t\t\t\t=====================================");
            printf("\n\t\t\t\t\t EMPLOYEE NAME:%s",temp1->mdept.demp.ename);
            printf("\n\t\t\t\t\t EMPLOYEE ID:%s",temp1->mdept.demp.emp_Id);
            printf("\n\t\t\t\t\t DEPARTMENT:%s",temp1->mdept.dname);
            printf("\n\t\t\t\t\t Phone No:%d",temp1->mdept.demp.phoneno);
            printf("\n\t\t\t\t\t DESIGNATION:%s",temp1->mdept.demp.desig);
            printf("\n\t\t\t\t\t Project :%s",temp1->mdept.pro.pname);
            printf("\n\t\t\t\t\t=====================================");
            count++;
		  }
    }
    if(count==0)
    {
    	printf("\n\t\t\tEMPLOYEE NOT THERE WITH %s EMP_ID",EMPNO);
	}
  }
    printf("\n\n\t\t\tEnter (5 =BACK)or(1 = MAIN Page)or(0 to EXIT)");
	int choice=((int)getch())-48;
	if(choice==5)
	goto MENU;
	fclose(empout);
	return choice;
}
int dptvew()
{
  MENU:
  {
	char ch;
	system("cls");
	printf("\n\t\t\t\t\t\tII.DEPARTMENTS OVERVIEW");
	printf("\n\t\t\t\t\t====================================");
    printf("\n\t\t\t\t\t 1.COMPUTER SCIENCE");
    printf("\n\t\t\t\t\t 2.CYBER SECURITY");
    printf("\n\t\t\t\t\t 3.DATA SCIENCE.");
    printf("\n\t\t\t\t\t 4.ARTIFICIAL INTELLIGENCE");
    printf("\n\t\t\t\t\t 5.ELECTRICAL");
    printf("\n\t\t\t\t\t 6.INTERNET OF THINGS");
    printf("\n\t\t\t\t\t====================================");
    printf("\n\n\t\t\t\tThese are the departments available in yukthi consultancy\n");
    printf("\n\t\t\t\tEnter your choice to know briefly about departments:");
    ch=getch();
    switch(ch)
    {
    	case '1':
    	{
    		system("cls");
    		printf("\n\t\t\t\t\t1.COMPUTER SCIENCE"); 
    		printf("\n\n\t\t    ===========================================================");
    		printf("\n\n\t\t\tComputer science is the study of computation, \n");
			printf("\t\t\tinformation, and automation.Computer science spans \n");
			printf("\t\t\ttheoretical disciplines (such as algorithms, theory \n");
			printf("\t\t\tof computation, and information theory) to applied \n");
			printf("\t\t\tdisciplines (including the design and implementation \n");
			printf("\t\t\tof hardware and software).Though more often considered\n");
			printf("\t\t\t an academic discipline, computer science is closely \n");
			printf("\t\t\trelated to computer programming.\n");
			printf("\n\n\t\t    ===========================================================");
            break;
		}
    	case '2':
    		{
    			system("cls");
    		printf("\n\t\t\t\t\t2.CYBER SECURITY");
    		printf("\n\n\t\t   =========================================================================");
    		printf("\n\n\t\t\tCybersecurity refers to any technology, measure or practice\n");
			printf("\t\t\tfor preventing cyberattacks or mitigating their impact. \n");
			printf("\t\t\tCybersecurity aims to protect individuals� and organizations�\n");
			printf("\t\t\tsystems, applications, computing devices, sensitive data and \n");
			printf("\t\t\tfinancial assets against simple and annoying computer viruses, \n");
			printf("\t\t\tsophisticated and costly ransomware attacks, and everything in \n\t\t\tbetween.\n");
            printf("\n\n\t\t   =========================================================================");
			break;        
		    }
		
    	case '3':
    	{
    		system("cls");
    		printf("\n\t\t\t\t\t3.DATA SCIENCE");
    		printf("\n\n\t\t   ==========================================================================");
    		printf("\n\n\t\t\tData science combines math and statistics, specialized \n");
			printf("\t\t\tprogramming, advanced analytics, artificial intelligence \n");
			printf("\t\t\t(AI),and machine learning with specific subject matter expertise\n");
			printf("\t\t\tto uncover actionable insights hidden in an organization�s data.\n");
			printf("\t\t\tThese insights can be used to guide decision making and strategic planning.\n");
            printf("\n\n\t\t   ==========================================================================");
			break;
		}
    	case '4':
    	{	
    	    system("cls");
            printf("\n\t\t\t\t\t4.ARTIFICIAL INTELLIGENCE");
            printf("\n\n\t\t    ===========================================================");
    		printf("\n\n\t\t\tArtificial intelligence (AI) refers to computer \n");
			printf("\t\t\tsystems capable of performing complex tasks that \n");
			printf("\t\t\thistorically only a human could do, such as reasoning,\n");
			printf("\t\t\tmaking decisions, or solving problems. Today, the term\n");
			printf("\t\t\t�AI� describes a wide range of technologies that power \n");
			printf("\t\t\tmany of the services and goods we use every day � from \n");
			printf("\t\t\tapps that recommend tv shows to chatbots that provide \n");
			printf("\t\t\tcustomer support in real time.\n");
    	   	printf("\n\n\t\t    ===========================================================");
			   break;
		}
    	case '5':
    	{
    		system("cls");
    		printf("\n\t\t\t\t\t5.ELECTRICAL");
    		printf("\n\n\t\t   ==========================================================");
			printf("\n\n\t\t\tElectrical department is a modern department of \n");
			printf("\t\t\tengineering that comprises several specialised \n");
			printf("\t\t\tcategories like power generation, transmission, \n");
			printf("\t\t\tmotors, batteries, control systems and commercial \n");
			printf("\t\t\tappliances. From tiny microchips and microprocessors\n");
			printf("\t\t\tto large-scale electrical systems and power grids, \n");
			printf("\t\t\tthe field has extensive scope for specialisation.\n");
            printf("\n\n\t\t   ==========================================================");
			break;
    	}
    	case '6':
    	{
    		system("cls");
    		printf("\n\t\t\t\t\t6.INTERNET OF THINGS");
    		printf("\n\n\t\t   ===========================================================================");
    		printf("\n\n\t\t\tThe Internet of Things (IoT) refers to a network of physical");
			printf("\n\t\t\tdevices, vehicles, appliances and other physical objects");
			printf("\n\t\t\tthat are embedded with sensors, software and network connectivity ");
			printf("\n\t\t\tthat allows them to collect and share data. These devices � also");
			printf("\n\t\t\tknown as �smart objects� � can range from simple \n");
			printf("\t\t\t�smart home� devices like smart thermostats, to wearables \n");
			printf("\t\t\tlike smartwatches and RFID-enabled clothing, to complex\n");
			printf("\t\t\tindustrial machinery and transportation systems.\n");
			printf("\t\t\tTechnologists are even envisioning entire �smart cities�\n");
			printf("\t\t\tpredicated on IoT technologies.\n");
    	    printf("\n\n\t\t   ===========================================================================");
			break;
		}
    	default:
    		printf("\n\n\t\t\t\tInvalid choice!!\n");
	}
}
	printf("\n\n\n\t\t\tEnter (5 =BACK)or(1 = MAIN Page)or(0 to EXIT)");
	int choice=((int)getch())-48;
	if(choice==5)
	goto MENU;
	return choice;
}
int prdtl()
{
    char ch;
  MENU:
  {	  	
    system("cls");
   	printf("\n\t\t\t\t\t\t   III.PROJECT DETAILS");
    printf("\n\t\t\t\t=========================================================");
 	printf("\n\t\t\t\t\tHERE IS OUR COMPANY PROJECTS OVERVIEW");
    printf("\n\n\t\t\t\t\t1.ANDROID TASK MONITORING");
    printf("\n\t\t\t\t\t2.FINGERPRINT-BASED ATM SYSTEM");
    printf("\n\t\t\t\t\t3.IMAGE ENCRYPTION USING THE AES ALGORITHM");
    printf("\n\t\t\t\t\t4.FINGERPRINT VOTING SYSTEM");
    printf("\n\t\t\t\t\t5.ANDROID PATIENT TRACKER");
    printf("\n\t\t\t\t\t6.CREDIT CARD FRAUD DETECTION");
    printf("\n\n\t\t\t\t=========================================================");
    printf("\n\t\t\t\tThese are the departments available in yukthi consultancy\n");
    printf("\t\t\t\tEnter your choice to know briefly about departments:");
    ch=getch();
	switch(ch)
	{
		 case '1':{
		 	system("cls");
		 	printf("\n\n\t\t\t\t\t1.Android task monitoring");
		 	printf("\n\n\t\t======================================================================================");
		 	printf("\n\n\t\tThis innovative ideas for project is exclusively designed to simplify the tracking and");
			printf("\n\t\tmonitoring of day-to-day activities of busy modern life. We are so busy in our daily lives");
			printf("\n\t\tright now that it becomes impossible to keep track of our daily events, meetings, and");
            printf("\n\t\tappointments. To address this issue, this project focuses on developing a Weekly Task");
            printf("\n\t\tAlerting System for Android devices that can alert users of the tasks/appointments that");
            printf("\n\t\tare scheduled for each day of the week. ");
			printf("\n\n\t\t======================================================================================");
			break;
		 }
		 case '2':{
		 	system("cls");
		 	printf("\n\n\t\t\t\t\t2.Fingerprint-based ATM system");
		 	printf("\n\n\t\t======================================================================================");
		 	printf("\n\n\t\tThis innovative project ideas for students is a desktop application that uses the");
		 	printf("\n\t\tfingerprint of users for authentication. Since each individual has a unique fingerprint, this");
		 	printf("\n\t\tmethod of using fingerprint as a means of authentication to access your ATM is safer");
		 	printf("\n\t\tand more secure than using an ATM card. Users need not carry their ATM cards with");
		 	printf("\n\t\tthem at all times � they can use their fingerprints to access ATM services. ");
			printf("\n\n\t\t======================================================================================");
			break;
		 }
		 case '3':{
		 	system("cls");
		 	printf("\n\n\t\t\t\t\t3.Image encryption using the AES algorithm");
		 	printf("\n\n\t\t======================================================================================");
		 	printf("\n\n\t\tWhen it comes to communication and imaging systems, you need to incorporate the");
		 	printf("\n\t\thighest level of security in place. Without a reliable and secure system, there�s a massive");
		 	printf("\n\t\tthreat to sensitive data. Cybercriminals and hackers are always on the lookout for");
		 	printf("\n\t\thacking into confidential data, which puts it at risk of being violated. ");
			printf("\n\n\t\t======================================================================================");
			break;
		 }
		 case '4':{
		 	system("cls");
		 	printf("\n\n\t\t\t\t\t4.Fingerprint voting system");
		 	printf("\n\n\t\t======================================================================================");
		 	printf("\n\n\t\tIn this software testing micro project topics, you will develop a fingerprint-based voting");
		 	printf("\n\t\tapplication that can recognize users based on their fingerprint patterns. Since");
		 	printf("\n\t\tfingerprint authentication is unique for each person, the system can quickly identify the");
	        printf("\n\t\tvoters using their fingerprints. Naturally, a voter can vote for a candidate only once.");	
			printf("\n\n\t\t======================================================================================");
			break;
		 }
		 case '5':{
		 	system("cls");
	        printf("\n\n\t\t\t\t\t5.Android Patient Tracker");
			printf("\n\n\t\t======================================================================================");	 	
	        printf("\n\n\t\tThis innovative project ideas for college students involves the development of an");
	        printf("\n\t\tAndroid application for viewing and managing patient data. The app is designed to help");
	        printf("\n\t\tdoctors to see the medical history of their patients. Doctors can also continually");
	        printf("\n\t\tupgrade the system by entering the latest medical data of their patients. ");
			printf("\n\n\t\t======================================================================================");
			break;
		 }
		 case '6':{
		 	system("cls");
		 	printf("\n\n\t\t\t\t\t6.Credit card fraud detection");
		 	printf("\n\n\t\t======================================================================================");
		 	printf("\n\n\t\tCredit card fraud is a significant threat in the BFSI sector. This credit card fraud");
		 	printf("\n\t\tdetection system studies and analyzes user behavior patterns and uses location");
		 	printf("\n\t\tscanning techniques to identify any unusual patterns. One of The user patterns includes");
			printf("\n\t\timportant user behavior like spending habits, usage patterns, etc. The system uses");
			printf("\n\t\tgeographic location for identity verification. In case it detects any unusual pattern, the");
			printf("\n\t\tuser will be required to undergo the verification process again. ");
			printf("\n\n\t\t======================================================================================");
			break;
		 }
		 default:{
		 	printf("\n\n\t\t\tInvalid Choice..");
			break;
		 }
	} 
 }
    printf("\n\n\n\t\t\tEnter (5 =BACK) or (1 = MAIN Page) or (0 to EXIT)");
	int choice=((int)getch())-48;
	if(choice==5)
	goto MENU;
	return choice;
}
int AED(char aname[15])
{
	FILE *empin,*empout;
	struct node *temp,*temp1,*temp2;
	struct node *head1=NULL,*head2=NULL;
	empout=fopen("C://Users/User/Documents/Learning/C/PROJECTS/Yukthi/YUKTHI.bin","rb+");
	if(empout==NULL)
	{
		fprintf(stderr,"\n\t\tError to open the file");
		exit(1);
	}
	while(fread(&temp,sizeof(struct node),12,empout))
	    {
	    	temp->next=NULL;
	    	temp->prev=NULL;
	        if(head1==NULL)
    	    {
    	    	head1=temp1=temp;
    	    }
            else{
     	    	temp1=head1;
     	    	while(temp1->next!=NULL)
     	    	{
     	    	    temp1=temp1->next;
   		        }
 	       	    temp1->next=temp;
    		    temp->prev=temp1;
	        }
       }
       fclose(empout);
	MENU:
	{
		int count=0,ct=0;
	temp=(struct node*)malloc(sizeof(struct node));
	system("cls");
	printf("\n\n\t\t\t\t\t4.EDIT EMPLOYEE DETAILS");
    printf("\n\t\t\t\t=====================================\n");
	printf("\n\t\t\t\t\tI.ADD EMPLOYEE DETAILS ");
	printf("\n\t\t\t\t=====================================");
	printf("\n\t\t\tADMIN:%s",aname);
	printf("\n\t\t\t\t=====================================");
	printf("\n\t\t\t1.Employee Id :");
	scanf("%s",temp->mdept.demp.emp_Id);
	printf("\n\t\t\t2.Employee Name :");
	scanf("%s",temp->mdept.demp.ename);
	printf("\n\t\t\t3.Gender :");
	scanf("%s",temp->mdept.demp.gender);
	printf("\n\t\t\t4.Designation :");
	scanf("%s",temp->mdept.demp.desig);
	printf("\n\t\t\t5.Phone No :");
	scanf("%d",&temp->mdept.demp.phoneno);
	printf("\n\t\t\t6.Salary:");
	scanf("%d",&temp->mdept.demp.sal);
	printf("\n\t\t\t7.Department No:");
	scanf("%d",temp->mdept.deptno);
	printf("\n\t\t\t8.Department Name:");
	scanf("%s",temp->mdept.dname);
	printf("\n\t\t\t9.Project Id:");
	scanf("%s",temp->mdept.pro.p_Id);
	printf("\n\t\t\t10.Project Name:");
	scanf("%s",temp->mdept.pro.p_Id);
	printf("\n\t\t=====================================");
	temp->next=NULL;
	temp->prev=NULL;
	temp1=NULL;
     temp1=binarySearch(head1,temp->mdept.demp.emp_Id);
     if(temp1!=NULL)
     printf("\n\t\t\t\tEMPLOYEE DETAILS ALREADY EXIST");
     else
     {
           	temp1=head1;
            while(temp1->next!=NULL)
            {
            	temp1=temp1->next;
     		}
    		 temp1->next=temp;
    	     temp=mergeSort(head1);
    	     empin=fopen("C://Users/User/Documents/Learning/C/PROJECTS/Yukthi/YUKTHI.bin","wb+");
    		 if(empin==NULL) 
           	{
        		fprintf(stderr,"Error to open the file");
	        	exit(1);
	         }
    		while(temp->next!=NULL)
        	{
        		fwrite(&temp,sizeof(struct node),12,empin);
        		temp=temp->next;
	        }
	        fclose(empin);
       }
	printf("\n\n\t\t\tEnter (5=MENU) or (1 = MAIN Page) or (0 to EXIT)");
	int choice=((int)getch())-48;
	fclose(empin);
	return choice;
}
}
int UED(char aname[15])
{ 
    FILE *empout;
    struct node *temp1,*temp2,*head1=NULL;
    int count1=0,salary;
    char emp_id[25];
    MENU:
    {
    empout=fopen("C://Users/User/Documents/Learning/C/PROJECTS/Yukthi/YUKTHI.bin","rb+");
	if(empout==NULL)
	{
		fprintf(stderr,"Error to open the file");
		exit(1);
	}
	system("cls");
	printf("\n\n\t\t\t\t\t4.EDIT EMPLOYEE DETAILS");
	printf("\n\t\t\t\t======================================\n");
	printf("\n\t\t\t\t\tII.UPDATE EMPLOYEE DETAILS");
    printf("\n\t\t\t\t======================================");
	printf("\n\t\t\t\t\tADMIN:%s",aname);
	printf("\n\t\t\t\t======================================");
	printf("\n\t\t\tEnter Employee Id:");
	scanf("%s",emp_id);
	while(fread(&temp1,sizeof(struct node),12,empout))
	{
		temp1->next=NULL;
		temp1->prev=NULL;
	   if(head1==NULL)
	   {
	   	head1=temp2=temp1;
	   }
	   else{
	   	temp2=head1;
	   	while(temp2->next!=NULL)
	   	{
	   	    temp2=temp2->next;
		   }
		   temp2->next=temp1;
		   temp1->prev=temp2;
	   }
	}
	     temp2 = binarySearch(head1,emp_id);
		if(emp_id==temp2->mdept.demp.emp_Id)
		{
			    int uch;
	    printf("\n\n\t\t\t\t\t4.EDIT EMPLOYEE DETAILS");
	    printf("\n\t\t\t\t================================\n");
	    printf("\n\t\t\t\t\t\tIII.UPDATE EMP DETAILS");
	    printf("\n\t\t\t\t************************************");
	    printf("\n\t\t\t\t\t1.SALARY");
		printf("\n\t\t\t\t\t2.DEPARTMENT");
		printf("\n\t\t\t\t\t3.DESIGNATION");
		printf("\n\t\t\t\t\t4.ATTENDANCE");
		printf("\n\t\t************************************");
		uch=getch();
		switch(uch)
		{
			case '1':{
				printf("\n\t\t\t\t 1.SALARY");
				printf("\n\t\t==================================");
				printf("\n\t\t\tENTER THIS MONTH SALARY:");
				scanf("%d",&salary);
				temp2->mdept.demp.sal+=salary;
				printf("\n\t\t=====================================");
				printf("\n\t\t\tSUCCESSFULLY CHANGED!");
				break;
			}
			case '2':{
				printf("\n\t\t\t2.DEPARTMENT");
				printf("\n\t\t=====================================");
				printf("\n\t\t\tIf you are sure to change department");
				printf("\n\t\t=====================================");
				printf("\n\t\t\t\tDepartment NAME:");
				scanf("%s",temp2->mdept.dname);
				printf("\n\t\t=====================================");
				printf("\n\t\t\tSUCCESSFULLY CHANGED!");
				break;
			}
			case '3':{
                printf("\n\t\t\t3.DESIGNATION");
				printf("\n\t\t=====================================");
				printf("\n\t\t\tIf you are sure to change designation");
				printf("\n\t\t=====================================");
				printf("\n\t\t\t\tDESIGNATION NAME:");
				scanf("%s",temp2->mdept.demp.desig);
				printf("\n\t\t=====================================");
				printf("\n\t\t\tSUCCESSFULLY CHANGED!");				
				break;	
			}
			case '4':{
				printf("\n\t\t\t4.ATTENDANCE");
				printf("\n\t\t=====================================");
				printf("\n\t\t\t\tEMPLOYEE ATTENDANCE :");
				scanf("%s",temp2->mdept.eattendance);
				printf("\n\t\t=====================================");
				printf("\n\t\t\tSUCCESSFULLY CHANGED!");	
				break;
		    }
			default:
				printf("\n\t\t\tINVALID CHOICE");
		}
		}
    else
    {
		printf("\n\t\t\tEMPLOYEE NOT PRESENT");
	}
	FILE *empin=fopen("C://Users/User/Documents/Learning/C/PROJECTS/Yukthi/YUKTHI.bin","wb+");
	temp1=head1;
	while(temp1->next!=NULL)
	{
		fwrite(&temp1,sizeof(struct node),1,empin);
	 }
	fclose(empout);
    fclose(empin); 
   }
   printf("\n\n\t\tEnter (1 = MAIN Page)or(0 to EXIT)");
	int choice=((int)getch())-48;
	return choice;
}
int DED(char aname[15])
{
	int count=0;
	char empid[15];
	struct node *temp1,*temp2,*ytemp1,*ytemp2,*yhead,*head1=NULL;
	FILE *empin,*empout;
	empout=fopen("C://Users/User/Documents/Learning/C/PROJECTS/Yukthi/YUKTHI.bin","rb");
	if(empout==NULL)
	{
		fprintf(stderr,"Error to open the file");
		exit(1);
	}
	FILE *yempin,*yempout;
	yempout=fopen("C://Users/User/Documents/Learning/C/PROJECTS/Yukthi/yukthired.bin","rb");
	if(yempout==NULL)
	{
		fprintf(stderr,"Error to open the file");
		exit(1);
	}
	while(fread(&temp1,sizeof(struct node),12,empout))
	{
		temp1->next=NULL;
		temp1->prev=NULL;
	   if(head1==NULL)
	   {
	   	head1=temp2=temp1;
	   }
	   else{
	   	temp2=head1;
	   	while(temp2->next!=NULL)
	   	{
	   	    temp2=temp2->next;
		   }
		   temp2->next=temp1;
		   temp1->prev=temp2;
	   }
	}
	while(fread(&ytemp1,sizeof(struct node),12,yempout))
	{
		ytemp1->next=NULL;
		ytemp1->prev=NULL;
	   if(yhead==NULL)
	   {
	   	yhead=ytemp2=ytemp1;
	   }
	   else{
	   	ytemp2=yhead;
	   	while(ytemp2->next!=NULL)
	   	{
	   	    ytemp2=ytemp2->next;
		   }
		   ytemp2->next=ytemp1;
		   ytemp1->prev=ytemp2;
	   }
	}
	fclose(empout);
	fclose(yempout);
    empin=fopen("C://Users/User/Documents/Learning/C/PROJECTS/Yukthi/YUKTHI.bin","wb+");
    yempin=fopen("C://Users/User/Documents/Learning/C/PROJECTS/Yukthi/yukthired.bin","wb+");
	if(empin==NULL)
	{
		fprintf(stderr,"Error to open the file");
		exit(1);
	}
	if(yempin==NULL)
	{
		fprintf(stderr,"Error to open the file");
		exit(1);
	}
	system("cls");
	printf("\n\n\t\t\t\t\t  4.EDIT EMPLOYEE DETAILS");
	printf("\n\t\t\t\t==========================================\n");
	printf("\n\t\t\t\t\tIII.DELETE EMPLOYEE DETAILS");
    printf("\n\t\t\t\t==========================================");
	printf("\n\t\t\t\t\tADMIN:%s",aname);
	printf("\n\t\t\t\t==========================================");
	printf("\n\t\t\t\t\tEmployee Id:");
	scanf("%s",empid);
	temp2=head1;
	while(temp2->next!=NULL)
	{
		if((temp2->mdept.demp.emp_Id)==empid)
		{
			count++;
			temp2->prev->next=temp2->next;
			temp2->next->prev=temp2->prev;
			ytemp1=yhead;
			while(ytemp1->next!=NULL)
			{
				ytemp1=ytemp1->next;
			}
			ytemp1->next=temp2;
			temp2->prev=ytemp1;
			free(temp2);
			temp1=head1;
			while(temp1->next!=NULL)
			{
				fwrite(&temp1,sizeof(struct node),12,empin);
			    temp1=temp1->next;
			}
			ytemp1== mergeSort(yhead);///////////////////////////////
		    while(ytemp1->next!=NULL)
			{
				fwrite(&ytemp1,sizeof(struct node),12,yempin);
			    ytemp1=ytemp1->next;
			}	
		}
	}
	if(count==0)
	{
		printf("\n\t\t\tEmployee not found");
	}
	fclose(empin);
	fclose(yempin);
	printf("\n\n\t\tEnter (1 = MAIN Page)or(0 to EXIT)");
	int choice=((int)getch())-48;
	return choice;
}
int RED(char aname[15])
{
	char emp_id[15];
	int count=0;
	struct node *head1=NULL,*temp1,*temp2,*ytemp1,*ytemp2,*yhead=NULL;
	FILE *empin,*empout;
	empout=fopen("C://Users/User/Documents/Learning/C/PROJECTS/Yukthi/YUKTHI.bin","rb+");
	if(empin==NULL)
	{
		fprintf(stderr,"Error to open the file");
		exit(1);
	}
	FILE *yempout,*yempin;
	yempout=fopen("C://Users/User/Documents/Learning/C/PROJECTS/Yukthi/yukthired.bin","rb+");
	if(empout==NULL)
	{
		fprintf(stderr,"Error to open the file");
		exit(1);
	}
	while(fread(&ytemp1,sizeof(struct node),12,yempout))
	{
		ytemp1->next=NULL;
		ytemp1->prev=NULL;
	   if(yhead==NULL)
	   {
	   	yhead=ytemp2=ytemp1;
	   }
	   else{
	   	ytemp2=yhead;
	   	while(ytemp2->next!=NULL)
	   	{
	   	    ytemp2=ytemp2->next;
		   }
		   ytemp2->next=ytemp1;
		   ytemp1->prev=ytemp2;
	   }
	}
	while(fread(&temp1,sizeof(struct node),12,empout))
	{
		temp1->next=NULL;
		temp1->prev=NULL;
	   if(head1==NULL)
	   {
	   	head1=temp2=temp1;
	   }
	   else{
	   	temp2=head1;
	   	while(temp2->next!=NULL)
	   	{
	   	    temp2=temp2->next;
		   }
		   temp2->next=temp1;
		   temp1->prev=temp2;
	   }
	}
	fclose(empout);
	fclose(yempout);
	empin=fopen("C://Users/User/Documents/Learning/C/PROJECTS/Yukthi/YUKTHI.bin","wb+");
    yempin=fopen("C://Users/User/Documents/Learning/C/PROJECTS/Yukthi/yukthired.bin","wb+");
	if(empin==NULL)
	{
		fprintf(stderr,"Error to open the file");
		exit(1);
	}
	if(yempin==NULL)
	{
		fprintf(stderr,"Error to open the file");
		exit(1);
	}
	system("cls");
	printf("\n\n\t\t\t\t\t  4.EDIT EMPLOYEE DETAILS");
	printf("\n\t\t\t\t========================================\n");
	printf("\n\t\t\t\t\tIV.RETRIVE EMPLOYEE DETAILS");
    printf("\n\t\t\t\t========================================");
	printf("\n\t\t\t\tADMIN:%s",aname);
	printf("\n\t\t\t\t========================================");
	printf("\n\t\t\t\tEMPLOYEE ID:");
	scanf("%s",emp_id);
	ytemp2=yhead;
	while(ytemp2->next!=NULL)
	{
		if((ytemp2->mdept.demp.emp_Id)==emp_id)
		{
			count++;
			ytemp2->prev->next=ytemp2->next;
			ytemp2->next->prev=ytemp2->prev;
			temp1=head1;
			while(temp1->next!=NULL)
			{
				temp1=temp1->next;
			}
			temp1->next=ytemp2;
			ytemp2->prev=temp1;
			free(ytemp2);
			ytemp1=yhead;
			while(ytemp1->next!=NULL)
			{
				fwrite(&ytemp1,sizeof(struct node),12,yempin);
			    ytemp1=ytemp1->next;
			}
			temp1== mergeSort(head);
		    while(temp1->next!=NULL)
			{
				fwrite(&temp1,sizeof(struct node),12,empin);
			    temp1=temp1->next;
			}
		}
	}
	if(count==0)
	{
		printf("\n\t\t\tEmployee not found");
	}
	else{
		printf("\n\t\t\t\tEMPLOYEE DATA SUCCESSFULLY RETRIVED");
	}
	fclose(yempout);
	fclose(empout);
	printf("\n\n\t\tEnter (1 = MAIN Page)or(0 to EXIT)");
	int choice=((int)getch())-48;
	return choice;
}
int edtemp()
{
	int i;
	char ch,aid[10],ech,aname[15],aps[10],count=0;
	FILE *empout=fopen("C://Users/User/Documents/Learning/C/PROJECTS/Yukthi/YUKTHI.bin","rb+");
	struct node *temp;
	system("cls");
	printf("\n\n\t\t\t\t\t\t4.EDIT EMPLOYEE DETAILS");
	printf("\n\t\t\t\t=====================================================\n");
	printf("\t\t\t\t  KIND INFORMATION THIS PAGE ONLY FOR ADMINISTRATORS\n");
	printf("\t\t\t\t  WITHOUT ID AND PASSWORD YOUR NOT ALLOWED....");
	printf("\n\n\t\t\t\t\t\t\t LOGIN");
	printf("\n\t\t\t\t======================================================");
	printf("\n\n\t\t\t\t\tADMIN ID:");
	scanf("%s",&aid);
	printf("\n\t\t\t\t\tADMIN PASSWORD:");
	scanf("%s",&aps);
	printf("\n\t\t\t\t======================================================");
	while(fread(&temp,sizeof(struct node),1,empout))
	{	
		if(aid==(temp->mdept.demp.emp_Id))
		{
			if((temp->mdept.demp.desig)=="administrator")
			{
			    if(aps==(temp->mdept.demp.password))
			    {   tail=temp;
			    	goto EMENU;
			    }
		    	else 
	    		{
    				printf("\n\n\t\t\t\tWRONG PASSWORD");
     				break;
	    		}
	        }
	        else
	        {
	        	printf("\n\n\t\t\tSORRY YOU ARE NOT ALLOWED");
			    break;
			}
		}
	}
        if(count==0)	 
		{
			printf("\n\n\t\t\t\t WRONG ADMIN ID,IT IS DIDNOT MATCH WITH OUR DATABASE");
		    printf("\n\n\t\t\t\t Enter (1 = MAIN Page)or(0 to EXIT)");
	        int choice=((int)getch())-48;
	        return choice;
		}
	EMENU:
		{
			system("cls");
			printf("\n\n\t\t\t\t\t\t4.EDIT EMPLOYEE DETAILS");
	        printf("\n\t\t\t\t========================================================\n");
			printf("\n\t\t\tADMIN:%s",&tail->mdept.demp.ename);
			printf("\n\t\t\t\t========================================================");
			printf("\n\t\t\t\t  1.ADD EMPLOYEE DETAILS(Entering employee details)");
			printf("\n\t\t\t\t  2.UPDATE EMPLOYEE DETAILS(update salary,desig,dept)");
			printf("\n\t\t\t\t  3.DELETE EMPLOYEE DETAILS(delete employee details)");
			printf("\n\t\t\t\t  4.RETRIVE EMPLOYEE DETAILS");
			printf("\n\t\t\t\t========================================================\n");
			printf("\t\t\t\t\tEnter your choice");
			ch=getch();
			switch(ch)
			{
				case '1':{
				    ech=AED(tail->mdept.demp.ename);
					if(ech==1)
					goto EMENU;
					break;
				}
				case '2':{
				    ech=UED(tail->mdept.demp.ename);
					if(ech==1)
					goto EMENU;
					break;
				}
				case '3':{
				    ech=DED(tail->mdept.demp.ename);
					if(ech==1)
					goto EMENU;
					break;
				}
				case '4':{
				    ech=RED(tail->mdept.demp.ename);
					if(ech==1)
					goto EMENU;
					break;
				}
				default:{
					printf("\n\t\t\tINVALID CHOICE");
	                printf("\n\n\t\tEnter (1 = MAIN Page)or(0 to EXIT)");
	                int choice=((int)getch())-48;
	                return choice;
					break;
			    }
			}
		 return ech;
		}
}
int emp()
{
	char empid[15],epsd[15];
	int count=0;
	struct node *temp;
	FILE *empout;
	MENU:
    {
	 empout=fopen("C://Users/User/Documents/Learning/C/PROJECTS/Yukthi/YUKTHI.bin","rb+");
	 if(empout==NULL)
	 {
    		fprintf(stderr,"\n\t\tError to open the file");
    		exit(1);
   	 }
	 system("cls");
	 printf("\n\t\t\t\t\t   5.EMPLOYEE PERSONAL LOGIN");
	 printf("\n\t\t\t    ===================================================");
	 printf("\n\t\t\t\t KIND INFORMATION THIS PAGE ONLY FOR EMPLOYEE\n");
	 printf("\t\t\t\t WITHOUT ID AND PASSWORD YOUR NOT ALLOWED....");
	 printf("\n\t\t\t    ===================================================\n");
	 printf("\n\t\t\t\tEmployee Id:");
	 scanf("%s",empid);
	 printf("\n\t\t\t\tPassword:");
	 scanf("%s",epsd);
	 printf("\n\t\t\t    ===================================================\n");
	 rewind(empout);
	 while(fread(&temp,sizeof(struct node),12,empout))
	 {
	  if((temp->mdept.demp.emp_Id)==empid)
	  {
 	 	 if((temp->mdept.demp.password)==epsd)
		 {
	       printf("\n\n\t\t\t\t\tEMPLOYEE DETAILS");
	       printf("\n\t\t\t===================================================\n");
	       printf("\n\n\t\t\t\t1.Employee Id:%s",temp->mdept.demp.emp_Id);
	       printf("\n\n\t\t\t\t2.Employee Name:%s",temp->mdept.demp.emp_Id);
	       printf("\n\n\t\t\t\t3.Employee Designation :%s",temp->mdept.demp.desig);
	       printf("\n\n\t\t\t\t4.Gender:%s",temp->mdept.demp.gender);
	       printf("\n\n\t\t\t\t5.Password:%s",temp->mdept.demp.password);
	       printf("\n\n\t\t\t\t6.Phone No:%d",temp->mdept.demp.phoneno);
	       printf("\n\n\t\t\t\t7.Salary:%d",temp->mdept.demp.sal);
	       printf("\n\n\t\t\t\t8.Department:%s",temp->mdept.deptno);
	       printf("\n\n\t\t\t\t9.Department:%s",temp->mdept.dname);
	       printf("\n\n\t\t\t\t10.Attendance:%d",temp->mdept.eattendance);
	       printf("\n\n\t\t\t\t11.Project Id:%s",temp->mdept.pro.p_Id);
	       printf("\n\n\t\t\t\t12.Project Name:%s",temp->mdept.pro.pname);
	       printf("\n\t\t\t===================================================\n");
	       count++;
		 }
		 else
		 {
			 printf("\n\n\t\t\tSORRY PLEASE CHECK YOUR ID AND PASSWORD AGAIN!!!");
		 }
      }
	 }
	 if(count==0)
	 {
 		 printf("\n\t\t\t\t\tEmployee not found");
	 }
   }
	 fclose(empout);
	 printf("\n\n\t\tEnter (1 = MAIN Page)or(0 to EXIT)");
	 int choice=((int)getch())-48;
	 return choice;
}
void menu()
{
	int k;
	MENU:
	{
	  system("cls");
	  printf("\n\n\n\n\t\t\t\t\t\t      MENU");
	  printf("\n\t\t\t\t\t==================================");
      printf("\n\t\t\t\t\t 1.VIEW COMPANY EMPLOYEE DETAILS");
      printf("\n\t\t\t\t\t 2.DEPARTMENT OVERVIEW ");
      printf("\n\t\t\t\t\t 3.PROJECT  DETAILS");
      printf("\n\t\t\t\t\t 4.EDIT EMPLOYEE DETAILS");
      printf("\n\t\t\t\t\t 5.EMP PERSONAL LOGIN");
      printf("\n\t\t\t\t\t==================================");
      printf("\n\t\t\t\t\tchoose your choice");
      char choice=getch();
      switch(choice)
      {
        	case '1':
    	    {	
				k=view();
    	    	if(k==1)
    		    goto MENU;
    		    break;
            }
		    case '2':
		    {   
			    k=dptvew();
		        if(k==1)
    	    	goto MENU;
	    		break;
		    }
    		case '3':
	        {
    		    k=prdtl();	
	    	    if(k==1)
        		goto MENU;
	    	    break;
		    }
    		case '4':
	        {
    		    k=edtemp();
	    	    if(k==1)
    	    	goto MENU;
	    		break;
            }
     		case '5':
	        {
      		    k=emp();
    		    if(k==1)
        		goto MENU;
    			break; 		
    		}
    		default :
    			printf("\n\n\n\t\t\t\tTHANK U!!");
	    		printf("\n\t\t\t\t\tEXIT!!");
		    	exit(0);
	    }  
    }
}
int main()
{
	system("cls");
	printf("\n\n\n\n\t\t\t\t\t   ============================");
	printf("\n\n\n\t\t\t\t\t\t      WELCOME\n\t\t\t\t\t\t\tTO");
	printf("\n\t\t\t\t\t\tYUKTHI CONSULTANCY");
	printf("\n\n\n\t\t\t\t\t   ============================");
	printf("\n\n\n\t\t\t\t\tHello...Enter 0 for next!!");
	int c=getch()-48;
	if(c==0)
	{
		menu();
	}
	else
	{
		printf("\n\n\n\t\t\t\tTHANK U!!");
	}
	return 0;
}// Function to get the middle node of the linked list
struct node* getMiddle(struct node* head) {
    struct node* slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}// Function to merge two sorted linked lists
struct node* merge(struct node* first, struct node* second) {
    struct node* result = NULL;
    if (first == NULL) {
        return second;
    }
    if (second == NULL) {
        return first;
    }
    if (first->mdept.demp.emp_Id <= second->mdept.demp.emp_Id) {
        result = first;
        result->next = merge(first->next, second);
        result->next->prev = result;
    } else {
        result = second;
        result->next = merge(first, second->next);
        result->next->prev = result;
    }
    return result;
}
struct node* mergeSort(struct node* head) { // Function to sort the linked list using merge sort
    if (head == NULL || head->next == NULL) {
        return head;
    }   
    struct node* middle = getMiddle(head);
    struct node* nextToMiddle = middle->next;
    middle->next = NULL;
    return merge(mergeSort(head), mergeSort(nextToMiddle));
}
struct node* findMiddle(struct node* head) { // Function to find the middle node of the linked list
    if (head == NULL) {
        return NULL;
    }
    struct node* slow = head;
    struct node* fast = head->next;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
struct node* binarySearch(struct node* head, char target[25]) {// Function to perform binary search on the linked list
    if (head == NULL) {
        return NULL; // Target not found
    }
    struct node* middle = findMiddle(head);
    if (middle->mdept.demp.emp_Id == target) {
        return middle; // Target found
    } else if (middle->mdept.demp.emp_Id > target) {
        return binarySearch(head, target); // Search in the left half
    } else {
        return binarySearch(middle->next, target); // Search in the right half
    }
}
