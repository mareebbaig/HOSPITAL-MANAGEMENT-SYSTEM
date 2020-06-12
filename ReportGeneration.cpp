#include "ReportGeneration.h"

  ReportGeneration::ReportGeneration() {}
  ReportGeneration::ReportGeneration(Diagnostic obj)
  {
    ofstream open("PatReport.txt", ios::out);
    open.write((char*)&obj, sizeof(obj));
    open << obj.disease;  
    open.close();  
  } 
  void ReportGeneration::patientReport()
  {
    ReportGeneration ob2;
    ifstream in("PatReport.txt", ios::in);
    in.read((char*)&ob2,sizeof(ob2));
    in.close();
    ob2.showData();
  }
  void ReportGeneration::showData()
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

