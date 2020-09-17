/*
Name: Lucas Allen, 5004607031, CS135 1002, Assignment #8.
Description: This program takes input from a file and uses it to calculate max age, minimum age, average age, max wage, minimum wage, and average wage. These values are then output to a user selected file.
Input: The user inputs which file they would like to read in, whether or not to read in all records, and if not, how many records to read in. Next, the calculated data is output to a chosen file. 
Output: Outputs max age, minimum age, average age, max wage, minimum wage, and average wage.
Algorithm:
1.) prompt user for input file name.
2.)prompt user for output file.  
3.)read in file name.
4.)check that file name is open
5.)loop is open until ==true
6.)ask user if they want all records to be processed.
7.)if no, prompt user for the number of records to process
8.)show user number of records read. 
9.)take relevent data out of file. 
10.) Find minimums and maximums. 
11.)show the user the employee ID, First Name, Last Name, wage, %Ave wage, %Ave age, and age. 
12.)show the max wage, max age, min wage, min age, Ave wage, Ave age. 
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std; 

int main()
{	
	const int TODAY=2019;
	//stats
	int employee_id=0;
	string firstName=" ";
	string lastName=" ";
	double wage=0;
	int birthyear=0;
	double wageAve=0;
	double ageAve=0;
	double minWage=0.0;
	double maxWage=0;
	int maxAge=0;
	int minAge=0;
	int age=0;
	double wageTotal=0;
	double ageTotal=0;
	double currentWage=0;
	double currentAge=0;
	double Wpercent=0; 
	double Apercent; 
		

	//file
	string fileName=" ";
	string outFile=" ";
	char answer=' ';
	int fileNumber=0;
	//format
	string star (70,'*');
	string gthan(38, '>');
	string lthan(38, '<');
	string dashes(70, '-');
	int i=0;
	int j=0;

	
	cout<<"Enter file name to process: ";
	cin>>fileName;
	cout<<"Enter output file name: ";
	cin>>outFile;
	ifstream iFile;
	iFile.open(fileName);
	if(iFile.is_open()==false){
		cout<<"the file "<<fileName<<" did not open properly."<<endl;
	}else{
		cout<<"Would you like to process all the records in the file? (y/n): ";
		cin>>answer;
		if(answer!='y' || answer!='Y'){
			cout<<"Enter the number of records to process: ";
			cin>>fileNumber;
		}
	if(iFile.eof()==true){
	cout<<"Hit the end of file."<<endl;
	return 0;
	}
		cout<<"Max record count reached "<<fileNumber<<endl;
		
	}
	cout<<endl;
	iFile.close();
	ofstream aFile;
	aFile.open(outFile);
	iFile.open(fileName);
	aFile<<"Employee ID"<<setw(14)<<"First Name"<<setw(14)<<"Last Name"<<setw(10)<<"Wage"<<setw(10)<<" %"" Ave"<<setw(7)<<"Age"<<setw(10)<<"%"" Ave "<<endl;
	for(i=0;i<fileNumber;++i){
	iFile>>employee_id>>firstName>>lastName>>wage>>birthyear;
	Apercent=(age/ageAve)*100;
	if(currentWage==0){
		minWage=wage;
	}
	else{
		if(wage<minWage)
			minWage=wage;
	}
	currentWage++;

	maxWage = (wage > maxWage)? wage: maxWage;
	maxAge = (age > maxAge)? age: maxAge;

	age=TODAY-birthyear;
	if(currentAge==0){
		minAge=age;	
	}
	else{
		if(age<minAge)
			minAge=age;
	}
	
	currentAge++;
	ageTotal+=age;
	ageAve=ageTotal/fileNumber;
	wageTotal+=wage;
	wageAve=wageTotal/fileNumber;
	if(currentAge<fileNumber){
		Apercent=0;
	}else{
		Apercent=age/ageTotal*1000;
	}
	if(currentWage<fileNumber){
		Wpercent=0;
	}else{
		Wpercent=wage/wageTotal*1000;
	}
	aFile<<setw(7)<<employee_id<<setw(14)<<firstName<<setw(16)<<lastName<<setw(12)<<fixed<<setprecision(2)<<wage<<setw(9)<<fixed<<setprecision(0)<<ceil(Wpercent)<<setw(8)<<age<<setw(10)<<fixed<<setprecision(0)<<ceil(Apercent)<<endl;

	}
	aFile<<endl;
	aFile<<"Wage Statistics "<<endl;
	aFile<<dashes<<endl;
	aFile<<"Max wage: "<<fixed<<setprecision(2)<<maxWage<<"    Min wage: "<<fixed<<setprecision(2)<<minWage<<"   Ave. wage: "<<fixed<<setprecision(2)<<wageAve<<endl;
	aFile<<endl;
	aFile<<"Age Statistics"<<endl;
	aFile<<dashes<<endl;
	aFile<<"Max age: "<<maxAge<<"        Min  age: "<<fixed<<minAge<<"      Ave. age:  "<<fixed<<setprecision(2)<<ageAve<<endl;


	cout<<"Program complete"<<endl;
	cout<<gthan<<lthan<<endl;
	return 0; 
}