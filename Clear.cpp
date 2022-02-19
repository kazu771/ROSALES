//================================================================================================================
//ゲームクリア基本処理.cpp[Clear.cpp]
//date:2022/01/25         name:Kazuki Wada
//================================================================================================================
#include "main.h"
#include "Scene.h"
#include "manager.h"
#include "renderer.h"
#include "input.h"
#include "Texture.h"
#include "Sprite.h"
#include "assetnames.h"
#include "Clear.h"
#include "Title.h"
#include "FinishScene.h"

void Clear::Init()
{
	Texture::Init();
	Sprite::Init();
	m_IsUse = false;
	m_IsChange = false;
	m_alfa = 1.0f;
	m_Var = 0.0f;
	m_Fade = 0.0f;
	m_FadeIn = 0.0f;
}

void Clear::UnInit()
{
	Scene::UnInit(); //継承元のuninitの呼び出し,オーバーライドするとどちらかだけが呼ばれるようになるためここで一度呼ばないとダメ
	Texture::Uninit();
	Sprite::Uninit();
}

void Clear::Update()
{
	m_Var += 0.1f;
	m_alfa = sinf(m_Var);
	m_Fade += 0.01f;
	m_FadeIn += 0.01f;

	if (Input::GetKeyTrigger(VK_SPACE))
	{
		m_IsUse = true;

	}
	//trueになるとフェード用のアルファ値を増やしていく
	if (m_IsUse)
	{
		m_FadeIn += 0.01f;
	}

	if (m_FadeIn >= 1.0f)
	{
		m_IsChange = true;
	}
	//チェンジフラグがtrueになるとシーンの変更
	if (m_IsChange)
	{
		Manager::Setscene<FinishScene>();
	}
}

void Clear::Draw()
{
	
		Sprite::Draw(Texture::GetNum(TX_CLEAR), 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, m_Fade);

		//ボタンロゴ
		Sprite::Draw(Texture::GetNum(TX_PUSH), 50.0f, 190.0f, 512.0f, 512.0f, 100.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, m_alfa);

		//フェード
		if (m_IsUse)
		{
			Sprite::Draw(Texture::GetNum(TX_FADE), 0.0f, 0.0f, 960.0f, 700.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, m_FadeIn);
		}
}
