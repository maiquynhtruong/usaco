#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXNAME 14 //maximum length of name

int nameMatching(char* toBeMatched);//return the index of the toBeMatched name
void print(FILE* fout);
struct People
{
	char* name;
	int money;
};
int NP;
struct People makeMember(char* name);
struct People group[10];//array of group member
struct People* member = group;//pointer to that array 
//( if pa is a pointer, expressions might use it with a subscript; pa[i] is identical to *(pa+i). )

int main()
{
	FILE* fin = fopen("gift1in.txt","r");
	FILE* fout = fopen("gift1out.txt","w");
	if (fin == NULL)
	{
		fprintf(stderr,"Can't open file");
		exit(1);
	}
	int i;
	fscanf(fin,"%d",&NP);
	for (i = 0; i < NP; i++)
	{
		char name[MAXNAME];
		fscanf(fin,"%s",name);
		fprintf(fout,"%d\n",name);
		group[i] = makeMember(name);
		fprintf(fout,"Name reading is %s\n",name);
		fprintf(fout,"%dth name in group is %s\n",i,group[i].name);
	}
		
	for (i = 0; i < NP; i++)//NP groups
	{
		char name[MAXNAME];
		fscanf(fin,"%s",name);//read in the names first
		fprintf(fout,"%d\n",name);
		int j = nameMatching(name);
		fprintf(fout,"Name found is %s, the %dth member\n",member[j].name,j);
		fprintf(fout,"%d\n",member[j].name);
		fprintf(fout,"%dth name in group is %s\n",0,group[0].name);
		fprintf(fout,"%d\n",member[0].name);
		fprintf(fout,"%d\n",member[1].name);
		fprintf(fout,"%dth name in group is %s\n",1,group[1].name);
		int initMoney = 0;
		int giving = 0;
		fscanf(fin,"%d",&initMoney);//assign the values to the corresponding person
		fscanf(fin,"%d",&giving);
		if (giving == 0)
		continue;	
		member[j].money += (initMoney % giving)- initMoney;
		fprintf(fout,"Initial money that %s had is %d\n", member[j].name, member[j].money);
		int k;
		for (k = 0; k < giving; k++)
		{
			char receiver[MAXNAME];
			fscanf(fin,"%s",receiver);
			int i = nameMatching(receiver);
			fprintf(fout,"Name of the %dth member found is %s\n",i , member[i].name);
			fprintf(fout,"Amount that %s received is %d\n", member[i].name, (initMoney / giving));
			member[i].money += (initMoney / giving);
		}
	}
	print(fout);
	
	exit(0);
}

int nameMatching(char* toBeMatched)
{
	int j;
		for (j = 0; j < NP; j++)// find the matching name in the array of names
		{
			if (strcmp(toBeMatched,member[j].name)==0)
			break;
		}
	return j;
}

void print(FILE* fout)
{
	struct People* iter;
	for(iter = group; iter < group + NP; iter++)
	{
		fprintf(fout,"%s %d\n",iter->name,iter->money);
		fprintf(fout,"%d\n",iter->name);
	}
}
struct People makeMember(char* name)
{
	struct People temp;
	//strcpy(temp.name, name);
	temp.name = name;
	temp.money = 0;
	return temp;
}

