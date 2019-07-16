#include"Model.h"
#include<Windows.h>

#define Maxdistance 20

void Model::attack(Robotskill&skill, Robotdata&target,location&targetlocation) {
	int acc = skill.getaccuracy();
	int sp = target.getspeed();
	int x = targetlocation.getlocationx();
	int y = targetlocation.getlocationy();
	Fightingjudgement judge;
	if (judge.accuracyjudge(acc, sp))
	{
		int dmg = skill.getdamage() - target.getdefense();
		target.changehp(dmg);
	}
	skill.use();
	string str = "attack" + to_string(x) + "," + to_string(y);
	Fire_OnPropertyChanged(str);
	Sleep(1200);

	
}

void Model::moveto(location&currentlocation, int movetox, int movetoy) {
	gmap.move(currentlocation,movetox,movetoy);
	currentlocation.setlocation(movetox, movetoy);
	Fire_OnPropertyChanged("robots");
	Sleep(1200);
}

void Model::cpumove() {
	int m = playerlist[1].getrobotnumber();
	for (int i = 0; i < m; i++) 
	{
		if (playerlist[1].playerrobot[i].getnowhp()) 
		{
			int x = playerlist[1].Robotlocation[i].getlocationx();
			int y = playerlist[1].Robotlocation[i].getlocationy();
			int tempd, target=-1;
			int distance = Maxdistance;
			int p = playerlist[0].getrobotnumber();

			for (int j = 0; j < p; j++)
			{
				if (playerlist[0].playerrobot[j].getnowhp())
				{
					int x1 = playerlist[0].Robotlocation[j].getlocationx();
					int y1 = playerlist[0].Robotlocation[j].getlocationy();
					tempd = abs(x - x1) + abs(y - y1);
					if (tempd < distance)
					{
						distance = tempd;
						target = j;
					}
				}
			}
			int targetx= playerlist[0].Robotlocation[target].getlocationx();
			int targety= playerlist[0].Robotlocation[target].getlocationy();
			int xa = 0;int ya=0;
			
			
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
				attack(nowrobot.getskillinfo(skilluse),playerlist[0].playerrobot[target],playerlist[0].Robotlocation[target]);
			else
			{
				int movetox, movetoy;
				int needtomove = distance - skillrange;
				int moverange = playerlist[1].playerrobot[i].getmoverange();
				//int attackflag = 1;
				
				if (moverange < needtomove) 
				{
					needtomove = moverange;
					//attackflag = 0;
				}
				
					int dx = x - targetx;
					int dy = y - targety;

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
					while(gmap.getrobot(movetox, movetoy) != -1) {
						if (dx > 0)
							movetox++;
						else
							movetox--;
						if (dy > 0)
							movetoy--;
						else
							movetoy++;

					}
					if (movetox < 0)
						movetox = 0;
					else if (movetox > 19)
						movetox = 19;
					if (movetoy < 0)
						movetoy = 0;
					else if (movetoy > 19)
						movetoy = 19;
					
					

				moveto(playerlist[1].Robotlocation[i],movetox,movetoy);
					//if (attackflag)
				int skilldistance = abs(movetox - playerlist[0].Robotlocation[target].getlocationx()) + abs(movetoy - playerlist[0].Robotlocation[target].getlocationy());
				if(skilldistance<= playerlist[1].playerrobot[i].getskillinfo(skilluse).getdistance())
						attack(playerlist[1].playerrobot[i].getskillinfo(skilluse), playerlist[0].playerrobot[target], playerlist[0].Robotlocation[target]);
			}

			playerlist[1].done(i);
			Fire_OnPropertyChanged("robots");
			Sleep(1000);
		}
		if (winorlose() == 1)
		{
			Fire_OnPropertyChanged("win");
			return;
		}
			

		if (winorlose() == -1) {
			Fire_OnPropertyChanged("lose");
			return;
		}
			
	}
}