#include "Financedepartment.h"

Financedepartment::Financedepartment()
{

}
void Financedepartment::generalWard(Diagnostic &ob)
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

void Financedepartment::semiPrivateward(Diagnostic &ob)
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
void Financedepartment::Privateward(Diagnostic &ob)
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

void Financedepartment::DrBill(string doc, Diagnostic &ob)
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

void Financedepartment::MedicineBill(Diagnostic &ob)
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

double Financedepartment::totalhospbill()
{
  totalbill=wardbill+doctorbill+medicinebill;
  return totalbill;
}

void Financedepartment::insurance()
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

