/*
while（getline(cin, str)）或者 while(cin >> str)跳出循环的方式： 
	windows下：输入流对象cin输入的结束符在windows下是ctrl+z，所以，按下ctrl+z，然后回车，程序就正常跳出循环了
*/
#include <iostream>
#include <vector>
using namespace std;

struct Markdown
{
    int type;
    string s;
};
vector<Markdown> article;

//判断是否为空行
bool isspace(string str)
{
    for(int i=0;i<str.length();i++)
        if(str[i]!=' ')
            return false;
    return true;
}

//去除首尾空格 
string standard(string str)
{
	int len = str.length();
	int pos1 = 0,pos2 = len-1;
	
	while(str[pos1] == ' ')
		pos1++;
	while(str[pos2] == ' ')
		pos2--;
	str = str.substr(pos1,pos2-pos1+1);
	return str;
}

int main() 
{
	//加速了cin速度,否则造成超时
	ios::sync_with_stdio(false);
    
	int n;
	cin>>n;
    
    //通过第一行判断是什么文本
	string str;
    while(getline(cin,str))
	{
        if(!isspace(str))	//跳过空行
            break;
    }

	//列表
    if(str.length()>=2 && str.substr(0,2) == "* ")
        article.push_back({1,standard(str.substr(2))});
    //段落 
	else
        article.push_back({2,standard(str)});
    
	bool check=false;
    while(getline(cin,str))
	{			
		//是空行
        if(isspace(str))
            check=true;
        else
		{	
			//上一行是空行，该行非空，直接插入
            if(check)
			{
                check=false;
                //开启列表 
                if(str.length()>=2 && str.substr(0,2) == "* ")		
                	article.push_back({1,standard(str.substr(2))});
                //开启段落 
				else												
                    article.push_back({2,standard(str)});
            }
            //上一行非空，那就要考虑是否是同一段/同一列表了
            else
			{
                Markdown &temp=article.back();
                //列表情况
				if(temp.type==1||temp.type==3)
				{
					//本列表项内容，直接连结 
                    if(str.length()>=2 && str.substr(0,2) == "  ")
					{ 
                        temp.s+=" ";
                        temp.s += standard(str.substr(2));
                    }
                    //列表非首项 
					else if(str.length()>=2 && str.substr(0,2) == "* ")
                        article.push_back({3,standard(str.substr(2))});
                    //新段落 
					else
                        article.push_back({2, standard(str)});
                }
                //段落情况 
				else
				{
					//开启新列表
                    if(str.length()>=2 && str.substr(0,2) == "* ")
                        article.push_back({1,standard(str.substr(2))});	
                    //本段内容，直接连接 
					else
					{
                        temp.s+=" ";
                        temp.s += standard(str);
                    }
                }
            }
        }
    }
    
    long long ans=0;
    for(int i=0;i<article.size();i++)
	{
        string& str=article[i].s;
        
        //新的段落或列表，空一行 
        if(article[i].type!=3 && i>0)
            ans++;
        
        //列表的处理 
        if(article[i].type!=2)
		{
        	//空项目（注意上面的处理方式，如果非空会连结上内容的） 
            if(str.size()==0)
                ans++;
            //注意同一项目第一行 空格 * 空格 /非第一行要插入三个空格
			else
			{
                for (int i = 0; i < str.length(); i += (n - 3))
				{
					//换行时去掉前导空格 
                    while(i<str.length()&&str[i]==' ')
                        i++;
                    ans++;
                }
            }
        }
        
        //段落的处理
        else
		{
            for (int i = 0; i < str.length(); i += n)
			{
				//换行时去掉前导空格 
                while(i<str.length()&&str[i]==' ')
                    i++;
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
/*

10
* CSP

*   CSP is
  * a real 
    competition.
* 
  * ome!   and   join.
*Tel:
* 12345
*  

*/ 
