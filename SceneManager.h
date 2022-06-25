#pragma once
class SceneManager :
	public CSingleInstance<SceneManager>
{
	bool CloseNowScene = false;
	IScene * nowScene = nullptr;
	IScene * nextScene = nullptr;
	map<string, IScene*> m_SceneMap;
public:
	SceneManager();
	virtual ~SceneManager();
public:
	void AddScene(LPCSTR sceneName, IScene * scene);
	void ChangeScene(LPCSTR sceneName, bool _CloseNowScene);
	void CheckChangeScene();
	void RemoveAll();

	IScene * GetScene(LPCSTR sceneName);
	IScene * GetNowScene();
};

