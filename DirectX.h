#define			SafeRelease(x)		if(x){x->Release();x=NULL;}
//global variares
LPGUID						lpGUID=NULL;
LPDIRECTDRAW4				lpDD=NULL;
LPDIRECTDRAWSURFACE4		lpDDPri=NULL;
LPDIRECTDRAWSURFACE4		lpDDBack=NULL;

//global function 
void DrawDirectX();


//Create or Delete  
HRESULT	InitDirectX(HWND hWnd)
{
	int ddrval;
	DDSURFACEDESC2 ddsd;
	DDSCAPS2 ddscaps;
	LPDIRECTDRAW pDD;
	
	ddrval = DirectDrawCreate(NULL, &pDD, NULL );
	if( ddrval != DD_OK )
	{
		MessageBox(hWnd,TEXT("DirectDrawCreateWrong!"),TEXT("WRONG"),NULL);
		return FALSE;
	}
	ddrval = pDD->QueryInterface(IID_IDirectDraw4,(LPVOID *) &lpDD );
	if( ddrval != DD_OK )
	{
		MessageBox(hWnd,TEXT("DirectDrawCreateWrong2!"),TEXT("WRONG"),NULL);
		return FALSE;
	}
	
	ddrval = lpDD->SetCooperativeLevel(hWnd, DDSCL_EXCLUSIVE|DDSCL_FULLSCREEN|DDSCL_ALLOWREBOOT );
	if( ddrval != DD_OK )
	{
		MessageBox(hWnd, TEXT("Cooperate Wrong!"), TEXT("WRONG"),NULL);
		return  FALSE;
	}

	ZeroMemory(&ddsd, sizeof(ddsd) );
	ddsd.dwSize = sizeof( ddsd );
	ddsd.dwFlags = DDSD_CAPS|DDSD_BACKBUFFERCOUNT;
	ddsd.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE|DDSCAPS_FLIP|DDSCAPS_COMPLEX;
	ddsd.dwBackBufferCount = 1;
	ddrval = lpDD->CreateSurface(&ddsd,&lpDDPri,NULL);
	if( ddrval !=DD_OK )
	{
		MessageBox(hWnd, TEXT("Primary Surface Wrong!"), TEXT("WRONG"),NULL);
		return  FALSE;
	}

	ddscaps.dwCaps=DDSCAPS_BACKBUFFER;
	ddrval = lpDDPri->GetAttachedSurface(&ddscaps,&lpDDBack);
	if( ddrval!=DD_OK )
	{
		MessageBox(hWnd, TEXT("Back Surface Wrong!"), TEXT("WRONG"),NULL);
		return  FALSE;
	}
	if( !lpDDBack )
	{
		MessageBox(hWnd,TEXT("Back surface Wrong!"),TEXT("WRONG"),NULL);
		return FALSE;
	}
	DrawDirectX();
	return TRUE;
}
void CleanUp()
{
	SafeRelease( lpDDBack );
	SafeRelease( lpDDPri );
	SafeRelease( lpDD );
}


void DrawDirectX()
{

	if( lpDDBack )	
	{
		lpDDBack->GetDC( &hdc );
		Draw();
		lpDDBack->ReleaseDC(hdc);
		lpDDPri->Flip(0,DDFLIP_WAIT);
	}
	else
		MessageBox(NULL,TEXT("No this lpDDback!"),TEXT("WRONG"),MB_ERR_INVALID_CHARS);	
}