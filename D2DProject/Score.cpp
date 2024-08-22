#include "Score.h"
#include "VBall.h"

Score::Score()
{
}

Score::~Score()
{
}

void Score::Initialize()
{
}

void Score::Update()
{
	__super::Update();

	D2D1_RECT_F rect = { 480,10, 700,100 };
	//std::wstring key = L" Score : " + std::to_wstring(VBall::count_p1);
	std::wstring key = std::to_wstring(VBall::count_p2) + L" : " + std::to_wstring(VBall::count_p1);

	/*D2DRender::GetRenderTarget()->DrawTextW(
		key.c_str(), static_cast<UINT32>(key.size()),
		D2DRender::GetIDWriteTextFormat(),
		rect,
		D2DRender::GetID2D1SolidColorBrush());*/

	ID2D1SolidColorBrush* outlineBrush = nullptr;
	ID2D1SolidColorBrush* textBrush = nullptr;

	D2DRender::GetRenderTarget()->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Black, 1.0f), &outlineBrush);
	D2DRender::GetRenderTarget()->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::DarkOrange, 1.0f), &textBrush);

	D2DRender::GetRenderTarget()->DrawTextW
	(
		key.c_str(),
		static_cast<UINT32>(key.size()),

		D2DRender::GetIDWriteTextFormat(),
		rect,
		outlineBrush, // 외곽선 브러시
		D2D1_DRAW_TEXT_OPTIONS_NONE,
		DWRITE_MEASURING_MODE_NATURAL
	);

	D2DRender::GetRenderTarget()->DrawTextW
	(
		key.c_str(),
		static_cast<UINT32>(key.size()),
		D2DRender::GetIDWriteTextFormat(),
		rect,
		textBrush, // 텍스트 브러시
		D2D1_DRAW_TEXT_OPTIONS_NONE,
		DWRITE_MEASURING_MODE_NATURAL
	);
}

void Score::Render()
{
	__super::Render();
}
