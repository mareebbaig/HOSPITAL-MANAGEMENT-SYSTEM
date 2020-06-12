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
void delay(int milisec)															// function for delaying screen time
{
	clock_t start_time = clock();
	while (clock() < start_time + milisec);
	
}

class Diagnostic
{  

   protected: 
    string doctor;
    const string hospid = "AKU- ";   // hospital's default code
    static int pid;                  // patient's ID
    int age, noofsymptoms;
    string name, symptoms[5], DOB , pat_ID, disease; // pat_ID = contains all concatenated string of both ID's (hosp ID and  pid)
    char gender; 
    public:

    Diagnostic() {}
  Diagnostic(string name,int age,string DOB,char gender,string *symptoms, int n) 
  {
      
      this->name = name;
      this->age = age;
      this->DOB = DOB;
      this->gender = gender;
      noofsymptoms = n; 
      for(int i =0; i< noofsymptoms ;i++)
      this->symptoms[i] = *(symptoms + i);
      this->pid = pid;
      pid++;
      pat_ID = hospid + to_string(pid);
}

void symptomsMatch()
{

  ifstream open("symptoms.txt", ios::in);
  ofstream open1("PatReport.txt", ios::out);
 // string sympt[5] = {"Vomitting","cold-fever","diarrhea","Body-ache","dizziness"};
	string symptom;
	int count = 0;
	
  fflush(stdin);
	getline(open,disease);
  do{
    
    fflush(stdin);
		getline(open,symptom);
		if (symptom == "next")
		{
      fflush(stdin);
			getline(open , disease);
			count = 0;
		}
		else 
		{
			for (int i = 0 ; i < noofsymptoms ; i++)
			{
				if (symptom == symptoms[i])
				{  
					count++;
					//cout<<count<<" "<<symptom<<disease << endl;
					break;
				}
			}
		} 
 	}while(count != noofsymptoms && count != noofsymptoms - 1);
  fflush(stdin);
  //open1 <<  disease;   //disease written in patient report file
  open.close();
  open1.close();
   
}

string getDisease()
{
  return disease;
}

  friend class ReportGeneration;
  friend class Covid19;
  friend class Sars;
  friend class Malaria;
  friend class Influenza;
  friend class Financedepartment;
  
  void set_doctor(string doctor)
  {
    this->doctor = doctor;
  }
  

};
int Diagnostic :: pid = 0;//static variable declaration
class ReportGeneration : public Diagnostic
{     
  public: 
  ReportGeneration() {}
  ReportGeneration(Diagnostic obj)
  {
    ofstream open("PatReport.txt", ios::out);
    open.write((char*)&obj, sizeof(obj));
    open << obj.disease;  
    open.close();  
  } 
  void patientReport()
  {
    ReportGeneration ob2;
    ifstream in("PatReport.txt", ios::in);
    in.read((char*)&ob2,sizeof(ob2));
    in.close();
    ob2.showData();
  }
  void showData()
  {  
    cout << "Patient ID : " << pat_ID << endl;
    cout << "Name : " << name << endl; 
    cout << "Age : " << age << endl;
    cout << "DOB : " << DOB << endl;
    cout << "Gender : " << gender << endl;
    cout << "Symptoms : " ;
    for(int i=0;i<noofsymptoms;i++)
    cout << *(symptoms+i) << endl;  
    cout <<  "Disease : " << disease << endl;
    cout << "Doctor Assigned : " << doctor << endl;
     system("PAUSE");
  }

};
class Administration                                                 
{
  protected:
  string dr;

  public:
  
