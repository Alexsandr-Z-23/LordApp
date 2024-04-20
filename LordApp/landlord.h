#include <iostream>
#include <vector>    // ��� ���������� vector
#include <set>       // ��� ���������� set
#include <string>    // ��� ������ wstring
#include <algorithm> // ��� ��������� sort
#include <numeric>   // ��� ��������� accumulate
#include <iomanip>   // ��� ������������ setw
using namespace std;

//////////////////// ���������� ������� ////////////////////////////////////////
void getaLine(wstring& inStr); // ��������� ������ ������
wchar_t getaChar();            // ��������� �������

//////////////////// ����� tenant (�����) //////////////////////////////////////
class tenant
{
private:
	wstring name;  // ��� � ������� ������
	int aptNumber; // ����� �������� ������

	// ����� ����� ���� ���� � �������������� ����������� � ������
	// (������� � �.�.)

public:
	tenant(wstring n, int aNo);
	~tenant();
	int getAptNumber();

	// ��� ��������� (��������� set): ������� ���������
	friend bool operator< (const tenant&, const tenant&);

	friend bool operator== (const tenant&, const tenant&);

	// ��� ������ ������� ������ � �������� �����
	friend wostream& operator<< (wostream&, const tenant&);
};

//////////////////// ����� compareTenants //////////////////////////////////////
class compareTenants // �������������� ������ � ���������� ������� ������ tenant
{
public:
	bool operator() (tenant*, tenant*) const;
};

//////////////////// ����� tenantList //////////////////////////////////////////
class tenantList
{
private:
	// ��������� ���������� �� ������� ������ tenant (�����)
	set<tenant*, compareTenants> setPtrsTens;
	set<tenant*, compareTenants>::iterator iter;
public:
	~tenantList();              // ���������� (����������� ������, ������� �����
	// ��� �������� ��������� (������� ������ tenant))
	void insertTenant(tenant*); // �������� ������ �� ��������� (������ �������)
	int getAptNo(wstring);      // ���������� ����� �������� �� ����� ������
	void display();             // ����� ������ ������� �� �����
};

//////////////////// ����� tenantInputScreen ///////////////////////////////////
class tenantInputScreen
{
private:
	tenantList* ptrTenantList;
	wstring tName;
	int aptNo;
public:
	tenantInputScreen(tenantList* ptrTL) : ptrTenantList(ptrTL)
	{ }
	void getTenant();
};

//////////////////// ����� rentRow /////////////////////////////////////////////
// ���� ������ ������� �������� ����: ����� �������� � 12 �������� ����
class rentRow
{
private:
	int aptNo;
	float rent[12];
public:
	rentRow(int);             // ����������� � ����� ����������
	void setRent(int, float); // �������� ����� �� ���� �����
	float getSumOfRow();      // ���������� ����� ���� �� ����� ������

	// ��� ��������� (��������� set): ������� ���������
	friend bool operator< (const rentRow&, const rentRow&);

	friend bool operator== (const rentRow&, const rentRow&);

	// ��� ������ ������� ������ � �������� �����
	friend wostream& operator<< (wostream&, const rentRow&);
};

//////////////////// ����� compareRows /////////////////////////////////////////
class compareRows // �������������� ������ � ���������� ������� ������ rentRow
{
public:
	bool operator() (rentRow*, rentRow*) const;
};

//////////////////// ����� rentRecord //////////////////////////////////////////
class rentRecord // ������� �������� ����
{
private:
	// ��������� ���������� �� ������� ������ rentRow (�� ������ �� ������)
	set<rentRow*, compareRows> setPtrsRR;
	set<rentRow*, compareRows>::iterator iter;
public:
	~rentRecord();
	void insertRent(int, int, float);
	void display();
	float getSumOfRents(); // ���������� ����� ���� �������� ���� � �������
};

//////////////////// ����� rentInputScreen /////////////////////////////////////
class rentInputScreen
{
private:
	tenantList* ptrTenantList;
	rentRecord* ptrRentRecord;

	wstring renterName;
	float rentPaid;
	int month;
	int aptNo;
public:
	rentInputScreen(tenantList* ptrTL, rentRecord* ptrRR) :
		ptrTenantList(ptrTL), ptrRentRecord(ptrRR)
	{ }
	void getRent(); // �������� �������� ����� ������ ������ �� ���� �����
};

//////////////////// ����� expense /////////////////////////////////////////////
class expense // ������
{
public:                      // public � ��� �� ������! � ���������� � ���������
	int month, day;          // ���� ������� ������ ����� �������������� �������
	wstring category, payee; // �������� ��������
	float amount;

	expense()
	{ }
	expense(int m, int d, wstring c, wstring p, float a) :
		month(m), day(d), category(c), payee(p), amount(a)
	{ }

	// ��� ��������� (��������� set): ������� ���������
	friend bool operator< (const expense&, const expense&);

	friend bool operator== (const expense&, const expense&);

	// ��� ������ ������� ������ � �������� �����
	friend wostream& operator<< (wostream&, const expense&);
};

//////////////////// ����� compareDates ////////////////////////////////////////
class compareDates // �������������� ������ � ���������� ������� �� ����
{
public:
	bool operator() (expense*, expense*) const;
};

//////////////////// ����� compareCategories ///////////////////////////////////
class compareCategories // �������������� ������ � ���������� ������� �� ���������
{
public:
	bool operator() (expense*, expense*) const;
};

//////////////////// ����� expenseRecord ///////////////////////////////////////
class expenseRecord // ������ ��������
{
private:
	// ������ ���������� �� ������� ������ expense (������)
	vector<expense*> vectPtrsExpenses;
	vector<expense*>::iterator iter;
public:
	~expenseRecord();
	void insertExp(expense*);
	void display();
	float displaySummary(); // ������������ ������� annualReport (������� �����)
};

//////////////////// ����� expenseInputScreen //////////////////////////////////
class expenseInputScreen
{
private:
	expenseRecord* ptrExpenseRecord;
public:
	expenseInputScreen(expenseRecord*);
	void getExpense();
};

//////////////////// ����� annualReport ////////////////////////////////////////
class annualReport // ������� �����
{
private:
	rentRecord* ptrRR;
	expenseRecord* ptrER;
	float expenses, rents;
public:
	annualReport(rentRecord*, expenseRecord*);
	void display();
};

//////////////////// ����� userInterface ///////////////////////////////////////
class userInterface // ��������� ��� ������ ������������ � ����������
{
private:
	tenantList* ptrTenantList;
	tenantInputScreen* ptrTenantInputScreen;
	rentRecord* ptrRentRecord;
	rentInputScreen* ptrRentInputScreen;
	expenseRecord* ptrExpenseRecord;
	expenseInputScreen* ptrExpenseInputScreen;
	annualReport* ptrAnnualReport;
	wchar_t ch;
public:
	userInterface();
	~userInterface();
	void interact();
};