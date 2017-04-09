#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdio>
#include<cstring>
#include<stdlib.h>
using namespace std;

#define DEBUG cout
/************判断字符串类型**********/
void category(char *s , int type){

    //文件写入

    //表
    char keywords_tab[40][50]={"main","auto","break","case","char","const","continue","default","do","double",  
               "else","enum","extern","float","for","goto","if","int","long","register",  
               "return","short","signed","sizeof","static","struct","switch","typedef",  
               "union","unsigned","void","volatile","while"};
    const int keywords_tab_len = 33;
    char keychars_tab[40][10]={"!","~","++","--","+","-","*","&","/","%","<<",">>","<",">","<=",">=","==",
                               "!=","^","|","&&","||","=","+=","-=","/=","*=","&=","^=","|=","<<=",">>=",","};
    const int keychars_tab_len=33;
    char defchars_tab[40][50]={"include","define","error","if","else","elif","endif","ifndef","undef","line","pragma"};
    const int defchars_tab_len=11;

    //1.标识符   2.关键字   3.空格,制表符,回车  4.分界符  5.运算符  6. 整型    7.浮点型   8.错误
    switch(type){
    	case 1:{
    		for(int i=0;i<keywords_tab_len;i++){
    			if(strcmp(s,keywords_tab[i])==0){
    				printf("2--->%s\n",s);
                    return ;
				}
			}
            for(int i=0;i<defchars_tab_len;i++){
                if(strcmp(s,defchars_tab[i])==0){
                    printf("2--->%s\n",s);
                    return ;
                }
            }
			printf("1--->%s\n",s);
            return ;
		}
    	case 2:{
            printf("6--->%s\n",s);
            return ;
		}
    	case 3:{
    		printf("3--->%s\n",s);
            return ;
		}
    	case 4:{
            printf("4--->%s\n",s);
            return ;
		}
        case 5:{
            for(int i=0;i<keychars_tab_len;i++){
                if(strcmp(s,keychars_tab[i])==0){
                    printf("5--->%s\n",s);
                    return ;
                }
            }
            printf("error--->%s\n",s);
            return ;
        }
        case 6:{
            printf("6--->");
            puts(s);
            return ;
        }
        case 7:{
            printf("7--->%s\n",s);
            return ;
        }
        /*
        case 8:{
            for(int i=0;i<defchars_tab_len;i++){
                if(strcmp(s,defchars_tab[i])==0){
                    printf("8--->%s\n",s);
                    return ;
                }
            }
            printf("error--->%s\n",s);
            return ; 
        }
        */
        case 9:{
            printf("9--->");
            puts(s);
            return ;
        }
	}
}
/************判断字符串类型**********/


/************判断单个字符类型**********/

//字母下划线
bool isalpha(char c){
    if((c>=65&&c<=90)||(c>=97&&c<=122)||c==95){
        return true;
    }
    else return false;
}

//数字
bool isnum(char c){
    if(c>=48&&c<=57){
        return true;
    }
    else return false;
}

//空格,回车,制表符
bool isnull(char c){
    if(c==' '||c=='\n'||c=='\t'){
        return true;
    }
    else return false;
}
//分界符
bool isfenjie(char c){
    const int len_fenjie=10;
    char s[len_fenjie]={'(',')','[',']','{','}',';','#',(char)34,(char)39};//单引号,双引号
    for(int i=0;i<len_fenjie;i++){
        if(c==s[i]){
            return true;
        }
    }
    return false;
}
//点
bool isdian(char c)
{
    if(c=='.'){
        return true;
    }
    else return false ;
}
//井号
bool isjinghao(char c){
    if(c=='#')return true;
    else return false;
}
//单引号
bool isdanyinhao(char c){
    if(c=='\'')return true;
    else return false ;
}
//双引号
bool isshuangyinhao(char c){
    if(c=='\"')return true ;
    else return false ;
}
/************判断单个字符类型**********/

//字符追加
void strcat_plus(char temp[],char c){
    int len=strlen(temp);
    temp[len]=c;
    temp[len+1]='\0';
}
int main()
{
    freopen("test.c","r",stdin);
    freopen("result.txt","w",stdout);
	char c;
    char instr[255]={};
    int type=3;//1.字母下划线   2.数字  3.空格，回车，制表符   4.分界符  5. 运算符,其他错误
	char temp[256]={0};
	while((gets(instr))){
    int count_c=0;
    //puts(instr);
    while(instr[count_c]){
        c=instr[count_c++];
	    //1	
		if( isalpha(c) ){
			if(type==1){
				strcat_plus(temp,c);
			}
			else {
				category(temp,type);
				memset(temp,0,sizeof(temp));
				temp[0]=c;
				type=1;
			}
		}
        //井号 
        else if( isjinghao(c) ){
            category(temp,type);
            memset(temp,0,sizeof(temp));
            temp[0]=c;
            type=4;
            /*
            category(temp,type);
            memset(temp,0,sizeof(temp));
            type=8;
            while(isalpha(instr[count_c++])){
                c=instr[count_c-1];
                strcat_plus(temp,c);
            }
            */
        }
        //单引号
        else if( isdanyinhao(c) ){
            category(temp,type);
            memset(temp,0,sizeof(temp));
            temp[0]=c;
            type=9;
            while(!isdanyinhao(instr[count_c++])){
                c=instr[count_c-1];
                strcat_plus(temp,c);
            }
            strcat_plus(temp,instr[count_c-1]);
        }
        //双引号
        else if( isshuangyinhao(c) ){
            category(temp,type);
            memset(temp,0,sizeof(temp));
            temp[0]=c;
            type=9;
            while(!isshuangyinhao(instr[count_c++])){
                c=instr[count_c-1];
                strcat_plus(temp,c);
            }
            strcat_plus(temp,instr[count_c-1]);
        }
        //2
		else if( isnum(c) ){
			if(type==1||type==2||type==7){
				strcat_plus(temp,c);
			}
			else {
				category(temp,type);
				memset(temp,0,sizeof(temp));
				temp[0]=c;
				type=2;
			}
		}
        //点
        else if( isdian(c) ){
            if(type==2){
                strcat_plus(temp,c);
                type=7;
            }
            else {
                category(temp,type);
                memset(temp,0,sizeof(temp));
                temp[0]='.';
                type=5;
            }
        }
        //3
		else if(isnull(c)){
			if(type==3){
			}
			else {
                category(temp,type);
				memset(temp,0,sizeof(temp));
				temp[0]=c;
				type=3;
			}
		}
        //4
		else if( isfenjie(c) ) {
            category(temp,type);
            memset(temp,0,sizeof(temp));
            temp[0]=c;
            type=4;
        }
        //5 
        else {
            if(type==5){
                strcat_plus(temp,c);
            }
            else {
                category(temp,type);
                memset(temp,0,sizeof(temp));
                temp[0]=c;
                type=5;
                int toutemp=count_c;
                bool pd=1;
                if(c=='<'){
                    while(instr[toutemp++]!='>'){
                        if(instr[toutemp-1]=='\n'||!instr[toutemp-1]){
                            pd=0;
                            break;
                        }
                        strcat_plus(temp,instr[toutemp-1]);
                    }
                    if(pd){
                        strcat_plus(temp,instr[toutemp-1]);
                        count_c=toutemp;
                        type=6;
                    }
                    else{
                        memset(temp,0,sizeof(temp));
                        temp[0]='<';
                    }
                }
            }
        }
	}
    memset(instr,0,sizeof(instr));
    }
    if(temp[0]){
        category(temp,type);
    }
	return 0;
}

