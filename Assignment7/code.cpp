#include <iostream>
using namespace std;

class Employee
{
private:
    int id;
    double salary;

public:
    Employee()
    {
        cout << "Inside Employee()" << endl;
    }
    Employee(int id, double salary)
    {
        cout << "Inside Employee(int,double)" << endl;
    }
    virtual void accept()
    {
        cout << "Enter the empid - ";
        cin >> id;
        cout << "Enter the salary - ";
        cin >> salary;
    }
    virtual void display()
    {
        cout << "Id - " << id << endl;
        cout << "Salary - " << salary << endl;
    }
    virtual ~Employee()
    {
        cout << "~Employee()" << endl;
    }
};

class Manager : virtual public Employee
{
private:
    double bonus;

protected:
    void acceptManager()
    {
        cout << "Enter the bonus - ";
        cin >> bonus;
    }
    void displayManager()
    {
        cout << "Bonus - " << bonus << endl;
    }

public:
    Manager()
    {
        cout << "Inside Manager()" << endl;
    }
    Manager(int id, double salary, double bonus)
    {
        cout << "Inside Manager(int,double,double)" << endl;
    }
    void accept()
    {
        Employee::accept();
        acceptManager();
    }

    void display()
    {
        Employee::display();
        displayManager();
    }
    ~Manager()
    {
        cout << "~Manager()" << endl;
    }
};

class Salesman : virtual public Employee
{
private:
    double commission;

protected:
    void acceptSalesman()
    {
        cout << "Enter the Commission - ";
        cin >> commission;
    }
    void displaySalesman()
    {
        cout << "Commission - " << commission << endl;
    }

public:
    Salesman()
    {
        cout << "Inside Salesman()" << endl;
    }
    Salesman(int id, double salary, double commission)
    {
        cout << "Inside Salesman(int,double,double)" << endl;
    }
    void accept()
    {
        Employee::accept();
        acceptSalesman();
    }
    void display()
    {
        Employee::display();
        displaySalesman();
    }
    ~Salesman()
    {
        cout << "~Salesman()" << endl;
    }
};
class SalesManager : public Manager, public Salesman
{
public:
    SalesManager()
    {
        cout << "Inside Salesmanager()" << endl;
    }
    SalesManager(int id, double salary, double bonus, double commission)
    {
        cout << "Inside SalesManager(int,double,double,double)" << endl;
    }
    ~SalesManager()
    {
        cout << "~Salesmanager()" << endl;
    }
    void accept()
    {
        Employee::accept();
        acceptManager();
        acceptSalesman();
    }
    void display()
    {
        Employee::display();
        displayManager();
        displaySalesman();
    }
};

int main()
{
    // Employee *eptr = new Employee();
    // Employee *eptr = new Manager();
    // Employee *eptr = new Salesman();
    // Employee *eptr = new SalesManager();
    // eptr->accept(); // Late Binding
    // eptr->display();

    // delete eptr;
    // eptr = NULL;
    // return 0;

    int choice;
    int countManger = 0;
    int countSalesman = 0;
    int coutSalesmanger = 0;
    
    int index = 0;
    Employee *arr[10];

    do
    {
        cout << "0. Exit" << endl;
        cout << "1. Accept Employee" << endl;
        cout << "2. Display the count of all employees with respect to designation" << endl;
        cout << "3. Display All Managers" << endl;
        cout << "4. Display All Salesman" << endl;
        cout << "5. Display All SalesManagers" << endl;
        cout << "Enter your choice - ";
        cin >> choice;

        switch(choice)
        {
            case 0:
                cout<<"Thank you..."<<endl;
            break;
            case 1:
                {
                    int choose;
                    cout<<"Enter '1' for Manager"<<endl;
                    cout<<"Enter '2' for Salesman"<<endl;
                    cout<<"Enter '3' for Salesmanager"<<endl;
                    cin>>choose;

                    if(choose == 1)
                    {
                        if(index<10)
                        {
                            arr[index]= new Manager();
                            arr[index]-> accept();
                            index++;
                            countManger++;

                        }
                    }
                    else if(choose == 2)
                    {
                        if(index<10)
                        {
                            arr[index]= new Salesman();
                            arr[index]-> accept();
                            index++;
                            countSalesman++;
                        }
                    }
                    else if(choose == 3)
                    {
                        if(index<10)
                        {
                            arr[index]= new SalesManager();
                            arr[index]-> accept();
                            index++;
                            coutSalesmanger++;
                        }

                    }
                    else
                    { cout<<"wrong choice of designation"<<endl;}
                }
            break;

            case 2:
                cout<<"The count of MANAGERS is "<<countManger<<endl;;
                cout<<"The count of SALESMAN is "<<countSalesman<<endl;
                cout<<"The count of SALESMANAGER is "<<coutSalesmanger<<endl;

            break;

            case 3:
                 for(int i = 0;i<index;i++)
                 {
                    if(typeid(*arr[i])==typeid(Manager))
                    {
                        arr[i]->display();
                    }
                 }
                 break;

            case 4:
                for(int i=0;i<index;i++)
                {
                    if(typeid(*arr[i]) == typeid(Salesman)) 
                    {
                        arr[i]->display();
                    }
                }
                
                break;

            case 5:
               for(int i=0;i<index;i++)
               {
                    if(typeid(*arr[i]) == typeid(SalesManager))
                    {
                        arr[i]->display();
                    }
               }
               break;
        }
    }while(choice!=0);

    for(int i =0;i<index;i++)
    {
        delete arr[i];
        arr[i] = NULL;
    }
    return 0;
}


// int main1()
// {
//     // Employee obj;
//     // Manager obj;
//     // Salesman obj;
//     SalesManager obj;
//     obj.accept();
//     obj.display();
//     return 0;
// }