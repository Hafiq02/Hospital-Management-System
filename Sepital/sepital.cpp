#include <iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;

//class Patient
class Patient // parent class
{
    public:
        long long patientIC;
        string firstname;
        string lastname;
        int age;
        char blood[5];
        char gender;
        Patient *next; 
        virtual dipslayList(){}; // indicate polymorphism
};

//class Queue
class Queue: public Patient // child class of patient class
{
    private:                       // data hiding(encapsualtion)
        Patient *first, *last;     // indicate aggregation
    public:
        Queue(){
            first = NULL;
            last  = NULL;
        }
        Patient input();
        void insertatend();
        void insertatbeg();
        void getpatientout(); 
        void displayList(Patient*);
        int search(int);
};
//Queue function outline definitions
int Queue::search(int item) {
    if (first == NULL)
        return false;
    else {
        int flag = 0;
        Patient *p = new Patient();
        p = first;

    while (p->next != NULL && p->patientIC != item) {
        p = p->next;
    }
    if (p->patientIC == item) {
        flag = 1;
        return true;
    }
    if (flag == 0)
        return false;
    }
}

int readnumber() { // read input from main menu
    char b[20];
    cin.getline(b, sizeof(b));
    return atoi(b);
}

Patient Queue::input() { // function to input patient details
    int flag = 0;
    Patient *p = new Patient();
    cout<< "\n   Please enter data for Patient\n";
    cout<< "\n   First name     : ";
    getline(cin, p->firstname);
    cout << "   Last name      : ";
    getline(cin, p->lastname);
again:
    cout << "   Blood Group    : ";
    cin >> p->blood;
    if ((strcmp(p->blood, "A+") == 0) || (strcmp(p->blood, "a+") == 0) ||
        (strcmp(p->blood, "A-") == 0) || (strcmp(p->blood, "a-") == 0) ||
        (strcmp(p->blood, "B+") == 0) || (strcmp(p->blood, "b+") == 0) ||
        (strcmp(p->blood, "B-") == 0) || (strcmp(p->blood, "b-") == 0) ||
        (strcmp(p->blood, "O+") == 0) || (strcmp(p->blood, "o+") == 0) ||
        (strcmp(p->blood, "O-") == 0) || (strcmp(p->blood, "o-") == 0) ||
        (strcmp(p->blood, "AB+") == 0) || (strcmp(p->blood, "ab+") == 0) ||
        (strcmp(p->blood, "AB-") == 0) || (strcmp(p->blood, "ab-") == 0))
        flag = 1;
    if (flag == 0) {
        cout << "\n   Invalid Blood Group Try Again..\n\n";
    goto again;
  }
  cout << "   Gender(m/f)    : ";
  cin >> p->gender;
  cout << "   Age            : ";
  cin >> p->age;
  cout << "   IC number      : ";
  cin >> p->patientIC;

  if (search(p->patientIC)) {
    p->patientIC = 0;
    cout << "\n   Data not valid. Operation cancelled.";
    }
  return *p;
}

void output(Patient *p) { // fucntion to display patient details
    cout 
         << "\n  "
         "\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd"
         "\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
    cout << "\n   Patient data:\n";
    cout << "\n   First Name         : " << p->firstname;
    cout << "\n   Last Name          : " << p->lastname;
    cout << "\n   Gender             : " << p->gender;
    cout << "\n   Age                : " << p->age;
    cout << "\n   Blood Group        : " << p->blood;
    cout << "\n   IC number          : " << p->patientIC;
    cout
      << "\n\n  "
         "\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd"
         "\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
}

void Queue::insertatbeg() {                        // function insert at beginning from class queue    
    Patient *p = new Patient();                    // to add patient at the begining of the queue
    *p = input();

    if (p->patientIC == 0)
        return;

    if (first == NULL) {
        first = p;
        last = p;
        p->next = NULL;
    } 
    else {
        p->next = first;
        first = p;
    }
    system("cls");
    cout << "\n\tPatient added:";
    output(p);
}

void Queue::insertatend() {                         // function insert at end from class queue    
    Patient *p = new Patient();                    // to add patient at the end of the queue
    *p = input();
    if (p->patientIC == 0)
        return;

    if (first == NULL) {
        first = p;
        last = p;
        p->next = NULL;
    } 
    else {
        p->next = NULL;
        last->next = p;
        last = p;
    }
    system("cls");
    cout
      << "\n  "
         "\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd"
         "\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
    cout << "\n  |-- HOSPITAL MANAGEMENT SYSTEM --|";
    cout << "\n  "
          "\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd"
          "\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd"
          "\n";
    cout << "\n  ----------Patient ADDED-----------";
    output(p);
}



