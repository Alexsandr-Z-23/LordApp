#include"landlord.h"




////////////////////////////// ������ ������ Tenant (�����) ///////////////////////////

tenant::tenant(wstring n, int aNo) :name(n), aptNumber(aNo)
{}
tenant::~tenant(){}
int tenant::getAptNumber()
{
	return aptNumber;
}

userInterface::userInterface()
{
	ptrTenantList = new tenantList;
	ptrRentRecord = new rentRecord;
	ptrExpenseRecord = new expenseRecord;
}
userInterface::~userInterface()
{
	delete ptrTenantList;
	delete ptrRentRecord;
	delete ptrExpenseRecord;
}
void userInterface::interact()
{
	while (true)
	{
		wcout << L"������� '�' ��� ����� ������, \n"
			<< L"		 '�' ��� ������ �� ������ ������\n"
			<< L"        '�' ��� ������ �� ���������: ";
		ch = getaChar();
		if (ch == L'�')
		{
			wcout << L"������� '�' ��� ���������� ������, \n"
				<< L"		   '�' ��� ������ ������� �����\n"
				<< L"        '�' ��� ������ ���������: ";
			ch = getaChar();
			switch (ch)
			{
			case L'�':
			{
				ptrRentInputScreen = new rentInputScreen(ptrTenantList, ptrRentRecord);
				ptrRentInputScreen->getRent();
				delete ptrRentInputScreen;
				break;
			}
			case L'�':
			{
				ptrTenantInputScreen = new tenantInputScreen(ptrTenantList);
				ptrTenantInputScreen->getTenant();
				delete ptrTenantInputScreen;
				break;
			}
			case L'�':
			{
				ptrExpenseInputScreen = new expenseInputScreen(ptrExpenseRecord);
				ptrExpenseInputScreen->getExpense();
				delete ptrExpenseInputScreen;
				break;
			}
			default:wcout << L"����������� ����� ����� ������\n\n";
				break;
			}
		}
		else if (ch == L'�')
		{
			wcout << L"������� '�' ��� ������ �� ����� ������ �������, \n"
				<< L"		   '�' ��� ������ �� ����� ������� �������� ����,\n"
				<< L"          '�' ��� ������ �� ����� ������ ��������,\n "
				<< L"          '�' ��� ������ �������� ������:  ";

			ch = getaChar();
			switch (ch)
			{
			case L'�':
			{
				ptrTenantList->display();
				break;
			}
			case L'�':
			{
				ptrRentRecord->display();
				break;
			}
			case L'�':
			{
				ptrExpenseRecord->display();
				break;
			}
			case L'�':
			{
				ptrAnnualReport = new annualReport(ptrRentRecord, ptrExpenseRecord);
				ptrAnnualReport->display();
				delete ptrAnnualReport;
				break;
			}

			default:wcout << L"����������� ����� ����� ������\n\n";
				break;
			}
		}
		else if (ch == L'�')
			return;
		else
		{
			wcout << L"����������� �����. ������� ������ '�', '�' ��� '�' \n";
		}
		
	}
}