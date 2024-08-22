#pragma once
#include "DemoApp.h"

class TextScore : public GameObject
{

	static ID2D1SolidColorBrush* outlineBrush;
	static ID2D1SolidColorBrush* textBrush;
public:
	TextScore();
	~TextScore();

	void Initialize();
	void Update();
	void Render();
	static void Clear();
};

