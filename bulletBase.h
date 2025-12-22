#pragma once

//弾
struct Bullets {

	Vector2 pos;     //座標    
	int radius;      //半径
	int maxBulets;   //最大発射数
	int bulletSpeed; //射速
	int bulletDamage;//ダメージ
	int bulletAngle; //向き
	int bulletFacing;

	bool isAlive;    //生存
	
};

class BulletBase {

private:
	Bullets m_bullet; //構造体定義
	Field* m_pfield;
	Vector2 m_startPos;//弾のstartPos
	
public:
	BulletBase()
		: m_bullet{ {0.0f, 0.0f},       //pos
					 0, 0, 0, 0, 0, 0, false}//radius、maxBulets、bulletSpeed、bulletDamage、angle、alive 
	{};
	~BulletBase() = default; 
	
	void Init(Vector2 cpos,int r,int max,int bsp,int bdam,int angle,bool alive, int facing,Field* f);
	//void Updata();

	void Draw(int playerNo);//弾描画
	void Move();//発射たし弾の移動
	void BulletArea();//生存エリア
	void BulletAreaRange(E_TANK_RING ring);//射程距離
	void BulletJudge();//当たったobjをチェック
	bool GetAlive() { return m_bullet.isAlive; }
	void SetAlive(bool isAlive) {  m_bullet.isAlive =isAlive; }
	Vector2 GetPos() const { return m_bullet.pos; }
	float  GetMaxRange(E_TANK_RING ring);//アイテムより射程距離が変更
};