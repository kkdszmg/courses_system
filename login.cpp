//#include "headers.h"
//#include <conio.h>
//vector<users> readUserData() {  
//    vector<users> user;  
//    ifstream file("users.txt");  
//
//    if (!file.is_open()) {  
//        cout << "错误：无法打开文件 " << "users.txt" << endl;  
//        return user;  
//    }  
//
//    string line;  
//    while (getline(file, line)) {  
//        // 跳过空行和注释行（以#开头的行）  
//        if (line.empty() || line[0] == '#') {  
//            continue;  
//        }  
//
//        stringstream ss(line);  
//        string Account, Password, Role;  
//
//        // 假设文件格式：用户名 密码（用空格或制表符分隔）  
//        if (ss >> Account >> Password >> Role) {  
//            user.emplace_back(users{Account, Password, Role});  // 修复错误：正确使用结构体初始化  
//        }  
//    }  
//
//    file.close();  
//    return user;  
//}
//string inputAccount() {
//	string acc;
//	cin >> acc;
//	return acc;
//}
//
//
//string getPasswordHidden(const string& prompt) {
//	string password;
//	char ch;
//
//	cout << prompt;
//
//	// 逐个字符读取，显示星号
//	while ((ch = _getch()) != '\r') {  // 回车键结束输入
//		if (ch == '\b') {  // 退格键处理
//			if (!password.empty()) {
//				cout << "\b \b";  // 回退一个字符，用空格覆盖，再回退
//				password.pop_back();
//			}
//		}
//		else if (ch == 27) {  // ESC键，清空输入
//			while (!password.empty()) {
//				cout << "\b \b";
//				password.pop_back();
//			}
//		}
//		else {
//			cout << '*';  // 显示星号
//			password.push_back(ch);
//		}
//	}
//	cout << endl;  // 输入完成后换行
//	return password;
//}
///*bool password(int role, users* user) {
//	string inputPassword = getPasswordHidden();
//	user->password = inputPassword;
//	return 1;
//}*/
///*
//int getUserRole(const vector<users>& userList, const string& account) {
//	for (const auto& user : userList) {
//		if (user.account == account) {
//			return stoi(user.role);
//		}
//	}
//	return -1;
//}*/
//
//int verifyAccountPassword(const vector<users>& userList, const string& account, const string& password, int expectedRole) {
//	for (const auto& user : userList) {
//		if (user.account == account) {
//			if (user.password != password) {
//				return 1; // 密码错误
//			}
//			if (expectedRole != -1) {
//				int userRole = stoi(user.role);
//				if (userRole != expectedRole) {
//					return 2; // 角色不匹配
//				}
//			}
//			return 0; // 验证成功
//		}
//	}
//	return 3; // 账号不存在
//}
//
//int getUserRole(const vector<users>& userList, const string& account) {
//	for (const auto& user : userList) {
//		if (user.account == account) {
//			return stoi(user.role);
//		}
//	}
//	return -1; // 用户不存在
//}
//
//int login(int Try,int role,users *user) {
//	if (Try >= 3) {
//		cout << "登录失败超过3次，请稍后再试！\n";
//		return 0;
//	}
//	vector<users> userList = readUserData();
//	if (userList.empty()) {
//		cout << "系统错误：用户数据文件为空或无法读取！\n";
//		return 0;
//	}
//	cout << "请输入账号\n";
//	string Accountinput = inputAccount();
//
//	cin.clear();
//	cin.ignore(10000, '\n');
//
//	string inputPassword = getPasswordHidden("请输入密码: ");
//
//	int verifyResult = verifyAccountPassword(userList, Accountinput, inputPassword, role);
//	if (verifyResult == 0) {
//		// 登录成功，保存用户信息
//		user->account = Accountinput;
//		user->password = inputPassword;
//		user->role = to_string(getUserRole(userList, Accountinput));
//
//		cout << "登录成功！欢迎 " << user->account << "！\n";
//		cout << "用户角色: " << user->role << endl;
//		return 1;
//	}
//	else {
//		// 根据错误类型显示不同的提示信息
//		if (verifyResult == 1) {
//			cout << "密码错误！\n";
//		}
//		else if (verifyResult == 2) {
//			cout << "角色权限不足！您没有权限以该角色登录。\n";
//		}
//		else if (verifyResult == 3) {
//			cout << "账号不存在！\n";
//		}
//
//		cout << "剩余尝试次数: " << (2 - Try) << "\n\n";
//
//		// 递归调用继续尝试
//		return login(Try + 1, role, user);
//	}
//	return 0;
//}