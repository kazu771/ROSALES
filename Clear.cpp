//================================================================================================================
//�Q�[���N���A��{����.cpp[Clear.cpp]
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
	Scene::UnInit(); //�p������uninit�̌Ăяo��,�I�[�o�[���C�h����Ƃǂ��炩�������Ă΂��悤�ɂȂ邽�߂����ň�x�Ă΂Ȃ��ƃ_��
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
	//true�ɂȂ�ƃt�F�[�h�p�̃A���t�@�l�𑝂₵�Ă���
	if (m_IsUse)
	{
		m_FadeIn += 0.01f;
	}

	if (m_FadeIn >= 1.0f)
	{
		m_IsChange = true;
	}
	//�`�F���W�t���O��true�ɂȂ�ƃV�[���̕ύX
	if (m_IsChange)
	{
		Manager::Setscene<FinishScene>();
	}
}

void Clear::Draw()
{
	
		Sprite::Draw(Texture::GetNum(TX_CLEAR), 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, m_Fade);

		//�{�^�����S
		Sprite::Draw(Texture::GetNum(TX_PUSH), 50.0f, 190.0f, 512.0f, 512.0f, 100.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, m_alfa);

		//�t�F�[�h
		if (m_IsUse)
		{
			Sprite::Draw(Texture::GetNum(TX_FADE), 0.0f, 0.0f, 960.0f, 700.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, m_FadeIn);
		}
}
