#include <iostream> //input functions
#include <fstream> //file handling
#include <windows.h> //system operations
#include <sstream> //enables use of std::stringstream (converting between diff data types and strings..)

using namespace std;



class Login{
private:
    string LoginID, Password;
public:
    Login():LoginID(""),Password(""){

    }

    void setID(string id){
        LoginID = id;
    }

    void setPW(string pw){
        Password = pw;
    }

    string getID(){
        return LoginID;
    }

    string getPW(){
        return Password;
    }
};


void registration(Login log){
    system("cls");
    string id, pw;

    cout<<"\tEnter Login ID:: ";
    cin>>id;
    log.setID(id);

    start:
    cout<<"\t Enter Strong Password:: ";
    cin>>pw;
    if(pw.length() >= 8){
        log.setPW(pw);
    } else {
        cout<<"\t The password should be at least 8 characters long!"<<endl;
        goto start;
    }
    ofstream outfile("C:\\Users\\hp\\Desktop\\HTML\\Github projects\\Social Media\\Registration an login\\Login.txt", ios::app);
    if (!outfile) {
        cout <<"\tError opening file for writing!"<<endl;
    } else {
        outfile<<"\t"<<log.getID()<<" : "<<log.getPW()<<endl<<endl;
        std::cout << "\tRegistration successful!" <<endl;
    }
    Sleep(3000);
}

void login(){
    system("cls");
    string id, pw;
    cout<<"\t Enter Login ID: ";
    cin>>id;

    cout<<"\t Enter Password:: ";
    cin>>pw;

    ifstream infile("C:\\Users\\hp\\Desktop\\HTML\\Github projects\\Social Media\\Registration an login\\Login.txt");
    if(!infile){
        cout<<"Cannot Access the file!"<<endl;
    } else {
        string line;
        bool found = false;
        while(getline(infile,line)){
            stringstream ss;
            ss<<line; //extract values from a single line
            string userID, userPW;
            char delimiter; //stores a single character that separates the values in the stream.
            ss>>userID>>delimiter>>userPW; //extracts the values from the stringstream ss

            if(id==userID && pw==userPW){
                found = true;

                cout<<"\tPlease Wait";

                for(int i=0; i < 3 ; i++){
                    cout<<".";
                    Sleep(800);
                }
                system("cls");
                cout<<"\tWelcome To Login Page!"<<endl;
            }
        }
        if(!found){
            cout<<"\tError: Incorrect Login ID or Password!"<<endl;
        }
    }
    infile.close();
    Sleep(5000);
}

int main(){
    Login log;

    bool exit = false;
    while(!exit){
        system("cls");

        int ch;

        cout<<"\tWelcome to Registration & Login Form"<<endl;
        cout<<"\t***********************************"<<endl;
        cout<<"\t1. Register"<<endl;
        cout<<"\t2. Login"<<endl;
        cout<<"\t3. Exit"<<endl;
        cout<<"\tEnter Choice:: ";
        cin>>ch;

        if(ch==1){
            registration(log);
        } else if(ch==2){
            login();
        } else if(ch==3){
            exit = true;
        } else {
            cout<<"\tInvalid Choice! Please enter 1, 2, or 3."<<endl;
            Sleep(3000);
        }
    }

    return 0;
}
