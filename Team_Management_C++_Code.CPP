#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<process.h>
#include<iomanip.h>
#include<dos.h>

void write();
void read(); 			//Function Prototype
void search();
void update();
void deletee();


class PLAYER
{
	int eid;
	char ename[40];		//Class Fields
	float esal;
	int term;

public:
	PLAYER()
	{
		eid=0;
		strcpy(ename," ");	//Constructor
		esal=0.0;
		term=0;

	}
	void get()
	{
		cout<<"\n\t Enter the Jersey Number of the player :--- ";
		cin>>eid;
		cout<<"\n\t Enter the Player Name :--- ";	//Function to
		gets(ename);			//take input into field
		cout<<"\n\t Enter Contract Salary :--- ";
		cin>>esal;
		cout<<"\n\t Enter Contract Term in years :--- ";
		cin>>term;
	}
	void put()
	{
		cout<<"\n\t The Jersey Number of the player is :--- "<<eid;
		cout<<"\n\t The Player Name is :--- ";		//Function to display
		puts(ename);			//content of the field
		cout<<"\t The Contract Salary is :--- "<<esal;
		cout<<"\n\t The Contract Term in years is :--- "<<term;
		cout<<"\n";
	}
	int getid()
	{
		return eid;		//return current record eid
	}
	char * getname()
	{
		return ename;           //return current record ename
	}
	float getsal()
	{
		return esal;		//return current record esal
	}
	int getterm()
	{
		return term;
	}
};
PLAYER e1,e2;

ofstream fout;			//Global variable
ifstream fin;
fstream finout;



