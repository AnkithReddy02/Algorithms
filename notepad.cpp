/******************************************************************************

Program Of Note_Pad using Doubly Linked_List.

*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    list<char> list;
    
    int cursor=0;
    
    string clipboard="";
    
    ofstream file;
    
    while(1)
    {
        string s="";
        
        printf("ENter Operation : ");
        
        cin >> s;
        
        if(s=="INSERT")
        {
            char x;
            
            cin >> x;
            
            auto it = list.begin();
            
            advance(it,cursor);
            
            list.insert(it,x);
            
            cursor = cursor + 1;  // cursor update.
        }
        else if(s=="SEEK")
        {
            int x;
            
            cin >> x;
            
            if(x==-1)
            {
                cursor = list.size();
            }
            else if(x>=0&&x<=list.size())
            {
                cursor = x;
            }
        }
        else if(s=="PRINT")
        {
            for(auto i = list.begin();i!=list.end();i++)
            {
                cout << *i ;
            }
            cout << endl;
        }
        else if(s=="PRINT_CURSOR")
        {
            cout << cursor << endl;
        }
        else if(s=="COPY")
        {
            int x, y;
            cin >> x >> y;
            if(x>=0&&y<list.size())
            {
                
                clipboard = "";  // clearing before copied string if any.
                
                auto start = list.begin(),end = list.begin();
                
            
                advance(start,x);
                advance(end,y+1);
                
                for(auto i = start;i!=end;i++)
                {
                    clipboard = clipboard + *i;
                }
            }
            else
            {
                cout << "Can't Copy to clipboard" << endl;
            }
        }
        else if(s=="PRINT_CLIPBOARD")
        {
            cout << clipboard << endl;
        }
        else if(s=="CUT")
        {
            int x, y;
            cin >> x >> y;
            if(x>=0&&y<list.size())
            {
                
               clipboard = "";
                
                auto start = list.begin(),end=list.begin();
                
            
                advance(start,x);
                advance(end,y+1);
                
                for(auto i = start;i!=end;i++)
                {
                    clipboard = clipboard + *i;
                }
                
                list.erase(start,end);
                
                cursor = list.size();
            }
            else
            {
                cout << "Can't CUT" << endl;
            }
        }
        else if(s=="DELETE")
        {
            int x;
            
            cin >> x;
            
            if(x==1)
            {
                if(cursor>=0&&cursor<list.size())
                {
                    auto it = list.begin();
                    
                    advance(it,cursor);
                    
                    list.erase(it);
                }
                else
                {
                    cout << "Can't Delete" << endl;
                 }
            }
            else if(x==-1)
            {
                if(cursor>=1&&cursor<=list.size())
                {
                    auto it = list.begin();
                    
                    advance(it,cursor-1);
                    
                    list.erase(it);
                    
                    cursor = cursor - 1;
                }
                else
                {
                     cout << "Can't Delete" << endl;
                }
            }
        }
        else if(s=="PASTE")
        {
            int x;
            
            cin >> x;
            
            int n = list.size();
            
            if(x>=0&&x<=n)
            {
                if(x==n)
                {
                    for(int i=0;i<clipboard.length();i++)
                    {
                        list.push_back(clipboard[i]);
                    }
                    cursor = x + clipboard.length();
                }
                else
                {
                    auto it = list.begin();
                    
                    advance(it,x);
                    
                    for(int i=0;i<clipboard.length();i++)
                    {
                        list.insert(it,clipboard[i]);
                       // it++;
                    }
                    cursor = x + clipboard.length();
                    
                }
            }
            else
            {
                cout << "Can't PASTE" << endl;
            }
        }
        else if(s=="OPEN_FILE")
        {
            string file_name;
            cin >> file_name;
            
            clipboard.erase(clipboard.begin(),clipboard.end());
            clipboard = "";
            
            cursor = list.size();
            
            file.open(file_name);
            
            
            
            
            
            
        }
        else if(s=="SAVE_FILE")
        {
            for(auto it = list.begin();it!=list.end();it++)
            {
                file << *it  ;
            }
            
            
            
            
        }
        else if(s=="EXIT")
        {
            file.close();
            exit(0);
        }
        
        
        
    }
}


