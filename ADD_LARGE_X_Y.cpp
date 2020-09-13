#include<bits/stdc++.h>
using namespace std;
string add(string s , string t )
{
    string p =""; // intialising empty string to generate final output and to add each character to it.
    
    int i = s.length()-1,j=t.length()-1;  // starting from end of the string.
    
   int c = 0;
    
    while(i>=0&&j>=0)    // this loop comes from last and does addition upto same length.
    {
      
        if(s[i]==t[j]&&s[i]=='.')
        {
            i--;
            j--;
            p = '.' + p;
            continue;
        }
        int si = s[i] - '0';// converting to int.
        int tj = t[j] - '0';
        
        int sum = si + tj + c;  // intially carry = 0;
        
        c = sum/10; // new carry
        
        sum = sum%10; // neglecting carry as carry is required next time.
        
        char v = (sum+'0');
      
        p = v + p; // adding to string to generate final o/p.
        
        i--;
        j--;
        
     
    }
  
    
    
    while(i>=0)// this loop does remaining addition if 2 integers are of diiferent length
    {
         int si = s[i] - '0';// converting to int.
         
         int sum = si + c; // doing sum with carry.
         
          c = sum/10;// new carry
          
        sum = sum%10; // neglecting carry as carry is required next time.
        
         char v = (sum+'0'); // converting added value to char .
         
        p = v + p;  // adding to string to generate final o/p.
        
        i--;
    }
   
    while(j>=0)// this loop does remaining addition if 2 integers are of diiferent length
    {
        int tj = t[j] - '0';// converting to int.
      
        
        int sum = tj + c;// doing sum with carry.
         
        c = sum/10; // new carry
        
        sum = sum%10; // neglecting carry as carry is required next time.
        
        char v = (sum+'0');   // converting added value to char .
        
        p = v + p;   // adding to string to generate final o/p.
      
        j--;
    }
    if(c!=0) // adding carry (if carry is not equal to zero because we dont add leading zeroes)
    {
        char v = c + '0'; // converting carry to char.
        
        p = v + p;// adding carry to string.
      
    }
    
    return p; // return final o/p as string.
    
}
int main()
{
    string s,t;
    printf("Enter the real value_1 : ");
    cin >> s ;
    printf("Enter the real value_2 : ");
    cin >> t;
    
    if(s.find('.')==-1)
    {
        s = s + ".0";
 
    }
    if(t.find('.')==-1)
    {
        t = t + ".0";
  
    }
    
    
    
    int ls = s.length()-s.find('.');
    int lt = t.length()-t.find('.');
    if(ls>lt)
    {
        while(lt!=ls)
        {
            t = t + '0';
            lt++;
        }
    }
    else
    {
        while(ls!=lt)
        {
           s = s + '0';
           ls++;
        }   
    }
    
    int c = 0;
    
    
    string final_answer = add(s,t);
    

    
    cout << " Value_1 + Value_2 = ";
    
    cout << final_answer << endl ;
    
    
    
}


