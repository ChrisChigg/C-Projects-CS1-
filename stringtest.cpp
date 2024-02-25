#include <iostream>
#include <string>
#include <sstream>

using namespace std;
int main(int argc, char const *argv[])
{
  /* code */
  // // istream cin
  // int a;
  // cin >> a;
  // cout << a << endl;

  // // ostream cout
  // int b = 10;
  // cout << b << endl;

  // istream getline
  string str1;
  getline(cin, str1);
  cout << str1 << endl;

  // istringstream
  string str2 = "Hello World";
  istringstream iss(str2);
  string str3;
  iss >> str3;
  cout << str3 << endl;

  // ostringstream
  string str4;
  ostringstream oss;
  oss << "Hello World";
  str4 = oss.str();
  cout << str4 << endl;

  // stringstream
  string str5;
  stringstream ss;
  ss << "Hello World";
  ss >> str5;
  cout << str5 << endl;

  // get integer from string
  string str6 = "123";
  int c = stoi(str6);
  cout << c << endl;

  // get float from string
  string str7 = "123.456";
  float d = stof(str7);
  cout << d << endl;

  // get an array of integer from string
  string str8 = "1 2 3 4 5";
  istringstream iss2(str8);
  int e[5];
  for (int i = 0; i < 5; ++i)
  {
    iss2 >> e[i];
  }
  for (int i = 0; i < 5; ++i)
  {
    cout << e[i] << endl;
  }

  return 0;
}