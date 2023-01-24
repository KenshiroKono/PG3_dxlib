#include "SceneManager.h"
SceneManager::SceneManager() {
}
SceneManager::~SceneManager() {
}

SceneManager* SceneManager::GetInstance() {
	static SceneManager instance;

	return &instance;
}

void SceneManager::SceneChange(int& sceneNo) {
	if (sceneNo < 3) {
		sceneNo += 1;
	}
	else {
		sceneNo = 0;
	}
}