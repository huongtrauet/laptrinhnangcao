#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <cstring>
#include <windows.h>
#include <stdio.h>
#include <time.h>
using namespace std;




/*
int inputKey()
{
	if (_kbhit())
	{
		int key = _getch();
		if (key == 224)	// special key
		{
			key = _getch();
			return key + 1000;
		}
		return key;
	}
	else
	{
		return key_none;
	}
	return key_none;
} */


//-------------------------Screen-------------------------
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
void clrscr()
{
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;
	HANDLE	hConsoleOut;
	COORD	Home = {0,0};
	DWORD	dummy;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut,&csbiInfo);

	FillConsoleOutputCharacter(hConsoleOut,' ',csbiInfo.dwSize.X * csbiInfo.dwSize.Y,Home,&dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut,csbiInfo.dwCursorPosition);
}


//screen: goto [x,y]
void gotoXY (int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}


//screen: get [x]
int whereX()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if(GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}


//screen: get [y]
int whereY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if(GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.Y;
	return -1;
}


void TextColor (int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , color);
}

    // CHƯƠNG TRÌNH ============================================

#define consoleHeight 30
#define consoleWidth 80
#define bientrai 15
#define bienphai 40
#define bienduoi 29
#define intengame  42

struct hinhdang
{
    char hinhxe[4][4];
    char hinhvc[4][4];
    char hinhvp[2][2];
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
void khoitao(Xe &xe, VatCan &vc1, VatCan &vc2, VatCan &vc3, VatPham &vp)
{
    // khởi tạo tên game

    // khởi tạo xe
    xe.hd.hinhxe[0][0] = 237;
    xe.hd.hinhxe[0][1] = 234;
    xe.hd.hinhxe[0][2] = 234;
    xe.hd.hinhxe[0][4] = 237;
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


    xe.td.y = bienduoi - 4;
    xe.td.x = bientrai + 4 * 1 + 2;

    xe.diem = 0;

    // khởi tạo vật cản
    vc1.hd.hinhvc[0][0]='*';
    vc1.hd.hinhvc[0][1]='*';
    vc1.hd.hinhvc[0][2]='*';
    vc1.hd.hinhvc[0][3]='*';
    vc1.hd.hinhvc[1][0]='*';
    vc1.hd.hinhvc[1][1]='*';
    vc1.hd.hinhvc[1][2]='*';
    vc1.hd.hinhvc[1][3]='*';
    vc1.hd.hinhvc[2][0]='*';
    vc1.hd.hinhvc[2][1]='*';
    vc1.hd.hinhvc[2][2]='*';
    vc1.hd.hinhvc[2][3]='*';
    vc1.hd.hinhvc[3][0]='*';
    vc1.hd.hinhvc[3][1]='*';
    vc1.hd.hinhvc[3][2]='*';
    vc1.hd.hinhvc[3][3]='*';

    vc2.hd.hinhvc[0][0]='*';
    vc2.hd.hinhvc[0][1]='*';
    vc2.hd.hinhvc[0][2]='*';
    vc2.hd.hinhvc[0][3]='*';
    vc2.hd.hinhvc[1][0]='*';
    vc2.hd.hinhvc[1][1]='*';
    vc2.hd.hinhvc[1][2]='*';
    vc2.hd.hinhvc[1][3]='*';
    vc2.hd.hinhvc[2][0]='*';
    vc2.hd.hinhvc[2][1]='*';
    vc2.hd.hinhvc[2][2]='*';
    vc2.hd.hinhvc[2][3]='*';
    vc2.hd.hinhvc[3][0]='*';
    vc2.hd.hinhvc[3][1]='*';
    vc2.hd.hinhvc[3][2]='*';
    vc2.hd.hinhvc[3][3]='*';

    vc3.hd.hinhvc[0][0]='*';
    vc3.hd.hinhvc[0][1]='*';
    vc3.hd.hinhvc[0][2]='*';
    vc3.hd.hinhvc[0][3]='*';
    vc3.hd.hinhvc[1][0]='*';
    vc3.hd.hinhvc[1][1]='*';
    vc3.hd.hinhvc[1][2]='*';
    vc3.hd.hinhvc[1][3]='*';
    vc3.hd.hinhvc[2][0]='*';
    vc3.hd.hinhvc[2][1]='*';
    vc3.hd.hinhvc[2][2]='*';
    vc3.hd.hinhvc[2][3]='*';
    vc3.hd.hinhvc[3][0]='*';
    vc3.hd.hinhvc[3][1]='*';
    vc3.hd.hinhvc[3][2]='*';
    vc3.hd.hinhvc[3][3]='*';

    int tmptdx = 1 + rand() % (bienphai - bientrai-1) + 15;
    if(tmptdx > 15 && tmptdx < 20)
        vc1.td.x = 16;
    else if(tmptdx >=20 && tmptdx < 25)
        vc1.td.x = 21;
    else if(tmptdx >=25 && tmptdx < 30)
        vc1.td.x = 26;
    else if(tmptdx >=30 && tmptdx < 35)
        vc1.td.x = 31;
    else if(tmptdx >=35 && tmptdx < 40)
        vc1.td.x = 36;
    vc1.td.y = -4;

     tmptdx = 1 + rand() % (bienphai - bientrai-1) + 15;
    if(tmptdx > 15 && tmptdx < 20)
        vc2.td.x = 16;
    else if(tmptdx >=20 && tmptdx < 25)
        vc2.td.x = 21;
    else if(tmptdx >=25 && tmptdx < 30)
        vc2.td.x = 26;
    else if(tmptdx >=30 && tmptdx < 35)
        vc2.td.x = 31;
    else if(tmptdx >=35 && tmptdx < 40)
        vc2.td.x = 36;
    vc2.td.y = -4;

     tmptdx = 1 + rand() % (bienphai - bientrai-1) + 15;
    if(tmptdx > 15 && tmptdx < 20)
        vc3.td.x = 16;
    else if(tmptdx >=20 && tmptdx < 25)
        vc3.td.x = 21;
    else if(tmptdx >=25 && tmptdx < 30)
        vc3.td.x = 26;
    else if(tmptdx >=30 && tmptdx < 35)
        vc3.td.x = 31;
    else if(tmptdx >=35 && tmptdx < 40)
        vc3.td.x = 36;
    vc3.td.y = -4;


    // khởi tạo vật phẩm
    vp.hd.hinhvp[0][0]='$';
    vp.hd.hinhvp[0][1]='$';
    vp.hd.hinhvp[1][0]='$';
    vp.hd.hinhvp[1][1]='$';

    vp.td.y = -2;
    tmptdx = 1 + rand() % (bienphai - bientrai-1) + 15;
    if(tmptdx > 15 && tmptdx < 20)
        vp.td.x = 17;
    else if(tmptdx >=20 && tmptdx < 25)
        vp.td.x = 22;
    else if(tmptdx >=25 && tmptdx < 30)
        vp.td.x = 27;
    else if(tmptdx >=30 && tmptdx < 35)
        vc3.td.x = 32;
    else if(tmptdx >=35 && tmptdx < 40)
        vp.td.x = 37;

}
void Hien_thi_trang_thai_game(Xe xe, VatCan vc1, VatCan vc2, VatCan vc3, VatPham vp, char tengame[][23])
{
    system("cls");
    // hiển thị biên
    for(int i = 0; i < bienduoi; i++)
    {
         gotoXY(15, i);
         cout << '#';
    }
     for(int i = 0; i < bienduoi; i++)
    {
         gotoXY(20, i);
         cout << '|';
    }
     for(int i = 0; i < bienduoi; i++)
    {
         gotoXY(25, i);
         cout << '|';
    }
     for(int i = 0; i < bienduoi; i++)
    {
         gotoXY(30, i);
         cout << '|';
    }
     for(int i = 0; i < bienduoi; i++)
    {
         gotoXY(35, i);
         cout << '|';
    }
     for(int i = 0; i < bienduoi; i++)
    {
         gotoXY(40, i);
         cout << '#';
    }

  //  gotoXY(15, bienduoi);
  //  for(int i = 15; i <= 40; i++)
   //     cout << '#';
     // hiển thị tên game
 /*    for(int i = 0; i < 3; i++)
     {
         for(int j = 0; j < 23; j++)
         {
             int tmpx = intengame + j;
             int tmpy = 1 + i;
             gotoXY(tmpx, tmpy);
             putch(tengame[i][j]);
         }
     } */

    //hiển thị xe
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            int tmpx = xe.td.x + i;
            int tmpy = xe.td.y + j;
            gotoXY(tmpx, tmpy);
            putch(xe.hd.hinhxe[j][i]);
        }
    }

    // hiển thị vật cản
    for(int i = 0; i < 4; i++)
    {
        for( int j = 0; j < 4; j++ )
        {
            int tmpx = vc1.td.x + i;
            int tmpy = vc1.td.y + j;
            if(tmpy >= 0 && tmpy < bienduoi)
            {
                gotoXY(tmpx, tmpy);
                putch(vc1.hd.hinhvc[j][i]);
            }
        }
    }
    for(int i = 0; i < 4; i++)
    {
        for( int j = 0; j < 4; j++ )
        {
            int tmpx = vc2.td.x + i;
            int tmpy = vc2.td.y + j;
            if(tmpy >= 0 && tmpy < bienduoi)
            {
                gotoXY(tmpx, tmpy);
                putch(vc2.hd.hinhvc[j][i]);
            }
        }
    }

    for(int i = 0; i < 4; i++)
    {
        for( int j = 0; j < 4; j++ )
        {
            int tmpx = vc3.td.x + i;
            int tmpy = vc3.td.y + j;
            if(tmpy >= 0 && tmpy < bienduoi)
            {
                gotoXY(tmpx, tmpy);
                putch(vc3.hd.hinhvc[j][i]);
            }
        }
    }

    // hiển thị vật phẩm
    for(int i = 0; i < 2; i++)
    {
        for( int j = 0; j < 2; j++)
        {
          int  tmpx = vp.td.x + i;
          int  tmpy = vp.td.y + j;
            if(tmpy < bienduoi && tmpy >= 0)
            {
                gotoXY(tmpx, tmpy);
                putch(vp.hd.hinhvp[j][i]);
            }
        }
    }
    gotoXY(2, 14);
    cout << "DIEM : " << xe.diem;

    // hiển thị chỉ dẫn
    gotoXY(42, 5);
    cout << "Chon 1 de thoat game.";
    gotoXY(42, 6);
    cout << "Chon 2 de tam dung.";


}

