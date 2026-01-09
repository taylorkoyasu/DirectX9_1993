#include "stdafx.h"
#include "myApp.h"
#include "myBmpFont.h"
#include "myTimer.h"
#include "SceneManager.h"

// Title
void TitleScene::TitleInit() {
	m_logo.logoY = 0.0f;
	m_logo.logoSpeed = 120.0f;
	m_logo.logotime = 1.0f / 60.0f;
	//m_gameScene = GAME_SCENE_BEGIN;
}

void TitleScene::UpdateTitle()
{	
	float targetY = 200.0f; // 最終位置
	if (m_logo.logoY < targetY)
	{
		m_logo.logoY += m_logo.logoSpeed * m_logo.logotime;
		if (m_logo.logoY > targetY)
			m_logo.logoY = targetY;
	}
	MyInput* pInput = GetInputInst();
	if (pInput->IsPushKeyOne(DIK_RETURN)) {
		GetAppInst()->ChangeScene(GAME_SCENE_SELECT);
		return;
	}
	//MyInput* pInput = GetInputInst();
	//// 何かキーが押されたらゲームシーンへ
	//bool isAnyKeyPressed = false;
	//for (int i = 0; i < 256; ++i) {
	//	if (pInput->IsPushKeyOne(i)) {
	//		isAnyKeyPressed = true;
	//		break;
	//	}
	//}
	// コントローラーは2つ引数必要
	/*for (int i = 0; i < 30; ++i) {
		if (pInput->IsPushBtnOne(i)) {
			isAnyKeyPressed = true;
			break;
		}
	}*/
	//if (isAnyKeyPressed = true) {
	//	/*m_gameScene = GAME_SCENE_STORY;*/
	//	ChangeScene(GAME_SCENE_STORY);
	//	printf("キー入力 o");
	//}
}
//タイトル画面を描画
void TitleScene::DrawTitle()
{
	//Title messsage
	//背景
	IDirect3DDevice9* m_pDev = GetAppInst()->GetDxDev();// Direct3D デバイスの確認
	assert(m_pDev != NULL && "Direct3D デバイスが初期化されていません");
	ID3DXSprite* m_pSpr = GetAppInst()->GetDxSpr();// スプライトオブジェクトの確認
	assert(m_pSpr != NULL && "ID3DXSprite オブジェクトが初期化されていません");
	// 背景色を決める。RGB=(0,0,255)とする.-
	D3DCOLOR rgb = D3DCOLOR_XRGB(0, 0, 255);
	// 画面全体を消去.
	m_pDev->Clear(0, NULL, D3DCLEAR_TARGET, rgb, 1.0f, 0);

	// 描画を開始（シーン描画の開始）.
	m_pDev->BeginScene();
	m_pSpr->Begin(D3DXSPRITE_ALPHABLEND);

	D3DXMATRIX identity;
	D3DXMatrixIdentity(&identity);
	m_pSpr->SetTransform(&identity);

	IDirect3DTexture9* m_pTex = GetAppInst()->GetDxTex(TEX_TITLE);
	IDirect3DTexture9* m_pLogo = GetAppInst()->GetDxTex(TEX_LOGO);
	//D3DXMATRIX identity;
	//D3DXMatrixIdentity(&identity);
	//pSpr->SetTransform(&identity);
	// テクスチャ情報を取得（幅、高さ）
	D3DSURFACE_DESC desc;
	m_pTex->GetLevelDesc(0, &desc);

	float texW = (float)desc.Width;   // 512
	float texH = (float)desc.Height;  // 512

	// 画面いっぱいにするスケールを計算
	float scaleX = 1280.0f / texW;
	float scaleY = 1024.0f / texH;

	D3DXMATRIX mat;
	D3DXMatrixScaling(&mat, scaleX, scaleY, 1.0f);
	m_pSpr->SetTransform(&mat);

	// 背景画像の描画
	m_pSpr->Draw(m_pTex, nullptr, nullptr, nullptr, 0xFFFFFFFF);//888899

	//m_pSpr->Draw(m_pTex, &rc, NULL, NULL, 0xFFFFFFFF);
	//pSpr->Draw(pTex, nullptr, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));
	m_pSpr->End();
	// ロゴ
	m_pSpr->Begin(D3DXSPRITE_ALPHABLEND);

	// 行列
	D3DXMATRIX matScale, matTrans, matWorld;
	// 縮小率
	float scale = 1.5f;
	D3DXMatrixScaling(&matScale, scale, scale, 1.0f);

	// ロゴ幅（縮小後）
	float logoW = 512.0f * scale;

	// 中央寄せ
	float x = (WIDTH - logoW) / 2;
	float y = m_logo.logoY;

	D3DXMatrixTranslation(&matTrans, x, y, 0.0f);
	// 合成
	matWorld = matScale * matTrans;
	m_pSpr->SetTransform(&matWorld);

	m_pSpr->Draw(m_pLogo, NULL, NULL, NULL, 0xFFFFFFFF);
	//m_pSpr->Draw(m_pLogo, nullptr, nullptr, nullptr, 0xFFFFFFFF);
	m_pSpr->End();

	//text処理
	static int frameBlink = 0;

	// 点滅の間隔
	int blinkInterval = 30;
	frameBlink++;

	// 点滅 ON/OFF
	bool visible = (frameBlink / blinkInterval) % 2 == 0;

	// TEXTアニメーション描画 機体の4色で回す
	D3DCOLOR colors[4] =
	{
		D3DCOLOR_XRGB(230,  20,  20),   // 赤
		D3DCOLOR_XRGB(250, 200,  50),   // 黄色
		D3DCOLOR_XRGB(250, 100, 160),	// ピンク
		D3DCOLOR_XRGB(148, 20, 210),    // 紫 6216E5
	};
	static int colorTimer = 0;
	static int colorIndex = 0;
	static bool oldVisible = true;
	// 4色のインデックス
	if (visible == true && oldVisible == false)
	{
		colorIndex = rand() % 4;
	}
	oldVisible = visible;
	ID3DXFont* font = GetAppInst()->GetFont();
	// テキスト
	if (visible == true)   // 点滅 : OFFの時は描画しない
	{
		wchar_t Text[64];
		ZeroMemory(Text, sizeof(Text));
		swprintf_s(Text, 64, L"Hello world\n");
		// 中央に表示
		RECT rcTitle{ -30, (HEIGHT / 2) + 200, WIDTH, HEIGHT };
		// RECT rcTitle{ 0, 0, WIDTH, HEIGHT};
		 /*font->DrawText(nullptr, Text, -1, &rcTitle,
			 DT_CENTER | DT_VCENTER | DT_SINGLELINE,
			 colors[colorIndex]);*/
			 // コントローラーABXY
			 //font->DrawText(nullptr, L"任意のボタンを押してゲームを開始", -1, &rcTitle, DT_RIGHT | DT_TOP, D3DCOLOR_XRGB(255, 255, 0));
		font->DrawText(nullptr, L"任意のボタンを押してゲームを開始", -1, &rcTitle, DT_CENTER | DT_VCENTER, colors[colorIndex]);
	}
	// シーンの描画を終了
	m_pDev->EndScene();
}
void SelectScene::SelectInit()
{
	/*m_gameScene = GAME_SCENE_SELECT;*/
}

