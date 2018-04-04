#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <stack>
#include <vector>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include <string.h>

#define ColorCode_Back			0
#define ColorCode_DarkBlue		1
#define ColorCode_DarkGreen		2
#define ColorCode_DarkCyan		3
#define ColorCode_DarkRed		4
#define ColorCode_DarkPink		5
#define ColorCode_DarkYellow	6
#define ColorCode_DarkWhite		7
#define ColorCode_Grey			8
#define ColorCode_Blue			9
#define ColorCode_Green			10
#define ColorCode_Cyan			11
#define ColorCode_Red			12
#define ColorCode_Pink			13
#define ColorCode_Yellow		14
#define ColorCode_White			15
#define default_ColorCode		7

#define consoleHeight 30
#define consoleWidth 80
#define bientrai 15
#define bienphai 40
#define bienduoi 44
#define intengame  42

using namespace std;

void gotoXY(int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void TextColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

//CHUONG TRÌNH

struct hinhdang
{
	char hinhxe[4][4];
	char hinhvc[4][4];
	char hinhvp[1][2];
	char hinhtengame[3][23];
};

struct toado
{
	int x; // cot
	int y; // hang
};

struct Xe
{
	hinhdang hd;
	toado td;
	int diem;
};

struct VatCan
{
	hinhdang hd;
	toado td;
};

struct VatPham
{
	hinhdang hd;
	toado td;
};

class XE
{
public:
	XE()
	{
		khoiTaoXe();
		khoiTaoVatCan();
		khoiTaoVatPham();
		khoitaotengame();
	}


	void Hien_thi_trang_thai_game()
	{
		hienThiBien();
		hienThiXe();
		hienThiVatCan();
		hienThiVatPham();
		hienthitengame();
	}

	int Xu_ly_game(int &toSleep)
	{
		vc1.td.y++;


		if (vc1.td.y == bienduoi)
		{
			vc1.td.x = randomToaDo();
			vc1.td.y = -4;
			xe.diem++;
			if (toSleep > 40)
				toSleep -= 10;
		}


		if (vc1.td.y > bienduoi / (rand() % 5 + 1) || vc2.td.y != -4)
			vc2.td.y++;


		if (vc2.td.y == bienduoi)
		{
			vc2.td.x = randomToaDo();
			vc2.td.y = -4;
			xe.diem++;
			if (toSleep > 40)
				toSleep -= 10;
		}

		if (vc2.td.y > bienduoi / (rand() % 5 + 1) || vc3.td.y != -4)
			vc3.td.y++;



		if (vc3.td.y == bienduoi)
		{
			vc3.td.x = randomToaDo();
			vc3.td.y = -4;

			xe.diem++;
			if (toSleep > 40)
				toSleep -= 10;
		}

		if (vc3.td.y > bienduoi / (rand() % 5 + 1) || vc4.td.y != -4)
			vc4.td.y++;



		if (vc4.td.y == bienduoi)
		{
			vc4.td.x = randomToaDo();
			vc4.td.y = -4;

			xe.diem++;
			if (toSleep > 40)
				toSleep -= 10;
		}



		if ((xe.diem % 10 == 0 || vp.td.y != -1) && xe.diem != 0)
			 vp.td.y++;

		if (vp.td.y == bienduoi)
		{
			vp.td.y = -1;
			int  tmptdx = 1 + rand() % (bienphai - bientrai - 1) + 15;
			if (tmptdx > 15 && tmptdx < 20)
				vp.td.x = 17;
			else if (tmptdx >= 20 && tmptdx < 25)
				vp.td.x = 22;
			else if (tmptdx >= 25 && tmptdx < 30)
				vp.td.x = 27;
			else if (tmptdx >= 30 && tmptdx < 35)
				vp.td.x = 32;
			else if (tmptdx >= 35 && tmptdx < 40)
				vp.td.x = 37;
		}

		if ((vp.td.y - xe.td.y <= 3) && (vp.td.x - xe.td.x <= 1) && (vp.td.y - xe.td.y >= 0))
		{
			xe.diem += 5;
			vp.td.y = -1;
			int  tmptdx = 1 + rand() % (bienphai - bientrai - 1) + 15;
			if (tmptdx > 15 && tmptdx < 20)
				vp.td.x = 17;
			else if (tmptdx >= 20 && tmptdx < 25)
				vp.td.x = 22;
			else if (tmptdx >= 25 && tmptdx < 30)
				vp.td.x = 27;
			else if (tmptdx >= 30 && tmptdx < 35)
				vp.td.x = 32;
			else if (tmptdx >= 35 && tmptdx < 40)
				vp.td.x = 37;

		}

		if (abs(vc1.td.x - xe.td.x) <= 3 && abs(vc1.td.y - xe.td.y) <= 3)
			return 0;
		if (abs(xe.td.x - vc2.td.x) <= 3 && abs(xe.td.y - vc2.td.y) <= 3)
			return 0;
		if (abs(xe.td.x - vc3.td.x) <= 3 && abs(xe.td.y - vc3.td.y) <= 3)
			return 0;
        if (abs(xe.td.x - vc4.td.x) <= 3 && abs(xe.td.y - vc4.td.y) <= 3)
			return 0;
	}

	void Dieu_khien_game()
	{
		if (kbhit())
		{
			char key = getch();

			if ((key == 'A' || key == 'a') && xe.td.x > bientrai + 1)
                xe.td.x -= 5;
            else if ((key == 'd' || key == 'D') && xe.td.x < bienphai - 4)
                xe.td.x += 5;
            else if ((key == 'w' || key == 'W') && xe.td.y >= 1)
                xe.td.y -= 2;
            else if ((key == 's' || key == 'S') && xe.td.y < bienduoi - 4)
                xe.td.y += 2;

		}
	}

	int GetDiem()
	{
		return xe.diem;
	}

private:
	Xe xe;
	VatCan vc1, vc2, vc3, vc4;
	VatPham vp;
	vector < vector < char > > tengame ;
    void khoiTaoVatPham()
	{
		khoiTaoHinhVatPham();
		khoiTaoToaDoVatPham();
	}

	void khoiTaoHinhVatPham()
	{
		vp.hd.hinhvp[0][0] = '$';
		vp.hd.hinhvp[0][1] = '$';
	}

	void khoiTaoToaDoVatPham()
	{
		vp.td.y = -1;
		int tmptdx = 1 + rand() % (bienphai - bientrai - 1) + 15;
		if (tmptdx > 15 && tmptdx < 20)
			vp.td.x = 17;
		else if (tmptdx >= 20 && tmptdx < 25)
			vp.td.x = 22;
		else if (tmptdx >= 25 && tmptdx < 30)
			vp.td.x = 27;
		else if (tmptdx >= 30 && tmptdx < 35)
			vp.td.x = 32;
		else if (tmptdx >= 35 && tmptdx < 40)
			vp.td.x = 37;
	}

	void khoiTaoXe()
	{
		khoiTaoHinhXe();
		khoiTaoToaDoXe();
	}

	void khoiTaoHinhXe()
	{
		xe.hd.hinhxe[0][0] = 237;
		xe.hd.hinhxe[0][1] = 234;
		xe.hd.hinhxe[0][2] = 234;
		xe.hd.hinhxe[0][3] = 237;
		xe.hd.hinhxe[1][0] = '|';
		xe.hd.hinhxe[1][1] = 175;
		xe.hd.hinhxe[1][2] = 175;
		xe.hd.hinhxe[1][3] = '|';
		xe.hd.hinhxe[2][0] = '|';
		xe.hd.hinhxe[2][1] = 175;
		xe.hd.hinhxe[2][2] = 175;
		xe.hd.hinhxe[2][3] = '|';
		xe.hd.hinhxe[3][0] = 237;
		xe.hd.hinhxe[3][1] = 207;
		xe.hd.hinhxe[3][2] = 207;
		xe.hd.hinhxe[3][3] = 237;
	}

	void khoiTaoToaDoXe()
	{
		xe.td.y = bienduoi - 4;
		xe.diem = 0;

		xe.td.x = randomToaDo();
	}

	void khoiTaoVatCan()
	{
		khoiTaoHinhVatCan();
		khoiTaoToaDoVatCan();
	}

	void khoiTaoHinhVatCan()
	{
		vc1.hd.hinhvc[0][0] = 234;
		vc1.hd.hinhvc[0][1] = 234;
		vc1.hd.hinhvc[0][2] = 234;
		vc1.hd.hinhvc[0][3] = 234;
		vc1.hd.hinhvc[1][0] = 247;
		vc1.hd.hinhvc[1][1] = 247;
		vc1.hd.hinhvc[1][2] = 247;
		vc1.hd.hinhvc[1][3] = 247;
		vc1.hd.hinhvc[2][0] = 247;
		vc1.hd.hinhvc[2][1] = 247;
		vc1.hd.hinhvc[2][2] = 247;
		vc1.hd.hinhvc[2][3] = 247;
		vc1.hd.hinhvc[3][0] = 234;
		vc1.hd.hinhvc[3][1] = 234;
		vc1.hd.hinhvc[3][2] = 234;
		vc1.hd.hinhvc[3][3] = 234;

		vc2.hd.hinhvc[0][0] = 234;
		vc2.hd.hinhvc[0][1] = 234;
		vc2.hd.hinhvc[0][2] = 234;
		vc2.hd.hinhvc[0][3] = 234;
		vc2.hd.hinhvc[1][0] = 247;
		vc2.hd.hinhvc[1][1] = 247;
		vc2.hd.hinhvc[1][2] = 247;
		vc2.hd.hinhvc[1][3] = 247;
		vc2.hd.hinhvc[2][0] = 247;
		vc2.hd.hinhvc[2][1] = 247;
		vc2.hd.hinhvc[2][2] = 247;
		vc2.hd.hinhvc[2][3] = 247;
		vc2.hd.hinhvc[3][0] = 234;
		vc2.hd.hinhvc[3][1] = 234;
		vc2.hd.hinhvc[3][2] = 234;
		vc2.hd.hinhvc[3][3] = 234;

		vc3.hd.hinhvc[0][0] = 234;
		vc3.hd.hinhvc[0][1] = 234;
		vc3.hd.hinhvc[0][2] = 234;
		vc3.hd.hinhvc[0][3] = 234;
		vc3.hd.hinhvc[1][0] = 247;
		vc3.hd.hinhvc[1][1] = 247;
		vc3.hd.hinhvc[1][2] = 247;
		vc3.hd.hinhvc[1][3] = 247;
		vc3.hd.hinhvc[2][0] = 247;
		vc3.hd.hinhvc[2][1] = 247;
		vc3.hd.hinhvc[2][2] = 247;
		vc3.hd.hinhvc[2][3] = 247;
		vc3.hd.hinhvc[3][0] = 234;
		vc3.hd.hinhvc[3][1] = 234;
		vc3.hd.hinhvc[3][2] = 234;
		vc3.hd.hinhvc[3][3] = 234;

		vc4.hd.hinhvc[0][0] = 234;
		vc4.hd.hinhvc[0][1] = 234;
		vc4.hd.hinhvc[0][2] = 234;
		vc4.hd.hinhvc[0][3] = 234;
		vc4.hd.hinhvc[1][0] = 247;
		vc4.hd.hinhvc[1][1] = 247;
		vc4.hd.hinhvc[1][2] = 247;
		vc4.hd.hinhvc[1][3] = 247;
		vc4.hd.hinhvc[2][0] = 247;
		vc4.hd.hinhvc[2][1] = 247;
		vc4.hd.hinhvc[2][2] = 247;
		vc4.hd.hinhvc[2][3] = 247;
		vc4.hd.hinhvc[3][0] = 234;
		vc4.hd.hinhvc[3][1] = 234;
		vc4.hd.hinhvc[3][2] = 234;
		vc4.hd.hinhvc[3][3] = 234;

	}

	void khoiTaoToaDoVatCan()
	{

		vc1.td.x = randomToaDo();
		vc1.td.y = -4;

		vc2.td.x = randomToaDo();
		vc2.td.y = -4;

		vc3.td.x = randomToaDo();
		vc3.td.y = -4;

		vc4.td.x = randomToaDo();
		vc4.td.y = -4;
	}

	void hienThiBien()
	{
		system("cls");
		for (int i = 0; i < bienduoi; i++)
		{
			gotoXY(15, i);
			cout << (char) 176;
		}
		for (int i = 0; i < bienduoi; i++)
		{
			gotoXY(20, i);
			cout << '|';
		}
		for (int i = 0; i < bienduoi; i++)
		{
			gotoXY(25, i);
			cout << '|';
		}
		for (int i = 0; i < bienduoi; i++)
		{
			gotoXY(30, i);
			cout << '|';
		}
		for (int i = 0; i < bienduoi; i++)
		{
			gotoXY(35, i);
			cout << '|';
		}
		for (int i = 0; i < bienduoi; i++)
		{
			gotoXY(40, i);
			cout << (char) 176;
		}

		gotoXY(2, 14);
		cout << "DIEM : " << xe.diem;

	}

	void hienThiXe()
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				int tmpx = xe.td.x + i;
				int tmpy = xe.td.y + j;
				gotoXY(tmpx, tmpy);
				cout << xe.hd.hinhxe[j][i];
			}
		}
	}

	void hienThiVatCan()
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				int tmpx = vc1.td.x + i;
				int tmpy = vc1.td.y + j;
				if (tmpy >= 0 && tmpy < bienduoi)
				{
					gotoXY(tmpx, tmpy);
					cout << vc1.hd.hinhvc[j][i];
				}
			}
		}
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				int tmpx = vc2.td.x + i;
				int tmpy = vc2.td.y + j;
				if (tmpy >= 0 && tmpy < bienduoi)
				{
					gotoXY(tmpx, tmpy);
					cout << vc2.hd.hinhvc[j][i];
				}
			}
		}

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				int tmpx = vc3.td.x + i;
				int tmpy = vc3.td.y + j;
				if (tmpy >= 0 && tmpy < bienduoi)
				{
					gotoXY(tmpx, tmpy);
					cout << vc3.hd.hinhvc[j][i];
				}
			}
		}

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				int tmpx = vc4.td.x + i;
				int tmpy = vc4.td.y + j;
				if (tmpy >= 0 && tmpy < bienduoi)
				{
					gotoXY(tmpx, tmpy);
					cout << vc1.hd.hinhvc[j][i];
				}
			}
		}
	}

	void hienThiVatPham()
	{
	    if(vp.td.y != -1 && vp.td.y < bienduoi)
        {
            gotoXY(vp.td.x, vp.td.y);
            cout << vp.hd.hinhvp[0][0] << vp.hd.hinhvp[0][1];
        }


    }

	int randomToaDo()
	{
		int tmptdx = 1 + rand() % (bienphai - bientrai - 1) + 15;
		if (tmptdx > 15 && tmptdx < 20)
			return 16;
		else if (tmptdx >= 20 && tmptdx < 25)
			return 21;
		else if (tmptdx >= 25 && tmptdx < 30)
			return 26;
		else if (tmptdx >= 30 && tmptdx < 35)
			return 31;
		else if (tmptdx >= 35 && tmptdx < 40)
			return 36;
	}
	void khoitaotengame()
	{
       int column = 23;
	   for( int i = 0; i < 3; i++)
        tengame.push_back( vector < char > (column));

       tengame[0][0] = 'D';
       tengame[0][1] = 'D';
       tengame[0][2] = ' ';
       tengame[0][3] = ' ';
       tengame[0][4] = 'D';
       tengame[0][5] = ' ';
       tengame[0][6] = 'D';
       tengame[0][7] = ' ';
       tengame[0][8] = ' ';
       tengame[0][9] = ' ';
       tengame[0][10] = 'D';
       tengame[0][11] = ' ';
       tengame[0][12] = ' ';
       tengame[0][13] = ' ';
       tengame[0][14] = ' ';
       tengame[0][15] = ' ';
       tengame[0][16] = 'D';
       tengame[0][17] = ' ';
       tengame[0][18] = 'D';
       tengame[0][19] = ' ';
       tengame[0][20] = 'D';
       tengame[0][21] = 'D';
       tengame[0][22] = 'D';


       tengame[1][0] = 'D';
       tengame[1][1] = ' ';
       tengame[1][2] = 'D';
       tengame[1][3] = ' ';
       tengame[1][4] = 'D';
       tengame[1][5] = ' ';
       tengame[1][6] = 'D';
       tengame[1][7] = ' ';
       tengame[1][8] = ' ';
       tengame[1][9] = 'D';
       tengame[1][10] = ' ';
       tengame[1][11] = 'D';
       tengame[1][12] = ' ';
       tengame[1][13] = ' ';
       tengame[1][14] = ' ';
       tengame[1][15] = ' ';
       tengame[1][16] = ' ';
       tengame[1][17] = 'D';
       tengame[1][18] = ' ';
       tengame[1][19] = ' ';
       tengame[1][20] = 'D';
       tengame[1][21] = 'D';
       tengame[1][22] = ' ';


       tengame[2][0] = 'D';
       tengame[2][1] = 'D';
       tengame[2][2] = ' ';
       tengame[2][3] = ' ';
       tengame[2][4] = 'D';
       tengame[2][5] = 'D';
       tengame[2][6] = 'D';
       tengame[2][7] = ' ';
       tengame[2][8] = 'D';
       tengame[2][9] = ' ';
       tengame[2][10] = ' ';
       tengame[2][11] = ' ';
       tengame[2][12] = 'D';
       tengame[2][13] = ' ';
       tengame[2][14] = ' ';
       tengame[2][15] = ' ';
       tengame[2][16] = 'D';
       tengame[2][17] = ' ';
       tengame[2][18] = 'D';
       tengame[2][19] = ' ';
       tengame[2][20] = 'D';
       tengame[2][21] = 'D';
       tengame[2][22] = 'D';



	}
	void hienthitengame()
	{
	    gotoXY(42,2);
	    for( int i = 0; i < 3; i++)
        {
            for( int j = 0; j < 23; j++)
            {
               gotoXY(42 + j, 2 + i);
               cout << tengame[i][j];
            }
        }
	}
};

int main()
{
	srand(time(NULL));
	char xulituychon;
	int toSleep = 200;
	XE xeclass;
	cout << "1/ Let's go" << endl <<"2/ Exit";
	xulituychon = getch();
	if (xulituychon == '1')
	{
		int xuli2;
		while(true)
        {
            xeclass.Dieu_khien_game();
            xuli2 = xeclass.Xu_ly_game(toSleep);
            xeclass.Hien_thi_trang_thai_game();

            if( xuli2 == 0)
            {
                system("cls");
                gotoXY(1, 1);
                cout << "Game over " << endl << "Diem cua ban: " << xeclass.GetDiem();
                break;
                system("pause");
            }
            Sleep(toSleep);
        }
	}
	else if (xulituychon == '2')
	{
		system("cls");
		cout << "HEN GAP LAI\t\t\t";
		system("pause");
	}
}
