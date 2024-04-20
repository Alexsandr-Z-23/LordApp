#include"landlord.h"




////////////////////////////// Методы класса Tenant (жилец) ///////////////////////////

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
		wcout << L"Введите 'д' для ввода данных, \n"
			<< L"		 'о' для вывода на экранн отчета\n"
			<< L"        'в' для выхода из программы: ";
		ch = getaChar();
		if (ch == L'д')
		{
			wcout << L"Введите 'ж' для добавления жильца, \n"
				<< L"		   'а' для записи аредной платы\n"
				<< L"        'р' для записи рассходов: ";
			ch = getaChar();
			switch (ch)
			{
			case L'а':
			{
				ptrRentInputScreen = new rentInputScreen(ptrTenantList, ptrRentRecord);
				ptrRentInputScreen->getRent();
				delete ptrRentInputScreen;
				break;
			}
			case L'ж':
			{
				ptrTenantInputScreen = new tenantInputScreen(ptrTenantList);
				ptrTenantInputScreen->getTenant();
				delete ptrTenantInputScreen;
				break;
			}
			case L'р':
			{
				ptrExpenseInputScreen = new expenseInputScreen(ptrExpenseRecord);
				ptrExpenseInputScreen->getExpense();
				delete ptrExpenseInputScreen;
				break;
			}
			default:wcout << L"Неизвестная опция ввода данных\n\n";
				break;
			}
		}
		else if (ch == L'о')
		{
			wcout << L"Введите 'ж' для вывода на экран списка жильцов, \n"
				<< L"		   'а' для вывода на экран тадлицы арендных плат,\n"
				<< L"          'р' для вывода на экран списка расходов,\n "
				<< L"          'г' для вывода годового отчета:  ";

			ch = getaChar();
			switch (ch)
			{
			case L'ж':
			{
				ptrTenantList->display();
				break;
			}
			case L'а':
			{
				ptrRentRecord->display();
				break;
			}
			case L'р':
			{
				ptrExpenseRecord->display();
				break;
			}
			case L'г':
			{
				ptrAnnualReport = new annualReport(ptrRentRecord, ptrExpenseRecord);
				ptrAnnualReport->display();
				delete ptrAnnualReport;
				break;
			}

			default:wcout << L"Неизвестная опция ввода данных\n\n";
				break;
			}
		}
		else if (ch == L'в')
			return;
		else
		{
			wcout << L"Неизвестная опция. Нажмите только 'д', 'о' или 'в' \n";
		}
		
	}
}