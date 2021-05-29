/************************************************************************** 
Title: Develop an object oriented program in C++ to create a database of student information system containing 
the following information: Name, Roll number, Class, division, Date of Birth, Blood group, Contact address, 
telephone number, driving license no. etc Construct the database with suitable member functions for initializing 
and destroying the data viz constructor, default constructor, Copy constructor, destructor, static member 
functions, friend class, this pointer, inline code and dynamic memory allocation operators-new and delete. 
**************************************************************************/

#include<iostream> 
#include<string.h> //for handling string eg.strcpy() 
#include<ctime> //current date and time of system 
using namespace std; 
class age; 
class person 
{ 
friend class age; //declared friend class age 
private: 
char *name,*blood,*address; //declared data variable 
 int dob; 
long int insurance,tel,license; 
float height,weight; 
static int count; //static variables 
public: person() //default & dynamic constructor 
{ 
count++; 
cout<<"-----------------default information------------"; 
name=new char[13]; //allocate dynamic memory using new operator Department of Computer Engineering, SVCET, Pune
strcpy(name,"default name"); 
blood=new char[3]; 
strcpy(blood,"A+"); 
address=new char[20]; 
strcpy(address,"Nasik"); 
insurance=12345; 
tel=0240252222532; 
license=1234567; 
height=7.3; 
weight=50; 
dob=1998; 
display(); 
 } 
person(char n[], char b[], int yy, char add[], long int in, long int tn, long int ln, float h, float w) 
 //parameterized constructor 
{ 
 count++; 
int len; 
 len=strlen(n); 
 name=new char[len+1]; 
 strcpy(name,n); 
 len=strlen(b); 
 blood=new char[len+1]; 
 strcpy(blood,b); 
 len=strlen(add); 
 address=new char[len+1]; 
 strcpy(address,add); 
 dob=yy; 
 insurance=in; 
 tel=tn; 
 license=ln; 
 height=h; 
 weight=w; 
 } 
void display(); //display function declaration
 
 person & compare(person *x1) // copy constructer 
{ 
if(x1->height > height) 
{ 
 return *x1; 
} 
else 
{
 return *this; // use thin pointer
 } 
}
 static int displaycount() //static member function 
{ 
 cout<<"\n NUMBER OF ENTRIES ARE:"<<count<<endl; 
 }
 ~person() //destructor having same name like constructor 
 { 
 cout<<"\n destructor called..."; 
 } 
 }; 
//copy constructor 
//uses thin pointer 
~person( ) //destructor having same name like constructor 
 { 
 cout<<"\n destructor called..."; 
 } 
 }; 
 class age //friend class defination 
{ private:int ag,date; 
public: 
 void calculate(person *x) //calculate the age of person 
 { 
 date=x->dob; 
 time_t now=time(0);
 tm *ltm=localtime(&now); 
 ag=(1900+ltm->tm_year)-date; 
 cout<<" AGE:"<<ag<<endl; 
 } }; 
int person::count=0; 
 void person::display() //display function definition 
 { 
 cout<<"\n PERSON NAME:"<<name; 
cout<<"\n BLOOD GROUP:"<<blood; 
cout<<"\n DATE OF BIRTH:"<<dob; 
cout<<"\n CONTACT ADDRESS:"<<address; 
cout<<"\n INSURANCE NUMBER:"<<insurance; 
cout<<"\n TELEPHONE NUMBER:"<<tel; 
cout<<"\n LICENSE NUMBER:"<<license; 
cout<<"\n HEIGHT:"<<height; 
cout<<"\n WEIGHT:"<<weight<<endl; 
 } 
int main() //main function 
{ 
int ch; //variable declaration 
person *p[20],*temp; 
age *a[20]; 
char pname[15],pblood[5],paddress[20]; 
long int pinsurance,ptel,plicense; 
float pheight,pweight; 
int cnt=0,dd; 
do 
{
 cout<<"\n ---------------------------MENU--------------------------"<<endl; 
cout<<"\n 1.DEFAULT CONSTRUCTER "; 
cout<<"\n 2.PARAMETERIZED CONSTRUCTOR"; 
cout<<"\n 3.NUMBER OF ENTRIES"; 
cout<<"\n 4.CALCULATE AGE:"; 
 cout<<"\n 5.TALLER PERSON:"; 
cout<<"\n 6.EXIT"; 
 cout<<"\n ENTER THE CHOICE:"; 
cin>>ch; 
switch(ch) 
{ 
case 1: //DEFAULT CONSTRUCTER INFORMATION 
p[cnt]=new person(); 
a[cnt]=new age();
 cnt=cnt+1; 
break; 
case 2: //PARAMETERIZED CONSTRUCTOR INFORMATION
cout<<"\n ENTER THE PERSON NAME:"; 
cin>>pname; 
cout<<"\n ENTER THE PERSON BLOOD GROUP:"; 
cin>>pblood; 
 cout<<"\n ENTER DATE OF BIRTH:"; 
 cin>>dd; 
cout<<"\n ENTER THE PERSON CONTACT ADDRESS:"; 
cin>>paddress; 
cout<<"\n ENTER THE PERSON INSURANCE NUMBER:"; 
cin>>pinsurance; 
 cout<<"\n ENTER THE PERSON TELEPHONE NUMBER:"; 
 cin>>ptel; 
 cout<<"\n ENTER THE PERSON LICENSE NUMBER:"; 
 cin>>plicense; 
 cout<<"\n ENTER THE PERSON HEIGHT:"; 
 cin>>pheight; 
 cout<<"\n ENTER THE PERSON WEIGHT:"; 
 cin>>pweight; 
p[cnt]=new 
person(pname,pblood,dd,paddress,pinsurance,ptel,plicense,pheight,pweight); 
a[cnt]=new age(); 
cnt=cnt+1; 
break; 
case 3: //NUMBER OF ENTRIES INFORMATION 
person::displaycount(); 
break; 
case 4: //CALCULATE AGE INFORMATION 
for(int i=0;i<cnt;i++) 
{ 
p[i]->display(); 
a[i]->calculate(p[i]); 
} 
break; 
case 5: //TALLER PERSON INFORMATION 
temp = p[0]; 
for(int j=1;j<cnt;j++) 
{ 
temp = &temp->compare(p[j]); 
} 
cout<<"\n ------TALLER PERSON INFORMATON-------"<<endl; 
temp->display(); 
break; 
case 6: 
 return 0; 
} 
 }while(ch!=6); 
}
