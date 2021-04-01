#include <stdio.h>
#include <conio.h>
#include <string.h>

static void force_fpf(){
	float x, *y;
	y = &x;
	x = *y;
}

typedef struct studentInfo{
    int studentNumber;
    char fname[256],lname[256],mname[256];
    float nstp2[5],pe2[5],ge2[5],csc13[5],csc14[5],cses2[5],fil1[5];
    float average,equiv;

}student;

    student infoIn[50],test1;
    int numberOfStudents=0,i,j;
    int studentNum;
    char pmft[3][10]={"PRELIM","MIDTERM","FINALS"};

 char choice,ScaNner;
 int x;

    void frame();
    void mainMenu();
    void result();
    void addEdit();
	void addStudent();
	void displayStudents();
	void searchStudent();
	void enterGrade();
	void Grades();
	void modify();
	void deleteStudent();

    void insertionSort();
    void ainsertionSort();

    float gwa(float average)
	{
		if(average>=98){return 1.00;}
		else if(average>=95){return 1.25;}
		else if(average>=92){return 1.50;}
		else if(average>=89){return 1.75;}
		else if(average>=86){return 2.00;}
		else if(average>=83){return 2.25;}
		else if(average>=80){return 2.50;}
		else if(average>=77){return 2.75;}
		else if(average>=75){return 3.00;}
		else {return 5.00;}
	}
	
	

int main()
{
	frame();
	mainMenu();
	return 0;
}

