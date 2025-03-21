#include <windows.h> // ϳ�������� ������ Windows
#include <stdio.h>  // ���������� �������� ��������-���������
#include <math.h>  //ϳ�������� ������ ������������ �������



HINSTANCE instance;

#define ID_COMBOBOX_1       110 //�������������� ��� ������
#define ID_BUTTON_1         111
#define ID_BUTTON_2         112
#define ID_EDIT_1           113
#define ID_EDIT_2           114
#define ID_EDIT_3           115
#define ID_STATIC_1         116
#define ID_EDIT_4           117
#define ID_EDIT_5           118
#define ID_EDIT_6           119
#define PI 3.142
#define K 2.65

HWND hComboBox1; //��������� ���������� ������
HWND hEdit1;
HWND hEdit2;
HWND hEdit3;
HWND hEdit4;
HWND hEdit5;
HWND hEdit6; 

int StrToInt(char *s)
{
  int temp = 0; // �����
  int i = 0;
  int sign = 0; // ���� ����� 0- ������, 1 - ��'����
  if (s[i] == '-')
  {
    sign = 1;
    i++;
  }
  while (s[i] >= 0x30 && s[i] <= 0x39)
  {
    temp = temp + (s[i] & 0x0F);
    temp = temp * 10;
    i++;
  }
  temp = temp / 10;
  if (sign == 1)
    temp = -temp;
  return(temp);
}
// ������� ������������ ����� � ������
char* IntToStr(int n)
{
  char s[40], t, *temp;
  int i, k;
  int sign = 0;
  i = 0;
  k = n;
  if (k<0)
  {
    sign = 1;
    k = -k;
  }
  do {
    t = k % 10;
    k = k / 10;
    s[i] = t | 0x30;
    i++;
  } while (k>0);
  if (sign == 1)
  {
    s[i] = '-';
    i++;
  }
  temp = new char[i];
  k = 0;
  i--;
  while (i >= 0) {
    temp[k] = s[i];
    i--; k++;
  }
  temp[k] = '\0';
  return(temp);
}

