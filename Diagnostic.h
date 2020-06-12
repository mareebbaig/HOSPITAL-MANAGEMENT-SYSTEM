
#ifndef CLASS_DIAGNOSTIC
#define CLASS_DIAGNOSTIC
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
    Diagnostic() ;
  Diagnostic(string name,int age,string DOB,char gender,string *symptoms, int n) ;

void symptomsMatch();





string getDisease();

  friend class ReportGeneration;
  friend class Covid19;
  friend class Sars;
  friend class Malaria;
  friend class Influenza;
  friend class Financedepartment;
  
  void set_doctor(string doctor);

};

#endif