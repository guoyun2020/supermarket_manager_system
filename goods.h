//author:���S version:1.0 time:12/21/20
#pragma once
#include<iostream>
#include<string>
#include<ctime>
#include<vector>

using namespace std;

/*@����Ʒ����Ķ���
//����
@ name	   ��Ʒ����
@ category ��Ʒ����
@ price	   ����
@ storage  ���
@ buy_num  ��������
//����
@ total_price() ��Ʒ�ܼ�
@ goods_info()  ��Ʒ��Ϣ
@ change_info() �޸���Ʒ��Ϣ
@ add_notify()  �������
*/
class goods {
public:
	double total_price(int num) { return price * num; };
	void goods_info();
	void goods_init(string a, string b, double c, int d);
	void change_info();
	void storage_reduce() { storage--; };
	void add_notify() { if (storage < 10) cout << "����Ʒ��治�㣡" << endl; };
	int buy_num;
	int get_storage() { return storage; };
	string get_name() { return name; };
	string get_category() { return category; };
	double get_price() {return price; };
private:
	string name;
	string category;
	double price;
	int storage;
};

