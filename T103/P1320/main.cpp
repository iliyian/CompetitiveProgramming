#include <iostream>
#include <string>
using namespace std;

char ch = '0';
int count = 0, N;

void parse(const string &str)
{
  for (int i = 0; i < N; i++)
  {
    if (str[i] == ch)
      count++;
    else
    {
      ch = str[i];
      cout << count << " ";
      count = 1;
    }
  }
}

int main()
{
  freopen("data.in", "r", stdin);

  string str;
  cin >> str;
  N = str.size();

  cout << N << " ";
  parse(str);

  for (int i = 1; i < N; i++)
  {
    cin >> str;
    parse(str);
  }

  cout << count << " ";

  return 0;
}