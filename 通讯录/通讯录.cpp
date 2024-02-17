
#include<iostream>
using namespace std;

#include<string>
#define MAX 1000//定义后不加分号

struct Person //联系人结构体
{
	string Name;
	int Sex;
	int Age;
	string Phone;
	string Address;
};
struct Address_Books //联系人结构体
{
	struct Person Person_Array[MAX];
	int Person_Size;
};

//菜单
void Show_Menu() {
	cout << "———————————" << endl;
	cout << "（1）添加联系人" << endl;
	cout << "（2）显示联系人" << endl;
	cout << "（3）删除联系人" << endl;
	cout << "（4）查找联系人" << endl;
	cout << "（5）修改联系人" << endl;
	cout << "（6）清空联系人" << endl;
	cout << "（0）退出通讯录" << endl;
	cout << "———————————" << endl;
}

void Add_Person(Address_Books *ab) {//函数输入变量的类型不能忘

	if (ab->Person_Size == MAX) {//即使我用的是. ，软件也自动给我改成了->
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else {//else直接在if下面写一个新的分号展开

		string Name;
		cout << "请输入姓名：" << endl;
		cin >> Name;
		ab->Person_Array[ab->Person_Size].Name = Name;

		cout << "请输入性别：" << endl;
		cout << "1--男" << endl;
		cout << "2--女" << endl;
		int Sex;
		
		while (1) {
			cin >> Sex;
			if (Sex == 1 || Sex == 2) {
				ab->Person_Array[ab->Person_Size].Sex = Sex;
				break;
			}
			else {
				cout << "输入错误，请重新输入！" << endl;
			}
		}
		
		cout << "请输入年龄：" << endl;
		int Age;
		cin >> Age;
		ab->Person_Array[ab->Person_Size].Age = Age;

		cout << "请输入电话：" << endl;
		string Phone;
		cin >> Phone;
		ab->Person_Array[ab->Person_Size].Phone = Phone;

		cout << "请输入地址：" << endl;
		string Address;
		cin >> Address;
		ab->Person_Array[ab->Person_Size].Address = Address;

		ab->Person_Size++;
		cout << "添加成功！" << endl;

		system("pause");//暂停界面，请继续输入
		system("cls");//清屏
	}
}
///////////////////////////////////////////////////////////////////////////////////
//void Search_Person(Address_Books *ab,int select) {//函数里面套函数会出错
// 
// 
//	cout << "姓名——" << ab->Person_Array[select].Name << endl;
//	cout << "性别——" << ab->Person_Array[select].Sex << endl;
//	cout << "年龄——" << ab->Person_Array[select].Age << endl;
//}

void Search_Person(Address_Books* ab, int i) {

	cout << "姓名：" << ab->Person_Array[i].Name << "\t"; //转义符需要""
	cout << "性别：" << (ab->Person_Array[i].Sex == 1 ? "男" : "女") << "\t";
	cout << "年龄：" << ab->Person_Array[i].Age << endl;
}

void Show_Person(Address_Books *ab) {//函数输入变量的类型不能忘

	if (ab->Person_Size == 0) {
		cout << "通讯录为空！" << endl;
	}
	else {
		cout << "下面是通讯录中的所有联系人信息：" << endl;
		for (int i = 0; i < ab->Person_Size; i++) {
			cout << "(" << i + 1 << ")姓名：" << ab->Person_Array[i].Name << "\t"; //转义符需要""
			cout << "性别：" << (ab->Person_Array[i].Sex ==1?"男":"女") << "\t";
			cout << "年龄：" << ab->Person_Array[i].Age << endl;
		}
	}

	///////////////////////////////////////////////////////////////////////////////////////////////
	// 新思路而已，无疑惑
	//cout << "下面是通讯录中的所有联系人姓名列表，请选择你要显示的联系人编号：" << endl;
	//for (int i = 0; i < ab->person_size; i++) {
	//	cout << i+1 << "——" << ab->person_array[i].name << endl;
	//}
	//int select;
	//while (1) {
	//	cin >> select;
	//	if (select>ab->person_size) {
	//		cout << "输入错误，请重新输入！" << endl;
	//	}
	//	else {
	//		break;
	//	}
	//}
	

	//快捷注释：ctrl K + ctrl C   取消：ctrl K + ctrl U
}

int IsExist_Person(Address_Books* ab) {

	string Name;
	cout << "请输入联系人姓名：" << endl;
	cin >> Name;
	for (int i = 0; i < ab->Person_Size; i++) {
		if (ab->Person_Array[i].Name == Name) {
			return i;
		}
	}
	return -1;
}

void Delete_Person(Address_Books* ab,int isnum) {

	for (int i = isnum+1; i < ab->Person_Size; i++) {
		ab->Person_Array[i - 1] = ab->Person_Array[i];
	}
	ab->Person_Size--;

}

int main() {

	int select = 0;
	Address_Books ab;//定义一个通讯录变量
	ab.Person_Size = 0;//初始化通讯录中人员数量

	while (1) {

		//菜单调用
		Show_Menu();

		//输入选项
		cin >> select ;//cin没有endl

		//选择功能
		switch (select) {
		case 1:
			Add_Person(&ab); //传入ab的地址，以便作为实参对ab进行修改
			break;//switch的匹配直到遇到break为止，退出switch
		case 2: {
			Show_Person(&ab); //传入ab的地址，以便作为实参对ab进行修改		
			system("pause");//暂停界面，请继续输入
			system("cls");//清屏
			break;
		}		
		case 3: {//switch的语句较长时，需要使用{}
			int is=IsExist_Person(&ab);
			if (is == -1) {
				cout << "查无此人！" << endl;
			}
			else {
				Delete_Person(&ab,is);
				cout << "删除成功！" << endl;
			}
			system("pause");//暂停界面，请继续输入
			system("cls");//清屏
			break;
		}
		case 4: {//switch的语句较长时，需要使用{}
			int is = IsExist_Person(&ab);
			if (is == -1) {
				cout << "查无此人！" << endl;
			}
			else {
				Search_Person(&ab, is);
			}
			system("pause");//暂停界面，请继续输入
			system("cls");//清屏
			break;
		}
		case 5: {//switch的语句较长时，需要使用{}
			int is = IsExist_Person(&ab);
			if (is == -1) {
				cout << "查无此人！" << endl;
			}
			else {
				Search_Person(&ab, is);

				string Name;
				cout << "请输入姓名：" << endl;
				cin >> Name;
				ab.Person_Array[is].Name = Name;

				cout << "请输入性别：" << endl;
				cout << "1--男" << endl;
				cout << "2--女" << endl;
				int Sex;

				while (1) {
					cin >> Sex;
					if (Sex == 1 || Sex == 2) {
						ab.Person_Array[is].Sex = Sex;
						break;
					}
					else {
						cout << "输入错误，请重新输入！" << endl;
					}
				}

				cout << "请输入年龄：" << endl;
				int Age;
				cin >> Age;
				ab.Person_Array[is].Age = Age;

				cout << "请输入电话：" << endl;
				string Phone;
				cin >> Phone;
				ab.Person_Array[is].Phone = Phone;

				cout << "请输入地址：" << endl;
				string Address;
				cin >> Address;
				ab.Person_Array[is].Address = Address;

				cout << "修改成功！" << endl;
			}
			system("pause");//暂停界面，请继续输入
			system("cls");//清屏
			break;
		}
		case 6:
			ab.Person_Size = 0;
			break;
		case 0:
			cout << "欢迎下次使用~~~" << endl;
			system("pause");
			return 0;
			//break;
		default:
			cout << "输入错误，请重新输入！" << endl;
			break;
		}

	}

	system("pause");//防止界面一闪而过
	return 0;
}