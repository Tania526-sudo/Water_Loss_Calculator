#include <windows.h> // Підключаємо модуль Windows
#include <stdio.h>  // Стандартна бібліотека введення-виведення
#include <math.h>  //Підключаємо модуль математичних функцій



HINSTANCE instance;

#define ID_COMBOBOX_1       110 //Ідентифікатори для кнопок
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

HWND hComboBox1; //Створення глобальних змінних
HWND hEdit1;
HWND hEdit2;
HWND hEdit3;
HWND hEdit4;
HWND hEdit5;
HWND hEdit6; 

int StrToInt(char *s)
{
  int temp = 0; // число
  int i = 0;
  int sign = 0; // знак числа 0- додатнє, 1 - від'ємне
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
// Функція перетворення числа в символ
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
    

     hEdit1=CreateWindow(     //Створення першого поля для введення періоду тривалості аварії
        "EDIT",
        "Введіть час",
        WS_CHILD|WS_VISIBLE|ES_AUTOHSCROLL|WS_BORDER,
        400,150,                      //Координати лівого верхнього кута
        180,20,                       //Розмір кнопки
        fenetrePrincipale,
        (HMENU)ID_EDIT_1,
        instance,
        NULL);
        
        hEdit2=CreateWindow( //Створення другого поля для введення тиску
        "EDIT",
        "Введіть тиск",
        WS_CHILD|WS_VISIBLE|ES_AUTOHSCROLL|WS_BORDER,
        400,250,                     //Координати лівого верхнього кута
        180,20,                      //Розмір кнопки
        fenetrePrincipale,
        (HMENU)ID_EDIT_2,
        instance,
        NULL);
        
        hEdit3=CreateWindow(  //Створення третього поля для введення радіусу пошкодження
        "EDIT",
        "Введіть радіус",
        WS_CHILD|WS_VISIBLE|ES_AUTOHSCROLL|WS_BORDER, //Флаг WS_BORDER додає границю до нашого елементу
        20,150,                  //Координати лівого верхнього кута
        180,20,                   //Розмір кнопки
        fenetrePrincipale,
        (HMENU)ID_EDIT_3,
        instance,
        NULL);
        
        hEdit4=CreateWindow(  //Створення  поля для виведення результату розрахунку за першою формулою 
        "EDIT",
        "0",
        WS_CHILD|WS_VISIBLE|ES_AUTOHSCROLL|WS_BORDER,
        120,270,              //Координати лівого верхнього кута
        180,30,                //Розмір кнопки
        fenetrePrincipale,
        (HMENU)ID_EDIT_4,
        instance,
        NULL);
        
        hEdit5=CreateWindow(  //Створення  поля для введення площі пошкодження
        "EDIT",
        "Введіть площу",
        WS_CHILD|WS_VISIBLE|ES_AUTOHSCROLL|WS_BORDER,
        400,350,              //Координати лівого верхнього кута
        180,20,               //Розмір кнопки
        fenetrePrincipale,
        (HMENU)ID_EDIT_5,
        instance,
        NULL);
        
        hEdit6=CreateWindow(  //Створення  поля для виведення результату розрахунку за другою формулою
        "EDIT",
        "0",
        WS_CHILD|WS_VISIBLE|ES_AUTOHSCROLL|WS_BORDER,
        529,400,                //Координати лівого верхнього кута
        180,30,                //Розмір кнопки
        fenetrePrincipale,
        (HMENU)ID_EDIT_6,
        instance,
        NULL);
        
        CreateWindow("STATIC","2.1.ЧАС:",WS_VISIBLE|WS_CHILD,400,100,150,38,
		fenetrePrincipale,
        (HMENU)ID_STATIC_1,
        instance,
        NULL);
        
        CreateWindow("STATIC","2.2.ТИСК:",WS_VISIBLE|WS_CHILD,400,200,150,38,
		fenetrePrincipale,
        (HMENU)ID_STATIC_1,
        instance,
        NULL);
        
        CreateWindow("STATIC","2.3.ПЛОЩА ПОШКОДЖЕННЯ:",WS_VISIBLE|WS_CHILD,400,300,150,38,
		fenetrePrincipale,
        (HMENU)ID_STATIC_1,
        instance,
        NULL);
        
        CreateWindow("STATIC","1.ПЛОЩА ПОШКОДЖЕННЯ:",WS_VISIBLE|WS_CHILD,20,40,150,38,
		fenetrePrincipale,
        (HMENU)ID_STATIC_1,
        instance,
        NULL);
        
        CreateWindow("STATIC","2.РОЗРАХУНОК ВТРАТ ВОДИ:",WS_VISIBLE|WS_CHILD,400,40,150,38,
		fenetrePrincipale,
        (HMENU)ID_STATIC_1,
        instance,
        NULL);
        
        CreateWindow("STATIC","1.1.РАДІУС:",WS_VISIBLE|WS_CHILD,20,100,150,38,
		fenetrePrincipale,
        (HMENU)ID_STATIC_1,
        instance,
        NULL);

    CreateWindow(  //Створення кнопки розрахунку площі пошкодження (F)
        "BUTTON",
        "РОЗРАХУНОК",
        WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON, //Флаги: дочірнє вікно, показ кнопки,
        20,270,  //Координати верхнього лівого вікна кнопки
        100,30,  //Розмір кнопки
        fenetrePrincipale,
        (HMENU)ID_BUTTON_1,
        instance,
        NULL);

    CreateWindow( //Створення кнопки розрахунку втрат води при пошкодженні трубопроводу(Q)
        "BUTTON",
        "РОЗРАХУНОК",
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
    UINT iId=LOWORD(wParam); //Макрос LOWORD дістає з перемінної wParam значення ідентифікатора
    UINT iCode=HIWORD(wParam); //Макрос HIWORD дістає з перемінної wParam значення коду повідомлення
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
           MessageBox(fenetrePrincipale,"Aucun йlйment sйlectionnй","Action annulйe",MB_OK);
           return ;
       }

       SendMessage(hComboBox1,CB_DELETESTRING,(WPARAM)lRes,0);
   }
}
// Параметри процедури обробки повідомлень
LRESULT CALLBACK procedureFenetrePrincipale(HWND fenetrePrincipale, UINT message, WPARAM wParam, LPARAM lParam)  

