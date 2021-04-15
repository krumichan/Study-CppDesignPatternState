#include "Player.h"
#include "../core/InputController.h"

/**
 * 移動中なのか。
 */
bool Player::EventCheck_Walk()
{
	string _input = InputController::Call().GetInput();

	//　移動キーが押されているか。
	//　もし、押されていたら、移動すると判断。
	if (_input.compare("LEFT") == 0 ||
		_input.compare("RIGHT") == 0 ||
		_input.compare("FORWARD") == 0 ||
		_input.compare("BACKWARD") == 0)
	{
		return true;
	}

	return false;
}

/**
 * 移動が終わったのか
 */
bool Player::EventCheck_WalkEnd()
{
	string _input = InputController::Call().GetInput();

	//　現在のステートがWALKではなければ、無視
	if (this->state.compare("WALK") != 0)
	{
		return false;
	}

	//　移動キーが押されていないか。
	// 移動キーが押されていなければ、移動が終わったと判断
	if (_input.compare("LEFT") != 0 &&
		_input.compare("RIGHT") != 0 &&
		_input.compare("FORWARD") != 0 &&
		_input.compare("BACKWARD") != 0)
	{
		return true;
	}

	return false;
}

/**
 * 待機状態
 * @return 次のステート
 */
string Player::StateIDLE()
{
	//　移動を開始するか
	if (this->EventCheck_Walk())
	{
		return "WALK";
	}

	//　[無視]
	if (this->EventCheck_WalkEnd())
	{
		//　待機状態では、発生しないので、
		//　気にしない。
	}

	return "IDLE";
}

/**
 * 歩いている状態
 * @return 次のステート
 */
string Player::StateWALKING()
{
	//　移動が終わったのか。
	if (this->EventCheck_WalkEnd())
	{
		return "IDLE";
	}

	//　既に移動中なので、何もしない。
	// TODO: もし、走る状態ができたら、必要かも。
	if (this->EventCheck_Walk())
	{

	}

	return "WALK";
}

/**
 * 移動ハンドリング
 */
void Player::MoveHandling()
{
	string _input = InputController::Call().GetInput();

	if (_input.compare("LEFT") == 0) {
		this->x -= 1;
	}

	if (_input.compare("RIGHT") == 0) {
		this->x += 1;
	}

	if (_input.compare("FORWARD") == 0) {
		this->y += 1;
	}

	if (_input.compare("BACKWARD") == 0) {
		this->y -= 1;
	}
}

/**
 * クライアントから入力を受け取る関数
 * @return 入力値
 */
void Player::UpdateHandle()
{
	if (this->state.compare("IDLE"))
	{
		MoveHandling(); //	-- 移動動作を実行
		// JumpHandling()	-- ジャンプ動作を実行
		// AttackHandling()	-- 攻撃動作を実行
	}
	else if (this->state.compare("WALK"))
	{
		MoveHandling(); //	-- 移動動作を実行
		// JumpHandling() 	-- ジャンプ動作を実行
		// 移動中には攻撃はできないと仮定し、JumpHandling()は呼び出さない。
	}
}

/**
 * 入力値に基づき、次のステートを決定する関数
 * @return 次のステート
 */
string Player::UpdateState()
{
	//　待機ステートの動作を実行する
	if (this->state.compare("IDLE") == 0)	return StateIDLE();

	//　歩くステートの動作を実行する
	if (this->state.compare("WALK") == 0)	return StateWALKING();

	//　異常なステートの場合。
	return "error";
}
