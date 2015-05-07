////////////////////////////////////////////////////////////////////////////////
// Filename: SystemClass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "SystemClass.h"


SystemClass::SystemClass()
{
	mInput = 0;
	mGraphics = 0;
	mTimer = 0;
}

SystemClass::SystemClass(const SystemClass& other)
{

}
SystemClass::~SystemClass()
{
}

bool SystemClass::Initialize()
{
	int screenWidth, screenHeight;
	bool result;

	// Initialize the width and height of the screen to zero before sending the variables into the function.
	screenWidth = 0;
	screenHeight = 0;

	// Initialize the windows api.
	InitializeWindows(screenWidth, screenHeight);

	// Create the input object.  This object will be used to handle reading the keyboard input from the user.
	mInput = new InputClass;
	if (!mInput)
	{
		return false;
	}

	// Initialize the input object.
	mInput->Initialize();

	// Create the graphics object.  This object will handle rendering all the graphics for this application.
	mGraphics = new GraphicsClass;
	if (!mGraphics)
	{
		return false;
	}

	// Initialize the graphics object.
	result = mGraphics->Initialize(screenWidth, screenHeight, mHwnd);
	if (!result)
	{
		return false;
	}

	// Create the timer object.
	mTimer = new TimerClass();


	return true;
}

void SystemClass::Shutdown()
{
	// Release the graphics object.
	if (mGraphics)
	{
		mGraphics->Shutdown();
		delete mGraphics;
		mGraphics = 0;
	}

	// Release the input object.
	if (mInput)
	{
		delete mInput;
		mInput = 0;
	}

	// Shutdown the window.
	ShutdownWindows();

	return;
}

void SystemClass::Run()
{
	MSG msg;
	bool done, result;

	// Reset the timer
	mTimer->Reset();

	// Initialize the message structure.
	ZeroMemory(&msg, sizeof(MSG));

	// Loop until there is a quit message from the window or the user.
	done = false;
	while (!done)
	{
		// Handle the windows messages.
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		// If windows signals to end the application then exit out.
		if (msg.message == WM_QUIT)
		{
			done = true;
		}
		else
		{
			// Otherwise do the frame processing.

			mTimer->Tick();

			result = Frame();
			if (!result)
			{
				done = true;
			}
		}

	}

	return;
}

bool SystemClass::Frame()
{
	bool result;

	// Handle input from the user.
	result = HandleInput();
	if (!result)
	{
		return false;
	}

	float dt = mTimer->DeltaTime();

	// Handle any updates in the frame.
	result = Update(dt);
	if (!result)
	{
		return false;
	}

	// Handle all rendering for the frame.
	result = Render();
	if (!result)
	{
		return false;
	}

	return true;
}
bool SystemClass::HandleInput()
{
	// Check if the user pressed escape and wants to exit the application.
	if (mInput->IsKeyDown(VK_ESCAPE))
	{
		return false;
	}

	return true;
}
bool SystemClass::Update(float dt)
{

	return true;
}
bool SystemClass::Render()
{
	bool result; 

	// Do the frame processing for the graphics object.
	result = mGraphics->Frame();
	if (!result)
	{
		return false;
	}

	return true;
}

