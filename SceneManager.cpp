#include "stdafx.h"
#include "myApp.h"
#include "myBmpFont.h"
#include "SceneManager.h"

// Title
void TitleScene::TitleInit() {

	MyApp* app = MyApp::GetInstance();
	app->SetWinnerIndex(-1); // 初期化

	m_logo.logoY = 0.0f;
	m_logo.logoSpeed = 120.0f;
	m_logo.logotime = 1.0f / 60.0f;
	//m_gameScene = GAME_SCENE_BEGIN;
	//InitExplosion();
}

//EffectAnim m_explosion;
//
//void TitleScene::InitExplosion()
//{
//	m_explosion.isActive = false;
//	m_explosion.frame = 0;
//	m_explosion.maxFrame = 40;          //画像のコマ数
//	m_explosion.frameTime = 0.1f;      // 0.05秒ごと
//	m_explosion.timer = 0.0f;
//
//	m_explosion.frameW = 32;              // 画像1コマの幅
//	m_explosion.frameH = 32;              // 高さ
//}
//
//void TitleScene::StartExplosion(float x, float y)
//{
//	m_explosion.isActive = true;
//	m_explosion.frame = 0;
//	m_explosion.timer = 0.0f;
//	m_explosion.AnimPos = D3DXVECTOR3(x, y, 0);// デスしたキャラ座標を取得
//}
//void TitleScene::UpdateExplosion(float deltaTime)
//{
//	if (!m_explosion.isActive) return;
//
//	m_explosion.timer += deltaTime;
//	float frameDuration = 2.0f / 40; // 2秒で40フレーム
//
//	if (m_explosion.timer >= frameDuration)
//	{
//		m_explosion.timer -= frameDuration;
//		m_explosion.frame++;
//		if (m_explosion.frame >= m_explosion.maxFrame)
//		{
//			m_explosion.isActive = false;
//		}
//	}
//}

