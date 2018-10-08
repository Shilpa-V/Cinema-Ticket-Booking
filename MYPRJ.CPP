/* This is a simple CINEMA TICKET BOOKING project for beginners.
   It is only to guide beginners. Here I have shown various fundamental
   concepts of OOCP (Object Oriented Programming Language) like single
   inheritance, multilevel inheritance, constructor, destructor,
   manipulators(setw), file handling, operator overloading,friend
   function, formatted(setw) and unformatted IO(getline).

     /*****************************************************************
      *	Application      : Cinema Ticket Booking	              *
      *	Created By       : Shilpa                                     *
      *	Enrollment Number: 115370693003				      *
      * Subject Code     : 2620007                                    *
      *	Guided By        : Mr. Praful Nanda                           *
      *****************************************************************/

// Inclusion of header files

#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<graphics.h>
#include<dos.h>
#include<process.h>
#include<ctype.h>
#include<iomanip.h>
#include<fstream.h>

//Global variable and function declaration

int i,j,r,c;

void design(int row_st, int row_end,int col_st,int col_end)
{
	for(r=row_st;r<row_end;r++)
	{
		gotoxy(col_st,r);
		cout<<"*";
		gotoxy(col_end-1,r);
		cout<<"*";
	}
	for(c=col_st;c<col_end;c++)
	{
		gotoxy(c,row_st);
		cout<<"*";
		gotoxy(c,row_end);
		cout<<"*";
	}
}

/**  Login class to verify user name and password   **/
/**  provides maximum three valid inputs            **/
/**  if password is valid process bar will be shown **/

class login
{
	private:
		char user[20];
		char password[20];
	public:
		void verify();
		void process();
};

//Checking for user and password validation

void login :: verify()
{
	int flag=0,i=1,inc=0;
	char passwd[20];
	lbl1:
	clrscr();
	design(5,15,20,60);
	gotoxy(24,7);
	cout<<" SUBJECT:CINEMA TICKET BOOKING";
	gotoxy(24,9);
	cout<<" DEVELOPED BY : ";
	cout<<"USER";
	gotoxy(24,11);
	cout<<" ENROLLMENT NO:115370693003";
	gotoxy(24,13);
	cout<<" GUIDE : MR.XYZ";

	design(15,25,20,60);
	gotoxy(22,17);
	cout<<"Enter User Name:";
	cin.getline(user,30);
	gotoxy(22,19);
	cout<<"Enter password:";

	inc=0;
	while(inc<5)
	{
		passwd[inc]=getch();
		if(toascii(passwd[inc])==10)
			break;
		inc = inc+1;
		cout<<"*";
	}
		passwd[inc]='\0';

	gotoxy(27,28);
	if(strcmp(passwd,"cn123")==0)
	{
		flag=1;
	}
	else
	{
		cout<<"Wrong password, try again.....";
		getch();
		i++;
		if (i<=3)
			goto lbl1;

	}
	if(flag==0)
	{
		gotoxy(27,35);
		cout<<"Sorry, Invalid try to login..";
		delay(2000);
		exit(0);
	}
}

//Function to design a process bar

void login :: process()
{
	int x=202;
	int y=200;
	int gdriver=DETECT,gmode;
	initgraph(&gdriver,&gmode,"c:\\tc\\bgi");
	setcolor(MAGENTA);
	rectangle(200,200,400,210);
	outtextxy(150,400,"WELCOME TO CITY - GOLD MULTIPLEX.....");
	for(i=1;i<100;i++,x=x+2)
	{
		for(j=1;j<10;j++)
		{
			putpixel(x,y+j,3);
		}
		delay(60);
	}
}

/*** movie class includes movie details        *****/
/*** Includes friend function		       *****/
/*** Includes operator(<<) overloading function*****/

class movie
{
	private:
		int movie_id[5];
		int show_no[4];
	protected:
		int screen_id[5];
		char movie_name[5][25];
	public:
		movie()
		{
			show_no[0]=1;
			show_no[1]=2;
			show_no[2]=3;
			show_no[3]=4;
		}
		void get_movie_data();
		void show_movie_data();
		friend ostream & operator <<(ostream &, movie &);
		~movie(){};
};

// Function to initialize the movie details

