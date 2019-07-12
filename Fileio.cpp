#include"Model.h"

void Robotfile::read() {
	ifstream rob("Robotdata.txt");

	while (!rob.eof()) {
		char name[20];
		rob.getline(name, 20, '#');
		char num[4];
		rob.getline(num, 4, '#');
		int mhp = atoi(num);
		rob.getline(num, 4, '#');
		int nhp = atoi(num);
		rob.getline(num, 4, '#');
		int range = atoi(num);
		rob.getline(num, 4, '#');
		int sp = atoi(num);
		rob.getline(num, 4, '#');
		int de = atoi(num);
		Robotdata temp(name, mhp, nhp, range, sp, de);
		rob.getline(num, 4, '#');
		int numofskill = atoi(num);
		vector<int> skilltype;
		for (int i = 0; i < numofskill; i++)
		{
			rob.getline(num, 4, '#');
			skilltype.push_back(atoi(num));
		}

		temp.setskill(skilltype);
		Robotdatalist.push_back(temp);
	}
	rob.close();
}

void Skillfile::read() {
	ifstream skl("Skilldata.txt");
	while (!skl.eof()) {
		char name[20];
		skl.getline(name, 20, '#');
		char num[4];
		skl.getline(num, 4, '#');
		int dmg = atoi(num);
		skl.getline(num, 4, '#');
		int dis = atoi(num);
		skl.getline(num, 4, '#');
		int acc = atoi(num);
		skl.getline(num, 4, '#');
		int mtimes = atoi(num);
		Robotskill temp(name, dmg, dis, acc, mtimes);
		Robotskilllist.push_back(temp);
	}
	skl.close();
}

void Model::readstage(int stagenum) {
	char stagen[3];
	itoa(stagenum, stagen, 10);
	string filename = "Stage";
	for (int i = 0; i < 3 && stagen[i] != '\0'; i++)
		filename += stagen[i];
	ifstream sta(filename);
	gmap.setmap();
	while (!sta.eof())
		for (int i = 0; i < 2; i++) {
			char num[4];
			sta.getline(num, 4, '#');
			int robnum = atoi(num);
			vector<int> robtype;
			vector<location> loc;
			for (int j; j < robnum; j++) {
				sta.getline(num, 4, '#');
				robtype.push_back(atoi(num));
				sta.getline(num, 4, '#');
				int x = atoi(num);
				sta.getline(num, 4, '#');
				int y = atoi(num);
				location templ;
				templ.setlocation(x, y);
				loc.push_back(templ);
			}

			playerlist[i].setlist(Robotdatalist, robtype, loc);
			gmap.setrobotmap(robtype, loc, i);
		}
	sta.close();
}