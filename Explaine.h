//=======================================================================================
//Explaine基本処理.h[Explain.h]
//date:2021/08/28   name:Kazuki Wada
//=======================================================================================
#ifndef EXPLAINE_H_
#define EXPLAINE_H_

#include "Scene.h"
class Explaine : public Scene
{
private:
	float m_Fadein;
	bool m_IsUse;
	bool m_IsVisible;
	float m_Var;
	float m_Alfa;
public:
	void Init();   //初期化
	void UnInit(); //終了
	void Update(); //更新
	void Draw();   //描画
};
#endif // !EXPLAINE_H_
