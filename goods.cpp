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
	cout << "请输入新的商品名称：" << endl;
	cin >> name;
	cout << "请输入新的商品类型：" << endl;
	cin >> category;
	cout << "请输入新的商品单价：" << endl;
	cin >> price;
	cout << "请输入新的商品库存：" << endl;
	cin >> storage;
}
