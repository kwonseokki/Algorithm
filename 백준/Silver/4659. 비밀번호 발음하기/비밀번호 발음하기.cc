#include <bits/stdc++.h>
using namespace std;
string a;
int main()
{
   while (cin >> a)
   {
      if (a == "end")
         exit(0);
      bool is_m = false;
      int m_cnt = 0, j_cnt = 0;
      stack<char> stk;
      for (int i = 0; i < a.size(); i++)
      {
         if (a[i] != 'e' && a[i] != 'o')
         {
            if (stk.size() == 0)
            {
               stk.push(a[i]);
            }
            else
            {

               if (stk.top() == a[i])
               {
                  stk.push(a[i]);
               }
               else
               {
                  if (stk.size() == 2)
                  {
                     break;
                  }
                  while (!stk.empty())
                     stk.pop();
                  stk.push(a[i]);
               }
            }
         }

         if (m_cnt >= 3 || j_cnt >= 3)
         {
            break;
         }
         if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u')
         {
            is_m = true;
            m_cnt++;
            j_cnt = 0;
         }
         else
         {
            j_cnt++;
            m_cnt = 0;
         }
      }
      if (!is_m || m_cnt >= 3 || j_cnt >= 3 || stk.size() == 2)
         cout << "<" << a << ">"
              << " "
              << "is not acceptable.";
      else
         cout << "<" << a << ">"
              << " "
              << "is acceptable.";
      cout << '\n';
   }
   return 0;
}