#include <bits/stdc++.h>
using namespace std;

int input;
string a, b, answer; // 긴 숫자를 문자로 표현
vector<int> va, vb; // 연산을 위한 벡터

string fibo(string &a, string &b){
  string res = "";

  int diff_len = b.size()-a.size(); // 숫자 길이의 차이

  for(int i = 0; i < diff_len; i++) va.push_back(0);
  for(auto str : a) va.push_back(str - '0');
  for(auto str : b) vb.push_back(str - '0');

  int carry = 0;
  for(int i = vb.size()-1; i >= 0; i--){
    int temp_sum = va[i] + vb[i];

    if(carry == 1) { // 올림수가 있었다면, 더해주고. 다시 0 으로 돌려놓음
      temp_sum++;
      carry = 0;
    }
    if(temp_sum > 9){
      temp_sum %= 10;
      carry = 1;
    }
    res += (temp_sum + '0');
  }

  if(carry == 1) res += '1';
  reverse(res.begin(), res.end());
  va.clear(); vb.clear();

  return res;
}
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> input;

  a = "0", b ="1";

  if(input == 0) cout << 0;
  else if(input == 1) cout << 1;
  else{
    for(int i = 2; i <= input; i++){
      answer = fibo(a, b);
      a = b;
      b = answer;
    }
    cout << b;
  }
  return 0;
}