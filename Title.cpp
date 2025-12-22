#include "stdafx.h"
#include "myApp.h"
#include "myBmpFont.h"
#include "myTimer.h"
#include "Title.h"

// Title
void TitleScene::TitleInit() {
	m_logo.logoY = -200.0f;
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

	m_pSpr->Draw(m_pLogo, nullptr, nullptr, nullptr, 0xFFFFFFFF);
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
	// シーンの描画を終了.
	m_pDev->EndScene();
}