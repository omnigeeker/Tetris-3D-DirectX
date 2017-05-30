class POINT3D
{
public:
	int rx;
	int ry;
	int rz;
	POINT3D(){}
	POINT3D(int x,int y,int z){
		rx=x;ry=y;rz=z;
	}
	void C(int x,int y,int z){
		rx=x;ry=y;rz=z;
	}
};


POINT Change2To3(POINT3D p)
{
	POINT pt;
	if( p.rz <= zMe )
	{
		pt.x = 10000;
		pt.y = 10000;
	}
	else
	{
  		pt.x = cxMid+(p.rx-xMe)*Distance/(p.rz-zMe);
		pt.y = cyMid+(p.ry-yMe)*Distance/(p.rz-zMe);
	}
	return pt;
}
void Line(POINT pt1,POINT pt2 )
{
	static POINT pte;
	if( pt1.x!=10000 && pt2.x!=10000 && pt1.y!=10000 && pt2.y!=10000 )
	{
		MoveToEx(hdc, pt1.x, pt1.y ,&pte );
		LineTo(hdc, pt2.x, pt2.y );
	}
}
void Line(POINT3D p1,POINT3D p2)
{
	POINT pt1;
	POINT pt2;
	pt1 = Change2To3(p1);
	pt2 = Change2To3(p2);
	
	Line(pt1, pt2 );
}
void DrawBoxReal(POINT3D p1, POINT3D p7)
{
	POINT3D p2( p7.rx, p1.ry, p1.rz );
	POINT3D p3( p7.rx, p7.ry, p1.rz );
	POINT3D p4( p1.rx, p7.ry, p1.rz );
	POINT3D p5( p1.rx, p1.ry, p7.rz );
	POINT3D p6( p7.rx, p1.ry, p7.rz );
	POINT3D p8( p1.rx, p7.ry, p7.rz );
	POINT	pt1 = Change2To3( p1 );
	POINT	pt2 = Change2To3( p2 );
	POINT	pt3 = Change2To3( p3 );
	POINT	pt4 = Change2To3( p4 );
	POINT	pt5 = Change2To3( p5 );
	POINT	pt6 = Change2To3( p6 );
	POINT	pt7 = Change2To3( p7 );
	POINT	pt8 = Change2To3( p8 );
	
	Line(pt1, pt2);
	Line(pt2, pt3);
	Line(pt3, pt4);
	Line(pt4, pt1);
	Line(pt5, pt6);
	Line(pt6, pt7);
	Line(pt7, pt8);
	Line(pt8, pt5);
	Line(pt1, pt5);
	Line(pt2, pt6);
	Line(pt3, pt7);
	Line(pt4, pt8);
	
}
void DrawFillBoxReal1(POINT3D p1,POINT3D p7)
{
	POINT3D p2( p7.rx, p1.ry, p1.rz );
	POINT3D p3( p7.rx, p7.ry, p1.rz );
	POINT3D p4( p1.rx, p7.ry, p1.rz );
	POINT3D p5( p1.rx, p1.ry, p7.rz );
	POINT3D p6( p7.rx, p1.ry, p7.rz );
	POINT3D p8( p1.rx, p7.ry, p7.rz );
	POINT	pt1 = Change2To3( p1 );
	POINT	pt2 = Change2To3( p2 );
	POINT	pt3 = Change2To3( p3 );
	POINT	pt4 = Change2To3( p4 );
	POINT	pt5 = Change2To3( p5 );
	POINT	pt6 = Change2To3( p6 );
	POINT	pt7 = Change2To3( p7 );
	POINT	pt8 = Change2To3( p8 );
	
	Line(pt1, pt2);
	Line(pt2, pt3);
	Line(pt3, pt4);
	Line(pt4, pt1);
	Line(pt5, pt6);
	Line(pt6, pt7);
	Line(pt7, pt8);
	Line(pt8, pt5);
	Line(pt1, pt5);
	Line(pt2, pt6);
	Line(pt3, pt7);
	Line(pt4, pt8);
}
void DrawFillBoxReal2(POINT3D p1,POINT3D p7)
{
	POINT3D p3( p7.rx, p7.ry, p1.rz );
	POINT	pt1 = Change2To3( p1 );
	POINT	pt3 = Change2To3( p3 );
	Rectangle(hdc, pt1.x, pt1.y, pt3.x, pt3.y);
}