int Xu_ly_game(Xe &xe, VatCan &vc1, VatCan &vc2, VatCan &vc3, int &toSleep, VatPham &vp)
{   // vc1 di chuyển
    vc1.td.y ++;

    // vc1 chạm biên
    if(vc1.td.y == bienduoi)
    {
        int tmptdx = 1 + rand() % (bienphai - bientrai-1) + 15;
        if(tmptdx > 15 && tmptdx < 20)
            vc1.td.x = 16;
        else if(tmptdx >=20 && tmptdx < 25)
            vc1.td.x = 21;
        else if(tmptdx >=25 && tmptdx < 30)
            vc1.td.x = 26;
        else if(tmptdx >=30 && tmptdx < 35)
            vc1.td.x = 31;
        else if(tmptdx >=35 && tmptdx < 40)
            vc1.td.x = 36;
    vc1.td.y = -4;
    xe.diem ++;
    if(toSleep > 40)
        toSleep -=10;
    }


    // vc2 xuất hiện khi vc1 đi quá 1/3
    if(vc1.td.y > bienduoi/3 || vc2.td.y != -4)
        vc2.td.y++;

    // vc2 chạm biên
    if(vc2.td.y == bienduoi)
    {
        int tmptdx = 1 + rand() % (bienphai - bientrai-1) + 15;
        if(tmptdx > 15 && tmptdx < 20)
            vc2.td.x = 16;
        else if(tmptdx >=20 && tmptdx < 25)
            vc2.td.x = 21;
        else if(tmptdx >=25 && tmptdx < 30)
            vc2.td.x = 26;
        else if(tmptdx >=30 && tmptdx < 35)
            vc2.td.x = 31;
        else if(tmptdx >=35 && tmptdx < 40)
            vc2.td.x = 36;
        vc2.td.y = -4;
        xe.diem ++;
        if(toSleep > 40)
            toSleep -= 10;
    }

     // vc2 xuất hiện khi vc1 đi quá 1/3
    if(vc2.td.y > bienduoi/3 || vc3.td.y != -4)
        vc3.td.y++;


    // vc3 chạm biên
    if(vc3.td.y == bienduoi)
    {
        int tmptdx = 1 + rand() % (bienphai - bientrai-1) + 15;
        if(tmptdx > 15 && tmptdx < 20)
                vc3.td.x = 16;
        else if(tmptdx >=20 && tmptdx < 25)
            vc3.td.x = 21;
        else if(tmptdx >=25 && tmptdx < 30)
            vc3.td.x = 26;
        else if(tmptdx >=30 && tmptdx < 35)
            vc3.td.x = 31;
        else if(tmptdx >=35 && tmptdx < 40)
            vc3.td.x = 36;
        vc3.td.y = -4;

        xe.diem ++;
        if(toSleep > 40)
            toSleep -= 10;
    }
        // rơi vật phẩm
     if((xe.diem % 10 == 0 || vp.td.y != -2) && xe.diem != 0)
        vp.td.y ++;

    if(vp.td.y == bienduoi)
    {
        vp.td.y = -2;
    int  tmptdx = 1 + rand() % (bienphai - bientrai-1) + 15;
    if(tmptdx > 15 && tmptdx < 20)
        vp.td.x = 17;
    else if(tmptdx >=20 && tmptdx < 25)
        vp.td.x = 22;
    else if(tmptdx >=25 && tmptdx < 30)
        vp.td.x = 27;
    else if(tmptdx >=30 && tmptdx < 35)
        vc3.td.x = 32;
    else if(tmptdx >=35 && tmptdx < 40)
        vp.td.x = 37;
    }

     // xử lí ăn vật phẩm
     if((xe.td.y - vp.td.y <=2 )&&(vp.td.x - xe.td.x <= 1))
     {
         xe.diem+=5;
         vp.td.y = -2;
    int  tmptdx = 1 + rand() % (bienphai - bientrai-1) + 15;
    if(tmptdx > 15 && tmptdx < 20)
        vp.td.x = 17;
    else if(tmptdx >=20 && tmptdx < 25)
        vp.td.x = 22;
    else if(tmptdx >=25 && tmptdx < 30)
        vp.td.x = 27;
    else if(tmptdx >=30 && tmptdx < 35)
        vc3.td.x = 32;
    else if(tmptdx >=35 && tmptdx < 40)
        vp.td.x = 37;

     }
     if((vp.td.y - xe.td.y <= 3) && (vp.td.y - xe.td.y >=0 ) && (vp.td.x - xe.td.x <= 1))
     {
         xe.diem+=5;
         vp.td.y = -2;
    int  tmptdx = 1 + rand() % (bienphai - bientrai-1) + 15;
    if(tmptdx > 15 && tmptdx < 20)
        vp.td.x = 17;
    else if(tmptdx >=20 && tmptdx < 25)
        vp.td.x = 22;
    else if(tmptdx >=25 && tmptdx < 30)
        vp.td.x = 27;
    else if(tmptdx >=30 && tmptdx < 35)
        vc3.td.x = 32;
    else if(tmptdx >=35 && tmptdx < 40)
        vp.td.x = 37;
     }



    //XỬ LÍ VA CHẠM.
  /*  if((xe.td.y - vc1.td.y <= 3) &&((xe.td.x-vc1.td.x <= 3)||(vc1.td.x - xe.td.x <= 3)))
       return 0;
    if((xe.td.y - vc2.td.y <= 3) &&((xe.td.x-vc2.td.x <= 3)||(vc2.td.x - xe.td.x <= 3)))
       return 0;
    if((xe.td.y - vc3.td.y <= 3) &&((xe.td.x-vc3.td.x <= 3)||(vc3.td.x - xe.td.x <= 3)))
       return 0; */
    if(abs(vc1.td.x-xe.td.x) <= 3 && abs(vc1.td.y-xe.td.y) <= 3)
        return 0;
     if(abs(xe.td.x-vc2.td.x) <= 3 && abs(xe.td.y-vc2.td.y) <= 3)
        return 0;
     if(abs(xe.td.x-vc3.td.x) <= 3 && abs(xe.td.y-vc3.td.y) <= 3)
        return 0;




}
void Dieu_khien_game(Xe &xe)
{
    if(kbhit())
    {
        char key = getch();
        if((key == 'A' || key=='a') && xe.td.x > bientrai+1)
            xe.td.x-=5;
        else if((key == 'd'||key == 'D') && xe.td.x <bienphai-4)
            xe.td.x+=5;
        else if((key == 'w' || key == 'W')&& xe.td.y >= 1)
            xe.td.y -= 2;
        else if((key == 's' || key == 'S')&& xe.td.y < bienduoi-4)
            xe.td.y += 2;

    }
}
int main()
{
    srand(time(NULL));
    Xe xe;
    VatCan vc1, vc2, vc3;
    VatPham vp;
    char xuli;
    char tengame[3][23] ={
                      { 'D' , 'D' , ' ', ' ', 'D', ' ', 'D', ' ', ' ', ' ', 'D', ' ', ' ', ' ', ' ', ' ', 'D', ' ', 'D', ' ', 'D', 'D', 'D' } ,
                      { 'D' , ' ' , 'D', ' ', 'D', ' ', 'D', ' ', ' ', 'D', ' ', 'D', ' ', ' ', ' ', ' ', ' ', 'D', ' ', ' ', 'D', 'D', ' ' },
                      { 'D' , 'D' , ' ', ' ', 'D', 'D', 'D', ' ', 'D', ' ', ' ', ' ', 'D', ' ', ' ', ' ', 'D', ' ', 'D', ' ', 'D', 'D', 'D' }
                     };
   // char ** tengame = new char*[3];
    //for(int i = 0; i < 3; i++)
    //{
    //    tengame[i] = new char[23];
    //}
    int toSleep = 200;
    khoitao(xe, vc1, vc2, vc3, vp);
    cout << "1. Let's go" << endl << "2. Exit";
    xuli = getch();
    if(xuli == '1')
    {
    while(true)
    {
         int xuli;

         // hiển thị

         Hien_thi_trang_thai_game(xe, vc1, vc2, vc3, vp, tengame) ;// điều khiển

        Dieu_khien_game(xe);

         // xử lí

         xuli = Xu_ly_game(xe, vc1, vc2, vc3, toSleep, vp);

         // game over

         if(xuli==0)
         {
             gotoXY(0, 0);
             cout << " thua";
             while(_getch()!=13)
                break;
         }
         Sleep(toSleep);
    }
    system("pause");
    return 0;
    }
    else if(xuli == '2')
    {
        system("cls");
        cout << "HEN GAP LAI\t\t\t";
        system("pause");
    }


}
