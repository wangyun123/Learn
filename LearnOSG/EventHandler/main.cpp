#include "../common/common.h"
#include <Windows.h>
#include <iostream>
#include <string>
#include <OpenThreads/Thread>
#include <osgViewer/Viewer>
#include <osgDB/ReadFile>
#include <osgGA/EventHandler>

#ifdef _DEBUG
#pragma comment(lib, "../Debug/common.lib")
#else
#pragma comment(lib, "../Release/common.lib")
#endif

class TestInput : public osgGA::GUIEventHandler
{
public:
	bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa)
	{
		switch(ea.getEventType())
		{
		case osgGA::GUIEventAdapter::KEYDOWN:
			std::cout << ea.getKey() << std::endl;
			break;

		}
		return true;
	}

};
int main()
{
	osg::ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer;
	viewer->setSceneData(osgDB::readNodeFile("glider.osg"));
	osg::ref_ptr<TestInput> input = new TestInput;
	viewer->addEventHandler(input);
	viewer->run();

	return 0;
}