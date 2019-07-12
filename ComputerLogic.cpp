#include"Model.h"

#define Maxdistance 20

void attack(Robotskill&skill, Robotdata&target) {
	int acc = skill.getaccuracy();
	int sp = target.getspeed();
	Fightingjudgement judge;
	if (judge.accuracyjudge(acc, sp))
		target.changehp(skill.getdamage() - target.getdefense());
	skill.use();
}

void moveto(location&currentlocation, int movetox, int movetoy) {
	gamemap map;
	map.move(currentlocation,movetox,movetoy);
	currentlocation.setlocation(movetox, movetoy);
}

void Model::cpumove() {
	int m = playerlist[1].getrobotnumber();
	for (int i = 0; i < m; i++) 
	{
		if (playerlist[1].playerrobot[i].getnowhp()) 
		{
			int x = playerlist[1].Robotlocation[i].getlocationx();
			int y = playerlist[1].Robotlocation[i].getlocationy();
			int tempd, target;
			int distance = Maxdistance;
			int p = playerlist[0].getrobotnumber();

			for (int j = 0; j < p; j++)
			{
				if (playerlist[0].playerrobot[j].getnowhp())
				{
					int x1 = playerlist[0].Robotlocation[j].getlocationx();
					int y1 = playerlist[0].Robotlocation[j].getlocationy();
					tempd = abs(x - x1) + abs(y - y1);
					if (tempd < Maxdistance)
					{
						distance = tempd;
						target = j;
					}
				}
			}

			int targetx= playerlist[0].Robotlocation[target].getlocationx();
			int targety= playerlist[0].Robotlocation[target].getlocationy();
			
			int j = playerlist[1].playerrobot[i].getskillnum();
			int skilluse;
			int skillrange = 0;

			for (int k = 0; k < j; k++)
			{
				if (playerlist[1].playerrobot[i].getskillinfo(k).getnowtimes())
				{
					tempd = playerlist[1].playerrobot[i].getskillinfo(k).getdistance();
					if (skillrange < tempd)
					{
						skillrange = tempd;
						skilluse = k;
					}
				}
				
			}
			Robotdata nowrobot= playerlist[1].playerrobot[i];

			if (skillrange >= distance)
				attack(nowrobot.getskillinfo(skilluse),playerlist[0].playerrobot[target]);
			else
			{
				int movetox, movetoy;
				int needtomove = distance - skillrange;
				int moverange = playerlist[1].playerrobot[i].getmoverange();
				int attackflag = 1;
				
				if (moverange < needtomove) 
				{
					needtomove = moverange;
					attackflag = 0;
				}
				
					int dx = x - targetx;
					int dy = x - targety;

					if (abs(dx) >= needtomove)
					{
						if (dx > 0)
							movetox = x - needtomove;
						else
							movetox = x + needtomove;
						movetoy = y;
					}
					else
					{
						movetox = targetx;
						needtomove -= abs(dx);
						if (dy > 0)
							movetoy = y - needtomove;
						else
							movetoy = y + needtomove;
					}

				moveto(playerlist[1].Robotlocation[i],movetox,movetoy);
					if (attackflag)
						attack(playerlist[1].playerrobot[i].getskillinfo(skilluse), playerlist[0].playerrobot[target]);
			}

			playerlist[1].done(i);
		}
	}
}