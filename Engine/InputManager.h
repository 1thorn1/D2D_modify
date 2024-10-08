#pragma once

class InputManager
{
public:
	bool IsKeyDown(int VKCode) { return GetAsyncKeyState(VKCode) & 0x8000; }
	bool IsKeyUp(int VKCode) { return !(GetAsyncKeyState(VKCode) & 0x8000); }
	bool IsKeyHold(int VKCode) { return (GetAsyncKeyState(VKCode) & 0x8000) != 0; }
};

// 梓端 幻級奄
// 葵聖 籍嬢獄形亀 喫
// 痕呪 差紫 
// 舛旋 拝雁

// 匂昔斗 痕呪
// 神崎詮闘税 舛左 -> 什坪覗 蟹尽聖 凶 舛左 紫虞像 照掬蕉蕉だし
// 葵聖 籍嬢獄軒檎 照掬
// 疑旋拝雁 -> しし しし しし しし しし しし 鎧亜 背薦背匝 凶猿走 葵戚 害焼赤製
// 葵戚 眼移赤澗 是帖研 亜軒鉄