VOID RemplieFenetrePrincipale(HWND fenetrePrincipale)
{
    

     hEdit1=CreateWindow(     //��������� ������� ���� ��� �������� ������ ��������� ����
        "EDIT",
        "������ ���",
        WS_CHILD|WS_VISIBLE|ES_AUTOHSCROLL|WS_BORDER,
        400,150,                      //���������� ����� ��������� ����
        180,20,                       //����� ������
        fenetrePrincipale,
        (HMENU)ID_EDIT_1,
        instance,
        NULL);
        
        hEdit2=CreateWindow( //��������� ������� ���� ��� �������� �����
        "EDIT",
        "������ ����",
        WS_CHILD|WS_VISIBLE|ES_AUTOHSCROLL|WS_BORDER,
        400,250,                     //���������� ����� ��������� ����
        180,20,                      //����� ������
        fenetrePrincipale,
        (HMENU)ID_EDIT_2,
        instance,
        NULL);
        
        hEdit3=CreateWindow(  //��������� �������� ���� ��� �������� ������ �����������
        "EDIT",
        "������ �����",
        WS_CHILD|WS_VISIBLE|ES_AUTOHSCROLL|WS_BORDER, //���� WS_BORDER ���� ������� �� ������ ��������
        20,150,                  //���������� ����� ��������� ����
        180,20,                   //����� ������
        fenetrePrincipale,
        (HMENU)ID_EDIT_3,
        instance,
        NULL);
        
        hEdit4=CreateWindow(  //���������  ���� ��� ��������� ���������� ���������� �� ������ �������� 
        "EDIT",
        "0",
        WS_CHILD|WS_VISIBLE|ES_AUTOHSCROLL|WS_BORDER,
        120,270,              //���������� ����� ��������� ����
        180,30,                //����� ������
        fenetrePrincipale,
        (HMENU)ID_EDIT_4,
        instance,
        NULL);
        
        hEdit5=CreateWindow(  //���������  ���� ��� �������� ����� �����������
        "EDIT",
        "������ �����",
        WS_CHILD|WS_VISIBLE|ES_AUTOHSCROLL|WS_BORDER,
        400,350,              //���������� ����� ��������� ����
        180,20,               //����� ������
        fenetrePrincipale,
        (HMENU)ID_EDIT_5,
        instance,
        NULL);
        
        hEdit6=CreateWindow(  //���������  ���� ��� ��������� ���������� ���������� �� ������ ��������
        "EDIT",
        "0",
        WS_CHILD|WS_VISIBLE|ES_AUTOHSCROLL|WS_BORDER,
        529,400,                //���������� ����� ��������� ����
        180,30,                //����� ������
        fenetrePrincipale,
        (HMENU)ID_EDIT_6,
        instance,
        NULL);
        
        CreateWindow("STATIC","2.1.���:",WS_VISIBLE|WS_CHILD,400,100,150,38,
		fenetrePrincipale,
        (HMENU)ID_STATIC_1,
        instance,
        NULL);
        
        CreateWindow("STATIC","2.2.����:",WS_VISIBLE|WS_CHILD,400,200,150,38,
		fenetrePrincipale,
        (HMENU)ID_STATIC_1,
        instance,
        NULL);
        
        CreateWindow("STATIC","2.3.����� �����������:",WS_VISIBLE|WS_CHILD,400,300,150,38,
		fenetrePrincipale,
        (HMENU)ID_STATIC_1,
        instance,
        NULL);
        
        CreateWindow("STATIC","1.����� �����������:",WS_VISIBLE|WS_CHILD,20,40,150,38,
		fenetrePrincipale,
        (HMENU)ID_STATIC_1,
        instance,
        NULL);
        
        CreateWindow("STATIC","2.���������� ����� ����:",WS_VISIBLE|WS_CHILD,400,40,150,38,
		fenetrePrincipale,
        (HMENU)ID_STATIC_1,
        instance,
        NULL);
        
        CreateWindow("STATIC","1.1.��Ĳ��:",WS_VISIBLE|WS_CHILD,20,100,150,38,
		fenetrePrincipale,
        (HMENU)ID_STATIC_1,
        instance,
        NULL);

    CreateWindow(  //��������� ������ ���������� ����� ����������� (F)
        "BUTTON",
        "����������",
        WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON, //�����: ������ ����, ����� ������,
        20,270,  //���������� ��������� ����� ���� ������
        100,30,  //����� ������
        fenetrePrincipale,
        (HMENU)ID_BUTTON_1,
        instance,
        NULL);

    CreateWindow( //��������� ������ ���������� ����� ���� ��� ���������� ������������(Q)
        "BUTTON",
        "����������",
        WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,
        400,400,
        130,30,
        fenetrePrincipale,
        (HMENU)ID_BUTTON_2,
        instance,
        NULL);
}

VOID NotificationControle(HWND fenetrePrincipale,UINT message,WPARAM wParam, LPARAM lParam) 
{
    UINT iId=LOWORD(wParam); //������ LOWORD ���� � �������� wParam �������� ��������������
    UINT iCode=HIWORD(wParam); //������ HIWORD ���� � �������� wParam �������� ���� �����������
    HWND hCtl=(HWND)lParam;

   if(iId==ID_COMBOBOX_1)
   {

   }
   else if(iId==ID_BUTTON_1)
   {
        CHAR lpText[256];
        GetWindowText(hEdit1,lpText,256);

        SendMessage(hComboBox1,CB_ADDSTRING,0,(LPARAM)lpText);
   }
   else if(iId==ID_BUTTON_2)
   {
       LRESULT lRes=SendMessage(hComboBox1,CB_GETCURSEL,0,0);
       if(lRes==CB_ERR)
       {
           MessageBox(fenetrePrincipale,"Aucun �l�ment s�lectionn�","Action annul�e",MB_OK);
           return ;
       }

       SendMessage(hComboBox1,CB_DELETESTRING,(WPARAM)lRes,0);
   }
}
// ��������� ��������� ������� ����������
LRESULT CALLBACK procedureFenetrePrincipale(HWND fenetrePrincipale, UINT message, WPARAM wParam, LPARAM lParam)  

