HDC			hdc;
HPEN		hpen;
HPEN		hOldPen;
HBRUSH		hbrush;
HBRUSH		hOldBrush;
HFONT		hfont;

//
int cxScreen = GetSystemMetrics(SM_CXSCREEN );
int cyScreen = GetSystemMetrics(SM_CYSCREEN );
int cxMid = cxScreen/2;
int cyMid = cyScreen/2;
int czMid = 0;
int cxBegin = -LEC*LCX/2;
int cyBegin = -LEC*LCY/2;

int xMe = 0;
int yMe = 0;
int zMe = -80;

//real
int Distance=100;


//Color
COLORREF	color[20]={ RGB(127,0,255), RGB(255,0,255), RGB(255,0,127), RGB(255,0,0), RGB(255,127,0),
						  RGB(255,255,0), RGB(127,255,127), RGB(0,0,255), RGB(0,255,255),RGB(0,255,0),
						  RGB(127,0,255), RGB(255,0,255), RGB(255,0,127), RGB(255,0,0), RGB(255,127,0),
						  RGB(255,255,0), RGB(127,255,127), RGB(0,0,255), RGB(0,255,255),RGB(0,255,0)
						};
COLORREF	colorb[20]={ RGB(63,0,127), RGB(127,0,127), RGB(127,0,63), RGB(127,0,0), RGB(127,63,0),
						  RGB(127,127,0), RGB(63,127,63), RGB(0,0,127), RGB(0,127,127),RGB(0,127,0),
						  RGB(63,0,127), RGB(127,0,127), RGB(127,0,63), RGB(127,0,0), RGB(127,63,0),
						  RGB(127,127,0), RGB(63,127,63), RGB(0,0,127), RGB(0,127,127),RGB(0,127,0)
						};
//Platform
int Pannel[LCX][LCY][LCZ];


int iNum;
int _iNum;
int inH;
int inV;
int inT;
int _inV;

int xNow;
int yNow;
int zNow;
//Run
bool isRun = true;
//Time
int iTime=0;
int iSlowTime=201;
int iFastTime=1;
int iTempTime=iSlowTime;
int iRealTime=iTempTime;

int offX;
int offY;
int offZ;
// 
int Score = 0;
int LastScore = 0;