void DrawPlatform()
{
	int i=0;
	POINT3D p1;
	POINT3D p2;
	hpen = CreatePen(PS_SOLID, 0, RGB(127,127,127) );
	hOldPen = (HPEN)SelectObject(hdc, hpen);
	for( i=0;i<=LCY;i++)
	{
		p1.C(cxBegin, cyBegin+i*LEC, czMid+LCZ*LECD );
		p2.C(cxBegin+LEC*LCX, cyBegin+i*LEC, czMid+LCZ*LECD );
		Line(p1,p2);
	}
	for( i=0;i<=LCX;i++)
	{
		p1.C(cxBegin+i*LEC, cyBegin, czMid+LCZ*LECD );
		p2.C(cxBegin+i*LEC, cyBegin+LEC*LCY, czMid+LCZ*LECD );
		Line(p1,p2);
	}
	for( i=0;i<=LCY;i++)
	{
		p1.C(cxBegin, cyBegin+i*LEC, czMid );
		p2.C(cxBegin, cyBegin+i*LEC, czMid+LCZ*LECD );
		Line(p1,p2);
		p1.C(cxBegin+LEC*LCX, cyBegin+i*LEC, czMid );
		p2.C(cxBegin+LEC*LCX, cyBegin+i*LEC, czMid+LCZ*LECD );
		Line(p1,p2);
	}
	for( i=0;i<=LCX;i++)
	{
		p1.C(cxBegin+i*LEC, cyBegin, czMid );
		p2.C(cxBegin+i*LEC, cyBegin, czMid+LCZ*LECD );
		Line(p1,p2);
		p1.C(cxBegin+i*LEC, cyBegin+LEC*LCY, czMid );
		p2.C(cxBegin+i*LEC, cyBegin+LEC*LCY, czMid+LCZ*LECD);
		Line(p1,p2);
	}
	for( i=0;i<=LCZ;i++ )
	{
		p1.C(cxBegin, cyBegin, czMid+i*LECD );
		p2.C(cxBegin+LEC*LCX, cyBegin, czMid+i*LECD );
		Line(p1,p2);
		p1.C(cxBegin, cyBegin+LEC*LCY, czMid+i*LECD );
		p2.C(cxBegin+LEC*LCX, cyBegin+LEC*LCY, czMid+i*LECD );
		Line(p1,p2);
		p1.C(cxBegin, cyBegin, czMid+i*LECD );
		p2.C(cxBegin, cyBegin+LCY*LEC, czMid+i*LECD );
		Line(p1,p2);
		p1.C(cxBegin+LCX*LEC, cyBegin, czMid+i*LECD );
		p2.C(cxBegin+LCX*LEC, cyBegin+LEC*LCY, czMid+i*LECD );
		Line(p1,p2);
	}
	SelectObject( hdc, hOldPen );
	DeleteObject(hpen);
}
void DrawBox(int nX,int nY,int nZ)
{
	hpen = CreatePen(PS_SOLID, 2, color[nZ] );
	hOldPen = (HPEN)SelectObject( hdc,hpen );
	POINT3D p1(cxBegin+nX*LEC, cyBegin+nY*LEC, czMid+nZ*LECD );
	POINT3D p2(cxBegin+(nX+1)*LEC, cyBegin+(nY+1)*LEC, czMid+(nZ+1)*LECD );
	DrawBoxReal(p1,p2);
	SelectObject( hdc, hOldPen );
	DeleteObject(hpen);
}
void DrawFillBox1(int nX, int nY, int nZ )
{
	hpen = CreatePen(PS_SOLID, 0, RGB(255,255,255) );
	hOldPen = (HPEN)SelectObject( hdc,hpen );
	POINT3D p1(cxBegin+nX*LEC, cyBegin+nY*LEC, czMid+nZ*LECD );
	POINT3D p2(cxBegin+(nX+1)*LEC, cyBegin+(nY+1)*LEC, czMid+(nZ+1)*LECD );
	DrawFillBoxReal1(p1,p2);
	SelectObject( hdc, hOldPen );
	DeleteObject(hpen);
}
void DrawFillBox2(int nX, int nY, int nZ )
{
	hpen = CreatePen(PS_SOLID, 0, RGB(255,255,255) );
	hbrush = CreateSolidBrush( colorb[nZ] );
	hOldPen = (HPEN)SelectObject( hdc,hpen );
	hOldBrush = (HBRUSH)SelectObject( hdc,hbrush );
	POINT3D p1(cxBegin+nX*LEC, cyBegin+nY*LEC, czMid+nZ*LECD );
	POINT3D p2(cxBegin+(nX+1)*LEC, cyBegin+(nY+1)*LEC, czMid+(nZ+1)*LECD );
	if( czMid+nZ*LECD > zMe ) 
		DrawFillBoxReal2(p1,p2);
	SelectObject( hdc, hOldPen );
	SelectObject( hdc, hOldBrush );
	DeleteObject(hpen);
	DeleteObject(hbrush);
}
void DrawPannel()
{
	int i,j,k;
	for( k=LCZ-1;k>=0;k--)
	{
		for( i=0;i<LCX;i++)
			for( j=0;j<LCY;j++)
				if( Pannel[i][j][k] )
					DrawFillBox1(i,j,k);
		for( i=0;i<LCX;i++)
			for( j=0;j<LCY;j++)
				if( Pannel[i][j][k] )
					DrawFillBox2(i,j,k);
	}
	
}
void ShowScore()
{
	static TCHAR str[100];
	hpen = CreatePen( PS_SOLID, 0, RGB(255,255,255) );
	hbrush = CreateSolidBrush( RGB(0,0,0) );
	hOldPen = (HPEN)SelectObject( hdc, hpen );
	hOldBrush = (HBRUSH)SelectObject( hdc, hbrush );
	Rectangle(hdc, cxScreen-120, 10,cxScreen-20,90);
	SelectObject( hdc, hOldPen );
	SelectObject( hdc, hOldBrush );
	DeleteObject( hpen );
	DeleteObject( hbrush );
	wsprintf(str,"%d",Score);
	SetTextColor(hdc, RGB(0,255,255) );
	TextOut(hdc, cxScreen-87, 30,TEXT("分数"),lstrlen(TEXT("分数")) );
	TextOut(hdc, cxScreen-80, 50,str,lstrlen(str));
}
void ShowSpeed()
{
	static TCHAR str[100];
	hpen = CreatePen( PS_SOLID, 0, RGB(255,255,255) );
	hbrush = CreateSolidBrush( RGB(0,0,0) );
	hOldPen = (HPEN)SelectObject( hdc, hpen );
	hOldBrush = (HBRUSH)SelectObject( hdc, hbrush );
	Rectangle(hdc, cxScreen-120, 100,cxScreen-20,190);
	SelectObject( hdc, hOldPen );
	SelectObject( hdc, hOldBrush );
	DeleteObject( hpen );
	DeleteObject( hbrush );
	wsprintf(str,"%d",20-(iTempTime-1)/10);
	SetTextColor(hdc, RGB(255,0,255) );
	TextOut(hdc, cxScreen-100, 130,TEXT("速度等级"),lstrlen(TEXT("速度等级")) );
	TextOut(hdc, cxScreen-80, 150,str,lstrlen(str));
}
void ShowControl1()
{
	static int Left,Top,Bottom,Right,Height;
	Left = 20;
	Right = 170;
	Top = 10;
	Bottom = 450;
	Height = 20;
	hpen = CreatePen( PS_SOLID, 1, RGB(255,255,255) );
	hbrush = CreateSolidBrush( RGB(0, 0, 0) );
	hOldPen = (HPEN)SelectObject(hdc, hpen );
	hOldBrush = (HBRUSH)SelectObject(hdc, hbrush );
	Rectangle(hdc, Left, Top, Right, Bottom );
	SelectObject( hdc, hOldPen );
	SelectObject( hdc, hOldBrush );
	DeleteObject( hpen );
	DeleteObject( hbrush );
	SetTextColor(hdc, RGB(0,255,0) );
	TextOut(hdc, Left+10, Top+Height,TEXT("Left:   向左"),lstrlen(TEXT("Left:   向左")) );
	TextOut(hdc, Left+10, Top+2*Height ,TEXT("Right: 向右"),lstrlen(TEXT("Right: 向右")) );
	TextOut(hdc, Left+10, Top+3*Height ,TEXT("Up:    向上"),lstrlen(TEXT("Up:    向上")) );
	TextOut(hdc, Left+10, Top+4*Height ,TEXT("Down:  向下"),lstrlen(TEXT("Down:  向下")) );
	TextOut(hdc, Left+10, Top+5*Height ,TEXT("A:     翻转"),lstrlen(TEXT("A:     翻转")) );
	TextOut(hdc, Left+10, Top+6*Height ,TEXT("Z:     翻转"),lstrlen(TEXT("Z:     翻转")) );
	TextOut(hdc, Left+10, Top+7*Height ,TEXT("S:     翻转"),lstrlen(TEXT("S:     翻转")) );
	TextOut(hdc, Left+10, Top+8*Height ,TEXT("X:     翻转"),lstrlen(TEXT("X:     翻转")) );
	TextOut(hdc, Left+10, Top+9*Height ,TEXT("D:     翻转"),lstrlen(TEXT("D:     翻转")) );
	TextOut(hdc, Left+10, Top+10*Height ,TEXT("C:     翻转"),lstrlen(TEXT("C:     翻转")) );
	TextOut(hdc, Left+10, Top+11*Height ,TEXT("Space: 快速掉落"),lstrlen(TEXT("Space: 快速掉落")) );
	TextOut(hdc, Left+10, Top+14*Height ,TEXT("ESC: 退出"),lstrlen(TEXT("ESC: 退出")) );
	TextOut(hdc, Left+10, Top+15*Height ,TEXT("回车:   进入视角"),lstrlen(TEXT("回车:   进入视角")) );
	TextOut(hdc, Left+55, Top+16*Height ,TEXT("转换模式"),lstrlen(TEXT("转换模式")) );

	SetTextColor(hdc, RGB(255,255,0) );
	TextOut(hdc, Left+35, Bottom-3*Height ,TEXT("当前模式："),lstrlen(TEXT("当前模式：")) );
	TextOut(hdc, Left+45, Bottom-2*Height ,TEXT("游戏模式"),lstrlen(TEXT("游戏模式")) );
}
void ShowControl2()
{
	static int Left,Top,Bottom,Right,Height;
	Left = 20;
	Right = 170;
	Top = 10;
	Bottom = 350;
	Height = 20;
	hpen = CreatePen(PS_SOLID, 1, RGB(255,255,255) );
	hbrush = CreateSolidBrush( RGB(0, 0, 0) );
	hOldPen = (HPEN)SelectObject(hdc, hpen );
	hOldBrush = (HBRUSH)SelectObject(hdc, hbrush );
	Rectangle(hdc, Left, Top, Right, Bottom );
	SelectObject( hdc, hOldPen );
	SelectObject( hdc, hOldBrush );
	DeleteObject( hpen );
	DeleteObject( hbrush );
	SetTextColor(hdc, RGB(255,255,0) );
	TextOut(hdc, Left+10, Top+Height,TEXT("Left:  视角左移 "),lstrlen(TEXT("Left:  视角左移")) );
	TextOut(hdc, Left+10, Top+2*Height ,TEXT("Right: 视角右移"),lstrlen(TEXT("Right: 视角右移")) );
	TextOut(hdc, Left+10, Top+3*Height ,TEXT("Up:    视角上移"),lstrlen(TEXT("Up:    视角上移")) );
	TextOut(hdc, Left+10, Top+4*Height ,TEXT("Down:  视角下移"),lstrlen(TEXT("Down:  视角下移")) );
	TextOut(hdc, Left+10, Top+6*Height ,TEXT("空格:  视角前移"),lstrlen(TEXT("空格:  视角前移")) );
	TextOut(hdc, Left+10, Top+7*Height ,TEXT("Tab:   视角后移"),lstrlen(TEXT("Tab:   视角后移")) );
	TextOut(hdc, Left+10, Top+9*Height ,TEXT("ESC:   退出"),lstrlen(TEXT("ESC:   退出")) );
	TextOut(hdc, Left+10, Top+10*Height ,TEXT("回车:   回到游戏模式"),lstrlen(TEXT("回车:   回到游戏模式")) );

	SetTextColor(hdc, RGB(0,255,0) );
	TextOut(hdc, Left+35, Bottom-3*Height ,TEXT("当前模式："),lstrlen(TEXT("当前模式：")) );
	TextOut(hdc, Left+45, Bottom-2*Height ,TEXT("视角转换模式"),lstrlen(TEXT("视角转换模式")) );

}
void ShowAbout()
{
	static int Left,Top,Bottom,Right,Height;
	Left = 20;
	Right = 170;
	Top = 500;
	Bottom = cyScreen-20;
	Height = 20;
	hpen = CreatePen(PS_SOLID, 1, RGB(255,255,255) );
	hbrush = CreateSolidBrush( RGB(0, 0, 0) );
	hOldPen = (HPEN)SelectObject(hdc, hpen );
	hOldBrush = (HBRUSH)SelectObject(hdc, hbrush );
	Rectangle(hdc, Left, Top, Right, Bottom );
	SelectObject( hdc, hOldPen );
	SelectObject( hdc, hOldBrush );
	DeleteObject( hpen );
	DeleteObject( hbrush );
	SetTextColor(hdc, RGB(255,0,0) );
	TextOut(hdc, Left+5, Top+Height,TEXT("注意："),lstrlen(TEXT("注意：")) );
	TextOut(hdc, Left+10, Top+2*Height,TEXT("请勿用Alt-Tab跳出。"),lstrlen(TEXT("请勿用Alt-Tab跳出。")) );
	TextOut(hdc, Left+10, Top+3*Height,TEXT("请勿用Alt-ESC跳出。"),lstrlen(TEXT("请勿用Alt-ESC跳出。")) );
	SetTextColor(hdc, RGB(0,0,255) );
	TextOut(hdc, Left+5, Top+4*Height,TEXT("制作人："),lstrlen(TEXT("制作人：")) );
	TextOut(hdc, Left+10, Top+5*Height,TEXT("计算机 0108 班"),lstrlen(TEXT("计算机 0108 班")) );
	TextOut(hdc, Left+10, Top+6*Height,TEXT("王闻宇"),lstrlen(TEXT("王闻宇")) );
}
void ShowLayer()
{
	static int Left,Top,Bottom,Right;
	Left = cxScreen-120;
	Right = cxScreen-20;
	Top = cyScreen-500;
	Bottom = cyScreen-100;
	static int Height=(Top-Bottom)/LCZ;
	for( int i=0;i<LCZ;i++)
	{
		hpen=CreatePen(PS_SOLID, 4, color[i] );
		hbrush=CreateSolidBrush(colorb[i] );
		hOldPen = (HPEN)SelectObject(hdc, hpen );
		hOldBrush = (HBRUSH)SelectObject(hdc, hbrush );
		Rectangle(hdc,Left, Top-i*Height, Right, Top-(i+1)*Height-4 );
		SelectObject( hdc, hOldPen );
		SelectObject( hdc, hOldBrush );
		DeleteObject(hpen);
		DeleteObject(hbrush);
	}
}
void Draw()
{
	hpen = (HPEN)GetStockObject( WHITE_PEN );
	hOldPen = (HPEN)SelectObject(hdc,hpen);
	hbrush = (HBRUSH)GetStockObject( BLACK_BRUSH );
	hOldBrush = (HBRUSH)SelectObject(hdc,hbrush);
	Rectangle(hdc,0,0,cxScreen,cyScreen);
	SelectObject( hdc, hOldPen );
	SelectObject( hdc, hOldBrush );
	DeleteObject(hbrush);
	DeleteObject(hpen);
	
	DrawPlatform();
	DrawPannel();
	ShowNow();

	SetBkColor(hdc, RGB(0,0,0) );
	ShowScore();
	ShowSpeed();
	ShowLayer();
	ShowAbout();
	if( isRun )
		ShowControl1();
	else
		ShowControl2();
}