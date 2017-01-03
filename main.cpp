#include<iostream>
#include<string.h>
#include<iomanip>
#include <stdlib.h>
#include<fstream>
#include<conio.h>

using namespace std;

class admin{
    char ID_number[20];
    char Student_name[20];
    unsigned int mobile_number;
    char stbno[6];
    int token;

public:
    void create_student(){
        cout<<"\nEnter The ID Number ";
        cin>>ID_number;
        cout<<"\n\nEnter The Name of The Student: ";
        cin>>Student_name;
        cout<<"Enter The Mobile Number: ";
        cin>>mobile_number;
        token=0;
        stbno[0]='/0';
        cout<<"\t\t\n\nStudent Record Created Successfully...";
    }
    void show_student(){
        cout<<"\nID Number: "<<ID_number;
        cout<<"\nStudent Name: ";
        puts(Student_name);
        cout<<"\nMobile Number: "<<mobile_number;
        cout<<"\nNo of Book issued: "<<token;

        if(token==1)
            cout<<"\nBook No "<<stbno;
    }
    void modify_student(){
        cout<<"\nID Number: "<<ID_number;
        cout<<"\nModify Student Name: ";
        cin.ignore();
        cin.getline(Student_name,50);

    }
    char* get_ID_number(){
        return ID_number;
    }
    char* retstbno(){
        return stbno;
    }
    int rettoken(){
        return token;
    }
    void addtoken(){
        token=1;
    }
    void resettoken(){
        token=0;
    }
    void getstbno(char t[]){
        strcpy(stbno,t);
    }
    void report(){
        cout<<"\t"<<ID_number<<setw(20)<<Student_name<<setw(15)<<token<<setw(25)<<mobile_number<<endl;
    }
};

class Librarian : public admin{
public:
    show_student();
    issue_book();
    book_return();
};
class student : public admin{

public:
    get_ID_number();
    show_book();
};

class book{
    char book_number[30];
    char book_name[50];
    char author_name[50];
public:
    void create_book(){
        cout<<"\nEnter The Book Number: ";
        cin>>book_number;
        cout<<"\nEnter The Name of The Book: ";
        cin.ignore();
        cin.getline(book_name,50);
        cout<<"\nEnter The Author's Name: ";
        cin.ignore();
        cin.getline(author_name,50);
        cout<<"\t\t\n\nBook Created Successfully...";
    }

    void show_book(){
        cout<<"\nBook Number: "<<book_number;
        cout<<"\nBook Name: "<<book_name;
        cout<<"\nAuthor's Name: "<<author_name;
    }
    void modify_book(){
        cout<<"\nBook number : "<<book_number;
        cout<<"\nModify Book Name : ";
        cin.ignore();
        cin.getline(book_name,50);
        cout<<"\nModify Author's Name: ";
        cin.ignore();
        cin.getline(author_name,50);
    }
    char* getbooknumber(){
        return book_number;
    }
    void report(){
        cout<<"\t"<<book_number<<setw(24)<<book_name<<setw(30)<<author_name<<endl;
    }
};


fstream fp,fp1;
book bk;
admin adm;
student st;

