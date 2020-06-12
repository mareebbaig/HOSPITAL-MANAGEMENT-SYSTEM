#include <iostream>
#include <iomanip>
#include <cstring>
#include<conio.h>
#include <string>
#include <fstream>
#include <time.h>
#include<math.h>
#include<windows.h>
#include <sstream> // Doctor ki price ka char [].. integer mein convert krne k liay
using namespace std;
#include "Diagnostic.h"
#include "ReportGeneration.h"
#include "Administration.h"
#include "Wards.h"
#include "Covid19.h"
#include "Influenza.h"
#include "Malaria.h"
#include "Sars.h"
#include "Financedepartment.h"
void delay(int milisec)															// function for delaying screen time
{
	clock_t start_time = clock();
	while (clock() < start_time + milisec);
	
}





int main()
{
    char c, ch;
    Financedepartment f1;
    string name;
    int age;
    char gender;
    string dob;
    cout<< "\n\n\t\t\tREGISTER YOUR SELF\n\n";
    cout<<"\t\t\tEnter your Name: ";
    fflush(stdin);
    getline(cin,name);
    cout<<"\t\t\tEnter your age : ";
    cin>>age;
    cout<<"\t\t\tEnter the character of your gender "<<"M/F/O : ";
    cin>>gender;
    cout<<"\t\t\tEnter your DOB : ";
    fflush(stdin);
    getline(cin,dob);
    cout << "\t\t\t... THANK YOU .....";
    cout << "\n\n\t\t\t LET US PROCEED TO THE DIAGNOSTIC ";
    cout<< "\n\n\n\t\t\tPLEASE WAIT";
    for(int i = 0 ; i < 3 ; i++)
    {
      cout<<".";
      delay(800);
    }
    system("CLS");
    cout<<"\n\nNow you will be displayed with symptoms"<<"\nKindly determine the symptoms you're facing: \n";
       
        cout<<"|-------------------|\n";
        cout<<"|     sore throat   |\n";
        cout<<"|       fatigue     |\n";
        cout<<"|shortness of breath|\n";
        cout<<"|      diarrhea     |\n";
        cout<<"|      headache     |\n";
        cout<<"|     high fever    |\n";
        cout<<"|       cough       |\n";
        cout<<"|     body ache     |\n";
        cout<<"|     vomitting     |\n";
        cout<<"|    bloody stool   |\n";
        cout<<"|     dizziness     |\n";
        cout<<"|   non urinating   |\n";
        cout<<"|     red eyes      |\n";
        cout<<"|  profuse sweating |\n";
        cout<<"|     cold fever    |\n";
        cout<<"|    convulsions    |\n";
        cout<<"|-------------------|";
    cout<<"\nEnter the number count of symptoms you encounter  : ";
    int cn2;
    cin>>cn2;
    string *symptoms;
    string symp[cn2];
    symptoms = symp;
   cout << "\nEnter The symptoms as given in the CHART\n";
    for(int i=0;i<cn2;i++)
    { 
     fflush(stdin);
     getline(cin,*(symptoms+i));
    }

    Diagnostic D1(name,age,dob,gender,symptoms,cn2); //patients information  
    system("PAUSE");
while(true)
{
  system("CLS");
    cout<<"\n1-Do you want to diagnose your disease?"<<endl;
    cout<<"\n2-Do you want to view your disease"<<endl;
    cout<<"\n3-Which ward would you like your patient to be transferred?"<<endl;
    cout<<"\n4-Are you a guardian?(Y/N) "<<"If Yes would you like to know the patients health status?"<<endl;
    cout<<"\n5-View doctor's name and transferred ward"<<endl;
    cout<<"\n6-Do you want to access finance and billing department"<<endl;
    cout<<"\n7-Do you want to view your report?"<<endl;
    cout<<"\n8-Exit" <<endl;
    cout<<"\n\nENTER YOU CHOICE: ";
    cin>>c;
if (c == '1')
{
  system("CLS");
  cout<< "\n\n\n\t\t\tPLEASE WAIT";
  for(int i = 0 ; i < 3 ; i++)
  {
    cout<<".";
    delay(600);
  }
  cout<<endl;
  D1.symptomsMatch();
  cout<<"\n\n\t\t\tYOUR DISEASE HAS BEEN SUCCESSFULLY DIAGNOSED"<<endl;
  cout<<"\n\t\t\tPRESS ANY KEY TO PROCEED TO MAIN MENU" << endl;
  getch();
}
if(c=='2')
{
    system("CLS");
   cout<< "\n\n\n\t\t\tPLEASE WAIT";
    for(int i = 0 ; i < 3 ; i++)
    {
      cout<<".";
      delay(600);
    }
    cout<< endl;
    cout<<"\t\t\tyour diagnosed disease is : ";
    cout<<D1.getDisease()<<endl;
    cout<<"\t\t\tPRESS ANY KEY TO PROCEED TO MAIN MENU" << endl;
    getch();
}
else if(c=='3')
{
    system("CLS");
    cout<< "\n\n\n\t\t\tPLEASE WAIT";
    for(int i = 0 ; i < 3 ; i++)
  {
    cout<<".";
    delay(600);
  }
  cout<< endl;
    int sel3;
    cout<<"\nWhich ward would you prefer for your patient\n";
    cout<<"\n1-Private";
    cout<<"\n2-Semi Privaate";
    cout<<"\n3-General"<<endl << endl;
    cout << "ENTER YOUR CHOICE : ";
    cin >> sel3;
    if(sel3==1)
    {
        f1.Privateward(D1);
    }
    else if(sel3==2)
    {
        f1.semiPrivateward(D1);
    }
    else if(sel3==3)
    {
        f1.generalWard(D1);
    }
}
else if(c=='4')
{ 
  cout << "Yes/No : ";  
  cin >> ch;
  system("CLS");
  cout<< "\n\n\n\t\t\tPLEASE WAIT";
  for(int i = 0 ; i < 3 ; i++)
  {
    cout<<".";
    delay(600);
  }
  cout<<endl;
    if(ch=='y')
    {
  
        if(D1.getDisease()=="Covid19")
        {
            Covid19 C1;
            C1.treatment(D1);
        }
        else if(D1.getDisease()=="sars")
        {
           
            Sars S1;
            S1.treatment(D1);
        }
        else if(D1.getDisease()=="influenza")
        {
            Influenza I1;
            I1.treatment(D1);
        }
        else if(D1.getDisease()=="malaria")
        {
            Malaria m1;
            m1.treatment(D1);
        }
    }
    else if(ch=='n')
    {
      cout<< "PRESS ANY KEY TO GOTO MAIN MENU";
      getch();
       continue;
    }
}
else if(c=='5')
{
  system("CLS");
  cout<< "\n\n\n\t\t\tPLEASE WAIT";
  for(int i = 0 ; i < 3 ; i++)
  {
    cout<<".";
    delay(600);
  }
  cout<<endl;
  cout<<"As we've diagnosed your disease, we'll now assign you the doctor\t"<<endl;
  Administration A1;
  A1.Doctors(D1);
  string d = A1.showdoctor();
  f1.DrBill(d, D1);
  f1.MedicineBill(D1);
}
else if(c=='6')
{
    system("CLS");
    cout<< "\n\n\n\t\t\tPLEASE WAIT";
  for(int i = 0 ; i < 3 ; i++)
  {
    cout<<".";
    delay(600);
  }
  cout<<endl;
    char sel2;
    cout<<"\nYour calculated bill will be displayed now\n";
    cout<<"\nDo you have an insurance policy\n"<<"(Y/N)"<<endl;
    cin >> sel2;
    if(sel2=='y')
    {
         cout << "Your Bill before insurance" <<  f1.totalhospbill() << endl;
          f1.insurance();
           system("PAUSE");
    }
    else if(sel2=='n')
    {
        cout << "Your Total Bill is : " << f1.totalhospbill() << endl;
        system("PAUSE");
    }
    
}
else if(c=='7')
{ 
  system("CLS");
  cout<< "\n\n\n\t\t\tPLEASE WAIT";
  for(int i = 0 ; i < 3 ; i++)
  {
    cout<<".";
    delay(600);
  }
  cout<<endl;
  cout<<"\nNow your report will be formed by the hospital\t"<<endl;
  ReportGeneration R1(D1);
  R1.patientReport();
}
else if(c=='8')
{
  cout <<  "THANK YOU FOR USING OUR SERVICE" ; 
  delay(1000);
  exit(0);
}
}
}