void SelectScene::UpdateSelect()
{
	MyInput* pInput = GetInputInst();
	// デバッグ用 : Enterキーでゲームシーンへ
	if (pInput->IsPushKeyOne(DIK_RETURN)) {
		/*m_gameScene = GAME_SCENE_STORY;*/
		GetAppInst()->ChangeScene(GAME_SCENE_STORY);
		printf("Enter");
		return;
	}
	if (state == STATE_MODE_SELECT) {

		if (pInput->IsPushKeyOne(DIK_UP) || pInput->IsPushKeyOne(DIK_W)) {
			currentMode = GameMode::Coop;
		}
		if (pInput->IsPushKeyOne(DIK_DOWN) || pInput->IsPushKeyOne(DIK_S)) {
			currentMode = GameMode::Versus;
	}
		// カーソル位置
		arrowPos = (currentMode == Coop)
			? D3DXVECTOR3(200, 1100, 0)
			: D3DXVECTOR3(200, 1500, 0);

		// モード変更検出
		if (currentMode != prevMode) {
			infoIndex = 0;
			infoTimer = 0.0f;
			whiteFade = true;
			whiteAlpha = 0.0f;
			prevMode = currentMode;
		}
		// 決定
		if (pInput->IsPushKeyOne(DIK_RETURN)) {
			state = STATE_WAIT_START;
		}
		return;
	}

	// 説明画像 自動切り替え
	infoTimer += 1.0f / 60.0f;
	if (infoTimer >= INFO_INTERVAL) {
		infoTimer = 0.0f;
		infoIndex = (infoIndex + 1) % 3;
		whiteFade = true;
		whiteAlpha = 0.0f;
	}
	// 白フェード更新
	const float fadeSpeed = 2.0f;
	if (whiteFade) {
		whiteAlpha += fadeSpeed * (1.0f / 60.0f);
		if (whiteAlpha >= 1.0f) {
			whiteAlpha = 1.0f;
			whiteFade = false;
		}
	}
	else if (whiteAlpha > 0.0f) {
		whiteAlpha -= fadeSpeed * (1.0f / 60.0f);
		if (whiteAlpha < 0.0f) whiteAlpha = 0.0f;
	}

	//// player 待機画面
	//if (state == STATE_WAIT_START) {
	//	if (pInput->IsPushKeyOne(DIK_RETURN)) {
	//		// 決定されたら	
	//		GetAppInst()->ChangeScene(GAME_SCENE_STORY);
	//		return;
	//	}

		// 2人以上のplayerがボタンを押しているか
		// おしたplayerの場所の画像は差し替える
	    /*if (IsReadyToStart() == true) {
			GetAppInst()->ChangeScene(GAME_SCENE_STORY);
			return;
		}*/
	//}
}