  void Doctors(Diagnostic &ad)
  {  int n;
     
     string line;
    ifstream open("Doctors.txt", ios::in);
    srand(time(NULL));
    n = 1 + rand()%3;
    string dis = ad.getDisease();
    
    while(!open.eof())
  {
    fflush(stdin);
   getline(open,line);
    if (line.compare(dis)==0)
    {
      for(int i=0;i<n;i++)
      {
      fflush(stdin);  
      getline(open,dr);
      
      }
      cout << "You have been transferred to " << ad.getDisease() << " Ward"  << endl;    
      
      ofstream fout("PatReport.txt", ios::app);
      fout << dr;
      fout.close(); 
      ad.set_doctor(dr);
    break;
      
    }
    
  }
  
    cout<< "Doctor assigned : " << dr << endl;
system("PAUSE");
    
  }
  string showdoctor()
  {
      return dr;
  }


};

class Wards   
{
  public:
  virtual void treatment(Diagnostic &ob) = 0; 

};
// Diseases
class Covid19 : public Wards
{

 public:
  void treatment(Diagnostic &ob)
  {
    ifstream open ("medicine.txt" , ios::in);
	  string str , medicine[ob.noofsymptoms];

    int count = 0 , i= 0 ;
	  size_t found;
	  do
	  {
      fflush(stdin);
		  getline(open , str);
		  found = str.find(ob.symptoms[i]); 
      if (found != string::npos) 
      {
    	  str.erase(found, (ob.symptoms[i].length()+1));
		    medicine[i] = str;
		    open.seekg(0,ios_base::beg);
		    i++;
		    count++;
	    }
		
	  } while (count < ob.noofsymptoms);
    static int fatdi; // high fever, cough
    static int headshort;  // bodypain , shortness of breath
    static int sore; // diarrhea
    int n;
    int flag = 0;
    

    for(int i=1;i<=6;i++)  //days
    {
      for (int j = 0 ; j < ob.noofsymptoms ; j++)
      {
        if (j == 0)
        {
          cout << "\n\nfirst slot (9AM - 12AM)" << endl;
          cout << ob.symptoms[j] <<  "has been treated for "<< i << "day" <<endl;
          cout << medicine[j] << "was given in " << i << " day " << endl;
        }
        else if ( j == 1)
        {
          cout << "\n\nfirst slot (12PM - 3PM)" << endl;
          cout << ob.symptoms[j] <<  "has been treated for "<< i << "day" <<endl;
          cout << medicine[j] << "was given in " << i << " day " << endl;

        }
        else if ( j == 2 )
        {
          cout << "\n\nfirst slot (3PM - 6PM)" << endl;
          cout << ob.symptoms[j] <<  "has been treated for "<< i << "day" <<endl;
          cout << medicine[j] << "was given in " << i << " day " << endl;
        }
        else if (j == 3)
        {
          cout << "\n\nfirst slot (6PM - 9PM)" << endl;
          cout << ob.symptoms[j] <<  "has been treated for "<< i << "day" <<endl;
          cout << medicine[j] << "was given in " << i << " day " << endl;
        }
        else if (j == 4)
        {
          cout << "\n\nfirst slot (9PM - 12AM)" << endl;
          cout << ob.symptoms[j] <<  "has been treated for "<< i << "day" <<endl;
          cout << medicine[j] << "was given in " << i << " day " << endl;
        }
      }
      if(i<ob.noofsymptoms)
      {
        if(ob.symptoms[i]=="shortness of breath")
        flag =1;
      }
      
      
    }
    
      if(flag==1)
      cout << "\nPut Patient on Ventilator";
    system("PAUSE");
    open.close();
  }
    
       
};

