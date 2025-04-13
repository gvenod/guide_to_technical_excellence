#include <iostream>
#include <fstream>
#include <string>
#include <stringstream>
#include <map>

using namespace std;

int main () {
	ifstream fp("path of file here");
	if(!fp.is_open()) return -1;

	string line;
	map<string, string> kv;
	while (getline(fp, line)) {
		stringstream ss(line);
		string key, value;
		if(getline(ss, key, ":") && getline(ss, value)) {
			kv[key] = value;
		}
	}

	fclose(fp);
	
	for (const auto& it : kv) {
		cout << it.first << " : " << it.second << endl;
	}
	
	//write to file
	std::string text_to_write = "hello world";
	//std::getline(std::cin, text_to_write);//get string from user.	
	std::ofstream my_file("example.txt");//create stream object and open a file.	
	if (my_file.is_open()) {
		my_file << text_to_write << std::endl;
		my_file.close();
	}
	
	return 0;
}
