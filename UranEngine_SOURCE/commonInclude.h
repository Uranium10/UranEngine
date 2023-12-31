#pragma once
// 쓸 헤더들을 추가
#include <Windows.h>
#include <assert.h>
#include <vector>
#include "urTime.h"
#include <algorithm>
#include <string>
#include <map>
#include <functional>
#include "urMath.h"
#include <math.h>
#include <filesystem>

#include <mmsystem.h>
#include <dinput.h>

typedef const std::wstring WST;

#include "urLnums.h"
//비트맵
#pragma comment(lib, "Msimg32.lib");
#pragma comment(lib, "winmm.lib");

//png
#include <gdiplus.h>
#pragma comment(lib, "gdiplus.lib");