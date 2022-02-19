//====================================================================================================================
//�����h�A��{����.h[Door.h]
//date:2021/11/16   name:Kazuki Wada
//====================================================================================================================

#include "GameObject.h"

#ifndef DOOR_H_
#define DOOR_H_

class Door : public GameObject
{
public:
	enum DoorType
	{
		DoorType_Right = 0,
		DoorType_Left,
		DoorType_Max,
	};
	void Init();
	void UnInit();
	void Update();
	void Draw();
	bool SetActive();//�����g�������ǂ���

private:

	class Model*		m_Door;  //�X�s�[�h�A�C�e���p
	class Key*			m_Key;//���p
	class Player*		m_Player;
	ID3D11VertexShader* m_VertexShader = NULL;
	ID3D11PixelShader*  m_PixelShader = NULL;
	ID3D11InputLayout*  m_VertexLayout = NULL;
	bool				m_isActive; //true:���Ɉړ�,false:�����Ȃ�
	bool				m_Chack;//�v���C���[�������擾�������ǂ�������p
	int					m_Cnt;//�h�A�𓮂����Ƃ��̃J�E���g�p
};

#endif // !DOOR_H_

#pragma once