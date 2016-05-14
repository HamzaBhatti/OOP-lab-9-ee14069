#include<iostream>
#include<conio.h>
#include<string>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;
class atm
{
   private:
      float balance;
      float newbalance;
   public:
   	
   		atm();
   		
		void withdraw(float w, int acc);
		void fundstransfer(float l, float m);
		void billpay(float p, float q);        
		void statement();
};


atm::atm()
	{
         balance = 0;
         newbalance = 0;
    }
      

void atm::statement()
{
	char state[50];
	ifstream infile; 
   infile.open("state.txt");
   infile >> state;
   cout<< state << endl; 



}

void atm::fundstransfer(float l, float m)
{

	cout<<"Please entre Account No Of Receiver: ";
	cin>>l;
	cout<<"Please Entre Amount: ";
	cin>>m;
	if (m>balance)
	{
	cout<<"Insufficient Balance: ";
	
	}
	else
	
		balance = balance - m;
		newbalance = newbalance + m;

		//cout<<"Amount Transferred";


	ofstream outputFile("state.txt");
	outputFile << "\n------------FUND TRANSFER------------------\n";
	outputFile <<"Reciever Account Number = ";
	outputFile << l;
	outputFile <<"Amount =   ";
	
	outputFile << m;
	
	outputFile<<"---------------------------------------------------------";
	
	cout<< "\nyour Remaining Balance is "<<balance;		



}

void atm::billpay(float p, float q){

	cout<<"Please Enter Bill Refrence No: ";
	cin>>q;
	cout<<"Please entre amount of bill: ";
	cin>>p;
	if(p>balance)
	{
		cout<<"Sorry Your Account Balance is less than your bill amount";
	}

	else
		cout<<"Your Bill Is PAID";
		balance = balance - p;
	ofstream outputFile("bills.txt");
	outputFile << "\nBill Refrence Number\n";
		
	outputFile << q;	
	
	outputFile << "\nAmount = \n";
	outputFile << p;	
	cout<< "\nyour Remaining Balance is "<<balance;		

}
      
void atm::withdraw(float w, int acct)
{
        cout<<"Please entre your Account Number Again ";
        cin>>acct;
        //cout<<"Please Entre your PIN "
		cout<<"Please entre amount you want to withdraw"<<endl;
        cin>>w;
        if(w>balance)
	  	{
		  	
        cout<<"Your balance is less than amount you entered"<<endl;
        }
		else
            balance = balance - w;
      	
		ofstream outputFile("state.txt");
		outputFile << "\n--------WithdraW------------\n";
		outputFile << "\nAccount Number = ";
		
		outputFile << acct;
		outputFile << "\nAmount";
		
		outputFile << w;	
	      
	      
	   cout<< "\nyour Remaining Balance is "<<balance;		
   
}
	  
      


class newuser
{

	//void newuser1();
public:
	
	newuser()
	{
	//int r = 0;
	//r = srand(1000);
	int accno = 1000;
	string r;
	int u ;
	char username[20];
	char password[20];
	//double balance;
	char type[20];
	cout << "Are You new User: ";
	cout << " yes/no(y/n): ";
	//cout << "(7) no: ";
	cin>>r;
	
	if (r == "y")
	{
			
		
			cout<<"Please entre account type: ";
			cin>>type;
			cout<<"Please Enter Your name : ";
			cin>>username;
			if (type == "saving")
			{
			ofstream outputFile("saving.txt");
			outputFile << username;
			outputFile<<accno;	
		
			}
			
			if (type == "current")
			{
			ofstream outputFile("current.txt");
			outputFile << username;
			outputFile<<accno;	
		
			}
			
			cout<<username;
			
			cout<<"\nYour Dafult PIN is 1234 : ";
			cout<<"\nYour Account Number Is "<<accno;
			accno++;
			//cout<<"Press any key  to continue: ";
			//cin>>u;
		}

	
		}
};


int main()
{
	
	atm a1;
	newuser b1;
		float f = 0;
		float x = 0;
		int y = 0;
		float z = 0;
		float h = 0;
		int sd = 0;
		int choice;
		string password;
		system("cls");
		cout<<"\nPlease Entre Your Account Number";
		cin>>sd;		
		cout<<"Please entre what do you want :-\n";
        cout<<"(1)Cash Withdraw\n";
        cout<<"(2)Transfer funds\n";
        cout<<"(3)Pay Your Bill\n";
		cout<<"(4)Bank statement\n";
		
		cin>>choice;
		
	
	switch (choice)
	{

		case 1:
		
			a1.withdraw(x,y);
			break;
	
		case 2:
			a1.fundstransfer(x,z);
			break;
			
		case 3:
			a1.billpay(f,h);	
			break;
			
		case 4:
			a1.statement();
			break;

	}






}
		




