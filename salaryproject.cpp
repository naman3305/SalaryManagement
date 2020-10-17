#include<fstream>
#include<iostream>
#include<string.h>
using namespace std;

class employee
{
public:
    float salary;
    int employeeid;
    char name[50];
    char lastname[50];
    char post[50];
    void accept()
    {
        cout<<endl<<"\t\t\t\tEnter Employee First Name";
        cin>>name;
        cout<<endl<<"\t\t\t\tEnter Employee Last Name";
        cin>>lastname;
        cout<<endl<<"\t\t\t\tEnter Employee ID";
        cin>>employeeid;
        cout<<endl<<"\t\t\t\tEnter Employee Post";
        cin>>post;
        cout<<endl<<"\t\t\t\tEnter Salary of Employee";
        cin>>salary;
    }
    void display()
    {
        cout<<endl<<"\t\t\t\tEmployee First Name:"<<name;
        cout<<endl<<"\t\t\t\tEmployee Last Name:"<<lastname;
        cout<<endl<<"\t\t\t\tEmployee ID:"<<employeeid;
        cout<<endl<<"\t\t\t\tEmployee Post:"<<post;
        cout<<endl<<"\t\t\t\tEmployee Salary:"<<salary;
    }
};
employee obj; //global object

class salary
{
private:
    float salary_given;
public:
    int employeeid;
    char year[50];
    char month[50];
    void accept()
    {
        cout<<endl<<"\t\t\t\tEnter ID of Employee";
        cin>>employeeid;

        fstream rd;
        rd.open("F:\\salaryproject\\employeedata.txt",ios::in);
        rd.seekg(0,ios::end);
        int n=rd.tellg();
        n=n/sizeof(obj);
        rd.seekg(0,ios::beg);

        for(int i=1;i<=n;i++)
        {
            rd.read((char*)&obj,sizeof(obj));

            if (employeeid==obj.employeeid)
            {
                obj.display();
            }
        }
        cout<<endl<<"\t\t\t\tEmployee salary to be dispensed";
        cin>>salary_given;
        cout<<endl<<"\t\t\t\tEnter Month";
        cin>>month;
        cout<<endl<<"\t\t\t\tEnter Year";
        cin>>year;
    }
    int digit(int n)
    {
        int count_=0;
        while(n!=0)
        {
            n=n/10;
            count_++;
        }
        return count_;
  }
    void display()
    {
        cout<<endl<<employeeid<<"           ";
        cout<<salary_given;
         int p=digit(salary_given);
        for(int i=1;i<=(11-p);i++)
        {
            cout<<" ";
        }
        cout<<"\t"<<month<<"\t"<<year;
    }
};
salary salobj;
void addemployee()
{
    obj.accept();

    fstream wr;
    wr.open("F:\\salaryproject\\employeedata.txt",ios::app);
    wr.write((char*)&obj,sizeof(obj));
    cout<<endl<<"\t\t\t\t* * * * Data Saved * * * * *";
    cout<<endl<<"\t\t\t* * * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * ";
}
void showallemployee()
{
    fstream rd;
    rd.open("F:\\salaryproject\\employeedata.txt",ios::in);
    rd.seekg(0,ios::end);
    int n=rd.tellg();
    n=n/sizeof(obj);
    rd.seekg(0,ios::beg);
    for(int i=1;i<=n;i++)
    {
        rd.read((char*)&obj,sizeof(obj));
        obj.display();
        cout<<endl<<"\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * "<<endl;
    }
}
void searchbyemployeeid()
{

    fstream rd;
    rd.open("F:\\salaryproject\\employeedata.txt",ios::in);
    int sr;
    cout<<endl<<"\t\t\t\tEnter Employee ID to be Searched";
    cin>>sr;
    rd.seekg(0,ios::end);
    int n;
    n=rd.tellg();
    n=n/sizeof(obj);
    rd.seekg(0,ios::beg);
    for(int i=1;i<=n;i++)
    {
        rd.read((char*)&obj,sizeof(obj));
        if(obj.employeeid==sr)
        {
            obj.display();
            cout<<endl<<"\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
        }
    }
}


