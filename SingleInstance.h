#pragma once
template <typename T>
class CSingleInstance
{
protected:
	CSingleInstance() {};
	virtual ~CSingleInstance() {};
public:

	static T * GetInstance()
	{
		static T * _instance = new T();
		return _instance;
	}
};

