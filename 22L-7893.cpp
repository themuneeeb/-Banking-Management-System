#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include <regex>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

class UserClient
{
private:
	string *fullname;
	string *adress;
	string *phoneno;
	string *CNIC;
	string *loginid;
	string *password;
	int *withdrawlimit;
	string *accounttype;
	int *accountbalance;
	string *cardno;
	string *pin;
public:
	UserClient();
	void CreateAccount();
	void Login();
	void UserClientMenu();
};
UserClient::UserClient()
{
	fullname = new string("");
	adress = new string("");
	phoneno = new string("");
	CNIC = new string("");
	loginid = new string("");
	password = new string("");
	withdrawlimit = new int(0);
	accounttype = new string("");
	accountbalance = new int(0);
	cardno = new string("");
	pin = new string("");
}
void UserClient::CreateAccount()
{
	C:
	cin.ignore();
	fullname:
	cout << "ENTER YOUR FULL NAME:" << endl;
	getline(cin, *fullname);
	regex nameRegex(R"(^[A-Za-z\s]+$)");
	if (!regex_match(*fullname, nameRegex))
	{
		cout << "ERROR! INVALID FULL NAME. PLEASE RE-ENTER:" << endl;
		goto fullname;
	}
	phonenumber:
	cout << "ENTER YOUR PHONE NUMBER:" << endl;
	getline(cin, *phoneno);
	regex phonenoRegex(R"(^\d{11}$)");
	if (!regex_match(*phoneno, phonenoRegex))
	{
		cout << "ERROR! PLEASE ENTER PHONE NUMBER IN VALID FORMAT!" << endl;
		goto phonenumber;
	}
	adress:
	cout << "ENTER YOUR ADRESS!" << endl;
	getline(cin, *adress);
	if (adress->empty() || adress->length() < 5)
	{
		cout << "ERROR! INVALID ADRESS. PLEASE ENTER A VALID ADRESS!" << endl;
		goto adress;
	}
	CNIC:
	cout << "ENTER YOUR CNIC:" << endl;
	getline(cin, *CNIC);
	if (CNIC->length() != 13)
	{
		cout << "ERROR! PLEASE ENTER 13 DIGIT CNIC NUMBER!" << endl;
		goto CNIC;
	}
	regex cnicRegex(R"(^\d{13}$)");
	if (!regex_match(*CNIC, cnicRegex))
	{
		cout << "ERROR: INVALID CNIC FORMAT. PLEASE ENTER A VALID CNIC." << endl;
		goto CNIC;
	}
	cout << "ENTER YOUR LOGIN ID:" << endl;
	getline(cin, *loginid);
	password:
	cout << "ENTER YOUR PASSWORD:" << endl;
	getline(cin, *password);
	if (password->length() < 8)
	{
		cout << "ERROR: PASSWORD SHOULD CONTAIN MINIMUM 8 CHARACTERS." << endl;
		return;
	}
	bool hasUppercase = false;
	bool hasLowercase = false;
	bool hasDigit = false;
	bool hasSpecialChar = false;
	for (char c : *password)
	{
		if (isupper(c))
			hasUppercase = true;
		else if (islower(c))
			hasLowercase = true;
		else if (isdigit(c))
			hasDigit = true;
		else if (ispunct(c))
			hasSpecialChar = true;
	}
	if (!(hasUppercase && hasLowercase && hasDigit && hasSpecialChar))
	{
		cout << "ERROR: PASSWORD SHOULD CONTAIN ATLEAST ONE UPPER CASE LETTER, ONE LOWER CASE LETTER, ONE DIGIT, AND ONE SPECIAL CHARACTER." << endl;
		goto password;
	}
	//Checks to check fraudulent information
	if (fullname->empty() || phoneno->empty() || CNIC->empty() || loginid->empty() || password->empty())
	{
		cout << "ERROR! PLEASE ENTER ALL THE INFORMATION." << endl;
		goto C;
	}	
	A:
	cout << "ENTER YOUR ESTIMATED WITHDRAWAL LIMIT: " << endl;
	cout << "100,000 PKR\t500,000 PKR:" << endl;
	cin >> *withdrawlimit;

	if (*withdrawlimit == 100000)
	{
		*accounttype = "Bronze";
	}
	else if (*withdrawlimit == 500000)
	{
		*accounttype = "Gold";
	}
	else
	{
		cout << "INCORRECT WITHDRAWAL LIMIT! RE-ENTER:" << endl;
		goto A;
	}
	*accountbalance = 0;
	fstream tempfile1("tempusers.txt", ios::out | ios::app);  // Open temporary users file
	if (tempfile1.is_open())
	{
		tempfile1 << *loginid << endl;  // Store the filename in the temporary users file
		cout << "WAIT FOR SOME TIME FOR THE VERIFICATION OF YOUR ACCOUNT!" << endl;
	}
	else
	{
		cout << "ERROR IN OPENING TEMPORARY USERS FILE!" << endl;
	}
	tempfile1.close();
	fstream tempfile2(*loginid + "temp.txt", ios::out | ios::app);
	if (tempfile2.is_open())
	{
		tempfile2 << *fullname << "," << *phoneno << "," << *adress << "," << *CNIC << "," << *loginid << "," << *password << "," << *withdrawlimit << "," << *accounttype << "," << *accountbalance << endl;
	}
	else
	{
		cout << "ERROR IN OPENING FILE!" << endl;
	}
	tempfile2.close();
}

