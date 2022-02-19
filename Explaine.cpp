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
#include "Menu.h"
#include "Explaine.h"
#include "Rule.h"

void Explaine::Init()
{
	Texture::Init();
	Sprite::Init();
	m_Alfa = 0.0f;
	m_Var = 0.0f;
	m_Fadein = 0.0f;
	m_IsUse = false;
	m_IsVisible = false;
	
}

void Explaine::UnInit()
{
	Scene::UnInit(); //継承元のuninitの呼び出し,オーバーライドするとどちらかだけが呼ばれるようになるためここで一度呼ばないとダメ
	Texture::Uninit();
	Sprite::Uninit();
}


void Explaine::Update()
{
	Scene::Update();
	m_Var += 0.1f;
	m_Alfa = (float)sinf(m_Var);

	if (Input::GetKeyTrigger(VK_SPACE))
	{
		m_IsUse = true;
	}

	if (m_IsUse)
	{
		m_Fadein += 0.01f;
	}

	if (m_Fadein >= 1.0f)
	{
		m_IsVisible = true;
	}

	if (m_IsVisible)
	{
		Manager::Setscene<Rule>();
	}
}


void Explaine::Draw()
{
	Sprite::Draw(Texture::GetNum(TX_BACK), 0.0f, 0.0f, 960.0f, 540.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
	Sprite::Draw(Texture::GetNum(TX_EXP), 0.0f, 0.0f, 960.0f,540.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
	Sprite::Draw(Texture::GetNum(TX_WPUSH), 150.0f, 300.0f, 512.0f, 512.0f, 100.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, m_Alfa);
	if (m_IsUse)
	{
		Sprite::Draw(Texture::GetNum(TX_FADE), 0.0f, 0.0f, 960.0f, 700.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, m_Fadein);
	}
}