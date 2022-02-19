//===================================================================================================================================
//�^�C�g����{����.h[Title.h]
//date:2021/04/27   name;Kazuki Wada
//===================================================================================================================================
#ifndef TITLE_H_
#define TITLE_H_


#include "Scene.h"
#include "Titlelogo.h"
class Title: public Scene
{
private:
	bool isVisible;
	float m_Fadein;
	float m_Fade;
public:
	void Init();   //������
	void UnInit(); //�I��
	void Update(); //�X�V
	void Draw();
	float m_Alfa;
	float m_Var;
	bool m_IsUse;
};

#endif // !TITLE_H_