//Header files
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
//Homepage
class Homepage
{
    int f;
    string pwd;
    public:
        string usrname;
        Homepage()
        {
            f=0;
            cout<<"  _____            _        _      "<<endl;
            cout<<" |  __ \\          | |      | |     "<<endl;
            cout<<" | |__) |___ _ __ | |_ __ _| |___  "<<endl;
            cout<<" |  _  // _ \\ '_ \\| __/ _` | / __| "<<endl;
            cout<<" | | \\ \\  __/ | | | || (_| | \\__ \\ "<<endl;
            cout<<" |_|  \\_\\___|_| |_|\\__\\__,_|_|___/ "<<endl<<endl;
        }
        void Register();
        void Forgotpwd();
        int Login();
};
//Register
void Homepage::Register()
{
    system("CLS");
    cout<<"Enter username: ";
    cin>>usrname;
    f=1;
    string c;
    ifstream obj("Usernames.txt",ios::in);
    while(obj>>c)
    {
        if(usrname==c)
        {
            cout<<"User with this username already exists"<<endl;
            
            f=1;
            Register();
            break;
        }
        
    }
    if(f==1)
    {
        cout<<"Enter password: ";
        cin>>pwd;
        ofstream file("Usernames.txt",ios::app);
        file<<usrname<<endl;
        ofstream pswd("Passwords.txt",ios::app);
        pswd<<pwd<<endl;
        cout<<"Registration succesfull"<<endl;
        file.close();
        pswd.close();
        f=0;
    }
}
//Login
int Homepage::Login()
{
    system("CLS");
    int flag;
    string u,p;
    cout<<"Enter username: ";
    cin>>usrname;
    cout<<"Enter password: ";
    char pass[32];//to store password.
    int i = 0;
    char a;//a Temp char
    for(i=0;;)//infinite loop
    {
        a=getch();//stores char typed in a
        if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
            //check if a is numeric or alphabet
        {
            pass[i]=a;//stores a in pass
            ++i;
            cout<<"*";
        }
        if(a=='\b'&&i>=1)//if user typed backspace
            //i should be greater than 1.
        {
            cout<<"\b \b";//rub the character behind the cursor.
            --i;
        }
        if(a=='\r')//if enter is pressed
        {
            pass[i]='\0';//null means end of string.
            break;//break the loop
        }
        
    }
    pwd=string(pass);
    ifstream obj1("Usernames.txt",ios::in);
    ifstream obj2("Passwords.txt",ios::in);
    while(obj1>>u && obj2>>p)
    {
        if(usrname==u && pwd==p)
        {
            flag=1;
        }
    }
    obj1.close();
    obj2.close();
    if(flag==1)
    {
        cout<<"Hello "<<usrname<<"!!!"<<endl;
        return 0;
    }
    else
    {
        system("CLS");
        cout<<"Enter your credentials correctly!\nRegister if you are new..."<<endl;
        return 1;
    }
}
//Forgot Password
void Homepage::Forgotpwd()
{
    system("CLS");
    int c;
    string a,b;
    cout<<"Enter your username: ";
    cin>>usrname;
    ifstream obj1("Usernames.txt",ios::in);
    ifstream obj2("Passwords.txt",ios::in);
    while(obj1>>a && obj2>>b)
    {
        if(a==usrname)
        {
            c=1;
            break;
        }
    }
    if(c==1)
    {
        cout<<"Your password is: "<<b<<endl;
    }
    else
    {
        cout<<"Incorrect username!"<<endl;
    }
    obj1.close();
    obj2.close();

}