void movie::get_movie_data()
{
	for(i=0;i<3;i++)
	{
		movie_id[i]=i+1;
		screen_id[i]=i+1;
	}

	strcpy(movie_name[0],"Don - 2");
	strcpy(movie_name[1],"Titanic - 3D");
	strcpy(movie_name[2],"RA-ONE");
}

//"<<" operator is overloaded for movie object

ostream & operator << (ostream & tmpout, movie & tmpmv)
{
	int a=8;
	tmpout<<"\n\t\t\t\tMOVIE - DETAILS";
	design(3,3,1,81);
	design(5,5,1,81);
	gotoxy(7,4);
	tmpout<<"MOVIE_ID";
	gotoxy(25,4);
	tmpout<<"MOVIE_NAME";
	gotoxy(40,4);
	tmpout<<"SCREEN_NO";
	gotoxy(55,4);
	tmpout<<"PROVIDED SHOWS";
	for(i=0;i<3;i++)
	{

		textcolor(3);
		gotoxy(a,6+i);
		tmpout<<tmpmv.movie_id[i];
		gotoxy(a+15,6+i);
		tmpout<<tmpmv.movie_name[i];
		gotoxy(a+30,6+i);
		tmpout<<setw(10)<<tmpmv.screen_id[i];
		gotoxy(a+47,6+i);
		if(tmpmv.movie_id[i]==1)
			tmpout<<tmpmv.show_no[0]<<" , "<<tmpmv.show_no[1]<<" , "<<tmpmv.show_no[2]<<" , "<<tmpmv.show_no[3];
		if(tmpmv.movie_id[i]==2)
			tmpout<<tmpmv.show_no[1]<<" , "<<tmpmv.show_no[2];
		if(tmpmv.movie_id[i]==3)
			tmpout<<tmpmv.show_no[0]<<" , "<<tmpmv.show_no[1]<<" , "<<tmpmv.show_no[2];
	}

	gotoxy(30,22);
	tmpout<<"Press any key to return..";
}

// screen class derived from movie class with defualt constructor and
// destructor

class screen : public movie
{
	protected:
	char screen_name[5][15];
	int seat[3];

	public:
	       int rate[5];
	       screen()
	       {
			seat[0]=seat[1]=seat[2]=70;
	       }
	       void get_screen_data();
	       void show_screen_data();
	       ~screen(){};
};

//Function to initialize the screen_class variables

void screen::get_screen_data()
{
	strcpy(screen_name[0],"Platinum");
	strcpy(screen_name[1],"Gold");
	strcpy(screen_name[2],"Silver");
	rate[0]=120;
	rate[1]=100;
	rate[2]=80;
}

//Function which shows the screen details

void screen::show_screen_data()
{
	get_movie_data();
	int a=8;
	cout<<"\n\t\t\t\t SCREEN - DETAILS";
	design(3,3,1,81);
	design(5,5,1,81);
	gotoxy(5,4);
	cout<<"SCREEN_ID";
	gotoxy(20,4);
	cout<<"SCREEN_TYPES";
	gotoxy(38,4);
	cout<<"RATE";
	gotoxy(50,4);
	cout<<"MOVIE";
	gotoxy(63,4);
	cout<<"TOTAL SEATS";
	for(i=0;i<3;i++)
	{

		textcolor(3);
		gotoxy(a,6+(i*4));
		cout<<screen_id[i];
		cout<<setw(20)<<screen_name[0]<<setw(12)<<rate[0]<<setw(30)<<seat[0]<<"\n";
		cout<<setw(27)<<screen_name[1]<<setw(13)<<rate[1]<<setw(30)<<seat[1]<<"\n";
		cout<<setw(28)<<screen_name[2]<<setw(12)<<rate[2]<<setw(30)<<seat[2]<<"\n";
		gotoxy(a+42,6+(i*4));
		cout<<movie_name[i];
	}

	design(9,9,1,81);
	design(13,13,1,81);

	gotoxy(30,22);
	cout<<"Press any key to return..";
}

// menu class includes welcome screen and various menus

class menu : public screen
{
	private:
		char mchoice;
		char bchoice;
		char schoice;
	public:
		void welcome_screen();
		char mainmenu();
		char booking_menu();
		char screen_menu();
};