void login(){

}
void write_book(){
    system("cls");
    int more_or_main;
    fp.open("book.dat",ios::out|ios::app);

    do{
        bk.create_book();
        fp.write((char*)&bk,sizeof(book));
        cout<<"\nPress 1 to add more books.";
        cout<<"\nPress 2 to return to main menu.\n";
        cout<<"Enter: ";
        cin>>more_or_main;
    }while(more_or_main == 1);
        fp.close();
}
void write_student(){
    system("cls");
    int more_or_main;
    fp.open("student.dat",ios::out|ios::app);

    do{
        adm.create_student();
        fp.write((char*)&adm,sizeof(admin));
        cout<<"\nPress 1 to add more students.";
        cout<<"\nPress 2 to return to main menu.\n";
        cout<<"Enter: ";
        cin>>more_or_main;
    }while(more_or_main == 1);
        fp.close();
}
void display_a_book(char n[]){
        system("cls");
        cout<<"\nBOOK DETAILS\n";
        int check=0;
        fp.open("book.dat",ios::in);

        while(fp.read((char*)&bk,sizeof(book))){
            if(strcmp(bk.getbooknumber(),n)==0){
                bk.show_book();
                check=1;
            }
        }
        fp.close();
        if(check==0)
            cout<<"\n\nBook does not exist";
        getch();
}
void display_a_student(char n[]){
    system("cls");
    cout<<"\nSTUDENT DETAILS\n";
    int check=0;
    fp.open("student.dat",ios::in);

    while(fp.read((char*)&adm,sizeof(admin))){
        if((strcmp(adm.get_ID_number(),n)==0)){
            adm.show_student();
            check=1;
        }
    }
    fp.close();
    if(check==0)
        cout<<"\n\nStudent does not exist";
    getch();
}
void modify_book()
{
    system("cls");
    char n[20];
    int found=0;
    cout<<"\n\n\tMODIFY BOOK";
    cout<<"\n\n\tEnter The book number: ";
    cin>>n;
    fp.open("book.dat",ios::in|ios::out);

    while(fp.read((char*)&bk,sizeof(book)) && found==0){
        if(strcmp(bk.getbooknumber(),n)==0){
            bk.show_book();
            cout<<"\nEnter The New Details of book"<<endl;
            bk.modify_book();
            int pos=-1*sizeof(bk);
            fp.seekp(pos,ios::cur);
            fp.write((char*)&bk,sizeof(book));
            cout<<"\n\n\t Record Updated Successfully...";
            found=1;
        }
    }
    fp.close();
    if(found==0)
        cout<<"\n\n Record Not Found ";
    getch();
}
void modify_student()
{
    system("cls");
    char n[20];
    int found=0;
    cout<<"\n\n\tMODIFY STUDENT RECORD... ";
    cout<<"\n\n\tEnter Student's ID number: ";
    cin>>n;
    fp.open("student.dat",ios::in|ios::out);

    while(fp.read((char*)&adm,sizeof(admin)) && found==0){
        if(strcmp(adm.get_ID_number(),n)==0){
            adm.show_student();
            cout<<"\nEnter The New Details of student"<<endl;
            adm.modify_student();
            int pos=-1*sizeof(adm);
            fp.seekp(pos,ios::cur);
            fp.write((char*)&adm,sizeof(admin));
            cout<<"\n\n\t Record Updated Successfully...";
            found=1;
        }
    }
    fp.close();
    if(found==0)
        cout<<"\n\n Record Not Found ";
    getch();
}
void delete_student()
{
    system("cls");
    char n[20];
    int flag=0;
    cout<<"\n\n\n\tDELETE STUDENT";
    cout<<"\n\nEnter The ID number of the Student You Want To Delete: ";
    cin>>n;
    fp.open("student.dat",ios::in|ios::out);
    fstream fp2;
    fp2.open("Temp.dat",ios::out);
    fp.seekg(0,ios::beg);

        while(fp.read((char*)&adm,sizeof(admin))){
            if(strcmp(adm.get_ID_number(),n)!=0)
                fp2.write((char*)&adm,sizeof(admin));
            else
                flag=1;
        }
        fp2.close();
        fp.close();
        remove("student.dat");
        rename("Temp.dat","student.dat");
        if(flag==1)
            cout<<"\n\n\tRecord Deleted ..";
        else
            cout<<"\n\nRecord not found";
        getch();
}
void delete_book()
{
    system("cls");
    char n[20];
    int flag=0;
    cout<<"\n\n\n\tDELETE BOOK";
    cout<<"\n\nEnter The Book's number You Want To Delete: ";
    cin>>n;
    fp.open("book.dat",ios::in|ios::out);
    fstream fp2;
    fp2.open("Temp.dat",ios::out);
    fp.seekg(0,ios::beg);
        while(fp.read((char*)&bk,sizeof(book))){
            if(strcmp(bk.getbooknumber(),n)!=0){
                fp2.write((char*)&bk,sizeof(book));
        }
        else
            flag=1;
        }
        fp2.close();
        fp.close();
        remove("book.dat");
        rename("Temp.dat","book.dat");
        if(flag==1)
            cout<<"\n\n\tRecord Deleted ..";
        else
            cout<<"\n\nRecord not found";
        getch();
}
void display_all_students()
{
    system("cls");
    fp.open("student.dat",ios::in);
    if(!fp){
        cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
        getch();
        return;
    }
    cout<<"\n\n\t\tSTUDENT LIST\n\n";
    cout<<"=============================================================================\n";
    cout<<"\tID Number."<<setw(10)<<"Name"<<setw(20)<<"Book Issued"<<setw(20)<<"Contact\n";
    cout<<"=============================================================================\n";
        while(fp.read((char*)&adm,sizeof(admin))){
            adm.report();
        }
        fp.close();
        getch();
}
void display_allb()
{
    system("cls");
    fp.open("book.dat",ios::in);
    if(!fp){
        cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
        getch();
        return;
    }
    cout<<"\n\n\t\tBook LIST\n\n";
    cout<<"=========================================================================\n";
    cout<<"\tBook Number"<<setw(20)<<"Book Name"<<setw(20)<<"Author\n";
    cout<<"=========================================================================\n";
    while(fp.read((char*)&bk,sizeof(book))){
        bk.report();
    }
    fp.close();
    getch();
}
void issue_book()
{
    system("cls");
    char sn[20],bn[20];
    int found=0,flag=0;
    cout<<"\t\t\nBOOK ISSUE";
    cout<<"\n\n\tEnter student's ID number: ";
    cin>>sn;
    fp.open("student.dat",ios::in|ios::out);
    fp1.open("book.dat",ios::in|ios::out);

        while(fp.read((char*)&adm,sizeof(admin)) && found==0){
            if(strcmp(adm.get_ID_number(),sn)==0){
                found=1;
                if(adm.rettoken()==0){
                    cout<<"\n\n\tEnter book number: ";
                    cin>>bn;
                    while(fp1.read((char*)&bk,sizeof(book))&& flag==0){
                        if(strcmp(bk.getbooknumber(),bn)==0){
                            bk.show_book();
                            flag=1;
                            adm.addtoken();
                            adm.getstbno(bk.getbooknumber());
                            int pos=-1*sizeof(adm);
                            fp.seekp(pos,ios::cur);
                            fp.write((char*)&adm,sizeof(admin));
                            cout<<"\n\n\t Book issued successfully...";
                        }
                    }
                    if(flag==0)
                        cout<<"Book number does not exist";
                }
                else
                    cout<<"You have not returned the last book ";
            }
        }
        if(found==0)
            cout<<"Student record not exist...";
        getch();
        system("cls");
        fp.close();
        fp1.close();
}
void book_return(){
    system("cls");
    char sn[20],bn[20];
    int found=0, flag=0, day, fine;
    cout<<"\t\tRETURN BOOKS\n";
    cout<<"\n\n\tEnter The student's ID Number : ";
    cin>>sn;
    fp.open("student.dat",ios::in|ios::out);
    fp1.open("book.dat",ios::in|ios::out);
        while(fp.read((char*)&adm,sizeof(admin)) && found==0){
            if(strcmp(adm.get_ID_number(),sn)==0){
                found=1;
                if(adm.rettoken()==1){
                    while(fp1.read((char*)&bk,sizeof(book))&& flag==0){
                        if(strcmp(bk.getbooknumber(),adm.retstbno())==0){
                            bk.show_book();
                            flag=1;
                            cout<<"\n\nBook returned in no. of days : ";
                            cin>>day;

                            if(day>8){          //fine per day 50
                                fine=(day-8)*50;
                                cout<<"\n\nThe Book is last. You have to pay a fine of  "<<fine;
                            }

                            adm.resettoken();
                            int pos=-1*sizeof(adm);
                            fp.seekp(pos,ios::cur);
                            fp.write((char*)&adm,sizeof(admin));
                            cout<<"\n\n\t Book returned successfully...";
                        }
                    }

                    if(flag==0)
                        cout<<"Book number does not exist";
                }

                else
                    cout<<"No book is issued..please check!!";
                }
            }
            if(found==0)
                cout<<"Student record not exist...";
            getch();
            system("cls");
            fp.close();
            fp1.close();
}
void intro()
{

    system("color 02"); //For Text color

    system("cls");
    cout<<"\n\t\t\t\t\t--------------------------------------\n";
    cout<<"\t\t\t\t\t WELCOME TO LIBRARY MANAGEMENT SYSTEM\n";
    cout<<"\t\t\t\t\t--------------------------------------";
}
void book_menu()
{
    int option;
    intro();
    cout<<"\n\t\t-----------------------------------";
    cout<<"\n\t\t\t\tBOOKS MENU\n";
    cout<<"\n\t\tPress 1 to CREATE BOOKS";
    cout<<"\n\t\tPress 2 to DISPLAY ALL BOOKS";
    cout<<"\n\t\tPress 3 to DISPLAY SPECIFIC BOOK";
    cout<<"\n\t\tPress 4 to MODIFY BOOKS";
    cout<<"\n\t\tPress 5 to DELETE BOOKS";
    cout<<"\n\t\tPress 6 to GO BACK TO MAIN MENU";
    cout<<"\n\t\t---------------------------------\n";
    cout<<"\n\t\tOption: ";
    cin>>option;
        switch(option){
            case 1:
                system("cls");
                write_book();
                break;
            case 2:
                display_allb();
                break;
            case 3:
                char num[20];
                system("cls");
                cout<<"\n\n\tPlease Enter The book No. ";
                cin>>num;
                display_a_book(num);
                break;
            case 4:
                modify_book();break;
            case 5:
                delete_book();break;
            case 6:
                system("cls");
                break;
                default:cout<<"\a";
        }
}
void student_menu()
{
    int option;
    intro();
    cout<<"\n\t\t---------------------------------------------";
    cout<<"\n\t\t\t\tSTUDENTS Menu\n";
    cout<<"\n\t\tPress 1 to CREATE STUDENT RECORD";
    cout<<"\n\t\tPress 2 to DISPLAY ALL STUDENTS RECORD";
    cout<<"\n\t\tPress 3 to DISPLAY SPECIFIC STUDENT RECORD";
    cout<<"\n\t\tPress 4 to MODIFY STUDENT RECORD";
    cout<<"\n\t\tPress 5 to DELETE STUDENT RECORD";
    cout<<"\n\t\tPress 6 to GO BACK TO MAIN MENU";
    cout<<"\n\t\t--------------------------------------------\n";
    cout<<"\n\t\tOption: ";
    cin>>option;

        switch(option){
            case 1:
                system("cls");
                write_student();
                break;
            case 2:
                system("cls");
                display_all_students();
                break;
            case 3:
                char num[20];
                system("cls");
                cout<<"\n\n\tPlease Enter The ID Number: ";
                cin>>num;
                display_a_student(num);
                break;
            case 4:
                system("cls");
                modify_student();break;
            case 5:
                system("cls");
                delete_student();break;
            case 6:
                break;
            default:
                cout<<"\a";
        }
}
void admin(){
    int option;
    intro();
    cout<<"\n\t\t---------------------------------------";
    cout<<"\n\t\t\t\tAdmin Menu\n";
    cout<<"\n\t\tPress 1 to ISSUE BOOKS";
    cout<<"\n\t\tPress 2 to RETURN BOOKS";
    cout<<"\n\t\tPress 3 to UPDATE STUDENT RECORDS";
    cout<<"\n\t\tPress 4 to UPDATE BOOK RECORDS";
    cout<<"\n\t\tPress 5 to TO MAIN MENU";
    cout<<"\n\t\t--------------------------------------\n";
    cout<<"\n\t\tOption: ";
    cin>>option;

    switch(option){
        case 1:
            system("cls");
            issue_book();
            break;
        case 2:
            system("cls");
            book_return();
            break;
        case 3:
            system("cls");
            student_menu();
            break;
        case 4:
            system("cls");
            book_menu();
            break;
        case 5:
            break;
        default :
            cout<<"\a";
    }
}
void Librarian(){
    int option;
    intro();
    cout<<"\n\t\t---------------------------------------";
    cout<<"\n\t\t\t\tLibrarian Menu\n";
    cout<<"\n\t\tPress 1 to ISSUE BOOKS";
    cout<<"\n\t\tPress 2 to RETURN BOOKS";
    cout<<"\n\t\tPress 3 to VIEW ALL STUDENT";
    cout<<"\n\t\tPress 4 to UPDATE BOOK RECORDS";
    cout<<"\n\t\tPress 5 to TO MAIN MENU";
    cout<<"\n\t\t--------------------------------------\n";
    cout<<"\n\t\tOption: ";
    cin>>option;

    switch(option){
        case 1:
            system("cls");
            issue_book();
            break;
        case 2:
            system("cls");
            book_return();
            break;
        case 3:
            system("cls");
            display_all_students();
            break;
        case 4:
            system("cls");
            book_menu();
            break;
        case 5:
            break;
        default :
            cout<<"\a";
    }
}
void user(){
    int num;
    intro();
    cout<<"\n\t\t---------------------------------------";
    cout<<"\n\t\t\tStudent Menu\n";
    cout<<"\n\t\tPress 1 INFO OF STUDENT";
    cout<<"\n\t\tPress 2 LIST OF BOOK";
    cout<<"\n\t\tPress 3 TO MAIN MENU";
    cout<<"\n\t\t---------------------------------------";
    cout<<"\n\t\tOption: ";
    cin>>num;

    switch(num){
    case 1:
        char num[20];
        system("cls");
        cout<<"\n\n\tPlease Enter The ID Number: ";
        cin>>num;
        display_a_student(num);
        break;
    case 2:
        system("cls");
        display_allb();
        break;
    case 3:
        break;
    default :
        cout<<"\a";

    }

}

int main(){
    int login;
    for(;;){
        intro();
        cout<<"\n\t\t---------------------------------------";
        cout<<"\n\t\t\t\tMain Menu\n";
        cout<<"\n\t\tPress 1  Admin.";
        cout<<"\n\t\tPress 2  Librarian";
        cout<<"\n\t\tPress 3  Student";
        cout<<"\n\t\tPress 4  Exit Program";
        cout<<"\n\t\t---------------------------------------";
        cout<<"\n\t\tOption: ";
        cin>>login;

        switch(login){
        case 1:
            system("cls");
            admin();
            break;
        case 2:
            system("cls");
            Librarian();
            break;
        case 3:
            system("cls");
            user();
            break;
        case 4:
            exit(0);
            break;
        default:
            cout<<"\a";
        }
    }
    return 0;
}
