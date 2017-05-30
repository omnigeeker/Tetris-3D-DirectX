
bool Check(int iNow,int nT,int nH,int nV,int _xNow,int _yNow,int _zNow)
{
	switch( iNow )
	{
	case 0:
		return check0(nT, nH, nV, _xNow, _yNow, _zNow );
	case 1:
		return check1(nT, nH, nV, _xNow, _yNow, _zNow );
	case 2:
		return check2(nT, nH, nV, _xNow, _yNow, _zNow );
	case 3:
		return check3(nT, nH, nV, _xNow, _yNow, _zNow );
	case 4:
		return check4(nT, nH, nV, _xNow, _yNow, _zNow );
	default:
		return false;
	}
}
bool CheckNow()
{
	return Check(iNum,inT , inH, inV, xNow, yNow, zNow );
}
bool CheckInto()
{
	return Check(iNum,inT , inH, inV, xNow, yNow, zNow+1 );
}
bool CheckLeft()
{
	return Check(iNum,inT , inH, inV, xNow-1, yNow, zNow );
}
bool CheckRight()
{
	return Check(iNum,inT , inH, inV, xNow+1, yNow, zNow );
}
bool CheckUp()
{
	return Check(iNum,inT , inH, inV, xNow, yNow-1, zNow );
}
bool CheckDown()
{
	return Check(iNum,inT , inH, inV, xNow, yNow+1, zNow );
}
bool CheckTurn(int flags,int &offX,int &offY,int &offZ)
{
	int nT,nV,nH;
	/*
	if( flags == 0 )
	{
		nT = inT;
		nH = inH;
		nV =( inV<=0 )? 3: inV-1;
	}
	else if( flags == 1 )
	{
		nT = inT;
		nH = inH;
		nV =( inV>=3 )? 0: inV+1;
	}
	else if( flags == 2 )
	{
		nT = inT;
		nH = ( inH<=0 )? 3: inH-1;
		nV = inV;
	}
	else if( flags == 3 )
	{
		nT = inT;
		nH = ( inH>=3 )? 0: inH+1;
		nV = inV;
	}
	else if( flags == 4 )
	{
		nT = ( inT<=0 )?3: inT-1;
		nH = inH;
		nV = inV;
	}
	else if( flags == 5 )
	{
		nT = ( inT>=3 )?0: inT+1;
		nH = inH;
		nV = inV;
	}
	*/
	if( flags == 0 )
	{
		nT = -inH;
		nH = inT;
		nV = inV;
	}
	else if( flags == 1 )
	{
		nT = inH;
		nH = -inT;
		nV = inV;
	}
	else if( flags == 2 )
	{
		nT = -inV;
		nH = inH;
		nV = inT;
	}
	else if( flags == 3 )
	{
		nT = inV;
		nH = inH;
		nV = -inT;
	}
	else if( flags == 4 )
	{
		nT = inT;
		nH = -inV;
		nV = inH;
	}
	else if( flags == 5 )
	{
		nT = inT;
		nH = inV;
		nV = -inH;
	}
	if( Check(iNum, nT, nH, nV, xNow, yNow, zNow ) )
	{
		offX = 0; offY = 0; offZ = 0;
		return true;
	}
	if( Check(iNum, nT, nH, nV, xNow-1, yNow, zNow ) )
	{
		offX = -1; offY = 0; offZ = 0;
		return true;
	}
	if( Check(iNum, nT, nH, nV, xNow+1, yNow, zNow ) )
	{
		offX = 1; offY = 0; offZ = 0;
		return true;
	}
	if( Check(iNum, nT, nH, nV, xNow, yNow-1, zNow ) )
	{
		offX = 0; offY = -1; offZ = 0;
		return true;
	}
	if( Check(iNum, nT, nH, nV, xNow, yNow+1, zNow ) )
	{
		offX = 0; offY = 1; offZ = 0;
		return true;
	}
	if( Check(iNum, nT, nH, nV, xNow-1, yNow-1, zNow ) )
	{
		offX = -1; offY = -1; offZ = 0;
		return true;
	}
	if( Check(iNum, nT, nH, nV, xNow+1, yNow+1, zNow ) )
	{
		offX = 1; offY = 1; offZ = 0;
		return true;
	}
	if( Check(iNum, nT, nH, nV, xNow+1, yNow-1, zNow ) )
	{
		offX = 1; offY = -1; offZ = 0;
		return true;
	}
	if( Check(iNum, nT, nH, nV, xNow-1, yNow+1, zNow ) )
	{
		offX = -1;offY = 1; offZ = 0;
		return true;
	}

	if( Check(iNum, nT, nH, nV, xNow, yNow, zNow+1 ) )
	{
		offX = 0; offY = 0; offZ = 1;
		return true;
	}
	if( Check(iNum, nT, nH, nV, xNow-1, yNow, zNow+1 ) )
	{
		offX = -1; offY = 0; offZ = 1;
		return true;
	}
	if( Check(iNum, nT, nH, nV, xNow+1, yNow, zNow+1 ) )
	{
		offX = 1; offY = 0; offZ = 0;
		return true;
	}
	if( Check(iNum, nT, nH, nV, xNow, yNow-1, zNow ) )
	{
		offX = 0; offY = -1; offZ = 1;
		return true;
	}
	if( Check(iNum, nT, nH, nV, xNow, yNow+1, zNow+1 ) )
	{
		offX = 0; offY = 1; offZ = 1;
		return true;
	}
	if( Check(iNum, nT, nH, nV, xNow-1, yNow-1, zNow+1 ) )
	{
		offX = -1; offY = -1; offZ = 1;
		return true;
	}
	if( Check(iNum, nT, nH, nV, xNow+1, yNow+1, zNow+1 ) )
	{
		offX = 1; offY = 1; offZ = 1;
		return true;
	}
	if( Check(iNum, nT, nH, nV, xNow+1, yNow-1, zNow+1 ) )
	{
		offX = 1; offY = -1; offZ = 1;
		return true;
	}
	if( Check(iNum, nT, nH, nV, xNow-1, yNow+1, zNow+1 ) )
	{
		offX = -1;offY = 1; offZ = 1;
		return true;
	}

	return false;
}
void Show(int iNow,int nT,int nH,int nV,int _xNow,int _yNow,int _zNow)
{
	switch( iNow )
	{
	case 0:
		return show0(nT, nH,nV,_xNow,_yNow,_zNow);
	case 1:
		return show1(nT, nH,nV,_xNow,_yNow,_zNow);
	case 2:
		return show2(nT, nH,nV,_xNow,_yNow,_zNow);
	case 3:
		return show3(nT, nH,nV,_xNow,_yNow,_zNow);
	case 4:
		return show4(nT, nH,nV,_xNow,_yNow,_zNow);
	}
}
void ShowNow()
{
	Show(iNum, inT, inH, inV, xNow, yNow, zNow );
}
void Write(int iNow,int nT,int nH,int nV,int _xNow,int _yNow,int _zNow)
{
	switch( iNow )
	{
	case 0:
		return write0(nT, nH,nV,_xNow,_yNow,_zNow);
	case 1:
		return write1(nT, nH,nV,_xNow,_yNow,_zNow);
	case 2:
		return write2(nT, nH,nV,_xNow,_yNow,_zNow);
	case 3:
		return write3(nT, nH,nV,_xNow,_yNow,_zNow);
	case 4:
		return write4(nT, nH,nV,_xNow,_yNow,_zNow);
	}
}
void WriteNow()
{
	Write(iNum,inT , inH, inV, xNow, yNow, zNow );
}
