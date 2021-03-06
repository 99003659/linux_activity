#include "mystring.h"
#include <stdio.h>

char* mystrcpy(char* dest,const char *src)  //const char str[]
{
  int k=0;
  while(src[k]!='\0')  //while(dest[k++]=src[k])
  {
    dest[k]=src[k];
    k++;
  }
  dest[k]='\0';
  
}

int mystrlen(const char *str)  //const char str[]
	{
	  int k=0;
	  while(str[k]!='\0')  //while(str[k++])
	    k++;
	  return k;
	}

char* mystrcat(char* dest,const char *src)  //const char str[]
{
  int i=0,j=0;
  while(dest[i]!='\0')
    i++;
  while(src[j]!='\0')  //while(dest[i++]=src[j++])
  {
    dest[i]=src[j];
    i++;
    j++;
  }
  dest[i]='\0';
  return dest;
}


int mystrcmp(const char* str1,const char* str2)
{
  int i=0;
  while(str1[i]==str2[i]&&str1[i]!='\0'&&str2[i]!='\0')
    i++;
  if(str1[i]==str2[i])
    return 0;
  else if (str1[i] < str2[i])
    return -1;
  else //ps1[i] > ps2[i]
    return +1;
}
