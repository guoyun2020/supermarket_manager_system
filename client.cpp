#include<vector>
#include"goods.h"
#include"client.h"
#define random(x) (rand()%x)

void client::buy(goods&a) {
	int num;
	bool can_buy = true;
	while (true) {
		cout << "请输入购买数量：" << endl;
		cin >> num;
		if (num > a.get_storage()) {
			can_buy = false;
			cout << "购买数超过库存上限，请重新输入！" << endl;
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
	cout << "顾客代码：" << ID <<"  "<<"折扣：0"<< endl;
	cout << " " << endl;
	cout << "商品" << "       " << "类别" << "      " << "数量" << "      " << "单价" << endl;
	cout << " " << endl;
	for (int s = 0; s < goods_num; s++) {
		cout << purchase_list_one_time[s].get_name()<< "       "<< purchase_list_one_time[s].get_category()<<"       "<< purchase_list_one_time[s].buy_num<<"       "<< purchase_list_one_time[s].get_price()<<endl;
	}
	cout << " " << endl;
	cout << "总价：" << price_one_time << "元" << endl;
}

void client_vip::purchase_day_info() {
	cout << "顾客代码：" << ID << "  " << "折扣：0.98" << endl;
	cout << " " << endl;
	cout << "商品" << "       " << "类别" << "      " << "数量" << "      " << "单价" << endl;
	cout << " " << endl;
	for (int s = 0; s < goods_num; s++) {
		cout << purchase_list_one_time[s].get_name() << "       " << purchase_list_one_time[s].get_category() << "       " << purchase_list_one_time[s].buy_num << "       " << purchase_list_one_time[s].get_price() << endl;
	}
	cout << " " << endl;
	cout << "总价：" << price_one_time << "元" << endl;
	cout << "积分：" << score << endl;
}

void client_vip::buy(goods&a) {
	int num;
	cout << "请输入购买数量：" << endl;
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
	cout << "请输入会员姓名：" << endl;
	cin >> vip_name;
	cout << "请输入会员电话：" << endl;
	cin >> tel;
}

void client_vip::info_change(){
	cout << "请输入修改后的会员姓名：" << endl;
	cin >> vip_name;
	cout << "请输入修改后的会员电话：" << endl;
	cin >> tel;
}

void client_vip::price_to_score() {
	score += price_one_time;
}


void client_vip::purchase_year_info() {
	cout << "顾客代码：" << ID << "  " << "折扣：0.95" << endl;
	cout << " " << endl;
	cout << "商品" << "       " << "类别" << "      " << "数量" << "      " << "单价" << endl;
	cout << " " << endl;
	for (int s = 0; s < goods_num; s++) {
		cout << client_vip::purchase_list_one_year[s].get_name() << "       " << client_vip::purchase_list_one_year[s].get_category() << "       " << client_vip::purchase_list_one_year[s].buy_num << "       " << client_vip::purchase_list_one_year[s].get_price() << endl;
	}
	cout << " " << endl;
	cout << "总价：" << client_vip::price_one_year << "元" << endl;
	cout << "积分：" << client_vip::score << endl;
}

void client_vip_pro::buy(goods&a) {
	int num;
	cout << "请输入购买数量：" << endl;
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
	cout << "顾客代码：" << ID << "  " << "折扣：0.95" << endl;
	cout << " " << endl;
	cout << "商品" << "       " << "类别" << "      " << "数量" << "      " << "单价" << endl;
	cout << " " << endl;
	for (int s = 0; s < goods_num; s++) {
		cout << purchase_list_one_time[s].get_name() << "       " << purchase_list_one_time[s].get_category() << "       " << purchase_list_one_time[s].buy_num << "       " << purchase_list_one_time[s].get_price() << endl;
	}
	cout << " " << endl;
	cout << "总价：" << price_one_time << "元"<<endl;
	cout << "积分：" << score << endl;
}

void client_vip_pro::purchase_year_info() {
	cout << "顾客代码：" << ID << "  " << "折扣：0.95" << endl;
	cout << " " << endl;
	cout << "商品" << "       " << "类别" << "      " << "数量" << "      " << "单价" << endl;
	cout << " " << endl;
	for (int s = 0; s < goods_num; s++) {
		cout << client_vip_pro::purchase_list_one_year[s].get_name() << "       " << client_vip_pro::purchase_list_one_year[s].get_category() << "       " << client_vip_pro::purchase_list_one_year[s].buy_num << "       " << client_vip_pro::purchase_list_one_year[s].get_price() << endl;
	}
	cout << " " << endl;
	cout << "总价：" << client_vip_pro::price_one_year << "元" << endl;
	cout << "积分：" << client_vip_pro::score << endl;
}