void frame()
{
	clrscr();
	printf(" _____________________________________________________________________________\n");
	printf("|                    |                                                        |\n");
	printf("|____________________|                                                        |\n");
	printf("|                    |                                                        |\n");
	printf("|                    |                                                        |\n");
	printf("|                    |                                                        |\n");
	printf("|                    |                                                        |\n");
	printf("|                    |                                                        |\n");
	printf("|                    |                                                        |\n");
	printf("|____________________|                                                        |\n");
	printf("|                    |                                                        |\n");
	printf("|____________________|                                                        |\n");
	printf("|                    |                                                        |\n");
	printf("|                    |                                                        |\n");
	printf("|                    |                                                        |\n");
	printf("|                    |                                                        |\n");
	printf("|                    |                                                        |\n");
	printf("|                    |                                                        |\n");
	printf("|                    |                                                        |\n");
	printf("|                    |                                                        |\n");
	printf("|                    |                                                        |\n");
	printf("|                    |                                                        |\n");
	printf("|                    |                                                        |\n");
	printf("|____________________|________________________________________________________|\n");


	gotoxy(8,2);
	printf("MAIM MENU");
	gotoxy(3,5);
	printf("[1]Result");
	gotoxy(3,6);
	printf("[2]Entry Menu");
	gotoxy(3,7);
	printf("[3]Exit");
	gotoxy(3,9);
	printf("Enter (1-3): ");

	x=3;
	gotoxy(x+4,11);
	printf("ENTRY MENU");
	gotoxy(x,14);
	printf("[1]ADD STUDENT");
	gotoxy(x,15);
	printf("[2]DISPLAY");
	gotoxy(x,16);
	printf("[3]SEARCH");
	gotoxy(x,17);
	printf("[4]MODIFY");
	gotoxy(x,18);
	printf("[5]DELETE");
	gotoxy(x,19);
	printf("[6]BACK");

	gotoxy(x,21);
	printf("Enter (1-6): ");

}








    void mainMenu()
	{
		gotoxy(16,9);
		scanf(" %c",&choice);
		frame();
		switch(choice){

		case '1': result();
			  mainMenu();
		break;

		case '2':addEdit();
		break;

		case '3':exit(0);
		break;

		default: mainMenu();
			 exit(0);
			       }
	}

    void result()
	{
	int newline=0;
	ainsertionSort();
	gotoxy(43,2);
	printf("GRADE RESULT");
	gotoxy(23,3);
	printf("________________________________________________________");
	gotoxy(24,4);
	printf("STUDENT NAMES                      |   GWA   | REMARKS ");
	gotoxy(23,5);
	printf("____________________________________|_________|_________");
		for(i=0;i<numberOfStudents;i++)
		{

			gotoxy(25,6+newline);
			printf(" %s, %s %c.",infoIn[i].lname,infoIn[i].fname,infoIn[i].mname[0]);
			gotoxy(59,6+newline);
			printf("|         |         ");
			gotoxy(62,6+newline);
			printf("%.2f",infoIn[i].average);
			gotoxy(71,6+newline);
			printf("%s",infoIn[i].average>=3.0?"PASSED":"FAILED");
			gotoxy(23,7+newline);
			printf("____________________________________|_________|_________");
			newline+=2;

		if(newline==16&&i!=numberOfStudents-1)
		{
			gotoxy(41,22);
			printf("Next? (y/n) : ");
			scanf(" %c",&choice);
			if(choice == 'n'|| choice == 'N'){break;}
			newline=0;
		for(j=0;j<16;j++)
		{
		gotoxy(23,7+j);
		printf("                                                        ");
		newline+=2;
		}
		newline=0;
		}
		}
	}

    void addEdit()
	{
		gotoxy(16,21);
		scanf(" %c",&choice);
		frame();
	switch(choice){

	case '1': addStudent();
	break;

	case '2': displayStudents();
	break;

	case '3': searchStudent();
	break;

	case '4': modify();
	break;

	case '5': deleteStudent();
	break;

	case '6':mainMenu();
	break;

		       }
	addEdit();
	}

	void addStudent()
	{
    gotoxy(37,2);
    printf("ENTER DETAILS OF THE STUDENT");
    gotoxy(23,3);
    printf("________________________________________________________");
    gotoxy(24,5);
    printf("Student no.");
    scanf(" %d",&infoIn[numberOfStudents].studentNumber);

    for(i=0;i<numberOfStudents;i++){
	if(infoIn[numberOfStudents].studentNumber == infoIn[i].studentNumber){
	gotoxy(56,16);
	    printf("STUDENT No. EXIST.");
	    addEdit();
	    break;
	}
    }

    gotoxy(24,6);
    printf("First name : ");
    scanf(" %[^\n]s",&infoIn[numberOfStudents].fname);
    strupr(infoIn[numberOfStudents].fname);
    gotoxy(24,7);
    printf("Middle name: ");
    scanf(" %[^\n]s",&infoIn[numberOfStudents].mname);
    strupr(infoIn[numberOfStudents].mname);
    gotoxy(24,8);
    printf("Last name  : ");
    scanf(" %[^\n]s",&infoIn[numberOfStudents].lname);
    strupr(infoIn[numberOfStudents].lname);
    numberOfStudents++;
    gotoxy(24,9);
    printf("STUDENT ADDED TO THE CLASS.");
    	}

	void displayStudents()
	{
	int newLine = 0;
	insertionSort();
	gotoxy(41,2);
	printf("ALL STUDENT ENROLLED");
	gotoxy(23,3);
	printf("________________________________________________________");
	gotoxy(26,4);
	printf("STUDENT NO.  |");

	gotoxy(55,4);
	printf("STUDENT NAME");
	gotoxy(23,5);
	printf("________________|_______________________________________");

	for(i=0;i<numberOfStudents;i++){
		gotoxy(25,6+newLine);
		printf("%d",infoIn[i].studentNumber);
		gotoxy(39,6+newLine);
		printf("|  %s, %s %c.",infoIn[i].lname,infoIn[i].fname,infoIn[i].mname[0]);
		gotoxy(23,7+newLine);
		printf("________________|_______________________________________");
		newLine+=2;

		if(newLine==16&&i!=numberOfStudents-1)
		{
			gotoxy(41,22);
			printf("Next? (y/n) : ");
			scanf(" %c",&choice);
			if(choice == 'n'|| choice == 'N'){break;}
			newLine=0;
		for(j=0;j<16;j++)
		{
		gotoxy(23,7+j);
		printf("                                                        ");
		newLine+=2;
		}
		newLine=0;
		}

	}
	}

	void searchStudent()
	{
	gotoxy(24,3);
	printf("Enter student number : ");
	scanf(" %d",&studentNum);

	Grades();

	if(i==numberOfStudents){
	    gotoxy(32,13);
	    printf("Student not exist.");}
	else{
	gotoxy(23,15);
	printf("EDIT GRADES? (enter 'Y' if yes.) : ");
	scanf(" %c",&choice);
	if(choice=='y'||choice=='Y'){enterGrade(i);}
	}}

	void enterGrade(int i)
	{

	    int pmf;
	    gotoxy(23,16);
	    printf("[1]PRELIM [2]MIDTERM [3]FINALS ||Enter choice: ");
	    scanf(" %d",&pmf);
	    gotoxy(23,17);
	    printf("--------------------------------------------------------");
	    pmf-=1;
	    if(pmf<0||pmf>2){
	       gotoxy(23,17);
	       printf("INVALID.");
	       }
	    else{
	    gotoxy(23,18);
	    printf("[1]NSTP2   [2]PE2   [3]GE2 [4]CSC 1-3");
	    gotoxy(23,19);
	    printf("[5]CSC 1-4 [6]CSES2 [7]FIL1");
	    gotoxy(23,20);
	    printf("Enter choice: ");
	    scanf(" %c",&choice);



	    gotoxy(23,21);
	    printf("--------------------------------------------------------");

	    gotoxy(23,22);
	    switch(choice){

		case '1':printf("Enter grade 1 - 100: ");
			 scanf(" %f",&infoIn[i].nstp2[pmf]);
			 infoIn[i].nstp2[3] = infoIn[i].nstp2[0]*(float)0.3+infoIn[i].nstp2[1]*(float)0.3+infoIn[i].nstp2[2]*(float)0.4;
			 gotoxy(50,22);
			 printf("NSTP2 %s GRADE ADDED.",pmft[pmf]);
		break;

		case '2':printf("Enter grade 1 - 100: ");
			 scanf(" %f",&infoIn[i].pe2[pmf]);
			 infoIn[i].pe2[3] = infoIn[i].pe2[0]*(float)0.3+infoIn[i].pe2[1]*(float)0.3+infoIn[i].pe2[2]*(float)0.4;
			 gotoxy(50,22);
			 printf("PE2 %s GRADE ADDED.",pmft[pmf]);
		break;

		case '3':printf("Enter grade 1 - 100: ");
			 scanf(" %f",&infoIn[i].ge2[pmf]);
			 infoIn[i].ge2[3] = infoIn[i].ge2[0]*(float)0.3+infoIn[i].ge2[1]*(float)0.3+infoIn[i].ge2[2]*(float)0.4;
			 gotoxy(50,22);
			 printf("GE2 %s GRADE ADDED.",pmft[pmf]);
		break;

		case '4':printf("Enter grade 1 - 100: ");
			 scanf(" %f",&infoIn[i].csc13[pmf]);
			 infoIn[i].csc13[3] = infoIn[i].csc13[0]*(float)0.3+infoIn[i].csc13[1]*(float)0.3+infoIn[i].csc13[2]*(float)0.4;
			 gotoxy(50,22);
			 printf("CSC 1-3 %s GRADE ADDED.",pmft[pmf]);
		break;


		case '5':printf("Enter grade 1 - 100: ");
			 scanf(" %f",&infoIn[i].csc14[pmf]);
			 infoIn[i].csc14[3] = infoIn[i].csc14[0]*(float)0.3+infoIn[i].csc14[1]*(float)0.3+infoIn[i].csc14[2]*(float)0.4;
			 gotoxy(50,22);
			 printf("CSC 1-4 %s GRADE ADDED.",pmft[pmf]);
		break;

		case '6':printf("Enter grade 1 - 100: ");
			 scanf(" %f",&infoIn[i].cses2[pmf]);
			 infoIn[i].cses2[3] = infoIn[i].cses2[0]*(float)0.3+infoIn[i].cses2[1]*(float)0.3+infoIn[i].cses2[2]*(float)0.4;
			 gotoxy(50,22);
			 printf("CSES2 %s GRADE ADDED.",pmft[pmf]);
		break;

		case '7':printf("Enter grade 1 - 100: ");
			 scanf(" %f",&infoIn[i].fil1[pmf]);
			 infoIn[i].fil1[3] = infoIn[i].fil1[0]*(float)0.3+infoIn[i].fil1[1]*(float)0.3+infoIn[i].fil1[2]*(float)0.4;
			 gotoxy(50,22);
			 printf("FIL1 %s GRADE ADDED.",pmft[pmf]);
		break;

		default:
	        gotoxy(53,22);
		printf("Invalid");
	    }
		infoIn[i].average = (((gwa(infoIn[i].nstp2[3]/2+50))*3)+((gwa(infoIn[i].pe2[3]/2+50))*2)+((gwa(infoIn[i].ge2[3]/2+50))*3)+((gwa(infoIn[i].csc13[3]/2+50))*3)+((gwa(infoIn[i].csc14[3]/2+50))*3)+((gwa(infoIn[i].cses2[3]/2+50))*3)+((gwa(infoIn[i].fil1[3]/2+50))*3))/20;
		Grades();
		gotoxy(24,23);
		printf("ADD AGAIN? (enter 'Y' if yes.) : ");
		scanf(" %c",&choice);
		if(choice=='y'||choice=='Y'){frame(); Grades(); enterGrade(i);}
		
	}}

	void Grades()
	{
		for(i=0;i<numberOfStudents;i++){
	    if(studentNum == infoIn[i].studentNumber){
		gotoxy(24,5);
		printf("Name: %s, %s %c.",infoIn[i].lname,infoIn[i].fname,infoIn[i].mname[0]);
		gotoxy(26,6);
		printf("SUBJECT CODE\tPRELIM\tMIDTERM\tFINALS\tEQUIV  REMARKS");
		gotoxy(26,7);
		printf("NSTP2\t\t%.0f\t%.0f\t%.0f\t%.2f   %s",infoIn[i].nstp2[0],infoIn[i].nstp2[1],infoIn[i].nstp2[2],gwa(infoIn[i].nstp2[3]/2+50),gwa(infoIn[i].nstp2[3]/2+50)<=3.0?"PASSED":"FAILED");
		gotoxy(26,8);
		printf("PE2\t\t%.0f\t%.0f\t%.0f\t%.2f   %s",infoIn[i].pe2[0],infoIn[i].pe2[1],infoIn[i].pe2[2],gwa(infoIn[i].pe2[3]/2+50),gwa(infoIn[i].pe2[3]/2+50)<=3.0?"PASSED":"FAILED");
		gotoxy(26,9);
		printf("GE2\t\t%.0f\t%.0f\t%.0f\t%.2f   %s",infoIn[i].ge2[0],infoIn[i].ge2[1],infoIn[i].ge2[2],gwa(infoIn[i].ge2[3]/2+50),gwa(infoIn[i].ge2[3]/2+50)<=3.0?"PASSED":"FAILED");
		gotoxy(26,10);
		printf("CSC 1-3\t%.0f\t%.0f\t%.0f\t%.2f   %s",infoIn[i].csc13[0],infoIn[i].csc13[1],infoIn[i].csc13[2],gwa(infoIn[i].csc13[3]/2+50),gwa(infoIn[i].csc13[3]/2+50)<=3.0?"PASSED":"FAILED");
		gotoxy(26,11);
		printf("CSC 1-4\t%.0f\t%.0f\t%.0f\t%.2f   %s",infoIn[i].csc14[0],infoIn[i].csc14[1],infoIn[i].csc14[2],gwa(infoIn[i].csc14[3]/2+50),gwa(infoIn[i].csc14[3]/2+50)<=3.0?"PASSED":"FAILED");
		gotoxy(26,12);
		printf("CSES2\t\t%.0f\t%.0f\t%.0f\t%.2f   %s",infoIn[i].cses2[0],infoIn[i].cses2[1],infoIn[i].cses2[2],gwa(infoIn[i].cses2[3]/2+50),gwa(infoIn[i].cses2[3]/2+50)<=3.0?"PASSED":"FAILED");
		gotoxy(26,13);
		printf("FIL1\t\t%.0f\t%.0f\t%.0f\t%.2f   %s",infoIn[i].fil1[0],infoIn[i].fil1[1],infoIn[i].fil1[2],gwa(infoIn[i].fil1[3]/2+50),gwa(infoIn[i].fil1[3]/2+50)<=3.0?"PASSED":"FAILED");
		gotoxy(23,14);
		printf("--------------------------------------------------------");
		break;
	    }
	}
	}

	void modify(){
	frame();
	gotoxy(39,2);
	printf("MODIFY STUDENT INFORMATION");
	gotoxy(24,4);
        printf("Enter student no.");
        scanf(" %d",&studentNum);

        for(i=0;i<numberOfStudents;i++){
            if(studentNum==infoIn[i].studentNumber){
                break;
            }
        }

        if(i==numberOfStudents){
	    gotoxy(32,13);
            printf("Student not exist.");
            getch();
        }
        else{
	gotoxy(24,6);
        printf("[1]FIRST NAME");
	gotoxy(24,7);
	printf("[2]MIDDLE NAME");
	gotoxy(24,8);
	printf("[3]LAST NAME");
	gotoxy(24,9);
	printf("Enter choice: ");
        scanf(" %c",&choice);



        switch(choice){

            case '1': gotoxy(24,11);
		      printf("ENTER NEW FIRST NAME: ");
                      scanf(" %s",infoIn[i].fname);
                      gotoxy(24,13);
                      printf("FIRST NAME EDITED.");
            break;

            case '2': gotoxy(24,11);
		      printf("ENTER NEW MIDDLE NAME: ");
                      scanf(" %s",infoIn[i].mname);
                      gotoxy(24,13);
                      printf("MIDDLE NAME EDITED.");
            break;

            case '3': gotoxy(24,11);
		      printf("ENTER NEW LAST NAME: ");
                      scanf(" %s",infoIn[i].lname);
		      gotoxy(24,13);
                      printf("LAST NAME EDITED.");
            break;

            default: gotoxy(24,11);
		      
                     printf("INVALID.");
        }
}}
	void deleteStudent(){
	int test;
	gotoxy(24,4);
        printf("Enter student no.");
        scanf(" %d",&studentNum);

        for(i=0;i<numberOfStudents;i++){
            if(studentNum==infoIn[i].studentNumber){
                break;
            }
        }
        if(i==numberOfStudents){
	    gotoxy(32,13);
            printf("Student not exist.");
            getch();
        }
	else{
        test = i;
	gotoxy(24,6);
        printf("Are you sure you want to delete");
	gotoxy(24,7);
	printf("%s, %s %s. ? (enter 'N' to cancel.): ",infoIn[i].lname,infoIn[i].fname,infoIn[i].mname);
        scanf(" %c",&choice);

        if(choice == 'n'||choice == 'N'){
	    gotoxy(32,14);
            printf("Deletion cancelled.");
        }

        else{
            for(i=test;i<numberOfStudents;i++){
                infoIn[i]=infoIn[i+1];
            }
        
        numberOfStudents--;
	gotoxy(32,14);
	printf("STUDENT DELETED.");}}}

    void insertionSort(){
		i=1;
	while(i<numberOfStudents) {
		j=i;
		while(j>0 && strcmp(infoIn[j-1].lname,infoIn[j].lname)>0) {
			test1 = infoIn[j];
			infoIn[j] = infoIn[j-1];
			infoIn[j-1] = test1;
			j--;
		}
		i++;
	}				
}

   
     void ainsertionSort(){
		i=1;
	while(i<numberOfStudents) {
		j=i;
		while(j>0 && infoIn[j-1].average<infoIn[j].average) {
			test1 = infoIn[j];
			infoIn[j] = infoIn[j-1];
			infoIn[j-1] = test1;
			j--;
		}
		i++;
	}				
}
