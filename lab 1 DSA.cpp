/*
Name: Mohamad Nadzmi Bin Nasron
ID: 22011213
gmail: mohammad_22011213@utp.edu.my
*/

#include <iostream>
using namespace std;

struct Student{
	int id;
	string name;
	string contact;
	string email;
};

int main()
{
	Student student[5];
	
	for (int i=0;i<5;i++){
		cout << "Enter students #" << i+1 << " id: ";
		cin >> student[i].id;
		
		cout << "Enter students #" << i+1 << " name: ";
		cin >> student[i].name;
		
		cout << "Enter students #" << i+1 << " contact: ";
		cin >> student[i].contact;
		
		cout << "Enter students #" << i+1 << " email: ";
		cin >> student[i].email;
	}
	
	for (int i = 0; i<5; i++){
	    cout << "***************************" << endl;
	    cout << "Student #" << i+1 << endl;
	    cout << "ID: " << student[i].id << endl;
	    cout << "Name: " << student[i].name << endl;
	    cout << "Contact: " << student[i].contact << endl;
	    cout << "Gmail: " << student[i].email << endl;
	    cout << "***************************" <<endl; 
	}

return 0;	
}

