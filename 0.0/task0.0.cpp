// task0.0.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <set>
#include <string>

using namespace std;

int main()
{
	set<long long> tree;

	string line;
	ifstream in("input.txt");
	if (in.is_open()) {
		while (getline(in, line)) {
			tree.insert(stoi(line));
		}
	}
	in.close();
	long long res = 0;
	for (long long x : tree) {
		res += x;
	}
	ofstream out;
	out.open("output.txt");
	if (out.is_open()) {
		out << res << endl;
	}
	out.close();
	return 0;
}
