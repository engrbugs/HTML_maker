// HTML_maker.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include <windows.h>
#include "ShellAPI.h";
#include <iostream>
#include <fstream>
#include <string>

#include "HTML_maker.h"
#include <chrono>

#include <iostream>
#include <filesystem>
#include <sstream>
#include <iomanip>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <time.h>
#include <random>

#include <algorithm>

#include <fstream>
#include <limits>

using std::cout; using std::cin;
using std::endl; using std::string;

namespace fs = std::filesystem;

using namespace std;
using namespace std::chrono;

#define MAX_LOADSTRING 100

const string HTML_FILENAME = "\\index.html";
const string HTML_HEADER_BEGIN = "<!DOCTYPE html><html><head><title>Read</title></head>"
"<body><style> body {background-color: #121212f5; color: #fff; font-family: 'Helvetica Neue',"
"sans-serif; margin-left: 100px; margin-right: 100px; border-left: 16px; border-right: 16px; "
"margin-top: 54px; line-height: 1.2; padding-left: 24px;} strong {font-weight: 400; font-size: "
"44px;} div { margin-right: 100px; text-align: right;}</style></body>";
const string HTML_HEADER_END = "</html>";
const string HTML_QUOTE_APPEND_BEGIN = "<strong>";
const string HTML_QUOTE_APPEND_END = "</strong>";
const string HTML_NONQUOTE_APPEND_BEGIN = "";
const string HTML_NONQUOTE_APPEND_END = "";
const string HTML_AUTHOR_APPEND_BEGIN = "<div><br/>—";
const string HTML_AUTHOR_APPEND_END = "</div>";

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_HTMLMAKER, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_HTMLMAKER));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}


ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_HTMLMAKER));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_HTMLMAKER);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}


string ExePath() {
    TCHAR buffer[MAX_PATH] = { 0 };
    GetModuleFileName(NULL, buffer, MAX_PATH);
    size_t pos = string(buffer).rfind("\\");
    return string(buffer).substr(0, pos);
}


std::string tail(std::string const& source, size_t const length) {
    if (length >= source.size()) { return source; }
    return source.substr(source.size() - length);
}


void make_html(string body)
{
    ofstream myfile;

    myfile.open(ExePath() + HTML_FILENAME);
    myfile << "<!DOCTYPE html><html><head></head><body>"; //starting html
    myfile << "<p><span style='font-weight: bold'>" << "hello world" << "</span><span>" << "magic" << "</span></p>";
    myfile << "</body></html>";
    myfile.close();
}

int randomize_number(int max)
{
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> randomnumber(1, max);

    return randomnumber(gen);
}


int main()
{

    // open to browser the HTML
    // string url = "c://" + HTML_FILENAME;
    //ShellExecute(NULL, "open", string(ExePath() + "\\hello.html").c_str(), NULL, NULL, SW_SHOWNORMAL);

    // save ini file
    string path = ExePath() + "\\touch_of_darkness.ini";
    /*WritePrivateProfileString("Read Data", "Line Char", "5", path.c_str());*/

    // read all ini file data
    int line_char = GetPrivateProfileInt("Read Data", "Line Char", -1, path.c_str());
    int total_lines = GetPrivateProfileInt("Read Data", "Total Lines", -1, path.c_str());

    // cout all read ini data
    string debug = to_string(line_char) + string("\n");
    OutputDebugString(debug.c_str());

    debug = to_string(total_lines) + string("\n");
    OutputDebugString(debug.c_str());

    int random_number = randomize_number(total_lines);

    debug = to_string(random_number) + string("\n");
    OutputDebugString(debug.c_str());

    string line;

    auto start = high_resolution_clock::now();
    
    ifstream file_source(ExePath() + "\\touch_of_darkness.txt");
    if (file_source.is_open())
    {
        for (int i = 1; i <= random_number; i++)
            getline(file_source, line);
    }
    file_source.close();

    string number = line.substr(0, line_char-1);
    line = tail(line, line.length() - line_char); // remove the '####-'

    debug = line + string("\n");
    OutputDebugString(debug.c_str());
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    debug = "Time taken by function: " + 
        to_string(duration.count()) + " microseconds"
        + string("\n");
    OutputDebugString(debug.c_str());

    ofstream file_html(ExePath() + HTML_FILENAME);
    file_html << HTML_HEADER_BEGIN << endl;
    
    std::string::difference_type n = std::count(line.begin(), line.end(), '“');
    size_t start = 0;
    for (int i = 0; i <= n - 1; i++)
    {

        file_html << HTML_QUOTE_APPEND_BEGIN << endl;
        file_html << line << endl;
        file_html << HTML_QUOTE_APPEND_END << endl;
    }

    
    file_html << HTML_AUTHOR_APPEND_BEGIN << endl;
    file_html << "Touch of Darkness, Line " + number << endl;
    file_html << HTML_AUTHOR_APPEND_END << endl;
    file_html << HTML_HEADER_END << endl;
    file_html.close();

    //  open browser 
    ShellExecute(NULL, "open", (ExePath() + HTML_FILENAME).c_str(), NULL, NULL, SW_SHOWNORMAL);
}



BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;                                                             
   }

   //ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);
   // start here
   main();
   DestroyWindow(hWnd);
   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Add any drawing code that uses hdc here...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
