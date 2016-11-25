#include <iostream>
#include <string.h>
using namespace std;

// Admin class
class admin{
private:
    string id;              //Admin User Name or ID
    string password;        //Admin Password
public:
    admin(string i,string p){
        id=i;                   //Constructor
        password=p;
    }
    void addLibrarian(){

    }
    void removeLibrarian(){

    }
    void showID(){
        cout<<"Enter ID/User name : "<<id<<endl;
        cout<<"Enter password : "<<password<<endl;
    }
};
int main(){
    admin adm

    return 0;
}