class Influenza : public Wards
{
  public:
  void treatment(Diagnostic &ob)
  {
    ifstream open ("medicine.txt" , ios::in);
	  string str , medicine[ob.noofsymptoms];

    int count = 0 , i= 0 ;
	  size_t found;
	  do
	  {
      fflush(stdin);
		  getline(open , str);
		  found = str.find(ob.symptoms[i]); 
      if (found != string::npos) 
      {
    	  str.erase(found, (ob.symptoms[i].length()+1));
		    medicine[i] = str;
		    open.seekg(0,ios_base::beg);
		    i++;
		    count++;
	    }
		
	  } while (count < ob.noofsymptoms);
    static int fatdi; // high fever, cough
    static int headshort;  // bodypain , shortness of breath
    static int sore; // diarrhea
    int n;
    
    

    for(int i=1;i<=6;i++)  //days
    {
      for (int j = 0 ; j < ob.noofsymptoms ; j++)
      {
        if (j == 0)
        {
          cout << "\n\nfirst slot (9AM - 12AM)" << endl;
          cout << ob.symptoms[j] <<  "has been treated for "<< i << "day" <<endl;
          cout << medicine[j] << "was given in " << i << " day " << endl;
        }
        else if ( j == 1)
        {
          cout << "\n\nfirst slot (12PM - 3PM)" << endl;
          cout << ob.symptoms[j] <<  "has been treated for "<< i << "day" <<endl;
          cout << medicine[j] << "was given in " << i << " day " << endl;

        }
        else if ( j == 2 )
        {
          cout << "\n\nfirst slot (3PM - 6PM)" << endl;
          cout << ob.symptoms[j] <<  "has been treated for "<< i << "day" <<endl;
          cout << medicine[j] << "was given in " << i << " day " << endl;
        }
        else if (j == 3)
        {
          cout << "\n\nfirst slot (6PM - 9PM)" << endl;
          cout << ob.symptoms[j] <<  "has been treated for "<< i << "day" <<endl;
          cout << medicine[j] << "was given in " << i << " day " << endl;
        }
        else if (j == 4)
        {
          cout << "\n\nfirst slot (9PM - 12AM)" << endl;
          cout << ob.symptoms[j] <<  "has been treated for "<< i << "day" <<endl;
          cout << medicine[j] << "was given in " << i << " day " << endl;
        }
      }
      
      
    }
    system("PAUSE");
    open.close();
  }
    
  
 
};   

class Sars : public Wards
{
 
  public:
 void treatment(Diagnostic &ob)
  {
    ifstream open ("medicine.txt" , ios::in);
	  string str , medicine[ob.noofsymptoms];

    int count = 0 , i= 0 ;
	  size_t found;
	  do
	  {
      fflush(stdin);
		  getline(open , str);
		  found = str.find(ob.symptoms[i]); 
      if (found != string::npos) 
      {
    	  str.erase(found, (ob.symptoms[i].length()+1));
		    medicine[i] = str;
		    open.seekg(0,ios_base::beg);
		    i++;
		    count++;
	    }
		
	  } while (count < ob.noofsymptoms);
    static int fatdi; // high fever, cough
    static int headshort;  // bodypain , shortness of breath
    static int sore; // diarrhea
    int n;
    int flag = 0;
    

    for(int i=1;i<=6;i++)  //days
    {
      for (int j = 0 ; j < ob.noofsymptoms ; j++)
      {
        if (j == 0)
        {
          cout << "\n\nfirst slot (9AM - 12AM)" << endl;
          cout << ob.symptoms[j] <<  "has been treated for "<< i << "day" <<endl;
          cout << medicine[j] << "was given in " << i << " day " << endl;
        }
        else if ( j == 1)
        {
          cout << "\n\nfirst slot (12PM - 3PM)" << endl;
          cout << ob.symptoms[j] <<  "has been treated for "<< i << "day" <<endl;
          cout << medicine[j] << "was given in " << i << " day " << endl;

        }
        else if ( j == 2 )
        {
          cout << "\n\nfirst slot (3PM - 6PM)" << endl;
          cout << ob.symptoms[j] <<  "has been treated for "<< i << "day" <<endl;
          cout << medicine[j] << "was given in " << i << " day " << endl;
        }
        else if (j == 3)
        {
          cout << "\n\nfirst slot (6PM - 9PM)" << endl;
          cout << ob.symptoms[j] <<  "has been treated for "<< i << "day" <<endl;
          cout << medicine[j] << "was given in " << i << " day " << endl;
        }
        else if (j == 4)
        {
          cout << "\n\nfirst slot (9PM - 12AM)" << endl;
          cout << ob.symptoms[j] <<  "has been treated for "<< i << "day" <<endl;
          cout << medicine[j] << "was given in " << i << " day " << endl;
        }
      }
      if(i < ob.noofsymptoms)
      {
        if(ob.symptoms[i] == "shortness of breath")
        flag = 1;
      }
      
      if(flag==1)
      cout << "\nPut Patient on Ventilator";
      
    }
    system("PAUSE");
    open.close();
  }
    
  

};

