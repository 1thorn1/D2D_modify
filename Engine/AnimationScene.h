#pragma once
#include "BitmapScene.h"
#include "AnimationAsset.h"
#include "D2DRender.h"
#include "ResourceManager.h"
#include "World.h"
#include "CameraScene.h"
#include "GameObject.h"

struct ANIMATION_INFO;
class AnimationScene;

// 인터페이스 클래스
// 자식클래스에서 상속	받아 OnAnimationEnd 함수를 구현하여 애니메이션 종료시 처리할 내용을 작성한다.
class IAnimationProcesser
{
public:
	virtual void OnAnimationEnd(AnimationScene* pComponent, const std::string& AnimationName) = 0;
};

class AnimationScene
	: public BitmapScene
{
public:
	AnimationScene();
	virtual ~AnimationScene();

	// 공유하는 애니메이션 정보
	AnimationAsset* m_pAnimationAsset = nullptr;

	// 인스턴스마다 다른 애니매이션 정보
	ANIMATION_INFO* m_pAnimationInfo = nullptr; // 현재 애니메이션 프레임 정보
	std::wstring	m_strAnimationAssetFilePath;  // 애니메이션 정보, 파일 이름
	IAnimationProcesser* m_pAnimationProcesser = nullptr;		// 애니메이션 종료시 호출할 콜백 함수

	float m_FrameTime = 0.0f;				   // 프레임 진행 시간
	int	  m_FrameIndexCurr = -1;			   // 현재 프레임 인덱스
	int	  m_FrameIndexPrev = -1;			   // 이전 프레임 인덱스
	int	  m_AnimationIndex = -1;			   // 현재 애니메이션 인덱스
	D2D1_RECT_F m_SrcRect;					   // D2D1Bitmap의 Source 영역
	D2D1_RECT_F m_DstRect;					   // RenderTarget의 Destination영역
	D2D1_VECTOR_2F m_Center;

	bool m_bMirror;							   // 좌우 반전 여부
	D2D1_MATRIX_3X2_F m_ImageTransform;        // 반대 방향으로 뒤집기 위한 행렬 Scale.x = -0.1f

	bool m_bAnimationEnd = false;			   // 애니메이션 종료 여부

	bool IsAnimationEnd();					   // 애니메이션 종료 여부
	void LoadAnimationAsset(const std::wstring strFilePath);
	virtual void Update();
	void Render();
	void SetAnimation(int index, bool mirror);
};

