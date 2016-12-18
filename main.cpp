#include <iostream>
#include<fstream>
#include <string.h>
using namespace std;

//Admin
class admin{
private:

public:
    string id;
	string pass;
    //find private or protected
    void AddLibrarian(){

        cout<<"\nEnter The ID ";
        cin>>id;
        cout<<"\n\nEnter The Password of Librarian : ";
        cin>>pass;
        //Enter into data file
        cout<<"\t\t\n\nLibrarian Record Created Successfully...";
    }

    void RemoveLibrarian(){
        cout<<"Enter Librarian ID ";
        cin>>id;
        //Search in database and delete record
    }
    void viewSingleLibrarian(){
        cout<<"Enter Librarian ID  : ";
        cin>>id;
        //find and display
    }
    void viewAllLibrarian(){
        //open file display every thing

    }
    void AddUser(){

        cout<<"\nEnter The ID Number ";
        cin>>id;
        cout<<"\n\nEnter The Paaword of The Student: ";
        cin>>pass;
        //Enter into data file
        cout<<"\t\t\n\nStudent Record Created Successfully...";

    }

    void RemoveUser(){
        cout<<"Enter user ID ";
        cin>>id;
        //Search in database and delete record
    }

    void viewSingleUser(){
        cout<<"Enter user ID  : ";
        cin>>id;
        //find and display
    }

    void  viewAllUser(){
        //open file display every thing

    }

    void ReserveBook(){
        cout<<"Enter book Code : ";
        cin>>id;
        //search in database
    }

    void IssueBook(){
        cout<<"Enter book code : ";
        cin>>id;
        //file are found then issue else not
    }

    void ReturnBook(){
        cout<<"Enter a code : ";
        cin>>id;
    }
};
//Librarian  class

class librarian : public admin{


};

//User Class

class user{
public:
    void viewBook(){
        //open file display every thing
    }

    void IssuedBook(){
        //open file display every thing
    }

    void fine(){
        //open file display every thing
    }

};

//Book Class
class book{
private:
    string name;
    string author;
    string code;
    int quantity;
public:
    void createBook(){
        cout<<"Enter the book name : ";
        cin>>name;
        cout<<"Enter the author name : ";
        cin>>author;
        cout<<"Enter the code : ";
        cin>>code;
        cout<<"Enter the quantity : ";
        cin>>quantity;
        cout<<"\t\t\n\nBook Created Successfully...";
    }

    void editBook(){
        cout<<"Enter book code to edit : ";
        cin>>code;
        //The function are to edit book
        //Like change name,author,code etc
    }
    void removeBook(){
        cout<<"Enter book code to edit : ";
        cin>>code;
        //That function are use to show total number of books in library
        //The book may be issue or not.
    }

};

class Login{
private:
    string id;
    string password;
public:
    bool login(string i, string p){
        //file handling
        //match give string
        if(){
            return true;
        }
        else{
            cout<<"record not found";
            return false;
        }
    }
};

int main(){
    string id,pass;
    bool granted;

    Login lg;
    cout<<"Welcome LMS";

    int num;
    cout<<"Press 1 to user, 2 librarian, 3 Admin";
    cin>>num;

    cout<<"Enter id : ";cin>>id;
    cout<<"Enter password : ";cin>>pass;

    switch(num){
    case 1:
        //user file
        granted = lg.login(id,pass);
        if(granted){
            system("cls");
            cout<<"press 1.View books List\n 2.Issued book\n3.View Fine\n ";
            user User;
            cin>>num;
            switch(num){

            case 1:

                break;

            case 2:

                break;

            case 3:

                break;
            }
        }
        else{
            cout<<"Wrong Data Enter";
            break;
        }

    case 2:
        granted = lg.login(id,pass);
        if(granted)
            cout<<"Press  1.Add User\n 2.Remove User\n 3.View Single User\n 4.View All User\n 5.Issue Book\n 6.Return Book\n 7.Edit Book";
            cin>>num;

            switch(num){
            case 1:

                break;

            case 2:

                break;

            case 3:

                break;

            case 4:

                break;

            case 5:

                break;

            case 6:

                break;

            case 7:

                break;
            }

        else{
            cout<<"Wrong Data Enter";
            break;
        }

    case 3:
        granted = lg.login(id,pass);
        if(granted){
            cout<<"Press  1.Add Librarian\n 2.Remove Librarian\n 3.Add User\n 4.Remove User\n 5.View Single User\n 5.View All User\n 6.Issue Book\n 7.Return Book\n 8.Edit Book";
            cin>>num;
            switch(num){
            case 1:
                break;

            case 2:
                break;

            case 3:

                break;

            case 4:
                break;

            case 5:
                break;

            case 6:
                break;

            case 7:
                break;

            case 8:
                break;
            }
        }
        else{
            cout<<"Wrong Data Enter";
            break;
        }

    }

    return 0;
}
