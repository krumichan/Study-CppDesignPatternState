#pragma once

#include <string>
using namespace std;

/**
 * キャラクターの基底クラス
 */
class Entity
{
protected:
	/**
	 * コンストラクタ
	 */
	Entity();

public:
	/**
	 * デストラクタ
	 */
	virtual ~Entity();

public:
	/**
	 * このインスタンスを実行する関数
	 */
	virtual void Update();

protected:
	/**
	 * クライアントから入力を受け取る関数
	 * @return 入力値
	 */
	virtual void UpdateHandle() = 0;

	/**
	 * 入力値に基づき、次のステートを決定する関数
	 * @return 次のステート
	 */
	virtual string UpdateState() = 0;

protected:
	/**
	 * 現在のステート
	 */
	string state;

public:
	/**
	 * X位置
	 */
	int x;

	/**
	 * Y位置
	 */
	int y;
};
