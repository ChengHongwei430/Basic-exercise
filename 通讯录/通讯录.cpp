
#include<iostream>
using namespace std;

#include<string>
#define MAX 1000//����󲻼ӷֺ�

struct Person //��ϵ�˽ṹ��
{
	string Name;
	int Sex;
	int Age;
	string Phone;
	string Address;
};
struct Address_Books //��ϵ�˽ṹ��
{
	struct Person Person_Array[MAX];
	int Person_Size;
};

//�˵�
void Show_Menu() {
	cout << "����������������������" << endl;
	cout << "��1�������ϵ��" << endl;
	cout << "��2����ʾ��ϵ��" << endl;
	cout << "��3��ɾ����ϵ��" << endl;
	cout << "��4��������ϵ��" << endl;
	cout << "��5���޸���ϵ��" << endl;
	cout << "��6�������ϵ��" << endl;
	cout << "��0���˳�ͨѶ¼" << endl;
	cout << "����������������������" << endl;
}

void Add_Person(Address_Books *ab) {//����������������Ͳ�����

	if (ab->Person_Size == MAX) {//��ʹ���õ���. �����Ҳ�Զ����Ҹĳ���->
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return;
	}
	else {//elseֱ����if����дһ���µķֺ�չ��

		string Name;
		cout << "������������" << endl;
		cin >> Name;
		ab->Person_Array[ab->Person_Size].Name = Name;

		cout << "�������Ա�" << endl;
		cout << "1--��" << endl;
		cout << "2--Ů" << endl;
		int Sex;
		
		while (1) {
			cin >> Sex;
			if (Sex == 1 || Sex == 2) {
				ab->Person_Array[ab->Person_Size].Sex = Sex;
				break;
			}
			else {
				cout << "����������������룡" << endl;
			}
		}
		
		cout << "���������䣺" << endl;
		int Age;
		cin >> Age;
		ab->Person_Array[ab->Person_Size].Age = Age;

		cout << "������绰��" << endl;
		string Phone;
		cin >> Phone;
		ab->Person_Array[ab->Person_Size].Phone = Phone;

		cout << "�������ַ��" << endl;
		string Address;
		cin >> Address;
		ab->Person_Array[ab->Person_Size].Address = Address;

		ab->Person_Size++;
		cout << "��ӳɹ���" << endl;

		system("pause");//��ͣ���棬���������
		system("cls");//����
	}
}
///////////////////////////////////////////////////////////////////////////////////
//void Search_Person(Address_Books *ab,int select) {//���������׺��������
// 
// 
//	cout << "��������" << ab->Person_Array[select].Name << endl;
//	cout << "�Ա𡪡�" << ab->Person_Array[select].Sex << endl;
//	cout << "���䡪��" << ab->Person_Array[select].Age << endl;
//}

void Search_Person(Address_Books* ab, int i) {

	cout << "������" << ab->Person_Array[i].Name << "\t"; //ת�����Ҫ""
	cout << "�Ա�" << (ab->Person_Array[i].Sex == 1 ? "��" : "Ů") << "\t";
	cout << "���䣺" << ab->Person_Array[i].Age << endl;
}

void Show_Person(Address_Books *ab) {//����������������Ͳ�����

	if (ab->Person_Size == 0) {
		cout << "ͨѶ¼Ϊ�գ�" << endl;
	}
	else {
		cout << "������ͨѶ¼�е�������ϵ����Ϣ��" << endl;
		for (int i = 0; i < ab->Person_Size; i++) {
			cout << "(" << i + 1 << ")������" << ab->Person_Array[i].Name << "\t"; //ת�����Ҫ""
			cout << "�Ա�" << (ab->Person_Array[i].Sex ==1?"��":"Ů") << "\t";
			cout << "���䣺" << ab->Person_Array[i].Age << endl;
		}
	}

	///////////////////////////////////////////////////////////////////////////////////////////////
	// ��˼·���ѣ����ɻ�
	//cout << "������ͨѶ¼�е�������ϵ�������б���ѡ����Ҫ��ʾ����ϵ�˱�ţ�" << endl;
	//for (int i = 0; i < ab->person_size; i++) {
	//	cout << i+1 << "����" << ab->person_array[i].name << endl;
	//}
	//int select;
	//while (1) {
	//	cin >> select;
	//	if (select>ab->person_size) {
	//		cout << "����������������룡" << endl;
	//	}
	//	else {
	//		break;
	//	}
	//}
	

	//���ע�ͣ�ctrl K + ctrl C   ȡ����ctrl K + ctrl U
}

