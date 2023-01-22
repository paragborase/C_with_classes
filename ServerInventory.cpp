//===============================================================
// Description : Server Inventory managemnet system
//    	         (Hostname, server_ip, JVM running on server,Owner of server)
// Date        : 29 Dec 2022
// Auther      : Parag Rajedra Borase
//===============================================================

#include<iostream>
#include<string>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<cstring>
using namespace std;

struct node
{
	int Server_no;
	string Hostname;
	string Server_ip;
	string JVM1;
	string Owner;
	
	struct node * next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

class Server_class
{
	public: 
		PNODE First;
		int iCount;
	
	public:
		Server_class();
		void InsertLast(int No, string str1, string str2, string str3, string str4);
		void Display();
		void Search(int no);
		void Search(string str1);
		void Delete(int no);
		void Update(int no);
		//void File_Writer();
};

Server_class :: Server_class()
{
	First = NULL;
	iCount = 0;
}

void Server_class :: InsertLast(int No, string str1, string str2, string str3, string str4)
{
	int iCnt = 0;
	PNODE temp1 = First;
	PNODE temp2 = First;
	
	PNODE newn = new NODE;
	newn->Server_no = No;
	newn->Hostname = str1;
	newn->Server_ip = str2;
	newn->JVM1 = str3;
	newn->Owner = str4;
	newn->next = NULL;
	
	if((No < 1) || (No > 1000))
	{
		cout<<"\n Enter the server number between 1 to 1000 \n";
		return;
	}
	
	while(temp1 != NULL)
	{
		if(temp1-> Server_no == No)
		{
			cout<<"\n server Number is already present please enter another number\n";
			return;
		}
		temp1 = temp1->next;
	}
		
		
	if(First == NULL)
	{
		First = newn;
	}
	else
	{
		while(temp2->next != NULL)
		{
			temp2 =temp2->next;
		}
		temp2->next = newn;	
	}
	iCount++;
	cout<<"\n Server added in Inventory\n";
}
	
void Server_class :: Display()
{
	PNODE temp = First;
	cout<<"\n Server Inventory Records: \n";
	
	if(First == NULL)
	{
		cout<<"No records in server inventory\n";
		return;
	}
	
	while(temp != NULL)
	{
		cout<<"\n Server Hostname : "<<temp->Hostname<<"\n";
		cout<<"\n Server IP : "<<temp->Server_ip<<"\n";
		cout<<"\n Server JVM1 : "<<temp->JVM1<<"\n";
		cout<<"\n Server Owner : "<<temp->Owner<<"\n";
		temp = temp->next;
	}
	cout<<"\n"; 
}

void Server_class :: Search(int iNo)
{
	PNODE temp = First;
	
	while(temp != NULL)
	{
		if(temp -> Server_no == iNo)
		{
			cout<<"\n Server Hostname : "<<temp->Hostname<<"\n";
			cout<<"\n Server IP : "<<temp->Server_ip<<"\n";
			cout<<"\n Server JVM1 : "<<temp->JVM1<<"\n";
			cout<<"\n Server Owner : "<<temp->Owner<<"\n";
			break;
		}
		temp = temp->next;
	}
	
	if(temp == NULL)
	{
		cout<<"\n No server record found in inventory \n";
	}
}

void Server_class :: Search(string str1)
{
	PNODE temp = First;
	int iNo = 1;
	while(temp != NULL)
	{
		if(temp->Hostname == str1);
		{
			iNo = 0;
		}
		
		if(iNo = 0)
		{
			cout<<"\n Server Hostname : "<<temp->Hostname<<"\n";
			cout<<"\n Server IP : "<<temp->Server_ip<<"\n";
			cout<<"\n Server JVM1 : "<<temp->JVM1<<"\n";
			cout<<"\n Server Owner : "<<temp->Owner<<"\n";
			break;
		}
		temp = temp->next;
	}
	
	if(temp == NULL)
	{
		cout<<"\n No any records in server inventory\n";
	}
}

void Server_class :: Delete(int iNo)
{
	PNODE temp1 = First;
	int iCnt = 0;
	int ipos = 0;
	PNODE temp = First;
	
	if((iNo > iCount) || (iNo < 1))
	{
		cout<<"Invalid Server Number";
		return;
	}
	
	while(temp1 != NULL)
	{
		iCnt++;
		if(temp1 -> Server_no == iNo)
		{
			ipos = iCnt;
			break;
		}
		temp1 = temp1 -> next;
	}
	
	if(ipos < 1)
	{
		cout<<"\n Incorrect Position Number\n";
		return;
	}
	
	if(ipos == 1)  //Delete First server record
	{
		if(First->next == NULL)
		{
			delete First;
			First = NULL;
		}
		else
		{
			PNODE temp2 = First;
			First = First->next;
			delete temp2;
		}
	}
	
	else if(ipos == iCount)   //Delete Last server record
	{
		if(First->next == NULL)
		{
			delete First;
			First = NULL;
		}
		
		else
		{
			while(temp->next->next != NULL)
			{
				temp = temp->next;
			}
			delete temp->next;
			temp->next = NULL;
		}
	}
	
	else   //Delete at position record
	{
		for(int i = 1; i < ipos-1; i++)
		{
			temp = temp ->next;
		}
		PNODE temp3 = NULL;
		temp3 = temp->next;
		temp->next = temp3->next; //temp->next = temp->next->next
		delete temp3;
	}
	iCount--;
	cout<<"\n Server Record Delete Sucessfully\n";
}

void Server_class :: Update(int iNo)
{
	PNODE temp = First;
	int iOption = 1;
	int iRef = 0;
	int New_Server_No = 0;
	string New_Hostname;
	string New_server_IP;
	string NEW_JVM1;
	string NEW_Owner;
	
	while(temp != NULL)
	{
		if(temp->Server_no == iNo)
		{
			iRef = 1;
			break;
		}
		temp = temp->next;
	}
	
	if(iRef == 0)
	{
		cout<<"\n No any element as provided in Inventory\n";
		return;
	}
	else
	{
		cout<<"\n Server found for Server_No : "<<iNo<<"\n";
		
		while(iOption != 0)
		{
			cout<<"\n Enter your Choice : \n";
			cout<<"\n______________________________\n";
			cout << "1: Press 1 for Update Hostname: \n";
			cout << "2: Press 2 for Update Server_IP: \n";
			cout << "3: Press 3 for Update JVM1: \n";
			cout << "4: Press 4 for Update Owner: \n";
			cout << "0: Press 0 for Exit to main menu: \n";
			cin >> iOption;
			
			switch(iOption)
			{
				case 1: 
					cout<<"\n Enter New Hostname : \n";
					cin >> New_Hostname;
					temp->Hostname = New_Hostname;
					cout<<"Update Successfully \n";
					break;
					
				case 2:
					cout<<"\n Enter New Serevr_IP: \n";
					cin >> New_server_IP;
					
					//strcpy(temp->Server_ip, New_server_IP)
					temp->Server_ip = New_server_IP;
					cout<<"Update Successfully \n";
					break;
				
				case 3:
					cout<<" Enter new JVM Name: \n";
					cin >> NEW_JVM1;
					temp->JVM1 = NEW_JVM1;
					cout<<"Update Successfully \n";
					break;
					
				case 4:
					cout<<"\n Enter New owner Name\n";
					cin >> NEW_Owner;
					temp->Owner = NEW_Owner;
					cout<<"Update Successfully \n";
					break;
					
				case 0:
					break;
					
				default:
					cout<<"Please enter Valid Server Number \n";
					break;
			}
		}
	}
}


				
		
	

int main()
{
	int iNo = 0, iChoice = 1;
	int Server_noX;
	string HostnameX;
	string Server_ipX;
	string JVM1X;
	string OwnerX;
	
	Server_class *obj1 = new Server_class;
	
	cout<<"============================================================\n";
	cout<<"\t"<<"==========Server Inventory Managemnet=================\n";
	cout<<"\t"<<"==========***************************=================\n";
	cout<<"============================================================\n";
	
	while(1)
	{
		cout<< "Enter your choice\n";
		cout<<"============================================================\n";
		cout<<"1 : Press 1 to add  details of server: \n";
		cout<<"2 : Press 2 to display information of all server: \n";
		cout<<"3 : Press 3 to count Total number of server\n";
		cout<<"4 : Press 4 to Search server details by its IP details\n";
		cout<<"5 : Press 5 to Search server details by its Hostname details\n";
		cout<<"6 : Press 6 to delete the record of a server by its Server_Number\n";
		cout<<"7 : Press 7 to update the existing records of server details\n";
		cout<<"8 : Press 0 to exit the application\n";
		cout<<"============================================================\n";
		
		cin>>iChoice;
		
		switch(iChoice)
		{
			case 1: 
				cout<<"Enter the Server No :  \n";
				cin >> Server_noX;
				
				cout<<"Enter the HostnameX : \n";
				cin >> HostnameX;
				
				cout<<"Enter the serevr_ip : \n";
				cin >> Server_ipX;
				
				cout<<"Enter the JVM running on server:  \n";
				cin >> JVM1X;
				
				cout<<"enter the Owner Name:  \n";
				cin >> OwnerX;
				
				obj1->InsertLast(Server_noX,HostnameX,Server_ipX,JVM1X,OwnerX);
				break;
				
			case 2:
				obj1 -> Display();
				break;
				
			case 3:
				iNo = obj1->iCount;
				cout<<"\n Total number of servers are : "<<iNo<<"\n";
				break;
				
			case 4:
				cout<<"\n Enter the IP of server to search : \n";
				cin >> Server_ipX;
				obj1->Search(Server_ipX);
				break;
				
			case 5: 
				cout<<"\n Enter the Hostname details to search server record : \n";
				cin >> HostnameX;
				obj1->Search(HostnameX);
				break;
				
			case 6:
				cout<<"\n Enter the server Number to delete the record : \n";
				cin >> Server_noX;
				obj1->Delete(Server_noX);
				
			case 7:
				cout<<"\n Enter the server number for updation : \n";
				cin >> Server_noX;
				obj1-> Update(Server_noX);
				break;
				
			case 0 :
                cout << "\n Thank you for using the application \n";
                delete obj1;
                break;
        
            default:

                cout << "\n Enter valid input \n";
                break;
		}	
	}
	
	return 0;
}




// if ((fd = open(argv[1], O_WRONLY | O_APPEND)) < 0) {
//       perror("Problem in opening the file in append mode");
//       exit(1);