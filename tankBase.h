#pragma once


#define MAX_BULLET (3)

//enum E_TEXTURE;

struct Vector2
{
	float  x;
	float  y;

};
enum E_TANK_RING
{
	E_RING_VSHORT,  //4
	E_RING_SHORT,	//8
	E_RING_VMID,	//12
	E_RING_MID,		//16
	E_RING_LONG,	//20
	E_RING_VLONG    //24
	             
};


//タンク(戦車)
struct TankStatus
{
	Vector2 pos;   //座標
	Vector2 vel;   //速度成分
	int moveSpeed; //移動速度	
	int hp;		   //体力値
	float angle;   // 90 180 270 360
	int alpha;     //255不透明　0完全透明
	bool isDead;   //生存

	//3期追加
	E_TANK_RING ring;
	int maxBullet;
	//Damage Performance
	int hitShakeTimer; // 揺れ残りフレーム
	int hitShakeTotal; // 開始時のフレーム（減衰用）
 
};

class TankBase {


protected:
	E_TEXTURE   m_texName;// 表示するテクスチャ.
	TankStatus  m_tstatus;//搭載物の情報

	TankBase()
		:m_texName(TEX_INVALID) {
		m_tstatus.pos = { 0.0f, 0.0f };
		m_tstatus.vel = { 0.0f, 0.0f };
		m_tstatus.moveSpeed = 0;
		m_tstatus.hp = 0;
		m_tstatus.angle = 0;
		m_tstatus.alpha = 255;
		m_tstatus.isDead = false;
		m_tstatus.ring = E_RING_VSHORT;
		m_tstatus.maxBullet = 1;
		// _tprintf(_T("call PlayerBase constractor\n"));
		//３期追加
	
	}
public:
	virtual ~TankBase() = default;
	virtual void Init(float tx, float ty, float tvx, float tvy, int tspeed, int thp, bool isDead);//初期化
	virtual void Move() = 0;
	virtual void Fire() = 0;
	void Updata();//毎フレーム呼び出し
	virtual void Draw(E_TEXTURE texName);//描画タンク/パイロット本体

	Vector2 GetPos() { return m_tstatus.pos; }
	float  GetAngle() { return m_tstatus.angle; }

	void IsLive();



	bool IsDead() const { return  m_tstatus.isDead; }
	void Kill() { m_tstatus.isDead = true; }
	//int GetHp
	void Damage(int d)
	{
		m_tstatus.hp -= d;
		StartHitShake();
		if (m_tstatus.hp <= 0)
			m_tstatus.isDead = true;
	}
	//3期
	//アイテム取得するための関数

	void AddMoveSpeed(float speed);
	void AddHp(int hp);
	void AddRing();
	void AddMaxBullet();

	//DamagePerformance
	
	void StartHitShake();// ダメージ演出：揺れ開始
	void UpdateHitShake();// 毎フレーム更新
	int GetHitShakeOffsetY();// 描画で使う揺れオフセット
};