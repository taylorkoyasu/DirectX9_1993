//#include "stdafx.h"
//#include "myApp.h"
//#include "myBmpFont.h"
//#include "myTimer.h"
//#include "Select.h"

//void SelectScene::SelectInit()
//{
//	/*m_gameScene = GAME_SCENE_SELECT;*/
//}
//void SelectScene::UpdateSelect()
//{
//	MyInput* pInput = GetInputInst();
//	// デバッグ用 : Enterキーでゲームシーンへ
//	if (pInput->IsPushKeyOne(DIK_RETURN)) {
//		/*m_gameScene = GAME_SCENE_STORY;*/
//		GetAppInst()->ChangeScene(GAME_SCENE_STORY);
//		printf("Enter");
//	}
//}
//void SelectScene::DrawSelect()
//{
//	//Select messsage
//	//背景
//	IDirect3DDevice9* m_pDev = GetAppInst()->GetDxDev();// Direct3D デバイスの確認
//	assert(m_pDev != NULL && "Direct3D デバイスが初期化されていません");
//	ID3DXSprite* m_pSpr = GetAppInst()->GetDxSpr();// スプライトオブジェクトの確認
//	assert(m_pSpr != NULL && "ID3DXSprite オブジェクトが初期化されていません");
//
//	// 背景色を決める。RGB=(0,0,255)とする.-
//	D3DCOLOR rgb = D3DCOLOR_XRGB(0, 0, 0);
//	// 画面全体を消去.
//	m_pDev->Clear(0, NULL, D3DCLEAR_TARGET, rgb, 1.0f, 0);
//	// 描画を開始（シーン描画の開始）.
//	m_pDev->BeginScene();
//	m_pSpr->Begin(D3DXSPRITE_ALPHABLEND);
//	D3DXMATRIX identity;
//	D3DXMatrixIdentity(&identity);
//	m_pSpr->SetTransform(&identity);
//	// 動画を取得してループ再生・カーソルが動いたら初期化
//
//	//シーンの描画を終了.
//	m_pSpr->End();
//	m_pDev->EndScene();
//}
