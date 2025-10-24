#include "headers.h"

int main() {
	users User;
	while (1) {
		cout << "======= 选课系统 =======" << endl;
		cout << "1.学生登录\n2.教师登录\n3.管理员登录\n0.退出系统\n" << endl;
		int choice;
		cin >> choice;
		if (choice == 0) {
			cout << "欢迎下次使用！" << endl;
			return 0;
		}
		if (login(0, choice, &User)) {
			cout<<"登录成功！"<<endl;
		}
	}

return 0;
}