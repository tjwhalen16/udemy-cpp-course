#pragma once
class SdlGui
{
public:
	SdlGui();
	~SdlGui();
	void Run();
private:
	//Starts up SDL and creates window
	bool init();
	//Loads media
	bool loadMedia();
	//Frees media and shuts down SDL
	void close();
};

