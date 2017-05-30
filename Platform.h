int GetRand(int nN)
{
	return rand()%nN;
}
void ClearPannel()
{
	int i,j,k;
	for(k=0;k<LCZ;k++)
		for(j=0;j<LCY;j++)
			for(i=0;i<LCX;i++)
				Pannel[i][j][k]=0;
}
void Init()
{
	ClearPannel();
	iNum = GetRand(BOXES);
	inV = 3;
	inH = 2;
	inT = 1;
	_iNum = GetRand(BOXES);
	_inV = 3;
	xNow=LCX/2;
	yNow=LCX/2;
	zNow=0;
	Score = 0;
	LastScore = 0;
	iTempTime = iSlowTime;
	iRealTime = iTempTime;
}
void Restart()
{
	Init();
	iTime=0;
	iTempTime = iSlowTime;
	iRealTime = iTempTime;
	Score = 0; 
}
void Down(int nN)
{
	int i,j,k;
	for(k=nN-1;k>=0;k--){
		for(i=0;i<LCX;i++)
			for(j=0;j<LCY;j++)
				Pannel[i][j][k+1]=Pannel[i][j][k];
	}
	for(i=0;i<LCX;i++)
		for(j=0;j<LCY;j++)
			Pannel[i][j][0]=0;
}
bool CheckRow( int nN)
{
	int i,j;
	for(i=0;i<LCX;i++)
		for(j=0;j<LCY;j++)
			if( !Pannel[i][j][nN] )
				return false;
	return true;
}	
void MakeDown(){
	int k;
	int AddScore=0;
	for( k=LCZ-1;k>0;k--)
	{
		if( CheckRow(k) )
		{
			Down(k);
			k++;
			AddScore++;
		}
	}
	if( AddScore == 1 ) Score+=100;
	if( AddScore == 2 ) Score+=300;
	if( AddScore == 3 ) Score+=600;
	if( AddScore == 4 ) Score+=1000;
	if( Score-LastScore >= SCORELEC )
	{
		LastScore = LastScore+SCORELEC;
		iTempTime = iTempTime-10;
		if( iTempTime < 1 )
			iTempTime = 1;
		iRealTime = iTempTime;
	}
}
void swap(int &nA,int &nB)
{
	int nC;
	nC=nA;
	nA = -nB;
	nB=nC;
}