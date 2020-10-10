#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class BankAccount
{
private:
   
    string issued_date="";
    int balance;
    int month;
    int year;
    int day ;
    
    
public:
int account_number=1;
static int staticNumber;
    BankAccount(){
  time_t now = time(0);
  tm *ltm = localtime(&now);
  year= 1900 + ltm->tm_year;
  month= 1 + ltm->tm_mon;
  day= ltm->tm_mday;
issued_date+=to_string(year);
issued_date+="/";
issued_date+=to_string(month);
issued_date+="/";
issued_date+=to_string(day);
            this->balance = 0;
    }
    
    
    void SetBalance(int balance)
    {
        this->balance = balance;
    }
   
    int GetAccountNumber() 
    {
        return account_number;
    }
    int GetBalance() 
    {
        return balance;
    }
    string GetIssuedData() 
    {
        return issued_date;
    }
    
    void add_amount(int num){
        SetBalance(balance + num);
    }
    
    void withdraw_amount(int num){
        SetBalance(balance - num);
    }
    
    
    
}; 

int BankAccount::staticNumber=1;

class Client : public BankAccount
{
private:
    string name;
    int age;
    int phone;
    string address;
    bool is_married;
    

public:
    Client()
    {
    
    }
    
    Client(string name,int age, int phone ,string address,bool is_married)
    {
        this->name = name;
        this->age = age;
        this->phone = phone;
        this->address = address;
        this->is_married = is_married;
    }

    void SetAddress(string address)
    {
        this->address = address;
    }
    void SetAge(int age)
    {
        this->age = age;
    }
    void SetIsMarried(bool is_married)
    {
        this->is_married = is_married;
    }
    void SetName(string name)
    {
        this->name = name;
    }
    void SetPhone(int phone)
    {
        this->phone = phone;
    }
    string GetAddress() const
    {
        return address;
    }
    int GetAge() const
    {
        return age;
    }
    bool GetIsMarried() const
    {
        return is_married;
    }
    string GetName() const
    {
        return name;
    }
    int GetPhone() const
    {
        return phone;
    }
};

//entry function
Client full_it(Client client){
    string name;
    int age;
    int phone;
    bool is_married;
    string adress;
    string name1;
cout << "please enter your name\n";
cin >> name >> name1;
cout << "please enter your age\n";
cin >> age;
while(age < 18){
    cout << "age must be bigger than 18\n";
    cin >> age;
}
cout << "please enter your phone number \n";
cin >> phone;
cout << "please enter your adress\n";
cin >> adress;
cout << "please, if you are married enter 'yes' else 'no' \n";
string sis_married;
cin >> sis_married;
if(sis_married == "yes") is_married = true;
else is_married = false;
client.SetName(name+" "+name1);
client.SetAge(age);
client.SetAddress(adress);
client.SetPhone(phone);
client.SetIsMarried(is_married);

    return client;
}



int main()
{
    cout<<"----------------------Bank Account Project----------------------\n";
    cout <<"                     welcome\n";
    char num;
     int UserNeed =1;
     Client ArrClient[9999];
     int cnt=0;
     int account_number_var;
     double amount;
      string IsOk;
      int check;
         Client ClientNew;      
     while(UserNeed){
         cout<<"to create a new bank account enter one '1'\n";
         cout<<"to register enter two  '2'\n";
         cin >> num;
         switch(num){
             case '1':
             cout<<"welcome to sign in please fill the form\n";
             ClientNew = full_it(ClientNew);
             ArrClient[cnt] = ClientNew;
             cout << "Registered successfully";
             cout << endl;
             ArrClient[cnt].account_number=ArrClient[cnt].account_number+cnt;
                             cout<<"please dont forget it, Your account number is :"<<ArrClient[cnt].GetAccountNumber()<<endl;
             cout<< ", do you want to modify data ? yes/no\n";
             cin >> IsOk;
             if(IsOk == "yes"){
                 ClientNew = full_it(ClientNew);
                 ArrClient[cnt] = ClientNew;
             }else if(IsOk == "no"){
                 cout << "see you soon "<<endl;
             }
             
             cnt = cnt + 1;
             break;//case one ended
             case '2':
             cout <<"welcome, please enter your account number \n";
             cin >> account_number_var;
             int arrPos;
             bool isTrue =false;
             cout<<endl;
             cout<<endl;
             for(int j =0;j<cnt;j++){
                 if(account_number_var == ArrClient[j].GetAccountNumber()){
                     arrPos=j;   
                     cout <<"welcome to your account\n" <<"Mr/s" << ArrClient[j].GetName()<<endl;
                     cout << "issued date :"<<ArrClient[j].GetIssuedData()<<endl;
                     isTrue=true;
                     break;
                 } 
             }//for
             if(isTrue){
             cout << "Main Page \n";
             cout <<"if  you want to add amount enter 1\n";
             cout <<"if  you want to withdraw money  enter 2\n";
             cin >> check;
             if(check == 1){
                 cout << "enter money number\n";
                 cin >> amount;
                 ArrClient[arrPos].add_amount(amount);
                 
             }else if(check == 2){
                  cout << "enter money number\n";
                  cin >> amount;
                 ArrClient[arrPos].withdraw_amount(amount);

             }
             
             cout << "do you want to print your data before leaving\n  y/n?";
             cin >> num;
             if(num == 'y'){
                 cout << "your  new balance is : "<<ArrClient[arrPos].GetBalance()<<endl;
             }else if(num == 'n'){
                   cout << "see you again";
             }
             }else{
                 cout << "wrong account number"<<endl;
             }
             break;
         }//switch
         
         
         
         cout << endl;
         cout << endl;
         cout<<"welcome again\n";
     }//while
    
    
    
    
}