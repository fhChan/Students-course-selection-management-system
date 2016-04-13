#include<iostream>
#include<string>
#include<fstream>
#define MAX_NUM_OF_STUS 100
#define MAX_NUM_OF_COUS 100
using namespace std;

class student {
private:
	string name;
	int number;
public:
	student() {
		name = "";
		number = 0;
	}

	student(string str, int num) {
		name = str;
		number = num;
	}

	void set(string str, int num) {
		name = str;
		number = num;
	}

	string getname()const {
		return name;
	}

	int getnumber()const {
		return number;
	}
};

class course {
public:
	string name;
	int credit;
	course() {
		name = "";
		credit = 0;
	}

	course(string str) {
		name = str;
		credit = 0;
	}

	course(string str, int n) {
		name = str;
		credit = n;
	}

	void set(string str, int num) {
		name = str;
		credit = num;
	}

	void set(string str) {
		name = str;
		credit = 0;
	}
};

class stu_cou :public student{
public:
	course cou[MAX_NUM_OF_COUS];
	int num_of_cous;
	stu_cou(){
		num_of_cous = 0;
	}

	stu_cou(string str, int num) :student(str, num){
		num_of_cous = 0;
	}

	void add_course(course e) {
		cou[num_of_cous] = e;
		num_of_cous++;
	}

	void remove_course(course e) {
		for (int i = 0; i < num_of_cous; i++)
			if (cou[i].name == e.name) {
				for (int j = i; j < num_of_cous; j++)
					cou[j] = cou[j + 1];
				num_of_cous--;
			}
	}

	void clear() {
		set("", 0);
		for (int i = 0; i < num_of_cous; i++)
			cou[i].set("");
		num_of_cous = 0;
	}
};
/*
struct node {
	student st;
	node *next;
};

class StudentList
{
public:
	node *pHead;
	int count;

	StudentList() {
		pHead = NULL;
		count = 0;
	}

	void Insert(string str, int num)//在链表尾部插入学生信息
	{
		if (count >= MAX_NUM_OF_STUS) {
			cout << "容量达到上限！" << endl;
			return;
		}
		node *p1 = new node;
		p1->st.set(str, num);
		p1->next = NULL;
		node *p;
		p = pHead;
		while (p->next != NULL)
			p = p->next;
		p->next = p1;
		count++;
	}
	bool Delete(int num)//在链表中根据学号删除某学生信息
	{
		node *p;
		p = pHead;
		while (p->next != NULL) {
			if (p->next->st.getnumber() == num) {
				node *p1 = p->next;
				p->next = p->next->next;
				delete p1;
				cout << "The student is deleted successfully!" << endl;
				count--;
				return true;
			}
			p = p->next;
		}
		cout << "The student does not exist!" << endl;
		return false;
	}

	int getcount() {
		return count;
	}
};
*/
class PROGRAM
{
private:
	stu_cou S[MAX_NUM_OF_STUS];
	course C[MAX_NUM_OF_COUS];
	int num_of_stus, num_of_cous;
	int number;

	ifstream in;
	ofstream fout;

public:
	PROGRAM() {
	}

	void display() {
		int number;
		string name;
		course COU;
		char ch;
LOOP:	cout << " 1）学生管理" << endl;
		cout << " 2）课程管理" << endl;
		cout << " 3）选课管理" << endl;
		cout << " 请输入你想要执行的功能的序号（输入其他数字时结束程序）：" << endl;
		while (1) {
			cin >> ch;
			switch (ch) {
			case '1':
				cout << " 1）从文件中读入学生信息" << endl;
				cout << " 2）添加给定信息的学生" << endl;
				cout << " 3）删除给定学号的学生" << endl;
				cout << " 4）按照学号对学生排序" << endl;
				cout << " 5）按照姓名对学生排序" << endl;
				cout << " 6）将操作后的信息列表保存至文件" << endl; 
				cout << " 7）返回上一步" << endl; 

				cin >> ch;
				switch (ch) {
				case'1':Sread();
					break;
				case'2':Sins();
					break;
				case'3':Sdel();
					break;
				case'4':SortByNumber();
					break;
				case'5':SortByName();
					break;
				case'6':Swrite();
					break;
				case'7':goto LOOP;
					break;
				default:exit(0);
				}
				break;
			case'2':
				cout << " 1）从文件中读入课程信息" << endl;
				cout << " 2）添加给定信息的课程" << endl;
				cout << " 3）删除给定课程名的课程" << endl;
				cout << " 4）将操作后的信息列表保存至文件" << endl;
				cout << " 5）返回上一步" << endl;

				cin >> ch;
				switch (ch) {
				case'1':Cread();
					break;
				case'2':Cins();
					break;
				case'3':Cdel();
					break;
				case'4':Cwrite();
					break;
				case'5':goto LOOP;
					break;
				default:exit(0);
				}
				break;
			case'3':
				cout << " 1）指定某个学生选修某门课程" << endl;
				cout << " 2）指定某个学生退选某门课程" << endl;
				cout << " 3）查询某个学生的选修情况" << endl;
				cout << " 4）查询某门课程的全部选修学生" << endl;
				cout << " 5）返回上一步" << endl;

				cin >> ch;
				switch (ch) {
				case'1':cout << " 请输入学生学号与课程名称（以空格隔开）：" << endl;
					cin >> number >> name;
					COU.set(name);
					for (int i = 0; i < num_of_stus; i++) {
						if (S[i].getnumber() == number)
							S[i].add_course(COU);
						break;
					}
					break;
				case'2':SCdel();
					break;
				case'3':cout << " 请输入要查询的学生学号：" << endl;
					cin >> number;
					for (int i = 0; i < num_of_stus; i++) {
						if (S[i].getnumber() == number) {
							if (S[i].num_of_cous == 0) {
								cout << "该学生无选修！" << endl;
								break;
							}
							for (int j = 0; j < S[i].num_of_cous; j++)
								cout << S[i].cou[j].name << "\t";
							cout << endl;
						}
						break;
					}
					break;
				case'4':
					break;
				case'5':goto LOOP;
					break;
				default:exit(0);
				}
				break;
			default:exit(0);
			}
		}
	}