//Function to draw welcome screen

void menu :: welcome_screen()
{
     clrscr();
     int gdriver=DETECT,gmode;
     initgraph(&gdriver,&gmode,"c:\\tc\\bgi");
     cleardevice();
     setbkcolor(1);
     int size=8,style=1;
     settextstyle(style,HORIZ_DIR,size);
     setcolor(RED);
     outtextxy(2,2,"CITY-GOLD");
     outtextxy(2,60,"MULTIPLEX");
     setcolor(4);
     setfillstyle(4,RED);
     bar3d(425,-10,700,500,1,1);
     bar3d(430,-10,700,500,1,1);
     bar3d(435,-10,700,500,1,1);
     bar3d(440,-10,700,500,1,1);
     bar3d(445,-10,700,500,1,1);
     bar3d(450,-10,700,500,1,1);
}

//Function to provide main menu selection

char menu :: mainmenu()
{
	 gotoxy(23,12);
	 cout<<"MAIN MENU";
	 gotoxy(2,13);
	 cout<<"****************************************************";
	 gotoxy(2,15);
	 cout<<"1: MOVIE DETAILS";
	 gotoxy(2,17);
	 cout<<"2: SCREEN DETAILS";
	 gotoxy(2,19);
	 cout<<"3: BOOK TICKETS";
	 gotoxy(2,21);
	 cout<<"4: AVAILABLE SEATS";
	 gotoxy(2,23);
	 cout<<"5: EXIT";
	 gotoxy(2,25);
	 cout<<"ENTER CHOICE:";
	 cin>>mchoice;
	 return mchoice;
}

// Function provides booking menu for selection of screen 1,2 or 3

char menu :: booking_menu()
{
	closegraph();
	clrscr();
	get_movie_data();
	gotoxy(15,3);
	cout<<"BOOKING MENU";
	gotoxy(8,4);
	cout<<"==========================";
	gotoxy(10,5);
	cout<<"1: SCREEN 1 >> "<<movie_name[0];
	gotoxy(10,6);
	cout<<"2: SCREEN 2 >> "<<movie_name[1];
	gotoxy(10,7);
	cout<<"3: SCREEN 3 >> "<<movie_name[2];
	gotoxy(10,8);
	cout<<"4: BACK TO MAIN MENU";
	gotoxy(10,9);
	cout<<"5: EXIT";
	gotoxy(10,15);
	cout<<"ENTER CHOICE:";
	cin>>bchoice;
	return bchoice;
}

//Function to provide selection for screen type : Platinum, Gold or Silver

char menu :: screen_menu()
{
	closegraph();
	clrscr();
	get_screen_data();
	gotoxy(15,3);
	cout<<"SELECT SCREEN TYPE";
	gotoxy(8,4);
	cout<<"==========================";
	gotoxy(10,5);
	cout<<"1: PLATINUM >> Rs. " << rate[0];
	gotoxy(10,6);
	cout<<"2: GOLD >> Rs. " << rate[1];
	gotoxy(10,7);
	cout<<"3: SILVER >> Rs. " << rate[2];
	gotoxy(10,8);
	cout<<"4: BACK TO MAIN MENU";
	gotoxy(10,9);
	cout<<"5: EXIT";
	gotoxy(10,15);
	cout<<"ENTER CHOICE:";
	cin>>schoice;
	return schoice;
}

//booking class inherits screen class at multilevel by movie class
// with defualt constructor and destructor

class booking:public screen
{
	public:
		int platinum[3],gold[3],silver[3];
		booking()
		{
			platinum[0]=gold[0]=silver[0]=0;
			platinum[1]=gold[1]=silver[1]=0;
			platinum[2]=gold[2]=silver[2]=0;

		}
		void book_design(int num);
		int book_ticket(int num, int scr_typ, int rate, char sc);
		void book_dt();
		~booking(){};
};

// Function to provide details that how many seats are available
// For which screen_id and screen_type
// Also stores details in file for permanant storage

