//author:郭赟 version:1.0 time:12/21/20
#include"client.h"
#include"goods.h"

void Title() {
	system("CLS");
	cout << "				*****************************************" << endl;
	cout << "				*              超市管理系统             *" << endl;
	cout << "				* author:郭赟 version:1.5 time:12/22/20 *" << endl;
	cout << "				*           版权所有，禁止抄袭！        *" << endl;
	cout << "				*****************************************" << endl;
	cout << " " << endl;
}

int main() {
	//商品库导入
	vector<goods> goods_lib;
	goods apple;
	apple.goods_init("苹果", "水果", 3.5, 50);
	goods_lib.push_back(apple);
	goods banana;
	banana.goods_init("香蕉", "水果", 5.5, 50);
	goods_lib.push_back(banana);
	goods bread;
	bread.goods_init("面包", "食物", 10.5, 50);
	goods_lib.push_back(bread);
	goods chocolate;
	chocolate.goods_init("可可", "食物", 15.5, 50);
	goods_lib.push_back(chocolate);
	goods laptop;
	laptop.goods_init("电脑", "电器", 5000, 50);
	goods_lib.push_back(laptop);
	
	client c1;
	client_vip v1;
	client_vip_pro p1;

	//主菜单
	while (true) {
		bool manage=true;
		Title();
		cout << "----主菜单----" << endl;
		cout << " " << endl;
		cout << "1.购物大厅" << endl;
		cout << "2.店铺管理" << endl;
		cout << "3.退出系统" << endl;
		int option1;
		cin >> option1;
		while (option1==1) {
			Title();
			cout << "----购物大厅入口----" << endl;
			cout << " " << endl;
			cout << "1.普通顾客入口" << endl;
			cout << "2.普通会员入口" << endl;
			cout << "3.高级会员入口" << endl;
			cout << "4.返回主菜单" << endl;
			int option2;
			cin >> option2;
			while (option2 == 1) {
				c1.ID_generate();
				Title();
				cout << "----普通顾客菜单----" << endl;
				cout << " " << endl;
				cout << "1.购物" << endl;
				cout << "2.结算" << endl;
				cout << "3.离开" << endl;
				int option3;
				cin >> option3;
				while (option3 == 1) {
					Title();
					c1.reset_price_one_time();
					cout << "商品名称" << " " << "商品类型" << " " << "商品单价" << " " << "商品库存" << endl;
					for (int i = 0; i < goods_lib.size(); i++) {
						goods_lib[i].goods_info();
					}

					cout << "请输入购买的商品名称：" << endl;
					string buy_goods;
					cin >> buy_goods;
					int error_num=0;
					for (int m = 0; m < goods_lib.size(); m++) {
						if (buy_goods == goods_lib[m].get_name()) {
							c1.buy(goods_lib[m]);
						}
						else {
							error_num++;
						}
					}
					if (error_num == goods_lib.size()) {
						cout << "输入有误，请重试！" << endl;
						system("pause");
						continue;
					}
					
					cout << "是否继续购买？(Y/N)" << endl;
					string option4;
					cin >> option4;
					while (option4 == "y" || option4 == "Y") {
						Title();
						cout << "商品名称" << " " << "商品类型" << " " << "商品单价" << " " << "商品库存" << endl;
						for (int i = 0; i < goods_lib.size(); i++) {
							goods_lib[i].goods_info();
						}

						cout << "请输入购买的商品名称：" << endl;
						string buy_goods;
						cin >> buy_goods;
						int error_num = 0;
						for (int m = 0; m < goods_lib.size(); m++) {
							if (buy_goods == goods_lib[m].get_name()) {
								c1.buy(goods_lib[m]);
							}
							else {
								error_num++;
							}
						}
						if (error_num == goods_lib.size()) {
							cout << "输入有误，请重试！" << endl;
							system("pause");
							continue;
						}
						else {
							option3 = 2;
							break;
						}
					}
					if (option4 == "n" || option4 == "N") {
						option3 = 2;
						break;
					}

				}
				while (option3 == 2) {
					Title();
					if (c1.get_price_one_time() == 0) {
						cout << "购物车空空如也，即将返回主菜单..." << endl;
						system("pause");
						break;
					}
					c1.purchase_day_info();
					system("pause");
					if (c1.get_price_one_time() >= 1000 && c1.get_price_one_time() < 2000) {
						Title();
						cout << "单次消费满1000,升级成为普通会员!" << endl;
						v1.info_init();
						v1.list_init(c1.get_list());
						Title();
						cout << "升级完成!" << endl;
						system("pause");
					}
					if (c1.get_price_one_time() >= 2000) {
						Title();
						cout << "单次消费满2000,升级成为高级会员!" << endl;
						p1.info_init();
						p1.list_init(c1.get_list());
						Title();
						cout << "升级完成!" << endl;
						system("pause");
					}
					break;
				}

				while (option3 == 3) {
					Title();
					cout << "欢迎下次光临！" << endl;
					system("pause");
					break;
				}
				break;
			}
			while (option2 == 2) {
				v1.ID_generate();
				Title();
				cout << "----普通会员菜单----" << endl;
				cout << " " << endl;
				cout << "1.购物" << endl;
				cout << "2.结算" << endl;
				cout << "3.会员信息变更" << endl;
				cout << "4.查看年购物详单" << endl;
				cout << "5.离开" << endl;
				int option5;
				cin >> option5;
				while (option5 == 1) {//购物
					Title();
					v1.reset_price_one_time();
					cout << "商品名称" << " " << "商品类型" << " " << "商品单价" << " " << "商品库存" << endl;
					for (int i = 0; i < goods_lib.size(); i++) {
						goods_lib[i].goods_info();
					}

					cout << "请输入购买的商品名称：" << endl;
					string buy_goods;
					cin >> buy_goods;
					int error_num1 = 0;
					for (int m = 0; m < goods_lib.size(); m++) {
						if (buy_goods == goods_lib[m].get_name()) {
							v1.buy(goods_lib[m]);
						}
						else {
							error_num1++;
						}
					}
					if (error_num1 == goods_lib.size()) {
						cout << "输入有误，请重试！" << endl;
						system("pause");
						continue;
					}
					cout << "是否继续购买？(Y/N)" << endl;
					string option6;
					cin >> option6;
					while(option6 == "y" || option6 == "Y") {
						Title();
						cout << "商品名称" << " " << "商品类型" << " " << "商品单价" << " " << "商品库存" << endl;
						for (int i = 0; i < goods_lib.size(); i++) {
							goods_lib[i].goods_info();
						}

						cout << "请输入购买的商品名称：" << endl;
						string buy_goods;
						cin >> buy_goods;
						int error_num1 = 0;
						for (int m = 0; m < goods_lib.size(); m++) {
							if (buy_goods == goods_lib[m].get_name()) {
								v1.buy(goods_lib[m]);
							}
							else {
								error_num1++;
							}
						}
						if (error_num1 == goods_lib.size()) {
							cout << "输入有误，请重试！" << endl;
							system("pause");
							continue;
						}
						else { option5 = 2; break; }
						
					}
					if (option6 == "n" || option6 == "N") {
						option5 = 2;
						break;
					}
					

				}
				while (option5 == 2) {//结算
					Title();
					if (v1.get_price_one_time() == 0) {
						cout << "购物车空空如也，即将返回主菜单..." << endl;
						system("pause");
						break;
					}
					v1.price_to_score();
					v1.purchase_day_info();
					system("pause");
					if (v1.get_price_one_time() >= 1000) {
						Title();
						cout << "单次消费满1000,升级成为高级会员!" << endl;
						p1.info_init();
						p1.list_init(v1.get_list());
						Title();
						cout << "升级完成!" << endl;
						system("pause");
					}
					break;
				}
				while (option5 == 3) {//会员信息变更
					Title();
					v1.info_change();
					cout << "信息变更完成！" << endl;
					system("pause");
					break;
				}
				while (option5 == 4) {//查看年购物详单
					Title();
					v1.purchase_year_info();
					system("pause");
					break;
				}
				while (option5 == 5) {//退出
					Title();
					cout << "欢迎下次光临！" << endl;
					system("pause");
					break;
				}
				break;
			}
			while (option2 == 3) {
				p1.ID_generate();
				Title();
				cout << "----高级会员菜单----" << endl;
				cout << " " << endl;
				cout << "1.购物" << endl;
				cout << "2.结算" << endl;
				cout << "3.会员信息变更" << endl;
				cout << "4.查看年购物详单" << endl;
				cout << "5.离开" << endl;
				int option7;
				cin >> option7;
				while (option7 == 1) {//购物
					Title();
					p1.reset_price_one_time();
					cout << "商品名称" << " " << "商品类型" << " " << "商品单价" << " " << "商品库存" << endl;
					for (int i = 0; i < goods_lib.size(); i++) {
						goods_lib[i].goods_info();
					}

					cout << "请输入购买的商品名称：" << endl;
					string buy_goods;
					cin >> buy_goods;
					int error_num1 = 0;
					for (int m = 0; m < goods_lib.size(); m++) {
						if (buy_goods == goods_lib[m].get_name()) {
							p1.buy(goods_lib[m]);
						}
						else {
							error_num1++;
						}
					}
					if (error_num1 == goods_lib.size()) {
						cout << "输入有误，请重试！" << endl;
						system("pause");
						continue;
					}
					cout << "是否继续购买？(Y/N)" << endl;
					string option8;
					cin >> option8;
					while(option8 == "y" || option8 == "Y") {
						Title();
						cout << "商品名称" << " " << "商品类型" << " " << "商品单价" << " " << "商品库存" << endl;
						for (int i = 0; i < goods_lib.size(); i++) {
							goods_lib[i].goods_info();
						}

						cout << "请输入购买的商品名称：" << endl;
						string buy_goods;
						cin >> buy_goods;
						int error_num1 = 0;
						for (int m = 0; m < goods_lib.size(); m++) {
							if (buy_goods == goods_lib[m].get_name()) {
								p1.buy(goods_lib[m]);
							}
							else {
								error_num1++;
							}
						}
						if (error_num1 == goods_lib.size()) {
							cout << "输入有误，请重试！" << endl;
							system("pause");
							continue;
						}
						else {
							option7 = 2;
							break;
						}
					}
					if (option8 == "n" || option8 == "N") {
						option7 = 2;
						break;
					}
					
				}
				while (option7 == 2) {//结算
					Title();
					if (p1.get_price_one_time() == 0) {
						cout << "购物车空空如也，即将返回主菜单..." << endl;
						system("pause");
						break;
					}
					p1.price_to_score();
					p1.purchase_day_info();
					system("pause");
					break;
				}
				while (option7 == 3) {//会员信息变更
					Title();
					p1.info_change();
					cout << "信息变更完成！" << endl;
					system("pause");
					break;
				}
				while (option7 == 4) {//查看年购物详单
					Title();
					p1.purchase_year_info();
					system("pause");
					break;
				}
				while (option7 == 5) {//退出
					Title();
					cout << "欢迎下次光临！" << endl;
					system("pause");
					break;
				}
				break;
			}
			if (option2 == 4) { break; }
			

		}
		while(option1==2&&manage){//店铺管理
			Title();
			cout << "----店铺管理----" << endl;
			cout << " " << endl;
			cout << "1.商品管理" << endl;
			cout << "2.会员管理（待开发）" << endl;
			cout << "3.数据统计（待开发）" << endl;
			cout << "4.返回主菜单" << endl;
			int option7;
			bool log_in = true;
			cin >> option7;
			while (option7 == 1 && log_in) {
				Title();
				cout << "1.增加商品" << endl;
				cout << "2.删除商品" << endl;
				cout << "3.查看商品状态" << endl;
				cout << "4.更改商品状态" << endl;
				cout << "5.返回上级" << endl;
				int option8;
				cin >> option8;
				while (option8 == 1) {
					Title();
					string new_name,new_category;
					double new_price;
					int new_storage;
					cout << "请输入新商品：名称  类别  单价  库存" << endl;
					cin >> new_name >>new_category>>new_price>>new_storage;
					goods new_goods;
					new_goods.goods_init(new_name, new_category, new_price, new_storage);
					goods_lib.push_back(new_goods);
					Title();
					cout << "商品名称" << " " << "商品类型" << " " << "商品单价" << " " << "商品库存" << endl;
					cout << " " << endl;
					new_goods.goods_info();
					cout << "添加成功" << endl;
					system("pause");
					break;
				}
				while (option8 == 2) {
					Title();
					int goods_num = 0;
					cout << "商品名称" << " " << "商品类型" << " " << "商品单价" << " " << "商品库存" << endl;
					cout << " " << endl;
					for (int q = 0; q < goods_lib.size();q++) {
						cout << "商品序号：" << goods_num << endl;
						goods_lib[q].goods_info();
						goods_num++;
					}
					cout << " " << endl;
					cout << "请输入删除商品的序号" << endl;
					int remove_num;
					cin >> remove_num;
					goods_lib.erase(goods_lib.begin() + remove_num);
					Title();
					cout << "删除成功！" << endl;
					system("pause");
					break;
				}
				while (option8 == 3) {
					Title();
					cout << "商品名称" << " " << "商品类型" << " " << "商品单价" << " " << "商品库存" << endl;
					cout << " " << endl;
					for (int q = 0; q < goods_lib.size(); q++) {
						goods_lib[q].goods_info();
					}
					system("pause");
					break;
				}
				while (option8 == 4) {
					Title();
					int goods_num = 0;
					cout << "商品名称" << " " << "商品类型" << " " << "商品单价" << " " << "商品库存" << endl;
					cout << " " << endl;
					for (int q = 0; q < goods_lib.size(); q++) {
						cout << "商品序号：" << goods_num << endl;
						goods_lib[q].goods_info();
						goods_num++;
					}
					cout << " " << endl;
					cout << "请输入删除商品的序号" << endl;
					int change_num;
					cin >> change_num;
					Title();
					goods_lib[change_num].change_info();
					Title();
					cout << "商品名称" << " " << "商品类型" << " " << "商品单价" << " " << "商品库存" << endl;
					goods_lib[change_num].goods_info();
					system("pause");
					break;
				}
				while (option8 == 5) {
					log_in = false;
					break;
				}
			}
			while (option7 == 2) { Title(); cout << "开发中..." << endl; system("pause");  break; }
			while (option7 == 3) { Title(); cout << "开发中..." << endl; system("pause");  break; }
			while (option7 == 4) { manage = false; break; }
			
		}
		while (option1 == 3) {
			Title();
			cout << "谢谢使用！" << endl;
			system("pause");
			return 0;
		}
	}
	return 0;
}