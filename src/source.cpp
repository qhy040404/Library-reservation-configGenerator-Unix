#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

int checkIfExists()
{
	//initial
	int exist_user_count = -1;
	const string val = "#";
	string currentData;
	ifstream existData;
	existData.open("config.conf");
	//checkIfExists
	while (getline(existData, currentData));
	{
		string::size_type idx = currentData.find(val);
		if (idx != string::npos)
		{
			exist_user_count++;
		}
	}
	return exist_user_count;
}

void initialize()
{
	system("clear");
	cout << "欢迎来到图书馆自动预约配置生成器" << endl;
}

int main()
{
	cout << "请稍后...";
	system("sleep 1 && clear");
	//checkExistData
	if (checkIfExists() > 0)
	{
		printf("检测到现有配置文件中存在 %d 人数据，是否继续生成？（Y/N）：", checkIfExists());
		char init_choice;
		cin >> init_choice;
		if (init_choice == 'y' || init_choice == 'Y')
		{
			cout << endl << "正在初始化...";
			cout << endl << "旧配置文件会被直接覆盖";
			system("sleep 1");
		}
		else
		{
			exit(0);
		}
	}
	//initialize
	initialize();
	//初始化变量
	string user_id, password, area_name;
	string output_area_name;
	int room_name = 0;
	string seats;
	//初始化其他变量
	const string validateLX("令希");
	const string validateBC("伯川");
	int val1, val2;
	bool success = false;
	bool multi = true;
	int user_count = 0;
	//初始化输出流
	ofstream out;
	out.open("config.conf");
	out << "# config.conf DO NOT DELETE!" << endl;
	while (multi == true)
	{
		user_count++;
		//main
		cout << endl;
		cout << "首先，请输入学号：";
		while (1)
		{
			cin >> user_id;
			if (user_id.size() == 9 || user_id.size() == 11)
			{
				break;
			}
			else
			{
				cout << endl << "学号位数好像不对哦，再输一次吧：";
			}
		}
		cout << endl << "然后输入密码：";
		cin >> password;
		cout << endl << "输入你想去的图书馆（中文）：";
		while (1)
		{
			cin >> area_name;
			val1 = area_name.compare(validateLX);
			val2 = area_name.compare(validateBC);
			if (val1 == 0)
			{
				output_area_name = "LX";
				cout << endl << "想去哪个房间（不支持令希电子阅览室）：";
				while (success == false)
				{
					cin >> room_name;
					int room_map[] = { 201,202,301,302,401,402,501,502,601,602 };
					for (int i = 0; room_map[i] > 0; i++)
					{
						if (room_name == room_map[i])
						{
							success = true;
							break;
						}
					}
					if (success == false)
					{
						cout << endl << "这个图书馆没有这个房间哦，请重新输入：";
					}
				}
				break;
			}
			else if (val2 == 0)
			{
				output_area_name = "BC";
				cout << endl << "想去哪个房间（不支持伯川3楼大厅，伯川电子阅览室）：";
				while (success == false)
				{
					cin >> room_name;
					int room_map[] = { 301,312,401,404,409,501,504,507 };
					for (int j = 0; room_map[j] > 0; j++)
					{
						if (room_name == room_map[j])
						{
							success = true;
							break;
						}
					}
					if (success == false)
					{
						cout << endl << "这个图书馆没有这个房间哦，请重新输入：";
					}
				}
				break;
			}
			else
			{
				cout << endl << "图书馆名字输错啦，请重新输入：";
			}
		}
		cout << endl << "好的，基础信息设置完成" << endl;
		system("sleep 1");
		cout << endl << "接下来是期望座位（可连续输入，以-隔开，不足3位的座位号需用0补足）：";
		cin >> seats;
		cout << endl << "座位输入完毕" << endl;
		system("sleep 1");
		while (1)
		{
			cout << endl << "是否需要邮件提醒？(Y/N)：";
			char ifMail;
			cin >> ifMail;
			if (ifMail == 'y' || ifMail == 'Y')
			{
				string mail_user, mail_pass;
				cout << endl << endl << "邮件会由自己发送至自己" << endl;
				cout << "请输入邮箱地址（目前只支持网易普邮及QQ邮箱）：";
				cin >> mail_user;
				cout << "请输入授权码（请在各邮箱smtp设置中获取授权码）：";
				cin >> mail_pass;
				system("clear");
				cout << "所有数据输入完毕，正在生成当前用户的配置文件，请稍后..." << endl;
				out << "#" << user_count << endl;
				out << user_id.c_str() << " " << password.c_str() << " " << output_area_name.c_str() << " " << room_name << endl;
				out << seats.c_str() << endl;
				out << mail_user.c_str() << " " << mail_pass.c_str();
				break;
			}
			else if (ifMail == 'n' || ifMail == 'N')
			{
				system("clear");
				cout << "所有数据输入完毕，正在生成当前用户的配置文件，请稍后..." << endl;
				out << "#" << user_count << endl;
				out << user_id.c_str() << " " << password.c_str() << " " << output_area_name.c_str() << " " << room_name << endl;
				out << seats.c_str();
				break;
			}
			else
			{
				cout << "输入错误" << endl;
			}
		}
		// 是否多人
		while (1)
		{
			system("sleep 2");
			cout << endl;
			printf("当前已输入 %d 个用户数据\n", user_count);
			cout << "是否继续？(Y/N):";
			char multiVal;
			cin >> multiVal;
			if (multiVal == 'y' || multiVal == 'Y')
			{
				cout << endl << "正在初始化..." << endl;
				success = false;
				out << endl;
				system("sleep 1 && clear");
				break;
			}
			else if (multiVal == 'n' || multiVal == 'N')
			{
				multi = false;
				break;
			}
			else
			{
				cout << "输入错误" << endl;
			}
		}
	}
	out.close();
	system("clear");
	cout << "配置文件生成完毕！" << endl;
	cout << "程序将于三秒后关闭";
	system("sleep 3");
	return 0;
}