//Rental page
class Rental : public Homepage
{
    public:
        void car();
        void bike();
        void confirm(int days,int price,string car,int cno);
        void DelUser(string );
};
//Main function
int main()
{
    cout<<"Please wait..."<<endl;
    system("CLS");
    Rental R;
    int c,f=1;
    do
    {
       cout<<"1.Register\n2.Login\n3.Forgot Password\n4.EXIT\n";
       cin>>c;
       switch (c)
       {
            case 1:
                R.Register();
                break;
            case 2:
                f=R.Login();
                break;

            case 3:
                R.Forgotpwd();
                break;
            
            case 4:
                return 0;
                f=0;
                break;
            default:
                cout<<"Enter a valid choice!";
                break;
       } 
    } while (f==1);
    
    int choice,flag=1;
    do
    {
       system("CLS");
       cout<<"Welcome "<<R.usrname<<"!!"<<endl;
       cout<<"Choose the vehicle you want to rent\n1.Car\n2.Bike\n3.EXIT to main menu\n4.Delete user\n";
       cin>>choice;
       switch (choice)
       {
            case 1:
                R.car();
                flag=0;
                break;
            case 2:
                R.bike();
                flag=0;
                break;
            
            case 3:
                main();
                return 0;
                flag=0;
                break;
            case 4:
                R.DelUser(R.usrname);
                main();
                return 0;
                flag=0;
                break;
            default:
                cout<<"Enter a valid choice!";
                break;
       } 
    } while (flag==1);
    return 0;
    
}
//Delete user
void Rental::DelUser(string usr)
{
    string u,p;
    ifstream ob("Usernames.txt",ios::in);
    ofstream ob1("u1.txt",ios::app);
    ifstream ob2("Passwords.txt",ios::in);
    ofstream ob3("u2.txt",ios::app);
    while(ob>>u && ob2>>p)
    {
        if(usr!=u)
        {
            ob1<<u<<endl;
            ob3<<p<<endl;
        }
    }
    ob.close();
    ob1.close();
    ob2.close();
    ob3.close();
    remove("Usernames.txt");
    rename("u1.txt","Usernames.txt");
    remove("Passwords.txt");
    rename("u2.txt","Passwords.txt");
    system("CLS");
    printf("User Deleted!!\n");
    system("pause");

    
}
//Cars
void Rental::car()
{
    system("CLS");
    string c,car;
    
    int choice,flag=1,days,price,cno;
    cout<<"Enter the number of days you want to rent the car: ";
    cin>>days;
    do
    {
       cout<<"Select a car\n1.BMW 3 Series\n2.Audi Q5\n3.Audi A3\n4.Porsche 911 GT3\n5.EXIT to main menu\n";
       cin>>choice;
       switch (choice)
       {
            case 1:
                car="Car: BMW 3 Series";
                price=50;
                cno=5673;
                flag=0;
                break;
            case 2:
                car="Car: Audi Q5";
                price=30;
                cno=1029;
                flag=0;
                break;
            
            case 3:
                car="Car: Audi A3";
                price=20;
                cno=7234;
                flag=0;
                break;
            
            case 4:
                car="Car: Porsche 911 GT3";
                price=80;
                cno=9999;
                flag=0;
                break;
            
            case 5:
                main();
                exit(0);
                flag=0;
                break;
            default:
                cout<<"Enter a valid choice!\n";
                break;
       } 
    } while (flag==1);
    system("CLS");
    cout<<"The Vehicle you have chosen:\n";
    ifstream cars("Cars.txt",ios::in);
    while(getline(cars,c))
    {
        if(c==car)
        {
            cout<<c<<endl;
            while(getline(cars,c)&&c!="%")
            {
                cout<<c<<endl;
            }
        }
        
    }
    system("pause");
    confirm(days,price,car.substr(5,-1),cno);
    
}
//Bikes
void Rental::bike()
{
    system("CLS");
    string c,bike;
    
    int choice,flag=1,days,price,cno;
    cout<<"Enter the number of days you want to rent the bike: ";
    cin>>days;
    do
    {
       cout<<"Select a Bike\n1.Ducati Panigale V4\n2.BMW S 1000RR\n3.Kawasaki Ninja\n4.Aprilaa RSV4 RF\n5.EXIT to main menu\n";
       cin>>choice;
       switch (choice)
       {
            case 1:
                bike="Bike: Ducati Panigale V4";
                price=50;
                cno=7652;
                flag=0;
                break;
            case 2:
                bike="Bike: BMW S 1000RR";
                price=30;
                cno=4093;
                flag=0;
                break;
            
            case 3:
                bike="Bike: Kawasaki Ninja";
                price=20;
                cno=6666;
                flag=0;
                break;
            
            case 4:
                bike="Bike: Aprilaa RSV4 RF";
                price=80;
                cno=9999;
                flag=0;
                break;
            
            case 5:
                main();
                exit(0);
                flag=0;
                break;
            default:
                cout<<"Enter a valid choice!\n";
                break;
       } 
    } while (flag==1);
    system("CLS");
    cout<<"The Vehicle you have chosen:\n";
    ifstream bikes("Bikes.txt",ios::in);
    while(getline(bikes,c))
    {
        if(c==bike)
        {
            cout<<c<<endl;
            while(getline(bikes,c)&&c!="%")
            {
                cout<<c<<endl;
            }//'
        }
        
    }
    system("pause");
    
    confirm(days,price,bike.substr(6,-1),cno);
    
}
//Confirmation
void Rental::confirm(int days,int price,string car,int cno)
{
    system("CLS");
    int rate;
    rate=price*days;
    cout<< "\n\t\t                       Car Rental - Customer Invoice                  "<<endl;
    cout<< "\t\t	///////////////////////////////////////////////////////////"<<endl;
    cout<< "\t\t	| Invoice No. :"<<"------------------|"<<setw(20)<<"#Cnb82353"<<" |"<<endl;
    cout<< "\t\t	| Customer Name:"<<"-----------------|"<<setw(20)<<usrname<<" |"<<endl;
    cout<< "\t\t	| Vehicle Name :"<<"-----------------|"<<setw(20)<<car<<" |"<<endl;
    cout<< "\t\t	| Vehicle No. :"<<"------------------|"<<setw(20)<<cno<<" |"<<endl;
    cout<< "\t\t	| Number of days :"<<"---------------|"<<setw(20)<<days<<" |"<<endl;
    cout<< "\t\t	| Your Rental Amount is :"<<"--------|"<<setw(20)<<rate<<" |"<<endl;
    cout<< "\t\t	| Caution Money :"<<"----------------|"<<setw(20)<<"0"<<" |"<<endl;
    cout<< "\t\t	| Advanced :"<<"---------------------|"<<setw(20)<<"0"<<" |"<<endl;
    cout<< "\t\t	 ________________________________________________________"<<endl;
    cout<<"\n";
    cout<< "\t\t	| Total Rental Amount is :"<<"-------|"<<setw(20)<<rate<<" |"<<endl;
    cout<< "\t\t	 ________________________________________________________"<<endl;
    cout<< "\t\t	 # This is a computer generated invoce and it does not"<<endl;
    cout<< "\t\t	 require an authorised signture #"<<endl;
    cout<<" "<<endl;
    cout<< "\t\t	///////////////////////////////////////////////////////////"<<endl;
    cout<< "\t\t	You are advised to pay up the amount before due date."<<endl;
    cout<< "\t\t	Otherwise penalty fee will be applied"<<endl;
    cout<< "\t\t	///////////////////////////////////////////////////////////"<<endl;

    ofstream invoice("Invoice.txt",ios::app);
    invoice<< "\n\t\t                       Car Rental - Customer Invoice                  "<<endl;
    invoice<< "\t\t	///////////////////////////////////////////////////////////"<<endl;
    invoice<< "\t\t	| Invoice No. :"<<"------------------|"<<setw(20)<<"#Cnb82353"<<" |"<<endl;
    invoice<< "\t\t	| Customer Name:"<<"-----------------|"<<setw(20)<<usrname<<" |"<<endl;
    invoice<< "\t\t	| Vehicle Name :"<<"-----------------|"<<setw(20)<<car<<" |"<<endl;
    invoice<< "\t\t	| Vehicle No. :"<<"------------------|"<<setw(20)<<cno<<" |"<<endl;
    invoice<< "\t\t	| Number of days :"<<"---------------|"<<setw(20)<<days<<" |"<<endl;
    invoice<< "\t\t	| Your Rental Amount is :"<<"--------|"<<setw(20)<<rate<<" |"<<endl;
    invoice<< "\t\t	| Caution Money :"<<"----------------|"<<setw(20)<<"0"<<" |"<<endl;
    invoice<< "\t\t	| Advanced :"<<"---------------------|"<<setw(20)<<"0"<<" |"<<endl;
    invoice<< "\t\t	 ________________________________________________________"<<endl;
    invoice<<"\n";
    invoice<< "\t\t	| Total Rental Amount is :"<<"-------|"<<setw(20)<<rate<<" |"<<endl;
    invoice<< "\t\t	 ________________________________________________________"<<endl;
    invoice<< "\t\t	 # This is a computer generated invoce and it does not"<<endl;
    invoice<< "\t\t	 require an authorised signture #"<<endl;
    invoice<<" "<<endl;
    invoice<< "\t\t	///////////////////////////////////////////////////////////"<<endl;
    invoice<< "\t\t	You are advised to pay up the amount before due date."<<endl;
    invoice<< "\t\t	Otherwise penelty fee will be applied"<<endl;
    invoice<< "\t\t	///////////////////////////////////////////////////////////"<<endl;
    invoice<<"\t\t---------------------------------------------------------------"<<endl;
    invoice.close();
}





