
#include "Diagnostic.h"
#pragma once
class ReportGeneration : public Diagnostic
{     
  public: 
  ReportGeneration() ;
  ReportGeneration(Diagnostic obj);
  void patientReport();
  void showData();

};