#pragma once
#include <memory>

class BaseScene;
using Unique_Base = std::unique_ptr<BaseScene>;
class BaseScene
{
public:
	BaseScene() {};
	virtual ~BaseScene() {};
	virtual Unique_Base UpDate(Unique_Base own) = 0;
protected:
	virtual void Init(void) = 0;
};

