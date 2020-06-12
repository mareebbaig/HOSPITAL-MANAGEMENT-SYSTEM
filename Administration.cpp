
#include "Administration.h"
void Administration::Doctors(Diagnostic &ad)
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
  string Administration::showdoctor()
  {
      return dr;
  }