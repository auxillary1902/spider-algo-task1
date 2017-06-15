#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cctype>

using namespace std;
void computeLPSArray(string pat, int M, int lps[])
{
    
    int len = 0;
 
    lps[0] = 0; 
 
  
    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else 
        {
            
            if (len != 0)
            {
                len = lps[len-1];
 
               
            }
            else 
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
int KMPSearch(string pat, string txt)
{
    int M = pat.length();
    int N = txt.length();
 
    
 int   lps[M];
 int k=0;
    
    computeLPSArray(pat, M, lps);
   
  
     
    int i = 0;  
    int j  = 0;  
    while (i < N)
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }
 
        if (j == M)
        {
      if((!isalpha(txt[i-j-1]))&&(!isalpha(txt[i-j+M])))
       k++;
            j = lps[j-1];
        }
 
       
        else if (i < N && pat[j] != txt[i])
        {
            
            if (j != 0)
                j = lps[j-1];
            else
                i = i+1;
        }
    }
    
    return k;
}
 



int main()
{string s;int i,j=0,l=0;string txt;int m;
	ifstream f,fin;
	fin.open("queries.txt");
	while(!fin.eof())
	{
		getline(fin,s,'\n');int x[26][300],pg=0;
	cout<<s<<":"<<endl ;
		
		for(i=0;i<25;i++)
		{char a[]="page_",b[200];
		itoa(i+1,b,10);
		strcat(a,b);
		strcat(a,".txt");
		f.open(a);
		while(!f.eof())
		{
			getline(f,txt,'\n');
			x[i][j]=KMPSearch(s,txt);
			if(x[i][j]>0)
			{
				for(m=1;m<=x[i][j];m++)
				cout<<"line number "<<j+1<<" page number "<<i+1<<endl;
			}
		else	if(x[i][j]==0)
			{
			l++;}
			j++;
		}
		if(l==j)
	{
			pg++;	}
			
	
	
		j=0;
		l=0;	f.close();
		}
	
	
		
			
	if(pg==25)
		{
		cout<<"None"<<endl;
		pg=0;}
	}fin.close();
	return 0;
}
