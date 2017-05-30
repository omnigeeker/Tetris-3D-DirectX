int fab(int nN)
{
	if( nN>=0 ) return nN;
	else return -nN;
}

int GetNum(int nType,int nT,int nH,int nV,int _xNow,int _yNow,int _zNow)
{
	switch( nType )
	{
	case 0:
		switch( fab( nT ) )
		{
		case 1:
			return _xNow;
		case 2:
			return _yNow;
		case 3:
			return _zNow;
		default:
			return 0;
		}
		break;
	case 1:
		switch( fab( nH ) )
		{
		case 1:
			return _xNow;
		case 2:
			return _yNow;
		case 3:
			return _zNow;
		default:
			return 0;
		}
		break;
	case 2:
		switch( fab( nV ) )
		{
		case 1:
			return _xNow;
		case 2:
			return _yNow;
		case 3:
			return _zNow;
		default:
			return 0;
		}
		break;
	default:
		return 0;
	}
}
/*
int GetSign(int nType,int nT,int nH,int nV,int _xNow,int _yNow,int _zNow)
{
	switch( check[nT][nH][nV][nType]>0 )
	{
	case true:
		return 1;
	case false:
		return -1;
	}
}
*/
int GetSign(int nType,int nT,int nH,int nV,int _xNow,int _yNow,int _zNow)
{
	switch( nType )
	{
	case 0:
		switch( nT>0 )
		{
		case true:
			return 1;
		case false:
			return -1;
		}
		break;
	case 1:
		switch( nH>0 )
		{
		case true:
			return 1;
		case false:
			return -1;
		}
		break;
	case 2:
		switch( (nV>0) )
		{
		case true:
			return 1;
		case false:
			return -1;
		}
		break;
	}
	return 0;
}
void DrawBox(int nX,int nY,int nZ);

void ChangeDrawBox(int nT,int nH,int nV,int _xNow,int _yNow,int _zNow,int _a,int _b,int _c)
{
	int a,b,c,Sa,Sb,Sc;
	a=GetNum(0,nT,nH,nV,_a,_b,_c);
	b=GetNum(1,nT,nH,nV,_a,_b,_c);
	c=GetNum(2,nT,nH,nV,_a,_b,_c);
	Sa=GetSign(0,nT,nH,nV,_a,_b,_c);
	Sb=GetSign(1,nT,nH,nV,_a,_b,_c);
	Sc=GetSign(2,nT,nH,nV,_a,_b,_c);
	DrawBox(_xNow+Sa*a,_yNow+Sb*b,_zNow+Sc*c);
}

