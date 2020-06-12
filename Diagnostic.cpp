
#include "Diagnostic.h"
 Diagnostic::Diagnostic() {}
  Diagnostic::Diagnostic(string name,int age,string DOB,char gender,string *symptoms, int n) 
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

void Diagnostic::symptomsMatch()
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

string Diagnostic::getDisease()
{
  return disease;
}

 
  
  void Diagnostic::set_doctor(string doctor)
  {
    this->doctor = doctor;
  }

  int Diagnostic :: pid = 0;//static variable declaration
  