#include <bits/stdc++.h>
using namespace std;
int n;
string a, b;
vector<string> v;

bool cmp(string a, string b)
{
   if (a.size() == b.size())
   {
      for (int i = 0; i < a.size(); i++)
      {
         if (a[i] < b[i])
            return a < b;
      }
   }
   return a.size() < b.size();
}

int main()
{
   cin >> n;
   while (n--)
   {
      cin >> a;
      for (int i = 0; i < a.size(); i++)
      {
         if (isdigit(a[i]))
         {
            if (b.size() && b[0] == '0')
            {
               b[0] = a[i];
            }
            else
            {
               b += a[i];
            }
         }
         else if (!isdigit(a[i]) && b.size())
         {
            v.push_back(b);
            b.clear();
         }
         if (i == a.size() - 1 && b.size())
         {
            v.push_back(b);
            b.clear();
         }
      }
   }
   sort(v.begin(), v.end(), cmp);
   for (string i : v)
      cout << i << '\n';
   return 0;
}