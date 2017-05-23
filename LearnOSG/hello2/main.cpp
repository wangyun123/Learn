#include <osgViewer/Viewer>
#include <osgDB/ReadFile>
#include <osgViewer/ViewerEventHandlers>
#include <osg/ShapeDrawable>
#include <osgUtil/LineSegmentIntersector>
#include <osgUtil/IntersectionVisitor>
#include <iostream>
#include <windows.h>

#ifdef _DEBUG
#pragma comment(lib, "osgd.lib")
#pragma comment(lib, "osgDBd.lib")
#pragma comment(lib, "osgViewerd.lib")
#pragma comment(lib, "OpenThreadsd.lib")
#pragma comment(lib, "osgGAd.lib")
#pragma comment(lib, "osgUtild.lib")
#else
#pragma comment(lib, "osg.lib")
#pragma comment(lib, "osgDB.lib")
#pragma comment(lib, "osgViewer.lib")
#pragma comment(lib, "OpenThreads.lib")
#pragma comment(lib, "osgGA.lib")
#pragma comment(lib, "osgUtil.lib")
#endif

int ticket=10;

class MyThreads : public OpenThreads::Thread
{
public:
	MyThreads(std::string name) {this->name=name;}

	void run()
	{
		while(--ticket>0)
		{
			std::cout << name << ":" << ticket << std::endl;
		}
	}

private:
	std::string name;
};

osg::ref_ptr<osg::Geode> createBox()
{
	osg::ref_ptr<osg::Geode> gode = new osg::Geode;
	gode->addDrawable(new osg::ShapeDrawable(new osg::Box(osg::Vec3(0.0,0.0,0.0),10.0,10.0,10.0)));
	//gode->addDrawable(new osg::shape)
	return gode;
}

int main()
{
#if 0
	osg::ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer;

	osg::Timer* timer = new osg::Timer;
	std::cout << timer->getSecondsPerTick() << std::endl;

	// intersection 
	osg::ref_ptr<osgUtil::LineSegmentIntersector> line = 
		new osgUtil::LineSegmentIntersector(osg::Vec3(0.0,0.0,15.0), osg::Vec3(0.0,0.0,-15.0));
	osg::ref_ptr<osgUtil::IntersectionVisitor> nv = 
		new osgUtil::IntersectionVisitor(line);

	osg::ref_ptr<osg::Group> group = new osg::Group;
	group->addChild(createBox());
	group->accept(*nv);

	osgUtil::LineSegmentIntersector::Intersections inter;
	if (line->containsIntersections())
	{
		inter = line->getIntersections();
		for (osgUtil::LineSegmentIntersector::Intersections::iterator it=inter.begin(); it!=inter.end(); ++it)
		{
			std::cout<<it->getLocalIntersectPoint().x()<<","
				<<it->getLocalIntersectPoint().y()<<","
				<<it->getLocalIntersectPoint().z()<<std::endl;
		}
	}
	viewer->setSceneData(group);
	viewer->addEventHandler(new osgViewer::HelpHandler);
	viewer->addEventHandler(new osgViewer::StatsHandler);
	viewer->addEventHandler(new osgViewer::WindowSizeHandler);
	return viewer->run();
#else
	MyThreads t1("A");
	MyThreads t2("B");
	t1.start();
	t2.start();
	Sleep(30000);
	return 1;
#endif
	
}