#include<iostream.h>
#include<stdio.h>
#include<fstream.h>
#include<process.h>
#include<string.h>
#include<conio.h>

class bank

{
char n[25];
long amt ;
int accno;
long Wamt;

public:
void getdata()
{clrscr();
cout<<"ENTER THE NAME: ";
gets(n);
cout<<"ENTER THE ACCOUNT NUMBER(NOT MORE THAN 6 DIGITS): ";
cin>>accno;
cout<<"ENTER THE AMOUNT TO DEPOSIT FOR ADDING TO YOUR ACCOUNT: ";
cin>>amt;
  }

void putdata()
{
cout<<"NAME: ";
puts(n);
cout<<"YOUR ACCOUNT NUMBER: ";
cout<<accno;
cout<<"\nTHE CURRENT BALANCE IS:Rs.";
cout<<amt;
cout<<"\n\n";
 }


int asearch(int acc)
{

if(accno==acc)
return 1;
else
return 0;
 }

void rupdate()
{clrscr();
int i=0;
cout<<"1.PRESS (1) FOR WITHDRAWL\n";
cout<<"2.PRESS (2) FOR DEPOSIT\n";
cin>>i;
																																																																																																						  switch(i)
{
case 1: cout<<"\nENTER THE AMOUNT YOU WANT TO WITHDRAW :Rs.";
cin>>Wamt;
if(Wamt>amt)
cout<<"NOT ENOUGH BALANCE!!!";
else
amt=amt-Wamt;
cout<<"\nYOUR NEW BALANCE IS:Rs."<<amt;
cout<<"\n";

break;

case 2:
cout<<"\nENTER THE AMOUNT YOU WANT TO DEPOSIT :Rs.";
cin>>Wamt;
amt=amt+Wamt;
cout<<"\nYOUR NEW BALANCE IS:Rs."<<amt;
cout<<"\n";
break;

 }
  }
	};

void fwrite()
{clrscr();
bank s;
ofstream of;
of.open("proj.dat",ios::app);
char ans='y';
while(ans=='y'||ans=='Y')
{s.getdata();
of.write((char*)&s,sizeof(s));
cout<<"********* THANK YOU FOR CREATING THE ACCOUNT ********* \n";
cout<<"WANT TO CREATE MORE ACCOUNT....(y/n)\n";
cin>>ans;
}of.close();
cout<<"PRESS ANY KEY TO CONTINUE...";
getch();
clrscr();
 }

void update()
{clrscr();
ifstream iff;
iff.open("proj.dat");
bank p;
ofstream of;
of.open("copy.dat");
int acc=0;
cout<<"\nENTER YOUR ACCOUNT NUMBER:\n";
cin>>acc;
while(iff.read((char*)&p,sizeof(p)))
{ if(p.asearch(acc)==1)
p.rupdate();
of.write((char*)&p,sizeof (p));

 }
of.close();
iff.close();
remove("proj.dat");
rename("copy.dat","proj.dat");
cout<<"PRESS ANY KEY TO CONTINUE...";
getch();
clrscr();
  }

void details()
{clrscr();
ifstream iff;
iff.open("proj.dat");
bank p;
while(iff.read((char*)&p,sizeof(p)))
{
p.putdata();
 }
iff.close();
cout<<"PRESS ANY KEY TO CONTINUE...";
getch();
clrscr();
  }

void sdetails()
{clrscr();
ifstream iff;
iff.open("proj.dat");
int f=1;
bank p;
int acc=0;
cout<<"\nENTER YOUR ACCOUNT NUMBER:\n";
cin>>acc;
while(iff.read((char*)&p,sizeof(p)))
{if(p.asearch(acc)==1)
{
f=0;
break;
}
 }
if(f==0)
p.putdata();
else
cout<<"INVALID ENTRY\n";
iff.close();
cout<<"PRESS ANY KEY TO CONTINUE...";
getch();
clrscr();
 }

void display()
{clrscr();
int x,i=0;
do{
if(i==0)
cout<<"\t********************** WELCOME **********************\n\n";
else
cout<<"\t*****************************************************\n\n";
cout<<"\t\tPRESS (1) FOR CREATING A NEW ACCOUNT IN OUR BANK\n";
cout<<"\t\tPRESS (2) FOR DEPOSITING / WITHDRAWING MONEY FROM YOUR ACCOUNT\n";
cout<<"\t\tPRESS (3) FOR DISPLAYING DETAILS OF ALL ACCOUNTS\n";
cout<<"\t\tPRESS (4) FOR SPECIFIC DETAILS\n";
cout<<"\t\tPRESS (5) FOR EXIT\n";
cout<<"\t*****************************************************\n\n";
cout<<"ENTER YOUR CHOICE:   ";
cin>>x;
i++;
switch(x)
 {
case 1: fwrite();break;
case 2: update();break;
case 3: details();break;
case 4: sdetails();break;
case 5: exit(0);break;
 }
  }
while(x!=5);
	}
main()
 {
display();
  }

