#include "headers.h"
vector<users> readUserData() {  
    vector<users> user;  
    ifstream file("users.txt");  

    if (!file.is_open()) {  
        cout << "错误：无法打开文件 " << "users.txt" << endl;  
        return user;  
    }  

    string line;  
    while (getline(file, line)) {  
        // 跳过空行和注释行（以#开头的行）  
        if (line.empty() || line[0] == '#') {  
            continue;  
        }  

        stringstream ss(line);  
        string Account, Password, Role;  

        // 假设文件格式：用户名 密码（用空格或制表符分隔）  
        if (ss >> Account >> Password >> Role) {  
            user.emplace_back(users{Account, Password, Role});  // 修复错误：正确使用结构体初始化  
        }  
    }  

    file.close();  
    return user;  
}
bool account(int role, users* user) {
	cin >> user->account;
	return 1;
}


string getPasswordHidden(const string& prompt = "请输入密码: ") {
	string password;
	DWORD mode;
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);

	// 保存当前控制台模式
	GetConsoleMode(hStdin, &mode);
	// 禁用回显
	SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));

	cout << prompt;
	getline(cin, password);

	// 恢复控制台模式
	SetConsoleMode(hStdin, mode);
	cout << endl;

	return password;
}
bool password(int role, users* user) {
	string inputPassword = getPasswordHidden();
	user->password = inputPassword;
	return 1;
}
int verifyAccountPassword(const vector<users>& userList, const users* currentUser, int expectedRole) {
	for (const auto& user : userList) {
		if (user.account == currentUser->account) {
			if (user.password != currentUser->password) {
				return 1; // 密码错误
			}
			if (expectedRole != -1) {
				int userRole = stoi(user.role);
				if (userRole != expectedRole) {
					return 2; // 角色不匹配
				}
			}
			return 0; // 验证成功
		}
	}
	return 3; // 账号不存在
}
int getUserRole(const vector<users>& userList, const string& account) {
	for (const auto& user : userList) {
		if (user.account == account) {
			return stoi(user.role);
		}
	}
	return -1; // 用户不存在
}
int login(int Try,int role,users *user) {
	if (Try >= 3) {
		cout << "登录失败超过3次，请稍后再试！\n";
		return 0;
	}
	vector<users> userList = readUserData();
	if (userList.empty()) {
		cout << "系统错误：用户数据文件为空或无法读取！\n";
		return 0;
	}
	cout << "请输入账号\n";
	account(role, user);
	cin.clear();
	cin.ignore(10000, '\n');
	password(role,user);
	int result = verifyAccountPassword(userList, user, role);
	if (result == 0) {
		cout << "登录成功！欢迎 " << user->account << "！\n";
		user->role = to_string(getUserRole(userList, user->account));
		return 1;
	}
	else {
		if (result == 1) {
			cout << "密码错误！\n";
		}
		else if (result == 2) {
			cout << "角色权限不足！\n";
		}
		else if (result == 3) {
			cout << "账号不存在！\n";
		}
		cout << "剩余尝试次数: " << (2 - Try) << "\n\n";
		return login(Try + 1, role, user);
	}
	return 0;
}