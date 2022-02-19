//========================================================================================
//操作説明基本処理.cpp[Explaine.cpp]
//ate:2021/08/28  name:Kazuki Wada
//========================================================================================
#include "main.h"
#include "Scene.h"
#include "manager.h"
#include "renderer.h"
#include "input.h"
#include "assetnames.h"
#include "Texture.h"
#include "Sprite.h"
#include "Game.h"
#include "FinishScene.h"

void FinishScene::Init()
{
	Texture::Init();
	Sprite::Init();
	m_Alfa = 0.0f;
	m_Var = 0.0f;
	m_Fade = 0.0f;
	m_FadeIn = 0.0f;
	m_IsUse = false;
	m_IsVisible = false;

}

void FinishScene::UnInit()
{
	Scene::UnInit(); //継承元のuninitの呼び出し,オーバーライドするとどちらかだけが呼ばれるようになるためここで一度呼ばないとダメ
	Texture::Uninit();
	Sprite::Uninit();
}


void FinishScene::Update()
{
	Scene::Update();
	m_Var += 0.1f;
	m_Alfa = (float)sinf(m_Var);
	m_Fade += 0.01f;
	if (Input::GetKeyTrigger(VK_SPACE))
	{
		m_IsUse = true;
	}

	if (m_IsUse)
	{
		m_FadeIn += 0.01f;
	}

	if (m_FadeIn >= 1.0f)
	{
		m_IsVisible = true;
	}

	if (m_IsVisible)
	{
		Manager::Setscene<Game>();
	}
}


void FinishScene::Draw()
{
	Sprite::Draw(Texture::GetNum(TX_FIRST), 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, m_Fade);
	Sprite::Draw(Texture::GetNum(TX_WPUSH), 150.0f, 300.0f, 512.0f, 512.0f, 100.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, m_Alfa);
	if (m_IsUse)
	{
		Sprite::Draw(Texture::GetNum(TX_FADE), 0.0f, 0.0f, 960.0f, 700.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, m_FadeIn);
	}
}