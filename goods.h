//author:郭赟 version:1.0 time:12/21/20
#pragma once
#include<iostream>
#include<string>
#include<ctime>
#include<vector>

using namespace std;

/*@对商品基类的定义
//参数
@ name	   商品名称
@ category 商品类型
@ price	   单价
@ storage  库存
@ buy_num  购买数量
//函数
@ total_price() 商品总价
@ goods_info()  商品信息
@ change_info() 修改商品信息
@ add_notify()  库存提醒
*/
class goods {
public:
	double total_price(int num) { return price * num; };
	void goods_info();
	void goods_init(string a, string b, double c, int d);
	void change_info();
	void storage_reduce() { storage--; };
	void add_notify() { if (storage < 10) cout << "该商品库存不足！" << endl; };
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

