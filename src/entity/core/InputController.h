#pragma once

#include <string>
#include <map>
#include <list>
#include <Windows.h>

using namespace std;

/**
 * 入力を担当するクラス
 */
class InputController {

	/**
	 * 押下したのを正確に、1回取得する為のクラス
	 */
	class Toggle
	{
	public:
		/**
		 * コンストラクタ
		 * @param _key 入力値
		 * @param _input 入力値に該当する命令文字列
		 */
		Toggle(int _key, string _input)
			: m_key(_key)
			, m_inp(_input)
			, m_active(false)
		{
		}

		/**
		 * 命令文字列を取得
		 * @return 命令文字列
		 */
		string Get()
		{
			return m_inp;
		}

		/**
		 * 演算子を定義
		 */
		operator bool()
		{
			//　押下された場合。
			if (GetAsyncKeyState(m_key))
			{
				//　活動フラグを活性化
				if (!m_active)
				{
					return (m_active = true);
				}

			//　押下されなかった場合。
			} else
			{
				//　活動フラグを回収
				m_active = false;
			}

			return false;
		}
	private:
		/**
		 * 入力値
		 */
		int m_key;

		/**
		 * 入力値に該当する命令文字列
		 */
		string m_inp;

		/**
		 * 押下され、活性化されたのか
		 */
		bool m_active;
	};

public:
	/**
	 * メンバを初期化する関数
	 */
	void Initialization();

	/**
	 * 機器から、入力を受け取る。
	 * @return 入力値
	 */
	string GetInput();

public:
	/**
	 * 自分のインスタンスを生成し、呼び出す。
	 * @return 自分のインスタンス
	 */
	static InputController& Call();

private:
	/* can't copy */
	/* このクラスの唯一性を維持する為、複写及び代入を防止する。 */
	InputController(InputController const&);
	InputController& operator=(InputController const&);

//		// C++ 11
//	public:
//		SingleTon(SingleTon const&) = delete;
//		SingleTon& operator=(SingleTon const&) = delete;

private:
	/**
	 * コンストラクタ
	 */
	InputController();

public:
	/**
	 * デストラクタ
	 */
	virtual ~InputController();

private:
	/**
	 * 入力マッパー
	 */
	map<int, string> inpMapper;

	/**
	 * Toggle List
	 */
	list<Toggle> toggleList;
};
