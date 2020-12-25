#include<vector>
#include"goods.h"
#include"client.h"
#define random(x) (rand()%x)

void client::buy(goods&a) {
	int num;
	bool can_buy = true;
	while (true) {
		cout << "�����빺��������" << endl;
		cin >> num;
		if (num > a.get_storage()) {
			can_buy = false;
			cout << "����������������ޣ����������룡" << endl;
			continue;
		}
		else {
			can_buy = true;
			break;
		}
	}
	if (can_buy) {
		for (int i = 0; i < num; i++) {
			a.storage_reduce();
		}
		a.buy_num = num;
		price_one_time += a.total_price(num);
		purchase_list_one_time.push_back(a);
		goods_num++;
	}
}

void client::ID_generate() {
	ID = to_string(random(1000));
}

void client_vip::ID_generate() {
	ID = "8888"+to_string(random(1000));
}

void client::purchase_day_info() {
	cout << "�˿ʹ��룺" << ID <<"  "<<"�ۿۣ�0"<< endl;
	cout << " " << endl;
	cout << "��Ʒ" << "       " << "���" << "      " << "����" << "      " << "����" << endl;
	cout << " " << endl;
	for (int s = 0; s < goods_num; s++) {
		cout << purchase_list_one_time[s].get_name()<< "       "<< purchase_list_one_time[s].get_category()<<"       "<< purchase_list_one_time[s].buy_num<<"       "<< purchase_list_one_time[s].get_price()<<endl;
	}
	cout << " " << endl;
	cout << "�ܼۣ�" << price_one_time << "Ԫ" << endl;
}

void client_vip::purchase_day_info() {
	cout << "�˿ʹ��룺" << ID << "  " << "�ۿۣ�0.98" << endl;
	cout << " " << endl;
	cout << "��Ʒ" << "       " << "���" << "      " << "����" << "      " << "����" << endl;
	cout << " " << endl;
	for (int s = 0; s < goods_num; s++) {
		cout << purchase_list_one_time[s].get_name() << "       " << purchase_list_one_time[s].get_category() << "       " << purchase_list_one_time[s].buy_num << "       " << purchase_list_one_time[s].get_price() << endl;
	}
	cout << " " << endl;
	cout << "�ܼۣ�" << price_one_time << "Ԫ" << endl;
	cout << "���֣�" << score << endl;
}

void client_vip::buy(goods&a) {
	int num;
	cout << "�����빺��������" << endl;
	cin >> num;
	for (int i = 0; i < num; i++) {
		a.storage_reduce();
	}
	a.buy_num = num;
	price_one_time += a.total_price(num)*0.98;
	price_one_year += a.total_price(num)*0.98;
	purchase_list_one_time.push_back(a);
	purchase_list_one_year.push_back(a);
	goods_num++;
}

void client_vip::info_init() {
	cout << "�������Ա������" << endl;
	cin >> vip_name;
	cout << "�������Ա�绰��" << endl;
	cin >> tel;
}

void client_vip::info_change(){
	cout << "�������޸ĺ�Ļ�Ա������" << endl;
	cin >> vip_name;
	cout << "�������޸ĺ�Ļ�Ա�绰��" << endl;
	cin >> tel;
}

void client_vip::price_to_score() {
	score += price_one_time;
}


void client_vip::purchase_year_info() {
	cout << "�˿ʹ��룺" << ID << "  " << "�ۿۣ�0.95" << endl;
	cout << " " << endl;
	cout << "��Ʒ" << "       " << "���" << "      " << "����" << "      " << "����" << endl;
	cout << " " << endl;
	for (int s = 0; s < goods_num; s++) {
		cout << client_vip::purchase_list_one_year[s].get_name() << "       " << client_vip::purchase_list_one_year[s].get_category() << "       " << client_vip::purchase_list_one_year[s].buy_num << "       " << client_vip::purchase_list_one_year[s].get_price() << endl;
	}
	cout << " " << endl;
	cout << "�ܼۣ�" << client_vip::price_one_year << "Ԫ" << endl;
	cout << "���֣�" << client_vip::score << endl;
}

void client_vip_pro::buy(goods&a) {
	int num;
	cout << "�����빺��������" << endl;
	cin >> num;
	for (int i = 0; i < num; i++) {
		a.storage_reduce();
	}
	a.buy_num = num;
	price_one_time += a.total_price(num)*0.95;
	price_one_year += a.total_price(num)*0.95;
	purchase_list_one_time.push_back(a);
	purchase_list_one_year.push_back(a);
	goods_num++;
}

void client_vip_pro::purchase_day_info() {
	cout << "�˿ʹ��룺" << ID << "  " << "�ۿۣ�0.95" << endl;
	cout << " " << endl;
	cout << "��Ʒ" << "       " << "���" << "      " << "����" << "      " << "����" << endl;
	cout << " " << endl;
	for (int s = 0; s < goods_num; s++) {
		cout << purchase_list_one_time[s].get_name() << "       " << purchase_list_one_time[s].get_category() << "       " << purchase_list_one_time[s].buy_num << "       " << purchase_list_one_time[s].get_price() << endl;
	}
	cout << " " << endl;
	cout << "�ܼۣ�" << price_one_time << "Ԫ"<<endl;
	cout << "���֣�" << score << endl;
}

void client_vip_pro::purchase_year_info() {
	cout << "�˿ʹ��룺" << ID << "  " << "�ۿۣ�0.95" << endl;
	cout << " " << endl;
	cout << "��Ʒ" << "       " << "���" << "      " << "����" << "      " << "����" << endl;
	cout << " " << endl;
	for (int s = 0; s < goods_num; s++) {
		cout << client_vip_pro::purchase_list_one_year[s].get_name() << "       " << client_vip_pro::purchase_list_one_year[s].get_category() << "       " << client_vip_pro::purchase_list_one_year[s].buy_num << "       " << client_vip_pro::purchase_list_one_year[s].get_price() << endl;
	}
	cout << " " << endl;
	cout << "�ܼۣ�" << client_vip_pro::price_one_year << "Ԫ" << endl;
	cout << "���֣�" << client_vip_pro::score << endl;
}