void main()
{
int choice;
char ans;
/* ********  My Project - TEAM MANAGEMENT ********  */
printf("\n       *****************        ****************       **************** ");
printf("\n       *****************       *****************       ***************** ");
printf("\n       ****                   ****                     ****          **** ");
printf("\n       ****                   ****                     ****          **** ");
printf("\n       ****                   ****                     ****          **** ");
printf("\n       *****************      ****                     ****************** ");
printf("\n       *****************      ****                     ****************** ");
printf("\n       ****                   ****                     ****          **** ");
printf("\n       ****                   ****                     ****          **** ");
printf("\n       ****                   ****                     ****          **** ");
printf("\n       ****                    *****************       ***************** ");
printf("\n       ****                     ****************       **************** ");
cout<<"\n";
cout<<"\n    ***** WELCOME TO FC BARCELONA !! - THE GREATEST CLUB IN THE WORLD *****";
do
{

	cout<<"\n       *** HI COACH !! HERE'S THE KEY TO TEAM'S PORTAL AND MANAGEMENT ***\n";
	cout<<"\n\t1. * Enter Each Player Details Coach !! *";
	cout<<"\n\t2. * View Each Player's details Coach !! *";
	cout<<"\n\t3. * Do you want to search any player, Coach !! ? *";
	cout<<"\n\t4. * Do you want to update any Player's details, Coach !! ? *";	//Menu of Emp Project
	cout<<"\n\t5. * Do you want to delete any Player's details, Coach !! ? *";
	cout<<"\n\t6. * Ooh man !! Clear the rubbish on the screen !! *";
	cout<<"\n\t7. * Let's get out of this world and apply the tactics there *\n";
	cout<<"\t           * Enter Your Choice, Coach !! :- ";
	cin>>choice;
	switch(choice)
	{
		case 1: write(); break;
		case 2: read(); break;
		case 3: search(); break;
		case 4: update(); break;   //Calling function
		case 5: deletee(); break;
		case 6: clrscr();  break;
		case 7: exit(1);
		default :  cout<<"\n\t !!!Wrong Choice Tried coach !! enter Right Choice!!!";
	}
}while(1);
}
void write()
{
	char ans;
	fout.open("PLAYER.dat",ios::binary|ios::app);
	do
	{
	e1.get();
	fout.write((char*)&e1,sizeof(PLAYER));
	cout<<"\n\t Do You Want To Add More Records of players ? Press 'y' or 'Y' :----\n";
	cin>>ans;
	}while(ans=='y' || ans=='Y');
	fout.close();
}
void read()
{
	fin.open("PLAYER.dat",ios::binary);
	while(fin.read((char*)&e1,sizeof(PLAYER)))
	{
		e1.put();
	}
	fin.close();

}
void search()
{
	int choice,id,a;
	float sal1,sal2;
	char name[30];
	cout<<"\n\tSearch from any one of the details, coach !!\n";
	do
	{
		a=0;
		cout<<"\n\t 1. Jersey Number :---";
		cout<<"\n\t 2. Player name :---";
		cout<<"\n\t 3. Contract details :---";
		cout<<"\n\t 4. Contract term :---";
		cout<<"\n\t 5. Back to main menu, coach !! :---";
		cout<<"\n\t Enter Your Choice, Coach !! :-- \n";
		cin>>choice;
		switch(choice)
		{
			case 1: fin.open("PLAYER.dat",ios::binary);
				cout<<"\n\t Enter Jersey number :--- ";
				cin>>id;
				while(fin.read((char*)&e1,sizeof(PLAYER)))
				{
					if(e1.getid()==id)
					{
						e1.put();
						a++;
					}
				}
				if(a==0)
					cout<<"\nRecord not found.";
				fin.close();
				break;

			case 2: fin.open("PLAYER.dat",ios::binary);
				cout<<"\n\t Enter Player name :--- ";
				gets(name);
				while(fin.read((char*)&e1,sizeof(PLAYER)))
				{
					if(strcmp(e1.getname(),name)==0)
					{
						e1.put();
						a++;
					}
				}
				if(a==0)
					cout<<"\n\t Record not found.";

				fin.close();
				break;
			case 3: fin.open("PLAYER.dat",ios::binary);
				cout<<"\n\t Enter 1st Contract Salary :- ";
				cin>>sal1;
				cout<<"\n\t Enter 2nd Contract Salary :- ";
				cin>>sal2;
				while(fin.read((char*)&e1,sizeof(PLAYER)))
				{
					int salary=e1.getsal();
					if(salary>=sal1 && salary<=sal2)
					{
						e1.put();
						a++;
					}
				}
				if(a==0)
					cout<<"\n\t Record not found.";

				fin.close();
				break;
			case 4: fin.open("PLAYER.dat",ios::binary);
				cout<<"\n\t Enter Contract term :--- ";
				cin>>id;
				while(fin.read((char*)&e1,sizeof(PLAYER)))
				{
					if(e1.getterm()==id)
					{
						e1.put();
						a++;
					}
				}
				if(a==0)
					cout<<"\n\t Record not found.";
				fin.close();
				break;
			case 5: main();
			default: cout<<"\n\t Wrong Choice For Search Menu, Coach !!";
		}
	}while(1);
}
void update()

{
	fstream finout;
	finout.open("PLAYER.dat",ios::binary|ios::in|ios::out);
	char found ='n';
	int id;
	long pos;
	cout<<"\n\t Enter Jersey Number to be Updated :- ";
	cin>>id;
	while(1){
		pos=finout.tellg();
		finout.read((char*)&e1,sizeof(PLAYER));
		if(finout.eof())
			break;
		if(e1.getid()==id)
		{
			found='y';
		cout<<"\n\t Enter Updated Details of Player :--- \n";
		e2.get();
		finout.seekg(pos);
		finout.write((char*)&e2,sizeof(PLAYER));
		cout<<"\n\n";
		break;
		}
		}
	if(found=='n')
	cout<<"\n\t Record Not Found !! " ;
	finout.close();
}
void deletee()
{
	fin.open("PLAYER.dat",ios::binary);
	fout.open("TEMP.dat",ios::binary);
	char found='n';
	int id;
	cout<<"\n\n\t Enter Jersey Number to be Deleted :- ";
	cin>>id;
	while(fin.read((char*)&e1,sizeof(PLAYER)))
	{
		if(e1.getid()==id)
		{
			found='y';
			cout<<"\n\n\t Deleted Details of player :--- ";
			e1.put();
		}
		else
			fout.write((char*)&e1,sizeof(PLAYER));
	}
	if(found=='n')
		cout<<"\n\n\t Record Not Found ";
	fin.close();
	fout.close();
	remove("PLAYER.dat");
	rename("TEMP.dat","PLAYER.dat");
}