void UserClient::Login()
{
	string username, password;
	cin.ignore();
	cout << "ENTER USERNAME:" << endl;
	getline(cin, username);
	cout << "ENTER PASSWORD:" << endl;
	getline(cin, password);
	string account = username + ".txt";
	fstream accountfile(account, ios::in);
	if (accountfile.is_open())
	{
		string line;
		getline(accountfile, line);
		accountfile.close();
		stringstream ss(line);
		string Name,Phone, address, CNIC, accountId, accountPassword, drawLimit, accountType, balance;
		getline(ss, Name, ',');
		getline(ss, Phone, ',');
		getline(ss, address, ',');
		getline(ss, CNIC, ',');
		getline(ss, accountId, ',');
		getline(ss, accountPassword, ',');
		getline(ss, drawLimit, ',');
		getline(ss, accountType);
		getline(ss, balance, ',');
		if (accountId == username && accountPassword == password)
		{
			cout << "1. DEPOSIT FUNDS INTO YOUR ACCOUNT" << endl;
			cout << "2. WITHDRAW FUNDS FROM YOUR ACCOUNT" << endl;
			cout << "3. VIEW ACCOUNT BALANCE" << endl;
			cout << "4. VIEW TRANSACTION HISTORY" << endl;
			cout << "5. TRANSFER FUNDS " << endl;
			int OPTION;
			cin >> OPTION;
			if (OPTION == 1)
			{

			}
			else if (OPTION == 2)
			{

			}
			else if (OPTION == 3)
			{

			}
			else if (OPTION == 4)
			{

			}
			else if (OPTION == 5)
			{

			}
			else
			{

			}
		}
	}
	else
	{
		cout << "ACCOUNT DOES NOT EXIST!" << endl;
	}
}
void UserClient::UserClientMenu()
{
	int OPTION;
	cout << "WELCOME TO USER CLIENT PORTAL:" << endl;
	cout << "1. CREATE NEW ACCOUNT!" << endl;
	cout << "2. LOGIN!" << endl;
	cin >> OPTION;
	if (OPTION == 1)
	{
		UserClient* obj1 = new UserClient;
		obj1->CreateAccount();
		delete obj1;

	}
	else if (OPTION == 2)
	{
		UserClient* obj2 = new UserClient;
		obj2->Login();
		delete obj2;
	}

}
class Transaction {
private:
	string type;
	double amount;
	string dateTime;

public:
	Transaction(const string& type, double amount, const string& dateTime)
		: type(type), amount(amount), dateTime(dateTime) {}

	string getType() const {
		return type;
	}

	double getAmount() const {
		return amount;
	}

