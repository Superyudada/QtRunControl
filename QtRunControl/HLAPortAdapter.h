
/*
* RunControlAdapter��
* @date : 2018/10/13
* @author : jihang
*/

#include <iostream>

#include "HLAPortInterface.h"

#define READY_TO_RUN "ReadyToRun"

using namespace std;

//��һ�汾��÷ŵ�config.h��
const string TYPE_PAUSE = "PAUSE";
const string TYPE_CONTINUE = "CONTINUE";
const string TYPE_END = "END";

class HLAPortAdapter : public CHLAPortInterface {

public:
	//��Ա��Ϣ
	string fedFile;
	string federationName;
	string federateName;
	long federateId;

public:
	//1.�����ඨ��

	//������ƣ�Ŀǰ�����飬ȫ������
	ObjectNames objectNamesPause;
	ObjectHandles *objectHandlesPause;
	RTI::ObjectHandle handlePause;

	ObjectNames objectNamesContinue;
	ObjectHandles *objectHandlesContinue;
	RTI::ObjectHandle handleContinue;

	ObjectNames objectNamesEnd;
	ObjectHandles *objectHandlesEnd;
	RTI::ObjectHandle handleEnd;

	//�����û����Ƿ��ܻ��ȫ�����У�
	ObjectNames objectNamesB;
	ObjectHandles *objectHandlesB;

public:
	//2.���캯��
	HLAPortAdapter() {

		//��Ա����
		fedFile = "testfom.fed";
		federationName = "ExampleFederation";
		federateName = "runControl";
		isPause = false;
		isEnd = false;

		//�������
		objectNamesPause.className = "ObjectRoot.PAUSE";
		objectNamesPause.attributeNumber = 1;
		objectNamesPause.attributeList.push_back("pause");

		objectNamesContinue.className = "ObjectRoot.CONTINUE";
		objectNamesContinue.attributeNumber = 1;
		objectNamesContinue.attributeList.push_back("continue");

		objectNamesEnd.className = "ObjectRoot.End";
		objectNamesEnd.attributeNumber = 1;
		objectNamesEnd.attributeList.push_back("end");

		//�����û�
		objectNamesB.className = "ObjectRoot.B";
		objectNamesB.attributeNumber = 3;
		objectNamesB.attributeList.push_back("ba");
		objectNamesB.attributeList.push_back("bb");
		objectNamesB.attributeList.push_back("bc");
	};

	virtual ~HLAPortAdapter() {};

public:
	void initial() {
		//�������
		objectHandlesPause = initOneHandle(objectNamesPause);
		objectHandlesContinue = initOneHandle(objectNamesContinue);
		objectHandlesEnd = initOneHandle(objectNamesEnd);

		//�����û�
		objectHandlesB = initOneHandle(objectNamesB);
	}

	void pubAndSub() {
		//�������
		publishOne(objectHandlesPause);
		publishOne(objectHandlesContinue);
		publishOne(objectHandlesEnd);

		//�����û�
		subscribeOne(objectHandlesB);
	}

	void rigister() {
		//ע�������
		handlePause = registerObject(objectNamesPause.className);
		handleContinue = registerObject(objectNamesContinue.className);
		handleEnd = registerObject(objectNamesEnd.className);
	}

	void processData(RTI::ObjectHandle theObject,
		const RTI::AttributeHandleValuePairSet& theAttributes, const char* theTag)
		throw(RTI::ObjectNotKnown, RTI::AttributeNotKnown, RTI::FederateOwnsAttributes,
			RTI::FederateInternalError) {

		//Ԥ��ģ��յ����������Ϣ
		//���ɶ�������ȡ��������
		//int classHandle = getObjectClass(theObject);
		//���ݶ��������ж�
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
		//�Լ��ģ��û���ӣ��յ�������Ϣ
	}

	void simulate() {
		while (true) {
			if (isEnd) {
				del();
				resignFederation();
				//�����й���������
				destroyFederation(federationName);
				break;
			}
			advanceTime(1.0);
		}
	}

	void send(string type) {
		//���Ϳ�����Ϣ
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