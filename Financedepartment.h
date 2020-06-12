#include "Administration.h"
#pragma once

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

Financedepartment();
void generalWard(Diagnostic &ob);

void semiPrivateward(Diagnostic &ob);
void Privateward(Diagnostic &ob);

void DrBill(string doc, Diagnostic &ob);
void MedicineBill(Diagnostic &ob);

double totalhospbill();

void insurance();

};