	void Sread() {
		in.open("d:\\学生信息.txt");
		char str[255];
		int count = -1;
		while (in) {
			in.getline(str,255);
			int i = 0, j;
			for (j = i; str[j] != '\t'; j++);
			string name(&str[0], &str[j - 1]);
			number = 0;
			for (i = ++j; str[j] != '\t'&&str[j] != '\n'; j++);
			for (int k = j - 1; k >= i; k--)
				number += number * 10 + str[k] - '0';
			S[++count].set(name, number);
			if (str[j] != '\n') {
				for (i = ++j; str[j] != '\t'&&str[j] != '\n'; j++);
				string Cname(&str[i], &str[j - 1]);
				course *p = new course(Cname); 
				S[count].add_course(*p);
				delete p;
			}
		}
		in.close();
	}

	void Sins() {
		cout << " 请输入姓名学号（以空格隔开）：" << endl;
		string name;
		cin >> name >> number;
		S[num_of_stus++].set(name, number);
	}

	void Sdel() {
		cout << " 请输入学号：" << endl;
		cin >> number;
		for (int i = 0; i < num_of_stus;i++)
			if (S[i].getnumber() == number) {
				S[i].clear();
				S[i].set(S[num_of_stus - 1].getname(), S[num_of_stus - 1].getnumber());
				for (int j = 0; j < S[num_of_stus - 1].num_of_cous; j++)
					S[i].add_course(S[num_of_stus - 1].cou[j]);
				S[--num_of_stus].clear();
			}
	}

	void swap(stu_cou A, stu_cou B) {
		stu_cou T(A.getname(), A.getnumber());
		A.set(B.getname(), B.getnumber());
		B.set(T.getname(), T.getnumber());
		course temp;
		for (int i = 0; i < MAX_NUM_OF_COUS; i++) {
			temp.set(A.cou[i].name);
			A.cou[i].set(B.cou[i].name);
			B.cou[i].set(temp.name);
		}
	}

	void SortByNumber() {
		for (int i = 0; i < num_of_stus; i++)
			for (int j = num_of_stus - 1; j > i; j--)
				if (S[j].getnumber() < S[j - 1].getnumber())
					swap(S[j], S[j - 1]);
	}

	void SortByName() {
		for (int i = 0; i < num_of_stus; i++)
			for (int j = num_of_stus - 1; j > i; j--)
				if (S[j].getname() < S[j - 1].getname())
					swap(S[j], S[j - 1]);
	}

	void Swrite() {
		fout.open("d:\\学生信息（更新）.txt");
		for (int i = 0; i < num_of_stus; i++) {
			fout << S[i].getname() << "\t" << S[i].getnumber();
			for (int j = 0; j < S[i].num_of_cous; j++)
				fout << "\t" << S[i].cou[j].name;
			fout << endl;
		}
		fout.close();
	}

	void Cread() {
		in.open("d:\\课程信息.txt");
		string name;
		num_of_cous = 0;
		while (in) {
			in >> name >> number;
			C[num_of_cous++].set(name, number);
		}
		in.close();
	}

	void Cins() {
		cout << " 请输入课程名以及学分数（以空格隔开）：" << endl;
		string name;
		cin >> name >> number;
		C[num_of_cous++].set(name, number);
	}

	void Cdel() {
		cout << " 请输入要删除的课程名：" << endl;
		string name;
		char *n,*m;
		strncpy(n, name.c_str(), name.length());
		for (int i = 0; i < num_of_cous; i++) {
			strncpy(m, C[i].name.c_str(), C[i].name.length());
			if (strcmp(m, n)) {
				C[i].set(C[num_of_cous - 1].name, C[num_of_cous - 1].credit);
				C[num_of_cous - 1].set("", 0);
				num_of_cous--;
			}
		}
	}

	void Cwrite() {
		fout.open("d:\\课程信息（更新）.txt");
		for (int i = 0; i < num_of_cous; i++)
			fout << C[i].name << "\t" << C[i].credit << endl;
		fout.close();
	}

	void SCdel() {
		cout << " 请输入学生学号与课程名称（以空格隔开）：" << endl;
		string name;
		char *n, *m;
		cin >> number >> name;
		strncpy(n, name.c_str(), name.length());
		for (int i = 0; i < num_of_stus; i++) {
			if (S[i].getnumber() == number)
				for (int j = 0; j < num_of_cous; j++) {
					strncpy(m, S[i].cou[j].name.c_str(), S[i].cou[j].name.length());
					if (strcmp(m, n)) {
						S[i].cou[j].set(S[i].cou[S[i].num_of_cous - 1].name, S[i].cou[S[i].num_of_cous - 1].credit);
						S[i].cou[S[i].num_of_cous - 1].set("", 0);
						S[i].num_of_cous--;
					}
				}
			break;
		}

	}
};

int main() {
	PROGRAM G;
	G.display();
	return 0;
}
