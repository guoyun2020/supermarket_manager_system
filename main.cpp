//author:���S version:1.0 time:12/21/20
#include"client.h"
#include"goods.h"

void Title() {
	system("CLS");
	cout << "				*****************************************" << endl;
	cout << "				*              ���й���ϵͳ             *" << endl;
	cout << "				* author:���S version:1.5 time:12/22/20 *" << endl;
	cout << "				*           ��Ȩ���У���ֹ��Ϯ��        *" << endl;
	cout << "				*****************************************" << endl;
	cout << " " << endl;
}

int main() {
	//��Ʒ�⵼��
	vector<goods> goods_lib;
	goods apple;
	apple.goods_init("ƻ��", "ˮ��", 3.5, 50);
	goods_lib.push_back(apple);
	goods banana;
	banana.goods_init("�㽶", "ˮ��", 5.5, 50);
	goods_lib.push_back(banana);
	goods bread;
	bread.goods_init("���", "ʳ��", 10.5, 50);
	goods_lib.push_back(bread);
	goods chocolate;
	chocolate.goods_init("�ɿ�", "ʳ��", 15.5, 50);
	goods_lib.push_back(chocolate);
	goods laptop;
	laptop.goods_init("����", "����", 5000, 50);
	goods_lib.push_back(laptop);
	
	client c1;
	client_vip v1;
	client_vip_pro p1;

	//���˵�
	while (true) {
		bool manage=true;
		Title();
		cout << "----���˵�----" << endl;
		cout << " " << endl;
		cout << "1.�������" << endl;
		cout << "2.���̹���" << endl;
		cout << "3.�˳�ϵͳ" << endl;
		int option1;
		cin >> option1;
		while (option1==1) {
			Title();
			cout << "----����������----" << endl;
			cout << " " << endl;
			cout << "1.��ͨ�˿����" << endl;
			cout << "2.��ͨ��Ա���" << endl;
			cout << "3.�߼���Ա���" << endl;
			cout << "4.�������˵�" << endl;
			int option2;
			cin >> option2;
			while (option2 == 1) {
				c1.ID_generate();
				Title();
				cout << "----��ͨ�˿Ͳ˵�----" << endl;
				cout << " " << endl;
				cout << "1.����" << endl;
				cout << "2.����" << endl;
				cout << "3.�뿪" << endl;
				int option3;
				cin >> option3;
				while (option3 == 1) {
					Title();
					c1.reset_price_one_time();
					cout << "��Ʒ����" << " " << "��Ʒ����" << " " << "��Ʒ����" << " " << "��Ʒ���" << endl;
					for (int i = 0; i < goods_lib.size(); i++) {
						goods_lib[i].goods_info();
					}

					cout << "�����빺�����Ʒ���ƣ�" << endl;
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
						cout << "�������������ԣ�" << endl;
						system("pause");
						continue;
					}
					
					cout << "�Ƿ��������(Y/N)" << endl;
					string option4;
					cin >> option4;
					while (option4 == "y" || option4 == "Y") {
						Title();
						cout << "��Ʒ����" << " " << "��Ʒ����" << " " << "��Ʒ����" << " " << "��Ʒ���" << endl;
						for (int i = 0; i < goods_lib.size(); i++) {
							goods_lib[i].goods_info();
						}

						cout << "�����빺�����Ʒ���ƣ�" << endl;
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
							cout << "�������������ԣ�" << endl;
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
						cout << "���ﳵ�տ���Ҳ�������������˵�..." << endl;
						system("pause");
						break;
					}
					c1.purchase_day_info();
					system("pause");
					if (c1.get_price_one_time() >= 1000 && c1.get_price_one_time() < 2000) {
						Title();
						cout << "����������1000,������Ϊ��ͨ��Ա!" << endl;
						v1.info_init();
						v1.list_init(c1.get_list());
						Title();
						cout << "�������!" << endl;
						system("pause");
					}
					if (c1.get_price_one_time() >= 2000) {
						Title();
						cout << "����������2000,������Ϊ�߼���Ա!" << endl;
						p1.info_init();
						p1.list_init(c1.get_list());
						Title();
						cout << "�������!" << endl;
						system("pause");
					}
					break;
				}

				while (option3 == 3) {
					Title();
					cout << "��ӭ�´ι��٣�" << endl;
					system("pause");
					break;
				}
				break;
			}
			while (option2 == 2) {
				v1.ID_generate();
				Title();
				cout << "----��ͨ��Ա�˵�----" << endl;
				cout << " " << endl;
				cout << "1.����" << endl;
				cout << "2.����" << endl;
				cout << "3.��Ա��Ϣ���" << endl;
				cout << "4.�鿴�깺���굥" << endl;
				cout << "5.�뿪" << endl;
				int option5;
				cin >> option5;
				while (option5 == 1) {//����
					Title();
					v1.reset_price_one_time();
					cout << "��Ʒ����" << " " << "��Ʒ����" << " " << "��Ʒ����" << " " << "��Ʒ���" << endl;
					for (int i = 0; i < goods_lib.size(); i++) {
						goods_lib[i].goods_info();
					}

					cout << "�����빺�����Ʒ���ƣ�" << endl;
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
						cout << "�������������ԣ�" << endl;
						system("pause");
						continue;
					}
					cout << "�Ƿ��������(Y/N)" << endl;
					string option6;
					cin >> option6;
					while(option6 == "y" || option6 == "Y") {
						Title();
						cout << "��Ʒ����" << " " << "��Ʒ����" << " " << "��Ʒ����" << " " << "��Ʒ���" << endl;
						for (int i = 0; i < goods_lib.size(); i++) {
							goods_lib[i].goods_info();
						}

						cout << "�����빺�����Ʒ���ƣ�" << endl;
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
							cout << "�������������ԣ�" << endl;
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
				while (option5 == 2) {//����
					Title();
					if (v1.get_price_one_time() == 0) {
						cout << "���ﳵ�տ���Ҳ�������������˵�..." << endl;
						system("pause");
						break;
					}
					v1.price_to_score();
					v1.purchase_day_info();
					system("pause");
					if (v1.get_price_one_time() >= 1000) {
						Title();
						cout << "����������1000,������Ϊ�߼���Ա!" << endl;
						p1.info_init();
						p1.list_init(v1.get_list());
						Title();
						cout << "�������!" << endl;
						system("pause");
					}
					break;
				}
				while (option5 == 3) {//��Ա��Ϣ���
					Title();
					v1.info_change();
					cout << "��Ϣ�����ɣ�" << endl;
					system("pause");
					break;
				}
				while (option5 == 4) {//�鿴�깺���굥
					Title();
					v1.purchase_year_info();
					system("pause");
					break;
				}
				while (option5 == 5) {//�˳�
					Title();
					cout << "��ӭ�´ι��٣�" << endl;
					system("pause");
					break;
				}
				break;
			}
			while (option2 == 3) {
				p1.ID_generate();
				Title();
				cout << "----�߼���Ա�˵�----" << endl;
				cout << " " << endl;
				cout << "1.����" << endl;
				cout << "2.����" << endl;
				cout << "3.��Ա��Ϣ���" << endl;
				cout << "4.�鿴�깺���굥" << endl;
				cout << "5.�뿪" << endl;
				int option7;
				cin >> option7;
				while (option7 == 1) {//����
					Title();
					p1.reset_price_one_time();
					cout << "��Ʒ����" << " " << "��Ʒ����" << " " << "��Ʒ����" << " " << "��Ʒ���" << endl;
					for (int i = 0; i < goods_lib.size(); i++) {
						goods_lib[i].goods_info();
					}

					cout << "�����빺�����Ʒ���ƣ�" << endl;
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
						cout << "�������������ԣ�" << endl;
						system("pause");
						continue;
					}
					cout << "�Ƿ��������(Y/N)" << endl;
					string option8;
					cin >> option8;
					while(option8 == "y" || option8 == "Y") {
						Title();
						cout << "��Ʒ����" << " " << "��Ʒ����" << " " << "��Ʒ����" << " " << "��Ʒ���" << endl;
						for (int i = 0; i < goods_lib.size(); i++) {
							goods_lib[i].goods_info();
						}

						cout << "�����빺�����Ʒ���ƣ�" << endl;
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
							cout << "�������������ԣ�" << endl;
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
				while (option7 == 2) {//����
					Title();
					if (p1.get_price_one_time() == 0) {
						cout << "���ﳵ�տ���Ҳ�������������˵�..." << endl;
						system("pause");
						break;
					}
					p1.price_to_score();
					p1.purchase_day_info();
					system("pause");
					break;
				}
				while (option7 == 3) {//��Ա��Ϣ���
					Title();
					p1.info_change();
					cout << "��Ϣ�����ɣ�" << endl;
					system("pause");
					break;
				}
				while (option7 == 4) {//�鿴�깺���굥
					Title();
					p1.purchase_year_info();
					system("pause");
					break;
				}
				while (option7 == 5) {//�˳�
					Title();
					cout << "��ӭ�´ι��٣�" << endl;
					system("pause");
					break;
				}
				break;
			}
			if (option2 == 4) { break; }
			

		}
		while(option1==2&&manage){//���̹���
			Title();
			cout << "----���̹���----" << endl;
			cout << " " << endl;
			cout << "1.��Ʒ����" << endl;
			cout << "2.��Ա������������" << endl;
			cout << "3.����ͳ�ƣ���������" << endl;
			cout << "4.�������˵�" << endl;
			int option7;
			bool log_in = true;
			cin >> option7;
			while (option7 == 1 && log_in) {
				Title();
				cout << "1.������Ʒ" << endl;
				cout << "2.ɾ����Ʒ" << endl;
				cout << "3.�鿴��Ʒ״̬" << endl;
				cout << "4.������Ʒ״̬" << endl;
				cout << "5.�����ϼ�" << endl;
				int option8;
				cin >> option8;
				while (option8 == 1) {
					Title();
					string new_name,new_category;
					double new_price;
					int new_storage;
					cout << "����������Ʒ������  ���  ����  ���" << endl;
					cin >> new_name >>new_category>>new_price>>new_storage;
					goods new_goods;
					new_goods.goods_init(new_name, new_category, new_price, new_storage);
					goods_lib.push_back(new_goods);
					Title();
					cout << "��Ʒ����" << " " << "��Ʒ����" << " " << "��Ʒ����" << " " << "��Ʒ���" << endl;
					cout << " " << endl;
					new_goods.goods_info();
					cout << "��ӳɹ�" << endl;
					system("pause");
					break;
				}
				while (option8 == 2) {
					Title();
					int goods_num = 0;
					cout << "��Ʒ����" << " " << "��Ʒ����" << " " << "��Ʒ����" << " " << "��Ʒ���" << endl;
					cout << " " << endl;
					for (int q = 0; q < goods_lib.size();q++) {
						cout << "��Ʒ��ţ�" << goods_num << endl;
						goods_lib[q].goods_info();
						goods_num++;
					}
					cout << " " << endl;
					cout << "������ɾ����Ʒ�����" << endl;
					int remove_num;
					cin >> remove_num;
					goods_lib.erase(goods_lib.begin() + remove_num);
					Title();
					cout << "ɾ���ɹ���" << endl;
					system("pause");
					break;
				}
				while (option8 == 3) {
					Title();
					cout << "��Ʒ����" << " " << "��Ʒ����" << " " << "��Ʒ����" << " " << "��Ʒ���" << endl;
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
					cout << "��Ʒ����" << " " << "��Ʒ����" << " " << "��Ʒ����" << " " << "��Ʒ���" << endl;
					cout << " " << endl;
					for (int q = 0; q < goods_lib.size(); q++) {
						cout << "��Ʒ��ţ�" << goods_num << endl;
						goods_lib[q].goods_info();
						goods_num++;
					}
					cout << " " << endl;
					cout << "������ɾ����Ʒ�����" << endl;
					int change_num;
					cin >> change_num;
					Title();
					goods_lib[change_num].change_info();
					Title();
					cout << "��Ʒ����" << " " << "��Ʒ����" << " " << "��Ʒ����" << " " << "��Ʒ���" << endl;
					goods_lib[change_num].goods_info();
					system("pause");
					break;
				}
				while (option8 == 5) {
					log_in = false;
					break;
				}
			}
			while (option7 == 2) { Title(); cout << "������..." << endl; system("pause");  break; }
			while (option7 == 3) { Title(); cout << "������..." << endl; system("pause");  break; }
			while (option7 == 4) { manage = false; break; }
			
		}
		while (option1 == 3) {
			Title();
			cout << "ллʹ�ã�" << endl;
			system("pause");
			return 0;
		}
	}
	return 0;
}