#include "Bank.h"



Bank::Bank()
{
	this->name_ = "";   //string �ַ��������Ը�ֵΪNULL;
	this->account_ = "";
	this->money_ = 0;
}

Bank::Bank(string name, string account, double money)
{
	this->name_ = name;
	this->account_ = account;
	this->money_ = money;
}


Bank::~Bank()
{
}

void Bank::take_money(double money)
{
	cout << "ȡ��" << money << "Ԫ" << endl;
	this->money_ -= money;
	cout << "���Ϊ" << this->money_ << "Ԫ" << endl;
}

void Bank::show()
{
	cout << this->name_ << " " << this-> account_ << " " << this->money_ << endl;
}

void Bank::save_money(double money)
{
	cout << "�����" << money << "Ԫ" << endl;
	this->money_ += money;
	cout << "���Ϊ" << this->money_ << "Ԫ" << endl;
}
