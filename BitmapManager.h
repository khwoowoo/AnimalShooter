#pragma once
class BitmapManager :
	public CSingleInstance<BitmapManager>
{
	map<string, TextureData*> m_TextureMap;
public:
	BitmapManager();
	virtual ~BitmapManager();
public:
	void RemoveAll();
	void LoadBitmapFile(LPCSTR	filename);
	TextureData * GetBitmapFile(LPCSTR filename);

};

