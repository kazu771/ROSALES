//==================================================================================================================
//�I����ʊ�{����.h[FnishScene.h]
//date:2022/02/18       name:Kazuki Wada
//==================================================================================================================
#ifndef FINISHSCENE_H_
#define FINISHSCENE_H_

#include "Scene.h"
class FinishScene : public Scene
{
private:
	float m_Fade;
	float m_FadeIn;
	float m_Var;
	float m_Alfa;
	bool m_IsUse;
	bool m_IsVisible;
public:
	void Init();   //������
	void UnInit(); //�I��
	void Update(); //�X�V
	void Draw();   //�`��
};
#endif // !FINISHSCENE_H_