void SelectScene::DrawSelect()
{
	//Select messsage
	//背景
	IDirect3DDevice9* m_pDev = GetAppInst()->GetDxDev();// Direct3D デバイスの確認
	assert(m_pDev != NULL && "Direct3D デバイスが初期化されていません");
	ID3DXSprite* m_pSpr = GetAppInst()->GetDxSpr();// スプライトオブジェクトの確認
	assert(m_pSpr != NULL && "ID3DXSprite オブジェクトが初期化されていません");

	// 背景色を決める。RGB=(0,0,255)とする
	D3DCOLOR rgb = D3DCOLOR_XRGB(0, 0, 0);
	// 画面全体を消去.
	m_pDev->Clear(0, NULL, D3DCLEAR_TARGET, rgb, 1.0f, 0);
	// 描画を開始（シーン描画の開始）.
	m_pDev->BeginScene();
	m_pSpr->Begin(D3DXSPRITE_ALPHABLEND);
	D3DXMATRIX identity;
	D3DXMatrixIdentity(&identity);
	m_pSpr->SetTransform(&identity);
	
	IDirect3DTexture9* pTex = GetAppInst()->GetDxTex(TEX_SELECT);
	
	const D3DXVECTOR3 infoPos(300, 50, 0);

	if (state == STATE_MODE_SELECT) {
		if (currentMode == GameMode::Versus)
		{
			m_pSpr->Draw(
				infoTex_1[infoIndex],   // 対戦用
				NULL, NULL,
				&infoPos,
				D3DCOLOR_XRGB(255, 255, 255)
			);
		}
		else // Coop
		{
			m_pSpr->Draw(
				infoTex_2[infoIndex],   // 協力用
				NULL, NULL,
				&infoPos,
				D3DCOLOR_XRGB(255, 255, 255)
			);
		}
	}
	RECT CPRect = { 250, 580, 1000, 1800 };
	RECT VSRect = { 250, 780, 1400, 1800 };
	ID3DXFont* font = GetAppInst()->GetFont();
	font->DrawText(nullptr, L"協力モード:力を合わせてボスに勝利しよう", -1, &CPRect, DT_LEFT, D3DCOLOR_XRGB(255, 255, 255));
	font->DrawText(nullptr, L"対戦モード:アイテムを駆使して敵国(ライバル)を倒そう", -1, &VSRect, DT_LEFT, D3DCOLOR_XRGB(255, 255, 255));
	
	IDirect3DTexture9* pointTex = GetAppInst()->GetDxTex(TEX_CURSOR);
	// カーソル
	pointTex = GetAppInst()->GetDxTex(TEX_CURSOR);
	// 縮小
	float scale = 0.5f;
	// 変換行列
	D3DXMATRIX matScale;
	D3DXMatrixScaling(&matScale, scale, scale, 1.0f);
	m_pSpr->SetTransform(&matScale);
	// 描画
	/*m_pSpr->Draw(
		pointTex,
		NULL,
		NULL,
		NULL,
		D3DCOLOR_XRGB(255, 255, 255)
	);*/
	m_pSpr->Draw(pointTex, NULL, NULL, &arrowPos, 0xFFFFFFFF);
	D3DXMATRIX matIdentity;
	D3DXMatrixIdentity(&matIdentity);
	m_pSpr->SetTransform(&matIdentity);


	/*m_pSpr->Draw(pointTex, NULL, NULL, &arrowPos, 0xFFFFFFFF);*/

	/*if (whiteAlpha > 0.0f)
	{
		D3DCOLOR white =
			D3DCOLOR_ARGB(
				(int)(255 * whiteAlpha),
				255, 255, 255
			);*/

		//// 1×1 白テクスチャを全画面に拡大
		//D3DXMATRIX matScale;
		//D3DXMatrixScaling(&matScale,
		//	(float)WIDTH, (float)HEIGHT, 1.0f);
		//m_pSpr->SetTransform(&matScale);
		//m_pSpr->Draw(
		//	whiteTex,
		//	NULL, NULL,
		//	NULL,
		//	white
		//);

		//// 行列を戻す（超重要）
		//m_pSpr->SetTransform(&identity);

	//// 動画を取得してループ再生・カーソルが動いたら初期化
	//if (state == STATE_MODE_SELECT)
	//{
	//	// モード説明画像
	//	m_pSpr->Draw(
	//		infoTex_1[currentMode],
	//		NULL,
	//		NULL,
	//		&D3DXVECTOR3(300, 180, 0),
	//		D3DCOLOR_XRGB(255, 255, 255)
	//	);
	//	m_pSpr->Draw(
	//		infoTex_2[currentMode],
	//		NULL,
	//		NULL,
	//		&D3DXVECTOR3(300, 180, 0),
	//		D3DCOLOR_XRGB(255, 255, 255)
	//	);
	//	// 白フェード
	//	if (whiteAlpha > 0.0f) {
	//		D3DCOLOR white =
	//			D3DCOLOR_ARGB(int(255 * whiteAlpha), 255, 255, 255);

	//		RECT WhiteRc = {200, 200, WIDTH, HEIGHT};
	//	}
	//}


	//if (currentMode == GameMode::Versus)
	//{
	//	m_pSpr->Draw(
	//		infoTex_1[infoIndex],   // 対戦用
	//		NULL, NULL,
	//		&D3DXVECTOR3(300, 180, 0),
	//		D3DCOLOR_XRGB(255, 255, 255)
	//	);
	//}
	//else // Coop
	//{
	//	m_pSpr->Draw(
	//		infoTex_2[infoIndex],   // 協力用
	//		NULL, NULL,
	//		&D3DXVECTOR3(300, 180, 0),
	//		D3DCOLOR_XRGB(255, 255, 255)
	//	);
	//}

	//シーンの描画を終了.
	m_pSpr->End();
	m_pDev->EndScene();
}

