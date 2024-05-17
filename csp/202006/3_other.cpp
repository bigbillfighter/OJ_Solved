/*
while��getline(cin, str)������ while(cin >> str)����ѭ���ķ�ʽ�� 
	windows�£�����������cin����Ľ�������windows����ctrl+z�����ԣ�����ctrl+z��Ȼ��س����������������ѭ����
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

//�ж��Ƿ�Ϊ����
bool isspace(string str)
{
    for(int i=0;i<str.length();i++)
        if(str[i]!=' ')
            return false;
    return true;
}

//ȥ����β�ո� 
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
	//������cin�ٶ�,������ɳ�ʱ
	ios::sync_with_stdio(false);
    
	int n;
	cin>>n;
    
    //ͨ����һ���ж���ʲô�ı�
	string str;
    while(getline(cin,str))
	{
        if(!isspace(str))	//��������
            break;
    }

	//�б�
    if(str.length()>=2 && str.substr(0,2) == "* ")
        article.push_back({1,standard(str.substr(2))});
    //���� 
	else
        article.push_back({2,standard(str)});
    
	bool check=false;
    while(getline(cin,str))
	{			
		//�ǿ���
        if(isspace(str))
            check=true;
        else
		{	
			//��һ���ǿ��У����зǿգ�ֱ�Ӳ���
            if(check)
			{
                check=false;
                //�����б� 
                if(str.length()>=2 && str.substr(0,2) == "* ")		
                	article.push_back({1,standard(str.substr(2))});
                //�������� 
				else												
                    article.push_back({2,standard(str)});
            }
            //��һ�зǿգ��Ǿ�Ҫ�����Ƿ���ͬһ��/ͬһ�б���
            else
			{
                Markdown &temp=article.back();
                //�б����
				if(temp.type==1||temp.type==3)
				{
					//���б������ݣ�ֱ������ 
                    if(str.length()>=2 && str.substr(0,2) == "  ")
					{ 
                        temp.s+=" ";
                        temp.s += standard(str.substr(2));
                    }
                    //�б������ 
					else if(str.length()>=2 && str.substr(0,2) == "* ")
                        article.push_back({3,standard(str.substr(2))});
                    //�¶��� 
					else
                        article.push_back({2, standard(str)});
                }
                //������� 
				else
				{
					//�������б�
                    if(str.length()>=2 && str.substr(0,2) == "* ")
                        article.push_back({1,standard(str.substr(2))});	
                    //�������ݣ�ֱ������ 
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
        
        //�µĶ�����б���һ�� 
        if(article[i].type!=3 && i>0)
            ans++;
        
        //�б�Ĵ��� 
        if(article[i].type!=2)
		{
        	//����Ŀ��ע������Ĵ���ʽ������ǿջ����������ݵģ� 
            if(str.size()==0)
                ans++;
            //ע��ͬһ��Ŀ��һ�� �ո� * �ո� /�ǵ�һ��Ҫ���������ո�
			else
			{
                for (int i = 0; i < str.length(); i += (n - 3))
				{
					//����ʱȥ��ǰ���ո� 
                    while(i<str.length()&&str[i]==' ')
                        i++;
                    ans++;
                }
            }
        }
        
        //����Ĵ���
        else
		{
            for (int i = 0; i < str.length(); i += n)
			{
				//����ʱȥ��ǰ���ո� 
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