void Queue::displayList(Patient *) { // fucntion to display the complete list of patients
    if (first == NULL) {
        cout << "\n  No Patient";
    }
    system("cls");
    cout
      << "\n  "
         "\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd"
         "\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
    cout << "\n  |-- HOSPITAL MANAGEMENT SYSTEM --|";
    cout << "\n  "
          "\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd"
          "\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd"
          "\n";
    Patient *p = new Patient;
    p = first;

    while (p != NULL) {
        cout << "\n   Patient data:\n";
        cout << "\n   First Name       : " << p->firstname;
        cout << "\n   Last Name        : " << p->lastname;
        cout << "\n   Gender           : " << p->gender;
        cout << "\n   Age              : " << p->age;
        cout << "\n   Blood Group      : " << p->blood;
        cout << "\n   IC number        : " << p->patientIC;
        cout << "\n\n  "
            "\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd"
            "\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd"
            "\xcd\xcd\n";
        p = p->next;
    }
    cout << "\n";
}


//class Doctor
class Doctor: public Patient //indicate inheritance : class doctor is child class to patient class(parent class)
{
    protected:
        string tempDoctorName;
        string tempDoctorID;
        string doctorName[3];
        string doctorID[3];
        int choice;
        

    public:
        string names[3]={"Dr. Abdullah Ali Machiato", "Dr. Jackie Sparrow", "Dr. Spinazola Mojaraelia"};
        string ids[3]={"001","002","003"};
        
        void setName(string names[]);
        void setId(string ids[]);
        void displayList(Doctor *);
        void chooseDr(Doctor *);
        void displayDr(Doctor *);
};
// Doctor function outline definitons
void Doctor::setName(string names[]) { // function to set doctors' names
    for(int i=0;i<3;i++)
    {
        doctorName[i]=names[i];
    }
}

void Doctor::setId(string ids[]) { //fucntion to set doctors' id
    for(int i=0;i<3;i++)
    {
        doctorID[i]=ids[i];
    }
}

void Doctor::displayList(Doctor *d) { //display list of doctors availabe
	cout<<"\n-------------------------------";
    cout<<"\nList of available Doctors ";
    cout<<"\n-------------------------------\n";
    for (int i=0;i<3;i++)
    {
        cout<<i+1<<".\t Name: "<<doctorName[i]<<endl;
        cout<<"  \t ID: "<<doctorID[i]<<endl;    
    }
    cout<<endl<<endl;
    chooseDr(d);
}

void Doctor::chooseDr(Doctor *d) { // function to choose availabe doctors
    do 
	{
		int choice;
        cout << "\nPlease enter your choice(1 - 3)  : ";
        cin>>choice;
        cout << "\nChosen Dr. is ";
        switch (choice)
        {
            case 1:
            	cout << doctorName[0] << " (ID : " << doctorID[0] << ")";
            	d->tempDoctorName=doctorName[0];
        	    d->tempDoctorID=doctorID[0];
        	    cout << "\n";
        	    break;
        
            case 2:
        	    cout << doctorName[1] << " (ID : " << doctorID[1] << ")";
        	    d->tempDoctorName=doctorName[1];
        	    d->tempDoctorID=doctorID[1];
        	    cout << "\n";
        	    break;

            case 3:
        	    cout << doctorName[2] << " (ID : " << doctorID[2] << ")";
        	    d->tempDoctorName=doctorName[2];
        	    d->tempDoctorID=doctorID[2];
        	    cout << "\n";
        	    break;

            default:
            	break;
        }
    }while(choice<1 && choice>3);
    
}

void Doctor::displayDr(Doctor *d) { // display the selected doctor
    cout << "\n Name : " << d->doctorName[choice];
    cout << "\n ID   : " << d->doctorID[choice];
}

//class IPD
class IPD  
{
    protected:                    //encapsulation
        int ward_no;
        int bed_no;
        string drug_name;
        
        
    public:
		int charge_per_day;
		int num_days_admitted;
        int drug_price;
		
        void setPrescription() { // inline fucntion that ask user to set input prescription
            cout<<"\n Prescription from pharmacist : ";
            cin.ignore();
            getline(cin,drug_name);
            cout<<" Please enter price : RM";
            cin>>drug_price;
        }
        void accept_ipd_details() { // function that set input of the ipd details
                cout<<"\n -------------------------------";
                cout<<"\n Enter IPD Details ";
                cout<<"\n -------------------------------";
                cout<<"\n Ward No.        :  ";
                cin>>ward_no;
                cout<<"\n Bed No.         :  ";
                cin>>bed_no;
                cout<<"\n Charge Per Day  :  RM";
                cin>>charge_per_day;
                cout<<"\n Days Admitted   :  ";
    			cin>>num_days_admitted;
    cout<<endl;
        }
        void display_ipd_details() { // function to display ipd details
                cout<<"\n -------------------------------";
                cout<<"\n Displaying IPD Details";
                cout<<"\n -------------------------------";
                cout<<"\n Ward No.         :  "<<ward_no;
                cout<<"\n Bed No.          :  "<<bed_no;
                cout<<"\n Charge Per Day   :  RM"<<charge_per_day;
                cout<<"\n Days Admitted    :  "<<num_days_admitted;
        }
        void display_prescription() { // function that display prescription
                cout<<"\n Prescription     :  "<<drug_name;
                cout<<"\n Drug Price       :  RM"<<drug_price;
        }
};


