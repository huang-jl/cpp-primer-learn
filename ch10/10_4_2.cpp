#include<iterator>
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<algorithm>

using namespace std;

void f10_29()
{
	ofstream ofs("123.txt");
	ostream_iterator<string> ofs_iter(ofs, "\n");
	vector<string>vs = { "aaa","bbb","ccc" };
	auto iter = vs.begin();
	copy(vs.begin(), vs.end(), ofs_iter);
}

void f10_30()
{	
	ostream_iterator<int> os_iter(cout, " ");
	istream_iterator<int> is_iter(cin), eof;
	vector<int>vi;
	copy(is_iter, eof, back_inserter(vi));
	sort(vi.begin(), vi.end());
	copy(vi.cbegin(), vi.cend(), os_iter);
}

/*void f10_33()
{
	string input, out_odd, out_even;
	cout << "请输入读入文件名" << endl;
	cin >> input;
	cout << "请输入存入奇数文件名" << endl;
	cin >> out_odd;
	cout << "请输入存入偶数文件名" << endl;
	cin >> out_even;
	ifstream ifs(input);
	istream_iterator<int> is_iter(ifs),eof;
	ofstream even_os(out_even);
	ofstream odd_os(out_odd);
	ostream_iterator<int> odd_iter(odd_os," ");
	ostream_iterator<int> even_iter(even_os,"\n");
	
	for_each(is_iter, eof, [&odd_iter, &even_iter](int a) {(a % 2 ? odd_iter : even_iter) = a; });
}*/