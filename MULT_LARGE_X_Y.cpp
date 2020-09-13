#include<bits/stdc++.h>
using namespace std;
string multiply(string s,string t)
{
    vector<int>result(s.length()+t.length(),0);
    
    int index1=0,index2=0;
    
    int sum;
    
    for(int i=t.length()-1;i>=0;i--)
    {
        int carry = 0;
        int y = t[i]-'0';
        
        index2 = 0;
        
        for(int j=s.length()-1;j>=0;j--)
        {
            int x = s[j]-'0';
            
            sum = x*y + result[index2+index1] + carry;
            
            carry = sum/10;
            
            result[index1+index2] = sum%10;
            
            index2++;
            
            //cout << x*y << " ";
            
        }
        if(carry>0)
        {
            result[index1+index2] += carry;
        }
        index1++;
    }
    
    int i = result.size()-1;
    
    while(i>=0&&result[i]==0)
    {
        i--;
    }
    
    if(i==-1)
    {
        return "0";
    }
    
    string result_string = "";
    
    while(i>=0)
    {
        result_string = result_string + to_string(result[i--]);
    }
    

    
    return result_string;
}
int main()
{
    string s,t;
    printf("Enter Number 1 : ");
    cin >> s;
    printf("Enter Number 2 : ");
    cin >> t;
    
    if(s.length()==0||t.length()==0)
    {
        cout << 0 << endl;
        return 0;
    }
    
    if(s[0]=='+'&&t[0]=='-'||s[0]=='-'&&t[0]=='+')
    {
        cout << '-' << endl;
    }
    
    int after_decimal_count = 0;
    
    int x = s.find('.');
    int y = t.find('.');
    
    if(x!=-1)
    {
        after_decimal_count+= s.length()-1-x;
        
        s.erase(s.begin()+x);
    }
    if(y!=-1)
    {
        after_decimal_count+= t.length()-1-y;
        
        t.erase(t.begin()+y);
    }
    
    

    
    
    
    if(s[0]=='-')
    {
        s = s.substr(1);
        
    }
    if(t[0]=='-')
    {
        t = t.substr(1);
    }
  //  cout << s << endl << t << endl;
    string result = multiply(s,t);
    
    if(after_decimal_count)
    result.insert(result.begin()+s.length()-after_decimal_count+1,'.');
    
    cout << result << endl;
    
    
}
