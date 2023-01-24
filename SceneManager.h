#pragma once

class SceneManager final
{
private:
	//コンストラクタ
	SceneManager();
	//デストラクタ
	~SceneManager();

public:
	//コピーコンストラクタを無効
	SceneManager(const SceneManager& obj) = delete;
	//代入演算子を無効
	SceneManager& operator=(const SceneManager& obj) = delete;

	static SceneManager* GetInstance();//静的メンバー関数

	void SceneChange(int& sceneNo);
};