//void GameScene::Init(){}
//void GameScene::Update(){}
//void GameScene::Draw(){}

void ResultScene::ResultInit()
{

}
void ResultScene::UpdateResult() {
	MyInput* pInput = GetInputInst();
	if (pInput->IsPushKeyOne(DIK_RETURN)) {
		GetAppInst()->ChangeScene(GAME_SCENE_TITLE);
		printf("push Enterkey");
		return;
	}
}
void ResultScene::DrawResult() {
	IDirect3DDevice9* m_pDev = GetAppInst()->GetDxDev();// Direct3D デバイスの確認
	assert(m_pDev != NULL && "Direct3D デバイスが初期化されていません");
	ID3DXSprite* m_pSpr = GetAppInst()->GetDxSpr();// スプライトオブジェクトの確認
	assert(m_pSpr != NULL && "ID3DXSprite オブジェクトが初期化されていません");

	D3DCOLOR rgb = D3DCOLOR_XRGB(64, 64, 64);
	// 画面全体を消去.
	m_pDev->Clear(0, NULL, D3DCLEAR_TARGET, rgb, 1.0f, 0);
	// 描画を開始（シーン描画の開始）.
	m_pDev->BeginScene();
	m_pSpr->Begin(D3DXSPRITE_ALPHABLEND);
	//IDirect3DTexture9* pTex = GetAppInst()->GetDxTex(TEX_TITLE);
	//// 背景画像の描画
	//m_pSpr->Draw(pTex, nullptr, nullptr, nullptr, 0xFFFFFFFF);//888899
	//m_pSpr->End();
	ID3DXFont* font = GetAppInst()->GetFont();
	// テキスト表示
	RECT rcWIN = { -30, -300, WIDTH, HEIGHT };
	font->DrawText(nullptr, L"Enterでタイトルへ", -1, &rcWIN, DT_CENTER | DT_TOP, D3DCOLOR_XRGB(255, 255, 0));//仮

	IDirect3DTexture9* pTex = GetAppInst()->GetDxTex(TEX_TITLE);
	//// 背景画像の描画
	//m_pSpr->Draw(pTex, nullptr, nullptr, nullptr, 0xFFFFFFFF);//888899
	//m_pSpr->End();
	m_pSpr->End();
	// テキスト表示
	font->DrawText(nullptr, L"任意のキーでタイトルへ", -1, &rcWIN, DT_CENTER | DT_TOP, D3DCOLOR_XRGB(255, 255, 0));//仮

	// 誰が勝利したか表示する(gamesceneで勝った人)
	//font->DrawText(nullptr, L" PL :勝利", /*&,*/-1,&rcWIN, DT_CENTER | DT_TOP, D3DCOLOR_XRGB(255, 255, 0));
	//RECT rcSelect = { -30, 0, WIDTH, HEIGHT };
	//font->DrawText(nullptr, L"もう一度戦う", /*&,*/-1,&rcWIN, DT_CENTER | DT_TOP, D3DCOLOR_XRGB(255, 255, 0));
	// 次の画面遷移を提示する (操作はどのPLができるか)

	m_pSpr->End();
	m_pDev->EndScene();
}