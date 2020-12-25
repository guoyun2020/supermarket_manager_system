//author:���S version:1.0 time:12/21/20
#pragma once
#include<iostream>
#include<string>
#include<ctime>
#include<vector>
#include"goods.h"

/*@�Թ˿ͻ���Ķ���
//����
@ ID					 �˿�ID
@ purchase_list_one_time �����б� 
@ price_one_time	     ���ι�����
//����
@ buy()					 ����
@ ID_generate()			 ���ɹ˿�ID
@ purchase_day_info()    ������Ϣ�굥
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

/*@����������ͨ��Ա�Ķ���
//����
@ ID					 �˿�ID
@ purchase_list_one_time �����б�
@ price_one_time	     ���ι�����
@ name					 ����
@ tel					 �绰
@ score                  ����

//����
@ buy()					 ����9.8�ۿۣ�
@ vip_pro()				 ����Ϊ�߼���Ա
@ purchase_year_info()	 �깺����Ϣ�굥
@ info_change()			 �޸ĸ�����Ϣ
@ price_to_score()       ����ת��
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

/*@��������߼���Ա�Ķ���
//����
@ ID					 �˿�ID
@ purchase_list_one_time �����б�
@ price_one_time	     ���ι�����
@ name					 ����
@ tel					 �绰
@ score                  ����

//����
@ buy()					 ����9.5�ۿۣ�
@ purchase_year_info()	 �깺����Ϣ�굥
@ info_change()			 �޸ĸ�����Ϣ
@ price_to_score()       ����ת��
*/
class client_vip_pro :public client_vip {
public:
	client_vip_pro() { score = 0; }
	void buy(goods&);
	void purchase_day_info();
	void purchase_year_info();
};