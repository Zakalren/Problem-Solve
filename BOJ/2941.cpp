#include <iostream>

std::string replace_all(std::string &str, const std::string &from, const std::string &to)
{
	int pos = 0;
	
	while ((pos = str.find(from, pos)) != std::string::npos)
	{
		str.replace(pos, from.length(), to);
		pos += to.length();
	}
	
	return str;
}

main()
{
	char buf[100];
	scanf("%s", &buf);
	
	std::string str(buf);
	
	std::string step_1 = replace_all(str, "dz=", "a");
	std::string step_2 = replace_all(step_1, "c=", "a");
	std::string step_3 = replace_all(step_2, "c-", "a");
	std::string step_4 = replace_all(step_3, "d-", "a");
	std::string step_5 = replace_all(step_4, "lj", "a");
	std::string step_6 = replace_all(step_5, "nj", "a");
	std::string step_7 = replace_all(step_6, "s=", "a");
	std::string step_8 = replace_all(step_7, "z=", "a");

	printf("%d", step_8.length());
}