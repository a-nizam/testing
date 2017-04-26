#include "testmodel.h"

TestModel::TestModel()
{
    slTest = new QStringList();
    loadTests();
    this->setStringList(*slTest);
}

int TestModel::loadTests() {
    slTest->append("Test1");
    slTest->append("Test2");
    return 0;
}