	string getDateTime() const {
		return dateTime;
	}
};

class CompanyClient
{
private:
	string* companyname;
	string* companyadress;
	string* taxno;
	double* withdrawlimit;
	string* accountid;
	string* accountpassword;
	double* accountbalance;
	string* employeeids;
	string* accounttype;
	vector<Transaction> transactions;
public:
	CompanyClient();
	void CompanyClientMenu();
	void CreateAccount();
	void Login();
	void DepositFunds(string filename);
	void WithdrawFunds(string filename);
	void viewAccountBalance(const string& filename);
	void ViewTransactionHistory(string filename);
	void RequestLoan();
};
CompanyClient::CompanyClient()
{
	companyname = new string("");
	companyadress = new string("");
	taxno = new string("");
	withdrawlimit = new double(0.0);
	accountid = new string("");
	accountpassword = new string("");
	accountbalance = new double(0.0);
	employeeids = new string("");
	accounttype = new string("");
}
void CompanyClient::CreateAccount()
{
	cin.ignore();
	companyname:
	cout << "ENTER COMPANY'S NAME:" << endl;
	getline(cin, *companyname);
	regex companynameRegex(R"(^[A-Za-z\s]+$)");
	if (!regex_match(*companyname, companynameRegex))
	{
		cout << "ERROR: INVALID COMPANY NAME! RE-ENTER:" << endl;
		goto companyname;
	}
	companyadress:
	cout << "ENTER COMPANY'S ADRESS: " << endl;
	getline(cin, *companyadress);
	if (companyadress->empty() || companyadress->length() < 5)
	{
		cout << "ERROR! INVALID COMPANY ADRESS. PLEASE ENTER A VALID ADRESS!" << endl;
		goto companyadress;
	}
	taxno:
	cout << "ENTER COMPANY'S TAX NUMBER:" << endl;
	getline(cin, *taxno);
	regex taxnoRegex(R"(^\d{13}$)");
	if (!regex_match(*taxno, taxnoRegex))
	{
		cout << "ERROR: INVALID TAX NUMBER FORMAT. PLEASE ENTER A VALID TAX NUMBER." << endl;
		goto taxno;
	}
	accountid:
	cout << "ENTER ACCOUNT'S ID:" << endl;
	getline(cin, *accountid);
	accountpassword:
	cout << "ENTER ACCOUNT'S PASSWORD:" << endl;
	getline(cin, *accountpassword);
	if (accountpassword->length() < 8)
	{
		cout << "ERROR: PASSWORD SHOULD CONTAIN MINIMUM 8 CHARACTERS." << endl;
		return;
	}
	bool hasUppercase = false;
	bool hasLowercase = false;
	bool hasDigit = false;
	bool hasSpecialChar = false;
	for (char c : *accountpassword)
	{
		if (isupper(c))
			hasUppercase = true;
		else if (islower(c))
			hasLowercase = true;
		else if (isdigit(c))
			hasDigit = true;
		else if (ispunct(c))
			hasSpecialChar = true;
	}
	if (!(hasUppercase && hasLowercase && hasDigit && hasSpecialChar))
	{
		cout << "ERROR: PASSWORD SHOULD CONTAIN ATLEAST ONE UPPER CASE LETTER, ONE LOWER CASE LETTER, ONE DIGIT, AND ONE SPECIAL CHARACTER." << endl;
		goto accountpassword;
	}
	withdrawlimit:
	cout << "ENTER ESTIMATED WITHDRAWL LIMIT:" << endl;
	cout << "100,000 PKR\t 500,000 PKR\t 20,00,000" << endl;
	cin >> *withdrawlimit;
	if (*withdrawlimit == 100000)
	{
		*accounttype = "BRONZE";
	}
	else if (*withdrawlimit == 500000)
	{
		*accounttype = "GOLD";
	}
	else if (*withdrawlimit == 2000000)
	{
		*accounttype = "BUSINESS";
	}
	*accountbalance = 0;
	fstream companyfile(*accountid + ".txt", ios::out);
	if (companyfile.is_open())
	{
		companyfile << *companyname << "," << *companyadress << "," << *taxno << "," << *accountid << "," << *accountpassword << "," << *withdrawlimit << "," << *accounttype << "," << *accountbalance << endl;
	}
	else
	{
		cout << "ERROR IN OPENING COMPANY CLIENT FILE!" << endl;
	}
	companyfile.close();
	fstream companies("companies.txt", ios::out | ios :: app);
	if (companies.is_open())
	{
		companies << *accountid << ".txt" << endl;
	}
	companies.close();
}
void CompanyClient::Login()
{
	string username, password;
	cin.ignore();
	cout << "ENTER COMPANY'S ACCOUNT ID:" << endl;
	getline(cin, username);
	cout << "ENTER COMPANY'S ACCOUNT PASSWORD:" << endl;
	getline(cin, password);
	string account = username + ".txt";
	fstream accountfile(account, ios::in);
	if (accountfile.is_open())
	{
		string line;
		getline(accountfile, line);
		accountfile.close();
		stringstream ss(line);
		string companyName, address, taxNumber, accountId, accountPassword, drawLimit, accountType;
		getline(ss, companyName, ',');
		getline(ss, address, ',');
		getline(ss, taxNumber, ',');
		getline(ss, accountId, ',');
		getline(ss, accountPassword, ',');
		getline(ss, drawLimit, ',');
		getline(ss, accountType);
		if (accountId == username && accountPassword == password)
		{
			int OPTION;
			cout << "LOGIN SUCCESSFUL!" << endl;
			cout << "SELECT OPTIONS:" << endl;
			cout << "1. DEPOSIT FUNDS IN YOUR ACCOUNT" << endl;
			cout << "2. WITHDRAW FUNDS FROM ACCOUNT" << endl;
			cout << "3. VIEW ACCOUNT BALANCE" << endl;
			cout << "4. VIEW TRANSACTION HISTORY" << endl;
			cout << "5. TRANSFER FUNDS TO USER CLIENT'S ACCOUNT" << endl;
			cout << "6. REQUEST LOAN FROM BANK" << endl;
			cin >> OPTION;
			if (OPTION == 1)
			{
				CompanyClient* opt1 = new CompanyClient;
				opt1->DepositFunds(account);
				delete opt1;
			}
			else if (OPTION == 2)
			{
				CompanyClient* opt2 = new CompanyClient;
				opt2->WithdrawFunds(account);
				delete opt2;
			}
			else if (OPTION == 3)
			{
				CompanyClient* opt3 = new CompanyClient;
				opt3->viewAccountBalance(account);
				delete opt3;
			}
			else if (OPTION == 4)
			{
				CompanyClient* opt4 = new CompanyClient;
				opt4->ViewTransactionHistory(account);
				delete opt4;
			}
			else if (OPTION == 5)
			{

			}
			else if (OPTION == 6)
			{
				CompanyClient* opt6 = new CompanyClient;
				opt6->RequestLoan();
				delete opt6;
			}
			else
			{
				cout << "INVALID OPTION! CHOOSE CORRECT OPTION" << endl;
			}
		}
		else
		{
			cout << "INVALID CREDENTIALS!" << endl;
		}
	}
	else
	{
		cout << "ACCOUNT DOES NOT EXIST!" << endl;
	}
}
void CompanyClient::DepositFunds( string filename) {
	double amount = 0.0;
	cout << "ENTER THE AMOUNT YOU WANT TO DEPOSIT IN ACCOUNT" << endl;
	cin >> amount;

	*accountbalance += amount;

	time_t now = time(nullptr);
	string dateTime = ctime(&now);
	Transaction transaction("Deposit", amount, dateTime);
	transactions.push_back(transaction);

	ofstream transactionFile(filename + "_transactions.txt", ios::app);
	if (!transactionFile.is_open()) {
		cout << "ERROR: UNABLE TO OPEN THE TRANSACTION FILE." << endl;
		return;
	}

	transactionFile << transaction.getType() << "," << transaction.getAmount() << "," << transaction.getDateTime() << endl;
	transactionFile.close();



	cout << "THE FUNDS HAVE BEEN TRANSFERRED TO THE ACCOUNT SUCCESSFULLY!" << endl;
}
void CompanyClient::WithdrawFunds( string filename) {
	double amount = 0.0;
	cout << "ENTER THE AMOUNT YOU WANT TO WITHDRAW FROM ACCOUNT" << endl;
	cin >> amount;

	// Check if withdrawal amount is valid
	//if (amount > *accountbalance) {
	//	cout << "INSUFFICIENT FUNDS IN THE ACCOUNT!" << endl;
	//	return;
	//}

	// Update account balance
	*accountbalance -= amount;

	// Add the transaction to the transaction history
	time_t now = time(nullptr);
	string dateTime = ctime(&now);
	Transaction transaction("Withdraw", amount, dateTime);
	transactions.push_back(transaction);

	// Write the transaction history to a separate file
	ofstream transactionFile(filename + "_transactions.txt", ios::app);
	if (!transactionFile.is_open()) {
		cout << "ERROR: UNABLE TO OPEN THE TRANSACTION FILE." << endl;
		return;
	}

	transactionFile << transaction.getType() << "," << transaction.getAmount() << "," << transaction.getDateTime() << endl;
	transactionFile.close();

	// Update the account file with the new balance
	//
}
void CompanyClient::viewAccountBalance(const string& filename)
{
	ifstream inputFile(filename);
	if (!inputFile.is_open()) {
		cout << "ERROR: Unable to open file." << endl;
		return;
	}

	string line;
	CompanyClient data;
	bool found = false;

	while (getline(inputFile, line)) {
		istringstream iss(line);
		string companyName, companyAddress, taxNo, accountId, accountPassword, withdrawLimit, accountType, accountBalance;

		if (getline(iss, companyName, ',') &&
			getline(iss, companyAddress, ',') &&
			getline(iss, taxNo, ',') &&
			getline(iss, accountId, ',') &&
			getline(iss, accountPassword, ',') &&
			getline(iss, withdrawLimit, ',') &&
			getline(iss, accountType, ',') &&
			getline(iss, accountBalance)) {

			data.companyname = new string(companyName);
			data.companyadress = new string(companyAddress);
			data.taxno = new string(taxNo);
			data.accountid = new string(accountId);
			data.accountpassword = new string(accountPassword);
			data.withdrawlimit = new double(stod(withdrawLimit));
			data.accounttype = new string(accountType);
			data.accountbalance = new double(stod(accountBalance));
			found = true;
			break;  // Assuming only one matching account exists, we can stop reading the file.
		}
	}

	inputFile.close();

	if (found) {
		cout << "Account Balance: " << *data.accountbalance << endl;
	}
	else {
		cout << "Account not found!" << endl;
	}
}
void CompanyClient::ViewTransactionHistory(string filename)
{
	ifstream transactionFile(filename + "_transactions.txt");
	if (!transactionFile.is_open()) {
		cout << "ERROR: Unable to open transaction file." << endl;
		return;
	}

	string line;
	while (getline(transactionFile, line)) {
		cout << line << endl;
	}

	transactionFile.close();
}
void CompanyClient::RequestLoan() {
	double amount;
	cout << "Enter the loan amount you want to request: ";
	cin >> amount;

	// Check if the requested loan amount is valid
	if (amount <= 0) {
		cout << "Invalid loan amount. Please enter a positive value." << endl;
		return;
	}

	// Calculate the interest and total loan amount
	double interestRate = 0.08; // 8%
	double interest = amount * interestRate;
	double totalAmount = amount + interest;

	// Display the loan details
	cout << "Loan Request Details:" << endl;
	cout << "Loan Amount: " << amount << " PKR" << endl;
	cout << "Interest Rate: " << interestRate * 100 << "%" << endl;
	cout << "Total Amount to Repay: " << totalAmount << " PKR" << endl;

	// Prompt the user for confirmation
	char choice;
	cout << "Do you want to proceed with the loan request? (Y/N): ";
	cin >> choice;

	if (toupper(choice) == 'Y') {
		// Process the loan request

		// Update the account balance with the loan amount
		*accountbalance += amount;

		// Add the loan transaction to the transaction history
		time_t now = time(nullptr);
		string dateTime = ctime(&now);
		Transaction transaction("Loan", amount, dateTime);
		transactions.push_back(transaction);
		string filename = *accountid+ "_transactions.txt";
		// Write the transaction history to a separate file
		ofstream transactionFile(filename, ios::app);
		if (!transactionFile.is_open()) {
			cout << "ERROR: Unable to open the transaction file." << endl;
			return;
		}

		transactionFile << transaction.getType() << "," << transaction.getAmount() << "," << transaction.getDateTime() << endl;
		transactionFile.close();

		// Update the account file with the new balance
		ofstream accountFile(*accountid + ".txt", ios::trunc);
		if (!accountFile.is_open()) {
			cout << "ERROR: Unable to open the account file." << endl;
			return;
		}

		accountFile << *companyname << "," << *companyadress << "," << *taxno << "," << *accountid << "," << *accountpassword << "," << *withdrawlimit << "," << *accounttype << "," << *accountbalance << endl;
		accountFile.close();

		cout << "Loan request has been processed successfully." << endl;
	}
	else {
		cout << "Loan request has been canceled." << endl;
	}
}