//class Bill 
class Bill: public Queue, public IPD, public Doctor // inheritance : bill class is child class to ipd and doctor class(parent class)
{


    public:
    	int amount;
        Bill() {
            int amount=0; 
        }
        IPD ipd;
        Bill operator* (Bill &b)  // operator overloading * to calculate bill amount
        {
            Bill bill;
            bill.amount=num_days_admitted*charge_per_day;
            return bill;
        }
        Bill operator+= (Bill &b) // operator overloading + to calculate bill amount
        {
            Bill bill;
            bill.amount+=drug_price;
            return bill;
        }
        
        void accept_ipd_patient_details(IPD *ipd, Doctor *d, Bill *b);
};

void printBill(IPD *ipd, Doctor *d, Bill *b) {// standalone function that display the bill
    cout 
         << "\n  "
         "\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd"
         "\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";  
        cout << "\n        Hospital Bill:\n"; 
	    ipd->display_ipd_details();
	    ipd->display_prescription();
	    cout << "\n -------------------------------";
	    b->amount=ipd->num_days_admitted*ipd->charge_per_day;
	    b->amount+=ipd->drug_price;
	    cout << "\n Total payment due :  RM" << b->amount;
	    cout << "\n -------------------------------";
	    cout
	      << "\n\n  "
	         "\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd"
	         "\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n";
	    system("pause");
}

void Bill::accept_ipd_patient_details(IPD *ipd, Doctor *d, Bill *b) { // function that get/hold the ipd details and prescription
    ipd->accept_ipd_details();
    ipd->setPrescription();
    cout<<endl<<endl;
    cout<<"*** GENERATING PATIENT'S BILL ***\n ";
	system("pause");
    cout<<endl;    
	printBill(ipd, d, b);
}


void main_menu(Queue *q, Doctor *d, IPD *ipd, Bill *b) { // function that display the main menu
    int choice = 0;

    while (choice != 5) {
    system("cls");
    cout << "\n  "
            "\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd"
            "\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd"
            "\xcd\xcd";
    cout << "\n  |-- HOSPITAL MANAGEMENT SYSTEM --|";
    cout << "\n  "
            "\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd"
            "\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd"
            "\xcd\xcd";
    cout << "\n\n   Main Menu\n\n";
    cout << "\n   [1] Add normal patient\n";
    cout << "   [2] Add critically ill patient\n";
    cout << "   [3] Take patient to Doctor\n";
    cout << "   [4] Display patient waiting list\n";
    cout << "   [5] Exit\n";
    cout << "\n   Please enter your choice : ";
    choice = readnumber();
    cout << "  "
            "\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd"
            "\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd"
            "\xcd\xcd";

    switch (choice) {
    case 1:
        q->insertatend(); // access insertatend
        cout << "\n   Press any key";
        getchar();
        break;

    case 2:
        q->insertatbeg(); // access insertatbeg
        cout << "\n   Press any key";
        getchar();
        break;

    case 3:
        q->getpatientout(); //access getpatientout
        cout << "\n   Press any key";
        getchar();
        system("cls");
		
		d->setName(d->names);
		d->setId(d->ids);
        d->displayList(d);
        system("pause");
        system("cls");
        b->accept_ipd_patient_details(ipd, d, b);
        break;

    case 4:
        system("cls");
        q->displayList(q); // access displaylist
        cout << "\n   Press any key";
        getchar();
        break;

    case 5:
        cout << "\n\t\tThank you! \n";
        system("cls");
        exit(0);
        break;
    }
  }
}

void Queue::getpatientout() { // function to get patient out from the patient list
    system("cls");
    Queue q;
    if (first == NULL) {
    cout << "\n  No patient to operate\n";
    system("pause");
    Queue *q = new Queue();
    IPD *ipd = new IPD();
    Doctor *d = new Doctor();
    Bill *b = new Bill();
    label:
    main_menu(q, d, ipd, b);
    
    } 
    else {
        Patient *p = new Patient();
        p = first;
        first = first->next;
        cout << "\n  Patient to operate:";
        output(p);
    }
} 

//main function
int main()
{
	
    Queue *q = new Queue();            // dynamically allocated object
    IPD *ipd = new IPD();
    Doctor *d = new Doctor();
    Bill *b = new Bill();
    label:
    main_menu(q, d, ipd, b);           //function call to main menu

    return 0;
};

