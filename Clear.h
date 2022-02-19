//================================================================================================================
//�Q�[���N���A��{����.h[Clear.h]
//date:2022/01/25         name:Kazuki Wada
//================================================================================================================
#ifndef CLEAR_H_
#define CLEAR_H_

#include "Scene.h"

//-------------
//�N���X��`
//-------------

class Clear :public Scene
{
private:
	float m_alfa;    //�A���t�@�l
	float m_Fade;
	float m_Var;
	float m_FadeIn;
	bool  m_IsChange;//�`�F���W�t���O
	bool  m_IsUse;	 //
public:
	void Init();
	void UnInit();
	void Update();
	void Draw();
};

#endif // !CLEAR_H_
