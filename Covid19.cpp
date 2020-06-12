#include "Covid19.h"



 
  void Covid19::treatment(Diagnostic &ob)
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
          cout << "\n\nslot (9AM - 12AM)" << endl;
          cout << ob.symptoms[j] <<  "has been treated for "<< i << "day" <<endl;
          cout << medicine[j] << "was given in " << i << " day " << endl;
        }
        else if ( j == 1)
        {
          cout << "\n\nslot (12PM - 3PM)" << endl;
          cout << ob.symptoms[j] <<  "has been treated for "<< i << "day" <<endl;
          cout << medicine[j] << "was given in " << i << " day " << endl;

        }
        else if ( j == 2 )
        {
          cout << "\n\nslot (3PM - 6PM)" << endl;
          cout << ob.symptoms[j] <<  "has been treated for "<< i << "day" <<endl;
          cout << medicine[j] << "was given in " << i << " day " << endl;
        }
        else if (j == 3)
        {
          cout << "\n\nslot (6PM - 9PM)" << endl;
          cout << ob.symptoms[j] <<  "has been treated for "<< i << "day" <<endl;
          cout << medicine[j] << "was given in " << i << " day " << endl;
        }
        else if (j == 4)
        {
          cout << "\n\nslot (9PM - 12AM)" << endl;
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
    
       