int IsExist_Person(Address_Books* ab) {

	string Name;
	cout << "��������ϵ��������" << endl;
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
	Address_Books ab;//����һ��ͨѶ¼����
	ab.Person_Size = 0;//��ʼ��ͨѶ¼����Ա����

	while (1) {

		//�˵�����
		Show_Menu();

		//����ѡ��
		cin >> select ;//cinû��endl

		//ѡ����
		switch (select) {
		case 1:
			Add_Person(&ab); //����ab�ĵ�ַ���Ա���Ϊʵ�ζ�ab�����޸�
			break;//switch��ƥ��ֱ������breakΪֹ���˳�switch
		case 2: {
			Show_Person(&ab); //����ab�ĵ�ַ���Ա���Ϊʵ�ζ�ab�����޸�		
			system("pause");//��ͣ���棬���������
			system("cls");//����
			break;
		}		
		case 3: {//switch�����ϳ�ʱ����Ҫʹ��{}
			int is=IsExist_Person(&ab);
			if (is == -1) {
				cout << "���޴��ˣ�" << endl;
			}
			else {
				Delete_Person(&ab,is);
				cout << "ɾ���ɹ���" << endl;
			}
			system("pause");//��ͣ���棬���������
			system("cls");//����
			break;
		}
		case 4: {//switch�����ϳ�ʱ����Ҫʹ��{}
			int is = IsExist_Person(&ab);
			if (is == -1) {
				cout << "���޴��ˣ�" << endl;
			}
			else {
				Search_Person(&ab, is);
			}
			system("pause");//��ͣ���棬���������
			system("cls");//����
			break;
		}
		case 5: {//switch�����ϳ�ʱ����Ҫʹ��{}
			int is = IsExist_Person(&ab);
			if (is == -1) {
				cout << "���޴��ˣ�" << endl;
			}
			else {
				Search_Person(&ab, is);

				string Name;
				cout << "������������" << endl;
				cin >> Name;
				ab.Person_Array[is].Name = Name;

				cout << "�������Ա�" << endl;
				cout << "1--��" << endl;
				cout << "2--Ů" << endl;
				int Sex;

				while (1) {
					cin >> Sex;
					if (Sex == 1 || Sex == 2) {
						ab.Person_Array[is].Sex = Sex;
						break;
					}
					else {
						cout << "����������������룡" << endl;
					}
				}

				cout << "���������䣺" << endl;
				int Age;
				cin >> Age;
				ab.Person_Array[is].Age = Age;

				cout << "������绰��" << endl;
				string Phone;
				cin >> Phone;
				ab.Person_Array[is].Phone = Phone;

				cout << "�������ַ��" << endl;
				string Address;
				cin >> Address;
				ab.Person_Array[is].Address = Address;

				cout << "�޸ĳɹ���" << endl;
			}
			system("pause");//��ͣ���棬���������
			system("cls");//����
			break;
		}
		case 6:
			ab.Person_Size = 0;
			break;
		case 0:
			cout << "��ӭ�´�ʹ��~~~" << endl;
			system("pause");
			return 0;
			//break;
		default:
			cout << "����������������룡" << endl;
			break;
		}

	}

	system("pause");//��ֹ����һ������
	return 0;
}