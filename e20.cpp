#include<iostream>
#include<string>
#define n 20
#define serious 10
#define nonserious 5
#define checkup 1
using namespace std;

string q[n];
int pr[n];
int r = -1,f = -1;
//-------------------------------------------------------------------------------------------

void enqueue(string data,int p)//Enqueue function to insert data and its priority in queue
{
	int i;
	if((f==0)&&(r==n-1)) //Check if Queue is full
		cout<<"Queue is full";
	else {
		if(f==-1) { //if Queue is empty
			f = r = 0;
			q[r] = data;
			pr[r] = p;
		}
//-----------------------------------------
		else if(r == n-1){                  //if there there is some elemets in Queue
			for(i=f;i<=r;i++) { 
                q[i-f] = q[i]; 
                pr[i-f] = pr[i];
                r = r-f; 
                f = 0;
                for(i = r;i>f;i--) {
					if(p>pr[i]) {
						q[i+1] = q[i];
						pr[i+1] = pr[i];
		     		}
				    else break;
						
					q[i+1] = data;
					pr[i+1] = p;
					r++;
				}
			}
		}
//------------------------------------------
		else {
			for(i = r;i>=f;i--) {
				if(p>pr[i]) {
					q[i+1] = q[i];
					pr[i+1] = pr[i];	
				}
				else break;
			}
			q[i+1] = data;
			pr[i+1] = p;
			r++;
		}	
	}
}
//-----------------------------------------------------------------------------------------------------

void dequeue() { //remove the data from front
	if(f == -1) {
		cout<<"Queue is Empty";
	}	
	else {
	cout<<"deleted Element ="<<q[f]<<endl;
	cout<<"Its Priority = "<<pr[f]<<endl;
		// if(f==r) f = r = -1;
		// else f++;
	}
}
//---------------------------------------------------------------------------------------------------------

void display() { //print the data of Queue
	int i;
	if(f==-1){
		cout<<"No records found";
		return;
	}

	for(i=f;i<=r;i++) {
		cout << "Patient's Name - "<<q[i];
		switch(pr[i]) {
			case 1: 
				cout << " Priority - 'Checkup' " << endl;
			break;
			case 5:
				cout << " Priority - 'Non-serious' " << endl;
			break;
			case 10:
				cout << " Priority - 'Serious' " << endl;
			break;
			default:
				cout << "Priority not found" << endl;
		}
	}
}

//---------------------------------------------------------------------------------------------------------

int main() {
	string data;
	int p,opt;

			cout<<"\n---------------------------\n";
			cout<<"1)insert data\n2)display data\n3)delete data\n4)exit\n";
			cout<<"\n---------------------------\n";
			cout<<"Enter your choice:-";
			cin>>opt;

			switch(opt){
				case 1:
					cout<<"Enter patient name:-";
					cin>>data;
					cout<<"Enter priority of the patient(1-serious,2-non-serious,3-general checkup)";
					cin>>p;

					switch(p){
						case 1:
							enqueue(data,serious);
							break;

						case 2:
							enqueue(data,nonserious);
							break;

						case 3:
							enqueue(data,checkup);
							break;

						default:
							cout<<"Enter valid priority value:-";
							break;
					}
					break;

					case 2:
						display();
						break;

					case 3:
						dequeue();
						break;

					case 4:
						cout<<"------------exited-----------";
						break;

					default:
					cout<<"Enter valid choice";
					break;
			}
	return 0;
}
//-----------------------------------------------------------------------------------------------------------