void booking::book_dt()
{
	int a=8;
	get_movie_data();
	get_screen_data();
	ofstream f("screen.txt");

	cout<<"\n\t\t\t\t BOOKING - DETAILS";
	design(3,3,1,81);
	design(5,5,1,81);
	gotoxy(5,4);
	cout<<"SCREEN_ID";
	gotoxy(20,4);
	cout<<"SCREEN_TYPES";
	gotoxy(42,4);
	cout<<"AVL. SEATS";
	f<<"screen_id "<<" screen_name "<<" Avl. Seats "<<"\n";
	for(i=0;i<3;i++)
	{

		f<<screen_id[i]<<"\t"<<screen_name[0]<<"\t\t"<<(70-platinum[i])<<"\n";
		f<<screen_id[i]<<"\t"<<screen_name[1]<<"\t\t"<<(70-gold[i])<<"\n";
		f<<screen_id[i]<<"\t"<<screen_name[2]<<"\t\t"<<(70-silver[i])<<"\n";


		textcolor(3);
		gotoxy(a,6+(i*4));
		cout<<screen_id[i];

		cout<<setw(20)<<screen_name[0]<<setw(20)<<(70-platinum[i])<<"\n";
		cout<<setw(27)<<screen_name[1]<<setw(21)<<(70-gold[i])<<"\n";
		cout<<setw(28)<<screen_name[2]<<setw(20)<<(70-silver[i])<<"\n";

	}
	design(9,9,1,81);
	design(13,13,1,81);
	f.close();

	gotoxy(30,22);
	cout<<"Press any key to return..";
}

// Function designs a screen with booked or unbooked tickets for particular
// screen_id and screen_type

void booking::book_design(int num)
{
     int gdriver=DETECT,gmode;
     initgraph(&gdriver,&gmode,"c:\\tc\\bgi");
     cleardevice();
     int i,j,k,l,m,n;

     setcolor(8);
     setfillstyle(8,BLUE);
     bar3d(425,-10,700,500,1,1);
     i=50,j=40,k=100,l=55;
     for(j=40,l=55;j<=450,l<=465;j+=30,l+=30)
	  {
	  for(i=50,k=100;i<=330,k<=400;i+=70,k+=70)
	       {
	       bar3d(i,j,k,l,1,1);
	       }
	  }
     int s=0;
     gotoxy(55,10);
     s=num;
     int w=0;
     for(j=40,l=55;j<=450,l<=465;j+=30,l+=30)
	  {
	  for(i=50,k=100;i<=330,k<=400;i+=70,k+=70)
	       {
	       w+=1;
	       if(w>=s+1)
	       {
	       break;
	       }
	       setcolor(2);
	       setfillstyle(2,2);
	       bar3d(i,j,k,l,1,1);
	       }
	  }
}

// Function to check availabilty for seats at particular screen and
// show total amount if tickets get booked

int booking::book_ticket(int num,int scr_typ, int rate, char sc)
{
      book_design(scr_typ);
     screen sob;
     sob.get_screen_data();
     char scr_name[25];
     char scr_tp[25];
     if(sc=='1')
	strcpy(scr_name,"Screen     : 1");
     if(sc=='2')
	strcpy(scr_name,"Screen     : 2");
     if(sc=='3')
	strcpy(scr_name,"Screen     : 3");
    if(rate==sob.rate[0])
	strcpy(scr_tp,"PLATINUM");
     if(rate==sob.rate[1])
	strcpy(scr_tp,"GOLD");
     if(rate==sob.rate[2])
	strcpy(scr_tp,"SILVER");


     if((scr_typ+num)<=70)
     {
	  int st=scr_typ+1;
	  scr_typ+=num;
	  closegraph();
	  clrscr();
	  book_design(scr_typ);

	  gotoxy(55,5);
	  cout<<"TICKETS ARE BOOKED...";

	  gotoxy(55,9);
	  cout<<scr_name;
	  gotoxy(55,11);
	  cout<<"Screen Type: "<<scr_tp;
	  gotoxy(55,13);
	  cout<<"Seat No    : "<<st<<" - "<<(st+num)-1;

	  gotoxy(55,15);
	  cout<<"Please PAY : ";

	  gotoxy(67,15);
	  cout<<"Rs."<<num * rate;

	 for(int t=1;t<=20;t++)
	  {
		if(t%2==0)
		{
			gotoxy(60,25);
			cout<<"Printing...";
		}
		else
		{
			gotoxy(60,25);
			cout<<"           ";
		}
		delay(400);
	  }
	  gotoxy(60,25);
	  cout<<"Done........";
	  getch();
     }
     else
     {
	  clrscr();
	  closegraph();
	  book_design(scr_typ);
	  gotoxy(55,11);
	  cout<<" SORRY, NOT AVAILABLE... ";
	  getch();
     }
	  return scr_typ;
}

