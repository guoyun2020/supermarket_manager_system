//author:郭赟 version:1.0 time:12/21/20
#pragma once
#include<iostream>
#include<string>
#include<ctime>
#include<vector>
#include"goods.h"

/*@对顾客基类的定义
//参数
@ ID					 顾客ID
@ purchase_list_one_time 购物列表 
@ price_one_time	     单次购物金额
//函数
@ buy()					 购买
@ ID_generate()			 生成顾客ID
@ purchase_day_info()    购物信息详单
*/
class client {
public:
	client() { goods_num = 0; price_one_time = 0; }
	void buy(goods&);
	void ID_generate();
	void purchase_day_info();
	double get_price_one_time() { return price_one_time; }
	void reset_price_one_time() { price_one_time = 0; purchase_list_one_time.clear(); }
	int goods_num;
	vector<goods> get_list() { return purchase_list_one_time; }
protected:
	string ID;
	vector<goods> purchase_list_one_time;
	double price_one_time;

};

/*@对派生类普通会员的定义
//参数
@ ID					 顾客ID
@ purchase_list_one_time 购物列表
@ price_one_time	     单次购物金额
@ name					 姓名
@ tel					 电话
@ score                  积分

//函数
@ buy()					 购买（9.8折扣）
@ vip_pro()				 升级为高级会员
@ purchase_year_info()	 年购物信息详单
@ info_change()			 修改个人信息
@ price_to_score()       积分转换
*/
class client_vip :public client {
public:
	client_vip() { score = 0; }
	void buy(goods&);
	void ID_generate();
	void purchase_day_info();
	void purchase_year_info();
	void info_init();
	void info_change();
	void price_to_score();
	string get_vip_name() { return vip_name; };
	string get_tel() { return tel; };
	int get_score() { return score; }
	void list_init(vector<goods>a) { purchase_list_one_year = a; }
protected:
	string vip_name;
	string tel;
	int score;
	vector<goods> purchase_list_one_year;
	double price_one_year;
};

/*@对派生类高级会员的定义
//参数
@ ID					 顾客ID
@ purchase_list_one_time 购物列表
@ price_one_time	     单次购物金额
@ name					 姓名
@ tel					 电话
@ score                  积分

//函数
@ buy()					 购买（9.5折扣）
@ purchase_year_info()	 年购物信息详单
@ info_change()			 修改个人信息
@ price_to_score()       积分转换
*/
class client_vip_pro :public client_vip {
public:
	client_vip_pro() { score = 0; }
	void buy(goods&);
	void purchase_day_info();
	void purchase_year_info();
};