class Malaria : public Wards
{
  public:
  void treatment(Diagnostic &ob)
  {
    ifstream open ("medicine.txt" , ios::in);
	  string str , medicine[ob.noofsymptoms];

    int count = 0 , i= 0 ;
	  size_t found;
	  do
	  {
      fflush(stdin);
		  getline(open , str);
		  found = str.find(ob.symptoms[i]); 
      if (found != string::npos) 
      {
    	  str.erase(found, (ob.symptoms[i].length()+1));
		    medicine[i] = str;
		    open.seekg(0,ios_base::beg);
		    i++;
		    count++;
	    }
		
	  } while (count < ob.noofsymptoms);
    static int fatdi; // high fever, cough
    static int headshort;  // bodypain , shortness of breath
    static int sore; // diarrhea
    int n;
    
    

    for(int i=1;i<=6;i++)  //days
    {
      for (int j = 0 ; j < ob.noofsymptoms ; j++)
      {
        if (j == 0)
        {
          cout << "\n\nfirst slot (9AM - 12AM)" << endl;
          cout << ob.symptoms[j] <<  "has been treated for "<< i << "day" <<endl;
          cout << medicine[j] << "was given in " << i << " day " << endl;
        }
        else if ( j == 1)
        {
          cout << "\n\nfirst slot (12PM - 3PM)" << endl;
          cout << ob.symptoms[j] <<  "has been treated for "<< i << "day" <<endl;
          cout << medicine[j] << "was given in " << i << " day " << endl;

        }
        else if ( j == 2 )
        {
          cout << "\n\nfirst slot (3PM - 6PM)" << endl;
          cout << ob.symptoms[j] <<  "has been treated for "<< i << "day" <<endl;
          cout << medicine[j] << "was given in " << i << " day " << endl;
        }
        else if (j == 3)
        {
          cout << "\n\nfirst slot (6PM - 9PM)" << endl;
          cout << ob.symptoms[j] <<  "has been treated for "<< i << "day" <<endl;
          cout << medicine[j] << "was given in " << i << " day " << endl;
        }
        else if (j == 4)
        {
          cout << "\n\nfirst slot (9PM - 12AM)" << endl;
          cout << ob.symptoms[j] <<  "has been treated for "<< i << "day" <<endl;
          cout << medicine[j] << "was given in " << i << " day " << endl;
        }
      }
      
      
    }
    system("PAUSE");
    open.close();
  }
    
    
  

};

