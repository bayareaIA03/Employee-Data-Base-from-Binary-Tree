#include <iostream>
#include <string>
#include "EmployeeDB.h"

using namespace std;

int main() {
	string name;
	string badgeIDNumber;
	string hiringDate;

	int option;
	char choice;

	Employee e;
	Employee temp;
	EmployeeDB db;

	cout<<"Welcome to the Employee Data Base!"<<endl;
	cout<<"This is a program that will insert employees into a data base"<<endl;

	do{
		cout<<"\n#1 Please insert employee's name, badge number and hiring date."<<endl;
		cout<<"#2 delete an employee for data base"<<endl;
		cout<<"#3 display the data base"<<endl;
		cin>>option;

		switch(option){
			case 1:

				//std::string name = "Employee" + to_string(i);
				cout<<"what is the name of the employee."<<endl;
				cin>>name;
				e.setName(name);
				std::cout << "Inserting: " << e.getName() << std::endl;

				cout<<"\nwhat is the badge ID number of employee. "<<e.getName()<<endl;
				cin>>badgeIDNumber;
				e.setNumber(badgeIDNumber);
				std::cout << "Inserting: " << e.getNumber() << std::endl;

				cout<<"\nwhat is the hiring date of employee. "<<e.getName()<<endl;
				cin>>hiringDate;
				e.setHireDate(hiringDate);
				std::cout << "Inserting: " << e.getHireDate() << std::endl;
				db.insertEmployee(e);

				break;

			case 2:
				cout<<"What's the name of the employee that you would like to delete."<<endl;
				cin>>name;

				temp = db.searchEmployee(name);

				std::cout << "Deleting: "<<name << std::endl;
				db.deleteEmployee(temp);
				break;

			case 3:
				std::cout << "\nDisplay Records" << std::endl;
				db.displayRecords();
				break;

		}

	std::cout<<"Do you want to run this program again ? Y/N ";
    std::cin>>choice;
}
	while(choice=='Y' || choice=='y');

	return 0;
}

