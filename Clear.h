//================================================================================================================
//ゲームクリア基本処理.h[Clear.h]
//date:2022/01/25         name:Kazuki Wada
//================================================================================================================
#ifndef CLEAR_H_
#define CLEAR_H_

#include "Scene.h"

//-------------
//クラス定義
//-------------

class Clear :public Scene
{
private:
	float m_alfa;    //アルファ値
	float m_Fade;
	float m_Var;
	float m_FadeIn;
	bool  m_IsChange;//チェンジフラグ
	bool  m_IsUse;	 //
public:
	void Init();
	void UnInit();
	void Update();
	void Draw();
};

#endif // !CLEAR_H_