class Financedepartment : public Administration
{
  //price in PKR
  //per day charges
float CovidWard = 30000;
float SarsWard = 40000; 
float MalariaWard = 45000;
float InfluenzaWard = 15000;
float wardbill;
float medicinebill = 0.0;
float doctorbill = 0.0;
double totalbill = 0.0;    
double discountedbill = 0.0;   

public :

Financedepartment()
{

}
void generalWard(Diagnostic &ob)
{
string dis = ob.getDisease();
ofstream open("PatReport.txt",ios::app);
 if(dis == "Covid19")
 {
wardbill = CovidWard / 3;
wardbill = wardbill * 15;
 cout << "Bill of General ward(Covid19) : " << wardbill<<endl;
 system("PAUSE");

 }
 if(dis == "sars")
 {
wardbill  = SarsWard / 3;
wardbill  = wardbill * 6; 
 cout << "Bill of General ward(Sars) : " << wardbill<<endl;
 system("PAUSE");
 }
 if(dis == "malaria")
 {
 wardbill = MalariaWard /3;
 wardbill = wardbill * 12; //wardbill+doctorbill+medicinebill
cout << "Bill of General Ward(Malaria) : " << wardbill<<endl;
system("PAUSE");
 }
if(dis == "influenza")
{
wardbill = InfluenzaWard / 3;
wardbill = wardbill * 5;
cout << "Bill of General Ward(Influenza) : " << wardbill << endl;
system("PAUSE");
}
open << wardbill;
open.close();
 

}

void semiPrivateward(Diagnostic &ob)
{
   string dis = ob.getDisease();
 ofstream open("PatReport.txt",ios::app);
 if(dis == "Covid19")
 {
 wardbill = CovidWard / 2;
 wardbill = wardbill * 15;
  cout << "Bill of Semi Private Ward(Covid19) : " << wardbill << endl;
  system("PAUSE");
 }
 if(dis == "sars")
 {
 wardbill  = SarsWard / 2;
 wardbill = wardbill * 6;
  cout << "Bill of Semi Private Ward(Sars) : " << wardbill << endl;
  system("PAUSE");
 }
 if(dis == "malaria")
 {
 wardbill = MalariaWard /2;
 wardbill = wardbill * 12;
  cout << "Bill of Semi Private Ward(malaria) : " << wardbill << endl;
  system("PAUSE");
 }
 if(dis == "influenza")
 {
wardbill = InfluenzaWard / 2;
wardbill = wardbill * 5;
 cout << "Bill of Semi Private Ward(Influenza) : " << wardbill << endl;
 system("PAUSE");
 }
 open << wardbill;
open.close();
}
void Privateward(Diagnostic &ob)
{
   string dis = ob.getDisease();
 ofstream open("PatReport.txt",ios::app);
 if(dis == "Covid19")
 {
   wardbill = CovidWard;
   wardbill = wardbill * 15;
   cout << "Bill of Private Ward(Covid19) : " << wardbill << endl;
   system("PAUSE");
   
 }
 if(dis == "sars")
 {
   wardbill = SarsWard;
   wardbill = wardbill * 6;
   cout << "Bill of Private Ward(Sars) : " << wardbill << endl;
   system("PAUSE");
 }
 
 if(dis == "malaria")
 {
   wardbill = MalariaWard;
   wardbill = wardbill * 12;
   cout << "Bill of Private Ward(malaria) : " << wardbill << endl;
   system("PAUSE");
 }
 if(dis == "influenza")
 {
   wardbill = InfluenzaWard;
   wardbill = wardbill * 5;
   cout << "Bill of Private Ward(Influenza) : " << wardbill << endl;
   system("PAUSE");
 }
 open << wardbill;
open.close();
}

void DrBill(string doc, Diagnostic &ob)
{

ifstream open("Doctors.txt",ios::in);
    char number[4];
    int match , cnt, drpriceconvertedintoint=0;
    string line;
    do{
    	cnt = 0;                      
    	getline(open, line); 
    	for(int i = 0 ; i < 8 ; i++)
    	{
    		if(doc[i] == line[i])
    		cnt++;
		}
    	if(cnt == 8)
    	{
    		match = 1;
    		for (int i = 0 ; i < 4 ; i++)
    		{
    			number[i] = line [i+9];
                stringstream obj(number);  //char number[] converted into integer
                obj >> drpriceconvertedintoint;       
			}
		}
		else 
		{
			match = 0;
			line = "\0";
		}
    	
	}while (cnt != 8);

string dis = ob.getDisease();
if(dis == "Covid19")
 
 doctorbill = drpriceconvertedintoint * 15;
 
 if(dis == "sars")
 doctorbill = drpriceconvertedintoint * 6;
  if(dis == "malaria")
 doctorbill = drpriceconvertedintoint * 12;
 
 if(dis == "influenza")
 
doctorbill = drpriceconvertedintoint * 5;

cout << "Dr. BILL : " << doctorbill << endl;
system("PAUSE");

open.close();
}

void MedicineBill(Diagnostic &ob)
{
    string medicine[5];
   // string symptoms[5] = {"diarrhea","fatigue","high fever","vomitting","non urinating"};

    for(int i=0 ; i< 5; i++)
    {
    if (ob.symptoms[i] == "diarrhea")
    {
        medicine[i] = "Imodiom";
        medicinebill = medicinebill + 970.57;
    }
    else if(ob.symptoms[i] == "fatigue")
    {
        medicine[i] = "Modosinil";
        medicinebill = medicinebill + 450.27;
    }
    else if(ob.symptoms[i] == "high fever")
    {
        medicine[i] = "Acetaminophen";
       medicinebill = medicinebill + 200.67;
    }
    else if(ob.symptoms[i] == "shortness of breath")
    {
        medicine[i] = "Aerosol";
        medicinebill = medicinebill + 158.67;
    }
    else if(ob.symptoms[i] == "vomitting")
    {
        medicine[i] = "Bismuth";
        medicinebill = medicinebill + 250.67;
    }
    else if(ob.symptoms[i] == "headache")
    {
        medicine[i] = "Paracetamol";
        medicinebill = medicinebill + 317.27;
    }
    else if(ob.symptoms[i] == "high fever")
    {
        medicine[i] = "Acetaminophen";
        medicinebill = medicinebill + 850.50;
    }
    else if(ob.symptoms[i] == "cough")
    {
        medicine[i] = "Dextromethorphan";
        medicinebill = medicinebill + 827.27;
    }
    else if(ob.symptoms[i] == "cold ")
    {
        medicine[i] = "Motirn";
        medicinebill = medicinebill + 691.29;
    }
    else if(ob.symptoms[i] == "body ache")
    {
        medicine[i] = "Aerosol";
        medicinebill = medicinebill + 984.86;
    }
    else if(ob.symptoms[i] == "bloody stool")
    {
        medicine[i] = "Kaopectate";
        medicinebill = medicinebill + 535.3;
    }
    else if(ob.symptoms[i] == "dizziness")
    {
        medicine[i] = "Dramamine";
        medicinebill = medicinebill + 811.21;
    }
    else if(ob.symptoms[i] == "non urinating")
    {
        medicine[i] = "Trospium";
        medicinebill = medicinebill + 786.86;
    }
    else if(ob.symptoms[i] == "red eyes")
    {
        medicine[i] = "Namphazoline";
        medicinebill = medicinebill + 950.6;
    }
    else if(ob.symptoms[i] == "profuse sweating")
    {
        medicine[i] = "Drysol";
        medicinebill = medicinebill + 311.21;
    }
    else if(ob.symptoms[i] == "convulsions")
    {
        medicine[i] = "Epival";
        medicinebill = medicinebill + 900.56;
    }
    
    }
    cout<< "Your Medicine Bill : " <<  medicinebill << endl;

    system("PAUSE");
}

double totalhospbill()
{
  totalbill=wardbill+doctorbill+medicinebill;
  return totalbill;
}

void insurance()
{
    cout<<"\nThe associated insurance partner will be displayed to you\n"<<"select any one"<<endl;
    cout<<"\n1-Jubilee Life insurance\n";
    cout<<"\n2-State life insurance\n";
    cout<<"\n3-Asia Care Health and life insurance\n";
    int sel;
    cin >> sel;
    if(sel==1)
    {
      
  totalbill=totalbill-(0.25*(totalbill)); 
    }
    else if(sel==2)
    {
      totalbill=totalbill-(0.5*(totalbill));
    }
    else if(sel==3)
    {
        totalbill=totalbill-(0.75*(totalbill));
    }

    cout << "Your Total Bill Is : " << totalbill << endl;
}

};

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