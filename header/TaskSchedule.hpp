//TaskSchedule.hpp
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
void AddTaskForLinux()
{
	char* s;
	char* buffer;
	buffer = getcwd(NULL, 0);
	const char* ExecutePath = strcat(buffer, "/main");
	std::cout << "下面会要求输入sudo密码，权限仅用于向/etc/crontab写入任务" << std::endl;
	sprintf(s, "sudo echo \"30 6 * * * %s\" >> /etc/crontab", ExecutePath);
	system(s);
	system("/etc/init.d/crond restart");
	system("service crond restart");
	std::cout << "生成成功" << std::endl;
	return;
}
void AddTaskForMac()
{
	std::cout << "macOS用户创建计划任务请跟随打开的网页进行设置" << std::endl;
	system("open -a Safari https://github.com/qhy040404/Library-reservation-configGenerator-Unix/blob/master/macOSTaskSchedule.md");
	return;
}