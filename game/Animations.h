#ifndef ANIMATIONS_H_INCLUDED
#define ANIMATIONS_H_INCLUDED
void move1()			//movement of the first chicken in level 1
{
	if(n==1)
	{
		chicken1_x += dp;
		chicken1_y += dq;
		if (chicken1_x + 110 >= sWidth || chicken1_x <= 0)
			dp *= (-1);
		if (chicken1_y + 140 >= sHeight || chicken1_y <= 500)
			dq *= (-1);
	}

}
void move2()			//movement of the first chicken in level 2
{
	if(n==1 && total>300 )
	{
		chicken2_x += da;
		chicken2_y += db;
		if (chicken2_x + 100 >= sWidth || chicken2_x <= 0)
			da *= (-1);
		if (chicken2_y + 120 >= sHeight || chicken2_y <= 500)
			db *= (-1);
	}

}


void move3()			//movement of the first chicken in level 3
{
	if(n==1 && total>500)
	{
		chicken3_x += de;
		chicken3_y += df;
		if (chicken3_x + 100 >= sWidth || chicken3_x <= 0)
			de *= (-1);
		if (chicken3_y + 120 >= sHeight || chicken3_y <= 400)
			df *= (-1);
	}

}

void moveDim1()			//movement of the regular egg
{
	if(n==1)
	{
		egg_y -= dm;


		if ( egg_y <= baskety + 30 && egg_x > basketx && egg_x < basketx + 70)		//score count for catching a regular egg
		{
			egg_x = chicken1_x + 40;
			egg_y = chicken1_y - 30;

			score += 10;

		}
		else if (egg_y < 10)			//gameover for droping 3 eggs
		{
			if (drop == 3)
			{
				isGameOver = true;
			}
			else
			{
				egg_x = chicken1_x + 40;
				egg_y = chicken1_y - 30;
			}
			drop += 1;

		}
	}

}
void moveDim2()			//movement of the black egg
{
	if(n==1)
	{
		if (total>300)
		{

			egg1_y -= dn;


			if (egg1_y <= baskety + 20 && egg1_x > basketx && egg1_x < basketx + 70)		//gameover for catching a black egg
			{
	
				isGameOver1 = true;
			}
			else if (egg1_y <= baskety + 30 && ((egg1_x < basketx) || (egg1_x > basketx + 70)))

			{

				egg1_x = chicken2_x + 40;
				egg1_y = chicken2_y - 30;

			}
		}
	}
}

void moveDim3()			//movement of the bonus egg
{
	if(n==1 && total>500)
	{
		egg2_y -= dk;

		//score count for catching bonus egg
		if (score>250 && egg2_y <= baskety + 30 && egg2_x > basketx && egg2_x < basketx + 70)
		{
			egg2_x = chicken3_x + 40;
			egg2_y = chicken3_y - 30;

			bonus += 30;
		}

		else if (egg2_y < 0)
		{
			egg2_x = chicken3_x + 40;
			egg2_y = chicken3_y - 30;
		}
	}
}
void movestool()			//movement of the stool
{
	if(n==1)
	{

		stool_y -= ds;

	//decreasing score for catching stool
		if (stool_y <= baskety + 30 && stool_x > basketx && stool_x < basketx + 70)
	
		{
			minus_point -= 5;

			stool_x = chicken1_x + 40;
			stool_y = chicken1_y - 30;

		}
		else if (stool_y < 10)
		{
			stool_x = chicken1_x + 40;
			stool_y = chicken1_y - 30;
		}
	}

}



#endif // ANIMATIONS_H_INCLUDED
