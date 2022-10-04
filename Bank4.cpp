// Online C++ compiler to run C++ program online
#include<iostream>
#include<string>
#include<vector>
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
class Bank{
	string name, actype;
	int acno,balance;
	public :
		bool type(string ac){
			if(ac=="saving"){
			    cout<<"Enter the balance ";
			    cin>>balance ;
				if(balance>=1000){
				    balance=balance;
				    return true;
				}
				else{
				    return false;
				}
				
			}
			else if(ac=="current"){
			    cout<<"Enter the balance ";
			    cin>>balance;
				if(balance>=5000){
				    balance=balance;
				    return true;
				}
				else{
				    return false;
				}
			}
			else{
			    return false;
			}
		}
		bool openaccount(int i){
			cout<<"Name of the canditate: ";
			cin>>name;
			cout<<"Account Type: ";
			cin>>actype;
			if(type(actype)){
			    acno=i;
			   cout<<"Your account number is ";
			   cout<<acno<<endl;
			    return true;
			}
			else{
			    return false;
			}
			
		}
		void deposite(){
			int d;
			cout<<"Enter the deposite money "<<endl;
			cin>>d;
			balance=balance + d;
			cout<<"Your final balance is "<<balance<<endl;
		}
		void withdraw(){
			int w;
			cout<<"Enter the withdraw money "<<endl;
			cin>>w;
			
			if(w>balance){
				cout<<"Insufficient balance"<<endl;
			}
			else{
				balance=balance-w;
				cout<<"Your final balance is "<<balance<<endl;
			}
		}
		void showdetail(){
			cout<<"account number "<<acno<<endl;;
			cout<<"Name is "<<name<<endl;
			cout<<"Final balance is "<<balance<<endl;
		}
		int getaccount(){
			return acno;
		}
	
};
int main(){
	unordered_map<int,Bank>b;
	Bank c;
	int k;
	static int count =1;
		cout<<"******* Main Menu *********"<<endl;
	cout<<"1. Open account "<<endl;
	cout<<"2. Deposite Money "<<endl;
	cout<<"3. withdraw Money "<<endl;
	cout<<"4. Account detail "<<endl;
	cout<<"5. Delete account "<<endl;
	cout<<"6. close window"<<endl;
	while(1){
		int f=0,acno,i;

	int choice;
	cout<<"enter the choice"<<endl;
	cin>>choice;
	switch(choice){
		case 1:
			if(c.openaccount(count)){
			b.insert({count,c});
			count++;
			}
			else{
			    cout<<"account not opened due to low deposite or invalid account type "<<endl<<endl;
			}
			break;
		case 2:
			cout<<"Enter the account number ";
			cin>>acno;
			if(b.find(acno)!=b.end()){
				b[acno].deposite();
			}
			else{
				cout<<"account not found"<<endl;
			}
			break;
		case 3:
			cout<<"Enter the account number ";
			cin>>acno;
			if(b.find(acno)!=b.end()){
				b[acno].withdraw();
			}
			else{
				cout<<"account not found"<<endl;
			}
			break;
		case 4:
			cout<<"Enter the account number ";
			cin>>acno;
			if(b.find(acno)!=b.end()){
				b[acno].showdetail();
			}
			else{
				cout<<"account not found"<<endl;
			}
			break;
		case 5:
		   cout<<"Enter the account number ";
		   cin>>acno;
		   if(b.find(acno)!=b.end()){
				b.erase(acno);
			}
			else{
				cout<<"account not found"<<endl;
			}
			break;
		 case 6:
		 goto label;
		default :
			cout<<"Incorrect number";
	}
// 	cout<<"do you want do continue...press 1 for no "<<endl;
// 	cin>>k;	


  }
//   while(k!=1);
label: cout<<"Thank you for visiting us!!"<<endl;
   
}
