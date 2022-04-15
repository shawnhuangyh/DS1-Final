//
// Created by Shawn Huang on 2022/4/12.
//

#include "PCRTest.h"

PCRTest::PCRTest() {
    mixed_count = 0;
    single_count = 0;
}

void PCRTest::ImportQueueData() {
    int n, m;
    ifstream infile;
    infile.open("Test Cases/Queue.txt");
    infile >> n >> m;
    for (int i = 0; i < n; ++i) {
        string x;
        infile >> x;
        EnQueue(x, 0);
    }
    for (int i = 0; i < m; ++i) {
        string x;
        infile >> x;
        EnQueue(x, 1);
    }
    infile.close();
}

void PCRTest::ImportCheckedData() {
    int n, m;
    ifstream infile;
    infile.open("Test Cases/Checked.txt");
    infile >> n >> m;
    for (int i = 0; i < n; ++i) {
        string temp;
        DeQueue(temp, 0);
    }
    for (int i = 0; i < m; ++i) {
        string temp;
        DeQueue(temp, 1);
    }
    infile.close();
}

void PCRTest::EnQueue(const string &elem, int select) {
    if (select == 0) {
        Person temp(elem);
        mixed.EnQueue(temp);
    } else {
        Person temp(elem);
        single.EnQueue(temp);
    }
}

void PCRTest::EnQueue() {
    string PersonID;
    char type;
    cout << "===========排队===========" << endl;
    cout << "请输入检测人的人员编号：" << endl;
    cin >> PersonID;
    cout << endl << "请选择检测类型" << endl << "0：10人混合检测 ; 1：单人单管检测" << endl << "请输入(0/1)：";
    cin >> type;
    if (type == '0') {
        EnQueue(PersonID, 0);
        cout << endl << "排队成功！" << endl << endl;
    } else if (type == '1') {
        EnQueue(PersonID, 1);
        cout << endl << "排队成功！" << endl << endl;
    } else {
        cout << endl << "输入错误，请重新输入！" << endl << endl;
    }
}

void PCRTest::DeQueue(string &elem, int select) {
    if (select == 0) {
        Person temp;
        mixed.DeQueue(temp);
        elem = temp.getPersonID();
        string sample = GetSampleNo(0);
        temp.setSampleID(sample);
        mixed_count++;
    } else {
        Person temp;
        single.DeQueue(temp);
        elem = temp.getPersonID();
        string sample = GetSampleNo(1);
        temp.setSampleID(sample);
        single_count++;
    }
}

void PCRTest::DeQueue() {
    char type;
    string temp;
    cout << "===========采样===========" << endl;
    cout << endl << "请选择检测类型" << endl << "0：10人混合检测 ; 1：单人单管检测" << endl << "请输入(0/1)：";
    cin >> type;
    if (type == '0') {
        DeQueue(temp, 0);
        cout << endl << temp << "混合检测完成！" << endl << endl;
    } else if (type == '1') {
        DeQueue(temp, 1);
        cout << endl << temp << "单管检测完成！" << endl << endl;
    } else {
        cout << endl << "输入错误，请重新输入！" << endl << endl;
    }
}

void PCRTest::ShowQueue() {
    cout << "==========排队情况==========" << endl;
    cout << "10人混合检测：" << endl;
    mixed.ShowQueue();
    cout << "单人单管检测：" << endl;
    single.ShowQueue();
    cout << endl;
}

void PCRTest::PerformTest() {
    string SampleNo;
    cout << "==========检测登记管==========" << endl;
    cin >> SampleNo;
    // TODO Not finished yet
}

string PCRTest::GetSampleNo(int select) {
    string output;
    int num = 4;
    int sampleNo;
    if (select == 0) {
        sampleNo = mixed_count / 10;
    } else {
        sampleNo = single_count;
    }
    output = to_string(select) + string(num - to_string(sampleNo).length(), '0') + to_string(sampleNo);
    return output;
}
