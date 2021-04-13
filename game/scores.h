#ifndef SCORES_H_INCLUDED
#define SCORES_H_INCLUDED

#include <stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

struct data
{
	char name[100];
	int score;

	data()
	{
		;
	}
	data(char* _name,int _score)
	{
		strcpy(name,_name);
		score = _score;
	}
};

vector <data> dataBase;
data userInfo;

void saveScore(char* name,int score)
{
	data x;
	strcpy(x.name,name);
	x.score = score;
	FILE *fp = fopen("Score.bin", "ab");
	fwrite(&x,sizeof(x),1,fp);
	fclose(fp);
}


bool sorting(data a,data b)
{
	if(a.score==b.score)
		return a.name>= b.name;
	return a.score>b.score;
}


void getHigh()
{
	dataBase.clear();

	FILE *fp = fopen("Score.bin", "rb");
	data x;
	while(fread(&x,sizeof(x),1,fp)==1)
	{
		dataBase.push_back(x);
	}
	fclose(fp);

	sort(dataBase.begin(),dataBase.end(),sorting);
}


void showHigh()
{
	getHigh();
	iSetColor(0,0,0);
	iText(50, 450, "Rank", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(200, 450, "Name", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(400, 450, "Score", GLUT_BITMAP_TIMES_ROMAN_24);
	int point = 400;
	char rank[5][10];
	char score[5][10];
	for(int i=0;i<5;i++,point = point-40)
	{
		sprintf(rank[i],"%d",i+1);
		iText(60, point,rank[i], GLUT_BITMAP_TIMES_ROMAN_24);
		iText(200,point,dataBase[i].name, GLUT_BITMAP_TIMES_ROMAN_24);
		sprintf(score[i],"%d",dataBase[i].score);
		iText(410,point, score[i], GLUT_BITMAP_TIMES_ROMAN_24);
	}
	
}


#endif // SCORES_H_INCLUDED
