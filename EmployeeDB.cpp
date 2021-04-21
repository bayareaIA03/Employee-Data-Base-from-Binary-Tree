#include "EmployeeDB.h"
#include <iostream>
using namespace std;
	EmployeeDB::EmployeeDB(){
		//db.EmpBinaryTree();
	}
	void EmployeeDB::insertEmployee(Employee emp){
		db.insertEmployee(emp);
	}
	bool EmployeeDB::deleteEmployee(Employee emp){
		// find out if the deleted thing is in the tree by using the searchEmployee. if find then call the delete and itll be true.
		if(db.searchEmployee(emp)){
			db.remove(emp);
			return true;
		}
		else{
			cout<<"The name of this employee cannot be found"<<endl;
		}
		return false;
	}
	Employee EmployeeDB::searchEmployee(string name){
		Employee ee;
		ee = db.getEmployee(name);
		return ee;
	}
	void EmployeeDB::displayRecords(){
		db.displayInOrder();
	}