{
    static HWND boutons[2] = {NULL};
    HDC hdc;
    HINSTANCE hInst;
    PAINTSTRUCT ps;
    HWND hHits;
    HWND hTimesAtBat; //���������� ���� �����������
    HWND hOut;
    TCHAR StrA[20];
    int a,F,Len,b,d,Q;
    double c;
    
    
	

    switch (message)
    {
        case WM_CREATE:
            RemplieFenetrePrincipale(fenetrePrincipale);
            return 0;
        
		
		case WM_COMMAND: // ����������� ��� �������
        	
        	switch(wParam)
        {
        
		case ID_BUTTON_1: //��� ��������� ������:
      Len = GetWindowText(hEdit3, StrA, 20);
      a = StrToInt(StrA); // ������� ����� � ������� ����
      
      F = PI * pow(a, 2);  // ������ �� �������� ����� �����������
      
	  SetWindowText(hEdit4, IntToStr(F)); //�������� ��������� �  ���� 4
	  
	  case ID_BUTTON_2: // ��� ��������� ������ ���������� �����:
      Len = GetWindowText(hEdit1, StrA, 20);
      b = StrToInt(StrA); // ������� ����� � ������� ����
      
      Len = GetWindowText(hEdit2, StrA, 20);
      c = StrToInt(StrA); // ������� ����� � ������� ����
      
      Len = GetWindowText(hEdit5, StrA, 20);/*������� GetWindowText ����� ����� �������� ��'���� � �������� �����
      ������ ��������-�� ������ ��'����, ������ �������� - �� ������ ������, 
	  �������� �������� - �� ����������� ������� ���������� �������*/
      d = StrToInt(StrA); // ������� ����� � �������� ����
      
      Q = K * d * b * (pow(c, 1/2));  // ��������� �� �������� ����� ����� ���� ��� ������������ ������������
      
	  SetWindowText(hEdit6, IntToStr(Q)); //�������� ��������� �  ���� 6
      
      
            break;

        }
            NotificationControle(fenetrePrincipale,message,wParam,lParam);
            return 0;
        
		
		case WM_DESTROY: // �������� ����
            PostQuitMessage(0);
            return 0;
        default:  //  ���������� ���������� �� ������������
            return DefWindowProc(fenetrePrincipale,message,wParam,lParam);
    }
}


int APIENTRY WinMain (HINSTANCE cetteInstance, //���������� ���� ��������
    HINSTANCE precedenteInstance,
    LPSTR lignesDeCommande,        // �������� ��������
	int modeDAffichage)            //����� ����������� ����
{
    HWND fenetrePrincipale;      //���������� ��������� ���� ��������
    MSG message; //������� �������� ���������� ����
    WNDCLASS classeFenetre;  //��������� �����

    instance = cetteInstance;

    classeFenetre.style = CS_DBLCLKS;// ������ ������ ����������
    classeFenetre.lpfnWndProc = procedureFenetrePrincipale; //��������� ������� ���������� ����
    classeFenetre.cbClsExtra = 0;
    classeFenetre.cbWndExtra = 0;
    classeFenetre.hInstance = NULL;
    classeFenetre.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    classeFenetre.hCursor = LoadCursor(NULL, IDC_ARROW);
    classeFenetre.hbrBackground = (HBRUSH)(1 + COLOR_BTNFACE);
    classeFenetre.lpszMenuName = NULL;
    classeFenetre.lpszClassName = "classeF";


    if(!RegisterClass(&classeFenetre)) //��������� �� �������� ���� ����
        return FALSE;

    fenetrePrincipale=CreateWindow(   //��������� ��������� ����
        "classeF",   //��'� ����� ����
        "���������� ����� ���� ��� ������������ ������������",  //��������� ����
        WS_OVERLAPPEDWINDOW,      // ����� ��������� ����
        CW_USEDEFAULT,CW_USEDEFAULT,
        800,540,  //����� ����
        NULL,
        NULL,
        cetteInstance,
        NULL);

    if (!fenetrePrincipale)
        return FALSE;

    ShowWindow(fenetrePrincipale,modeDAffichage); //�������� ����
    UpdateWindow(fenetrePrincipale);


    while(GetMessage(&message,NULL,0,0)) //������� ������ ���������� �� �� ���������� � ����� message
    {
        TranslateMessage(&message); //������� ���������� ��������� ������� ������
        DispatchMessage(&message); //������� �������� ���������� � ����
    }

    return message.wParam;
}
