#include"goods.h"

void goods::goods_info() {
	
	cout << name <<"     "<< category << "      " << price << "      " << storage << endl;
	cout << " " << endl;
}

void goods::goods_init(string a,string b,double c,int d) {
	name = a;
	category = b;
	price = c;
	storage = d;
}

void goods::change_info() {
	cout << "�������µ���Ʒ���ƣ�" << endl;
	cin >> name;
	cout << "�������µ���Ʒ���ͣ�" << endl;
	cin >> category;
	cout << "�������µ���Ʒ���ۣ�" << endl;
	cin >> price;
	cout << "�������µ���Ʒ��棺" << endl;
	cin >> storage;
}
