
#include<iostream>
#include <fstream>
#include<string>
#include<unistd.h>>
using namespace std;
int logged;
int r;
void thanks()
{
    string message="\n\n\n\t\t\t\tT H A N K\n\t\t\t\t\tY O U !\n\n\n";
    for (char c : message)
    {
        cout << c << flush;
        usleep(50000);
    }
}
char stars()
{
	cout<<"********************************************************************************";
}
void box(int x, int y)
{
	for(int i=0;i<y;i++)
	cout<<(char)x;
}
string Uname;
class user
{
    protected:
        string userName;
        string userPW;
        string UN;
        string UNF;
        string UE;
        string UPW;
        string userInput;
        int UA;
        int userRole;
        int z;
    public:
        int userLogin()
        {
            logged=0;
            system("cls");
            cout << "Enter User Name: ";
            cin >> userName;
            cout << "Enter Password: ";
            cin >> userPW;
            Uname=userName;
            string filename = "user.txt";
            ifstream infile(filename);
            string line;
            int passwordchecker;
            while (getline(infile, line)) {
                passwordchecker=0;
                size_t pos1 = 0, pos2 = 0, pos3 = 0, pos4 = 0;
                string field1, field2, field3, field4, field5;
                pos2 = line.find(",", pos1);
                field1 = line.substr(pos1, pos2 - pos1);
                pos1 = pos2 + 1;
                pos2 = line.find(",", pos1);
                field2 = line.substr(pos1, pos2 - pos1);
                pos1 = pos2 + 1;
                pos2 = line.find(",", pos1);
                field3 = line.substr(pos1, pos2 - pos1);
                pos1 = pos2 + 1;
                pos2 = line.find(",", pos1);
                field4 = line.substr(pos1, pos2 - pos1);
                pos1 = pos2 + 1;
                field5 = line.substr(pos1);
                if (field2==userName&&field4==userPW)
                {
                    if(stoi(field1)==r)
                    {
                        system("cls");
                        cout << "Welcome " << field2 <<endl<< endl;
                        logged=1;
                        passwordchecker=1;
                    }
                    else
                    {
                        cout<<"\nYou entered wrong user role...\nTry Again...";
                        logged=0;
                    }
                    break;
                }
            }
             if(passwordchecker==0)
             {
                    system("cls");
                    cout<<"User Name or Password Incorrect\n\n";
                    cout<<"Select Option Belove list\n\n1.Enter User Name & Password again\n2.Exit\n..........:";
                    cin>>z;
                    if(z==1)
                    {
                        userLogin();
                        return 0;
                    }
                    else if(z==2)
                    {
                        thanks();
                        return 0;
                    }
                    else
                    {
                        cout<<"Invalid Choice...\n";
                        thanks();
                        return 0;
                    }
                }
            infile.close();
        }
};
class Student:public user
{
    private:
        string st_id;
        string st_name;
        string st_address;
        int st_telNo;
        int age;
    public:
        void registerForCourse()
        {
            string x;
            cout<<"Enter course ID from belove list...\nID\tName"<<endl;
            ifstream file("course.txt");
            string line;
            while (getline(file, line)) {
                for (size_t i=0; i<line.length(); i++) {
                    if (line[i]==',') {
                        line[i]='\t';
                    }
                }
                cout <<line<< endl;
            }
            file.close();
            cout<<"\n.............: ";
            cin>>x;
            ifstream filex("course.txt");
            string linex;
            string search_string = x;
            while (getline(filex, linex)) {
                size_t pos = linex.find(search_string);
                if (pos != string::npos) {
                    size_t comma_pos = linex.find(",", pos);
                    if (comma_pos != string::npos) {
                        string value = linex.substr(comma_pos + 1);
                        cout << "Value: " << value << endl;
                        ifstream inputFile("user.txt");
                        ofstream outputFile("studentcourse.txt", ios::app);

                        if (!inputFile.is_open() || !outputFile.is_open()) {
                            cerr << "Failed to open file" << endl;
                        }
                        string search_string1 =Uname;
                        string line1;
                        while (getline(inputFile, line1)) {
                            size_t pos = line1.find(search_string1);
                            if (pos != string::npos) {
                                outputFile << line1 << ","<<value<<endl;
                                break;
                            }
                        }

                        inputFile.close();
                        outputFile.close();

                        cout << "Data copied successfully!" << endl;
                    }
                    }
                }
            }
};
class Academic:public user
{
    private:
    public:
        Academic()
        {
            cout<<"Registered Student...\n"<<endl;
            ifstream file("studentcourse.txt");
            string line;
            while (getline(file, line)) {
                for (size_t i=0; i<line.length(); i++) {
                    if (line[i]==',') {
                        line[i]='\t';
                    }
                }
                cout <<line<< endl;
            }
            file.close();
        }
};
class ManagementStaff:public user
{
    private:
    public:
        ManagementStaff()
        {
            cout<<"Registered Student...\n"<<endl;
            ifstream file("studentcourse.txt");
            string line;
            while (getline(file, line)) {
                for (size_t i=0; i<line.length(); i++) {
                    if (line[i]==',') {
                        line[i]='\t';
                    }
                }
                cout <<line<< endl;
            }
            file.close();
        }
};
class Admin:public user
{
    private:
        string adminName;
        string adminPW;
        string courseID;
        string courseName;
    public:
        void deleteRecord()
        {
            string filename = "user.txt";
            string search_string;
            cout<<"Enter User ID for Delete record: ";
            cin>>search_string;
            ifstream infile(filename);
            ofstream outfile("temp.txt");
            string line;
            while (getline(infile, line)) {
                size_t pos1 = 0, pos2 = 0;
                string field1, field2, field3, field4, field5;
                pos2 = line.find(",", pos1);
                field1 = line.substr(pos1, pos2 - pos1);
                pos1 = pos2 + 1;
                pos2 = line.find(",", pos1);
                field2 = line.substr(pos1, pos2 - pos1);
                pos1 = pos2 + 1;
                pos2 = line.find(",", pos1);
                field3 = line.substr(pos1, pos2 - pos1);
                pos1 = pos2 + 1;
                pos2 = line.find(",", pos1);
                field4 = line.substr(pos1, pos2 - pos1);
                pos1 = pos2 + 1;
                field5 = line.substr(pos1);
                if (field2 != search_string) {
                    outfile << line << endl;
                }
            }
            infile.close();
            outfile.close();
            remove(filename.c_str());
            rename("temp.txt", filename.c_str());
        }
        void createCourse()
        {
            cout<<"Enter New Course ID: ";
            cin>>courseID;
            cout << "Enter Course Name: ";
            cin.ignore();
            getline(cin, courseName);
            string filename = "course.txt";
            string search_string = courseID + "," + courseName;
            bool found = false;
            ifstream infile(filename);
            if (infile) {
                string line;
                while (getline(infile, line)) {
                    if (line.find(courseID) != string::npos || line.find(courseName) != string::npos) {
                        found = true;
                        break;
                    }
                }
                infile.close();
            }
            if (found) {
                cout << "Course already added." << endl;
            }
             else {
                fstream coursefile;
                coursefile.open("course.txt", ios::app);
                coursefile << courseID << "," << courseName << endl;
                cout << "Course added successfully..." << endl;
                thanks();
            }
        }
        void deleteCourse()
        {
            string filename = "course.txt";
            string search_string;
            cout<<"Enter Course ID for Delete record: ";
            cin>>search_string;
            ifstream infile(filename);
            ofstream outfile("temp2.txt");
            string line;
            while (getline(infile, line)) {
                size_t pos1 = 0, pos2 = 0;
                string field1, field2, field3, field4, field5;
                pos2 = line.find(",", pos1);
                field1 = line.substr(pos1, pos2 - pos1);
                pos1 = pos2 + 1;
                pos2 = line.find(",", pos1);
                field2 = line.substr(pos1, pos2 - pos1);
                pos1 = pos2 + 1;
                pos2 = line.find(",", pos1);
                field3 = line.substr(pos1, pos2 - pos1);
                pos1 = pos2 + 1;
                pos2 = line.find(",", pos1);
                field4 = line.substr(pos1, pos2 - pos1);
                pos1 = pos2 + 1;
                field5 = line.substr(pos1);
                if (field1 != search_string) {
                    outfile << line << endl;
                }
            }
            infile.close();
            outfile.close();
            remove(filename.c_str());
            rename("temp2.txt", filename.c_str());
        }
        int createAccount()
        {
            int t;
            cout<<"1.Student\n2.Academic\n3.Management Staff\nSelect User Role: ";
            cin>>userRole;
            if (userRole==1||userRole==2||userRole==3)
            {
                cout<<"Enter User Name(without spaces): ";
                cin>>UN;
                cout<<"Enter Email Address: ";
                cin>>UE;
                cout<<"Create Password: ";
                cin>>UPW;
                cout<<"Enter Age: ";
                cin>>UA;
            }
            else
            {
                system("cls");
                cout<<"Invalid role......\n";
                system("cls");
                return 0;
            }
            string filename = "user.txt";
            ifstream infile(filename);
            string line;
            int r=1;
            while (getline(infile, line))
            {
                size_t pos1 = 0, pos2 = 0;
                string field1, field2, field3;
                pos2 = line.find(",", pos1);
                field1 = line.substr(pos1, pos2 - pos1);
                pos1 = pos2 + 1;
                pos2 = line.find(",", pos1);
                field2 = line.substr(pos1, pos2 - pos1);
                pos1 = pos2 + 1;
                field3 = line.substr(pos1);
                if (field2 ==UN) {
                    cout << "User name already taken..\n1.Try again\n2.Exit\n..........:"<< endl;
                    cin>>t;
                    if(t==1)
                    {
                        createAccount();
                    }
                    if(t==2)
                    {
                        thanks();
                        break;
                    }
                    else
                    {
                        cout<<"invalid choice...\n";
                        thanks();
                        break;
                    }
                }
            else
            {
                infile.close();
                r=0;
            }
            }
            if(r!=1)
            {
                ofstream userfile;
                userfile.open("user.txt",ios::app);
                userfile <<userRole<<","<<UN<<","<<UE<<","<<UPW<<","<<UA<<endl;
                cout<<"User account Created successfully...\n";
                userfile.close();
            }
        }
            Admin()
            {
                cout<<"Enter Admin Name: ";
                cin>>adminName;
                cout<<"Enter Password: ";
                cin>>adminPW;
                int c=1;
                system("cls");
                if(adminName=="Admin321"&&adminPW=="admin123"&&c!=0)
                {
                    cout<<"Select Option Belove list\n1.Create User Account.\n2.Create new course.\n3.Delete record.\n4.Delete course\n5.Exit\n..........:";
                    cin>>c;
                    if(c==1)
                    {
                        system("cls");
                        createAccount();
                    }
                    else if(c==2)
                    {
                        system("cls");
                        createCourse();
                    }
                    else if(c==3)
                    {
                        system("cls");
                        deleteRecord();
                    }
                    else if(c==5)
                    {
                        system("cls");
                        thanks();
                        exit(0);
                    }
                    else if(c==4)
                    {
                        system("cls");
                        deleteCourse();
                    }
                    else
                    {
                        cout<<"Invalid Choice...";
                    }
                    system("cls");
                }
                else
                {
                    cout<<"Check user name & Password"<<endl;
                    thanks();
                }
            }
};
int main()
{
    Student S1;
    user U1;
    system("cls");
    box(178,80);
    cout<<endl<<stars()<<endl;
    string message="\n\n\n\t\t\t\tW E L C O M E\t T O\n\n\n\t\tS T U D E N T\tR E G I S T R A T I O N   S Y S T E M\n\n\n";
    for (char c : message)
    {
        cout << c << flush;
        usleep(25000);
    }
    cout<<endl<<stars()<<endl;
    box(178,80);
    cout<<endl<<endl;
    cout<<"Select Your Role from belove list\n\n1.Student\n2.Academic\n3.Management Staff\n4.Admin\n\nType here.....:";
    cin>>r;
    system("cls");
    switch(r) {
        case 1:
            system("cls");
            U1.userLogin();
            if(logged==1)
            {
                char input;
                cout << "Press y to continue or any other key to exit." << endl;
                cin >> input;
                if(input == 'y' || input == 'Y')
                {
                    string filename = "studentcourse.txt";

                    ifstream infile(filename);
                    string line;
                    while (getline(infile, line)) {
                        size_t pos1 = 0, pos2 = 0;
                        string field1, field2, field3;
                        pos2 = line.find(",", pos1);
                        field1 = line.substr(pos1, pos2 - pos1);
                        pos1 = pos2 + 1;
                        pos2 = line.find(",", pos1);
                        field2 = line.substr(pos1, pos2 - pos1);
                        pos1 = pos2 + 1;
                        field3 = line.substr(pos1);
                        if (field2 ==Uname) {
                            cout << "You already registered." << endl;
                            thanks();
                            break;
                        }
                       else
                        {
                            S1.registerForCourse();
                        }
                    }
                    infile.close();
                }
                else {
                    system("cls");
                    cout << "You choose to exit." << endl;
                    thanks();
                }
            }
            break;
        case 2:
            U1.userLogin();
            if(logged==1)
            {
                int rs;
                cout<<"Choose options.\n\n1.View registered student.\n...........:";
                cin>>rs;
                if(rs==1)
                {
                    ManagementStaff();
                }
            }
            break;
        case 3:
            U1.userLogin();
            if(logged==1)
            {
                int rs;
                cout<<"Choose options.\n\n1.View registered student.\n...........:";
                cin>>rs;
                if(rs==1)
                {
                    ManagementStaff();
                }
            }
            break;
        case 4:
            Admin();
            break;
        default:
           cout<<"Entered Invalid Choice...\n\n";
           thanks();
    }
    return 0;
}

