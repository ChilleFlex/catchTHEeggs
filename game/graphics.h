#ifndef GRAPHICS_H_INCLUDED
#define GRAPHICS_H_INCLUDED

#include "scores.h"


int loadingSize = 0;
void loading();


void graphicscode()
{
    iClear();
	if(n==0)
	{
		iShowImage(0, 0, 500, 705, background[0]);
		//button
		iShowImage(140, 400, 186, 47, background[1]);
		iShowImage(140, 340, 186, 47, background[2]);
		iShowImage(140, 280, 186, 47, background[3]);
		iShowImage(140, 220, 186, 47, background[4]);
		iShowImage(140, 160, 186, 47, background[5]);
		iShowImage(140, 100, 186, 47, background[6]);
		iShowImage(90, 600, 320, 57, background[7]);
	}
	//1st level
    else if (n == 1)
	{

		if (total <= 300)
		{

			iShowImage(0, 0, 500, 705, background[8]);

			iShowImage(chicken1_x, chicken1_y, 110, 140, chicken[0]);

			iShowBMP2(basketx, baskety, basket, 0);
			iShowImage(egg_x, egg_y, 20, 20, egg[0]);
			iShowImage(stool_x, stool_y, 30, 30, stool[0]);

		}
//2nd level
		else if (total >300 && total<=500)
		{
			iShowImage(0, 0, 500, 705, background[14]);
			iShowImage(chicken2_x, chicken2_y, 100, 120, chicken[1]);
			iShowImage(chicken1_x, chicken1_y, 110, 140, chicken[0]);			
			iShowBMP2(basketx, baskety, basket, 0);
			iShowImage(egg_x, egg_y, 20, 20, egg[0]);
			iShowImage(egg1_x, egg1_y, 20, 20, egg[1]);
			iShowImage(stool_x, stool_y, 30, 30, stool[0]);
		}
//3rd level
		else if (total > 500)
		{
			iShowImage(0, 0, 500, 705, background[15]);
			iShowImage(chicken3_x, chicken3_y, 100, 120, chicken[2]);
			iShowImage(chicken2_x, chicken2_y, 100, 120, chicken[1]);
			iShowImage(chicken1_x, chicken1_y, 110, 140, chicken[0]);
			iShowBMP2(basketx, baskety, basket, 0);
			iShowImage(egg_x, egg_y, 20, 20, egg[0]);
			iShowImage(egg1_x, egg1_y, 20, 20, egg[1]);
			iShowImage(egg2_x, egg2_y, 30, 30, egg[2]);
			iShowImage(stool_x, stool_y, 30, 30, stool[0]);
		}
		//score
		sprintf(SCORE, "%d", score);
		iSetColor(0, 0, 0);
		iText(350, 680, "SCORE= ", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(450, 680, SCORE, GLUT_BITMAP_TIMES_ROMAN_24);
		//bonus
		sprintf(BONUS, "%d", bonus);
		iSetColor(0, 0, 0);
		iText(350, 650, "BONUS= ", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(450, 650, BONUS, GLUT_BITMAP_TIMES_ROMAN_24);

		//minus point

		sprintf(MINUS, "%d", minus_point);
		iSetColor(0, 0, 0);
		iText(350, 620, "MINUS= ", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(450, 620, MINUS, GLUT_BITMAP_TIMES_ROMAN_24);
	    //total
		total = (bonus + score + minus_point);
		sprintf(TOTAL, "%d", total);
		iSetColor(230, 45, 45);
		iText(350, 590, "TOTAL= ", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(450, 590, TOTAL, GLUT_BITMAP_TIMES_ROMAN_24);


		if (isGameOver || isGameOver1)
		{
			n = 8;
		}
		


	}

	else if (n == 2 && !game)
	{
		iShowImage(0, 0, 500, 705, background[10]);
	}
	else if (n == 3 && !game)
	{
		iShowImage(0, 0, 500, 705, background[9]);
	}
	else if (n == 4 && !game)
	{
		iShowImage(0, 0, 500, 705, background[11]);
	}
	else if (n == 5 && !game)
	{
		iShowImage(0, 0, 500, 705, background[12]);
		showHigh();
	}
	else if (n == 6 && !game)
	{
		exit(0);
	}
	else if(n==7 && !game)
	{
		iShowImage(0, 0, 500, 705, background[16]);
		char tString[100];
		sprintf(tString,"%d %%",loadingSize);
		iText(340,25,tString,GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(255,255,255);
		iFilledRectangle(200,20,100,25);
		iSetColor(0,0,255);
		iFilledRectangle(200,20,loadingSize,25);

	}
	else if(n==8)
	{
		iShowImage(0, 0, 500, 705, over[0]);
		char tempString[100];
		sprintf(tempString,"%d",total);
		iSetColor(255,255,255);
		iText(65,200,"Your Score:-",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(300,200,tempString,GLUT_BITMAP_TIMES_ROMAN_24);
		iText(65,150,"Write Your Name:-",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(300,150,userInfo.name,GLUT_BITMAP_TIMES_ROMAN_24);
		iText(100,50,"**To write name use keyboard and then press Enter button",GLUT_BITMAP_HELVETICA_12);

	}
}

void loading()
{
	if(n==7)
	{
		loadingSize+= 5;
		if(loadingSize>=100)
		{
			n = 0;
		}
	}

}

void resetData()
{
	basketx = 250;
	baskety = 30;

	chicken1_x = rand()%300 +50;
	chicken1_y = 550;
	chicken2_x = 200;
	chicken2_y = 500;
	chicken3_x = 300;
	chicken3_y = 400;

	egg_x = chicken1_x + 40;
	egg_y = chicken1_y - 30;

	egg1_x = chicken2_x + 40;
	egg1_y = chicken2_y - 30;

	egg2_x = chicken3_x + 40;
	egg2_y = chicken3_y - 30;


	stool_x = chicken1_x + 40;
	stool_y = chicken1_y - 30;

	score = 0;
	bonus = 0;
	drop = 0;
	minus_point = 0;
	total = 0;
}

#endif // GRAPHICS_H_INCLUDED