{
    static HWND boutons[2] = {NULL};
    HDC hdc;
    HINSTANCE hInst;
    PAINTSTRUCT ps;
    HWND hHits;
    HWND hTimesAtBat; //Дескриптор поля редагування
    HWND hOut;
    TCHAR StrA[20];
    int a,F,Len,b,d,Q;
    double c;
    
    
	

    switch (message)
    {
        case WM_CREATE:
            RemplieFenetrePrincipale(fenetrePrincipale);
            return 0;
        
		
		case WM_COMMAND: // Повідомлення про команду
        	
        	switch(wParam)
        {
        
		case ID_BUTTON_1: //При натисканні кнопки:
      Len = GetWindowText(hEdit3, StrA, 20);
      a = StrToInt(StrA); // Зчитуємо число з першого поля
      
      F = PI * pow(a, 2);  // Рахуємо за формулою площу пошкодження
      
	  SetWindowText(hEdit4, IntToStr(F)); //Виводимо результат в  поле 4
	  
	  case ID_BUTTON_2: // При натисканні кнопки розрахунок втрат:
      Len = GetWindowText(hEdit1, StrA, 20);
      b = StrToInt(StrA); // Зчитуємо число з першого поля
      
      Len = GetWindowText(hEdit2, StrA, 20);
      c = StrToInt(StrA); // Зчитуємо число з другого поля
      
      Len = GetWindowText(hEdit5, StrA, 20);/*Функція GetWindowText копіює текст заданого об'єкту у вказаний буфер
      перший параметр-це адреса об'єкту, другий параметр - це адреса буферу, 
	  останнфй параметр - це максимальна кількість копійованих символів*/
      d = StrToInt(StrA); // Зчитуємо число з третього поля
      
      Q = K * d * b * (pow(c, 1/2));  // Знаходимо за формулою обсяг втрат води при пошкодженнях трубопроводу
      
	  SetWindowText(hEdit6, IntToStr(Q)); //Виводимо результат в  поле 6
      
      
            break;

        }
            NotificationControle(fenetrePrincipale,message,wParam,lParam);
            return 0;
        
		
		case WM_DESTROY: // Закриття вікна
            PostQuitMessage(0);
            return 0;
        default:  //  Оброблення повідомлень за змовчуванням
            return DefWindowProc(fenetrePrincipale,message,wParam,lParam);
    }
}


int APIENTRY WinMain (HINSTANCE cetteInstance, //Дескриптор даної програми
    HINSTANCE precedenteInstance,
    LPSTR lignesDeCommande,        // Командна оболонка
	int modeDAffichage)            //Режим відображення вікна
{
    HWND fenetrePrincipale;      //Дескриптор головного вікна програми
    MSG message; //Функція передачі повідомлень вікна
    WNDCLASS classeFenetre;  //Структура класу

    instance = cetteInstance;

    classeFenetre.style = CS_DBLCLKS;// Ловимо подвійні натискання
    classeFenetre.lpfnWndProc = procedureFenetrePrincipale; //Процедура обробки повідомлень вікна
    classeFenetre.cbClsExtra = 0;
    classeFenetre.cbWndExtra = 0;
    classeFenetre.hInstance = NULL;
    classeFenetre.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    classeFenetre.hCursor = LoadCursor(NULL, IDC_ARROW);
    classeFenetre.hbrBackground = (HBRUSH)(1 + COLOR_BTNFACE);
    classeFenetre.lpszMenuName = NULL;
    classeFenetre.lpszClassName = "classeF";


    if(!RegisterClass(&classeFenetre)) //Створюємо та реєструємо клас вікна
        return FALSE;

    fenetrePrincipale=CreateWindow(   //Створення головного вікна
        "classeF",   //Ім'я класу вікна
        "РОЗРАХУНОК ВТРАТ ВОДИ ПРИ ПОШКОДЖЕННЯХ ТРУБОПРОВОДУ",  //Заголовок вікна
        WS_OVERLAPPEDWINDOW,      // Стиль головного вікна
        CW_USEDEFAULT,CW_USEDEFAULT,
        800,540,  //Розмір вікна
        NULL,
        NULL,
        cetteInstance,
        NULL);

    if (!fenetrePrincipale)
        return FALSE;

    ShowWindow(fenetrePrincipale,modeDAffichage); //Показуємо вікно
    UpdateWindow(fenetrePrincipale);


    while(GetMessage(&message,NULL,0,0)) //фуккція вибірки повідомлень та їх збереження в змінну message
    {
        TranslateMessage(&message); //Функція трансляції кодування нажатих кнопок
        DispatchMessage(&message); //Функція передачі повідомлень у вікно
    }

    return message.wParam;
}
