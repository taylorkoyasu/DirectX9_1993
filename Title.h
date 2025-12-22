#pragma once


// アニメーション
// logo.logoY;
struct logoAnime
{
	float logoY;
	float logoSpeed;
	float logotime;
};

class TitleScene {
public:
	
	void TitleInit();
	void UpdateTitle();     //更新関数
	void DrawTitle();       //描画関数

	//void ChangeScene(E_GAME_SCENE nextScene); // シーン変更処理

private:
	//ゲームシーンで必要なもの
	logoAnime m_logo;               // ロゴアニメーションの型


	// Get Set
};