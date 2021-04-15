#include "../_template/state_machine/Entity.h"

/**
 * プレイヤークラス
 */
class Player : public Entity
{

////////////////////////////////
/// EVENT CHECK
////////////////////////////////
private:
	/**
	 * 移動中なのか。
	 */
	bool EventCheck_Walk();

	/**
	 * 移動が終わったのか
	 */
	bool EventCheck_WalkEnd();



////////////////////////////////
/// STATE
////////////////////////////////
private:
	/**
	 * 待機状態
	 * @return 次のステート
	 */
	string StateIDLE();

	/**
	 * 歩いている状態
	 * @return 次のステート
	 */
	string StateWALKING();


////////////////////////////////
/// Handling
////////////////////////////////
private:
	/**
	 * 移動ハンドリング
	 */
	void MoveHandling();


////////////////////////////////
/// UPDATE
////////////////////////////////
protected:
	/**
	 * クライアントから入力を受け取る関数
	 * @return 入力値
	 */
	void UpdateHandle() override;

	/**
	 * 入力値に基づき、次のステートを決定する関数
	 * @return 次のステート
	 */
	string UpdateState() override;
};