void CompanyClient::CompanyClientMenu()
{
	int OPTION;
	cout << "WELCOME TO USER CLIENT PORTAL:" << endl;
	cout << "1. CREATE NEW ACCOUNT!" << endl;
	cout << "2. LOGIN!" << endl;
	cin >> OPTION;
	if (OPTION == 1)
	{
		CompanyClient* obj1 = new CompanyClient;
		obj1->CreateAccount();
		delete obj1;

	}
	else if (OPTION == 2)
	{
		CompanyClient* obj2 = new CompanyClient;
		obj2->Login();
		delete obj2;
	}

}
class Employee
{
private:
	string* userid;
	string* password;
public:
	Employee();
	void CreateAccount();
	void Login();
	void ViewClientAccounts();
	void Approve();
	void LoanRequests();
	void ViewTransactionHistory();
	void FreezeAccount();
	void EmployeeMenu();
	void displayMenu();
};
Employee::Employee()
{
	userid = new string("");
	password = new string("");
}
void Employee::Login() 
{


	cout << "Enter your username: ";
	cin >> *userid;
	cout << "Enter your password: ";
	cin >> *password;

	ifstream adminFile("admin.txt");
	if (!adminFile.is_open()) {
		cout << "Error: Failed to open admin file." << endl;
		return;
	}

	string line;
	bool isLoggedIn = false;
	while (getline(adminFile, line)) {
		istringstream iss(line);
		string storedUsername, storedPassword;
		if (getline(iss, storedUsername, ',') && getline(iss, storedPassword)) {
			if (storedUsername == *userid && storedPassword == *password) {
				isLoggedIn = true;
				break;
			}
		}
	}

	adminFile.close();

	if (isLoggedIn) {
		cout << "Login successful." << endl;
		displayMenu();
	}
	else {
		cout << "Invalid username or password. Login failed." << endl;
	}
}
void Employee::Approve()
{
	ifstream tempUsersFile("tempusers.txt");  // Open tempusers file
	ofstream approvedUsersFile("users.txt", ios::out | ios::app);  // Open users.txt file

	if (!tempUsersFile.is_open())
	{
		cout << "ERROR OPENING tempusers.txt!" << endl;
		return;
	}

	if (!approvedUsersFile.is_open())
	{
		cout << "ERROR OPENING users.txt!" << endl;
		tempUsersFile.close();
		return;
	}

	string filename;
	while (getline(tempUsersFile, filename))  // Read each filename from tempusers file
	{
		cout << "Do you want to approve the account for user: " << filename << "? (Y/N): ";
		char choice;
		cin >> choice;

		if (choice == 'Y' || choice == 'y')
		{
			// Move user data from temp file to new user file
			ifstream tempUserFile(filename + "temp.txt");
			ofstream newUserFile(filename + ".txt");
			if (!tempUserFile.is_open())
			{
				cout << "ERROR OPENING TEMPORARY USER FILE!" << endl;
				continue;
			}

			if (!newUserFile.is_open())
			{
				cout << "ERROR OPENING NEW USER FILE!" << endl;
				tempUserFile.close();
				continue;
			}

			approvedUsersFile << filename + ".txt" << endl;  // Store the approved user file name in users.txt

			string line;
			while (getline(tempUserFile, line))  // Copy user data from temp file to new user file
			{
				newUserFile << line << endl;
			}

			tempUserFile.close();
			newUserFile.close();

			if (remove((filename + "temp.txt").c_str()) != 0)  // Delete the temporary user file
			{
				cout << "ERROR DELETING TEMPORARY USER FILE!" << endl;
			}

			// Generate random card number and PIN
			srand(time(0));
			string cardNumber = "";
			for (int i = 0; i < 16; i++)
			{
				int digit = rand() % 10;
				cardNumber += to_string(digit);
			}

			string pin = "";
			for (int i = 0; i < 4; i++)
			{
				int digit = rand() % 10;
				pin += to_string(digit);
			}

			// Store card number and PIN in the user's card file
			ofstream cardFile(filename + "card.txt");
			if (cardFile.is_open())
			{
				cardFile << cardNumber << "," << pin << endl;
				cardFile.close();
			}
			else
			{
				cout << "ERROR OPENING CARD FILE FOR USER: " << filename << endl;
			}
		}
	}

	tempUsersFile.close();
	approvedUsersFile.close();
}
void Employee::displayMenu()
{
	displaymenu:
	int choice = 0;
	cout << endl;
	cout << "Banking Employee Menu:" << endl;
	cout << "1. View all client accounts" << endl;
	cout << "2. Approve/Reject new account applications" << endl;
	cout << "3. Approve/Reject loan requests" << endl;
	cout << "4. View transaction history for a specific account" << endl;
	cout << "5. Freeze or close an account" << endl;
	cin >> choice;

	if (choice == 1)
	{

	}
	else if (choice == 2)
	{
		Employee* opt2 = new Employee;
		opt2->Approve();
		delete opt2;
	}
	else if (choice == 3)
	{

	}
	else if (choice == 4)
	{

	}
	else if (choice == 5)
	{

	}
	else
	{
		cout << "INVALID OPTION! RE-ENTER:" << endl;
		goto displaymenu;
	}
}
void Employee::EmployeeMenu()
{
	menu:
	cout << " SELECT OPTIONS:" << endl;
	cout << "1. LOGIN" << endl;
	int OPTION;
	cin >> OPTION;
	if (OPTION == 1)
	{
		Employee* employee = new Employee;
		employee->Login();
		delete employee;
	}
	else
	{
		cout << "PLEASE SELECT VALID OPTION:" << endl;
		goto menu;
	}
}
//MAIN MENU
void mainmenu()
{
	int OPTION = 0;
	B:
	cout << "ENTER THE TYPE OF ACCOUNT:" << endl;
	cout << "1. USER CLIENT" << endl;
	cout << "2. COMPANY CLIENT" << endl;
	cout << "3. BANK EMPLOYEE" << endl;
	cout << "SELECT OPTION:" << endl;
	cin >> OPTION;
	if (OPTION == 1)
	{
		UserClient* user = new UserClient;
		user->UserClientMenu();
		delete user;
	}
	else if (OPTION == 2)
	{
		CompanyClient* companyclient = new CompanyClient;
		companyclient->CompanyClientMenu();
		delete companyclient;
	}
	else if (OPTION == 3)
	{
		Employee* employee = new Employee;
		employee->EmployeeMenu();
	}
	else
	{
		cout << "PLEASE SELECT VALID OPTION:" << endl;
		goto B;
	}
}
int main()
{
	mainmenu();
	return 0;
}