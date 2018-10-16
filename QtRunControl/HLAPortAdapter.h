
/*
* RunControlAdapter层
* @date : 2018/10/13
* @author : jihang
*/

#include <iostream>

#include "HLAPortInterface.h"

#define READY_TO_RUN "ReadyToRun"

using namespace std;

//下一版本最好放到config.h里
const string TYPE_PAUSE = "PAUSE";
const string TYPE_CONTINUE = "CONTINUE";
const string TYPE_END = "END";

class HLAPortAdapter : public CHLAPortInterface {

public:
	//成员信息
	string fedFile;
	string federationName;
	string federateName;
	long federateId;

public:
	//1.对象类定义

	//仿真控制，目前共三组，全部发布
	ObjectNames objectNamesPause;
	ObjectHandles *objectHandlesPause;
	RTI::ObjectHandle handlePause;

	ObjectNames objectNamesContinue;
	ObjectHandles *objectHandlesContinue;
	RTI::ObjectHandle handleContinue;

	ObjectNames objectNamesEnd;
	ObjectHandles *objectHandlesEnd;
	RTI::ObjectHandle handleEnd;

	//订阅用户，是否能获得全局所有？
	ObjectNames objectNamesB;
	ObjectHandles *objectHandlesB;

public:
	//2.构造函数
	HLAPortAdapter() {

		//成员属性
		fedFile = "testfom.fed";
		federationName = "ExampleFederation";
		federateName = "runControl";
		isPause = false;
		isEnd = false;

		//仿真控制
		objectNamesPause.className = "ObjectRoot.PAUSE";
		objectNamesPause.attributeNumber = 1;
		objectNamesPause.attributeList.push_back("pause");

		objectNamesContinue.className = "ObjectRoot.CONTINUE";
		objectNamesContinue.attributeNumber = 1;
		objectNamesContinue.attributeList.push_back("continue");

		objectNamesEnd.className = "ObjectRoot.End";
		objectNamesEnd.attributeNumber = 1;
		objectNamesEnd.attributeList.push_back("end");

		//订阅用户
		objectNamesB.className = "ObjectRoot.B";
		objectNamesB.attributeNumber = 3;
		objectNamesB.attributeList.push_back("ba");
		objectNamesB.attributeList.push_back("bb");
		objectNamesB.attributeList.push_back("bc");
	};

	virtual ~HLAPortAdapter() {};

public:
	void initial() {
		//仿真控制
		objectHandlesPause = initOneHandle(objectNamesPause);
		objectHandlesContinue = initOneHandle(objectNamesContinue);
		objectHandlesEnd = initOneHandle(objectNamesEnd);

		//订阅用户
		objectHandlesB = initOneHandle(objectNamesB);
	}

	void pubAndSub() {
		//仿真控制
		publishOne(objectHandlesPause);
		publishOne(objectHandlesContinue);
		publishOne(objectHandlesEnd);

		//订阅用户
		subscribeOne(objectHandlesB);
	}

	void rigister() {
		//注册控制类
		handlePause = registerObject(objectNamesPause.className);
		handleContinue = registerObject(objectNamesContinue.className);
		handleEnd = registerObject(objectNamesEnd.className);
	}

	void processData(RTI::ObjectHandle theObject,
		const RTI::AttributeHandleValuePairSet& theAttributes, const char* theTag)
		throw(RTI::ObjectNotKnown, RTI::AttributeNotKnown, RTI::FederateOwnsAttributes,
			RTI::FederateInternalError) {

		//预设的，收到仿真控制信息
		//先由对象句柄获取对象类句柄
		//int classHandle = getObjectClass(theObject);
		//根据对象类句柄判断
		//if (classHandle == objectHandlesPause->classHandle) {
		//	cout << "i should pause" << endl;
		//	isPause = true;
		//}
		//if (classHandle == objectHandlesContinue->classHandle) {
		//	cout << "i should continue" << endl;
		//	isPause = false;
		//}
		//if (classHandle == objectHandlesEnd->classHandle) {
		//	cout << "i should end" << endl;
		//	isEnd = true;
		//}
		//自己的，用户添加，收到数据信息
	}

	void simulate() {
		while (true) {
			if (isEnd) {
				del();
				resignFederation();
				//由运行管理器销毁
				destroyFederation(federationName);
				break;
			}
			advanceTime(1.0);
		}
	}

	void send(string type) {
		//发送控制信息
		RTI::AttributeHandleValuePairSet *attributes = RTI::AttributeSetFactory::create(1);
		char controlInfo[16];
		if (type == TYPE_PAUSE) {
			sprintf(controlInfo, "you should pause");
			attributes->add(objectHandlesPause->handleList[0], controlInfo, (RTI::ULong)strlen(controlInfo) + 1);
			sendObject(handlePause, attributes);
		}
		else if (type == TYPE_CONTINUE) {
			sprintf(controlInfo, "you should continue");
			attributes->add(objectHandlesContinue->handleList[0], controlInfo, (RTI::ULong)strlen(controlInfo) + 1);
			sendObject(handleContinue, attributes);
		}
		else if (type == TYPE_END) {
			sprintf(controlInfo, "you should end");
			attributes->add(objectHandlesEnd->handleList[0], controlInfo, (RTI::ULong)strlen(controlInfo) + 1);
			sendObject(handleEnd, attributes);
		}
	}

	void del() {
		deleteOne(handlePause);
		deleteOne(handleContinue);
		deleteOne(handleEnd);
	}
};