void searchbyname()
{
    int x;
    fstream rd;
    rd.open("F:\\salaryproject\\employeedata.txt",ios::in);
    char name[50];
    cout<<endl<<"\t\t\t\tEnter Name of Employee";
    cin>>name;
    rd.seekg(0,ios::end);
    int n;
    n=rd.tellg();
    n=n/sizeof(obj);
    rd.seekg(0,ios::beg);
    for(int j=1;j<=n;j++)
    {
        rd.read((char*)&obj,sizeof(obj));
        x=stricmp(name,obj.name);
        if(x==0)
        {
            obj.display();
            cout<<endl<<"\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
        }
    }
}
void searchbypost()
{
    int x;
    fstream rd;
    rd.open("F:\\salaryproject\\employeedata.txt",ios::in);
    char p[50];
    cout<<endl<<"\t\t\t\tEnter Post of Employee";
    cin>>p;
    rd.seekg(0,ios::end);
    int n=rd.tellg();
    n=n/sizeof(obj);
    rd.seekg(0,ios::beg);
    for(int j=1;j<=n;j++)
    {
        rd.read((char*)&obj,sizeof(obj));
        x=stricmp(p,obj.post);
        if(x==0)
        {
            obj.display();
            cout<<endl<<"\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * "<<endl;
        }
    }
}
void removeemployee()
{
    fstream rd,wr;
    rd.open("F:\\salaryproject\\employeedata.txt",ios::in);
    wr.open("F:\\salaryproject\\temp.txt",ios::out);
    int sr;
    cout<<endl<<"\t\t\t\tEnter Employee ID to be Removed";
    cin>>sr;
    rd.seekg(0,ios::end);
    int n;
    n=rd.tellg();
    n=n/sizeof(obj);
    rd.seekg(0,ios::beg);
    for(int i=1;i<=n;i++)
    {
        rd.read((char*)&obj,sizeof(obj));
        if(obj.employeeid==sr)
        {
            cout<<endl<<"\t\t\t\t* * * * EMPLOYEE REMOVED * * * *";
        }
        else
        {
            wr.write((char*)&obj,sizeof(obj));
        }
    }
    rd.close();
    wr.close();
    remove("F:\\salaryproject\\employeedata.txt");
    rename("F:\\salaryproject\\temp.txt","F:\\salaryproject\\employeedata.txt");
}
void updateemployee()
{
    fstream wr,rd;
    rd.open("F:\\salaryproject\\employeedata.txt",ios::in);
    wr.open("F:\\salaryproject\\temp.txt",ios::out);
    int sr;
    cout<<endl<<"\t\t\t\tEnter Employee ID to Update Employee";
    cin>>sr;
    rd.seekg(0,ios::end);
    int n=rd.tellg();
    n=n/sizeof(obj);
    rd.seekg(0,ios::beg);
    for(int i=1;i<=n;i++)
    {
        rd.read((char*)&obj,sizeof(obj));
        if(obj.employeeid==sr)
        {
            obj.accept();
            wr.write((char*)&obj,sizeof(obj));
        }
        else
        {
            wr.write((char*)&obj,sizeof(obj));
        }
    }
    rd.close();
    wr.close();
    remove("F:\\salaryproject\\employeedata.txt");
    rename("F:\\salaryproject\\temp.txt","F:\\salaryproject\\employeedata.txt");
    cout<<endl<<"\t\t\t\t* * * * * DATA UPDATED * * * * *";
}
void dispensesalary()
{
    salobj.accept();
    fstream wr;
    wr.open("F:\\salaryproject\\salary.txt",ios::app);
    wr.write((char*)&salobj,sizeof(salobj));
    cout<<endl<<"\t\t\t\t* * * * * SALARY RECORDED * * * * *";
}
void searchsalary()
{
    fstream rd;
    rd.open("F:\\salaryproject\\salary.txt",ios::in);
    char m[50],y[50];

    cout<<endl<<"\t\t\t\tEnter Year";
    cin>>y;
    cout<<endl<<"\t\t\t\tEnter Month";
    cin>>m;
    cout<<endl<<"Employee ID\tGiven Salary\tMonth\tyear";
    cout<<endl<<"* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ";
    rd.seekg(0,ios::end);
    int n=rd.tellg();
    n=n/sizeof(salobj);
    rd.seekg(0,ios::beg);


    for(int i=1;i<=n;i++)
    {
        rd.read((char*)&salobj,sizeof(salobj));

        if(strcmp(salobj.month,m)==0 && strcmp(salobj.year,y)==0)
        {
            salobj.display();
        }
        cout<<endl<<"* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
    }
}
main()
{
    int e=0;
    while(e!=1)
    {


       cout<<endl<<"\t\t\t* * * * * * * ENET YOUR CHOICE * * * * * * * * * * *";
       cout<<endl<<"\t\t\t*                Enter 1 to ADD EMPLOYEE           *";
       cout<<endl<<"\t\t\t*             Enter 2 to SHOW ALL EMPLOYEE         *";
       cout<<endl<<"\t\t\t*            Enter 3 to SEACH EMPLOYEE BY ID       *";
       cout<<endl<<"\t\t\t*           Enter 4 to SEARCH EMPLOYEE BY NAME     *";
       cout<<endl<<"\t\t\t*         Enter 5 to SEARCH EMPLOYEE BY POST       *";
       cout<<endl<<"\t\t\t*           Enter 6 to REMOVE EMPLOYEE             *";
       cout<<endl<<"\t\t\t*         Enter 7 to UPDATE EMPLOYEE STATUS        *";
       cout<<endl<<"\t\t\t*              Enter 8 to DISPENCE SALARY          *";
       cout<<endl<<"\t\t\t*              Enter 9 to SEARCH SALARY            *";
       cout<<endl<<"\t\t\t*                  Enter 10 to EXIT                *";
       cout<<endl<<"\t\t\t* * * * * * * *  * * * * * * * * * * * * * * * * * *";

       int choice;
       cin>>choice;
       switch(choice)
       {
       case 1:
        {
            addemployee();
            break;
        }
       case 2:
        {
            showallemployee();
            break;
        }
       case 3:
        {
            searchbyemployeeid();
            break;
        }
       case 4:
        {
            searchbyname();
            break;
        }
       case 5:
        {
            searchbypost();
            break;
        }
       case 6:
        {
            removeemployee();
            break;
        }
       case 7:
        {
            updateemployee();
            break;
        }
       case 8:
        {
            dispensesalary();
            break;
        }
       case 9:
        {
            searchsalary();
            break;
        }
       case 10:
        {
            e=1;
            break;
        }
       }
    }
}

