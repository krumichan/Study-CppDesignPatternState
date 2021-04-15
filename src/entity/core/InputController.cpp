#include "InputController.h"

/**
 * メンバを初期化する関数
 */
void InputController::Initialization()
{
	//　マップの追加
	// 0x41 : A KEY
	inpMapper[0x41] = "LEFT";
	// 0x53 : S KEY
	inpMapper[0x53] = "BACKWARD";
	// 0x44 : D KEY
	inpMapper[0x44] = "RIGHT";
	// 0x57 : W KEY
	inpMapper[0x57] = "FORWARD";

	//　作成しているツールのバージョンでは
	//　for (const aut& [key, value] : inpMapper)
	//　が使えない。


	//　マップをToggleリストに渡す
	map<int, string>::iterator itr;

	//　マップ要素を繰り返す
	for (itr = inpMapper.begin(); itr != inpMapper.end(); itr++)
	{
		//　Toggle生成　（入力値、入力値に対する動作文字列）
		Toggle toggle(itr->first, itr->second);

		//　リストに挿入
		toggleList.push_back(toggle);
	}
}

/**
 * 機器から、入力を受け取る。
 * @return 入力値
 */
string InputController::GetInput()
{
	list<Toggle>::iterator itr;

	//　Toggleリストの中身を確認
	for (itr = toggleList.begin(); itr != toggleList.end(); itr++)
	{
		if (*itr)
		{
			return itr->Get();
		}
	}

	return "";
}

/**
 * 自分のインスタンスを生成し、呼び出す。
 * @return 自分のインスタンス
 */
InputController& InputController::Call()
{
	/* インスタンスを生成 */
	/* 最初、１回しか生成しない */
	static InputController _instance;
	return _instance;
}

/**
 * コンストラクタ
 */
InputController::InputController()
{
	Initialization();
}

/**
 * デストラクタ
 */
InputController::~InputController()
{

}
