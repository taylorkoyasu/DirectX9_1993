// SceneManager.h

#pragma once

// TitleClass
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
	logoAnime m_logo;    // ロゴアニメーションの型
	// Get Set
};

//SelectClass
enum GameMode {
	Coop,   // 協力
	Versus  // 対戦
};
enum SceneState {
	STATE_MODE_SELECT,   // モード選択中
	STATE_WAIT_START,    // 決定後（ゲーム参加
};

class SelectScene {

public:
	void SelectInit();
	void UpdateSelect();
	void DrawSelect();
	void IsReadyToStart();
	//初期規定
	SceneState state = STATE_MODE_SELECT;

	GameMode currentMode = GameMode::Coop;
	GameMode prevMode;
private:
	const float JOIN_TIME_LIMIT = 4.0f; // Debug
	//	const float JOIN_TIME_LIMIT = 15.0f;
	float joinTimer = 0.0f;
	int joinedPlayers = 1;     // test
	//	int joinedPlayers = 2; // 2Pは必須

	// 説明画像
	int     infoIndex;      // 何枚目の説明か（0,1,2）
	float   infoTimer;      // 切り替え用タイマー
	float INFO_INTERVAL;    // ゲームシーンまでの切り替わりタイマー

	// 白フェード
	float whiteAlpha;
	bool  whiteFade;
	// 説明画像（2～3枚）
	IDirect3DTexture9* infoTex_1[2]; // 対戦
	IDirect3DTexture9* infoTex_2[2]; // 協力
	D3DXVECTOR3 arrowPos;
	D3DXVECTOR3 IconPos1;
	D3DXVECTOR3 IconPos2;
	D3DXVECTOR3 IconPos3;
	D3DXVECTOR3 IconPos4;
	int m_infoMax = 3;

	bool isP1Activated = false;
	bool isP2Activated = false;
	bool isP3Activated = false;
	bool isP4Activated = false;

};

class GameScene {

public:
	/*void GameInit();
	void UpdateGame();
	void DrawGame();*/

private:



};

class ResultScene{
public:
	void ResultInit();
	void UpdateResult();
	
	void DrawResult();

private:

};