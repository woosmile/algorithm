// #include <bits/stdc++.h>
# include <iostream>
using namespace std;

const int MX = 1000005;
char dat[MX];
int pre[MX], nxt[MX];
int unused = 1;

void insert(int addr, int num){
  if (addr >= 0 && addr < MX)
  {
    dat[unused] = num;
    pre[unused] = addr;
    nxt[unused] = nxt[addr];
    if (nxt[addr] != -1)
    {
      pre[nxt[addr]] = unused;
    }
    nxt[addr] = unused;
    unused++;
  }
}

void erase(int addr){
  nxt[pre[addr]] = nxt[addr];
  if (addr >= 0 && addr < MX)
  {
    pre[nxt[addr]] = pre[addr];
  }
}

void traverse(){
  int cur = nxt[0];
  // while(cur != -1){
  //   cout << dat[cur] << ' ';
  //   cur = nxt[cur];
  // }
  // cout << "\n\n";
  while(cur != -1){
    cout << dat[cur];
    cur = nxt[cur];
  }
}

void insert_test(){
  cout << "****** insert_test *****\n";
  insert(0, 10); // 10(address=1)
  traverse();
  insert(0, 30); // 30(address=2) 10
  traverse();
  insert(2, 40); // 30 40(address=3) 10
  traverse();
  insert(1, 20); // 30 40 10 20(address=4)
  traverse();
  insert(4, 70); // 30 40 10 20 70(address=5)
  traverse();
}

void erase_test(){
  cout << "****** erase_test *****\n";
  erase(1); // 30 40 20 70
  traverse();
  erase(2); // 40 20 70
  traverse();
  erase(4); // 40 70
  traverse();
  erase(5); // 40
  traverse();
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  fill(pre, pre+MX, -1);
  fill(nxt, nxt+MX, -1);

  int cycle;
  string init;
  char mode;
  cin >> init;
  int cursor = 0;
  for (auto c : init)
  {
    insert(cursor, c);
    cursor++;
  }
  cin >> cycle;
  while (cycle > 0)
  {
      cin >> mode;
      if (mode == 'P')
      {
        char c;
        cin >> c;
        insert(cursor, c);
        cursor = nxt[cursor];
      }
      else if (mode == 'L')
      {
        if (pre[cursor] != -1)
          cursor = pre[cursor];
      }
      else if (mode == 'D')
      {
        if (nxt[cursor] != -1)
          cursor = nxt[cursor];
      }
      else // B
      {
        if (pre[cursor] != -1)
        {
          erase(cursor);
          cursor = pre[cursor];
        }
      }
      cycle--;
  }
  traverse();
}
