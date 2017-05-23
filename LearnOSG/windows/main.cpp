#include "../common/common.h"
#include <osgViewer/Viewer>
#include <osgDB/ReadFile>
#include <osgGA/GUIEventHandler>

#ifdef _DEBUG
#pragma comment(lib, "../Debug/common.lib")
#else
#pragma comment(lib, "../Release/common.lib")
#endif

class ChangeWindow : public osgGA::GUIEventHandler
{
public:
	ChangeWindow() {first = false;}
	bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa)
	{
		if (!first)
		{
			osgViewer::Viewer * viewer = dynamic_cast<osgViewer::Viewer*> (&aa);
			osgViewer::ViewerBase::Windows ws;
			first = true;
			viewer->getWindows(ws);
			if (!ws.empty())
			{
				osgViewer::Viewer::Windows::iterator it = ws.begin();
				for (; it!=ws.end(); it++)
				{
					(*it)->setWindowRectangle(50,50,800,600);
					(*it)->setWindowDecoration(true);
				}
			}
		}
		return false;
	}

private:
	bool first;
};

int main()
{
	osg::ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer;
	viewer->setSceneData(osgDB::readNodeFile("glider.osg"));
	viewer->addEventHandler(new ChangeWindow());
	viewer->run();

	std::vector<int> vec;
	std::vector<int>::iterator itt;

	return 0;
}