void TitleScene::UpdateTitle()
{	
	float targetY = 180.0f; // 最終位置
	if (m_logo.logoY < targetY)
	{
		m_logo.logoY += m_logo.logoSpeed * m_logo.logotime;
		if (m_logo.logoY > targetY) {
			m_logo.logoY = targetY;
		}
	}
	MyInput* pInput = GetInputInst();
	if (pInput->IsPushKeyOne(DIK_RETURN)) {
		GetAppInst()->ChangeScene(GAME_SCENE_SELECT);
		return;
	}
	//if (pInput->IsPushKeyOne(DIK_J)) {
	//	StartExplosion(300 ,400);
	//	return;
	//}
	//UpdateExplosion(1.0f / 60.0f); // 仮で60FPS想定
	// 確認済み
	if ((pInput->IsPushBtnOne(JOY_CON_0, JOY_BTN_BIT_A))||(pInput->IsPushBtnOne(JOY_CON_0, JOY_BTN_BIT_B)||(pInput->IsPushBtnOne(JOY_CON_0, JOY_BTN_BIT_X)))) {
		GetAppInst()->ChangeScene(GAME_SCENE_SELECT);
		return;
	}
	if ((pInput->IsPushBtnOne(JOY_CON_1, JOY_BTN_BIT_A))||(pInput->IsPushBtnOne(JOY_CON_1, JOY_BTN_BIT_B)||(pInput->IsPushBtnOne(JOY_CON_1, JOY_BTN_BIT_X)))) {
		GetAppInst()->ChangeScene(GAME_SCENE_SELECT);
		return;
	}
	if ((pInput->IsPushBtnOne(JOY_CON_2, JOY_BTN_BIT_A))||(pInput->IsPushBtnOne(JOY_CON_2, JOY_BTN_BIT_B)||(pInput->IsPushBtnOne(JOY_CON_2, JOY_BTN_BIT_X)))) {
		GetAppInst()->ChangeScene(GAME_SCENE_SELECT);
		return;
	}
	if ((pInput->IsPushBtnOne(JOY_CON_3, JOY_BTN_BIT_A))||(pInput->IsPushBtnOne(JOY_CON_3, JOY_BTN_BIT_B)||(pInput->IsPushBtnOne(JOY_CON_3, JOY_BTN_BIT_X)))) {
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
	//IDirect3DTexture9* m_pUI = GetAppInst()->GetDxTex(TEX_UI_SENSHA);

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
	//m_pSpr->Draw(m_pTex, nullptr, nullptr, nullptr, 0xFFFFFFFF);//888899
	m_pSpr->Draw(m_pTex, nullptr, nullptr, nullptr, 0xEECCFFAA);
	//m_pSpr->Draw(m_pTex, &rc, NULL, NULL, 0xFFFFFFFF);
	//pSpr->Draw(pTex, nullptr, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));
	m_pSpr->End();

	//if (m_explosion.isActive)
	//{
	//	IDirect3DTexture9* m_pAnim = GetAppInst()->GetDxTex(TEX_EXP_ANIME);
	//	if (m_pAnim)
	//	{
	//		m_pSpr->Begin(D3DXSPRITE_ALPHABLEND);

	//		// 5x8のグリッド計算
	//		// 横に5枚なので、5で割った余りがX(列)、5で割った商がY(行)
	//		int frameX = m_explosion.frame % 5;
	//		int frameY = m_explosion.frame / 5;

	//		RECT src;
	//		src.left = (long)(frameX * m_explosion.frameW);
	//		src.top = (long)(frameY * m_explosion.frameH);
	//		src.right = (long)(src.left + m_explosion.frameW);
	//		src.bottom = (long)(src.top + m_explosion.frameH);

	//		// 行列によるトランスフォーム（拡大率と座標）
	//		float scaleA = 3.0f;
	//		D3DXMATRIX matScale, matTrans, matWorld;
	//		D3DXMatrixScaling(&matScale, scaleA, scaleA, 1.0f);
	//		D3DXMatrixTranslation(&matTrans, m_explosion.AnimPos.x, m_explosion.AnimPos.y, 0.0f);

	//		matWorld = matScale * matTrans;
	//		m_pSpr->SetTransform(&matWorld);

	//		// 描画実行
	//		m_pSpr->Draw(m_pAnim, &src, nullptr, nullptr, 0xFFFFFFFF);

	//		// 他の描画に影響が出ないよう行列を単位行列に戻す
	//		D3DXMATRIX identity;
	//		D3DXMatrixIdentity(&identity);
	//		m_pSpr->SetTransform(&identity);
	//		m_pSpr->End();
	//	}
	//}

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
	//m_pSpr->Begin(D3DXSPRITE_ALPHABLEND);

	//// スケール設定
	//float scaleUI = 1.0f;
	//D3DXMatrixScaling(&matScale, scaleUI, scaleUI, 1.0f);
	//float screenWidth = 1280.0f;
	//float screenHeight = 1024.0f;
	//float imageW = 512.0f * scaleUI; // スケール後の幅
	//float imageH = 512.0f * scaleUI; // スケール後の高さ
	//float posX = screenWidth - imageW;
	//float posY = screenHeight - imageH;

	//D3DXMatrixTranslation(&matTrans, posX, posY, 0.0f);
	//// 行列の合成（SRTの順：Scale -> Rotation -> Translation）
	//matWorld = matScale * matTrans;

	//// 行列の適用と描画
	//m_pSpr->SetTransform(&matWorld);
	//m_pSpr->Draw(m_pUI, NULL, NULL, NULL, 0xFFFFFFFF);

	//m_pSpr->End();

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
	cdTimer.StartTimer();    // タイマー開始
	int infoIndex = 0;
	float infoTimer = 3.0f;  //選択

	float whiteAlpha = 0.0f;
	bool whiteFade = false;
    isP1Activated = false;
    isP2Activated = false;
    isP3Activated = false;
    isP4Activated = false;
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
	//if (pInput->IsPushKeyOne(DIK_SPACE)) // Aボタンなど
	//{
	//	isP1Activated = true;
	//	isActivCnt++;
	//}
	if (pInput->IsPushBtnOne(JOY_CON_0, JOY_BTN_BIT_A)) // Aボタンなど
	{
		isP1Activated = true;
		//isP2Activated = true;
		isActivCnt++;
	}
	if (pInput->IsPushBtnOne(JOY_CON_1, JOY_BTN_BIT_A)) // Aボタンなど
	{
		//isP3Activated = true;
		isP2Activated = true;
		isActivCnt++;
	}
	if (pInput->IsPushBtnOne(JOY_CON_2, JOY_BTN_BIT_A)) // Aボタンなど
	{
		isP3Activated = true;
		//isP4Activated = true;
		isActivCnt++;
	}
	if (pInput->IsPushBtnOne(JOY_CON_3, JOY_BTN_BIT_A)) // Aボタンなど
	{
		isP4Activated = true;
		isActivCnt++;
	}

	//if (state == STATE_MODE_SELECT) {
	//	if (pInput->IsPushKeyOne(DIK_UP) || pInput->IsPushKeyOne(DIK_W)) {
	//		currentMode = GameMode::Coop;
	//	}
	//	if (pInput->IsPushKeyOne(DIK_DOWN) || pInput->IsPushKeyOne(DIK_S)) {
	//		currentMode = GameMode::Versus;
	//}
	//	// カーソル位置
	//	arrowPos = (currentMode == Coop)
	//		? D3DXVECTOR3(200, 1100, 0)
	//		: D3DXVECTOR3(200, 1500, 0);

	//	// モード変更検出
	//	if (currentMode != prevMode) {
	//		infoIndex = 0;
	//		infoTimer = 0.0f;
	//		whiteFade = true;
	//		whiteAlpha = 0.0f;
	//		prevMode = currentMode;
	//	}
	//	// 決定
	//	if (pInput->IsPushKeyOne(DIK_RETURN)) {
	//		state = STATE_WAIT_START;
	//	}
	//	return;
	//}

	//// 説明画像 自動切り替え
	//infoTimer += 1.0f / 60.0f;
	//if (infoTimer >= 3) {
	//	infoTimer = 0.0f;
	//	infoIndex = (infoIndex + 1) % 3;
	//	whiteFade = true;
	//	whiteAlpha = 0.0f;
	//}

	//// player 待機画面
    //if (state == STATE_WAIT_START) {
	// Timer秒
	UINT fps;
	cdTimer.GetPassTime(&interval, &fps);
	//15秒経過したらシーン移行
		if (interval > (15*1000000))
		{
			// タイムアップ処理
		    // if (pInput->IsPushKeyOne(DIK_RETURN)) {
			// 決定されたら	
		    if(isActivCnt > 2){
				GetAppInst()->ChangeScene(GAME_SCENE_STORY);	
				return;
			}
			else {
				GetAppInst()->ChangeScene(GAME_SCENE_TITLE);
				return;
			}
		//}
		}		
	//}

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
	// 待機時の
	IDirect3DTexture9* pTex2 = GetAppInst()->GetDxTex(TEX_SELECT);
	
	//const D3DXVECTOR3 infoPos(300, 50, 0);

	//if (state == STATE_MODE_SELECT) {
	//	if (currentMode == GameMode::Versus)
	//	{
	//		m_pSpr->Draw(
	//			infoTex_1[infoIndex],   // 対戦用
	//			NULL, NULL,
	//			&infoPos,
	//			D3DCOLOR_XRGB(255, 255, 255)
	//		);
	//	}
	//	else // Coop
	//	{
	//		m_pSpr->Draw(
	//			infoTex_2[infoIndex],   // 協力用
	//			NULL, NULL,
	//			&infoPos,
	//			D3DCOLOR_XRGB(255, 255, 255)
	//		);
	//	}
	//}

	//if (state == STATE_WAIT_START) {
	///*	int sec = (int)INFO_INTERVAL;
	//	m_pSpr->Draw(infoTex_1[infoIndex], NULL, NULL,&infoPos,D3DCOLOR_XRGB(255, 255, 255));*/
	//}

	//待機画面


	//IDirect3DTexture9* pointTex = GetAppInst()->GetDxTex(TEX_CURSOR);
	//// カーソル
	//pointTex = GetAppInst()->GetDxTex(TEX_CURSOR);
	//// 縮小
	//float scale = 0.5f;
	//// 変換行列
	//D3DXMATRIX matScale;
	//D3DXMatrixScaling(&matScale, scale, scale, 1.0f);
	//m_pSpr->SetTransform(&matScale);
	//// 描画
	//m_pSpr->Draw(pointTex, NULL, NULL, &arrowPos, 0xFFFFFFFF);
	//D3DXMATRIX matIdentity;
	//D3DXMatrixIdentity(&matIdentity);
	//m_pSpr->SetTransform(&matIdentity);

	//m_pSpr->End();

	//RECT CPRect = { 250, 580, 1000, 1800 };
	//RECT VSRect = { 250, 780, 1400, 1800 };
	//ID3DXFont* font = GetAppInst()->GetFont();
	//font->DrawText(nullptr, L"協力モード:力を合わせてボスに勝利しよう", -1, &CPRect, DT_LEFT, D3DCOLOR_XRGB(255, 255, 255));
	//font->DrawText(nullptr, L"対戦モード:アイテムを駆使して敵国(ライバル)を倒そう", -1, &VSRect, DT_LEFT, D3DCOLOR_XRGB(255, 255, 255));

	// ここはまだ
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

	IDirect3DTexture9* whiteTex = nullptr;
	m_pDev->CreateTexture(
		1, 1,
		1,
		0,
		D3DFMT_A8R8G8B8,
		D3DPOOL_MANAGED,
		&whiteTex,
		nullptr
	);

	D3DLOCKED_RECT lr;
	whiteTex->LockRect(0, &lr, nullptr, 0);
	*(DWORD*)lr.pBits = 0xFFFFFFFF; // 白
	whiteTex->UnlockRect(0);

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

	// ゲーム待機
	
	D3DSURFACE_DESC desc;
	pTex2->GetLevelDesc(0, &desc);
	float texW = (float)desc.Width;   // 512
	float texH = (float)desc.Height;  // 512
	// 画面いっぱいにするスケールを計算
	float scaleX = 1280.0f / texW;
	float scaleY = 1024.0f / texH;

	D3DXMATRIX mat;
	D3DXMatrixScaling(&mat, scaleX, scaleY, 1.0f);
	m_pSpr->SetTransform(&mat);

	// 背景画像の描画
	m_pSpr->Draw(pTex2, nullptr, nullptr, nullptr, 0xFFFFFFFF);

    IDirect3DTexture9* iconTex1 = GetAppInst()->GetDxTex(TEX_AAAPHTO);
    IDirect3DTexture9* iconTex2 = GetAppInst()->GetDxTex(TEX_BBBPHTO);
    IDirect3DTexture9* iconTex3 = GetAppInst()->GetDxTex(TEX_CCCPHTO);
    IDirect3DTexture9* iconTex4 = GetAppInst()->GetDxTex(TEX_DDDPHTO);
	// カーソル
	iconTex1 = GetAppInst()->GetDxTex(TEX_AAAPHTO);
	iconTex2 = GetAppInst()->GetDxTex(TEX_BBBPHTO);
	iconTex3 = GetAppInst()->GetDxTex(TEX_CCCPHTO);
	iconTex4 = GetAppInst()->GetDxTex(TEX_DDDPHTO);

	D3DXVECTOR3 IconPos1(300, 200,0);
	D3DXVECTOR3 IconPos2(800, 200,0);
	D3DXVECTOR3 IconPos3(300, 600,0);
	D3DXVECTOR3 IconPos4(800, 600,0);

	// アイコン
	{
		D3DSURFACE_DESC desc1;
		iconTex1->GetLevelDesc(0, &desc1);
		// 拡大率
		float scale = 2.0f;
		// 拡大行列
		D3DXMATRIX matScale, matTrans;
		D3DXMatrixScaling(&matScale, scale, scale, 1.0f);
		// 移動行列
		D3DXMatrixTranslation(&matTrans, IconPos1.x, IconPos1.y, 0);
		// 合成（スケール → 移動）
		D3DXMATRIX matWorld = matScale * matTrans;
		m_pSpr->SetTransform(&matWorld);
		// アイコン描画
		m_pSpr->Draw(iconTex1, NULL, NULL, NULL, 0xFFFFFFFF);

		D3DXMATRIX matIdentity;
		D3DXMatrixIdentity(&matIdentity);
		m_pSpr->SetTransform(&matIdentity);
	}
	{
		D3DSURFACE_DESC desc2;
		iconTex2->GetLevelDesc(0, &desc2);
		// 拡大率
		float scale = 2.0f;
		// 拡大行列
		D3DXMATRIX matScale, matTrans;
		D3DXMatrixScaling(&matScale, scale, scale, 1.0f);
		// 移動行列
		D3DXMatrixTranslation(&matTrans, IconPos2.x, IconPos2.y, 0);
		// 合成（スケール → 移動）
		D3DXMATRIX matWorld = matScale * matTrans;
		m_pSpr->SetTransform(&matWorld);
		// アイコン描画
		m_pSpr->Draw(iconTex2, NULL, NULL, NULL, 0xFFFFFFFF);

		D3DXMATRIX matIdentity;
		D3DXMatrixIdentity(&matIdentity);
		m_pSpr->SetTransform(&matIdentity);
	}
	{
		D3DSURFACE_DESC desc3;
		iconTex3->GetLevelDesc(0, &desc3);
		// 拡大率
		float scale = 2.0f;
		// 拡大行列
		D3DXMATRIX matScale, matTrans;
		D3DXMatrixScaling(&matScale, scale, scale, 1.0f);
		// 移動行列
		D3DXMatrixTranslation(&matTrans, IconPos3.x, IconPos3.y, 0);
		// 合成（スケール → 移動）
		D3DXMATRIX matWorld = matScale * matTrans;
		m_pSpr->SetTransform(&matWorld);
		// アイコン描画
		m_pSpr->Draw(iconTex3, NULL, NULL, NULL, 0xFFFFFFFF);

		D3DXMATRIX matIdentity;
		D3DXMatrixIdentity(&matIdentity);
		m_pSpr->SetTransform(&matIdentity);
	}
	{
		D3DSURFACE_DESC desc4;
		iconTex4->GetLevelDesc(0, &desc4);
		// 拡大率
		float scale = 2.0f;
		// 拡大行列
		D3DXMATRIX matScale, matTrans;
		D3DXMatrixScaling(&matScale, scale, scale, 1.0f);
		// 移動行列
		D3DXMatrixTranslation(&matTrans, IconPos4.x, IconPos4.y, 0);
		// 合成（スケール → 移動）
		D3DXMATRIX matWorld = matScale * matTrans;
		m_pSpr->SetTransform(&matWorld);
		// アイコン描画
		m_pSpr->Draw(iconTex4, NULL, NULL, NULL, 0xFFFFFFFF);

		D3DXMATRIX matIdentity;
		D3DXMatrixIdentity(&matIdentity);
		m_pSpr->SetTransform(&matIdentity);
	}

	// グレーオーバーレイ
	if (!isP1Activated)
	{
		D3DSURFACE_DESC desc1;
		iconTex1->GetLevelDesc(0, &desc1);
		float scaleG = 1.5f;
		D3DXMATRIX matGrayScale, matGrayTrans, matGrayWorld;
		// 1x1のwhiteTexを「表示倍率×アイコンのピクセル幅」に拡大する
		D3DXMatrixScaling(&matGrayScale, scaleG * desc1.Width, scaleG * desc1.Height, 1.0f);
		D3DXMatrixTranslation(&matGrayTrans, IconPos1.x, IconPos1.y, 0);

		matGrayWorld = matGrayScale * matGrayTrans;
		m_pSpr->SetTransform(&matGrayWorld);

		// 1x1のテクスチャをアイコンサイズまで引き伸ばして描画
		m_pSpr->Draw(whiteTex, NULL, NULL, NULL, D3DCOLOR_ARGB(220, 80, 80, 80));

		D3DXMATRIX matIdentity;
		D3DXMatrixIdentity(&matIdentity);
		m_pSpr->SetTransform(&matIdentity);
	}
	if (!isP2Activated)
	{
		D3DSURFACE_DESC desc;
		iconTex2->GetLevelDesc(0, &desc);
		float scaleG = 1.5f;
		D3DXMATRIX matGrayScale, matGrayTrans, matGrayWorld;
		// 1x1のwhiteTexを「表示倍率×アイコンのピクセル幅」に拡大する
		D3DXMatrixScaling(&matGrayScale, scaleG * desc.Width, scaleG * desc.Height, 1.0f);
		D3DXMatrixTranslation(&matGrayTrans, IconPos2.x, IconPos2.y, 0);

		matGrayWorld = matGrayScale * matGrayTrans;
		m_pSpr->SetTransform(&matGrayWorld);

		// 1x1のテクスチャをアイコンサイズまで引き伸ばして描画
		m_pSpr->Draw(whiteTex, NULL, NULL, NULL, D3DCOLOR_ARGB(220, 80, 80, 80));

		D3DXMATRIX matIdentity;
		D3DXMatrixIdentity(&matIdentity);
		m_pSpr->SetTransform(&matIdentity);
	}
	if (!isP3Activated)
	{
		D3DSURFACE_DESC desc;
		iconTex3->GetLevelDesc(0, &desc);
		float scaleG = 1.5f;
		D3DXMATRIX matGrayScale, matGrayTrans, matGrayWorld;
		// 1x1のwhiteTexを「表示倍率×アイコンのピクセル幅」に拡大する
		D3DXMatrixScaling(&matGrayScale, scaleG * desc.Width, scaleG * desc.Height, 1.0f);
		D3DXMatrixTranslation(&matGrayTrans, IconPos3.x, IconPos3.y, 0);

		matGrayWorld = matGrayScale * matGrayTrans;
		m_pSpr->SetTransform(&matGrayWorld);

		// 1x1のテクスチャをアイコンサイズまで引き伸ばして描画
		m_pSpr->Draw(whiteTex, NULL, NULL, NULL, D3DCOLOR_ARGB(220, 80, 80, 80));

		D3DXMATRIX matIdentity;
		D3DXMatrixIdentity(&matIdentity);
		m_pSpr->SetTransform(&matIdentity);
	}
	if (!isP4Activated)
	{
		D3DSURFACE_DESC desc;
		iconTex4->GetLevelDesc(0, &desc);
		float scaleG = 1.5f;
		D3DXMATRIX matGrayScale, matGrayTrans, matGrayWorld;
		// 1x1のwhiteTexを「表示倍率×アイコンのピクセル幅」に拡大する
		D3DXMatrixScaling(&matGrayScale, scaleG * desc.Width, scaleG * desc.Height, 1.0f);
		D3DXMatrixTranslation(&matGrayTrans, IconPos4.x, IconPos4.y, 0);

		matGrayWorld = matGrayScale * matGrayTrans;
		m_pSpr->SetTransform(&matGrayWorld);

		// 1x1のテクスチャをアイコンサイズまで引き伸ばして描画
		m_pSpr->Draw(whiteTex, NULL, NULL, NULL, D3DCOLOR_ARGB(220, 80, 80, 80));

		D3DXMATRIX matIdentity;
		D3DXMatrixIdentity(&matIdentity);
		m_pSpr->SetTransform(&matIdentity);
	}
	m_pSpr->End();

	LONGLONG restSec = 15 - (interval / 1000000);
	if(restSec < 0)
	{
		restSec = 0;
	}
	ID3DXFont* fontL = GetAppInst()->GetFontL();
	wchar_t timeText[64];
	swprintf_s(timeText,L"%d", (int)restSec);
	//swprintf_s(timeText, L"000");
	RECT rcTime = { 600, 50, WIDTH, HEIGHT };
	fontL->DrawText(nullptr,timeText,-1,&rcTime,DT_LEFT | DT_TOP,D3DCOLOR_XRGB(55, 0, 55));
	
	ID3DXFont* font = GetAppInst()->GetFont();
	RECT rc1 = { 330, 400, WIDTH, HEIGHT};
	font->DrawText(nullptr, L"Player 1", -1, &rc1, DT_LEFT | DT_TOP, D3DCOLOR_XRGB(255, 165, 0));
	RECT rc2 = { 520, 400, WIDTH, HEIGHT };
	font->DrawText(nullptr, L"Player 2", -1, &rc2, DT_CENTER | DT_TOP, D3DCOLOR_XRGB(155, 50, 155));
	RECT rc3 = { 330, 800, WIDTH, HEIGHT };
	font->DrawText(nullptr, L"Player 3", -1, &rc3, DT_LEFT | DT_TOP, D3DCOLOR_XRGB(255, 5, 0));
	RECT rc4 = { 520, 800, WIDTH, HEIGHT };
	font->DrawText(nullptr, L"Player 4", -1, &rc4, DT_CENTER | DT_TOP, D3DCOLOR_XRGB(250, 50, 255));

	RECT rcA = { 350, 500, WIDTH, HEIGHT };
	font->DrawText(nullptr, L"各自Aボタンから参加し戦闘を待つ", -1, &rcA, DT_LEFT | DT_TOP, D3DCOLOR_XRGB(240, 0, 100));
	//シーンの描画を終了
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
	if ((pInput->IsPushBtnOne(JOY_CON_0, JOY_BTN_BIT_A))|| (pInput->IsPushBtnOne(JOY_CON_1, JOY_BTN_BIT_A))||(pInput->IsPushBtnOne(JOY_CON_2, JOY_BTN_BIT_A))||(pInput->IsPushBtnOne(JOY_CON_3, JOY_BTN_BIT_A))) {
		GetAppInst()->ChangeScene(GAME_SCENE_TITLE);
		printf("push Enterkey");
		return;
	}
	/*if (pInput->IsPushBtnOne(JOY_CON_0, JOY_BTN_BIT_A)){
		GetAppInst()->ChangeScene(GAME_SCENE_TITLE);
		printf("push Enterkey");
		return;
	}
	if(pInput->IsPushBtnOne(JOY_CON_1, JOY_BTN_BIT_A)) {
		GetAppInst()->ChangeScene(GAME_SCENE_TITLE);
		printf("push Enterkey");
		return;
	}
	if (pInput->IsPushBtnOne(JOY_CON_2, JOY_BTN_BIT_A)) {

		GetAppInst()->ChangeScene(GAME_SCENE_TITLE);
		printf("push Enterkey");
		return;
	}
	if (pInput->IsPushBtnOne(JOY_CON_3, JOY_BTN_BIT_A)) {

		GetAppInst()->ChangeScene(GAME_SCENE_TITLE);
		printf("push Enterkey");
		return;
	}*/

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
	IDirect3DTexture9* pTex = GetAppInst()->GetDxTex(TEX_RESULT);
	//// 背景画像の描画
	D3DSURFACE_DESC desc;
	pTex->GetLevelDesc(0, &desc);
	float texW = (float)desc.Width;   // 1900
	float texH = (float)desc.Height;  // 1200
	// 画面いっぱいにするスケールを計算
	float scaleX = 1280.0f / texW;
	float scaleY = 1024.0f / texH;
	D3DXMATRIX mat;
	D3DXMatrixScaling(&mat, scaleX, scaleY, 1.0f);
	m_pSpr->SetTransform(&mat);
	m_pSpr->Draw(pTex, nullptr, nullptr, nullptr, 0xFFFFFFFF);//888899
	// 行列を元に戻す
	D3DXMATRIX matIdentity;
	D3DXMatrixIdentity(&matIdentity);
	m_pSpr->SetTransform(&matIdentity);
	DrawIcon();

	m_pSpr->End();
	ID3DXFont* fontL = GetAppInst()->GetFontL();
	ID3DXFont* font = GetAppInst()->GetFont();
	ID3DXFont* fontS = GetAppInst()->GetFontS();

	/*RECT rcInfo1 = { -150, 100, WIDTH, HEIGHT };
	font->DrawText(nullptr, L"アイテム取得数: 壊した障害物: ", -1, &rcInfo1, DT_CENTER | DT_TOP, D3DCOLOR_XRGB(100, 50, 0));
	RECT rcInfo2 = { 330, 200, WIDTH, HEIGHT };
	font->DrawText(nullptr, L"TEXT : ", -1, &rcInfo2, DT_LEFT | DT_TOP, D3DCOLOR_XRGB(250, 200, 0));*/
	//RECT rcInfo3 = { -50, 450, WIDTH, HEIGHT };
	//font->DrawText(nullptr, L":", -1, &rcInfo3, DT_CENTER | DT_TOP, D3DCOLOR_XRGB(255, 100, 0));


	// テキスト表示
	RECT rcWIN = { -20, 850, WIDTH, HEIGHT };
	// サイズはL
	fontL->DrawText(nullptr, L"Aボタンでタイトルへ", -1, &rcWIN, DT_CENTER | DT_TOP, D3DCOLOR_XRGB(255, 50, 50));//仮
	// 誰が勝利したか表示する(gamesceneで勝った人)
	//font->DrawText(nullptr, L" PL : 勝利", /*&,*/-1,&rcWIN, DT_CENTER | DT_TOP, D3DCOLOR_XRGB(255, 255, 0));
	//RECT rcSelect = { -30, 0, WIDTH, HEIGHT };
	//font->DrawText(nullptr, L"もう一度戦う", /*&,*/-1,&rcWIN, DT_CENTER | DT_TOP, D3DCOLOR_XRGB(255, 255, 0));
	// 次の画面遷移を提示する (操作はどのPLができるか)
	m_pDev->EndScene();
}

void ResultScene::DrawIcon() {

		ID3DXSprite* m_pSpr = GetAppInst()->GetDxSpr();
		

		RECT rc = { 0,0,96,96 };
		D3DXVECTOR3 center(0, 0, 0);

		IDirect3DTexture9* p1 = GetAppInst()->GetDxTex(TEX_AAAPHTO);
		IDirect3DTexture9* p2 = GetAppInst()->GetDxTex(TEX_BBBPHTO);
		IDirect3DTexture9* p3 = GetAppInst()->GetDxTex(TEX_CCCPHTO);
		IDirect3DTexture9* p4 = GetAppInst()->GetDxTex(TEX_DDDPHTO);
		 
		//if (!t0 || !t1 || !t2 || !t3) return; // どれか未ロード

		int winner = GetAppInst()->GetWinnerIndex();

		const DWORD COL_WIN = 0xFFFFFFFF;
		const DWORD COL_LOSE = D3DCOLOR_ARGB(120, 80, 80, 80);

		D3DXVECTOR3 pos;

		pos = D3DXVECTOR3(200, 100, 0);
		m_pSpr->Draw(p1, &rc, &center, &pos, (winner == 0) ? COL_WIN : COL_LOSE);

		pos = D3DXVECTOR3(200, 300, 0);
		m_pSpr->Draw(p2, &rc, &center, &pos, (winner == 1) ? COL_WIN : COL_LOSE);

		pos = D3DXVECTOR3(200, 500, 0);
		m_pSpr->Draw(p3, &rc, &center, &pos, (winner == 2) ? COL_WIN : COL_LOSE);

		pos = D3DXVECTOR3(200, 700, 0);
		m_pSpr->Draw(p4, &rc, &center, &pos, (winner == 3) ? COL_WIN : COL_LOSE);
}

void ResultScene::DrawData() {

	ID3DXFont* fontL = GetAppInst()->GetFontL();
	ID3DXFont* font = GetAppInst()->GetFont();
	ID3DXFont* fontS = GetAppInst()->GetFontS();

	RECT rcInfo1 = { -150, 100, WIDTH, HEIGHT };
	font->DrawText(nullptr, L"アイテム取得数: 壊した障害物: ", -1, &rcInfo1, DT_CENTER | DT_TOP, D3DCOLOR_XRGB(100, 50, 0));
	RECT rcInfo2 = { 330, 200, WIDTH, HEIGHT };
	font->DrawText(nullptr, L"TEXT : ", -1, &rcInfo2, DT_LEFT | DT_TOP, D3DCOLOR_XRGB(250, 200, 0));
}
