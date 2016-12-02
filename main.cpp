#include <iostream>
#include<fstream>
#include <string.h>
using namespace std;

// Admin class

class admin{
private:
    string id;              //Admin User Name or ID
    string password;        //Admin Password
public:
    void setAdmin(string i,string p){
        id=i;
        password=p;
    }
    void addLibrarian(){
        //Make a function to add Librarian
        //Then Librarian login our id

    }
    void removeLibrarian(){
        //That function are use use to remove Librarian
        //In case of librarian are remove
        //Only admin remove librarian

    }
    void showID(){

    }
};

//Librarian  class
class librarian : public admin{
	private:
		int id;
		string password;
	public:
		void login(){
			cout<<"Enter the User Id : "<<endl; cin>>Id;
			cout<<"Enter the Password : "<<endl; cin>>password;
		}
		void AddUser(){
			//this function will be used to add user by getting its informations
		}
		void RemoveUser(){
			//this function will remove the user from the labirary membership
		}
		void ViewUser(){
			//this function will alow the librarian to check the details about user
		}
		void ReserveBook(){
			//this function will reserve the book for a specific user
		}
		void IssueBook(){
			//this function will issue the book to the user
		}
		void ReturnBook(){
			//this function will be used to take back the book from the user
		}
		void EditBook(){
			//this function will used to edit book
		}
};
//Book Class
class book : public librarian{
private:
    string name;
    string author;
    string code;
    int quantity;
public:
    void setBook(string n, string a, string c, int q){
        name=n;
        authore=a;
        code=c;
        quantity=q;
    }
    void issue(){
        //That function are use to this book are issue or not
    }
    void Return(){
        //That function are use to
        //the use return the book or not
    }
    void editBook(){
        //The function are to edit book
        //Like change name,author,code etc
    }
};
int main(){

}