int main()
{
	login user1;
	menu menuobj;
	movie m1;
	screen s1;
	booking bkobj;
	char ans;
	int a,bch,num;
	char mch;
	clrscr();
	textcolor(CYAN);

	user1.verify();
	user1.process();

	do
	{
	entry:
	clrscr();
	menuobj.welcome_screen();
	mch=menuobj.mainmenu();
	switch(mch)
	{
		case '1':
			clrscr();
			closegraph();
			textcolor(CYAN);
			m1.get_movie_data();
			cout<<m1;
			getch();
			break;
		case '2':
			clrscr();
			closegraph();
			s1.get_screen_data();
			s1.show_screen_data();
			getch();
			break;
		case '3':
			top:
			clrscr();

			do
			{
			bch=menuobj.booking_menu();
			switch(bch)
			{
				case '1':

					char scr_ty1;

					scr_ty1=menuobj.screen_menu();
					s1.get_screen_data();
					if(scr_ty1=='1')
					{
					do
					{
						 clrscr();
						 bkobj.book_design(bkobj.platinum[0]);
						 gotoxy(58,7);
						 cout<<"NUMBER OF TICKETS:";
						 cin>>num;
						 bkobj.platinum[0]=bkobj.book_ticket(num,bkobj.platinum[0],s1.rate[0],bch);
						 bkobj.book_design(bkobj.platinum[0]);
						 gotoxy(58,22);
						 cout<<"RESERVE MORE(Y/N)?";
						 cin>>ans;
					 }while(toupper(ans)!='N');
					goto top;
					}

					else if(scr_ty1=='2')
					{
					do
					{
						 clrscr();
						 bkobj.book_design(bkobj.gold[0]);
						 gotoxy(58,7);
						 cout<<"NUMBER OF TICKETS:";
						 cin>>num;
						 bkobj.gold[0]=bkobj.book_ticket(num,bkobj.gold[0],s1.rate[1],bch);
						 bkobj.book_design(bkobj.gold[0]);
						 gotoxy(58,22);
						 cout<<"RESERVE MORE(Y/N)?";
						 cin>>ans;
					 }while(toupper(ans)!='N');
					goto top;
					}

					else if(scr_ty1=='3')
					{
					do
					{
						 clrscr();
						 bkobj.book_design(bkobj.silver[0]);
						 gotoxy(58,7);
						 cout<<"NUMBER OF TICKETS:";
						 cin>>num;
						 bkobj.silver[0]=bkobj.book_ticket(num,bkobj.silver[0],s1.rate[2],bch);
						 bkobj.book_design(bkobj.silver[0]);
						 gotoxy(58,22);
						 cout<<"RESERVE MORE(Y/N)?";
						 cin>>ans;
					 }while(toupper(ans)!='N');
					goto top;
					}

					else if(scr_ty1=='4')
					{
						goto entry;
						break;
					}
					else if(scr_ty1=='5')
					{
						exit(0);
					}
					else
					{
					       gotoxy(30,20);
					       cout<<"INVALID CHOICE...";
					       getch();
					       goto top;
					}
					break;

				case '2':
					char scr_ty2;
					scr_ty2=menuobj.screen_menu();
					s1.get_screen_data();
					if(scr_ty2=='1')
					{
					do
					{
						 clrscr();
						 bkobj.book_design(bkobj.platinum[1]);
						 gotoxy(58,7);
						 cout<<"NUMBER OF TICKETS:";
						 cin>>num;
						 bkobj.platinum[1]=bkobj.book_ticket(num,bkobj.platinum[1],s1.rate[0],bch);
						 bkobj.book_design(bkobj.platinum[1]);
						 gotoxy(58,22);
						 cout<<"RESERVE MORE(Y/N)?";
						 cin>>ans;
					 }while(toupper(ans)!='N');
					goto top;
					}

					else if(scr_ty2=='2')
					{
					do
					{
						 clrscr();
						 bkobj.book_design(bkobj.gold[1]);
						 gotoxy(58,7);
						 cout<<"NUMBER OF TICKETS:";
						 cin>>num;
						 bkobj.gold[1]=bkobj.book_ticket(num,bkobj.gold[1],s1.rate[1],bch);
						 bkobj.book_design(bkobj.gold[1]);
						 gotoxy(58,22);
						 cout<<"RESERVE MORE(Y/N)?";
						 cin>>ans;
					 }while(toupper(ans)!='N');
					goto top;
					}

					else if(scr_ty2=='3')
					{
					do
					{
						 clrscr();
						 bkobj.book_design(bkobj.silver[1]);
						 gotoxy(58,7);
						 cout<<"NUMBER OF TICKETS:";
						 cin>>num;
						 bkobj.silver[1]=bkobj.book_ticket(num,bkobj.silver[1],s1.rate[2],bch);
						 bkobj.book_design(bkobj.silver[1]);
						 gotoxy(58,22);
						 cout<<"RESERVE MORE(Y/N)?";
						 cin>>ans;
					 }while(toupper(ans)!='N');
					goto top;
					}

					else if(scr_ty2=='4')
					{
						goto entry;
						break;
					}
					else if(scr_ty2=='5')
					{
						exit(0);
					}
					else
					{
					       gotoxy(30,20);
					       cout<<"INVALID CHOICE...";
					       getch();
					       goto top;
					}
					break;

				case '3':
					char scr_ty3;
					scr_ty3=menuobj.screen_menu();
					s1.get_screen_data();
					if(scr_ty3=='1')
					{
					do
					{
						 clrscr();
						 bkobj.book_design(bkobj.platinum[2]);
						 gotoxy(58,7);
						 cout<<"NUMBER OF TICKETS:";
						 cin>>num;
						 bkobj.platinum[2]=bkobj.book_ticket(num,bkobj.platinum[2],s1.rate[0],bch);
						 bkobj.book_design(bkobj.platinum[2]);
						 gotoxy(58,22);
						 cout<<"RESERVE MORE(Y/N)?";
						 cin>>ans;
					 }while(toupper(ans)!='N');
					goto top;
					}

					else if(scr_ty3=='2')
					{
					do
					{
						 clrscr();
						 bkobj.book_design(bkobj.gold[2]);
						 gotoxy(58,7);
						 cout<<"NUMBER OF TICKETS:";
						 cin>>num;
						 bkobj.gold[2]=bkobj.book_ticket(num,bkobj.gold[2],s1.rate[1],bch);
						 bkobj.book_design(bkobj.gold[2]);
						 gotoxy(58,22);
						 cout<<"RESERVE MORE(Y/N)?";
						 cin>>ans;
					 }while(toupper(ans)!='N');
					goto top;
					}

					else if(scr_ty3=='3')
					{
					do
					{
						 clrscr();
						 bkobj.book_design(bkobj.silver[2]);
						 gotoxy(58,7);
						 cout<<"NUMBER OF TICKETS:";
						 cin>>num;
						 bkobj.silver[2]=bkobj.book_ticket(num,bkobj.silver[2],s1.rate[2],bch);
						 bkobj.book_design(bkobj.silver[2]);
						 gotoxy(58,22);
						 cout<<"RESERVE MORE(Y/N)?";
						 cin>>ans;
					 }while(toupper(ans)!='N');
					goto top;
					}

					else if(scr_ty3=='4')
					{
						goto entry;
						break;
					}
					else if(scr_ty3=='5')
					{
						exit(0);
					}
					else
					{
					       gotoxy(30,20);
					       cout<<"INVALID CHOICE...";
					       getch();
					       goto top;
					}
					break;

				case '4':
					break;

				case '5':
					exit(0);

				default:
					gotoxy(30,20);
					cout<<"INVALID CHOICE..";
					getch();
			}
			}while(bch!='4');
			break;

		case '4':
			clrscr();
			closegraph();

			s1.get_screen_data();
			bkobj.book_dt();
			getch();
			break;

		case '5':
			exit(0);
			break;

		default:
			gotoxy(15,28);
			cout<<"Invalid choice...";
			getch();
	}
	}while(mch!='5');
	return 0;
}