LRESULT CALLBACK SystemClass::MessageHandler(HWND hwnd, UINT umsg, WPARAM wparam, LPARAM lparam)
{
	switch (umsg)
	{
		// Check if a key has been pressed on the keyboard.
	case WM_KEYDOWN:
	{
		// If a key is pressed send it to the input object so it can record that state.
		mInput->KeyDown((unsigned int)wparam);
		return 0;
	}

	// Check if a key has been released on the keyboard.
	case WM_KEYUP:
	{
		// If a key is released then send it to the input object so it can unset the state for that key.
		mInput->KeyUp((unsigned int)wparam);
		return 0;
	}
	// Check if a key on the mouse has been pressed.
	case WM_LBUTTONDOWN:
	case WM_MBUTTONDOWN:
	case WM_RBUTTONDOWN:
	{
		mInput->MouseDown((unsigned int)wparam);
		return 0;
	}
	// Check if a key on the mouse has been released.
	case WM_LBUTTONUP:
	case WM_MBUTTONUP:
	case WM_RBUTTONUP:
	{
		mInput->MouseUp((unsigned int)wparam);
		return 0;
	}
	// Check if mouse has been moved.
	case WM_MOUSEMOVE:
	{
		mInput->OnMouseMove(GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
		return 0;
	}
		// Any other messages send to the default message handler as our application won't make use of them.
	default:
	{
		return DefWindowProc(hwnd, umsg, wparam, lparam);
	}
	}
}

void SystemClass::InitializeWindows(int& screenWidth, int& screenHeight)
{
	WNDCLASSEX wc;
	DEVMODE dmScreenSettings;
	int posX, posY;


	// Get an external pointer to this object.
	ApplicationHandle = this;

	// Get the instance of this application.
	mHinstance = GetModuleHandle(NULL);

	// Give the application a name.
	mApplicationName = L"Engine";

	// Setup the windows class with default settings.
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = mHinstance;
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	wc.hIconSm = wc.hIcon;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = mApplicationName;
	wc.cbSize = sizeof(WNDCLASSEX);

	// Register the window class.
	RegisterClassEx(&wc);

	// Determine the resolution of the clients desktop screen.
	screenWidth = GetSystemMetrics(SM_CXSCREEN);
	screenHeight = GetSystemMetrics(SM_CYSCREEN);

	// Setup the screen settings depending on whether it is running in full screen or in windowed mode.
	if (FULL_SCREEN)
	{
		// If full screen set the screen to maximum size of the users desktop and 32bit.
		memset(&dmScreenSettings, 0, sizeof(dmScreenSettings));
		dmScreenSettings.dmSize = sizeof(dmScreenSettings);
		dmScreenSettings.dmPelsWidth = (unsigned long)screenWidth;
		dmScreenSettings.dmPelsHeight = (unsigned long)screenHeight;
		dmScreenSettings.dmBitsPerPel = 32;
		dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

		// Change the display settings to full screen.
		ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN);

		// Set the position of the window to the top left corner.
		posX = posY = 0;
	}
	else
	{
		// If windowed then set it to 800x600 resolution.
		screenWidth = 800;
		screenHeight = 600;

		// Place the window in the middle of the screen.
		posX = (GetSystemMetrics(SM_CXSCREEN) - screenWidth) / 2;
		posY = (GetSystemMetrics(SM_CYSCREEN) - screenHeight) / 2;
	}

	RECT rc = { 0, 0, screenWidth, screenHeight };
	AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);

	// Create the window with the screen settings and get the handle to it.
	mHwnd = CreateWindowEx(
		WS_EX_APPWINDOW, 
		mApplicationName, 
		mApplicationName,
		WS_OVERLAPPEDWINDOW,
		posX, 
		posY, 
		rc.right - rc.left,
		rc.bottom - rc.top,
		NULL, 
		NULL, 
		mHinstance, 
		NULL);

	// Bring the window up on the screen and set it as main focus.
	ShowWindow(mHwnd, SW_SHOW);
	SetForegroundWindow(mHwnd);
	SetFocus(mHwnd);

	// Hide the mouse cursor.
	ShowCursor(true);

	return;
}

void SystemClass::ShutdownWindows()
{
	// Show the mouse cursor.
	ShowCursor(true);

	// Fix the display settings if leaving full screen mode.
	if (FULL_SCREEN)
	{
		ChangeDisplaySettings(NULL, 0);
	}

	// Remove the window.
	DestroyWindow(mHwnd);
	mHwnd = NULL;

	// Remove the application instance.
	UnregisterClass(mApplicationName, mHinstance);
	mHinstance = NULL;

	// Release the pointer to this class.
	ApplicationHandle = NULL;

	return;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT umessage, WPARAM wparam, LPARAM lparam)
{
	switch (umessage)
	{
		// Check if the window is being destroyed.
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		return 0;
	}

		// Check if the window is being closed.
	case WM_CLOSE:
	{
		PostQuitMessage(0);
		return 0;
	}

		// All other messages pass to the message handler in the system class.
	default:
	{
		return ApplicationHandle->MessageHandler(hwnd, umessage, wparam, lparam);
	}
	}
}