bool CheckBox(int nT,int nH,int nV,int _xNow,int _yNow,int _zNow,int _a,int _b,int _c)
{
	int a,b,c,Sa,Sb,Sc;
	a=GetNum(0,nT,nH,nV,_a,_b,_c);
	b=GetNum(1,nT,nH,nV,_a,_b,_c);
	c=GetNum(2,nT,nH,nV,_a,_b,_c);
	Sa=GetSign(0,nT,nH,nV,_a,_b,_c);
	Sb=GetSign(1,nT,nH,nV,_a,_b,_c);
	Sc=GetSign(2,nT,nH,nV,_a,_b,_c);
	if( _xNow+Sa*a<0 || _xNow+Sa*a>LCX-1 || _yNow+Sb*b<0 || _yNow+Sb*b>LCY-1 || _zNow+Sc*c<0 || _zNow+Sc*c>LCZ-1 )
		return false;
	if( Pannel[_xNow+Sa*a][_yNow+Sb*b][_zNow+Sc*c] )
		return false;
	return true;
}
bool check0(int nT,int nH,int nV,int _xNow,int _yNow,int _zNow)
{
		if( !CheckBox(nT,nH,nV,_xNow,_yNow,_zNow, 0, 0, 0) )
			return false;
		if( !CheckBox(nT,nH,nV,_xNow,_yNow,_zNow, 1, 0, 0) )
			return false;
		if( !CheckBox(nT,nH,nV,_xNow,_yNow,_zNow, 0, 1, 0) )
			return false;
		if( !CheckBox(nT,nH,nV,_xNow,_yNow,_zNow, 1, 1, 0) )
			return false;
		return true;
}
bool check1(int nT,int nH,int nV,int _xNow,int _yNow,int _zNow)
{
		if( !CheckBox(nT,nH,nV,_xNow,_yNow,_zNow, 0, 0, 0 ) )
			return false;
		if( !CheckBox(nT,nH,nV,_xNow,_yNow,_zNow, -1, 0, 0 ) )
			return false;
		if( !CheckBox(nT,nH,nV,_xNow,_yNow,_zNow, 1, 0, 0 ) )
			return false;
		if( !CheckBox(nT,nH,nV,_xNow,_yNow,_zNow, 2, 0, 0 ) )
			return false;
		return true;
}
bool check2(int nT,int nH,int nV,int _xNow,int _yNow,int _zNow)
{
		if( !CheckBox(nT,nH,nV,_xNow,_yNow,_zNow, 0, 0, 0 ) )
			return false;
		if( !CheckBox(nT,nH,nV,_xNow,_yNow,_zNow, 1, 0, 0 ) )
			return false;
		if( !CheckBox(nT,nH,nV,_xNow,_yNow,_zNow, 0, 1, 0 ) )
			return false;
		if( !CheckBox(nT,nH,nV,_xNow,_yNow,_zNow, -1 , 1, 0) )
			return false;
		return true;
}
bool check3(int nT,int nH,int nV,int _xNow,int _yNow,int _zNow)
{
		if( !CheckBox(nT,nH,nV,_xNow,_yNow,_zNow, 0, 0, 0) )
			return false;
		if( !CheckBox(nT,nH,nV,_xNow,_yNow,_zNow, -1, 0, 0) )
			return false;
		if( !CheckBox(nT,nH,nV,_xNow,_yNow,_zNow, 0, 1, 0 ) )
			return false;
		if( !CheckBox(nT,nH,nV,_xNow,_yNow,_zNow, 1, 0, 0 ) )
			return false;
	return true;
}
bool check4(int nT,int nH,int nV,int _xNow,int _yNow,int _zNow)
{
		if( !CheckBox(nT,nH,nV,_xNow,_yNow,_zNow, 0, 0, 0) )
			return false;
		if( !CheckBox(nT,nH,nV,_xNow,_yNow,_zNow, -1, 0, 0) )
			return false;
		if( !CheckBox(nT,nH,nV,_xNow,_yNow,_zNow, -1, 1, 0 ) )
			return false;
		if( !CheckBox(nT,nH,nV,_xNow,_yNow,_zNow, 1, 0, 0 ) )
			return false;
		return true;
}
void show0(int nT,int nH,int nV,int _xNow,int _yNow,int _zNow)
{	
	ChangeDrawBox(nT,nH,nV,_xNow,_yNow,_zNow, 0, 0, 0);
	ChangeDrawBox(nT,nH,nV,_xNow,_yNow,_zNow, 1, 0, 0); 
	ChangeDrawBox(nT,nH,nV,_xNow,_yNow,_zNow, 0, 1, 0 ); 
	ChangeDrawBox(nT,nH,nV,_xNow,_yNow,_zNow, 1, 1, 0);
}
void show1(int nT,int nH,int nV,int _xNow,int _yNow,int _zNow)
{
	ChangeDrawBox(nT,nH,nV,_xNow,_yNow,_zNow, 0, 0, 0 );
	ChangeDrawBox(nT,nH,nV,_xNow,_yNow,_zNow, -1, 0, 0 ); 
	ChangeDrawBox(nT,nH,nV,_xNow,_yNow,_zNow, 1, 0, 0 ); 
	ChangeDrawBox(nT,nH,nV,_xNow,_yNow,_zNow, 2, 0, 0 );
}
void show2(int nT,int nH,int nV,int _xNow,int _yNow,int _zNow)
{
	ChangeDrawBox(nT,nH,nV,_xNow,_yNow,_zNow, 0, 0, 0 );
	ChangeDrawBox(nT,nH,nV,_xNow,_yNow,_zNow, 1, 0, 0 ); 
	ChangeDrawBox(nT,nH,nV,_xNow,_yNow,_zNow, 0, 1, 0 ); 
	ChangeDrawBox(nT,nH,nV,_xNow,_yNow,_zNow, -1 , 1, 0);
}
void show3(int nT,int nH,int nV,int _xNow,int _yNow,int _zNow)
{
	ChangeDrawBox(nT,nH,nV,_xNow,_yNow,_zNow, 0, 0, 0);
	ChangeDrawBox(nT,nH,nV,_xNow,_yNow,_zNow, -1, 0, 0); 
	ChangeDrawBox(nT,nH,nV,_xNow,_yNow,_zNow, 0, 1, 0 ); 
	ChangeDrawBox(nT,nH,nV,_xNow,_yNow,_zNow, 1, 0, 0 );
}
void show4(int nT,int nH,int nV,int _xNow,int _yNow,int _zNow)
{
	ChangeDrawBox(nT,nH,nV,_xNow,_yNow,_zNow, 0, 0, 0);
	ChangeDrawBox(nT,nH,nV,_xNow,_yNow,_zNow, -1, 0, 0); 
	ChangeDrawBox(nT,nH,nV,_xNow,_yNow,_zNow, -1, 1, 0 ); 
	ChangeDrawBox(nT,nH,nV,_xNow,_yNow,_zNow, 1, 0, 0 );
}
void WriteBox(int nT,int nH,int nV,int _xNow,int _yNow,int _zNow,int _a,int _b,int _c)
{
	int a,b,c,Sa,Sb,Sc;
	a=GetNum(0,nT,nH,nV,_a,_b,_c);
	b=GetNum(1,nT,nH,nV,_a,_b,_c);
	c=GetNum(2,nT,nH,nV,_a,_b,_c);
	Sa=GetSign(0,nT,nH,nV,_a,_b,_c);
	Sb=GetSign(1,nT,nH,nV,_a,_b,_c);
	Sc=GetSign(2,nT,nH,nV,_a,_b,_c);
	Pannel[_xNow+Sa*a][_yNow+Sb*b][_zNow+Sc*c] = 1;
}
void write0(int nT,int nH,int nV,int _xNow,int _yNow,int _zNow)
{
	WriteBox(nT,nH,nV,_xNow,_yNow,_zNow, 0, 0, 0);
	WriteBox(nT,nH,nV,_xNow,_yNow,_zNow, 1, 0, 0); 
	WriteBox(nT,nH,nV,_xNow,_yNow,_zNow, 0, 1, 0 ); 
	WriteBox(nT,nH,nV,_xNow,_yNow,_zNow, 1, 1, 0 );
}
void write1(int nT,int nH,int nV,int _xNow,int _yNow,int _zNow)
{
	WriteBox(nT,nH,nV,_xNow,_yNow,_zNow, 0, 0, 0 );
	WriteBox(nT,nH,nV,_xNow,_yNow,_zNow, -1, 0, 0 ); 
	WriteBox(nT,nH,nV,_xNow,_yNow,_zNow, 1, 0, 0 ); 
	WriteBox(nT,nH,nV,_xNow,_yNow,_zNow, 2, 0, 0 );
}
void write2(int nT,int nH,int nV,int _xNow,int _yNow,int _zNow)
{
	WriteBox(nT,nH,nV,_xNow,_yNow,_zNow, 0, 0, 0 );
	WriteBox(nT,nH,nV,_xNow,_yNow,_zNow, 1, 0, 0 ); 
	WriteBox(nT,nH,nV,_xNow,_yNow,_zNow, 0, 1, 0 ); 
	WriteBox(nT,nH,nV,_xNow,_yNow,_zNow, -1 , 1, 0);
}
void write3(int nT,int nH,int nV,int _xNow,int _yNow,int _zNow)
{
	WriteBox(nT,nH,nV,_xNow,_yNow,_zNow, 0, 0, 0);
	WriteBox(nT,nH,nV,_xNow,_yNow,_zNow, -1, 0, 0); 
	WriteBox(nT,nH,nV,_xNow,_yNow,_zNow, 0, 1, 0 ); 
	WriteBox(nT,nH,nV,_xNow,_yNow,_zNow, 1, 0, 0 );
}
void write4(int nT,int nH,int nV,int _xNow,int _yNow,int _zNow)
{
	WriteBox(nT,nH,nV,_xNow,_yNow,_zNow, 0, 0, 0);
	WriteBox(nT,nH,nV,_xNow,_yNow,_zNow, -1, 0, 0); 
	WriteBox(nT,nH,nV,_xNow,_yNow,_zNow, -1, 1, 0 ); 
	WriteBox(nT,nH,nV,_xNow,_yNow,_zNow, 1, 0, 0 );
}
